/*********************************************************************
* Title     : Canny Edge Detector Algorithm
* Author    : balarcode
* Version   : 1.2
* Date      : 5th November 2024
* File Type : C++ Program
* File Test : Verified on open source SCRC V2.2
* Comments  : Algorithm steps:
*             1) Convolve the image with a separable Gaussian filter.
*             2) Take dx and dy - the first derivatives using [-1,0,1] and [1,0,-1]'.
*             3) Compute the magnitude: sqrt(dx*dx+dy*dy) and the angle.
*             4) Perform non-maximal suppression.
*             5) Perform hysteresis.
*
* All rights reserved.
*********************************************************************/

#include "canny.h"

unsigned int _IDcnt = 0;

/*********************************************************************
* FUNCTION DEFINITIONS
*********************************************************************/
/*********************************************************************
*@function     main
*
*@param  [in]  argc    - Argument count
*@param  [in]  *argv[] - Argument vector to pass input image
*
*@param  [out] Result code of execution of main
*
*@brief        Main function to start the program.
*
*********************************************************************/
int main(int argc, char *argv[]) {
    char *infilename = 0;
    char *dirfilename = 0;
    int cols = 320; int rows = 240;
    char outfilename[128];
    char composedfname[128];
    unsigned char image[240][320];
    unsigned char edge[240][320];

    float sigma;
    float tlow;
    float thigh;

    char comment_new[] = "";
    int ii; int jj;

    sigma = 6.000000000000000e-01;
    tlow = 3.000000000000000e-01;
    thigh = 8.000000000000000e-01;

    if (argc < 1) {
	    fprintf(stderr, "\n<USAGE> %s image [writedirim]\n", argv[0]);
	    fprintf(stderr, "\n      image:      An image to process. Must be in ");
	    fprintf(stderr, "PGM format.\n");
	    exit(1);
    }

    infilename = argv[1];

    if (argc == 2) dirfilename = infilename;
    else dirfilename = 0;

    for (ii = 0; ii < rows; ii++) {
	    for (jj = 0; jj < cols; jj++) {
	        image[ii][jj] = 0;
	        edge[ii][jj] = 0;
	    }
    }

    if (0) printf("Reading the image %s.\n", infilename);
    if (read_pgm_image(infilename, &image[0][0], &rows, &cols) == 0) {
	    fprintf(stderr, "Error reading the input image, %s.\n", infilename);
	    exit(1);
    }

    if (0) printf("Starting Canny edge detection.\n");
    if (dirfilename != 0) {
	    sprintf(composedfname, "%s_s_%3.2f_l_%3.2f_h_%3.2f.fim", infilename, sigma, tlow, thigh);
	    dirfilename = composedfname;
    }

    canny(&image[0][0], rows, cols, sigma, tlow, thigh, &edge[0][0], dirfilename);

    sprintf(outfilename, "%s_s_%3.2f_l_%3.2f_h_%3.2f.pgm", infilename, sigma, tlow, thigh);
    if (0) printf("Writing the edge iname in the file %s.\n", outfilename);
    if (write_pgm_image(outfilename, &edge[0][0], rows, cols, comment_new, 255) == 0) {
	    fprintf(stderr, "Error writing the edge image, %s.\n", outfilename);
	    exit(1);
    }
}

/*********************************************************************
*@function     canny
*
*@param  [in]  *image - Input image
*@param  [in]  rows   - Number of rows of input image
*@param  [in]  cols   - Number of columns of input image
*@param  [in]  sigma  - Input standard deviation
*@param  [in]  tlow   - Input low fraction for computing low gradient threshold
*@param  [in]  thigh  - Input high fraction for computing high gradient threshold
*
*@param  [in/out]  *edge - Output edge detected image
*@param  [out]    *fname - Output file to write gradient direction in radians
*
*@brief        Execute Canny edge detection.
*
*********************************************************************/
void canny(unsigned char *image, int rows, int cols, float sigma,
    float tlow, float thigh, unsigned char *edge, char *fname) {
    struct _IO_FILE *fpdir = 0;
    unsigned char *nms;
    short int *smoothedim;
    short int *delta_x;
    short int *delta_y;
    short int *magnitude;

    float *dir_radians = 0;

    if (0) printf("Smoothening the image using a Gaussian kernel.\n");
    gaussian_smooth(image, rows, cols, sigma, &smoothedim);

    if (0) printf("Computing the X and Y first derivatives.\n");
    derivative_x_y(smoothedim, rows, cols, &delta_x, &delta_y);

    if (fname != 0) {
	    radian_direction(delta_x, delta_y, rows, cols, &dir_radians, -1, -1);

	    if ((fpdir = fopen(fname, "wb")) == 0) {
	        fprintf(stderr, "Error opening the file %s for writing.\n", fname);
	        exit(1);
	    }
	    fwrite(dir_radians, sizeof(float), rows * cols, fpdir);
	    fclose(fpdir);
	    free(dir_radians);
    }

    if (0) printf("Computing the magnitude of the gradient.\n");
    magnitude_x_y(delta_x, delta_y, rows, cols, &magnitude);

    if (0) printf("Performing non-maximal suppression.\n");
    if ((nms = (unsigned char *)calloc(rows * cols, sizeof(unsigned char))) == 0) {
	    fprintf(stderr, "Error allocating the nms image.\n");
	    exit(1);
    }
    non_max_supp(magnitude, delta_x, delta_y, rows, cols, nms);

    if (0) printf("Performing hysteresis thresholding.\n");
    apply_hysteresis(magnitude, nms, rows, cols, tlow, thigh, edge);

    free(smoothedim);
    free(delta_x);
    free(delta_y);
    free(magnitude);
    free(nms);
}

/*********************************************************************
*@function     radian_direction
*
*@param  [in]  *delta_x          - X-direction derivative or gradient
*@param  [in]  *delta_y          - Y-direction derivative or gradient
*@param  [in]  rows              - Number of rows of input image
*@param  [in]  cols              - Number of columns of input image
*@param  [in/out]  **dir_radians - Gradient direction image
*@param  [in]  xdirtag           - X-direction control
*@param  [in]  ydirtag           - Y-direction control
*
*@brief        Compute the direction of the edges and store them as
*              an image.
*
*********************************************************************/
void radian_direction(short int *delta_x, short int *delta_y, int rows,
    int cols, float **dir_radians, int xdirtag, int ydirtag) {
    int c; int pos; int r;
    float *dirim = 0;
    double dx; double dy;

    if ((dirim = (float *)calloc(rows * cols, sizeof(float))) == 0) {
	    fprintf(stderr, "Error allocating the gradient direction image.\n");
	    exit(1);
    }
    *dir_radians = dirim;

    for (r = 0, pos = 0; r < rows; r++) {
	    for (c = 0; c < cols; c++, pos++) {
	        dx = (double)delta_x[pos];
	        dy = (double)delta_y[pos];

	        if (xdirtag == 1) dx = -dx;
	        if (ydirtag == -1) dy = -dy;

	        dirim[pos] = (float)angle_radians(dx, dy);
	    }
    }
}

/*********************************************************************
*@function     angle_radians
*
*@param  [in]  x         - X-direction derivative or gradient
*@param  [in]  y         - Y-direction derivative or gradient
*
*@param  [out] ang       - Angle in radians
*
*@brief        Compute the angle in radians between the gradients in
*              Y-direction and X-direction. arctan(|Gy|/|Gx|) is used.
*
*********************************************************************/
double angle_radians(double x, double y) {
    double ang; double xu; double yu;

    xu = fabs(x);
    yu = fabs(y);

    if ((xu == 0) && (yu == 0)) return (0);

    ang = atan(yu / xu);

    if (x >= 0) {
	    if (y >= 0) return (ang);
	    else return (2 * 3.141592653589793e+00 - ang);
    }
    else {
	    if (y >= 0) return (3.141592653589793e+00 - ang);
	    else return (3.141592653589793e+00 + ang);
    }
}

/*********************************************************************
*@function     magnitude_x_y
*
*@param  [in]  *delta_x         - X-direction derivative or gradient
*@param  [in]  *delta_y         - Y-direction derivative or gradient
*@param  [in]  rows             - Number of rows of input image
*@param  [in]  cols             - Number of columns of input image
*
*@param  [in/out]  **magnitude  - Gradient magnitude image
*
*@brief        Compute the gradient magnitudes or edge strengths and
*              store them as an image.
*
*********************************************************************/
void magnitude_x_y(short int *delta_x, short int *delta_y, int rows,
    int cols, short int **magnitude) {
    int c; int pos; int r; int sq1; int sq2;

    if ((*magnitude = (short int *)calloc(rows * cols, sizeof(short int))) == 0) {
	    fprintf(stderr, "Error allocating the magnitude image.\n");
	    exit(1);
    }

    for (r = 0, pos = 0; r < rows; r++) {
	    for (c = 0; c < cols; c++, pos++) {
	        sq1 = (int)delta_x[pos] * (int)delta_x[pos];
	        sq2 = (int)delta_y[pos] * (int)delta_y[pos];
	        (*magnitude)[pos] = (short int)(5.000000000000000e-01 + sqrt((float)sq1 + (float)sq2));
	    }
    }
}

/*********************************************************************
*@function     derivative_x_y
*
*@param  [in]  *smoothedim    - Input filtered/smoothened image
*@param  [in]  rows           - Number of rows of input image
*@param  [in]  cols           - Number of columns of input image
*
*@param  [in/out]  **delta_x  - X-direction derivative or gradient
*@param  [in/out]  **delta_y  - Y-direction derivative or gradient
*
*@brief        Compute the gradients in X and Y directions for the
*              Gaussian filtered or smoothened image.
*
*********************************************************************/
void derivative_x_y(short int *smoothedim, int rows, int cols,
    short int **delta_x, short int **delta_y) {
    int c; int pos; int r;

    if (((*delta_x) = (short int *)calloc(rows * cols, sizeof(short int))) == 0) {
	    fprintf(stderr, "Error allocating the delta_x image.\n");
	    exit(1);
    }
    if (((*delta_y) = (short int *)calloc(rows * cols, sizeof(short int))) == 0) {
	    fprintf(stderr, "Error allocating the delta_x image.\n");
	    exit(1);
    }

    if (0) printf("   Computing the X-direction derivative.\n");
    for (r = 0; r < rows; r++) {
        pos = r * cols;
	    (*delta_x)[pos] = smoothedim[pos + 1] - smoothedim[pos];
	    pos++;
	    for (c = 1; c < (cols - 1); c++, pos++) {
	        (*delta_x)[pos] = smoothedim[pos + 1] - smoothedim[pos - 1];
	    }
	    (*delta_x)[pos] = smoothedim[pos] - smoothedim[pos - 1];
    }

    if (0) printf("   Computing the Y-direction derivative.\n");
    for (c = 0; c < cols; c++) {
	    pos = c;
	    (*delta_y)[pos] = smoothedim[pos + cols] - smoothedim[pos];
	    pos += cols;
	    for (r = 1; r < (rows - 1); r++, pos += cols) {
	        (*delta_y)[pos] = smoothedim[pos + cols] - smoothedim[pos - cols];
	    }
	    (*delta_y)[pos] = smoothedim[pos] - smoothedim[pos - cols];
    }
}

/*********************************************************************
*@function     gaussian_smooth
*
*@param  [in]  *image - Input image
*@param  [in]  rows   - Number of rows of input image
*@param  [in]  cols   - Number of columns of input image
*@param  [in]  sigma  - Input standard deviation
*
*@param  [out] **smoothedim - Output smoothened/filtered image
*
*@brief        Convolve Gaussian filter/kernel with the input image.
*
*********************************************************************/
void gaussian_smooth(unsigned char *image, int rows, int cols, float sigma,
    short int **smoothedim) {
    int c; int cc; int r; int rr;
    int windowsize;
    int center;
    float *tempim;
    float *kernel;
    float dot;
    float sum;

    if (0) printf("   Computing the Gaussian smoothening kernel.\n");
    make_gaussian_kernel(sigma, &kernel, &windowsize);
    center = windowsize / 2;

    if ((tempim = (float *)calloc(rows * cols, sizeof(float))) == 0) {
	    fprintf(stderr, "Error allocating the buffer image.\n");
	    exit(1);
    }
    if (((*smoothedim) = (short int *)calloc(rows * cols, sizeof(short int))) == 0) {
	    fprintf(stderr, "Error allocating the smoothed image.\n");
	    exit(1);
    }

    if (0) printf("   Blurring the image in the X-direction.\n");
    for (r = 0; r < rows; r++) {
	    for (c = 0; c < cols; c++) {
	        dot = 0.000000000000000e+00;
	        sum = 0.000000000000000e+00;
	        for (cc = (-center); cc <= center; cc++) {
		        if (((c + cc) >= 0) && ((c + cc) < cols)) {
		            dot += (float)image[r * cols + (c + cc)] * kernel[center + cc];
		            sum += kernel[center + cc];
		        }
	        }
	        tempim[r * cols + c] = dot / sum;
	    }
    }

    if (0) printf("   Blurring the image in the Y-direction.\n");
    for (c = 0; c < cols; c++) {
	    for (r = 0; r < rows; r++) {
	        sum = 0.000000000000000e+00;
	        dot = 0.000000000000000e+00;
	        for (rr = (-center); rr <= center; rr++) {
		        if (((r + rr) >= 0) && ((r + rr) < rows)) {
		            dot += tempim[(r + rr) * cols + c] * kernel[center + rr];
		            sum += kernel[center + rr];
		        }
	        }
	        (*smoothedim)[r * cols + c] = (short int)(dot * 9.000000000000000e+01 / sum + 5.000000000000000e-01);
	    }
    }

    free(tempim);
    free(kernel);
}

/*********************************************************************
*@function     make_gaussian_kernel
*
*@param  [in]     sigma    - Input standard deviation
*@param  [in/out] **kernel - Output Gaussian filter/kernel
*@param  [in/out] *windowsize - Number of filter coefficients
*
*@brief        Form the Gaussian filter/kernel to perform convolution.
*              Note that selection of the size of the Gaussian kernel
*              will affect the performance of the detection algorithm.
*
*********************************************************************/
void make_gaussian_kernel(float sigma, float **kernel, int *windowsize) {
    int center; int i;
    float fx; float sum = 0.000000e+00f; float x;

    *windowsize = 1 + 2 * ceil(2.500000000000000e+00 * sigma);
    center = (*windowsize) / 2;

    if (0) printf("      The kernel has %d elements.\n", *windowsize);
    if ((*kernel = (float *)calloc((*windowsize), sizeof(float))) == 0) {
	    fprintf(stderr, "Error callocing the gaussian kernel array.\n");
	    exit(1);
    }

    for (i = 0; i < (*windowsize); i++) {
	    x = (float)(i - center);
	    fx = pow(2.718280000000000e+00,  -5.000000000000000e-01 * x * x / (sigma * sigma)) / (sigma * sqrt(6.283185300000000e+00));
	    (*kernel)[i] = fx;
	    sum += fx;
    }

    for (i = 0; i < (*windowsize); i++) (*kernel)[i] /= sum;

    if (0) {
	    printf("The filter coefficients are:\n");
	    for (i = 0; i < (*windowsize); i++)
	        printf("kernel[%d] = %f\n", i, (*kernel)[i]);
    }
}

void follow_edges(unsigned char *edgemapptr, short int *edgemagptr, short int lowval, int cols) {
    short int *tempmagptr;
    unsigned char *tempmapptr;
    int i;

    int x[8] = { 1,1,0,-1,-1,-1,0,1 };
    int y[8] = { 0,1,1,1,0,-1,-1,-1 };

    for (i = 0; i < 8; i++) {
	    tempmapptr = edgemapptr - y[i] * cols + x[i];
	    tempmagptr = edgemagptr - y[i] * cols + x[i];

	    if ((*tempmapptr == 128) && (*tempmagptr > lowval)) {
	        *tempmapptr = (unsigned char)0;
	        follow_edges(tempmapptr, tempmagptr, lowval, cols);
	    }
    }
}

void apply_hysteresis(short int *mag, unsigned char *nms, int rows, int cols,
    float tlow, float thigh, unsigned char *edge) {
    int c; int highcount; int highthreshold; int lowthreshold; int numedges; int pos; int r;
    int hist[32768];
    short int maximum_mag;

    for (r = 0, pos = 0; r < rows; r++) {
	    for (c = 0; c < cols; c++, pos++) {
	        if (nms[pos] == 128) edge[pos] = 128;
	        else edge[pos] = 255;
	    }
    }

    for (r = 0, pos = 0; r < rows; r++, pos += cols) {
	    edge[pos] = 255;
	    edge[pos + cols - 1] = 255;
    }
    pos = (rows - 1) * cols;
    for (c = 0; c < cols; c++, pos++) {
	    edge[c] = 255;
	    edge[pos] = 255;
    }

    for (r = 0; r < 32768; r++) hist[r] = 0;
    for (r = 0, pos = 0; r < rows; r++) {
	    for (c = 0; c < cols; c++, pos++) {
	        if (edge[pos] == 128) hist[mag[pos]]++ ;
	    }
    }

    for (r = 1, numedges = 0; r < 32768; r++) {
	    if (hist[r] != 0) maximum_mag = r;
	    numedges += hist[r];
    }

    highcount = (int)(numedges * thigh + 5.000000000000000e-01);

    r = 1;
    numedges = hist[1];
    while((r < (maximum_mag - 1)) && (numedges < highcount)) {
	    r++;
	    numedges += hist[r];
    }
    highthreshold = r;
    lowthreshold = (int)(highthreshold * tlow + 5.000000000000000e-01);

    if (0) {
	    printf("The input low and high fractions of %f and %f computed to\n", tlow, thigh);
	    printf("magnitude of the gradient threshold values of: %d %d\n", lowthreshold, highthreshold);
    }

    for (r = 0, pos = 0; r < rows; r++) {
	    for (c = 0; c < cols; c++, pos++) {
	        if ((edge[pos] == 128) && (mag[pos] >= highthreshold)) {
		        edge[pos] = 0;
		        follow_edges((edge + pos), (mag + pos), lowthreshold, cols);
	        }
	    }
    }

    for (r = 0, pos = 0; r < rows; r++) {
	    for (c = 0; c < cols; c++, pos++) if (edge[pos] != 0) edge[pos] = 255;
    }
}

void non_max_supp(short int *mag, short int *gradx, short int *grady, int nrows, int ncols,
    unsigned char *result) {
    int colcount; int count; int rowcount;
    short int *magptr; short int *magrowptr;
    short int *gxptr; short int *gxrowptr;
    short int *gyptr; short int *gyrowptr; short int z1; short int z2;
    short int gx; short int gy; short int m00;
    float mag1; float mag2; float xperp; float yperp;
    unsigned char *resultptr; unsigned char *resultrowptr;

    for (count = 0, resultrowptr = result, resultptr = result + ncols * (nrows - 1);
	    count < ncols; resultptr++, resultrowptr++, count++) {
	    *resultrowptr =  *resultptr = (unsigned char)0;
    }

    for (count = 0, resultptr = result, resultrowptr = result + ncols - 1;
	    count < nrows; count++, resultptr += ncols, resultrowptr += ncols) {
	    *resultptr =  *resultrowptr = (unsigned char)0;
    }

    for (rowcount = 1, magrowptr = mag + ncols + 1, gxrowptr = gradx + ncols + 1,
	    gyrowptr = grady + ncols + 1, resultrowptr = result + ncols + 1;
	    rowcount < nrows - 2;
	    rowcount++, magrowptr += ncols, gyrowptr += ncols, gxrowptr += ncols,
	    resultrowptr += ncols) {
	    for (colcount = 1, magptr = magrowptr, gxptr = gxrowptr, gyptr = gyrowptr,
	        resultptr = resultrowptr; colcount < ncols - 2;
	        colcount++, magptr++, gxptr++, gyptr++, resultptr++) {
	        m00 =  *magptr;
	        if (m00 == 0) {
		        *resultptr = (unsigned char)255;
	        }
	        else {
		        xperp = -(gx =  *gxptr) / ((float)m00);
		        yperp = (gy =  *gyptr) / ((float)m00);
	        }

	        if (gx >= 0) {
		        if (gy >= 0) {
		            if (gx >= gy) {

			            z1 =  *(magptr - 1);
			            z2 =  *(magptr - ncols - 1);

			            mag1 = (m00 - z1) * xperp + (z2 - z1) * yperp;

			            z1 =  *(magptr + 1);
			            z2 =  *(magptr + ncols + 1);

			            mag2 = (m00 - z1) * xperp + (z2 - z1) * yperp;
		            }
		            else {
			            z1 =  *(magptr - ncols);
			            z2 =  *(magptr - ncols - 1);

			            mag1 = (z1 - z2) * xperp + (z1 - m00) * yperp;

			            z1 =  *(magptr + ncols);
			            z2 =  *(magptr + ncols + 1);

			            mag2 = (z1 - z2) * xperp + (z1 - m00) * yperp;
		            }
		        }
		        else {
		            if (gx >= -gy) {
			            z1 =  *(magptr - 1);
			            z2 =  *(magptr + ncols - 1);

			            mag1 = (m00 - z1) * xperp + (z1 - z2) * yperp;

			            z1 =  *(magptr + 1);
			            z2 =  *(magptr - ncols + 1);

			            mag2 = (m00 - z1) * xperp + (z1 - z2) * yperp;
		            }
		            else {
			            z1 =  *(magptr + ncols);
			            z2 =  *(magptr + ncols - 1);

			            mag1 = (z1 - z2) * xperp + (m00 - z1) * yperp;

			            z1 =  *(magptr - ncols);
			            z2 =  *(magptr - ncols + 1);

			            mag2 = (z1 - z2) * xperp + (m00 - z1) * yperp;
		            }
		        }
	        }
	        else {
		        if ((gy =  *gyptr) >= 0) {
		            if (-gx >= gy) {
			            z1 =  *(magptr + 1);
			            z2 =  *(magptr - ncols + 1);

			            mag1 = (z1 - m00) * xperp + (z2 - z1) * yperp;

			            z1 =  *(magptr - 1);
			            z2 =  *(magptr + ncols - 1);

			            mag2 = (z1 - m00) * xperp + (z2 - z1) * yperp;
		            }
		            else {
			            z1 =  *(magptr - ncols);
			            z2 =  *(magptr - ncols + 1);

			            mag1 = (z2 - z1) * xperp + (z1 - m00) * yperp;

			            z1 =  *(magptr + ncols);
			            z2 =  *(magptr + ncols - 1);

			            mag2 = (z2 - z1) * xperp + (z1 - m00) * yperp;
		            }
		        }
		        else {
		            if (-gx > -gy) {
			            z1 =  *(magptr + 1);
			            z2 =  *(magptr + ncols + 1);

			            mag1 = (z1 - m00) * xperp + (z1 - z2) * yperp;

			            z1 =  *(magptr - 1);
			            z2 =  *(magptr - ncols - 1);

			            mag2 = (z1 - m00) * xperp + (z1 - z2) * yperp;
		            }
		            else {
			            z1 =  *(magptr + ncols);
			            z2 =  *(magptr + ncols + 1);

			            mag1 = (z2 - z1) * xperp + (m00 - z1) * yperp;

			            z1 =  *(magptr - ncols);
			            z2 =  *(magptr - ncols - 1);

			            mag2 = (z2 - z1) * xperp + (m00 - z1) * yperp;
		            }
		        }
	        }

	        if ((mag1 > 0.000000000000000e+00) || (mag2 > 0.000000000000000e+00)) {
		        *resultptr = (unsigned char)255;
	        }
	        else {
		        if (mag2 == 0.000000000000000e+00)
		            *resultptr = (unsigned char)255;
		        else
		            *resultptr = (unsigned char)128;
	        }
	    }
    }
}

/*********************************************************************
*@function     read_pgm_image
*
*@param  [in]      *infilename - Input image file in PGM format
*@param  [in/out]  *image      - Image matrix
*@param  [in]      *rows       - Number of rows of read image
*@param  [in]      *cols       - Number of columns of read image
*
*@param  [out]     Error code of reading an image
*
*@brief        Read an image in PGM (portable graymap) format.
*
*********************************************************************/
int read_pgm_image(char *infilename, unsigned char *image, int *rows, int *cols) {
    struct _IO_FILE *fp;
    char buf[71];

    if (infilename == 0) fp = stdin;
    else {
	    if ((fp = fopen(infilename, "r")) == 0) {
	        fprintf(stderr, "Error reading the file %s in read_pgm_image().\n", infilename);
	        return (0);
	    }
    }

    fgets(buf, 70, fp);
    if (strncmp(buf, "P5", 2) != 0) {
	    fprintf(stderr, "The file %s is not in PGM format in ", infilename);
	    fprintf(stderr, "read_pgm_image().\n");
	    if (fp != stdin) fclose(fp);
	    return (0);
    }
    do {
		fgets(buf, 70, fp);
    } while (buf[0] == '#');


    do {
        fgets(buf, 70, fp);
    } while(buf[0] == '#');

    if ((image) == 0) {
	    fprintf(stderr, "Memory allocation failure in read_pgm_image().\n");
	    if (fp != stdin) fclose(fp);
	    return (0);
    }

    if ((*rows) != (int)fread((image), (*cols), (*rows), fp)) {
	    fprintf(stderr, "Error reading the image data in read_pgm_image().\n");
	    if (fp != stdin) fclose(fp);
    }

    if (fp != stdin) fclose(fp);
    return (1);
}

/*********************************************************************
*@function     write_pgm_image
*
*@param  [in]  *image       - Image matrix
*@param  [in]  rows         - Number of rows of the image
*@param  [in]  cols         - Number of columns of the image
*@param  [in]  *comment     - Comment string
*@param  [in]  maxval       - Maximum number of characters in the comment string
*
*@param  [out] *outfilename - Output image file in PGM format
*@param  [out] Error code of writing PGM image to a file
*
*@brief        Write an image in PGM (portable graymap) format.
*
*********************************************************************/
int write_pgm_image(char *outfilename, unsigned char *image, int rows,
    int cols, char *comment, int maxval) {
    struct _IO_FILE *fp;

    if (outfilename == 0) fp = stdout;
    else {
	    if ((fp = fopen(outfilename, "w")) == 0) {
	        fprintf(stderr, "Error writing the file %s in write_pgm_image().\n", outfilename);
	        return (0);
	    }
    }

    fprintf(fp, "P5\n%d %d\n", cols, rows);
    if (comment != 0)
	if (strlen(comment) <= 70) fprintf(fp, "# %s\n", comment);
    fprintf(fp, "%d\n", maxval);

    if (rows != (int)fwrite(image, cols, rows, fp)) {
	    fprintf(stderr, "Error writing the image data in write_pgm_image().\n");
	    if (fp != stdout) fclose(fp);
	    return (0);
    }

    if (fp != stdout) fclose(fp);
    return (1);
}

/*********************************************************************
*@function     read_ppm_image
*
*@param  [in]      *infilename - Input image file in PPM format
*@param  [in/out]  **image_red - Image matrix for red component
*@param  [in/out]  **image_grn - Image matrix for green component
*@param  [in/out]  **image_blu - Image matrix for blue component
*@param  [in]      *rows       - Number of rows of read image
*@param  [in]      *cols       - Number of columns of read image
*
*@param  [out]     Error code of reading an image
*
*@brief        Read an image in PPM (portable pixmap) format.
*
*********************************************************************/
int read_ppm_image(char *infilename, unsigned char **image_red,
    unsigned char **image_grn, unsigned char **image_blu, int *rows,
    int *cols) {
    struct _IO_FILE *fp;
    char buf[71];
    int p; int size;

    if (infilename == 0) fp = stdin;
    else {
	    if ((fp = fopen(infilename, "r")) == 0) {
	        fprintf(stderr, "Error reading the file %s in read_ppm_image().\n", infilename);
	        return (0);
	    }
    }

    fgets(buf, 70, fp);
    if (strncmp(buf, "P6", 2) != 0) {
	    fprintf(stderr, "The file %s is not in PPM format in ", infilename);
	    fprintf(stderr, "read_ppm_image().\n");
	    if (fp != stdin) fclose(fp);
	    return (0);
    }

    do { fgets(buf, 70, fp);
    } while(buf[0] == '#');

    do { fgets(buf, 70, fp);
    } while(buf[0] == '#');

    if ((*image_red) == 0) {
	    fprintf(stderr, "Memory allocation failure in read_ppm_image().\n");
	    if (fp != stdin) fclose(fp);
	    return (0);
    }

    if ((*image_grn) == 0) {
	    fprintf(stderr, "Memory allocation failure in read_ppm_image().\n");
	    if (fp != stdin) fclose(fp);
	    return (0);
    }

    if ((*image_blu) == 0) {
	    fprintf(stderr, "Memory allocation failure in read_ppm_image().\n");
	    if (fp != stdin) fclose(fp);
	    return (0);
    }

    size = (*rows) * (*cols);
    for (p = 0; p < size; p++) {
	    (*image_red)[p] = (unsigned char)fgetc(fp);
	    (*image_grn)[p] = (unsigned char)fgetc(fp);
	    (*image_blu)[p] = (unsigned char)fgetc(fp);
    }

    if (fp != stdin) fclose(fp);
    return (1);
}

/*********************************************************************
*@function     write_ppm_image
*
*@param  [in]  *image_red   - Image matrix for red component
*@param  [in]  *image_grn   - Image matrix for green component
*@param  [in]  *image_blu   - Image matrix for blue component
*@param  [in]  rows         - Number of rows of the image
*@param  [in]  cols         - Number of columns of the image
*@param  [in]  *comment     - Comment string
*@param  [in]  maxval       - Maximum number of characters in the comment string
*
*@param  [out] *outfilename - Output image file in PPM format
*@param  [out] Error code of writing PPM image data to a file
*
*@brief        Write an image in PPM (portable pixmap) format.
*
*********************************************************************/
int write_ppm_image(char *outfilename, unsigned char *image_red,
    unsigned char *image_grn, unsigned char *image_blu, int rows,
    int cols, char *comment, int maxval) {
    struct _IO_FILE *fp;
    long int p; long int size;

    if (outfilename == 0) {
		fp = stdout;
	}
    else {
	    if ((fp = fopen(outfilename, "w")) == 0) {
	        fprintf(stderr, "Error writing the file %s in write_pgm_image().\n",
		    outfilename);
	        return (0);
	    }
    }

    fprintf(fp, "P6\n%d %d\n", cols, rows);
    if (comment != 0)
	if (strlen(comment) <= 70) fprintf(fp, "# %s\n", comment);
    fprintf(fp, "%d\n", maxval);

    size = (long int)rows * (long int)cols;
    for (p = 0; p < size; p++) {
	    fputc(image_red[p], fp);
	    fputc(image_grn[p], fp);
	    fputc(image_blu[p], fp);
    }

    if (fp != stdout) fclose(fp);
    return (1);
}

/*********************************************************************
*@function     _scc_bit4_err_handle
*
*@param  [in]  Bit vector
*
*@param  [out] Void
*
*@brief        Error handler for converting a bit vector to a string.
*
*********************************************************************/
void _scc_bit4_err_handle(const _bit4& bit4vec) {
    char temp_bits[1024], *p;
    p=bit2str(2,&temp_bits[1023], bit4vec);
    _specc::abort(
	"ERROR:\t Casting a bit4 vector failed \n"
	"Bit4 vector contains X/Z values %s\n"
	"Simulation aborted.\n", p);
}
