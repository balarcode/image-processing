/*********************************************************************
* Title     : Canny Edge Detection Algorithm
* Author    : balarcode
* Version   : 1.2
* Date      : 7th November 2024
* File Type : C++ Header File
* File Test : Verified on open source SCRC V2.2
* Comments  : Note that, only the required declarations and definitions
*             needed to successfully compile and run the program are
*             included and inlined in the header file for SOC modeling.
*             Alternatively one can let the SCRC to compile and generate
*             an output file similar to this file. Remember to copy over
*             function declarations for Canny edge detector algorithm
*             from the end of this header file.
*
* All rights reserved.
*********************************************************************/

/*********************************************************************
* STRUCTURE DATA TYPE DECLARATIONS
*********************************************************************/
struct __pthread_internal_slist;
struct __locale_struct;
struct _IO_jump_t;
struct _IO_FILE_plus;

struct timeval;
struct _IO_marker;
struct _IO_FILE;
struct exception;
struct random_data;
struct drand48_data;
struct timespec;

/*********************************************************************
* ENUMERATOR DATA TYPE DEFINITIONS
*********************************************************************/
enum __codecvt_result {
    __codecvt_ok=0,
    __codecvt_partial=1,
    __codecvt_error=2,
    __codecvt_noconv=3
};

enum {
    FP_NAN=0,
    FP_INFINITE=1,
    FP_ZERO=2,
    FP_SUBNORMAL=3,
    FP_NORMAL=4
};

typedef enum {
    _IEEE_=-1,
    _SVID_=0,
    _XOPEN_=1,
    _POSIX_=2,
    _ISOC_=3
} _LIB_VERSION_TYPE;

/*********************************************************************
* STRUCTURE/UNION DATA TYPE DEFINITIONS
*********************************************************************/
typedef union {
    unsigned char __c[8];
    double __d;
} __huge_val_t;

typedef union {
    unsigned char __c[4];
    float __f;
} __huge_valf_t;

typedef union {
    char __size[36];
    long int __align;
} pthread_attr_t;

struct __pthread_internal_slist {
    struct __pthread_internal_slist *__next;
};

typedef union {
    struct __pthread_mutex_s { int __lock; unsigned int __count; int __owner; int __kind; unsigned int __nusers; union { int __spins; struct __pthread_internal_slist __list; } NONAMEHERE; } __data;
    char __size[24];
    long int __align;
} pthread_mutex_t;

typedef union {
    char __size[4];
    long int __align;
} pthread_mutexattr_t;

typedef union {
    struct { int __lock; unsigned int __futex; unsigned long int dummy1; unsigned long int dummy2; unsigned long int dummy3; unsigned long int dummy4; unsigned long int dummy5; unsigned long int dummy6; void *__mutex; unsigned int __nwaiters; unsigned int __broadcast_seq; } __data;
    char __size[48];
    long int dummy7;
    long int dummy8;
} pthread_cond_t;

typedef union {
    char __size[4];
    long int __align;
} pthread_condattr_t;

typedef union {
    struct { int __lock; unsigned int __nr_readers; unsigned int __readers_wakeup; unsigned int __writer_wakeup; unsigned int __nr_readers_queued; unsigned int __nr_writers_queued; unsigned char __flags; unsigned char __shared; unsigned char __pad1; unsigned char __pad2; int __writer; } __data;
    char __size[32];
    long int __align;
} pthread_rwlock_t;

typedef union {
    char __size[8];
    long int __align;
} pthread_rwlockattr_t;

typedef union {
    char __size[20];
    long int __align;
} pthread_barrier_t;

typedef union {
    char __size[4];
    int __align;
} pthread_barrierattr_t;

typedef struct {
    int __count;
    union { unsigned int __wch; char __wchb[4]; } __value;
} __mbstate_t;

typedef struct {
    long int __pos;
    __mbstate_t __state;
} _G_fpos_t;

typedef struct {
    long int __val[2];
} __quad_t;

typedef struct {
    __quad_t __pos;
    __mbstate_t __state;
} _G_fpos64_t;

typedef struct {
    unsigned long int __val[32];
} __sigset_t;

struct timeval {
    long int tv_sec;
    long int tv_usec;
};

typedef struct {
    unsigned long int __val[2];
} __u_quad_t;

typedef struct {
    int __val[2];
} __fsid_t;

struct _IO_marker {
    struct _IO_marker *_next;
    struct _IO_FILE *_sbuf;
    int _pos;
};

struct _IO_FILE {
    int _flags;
    char *_IO_read_ptr;
    char *_IO_read_end;
    char *_IO_read_base;
    char *_IO_write_base;
    char *_IO_write_ptr;
    char *_IO_write_end;
    char *_IO_buf_base;
    char *_IO_buf_end;

    char *_IO_save_base;
    char *_IO_backup_base;
    char *_IO_save_end;

    struct _IO_marker *_markers;

    struct _IO_FILE *_chain;

    int _fileno;

    int _flags2;

    long int _old_offset;

    unsigned short int _cur_column;
    char _vtable_offset;
    char _shortbuf[1];

    void *_lock;

    __quad_t _offset;

    void *__pad1;
    void *__pad2;
    void *__pad3;
    void *__pad4;
    unsigned int __pad5;

    int _mode;

    char _unused2[40];
};

struct exception {
    int type;
    char *name;
    double arg1;
    double arg2;
    double retval;
};

typedef struct {
    int quot;
    int rem;
} div_t;

typedef struct {
    long int quot;
    long int rem;
} ldiv_t;

typedef struct {
    long long int quot;
    long long int rem;
} lldiv_t;

struct random_data {
    int *fptr;
    int *rptr;
    int *state;
    int rand_type;
    int rand_deg;
    int rand_sep;
    int *end_ptr;
};

struct drand48_data {
    unsigned short int __x[3];
    unsigned short int __old_x[3];
    unsigned short int __c;
    unsigned short int __init;
    unsigned long long int __a;
};

typedef struct {
    long int __fds_bits[32];
} fd_set;

struct timespec {
    long int tv_sec;
    long int tv_nsec;
};

/*********************************************************************
* USER-DEFINED DATA TYPE DEFINITIONS
*********************************************************************/
typedef unsigned long int pthread_t;

typedef struct __pthread_internal_slist __pthread_slist_t;

typedef unsigned int pthread_key_t;

typedef int pthread_once_t;

typedef volatile int pthread_spinlock_t;

typedef unsigned int size_t;

typedef struct _IO_FILE FILE;

typedef struct _IO_FILE __FILE;

typedef struct __locale_struct *__locale_t;

typedef struct __locale_struct *locale_t;

typedef int _G_int16_t;
typedef int _G_int32_t;
typedef unsigned int _G_uint16_t;
typedef unsigned int _G_uint32_t;

typedef long double float_t;

typedef long double double_t;

typedef int __sig_atomic_t;

typedef unsigned char __u_char;
typedef unsigned short int __u_short;
typedef unsigned int __u_int;
typedef unsigned long int __u_long;

typedef char __int8_t;
typedef unsigned char __uint8_t;
typedef short int __int16_t;
typedef unsigned short int __uint16_t;
typedef int __int32_t;
typedef unsigned int __uint32_t;

typedef unsigned int __uid_t;
typedef unsigned int __gid_t;
typedef unsigned long int __ino_t;

typedef unsigned int __mode_t;
typedef unsigned int __nlink_t;
typedef long int __off_t;

typedef int __pid_t;

typedef long int __clock_t;
typedef unsigned long int __rlim_t;

typedef unsigned int __id_t;
typedef long int __time_t;
typedef unsigned int __useconds_t;
typedef long int __suseconds_t;

typedef int __daddr_t;
typedef long int __swblk_t;
typedef int __key_t;

typedef int __clockid_t;

typedef void *__timer_t;

typedef long int __blksize_t;

typedef long int __blkcnt_t;

typedef unsigned long int __fsblkcnt_t;

typedef unsigned long int __fsfilcnt_t;

typedef int __ssize_t;

typedef __quad_t *__qaddr_t;
typedef char *__caddr_t;

typedef int __intptr_t;

typedef unsigned int __socklen_t;

typedef void _IO_lock_t;

typedef struct _IO_FILE _IO_FILE;

typedef int __io_read_fn(void *, char *, unsigned int);
typedef int __io_write_fn(void *, const char *, unsigned int);
typedef int __io_seek_fn(void *, __quad_t *, int);
typedef int __io_close_fn(void *);
typedef int (*__compar_fn_t)(const void *, const void *);

typedef long int suseconds_t;

typedef long int __fd_mask;

typedef long int fd_mask;

typedef unsigned char u_char;
typedef unsigned short int u_short;
typedef unsigned int u_int;
typedef unsigned long int u_long;

typedef unsigned long int ino_t;

typedef unsigned int gid_t;

typedef unsigned int mode_t;

typedef unsigned int nlink_t;

typedef unsigned int uid_t;

typedef long int off_t;

typedef int pid_t;

typedef unsigned int id_t;

typedef int ssize_t;

typedef int daddr_t;
typedef char *caddr_t;

typedef int key_t;

typedef unsigned long int ulong;
typedef unsigned short int ushort;
typedef unsigned int uint;

typedef char int8_t;
typedef short int int16_t;
typedef int int32_t;

typedef unsigned char u_int8_t;
typedef unsigned short int u_int16_t;
typedef unsigned int u_int32_t;

typedef int register_t;

typedef long int blkcnt_t;

typedef unsigned long int fsblkcnt_t;

typedef unsigned long int fsfilcnt_t;

typedef long int time_t;

typedef int clockid_t;

typedef void *timer_t;

typedef void *__gnuc_va_list;

/*********************************************************************
* VARIABLE AND FUNCTION DECLARATIONS
*********************************************************************/
extern struct _IO_FILE *stdin;
extern struct _IO_FILE *stdout;
extern struct _IO_FILE *stderr;

extern int sys_nerr;
extern int signgam;

extern const char *const sys_errlist[];

extern struct _IO_FILE_plus _IO_2_1_stdin_;
extern struct _IO_FILE_plus _IO_2_1_stdout_;
extern struct _IO_FILE_plus _IO_2_1_stderr_;

extern _LIB_VERSION_TYPE _LIB_VERSION;

extern "C" int remove(const char *);

extern "C" int rename(const char *, const char *);

extern "C" int renameat(int, const char *, int, const char *);

extern "C" struct _IO_FILE *tmpfile(void);

extern "C" char *tmpnam(char *);

extern "C" char *tmpnam_r(char *);

extern "C" char *tempnam(const char *, const char *);

extern "C" int fclose(struct _IO_FILE *);

extern "C" int fflush(struct _IO_FILE *);

extern "C" int fflush_unlocked(struct _IO_FILE *);

extern "C" struct _IO_FILE *fopen(const char *, const char *);

extern "C" struct _IO_FILE *freopen(const char *, const char *, struct _IO_FILE *);

extern "C" struct _IO_FILE *fdopen(int, const char *);

extern "C" struct _IO_FILE *fmemopen(void *, unsigned int, const char *);

extern "C" struct _IO_FILE *open_memstream(char **, unsigned int *);

extern "C" void setbuf(struct _IO_FILE *, char *);

extern "C" int setvbuf(struct _IO_FILE *, char *, int, unsigned int);

extern "C" void setbuffer(struct _IO_FILE *, char *, unsigned int);

extern "C" void setlinebuf(struct _IO_FILE *);

extern "C" int fprintf(struct _IO_FILE *, const char *, ...);

extern "C" int printf(const char *, ...);

extern "C" int sprintf(char *, const char *, ...);

extern "C" int vfprintf(struct _IO_FILE *, const char *, void *);

extern "C" int vprintf(const char *, void *);

extern "C" int vsprintf(char *, const char *, void *);

extern "C" int snprintf(char *, unsigned int, const char *, ...);

extern "C" int vsnprintf(char *, unsigned int, const char *, void *);

extern "C" int vdprintf(int, const char *, void *);

extern "C" int dprintf(int, const char *, ...);

extern "C" int fscanf(struct _IO_FILE *, const char *, ...);

extern "C" int scanf(const char *, ...);

extern "C" int sscanf(const char *, const char *, ...);

extern "C" int vfscanf(struct _IO_FILE *, const char *, void *);

extern "C" int vscanf(const char *, void *);

extern "C" int vsscanf(const char *, const char *, void *);

extern "C" int fgetc(struct _IO_FILE *);

extern "C" int getc(struct _IO_FILE *);

extern "C" int getchar(void);

extern "C" int getc_unlocked(struct _IO_FILE *);

extern "C" int getchar_unlocked(void);

extern "C" int fgetc_unlocked(struct _IO_FILE *);

extern "C" int fputc(int, struct _IO_FILE *);

extern "C" int putc(int, struct _IO_FILE *);

extern "C" int putchar(int);

extern "C" int fputc_unlocked(int, struct _IO_FILE *);

extern "C" int putc_unlocked(int, struct _IO_FILE *);

extern "C" int putchar_unlocked(int);

extern "C" int getw(struct _IO_FILE *);

extern "C" int putw(int, struct _IO_FILE *);

extern "C" char *fgets(char *, int, struct _IO_FILE *);

extern "C" char *gets(char *);

extern "C" int __getdelim(char **, unsigned int *, int, struct _IO_FILE *);

extern "C" int getdelim(char **, unsigned int *, int, struct _IO_FILE *);

extern "C" int getline(char **, unsigned int *, struct _IO_FILE *);

extern "C" int fputs(const char *, struct _IO_FILE *);

extern "C" int puts(const char *);

extern "C" int ungetc(int, struct _IO_FILE *);

extern "C" unsigned int fread(void *, unsigned int, unsigned int, struct _IO_FILE *);

extern "C" unsigned int fwrite(const void *, unsigned int, unsigned int, struct _IO_FILE *);

extern "C" unsigned int fread_unlocked(void *, unsigned int, unsigned int, struct _IO_FILE *);

extern "C" unsigned int fwrite_unlocked(const void *, unsigned int, unsigned int, struct _IO_FILE *);

extern "C" int fseek(struct _IO_FILE *, long int, int);

extern "C" long int ftell(struct _IO_FILE *);

extern "C" void rewind(struct _IO_FILE *);

extern "C" int fseeko(struct _IO_FILE *, long int, int);

extern "C" long int ftello(struct _IO_FILE *);

extern "C" int fgetpos(struct _IO_FILE *, _G_fpos_t *);

extern "C" int fsetpos(struct _IO_FILE *, const _G_fpos_t *);

extern "C" void clearerr(struct _IO_FILE *);

extern "C" int feof(struct _IO_FILE *);

extern "C" int ferror(struct _IO_FILE *);

extern "C" void clearerr_unlocked(struct _IO_FILE *);

extern "C" int feof_unlocked(struct _IO_FILE *);

extern "C" int ferror_unlocked(struct _IO_FILE *);

extern "C" void perror(const char *);

extern "C" int fileno(struct _IO_FILE *);

extern "C" int fileno_unlocked(struct _IO_FILE *);

extern "C" struct _IO_FILE *popen(const char *, const char *);

extern "C" int pclose(struct _IO_FILE *);

extern "C" char *ctermid(char *);

extern "C" void flockfile(struct _IO_FILE *);

extern "C" int ftrylockfile(struct _IO_FILE *);

extern "C" void funlockfile(struct _IO_FILE *);

extern "C" void *alloca(unsigned int);

extern "C" double __acos(double); extern "C" float __acosf(float); extern "C" long double __acosl(long double); extern "C" double acos(double); extern "C" float acosf(float); extern "C" long double acosl(long double);

extern "C" double __asin(double); extern "C" float __asinf(float); extern "C" long double __asinl(long double); extern "C" double asin(double); extern "C" float asinf(float); extern "C" long double asinl(long double);

extern "C" double __atan(double); extern "C" float __atanf(float); extern "C" long double __atanl(long double); extern "C" double atan(double); extern "C" float atanf(float); extern "C" long double atanl(long double);

extern "C" double __atan2(double, double); extern "C" float __atan2f(float, float); extern "C" long double __atan2l(long double, long double); extern "C" double atan2(double, double); extern "C" float atan2f(float, float); extern "C" long double atan2l(long double, long double);

extern "C" double __cos(double); extern "C" float __cosf(float); extern "C" long double __cosl(long double); extern "C" double cos(double); extern "C" float cosf(float); extern "C" long double cosl(long double);

extern "C" double __sin(double); extern "C" float __sinf(float); extern "C" long double __sinl(long double); extern "C" double sin(double); extern "C" float sinf(float); extern "C" long double sinl(long double);

extern "C" double __tan(double); extern "C" float __tanf(float); extern "C" long double __tanl(long double); extern "C" double tan(double); extern "C" float tanf(float); extern "C" long double tanl(long double);

extern "C" double __cosh(double); extern "C" float __coshf(float); extern "C" long double __coshl(long double); extern "C" double cosh(double); extern "C" float coshf(float); extern "C" long double coshl(long double);

extern "C" double __sinh(double); extern "C" float __sinhf(float); extern "C" long double __sinhl(long double); extern "C" double sinh(double); extern "C" float sinhf(float); extern "C" long double sinhl(long double);

extern "C" double __tanh(double); extern "C" float __tanhf(float); extern "C" long double __tanhl(long double); extern "C" double tanh(double); extern "C" float tanhf(float); extern "C" long double tanhl(long double);

extern "C" double __acosh(double); extern "C" float __acoshf(float); extern "C" long double __acoshl(long double); extern "C" double acosh(double); extern "C" float acoshf(float); extern "C" long double acoshl(long double);

extern "C" double __asinh(double); extern "C" float __asinhf(float); extern "C" long double __asinhl(long double); extern "C" double asinh(double); extern "C" float asinhf(float); extern "C" long double asinhl(long double);

extern "C" double __atanh(double); extern "C" float __atanhf(float); extern "C" long double __atanhl(long double); extern "C" double atanh(double); extern "C" float atanhf(float); extern "C" long double atanhl(long double);

extern "C" double __exp(double); extern "C" float __expf(float); extern "C" long double __expl(long double); extern "C" double exp(double); extern "C" float expf(float); extern "C" long double expl(long double);

extern "C" double __frexp(double, int *); extern "C" float __frexpf(float, int *); extern "C" long double __frexpl(long double, int *); extern "C" double frexp(double, int *); extern "C" float frexpf(float, int *); extern "C" long double frexpl(long double, int *);

extern "C" double __ldexp(double, int); extern "C" float __ldexpf(float, int); extern "C" long double __ldexpl(long double, int); extern "C" double ldexp(double, int); extern "C" float ldexpf(float, int); extern "C" long double ldexpl(long double, int);

extern "C" double __log(double); extern "C" float __logf(float); extern "C" long double __logl(long double); extern "C" double log(double); extern "C" float logf(float); extern "C" long double logl(long double);

extern "C" double __log10(double); extern "C" float __log10f(float); extern "C" long double __log10l(long double); extern "C" double log10(double); extern "C" float log10f(float); extern "C" long double log10l(long double);

extern "C" double __modf(double, double *); extern "C" float __modff(float, float *); extern "C" long double __modfl(long double, long double *); extern "C" double modf(double, double *); extern "C" float modff(float, float *); extern "C" long double modfl(long double, long double *);

extern "C" double __expm1(double); extern "C" float __expm1f(float); extern "C" long double __expm1l(long double); extern "C" double expm1(double); extern "C" float expm1f(float); extern "C" long double expm1l(long double);

extern "C" double __log1p(double); extern "C" float __log1pf(float); extern "C" long double __log1pl(long double); extern "C" double log1p(double); extern "C" float log1pf(float); extern "C" long double log1pl(long double);

extern "C" double __logb(double); extern "C" float __logbf(float); extern "C" long double __logbl(long double); extern "C" double logb(double); extern "C" float logbf(float); extern "C" long double logbl(long double);

extern "C" double __exp2(double); extern "C" float __exp2f(float); extern "C" long double __exp2l(long double); extern "C" double exp2(double); extern "C" float exp2f(float); extern "C" long double exp2l(long double);

extern "C" double __log2(double); extern "C" float __log2f(float); extern "C" long double __log2l(long double); extern "C" double log2(double); extern "C" float log2f(float); extern "C" long double log2l(long double);

extern "C" double __pow(double, double); extern "C" float __powf(float, float); extern "C" long double __powl(long double, long double); extern "C" double pow(double, double); extern "C" float powf(float, float); extern "C" long double powl(long double, long double);

extern "C" double __sqrt(double); extern "C" float __sqrtf(float); extern "C" long double __sqrtl(long double); extern "C" double sqrt(double); extern "C" float sqrtf(float); extern "C" long double sqrtl(long double);

extern "C" double __hypot(double, double); extern "C" float __hypotf(float, float); extern "C" long double __hypotl(long double, long double); extern "C" double hypot(double, double); extern "C" float hypotf(float, float); extern "C" long double hypotl(long double, long double);

extern "C" double __cbrt(double); extern "C" float __cbrtf(float); extern "C" long double __cbrtl(long double); extern "C" double cbrt(double); extern "C" float cbrtf(float); extern "C" long double cbrtl(long double);

extern "C" double __ceil(double); extern "C" float __ceilf(float); extern "C" long double __ceill(long double); extern "C" double ceil(double); extern "C" float ceilf(float); extern "C" long double ceill(long double);

extern "C" double __fabs(double); extern "C" float __fabsf(float); extern "C" long double __fabsl(long double); extern "C" double fabs(double); extern "C" float fabsf(float); extern "C" long double fabsl(long double);

extern "C" double __floor(double); extern "C" float __floorf(float); extern "C" long double __floorl(long double); extern "C" double floor(double); extern "C" float floorf(float); extern "C" long double floorl(long double);

extern "C" double __fmod(double, double); extern "C" float __fmodf(float, float); extern "C" long double __fmodl(long double, long double); extern "C" double fmod(double, double); extern "C" float fmodf(float, float); extern "C" long double fmodl(long double, long double);

extern "C" int __isinf(double); extern "C" int __isinff(float); extern "C" int __isinfl(long double);

extern "C" int __finite(double); extern "C" int __finitef(float); extern "C" int __finitel(long double);

extern "C" int isinf(double); extern "C" int isinff(float); extern "C" int isinfl(long double);

extern "C" int finite(double); extern "C" int finitef(float); extern "C" int finitel(long double);

extern "C" double __drem(double, double); extern "C" float __dremf(float, float); extern "C" long double __dreml(long double, long double); extern "C" double drem(double, double); extern "C" float dremf(float, float); extern "C" long double dreml(long double, long double);

extern "C" double __significand(double); extern "C" float __significandf(float); extern "C" long double __significandl(long double); extern "C" double significand(double); extern "C" float significandf(float); extern "C" long double significandl(long double);

extern "C" double __copysign(double, double); extern "C" float __copysignf(float, float); extern "C" long double __copysignl(long double, long double); extern "C" double copysign(double, double); extern "C" float copysignf(float, float); extern "C" long double copysignl(long double, long double);

extern "C" double __nan(const char *); extern "C" float __nanf(const char *); extern "C" long double __nanl(const char *); extern "C" double nan(const char *); extern "C" float nanf(const char *); extern "C" long double nanl(const char *);

extern "C" int __isnan(double); extern "C" int __isnanf(float); extern "C" int __isnanl(long double);

extern "C" int isnan(double); extern "C" int isnanf(float); extern "C" int isnanl(long double);

extern "C" double __j0(double); extern "C" float __j0f(float); extern "C" long double __j0l(long double); extern "C" double j0(double); extern "C" float j0f(float); extern "C" long double j0l(long double);

extern "C" double __j1(double); extern "C" float __j1f(float); extern "C" long double __j1l(long double); extern "C" double j1(double); extern "C" float j1f(float); extern "C" long double j1l(long double);

extern "C" double __jn(int, double); extern "C" float __jnf(int, float); extern "C" long double __jnl(int, long double); extern "C" double jn(int, double); extern "C" float jnf(int, float); extern "C" long double jnl(int, long double);

extern "C" double __y0(double); extern "C" float __y0f(float); extern "C" long double __y0l(long double); extern "C" double y0(double); extern "C" float y0f(float); extern "C" long double y0l(long double);

extern "C" double __y1(double); extern "C" float __y1f(float); extern "C" long double __y1l(long double); extern "C" double y1(double); extern "C" float y1f(float); extern "C" long double y1l(long double);

extern "C" double __yn(int, double); extern "C" float __ynf(int, float); extern "C" long double __ynl(int, long double); extern "C" double yn(int, double); extern "C" float ynf(int, float); extern "C" long double ynl(int, long double);

extern "C" double __erf(double); extern "C" float __erff(float); extern "C" long double __erfl(long double); extern "C" double erf(double); extern "C" float erff(float); extern "C" long double erfl(long double);

extern "C" double __erfc(double); extern "C" float __erfcf(float); extern "C" long double __erfcl(long double); extern "C" double erfc(double); extern "C" float erfcf(float); extern "C" long double erfcl(long double);

extern "C" double __lgamma(double); extern "C" float __lgammaf(float); extern "C" long double __lgammal(long double); extern "C" double lgamma(double); extern "C" float lgammaf(float); extern "C" long double lgammal(long double);

extern "C" double __tgamma(double); extern "C" float __tgammaf(float); extern "C" long double __tgammal(long double); extern "C" double tgamma(double); extern "C" float tgammaf(float); extern "C" long double tgammal(long double);

extern "C" double __gamma(double); extern "C" float __gammaf(float); extern "C" long double __gammal(long double); extern "C" double gamma(double); extern "C" float gammaf(float); extern "C" long double gammal(long double);

extern "C" double __lgamma_r(double, int *); extern "C" float __lgammaf_r(float, int *); extern "C" long double __lgammal_r(long double, int *); extern "C" double lgamma_r(double, int *); extern "C" float lgammaf_r(float, int *); extern "C" long double lgammal_r(long double, int *);

extern "C" double __rint(double); extern "C" float __rintf(float); extern "C" long double __rintl(long double); extern "C" double rint(double); extern "C" float rintf(float); extern "C" long double rintl(long double);

extern "C" double __nextafter(double, double); extern "C" float __nextafterf(float, float); extern "C" long double __nextafterl(long double, long double); extern "C" double nextafter(double, double); extern "C" float nextafterf(float, float); extern "C" long double nextafterl(long double, long double);

extern "C" double __nexttoward(double, long double); extern "C" float __nexttowardf(float, long double); extern "C" long double __nexttowardl(long double, long double); extern "C" double nexttoward(double, long double); extern "C" float nexttowardf(float, long double); extern "C" long double nexttowardl(long double, long double);

extern "C" double __remainder(double, double); extern "C" float __remainderf(float, float); extern "C" long double __remainderl(long double, long double); extern "C" double remainder(double, double); extern "C" float remainderf(float, float); extern "C" long double remainderl(long double, long double);

extern "C" double __scalbn(double, int); extern "C" float __scalbnf(float, int); extern "C" long double __scalbnl(long double, int); extern "C" double scalbn(double, int); extern "C" float scalbnf(float, int); extern "C" long double scalbnl(long double, int);

extern "C" int __ilogb(double); extern "C" int __ilogbf(float); extern "C" int __ilogbl(long double); extern "C" int ilogb(double); extern "C" int ilogbf(float); extern "C" int ilogbl(long double);

extern "C" double __scalbln(double, long int); extern "C" float __scalblnf(float, long int); extern "C" long double __scalblnl(long double, long int); extern "C" double scalbln(double, long int); extern "C" float scalblnf(float, long int); extern "C" long double scalblnl(long double, long int);

extern "C" double __nearbyint(double); extern "C" float __nearbyintf(float); extern "C" long double __nearbyintl(long double); extern "C" double nearbyint(double); extern "C" float nearbyintf(float); extern "C" long double nearbyintl(long double);

extern "C" double __round(double); extern "C" float __roundf(float); extern "C" long double __roundl(long double); extern "C" double round(double); extern "C" float roundf(float); extern "C" long double roundl(long double);

extern "C" double __trunc(double); extern "C" float __truncf(float); extern "C" long double __truncl(long double); extern "C" double trunc(double); extern "C" float truncf(float); extern "C" long double truncl(long double);

extern "C" double __remquo(double, double, int *); extern "C" float __remquof(float, float, int *); extern "C" long double __remquol(long double, long double, int *); extern "C" double remquo(double, double, int *); extern "C" float remquof(float, float, int *); extern "C" long double remquol(long double, long double, int *);

extern "C" long int __lrint(double); extern "C" long int __lrintf(float); extern "C" long int __lrintl(long double); extern "C" long int lrint(double); extern "C" long int lrintf(float); extern "C" long int lrintl(long double);

extern "C" long long int __llrint(double); extern "C" long long int __llrintf(float); extern "C" long long int __llrintl(long double); extern "C" long long int llrint(double); extern "C" long long int llrintf(float); extern "C" long long int llrintl(long double);

extern "C" long int __lround(double); extern "C" long int __lroundf(float); extern "C" long int __lroundl(long double); extern "C" long int lround(double); extern "C" long int lroundf(float); extern "C" long int lroundl(long double);

extern "C" long long int __llround(double); extern "C" long long int __llroundf(float); extern "C" long long int __llroundl(long double); extern "C" long long int llround(double); extern "C" long long int llroundf(float); extern "C" long long int llroundl(long double);

extern "C" double __fdim(double, double); extern "C" float __fdimf(float, float); extern "C" long double __fdiml(long double, long double); extern "C" double fdim(double, double); extern "C" float fdimf(float, float); extern "C" long double fdiml(long double, long double);

extern "C" double __fmax(double, double); extern "C" float __fmaxf(float, float); extern "C" long double __fmaxl(long double, long double); extern "C" double fmax(double, double); extern "C" float fmaxf(float, float); extern "C" long double fmaxl(long double, long double);

extern "C" double __fmin(double, double); extern "C" float __fminf(float, float); extern "C" long double __fminl(long double, long double); extern "C" double fmin(double, double); extern "C" float fminf(float, float); extern "C" long double fminl(long double, long double);

extern "C" int __fpclassify(double); extern "C" int __fpclassifyf(float); extern "C" int __fpclassifyl(long double);

extern "C" int __signbit(double); extern "C" int __signbitf(float); extern "C" int __signbitl(long double);

extern "C" double __fma(double, double, double); extern "C" float __fmaf(float, float, float); extern "C" long double __fmal(long double, long double, long double); extern "C" double fma(double, double, double); extern "C" float fmaf(float, float, float); extern "C" long double fmal(long double, long double, long double);

extern "C" double __scalb(double, double); extern "C" float __scalbf(float, float); extern "C" long double __scalbl(long double, long double); extern "C" double scalb(double, double); extern "C" float scalbf(float, float); extern "C" long double scalbl(long double, long double);

extern "C" int __underflow(struct _IO_FILE *);

extern "C" int __uflow(struct _IO_FILE *);

extern "C" int __overflow(struct _IO_FILE *, int);

extern "C" int _IO_getc(struct _IO_FILE *);

extern "C" int _IO_putc(int, struct _IO_FILE *);

extern "C" int _IO_feof(struct _IO_FILE *);

extern "C" int _IO_ferror(struct _IO_FILE *);

extern "C" int _IO_peekc_locked(struct _IO_FILE *);

extern "C" void _IO_flockfile(struct _IO_FILE *);

extern "C" void _IO_funlockfile(struct _IO_FILE *);

extern "C" int _IO_ftrylockfile(struct _IO_FILE *);

extern "C" int _IO_vfscanf(struct _IO_FILE *, const char *, void *, int *);

extern "C" int _IO_vfprintf(struct _IO_FILE *, const char *, void *);

extern "C" int _IO_padn(struct _IO_FILE *, int, int);

extern "C" unsigned int _IO_sgetn(struct _IO_FILE *, void *, unsigned int);

extern "C" __quad_t _IO_seekoff(struct _IO_FILE *, __quad_t, int, int);

extern "C" __quad_t _IO_seekpos(struct _IO_FILE *, __quad_t, int);

extern "C" void _IO_free_backup_area(struct _IO_FILE *);

extern "C" int matherr(struct exception *);

extern "C" unsigned int __ctype_get_mb_cur_max(void);

extern "C" double atof(const char *);

extern "C" int atoi(const char *);

extern "C" long int atol(const char *);

extern "C" long long int atoll(const char *);

extern "C" double strtod(const char *, char **);

extern "C" float strtof(const char *, char **);

extern "C" long double strtold(const char *, char **);

extern "C" long int strtol(const char *, char **, int);

extern "C" unsigned long int strtoul(const char *, char **, int);

extern "C" long long int strtoll(const char *, char **, int);

extern "C" unsigned long long int strtoull(const char *, char **, int);

extern "C" char *l64a(long int);

extern "C" long int a64l(const char *);

extern "C" long int random(void);

extern "C" void srandom(unsigned int);

extern "C" char *initstate(unsigned int, char *, unsigned int);

extern "C" char *setstate(char *);

extern "C" int random_r(struct random_data *, int *);

extern "C" int srandom_r(unsigned int, struct random_data *);

extern "C" int initstate_r(unsigned int, char *, unsigned int, struct random_data *);

extern "C" int setstate_r(char *, struct random_data *);

extern "C" int rand(void);

extern "C" void srand(unsigned int);

extern "C" int rand_r(unsigned int *);

extern "C" double drand48(void);

extern "C" double erand48(unsigned short int [3]);

extern "C" long int lrand48(void);

extern "C" long int nrand48(unsigned short int [3]);

extern "C" long int mrand48(void);

extern "C" long int jrand48(unsigned short int [3]);

extern "C" void srand48(long int);

extern "C" unsigned short int *seed48(unsigned short int [3]);

extern "C" void lcong48(unsigned short int [7]);

extern "C" int drand48_r(struct drand48_data *, double *);

extern "C" int erand48_r(unsigned short int [3], struct drand48_data *, double *);

extern "C" int lrand48_r(struct drand48_data *, long int *);

extern "C" int nrand48_r(unsigned short int [3], struct drand48_data *, long int *);

extern "C" int mrand48_r(struct drand48_data *, long int *);

extern "C" int jrand48_r(unsigned short int [3], struct drand48_data *, long int *);

extern "C" int srand48_r(long int, struct drand48_data *);

extern "C" int seed48_r(unsigned short int [3], struct drand48_data *);

extern "C" int lcong48_r(unsigned short int [7], struct drand48_data *);

extern "C" void *malloc(unsigned int);

extern "C" void *calloc(unsigned int, unsigned int);

extern "C" void *realloc(void *, unsigned int);

extern "C" void free(void *);

extern "C" void cfree(void *);

extern "C" void *valloc(unsigned int);

extern "C" int posix_memalign(void **, unsigned int, unsigned int);

extern "C" void abort(void);

extern "C" int atexit(void (*)(void));

extern "C" int on_exit(void (*)(int, void *), void *);

extern "C" void exit(int);

extern "C" void _Exit(int);

extern "C" char *getenv(const char *);

extern "C" char *__secure_getenv(const char *);

extern "C" int putenv(char *);

extern "C" int setenv(const char *, const char *, int);

extern "C" int unsetenv(const char *);

extern "C" int clearenv(void);

extern "C" char *mktemp(char *);

extern "C" int mkstemp(char *);

extern "C" int mkstemps(char *, int);

extern "C" char *mkdtemp(char *);

extern "C" int system(const char *);

extern "C" char *realpath(const char *, char *);

extern "C" void *bsearch(const void *, const void *, unsigned int, unsigned int, int (*)(const void *, const void *));

extern "C" void qsort(void *, unsigned int, unsigned int, int (*)(const void *, const void *));

extern "C" int abs(int);

extern "C" long int labs(long int);

extern "C" long long int llabs(long long int);

extern "C" div_t div(int, int);

extern "C" ldiv_t ldiv(long int, long int);

extern "C" lldiv_t lldiv(long long int, long long int);

extern "C" char *ecvt(double, int, int *, int *);

extern "C" char *fcvt(double, int, int *, int *);

extern "C" char *gcvt(double, int, char *);

extern "C" char *qecvt(long double, int, int *, int *);

extern "C" char *qfcvt(long double, int, int *, int *);

extern "C" char *qgcvt(long double, int, char *);

extern "C" int ecvt_r(double, int, int *, int *, char *, unsigned int);

extern "C" int fcvt_r(double, int, int *, int *, char *, unsigned int);

extern "C" int qecvt_r(long double, int, int *, int *, char *, unsigned int);

extern "C" int qfcvt_r(long double, int, int *, int *, char *, unsigned int);

extern "C" int mblen(const char *, unsigned int);

extern "C" int mbtowc(int *, const char *, unsigned int);

extern "C" int wctomb(char *, int);

extern "C" unsigned int mbstowcs(int *, const char *, unsigned int);

extern "C" unsigned int wcstombs(char *, const int *, unsigned int);

extern "C" int rpmatch(const char *);

extern "C" int posix_openpt(int);

extern "C" int getloadavg(double [], int);

extern "C" void *memcpy(void *, const void *, unsigned int);

extern "C" void *memmove(void *, const void *, unsigned int);

extern "C" void *memccpy(void *, const void *, int, unsigned int);

extern "C" void *memset(void *, int, unsigned int);

extern "C" int memcmp(const void *, const void *, unsigned int);

extern "C" void *memchr(const void *, int, unsigned int);

extern "C" char *strcpy(char *, const char *);

extern "C" char *strncpy(char *, const char *, unsigned int);

extern "C" char *strcat(char *, const char *);

extern "C" char *strncat(char *, const char *, unsigned int);

extern "C" int strcmp(const char *, const char *);

extern "C" int strncmp(const char *, const char *, unsigned int);

extern "C" int strcoll(const char *, const char *);

extern "C" unsigned int strxfrm(char *, const char *, unsigned int);

extern "C" int strcoll_l(const char *, const char *, struct __locale_struct *);

extern "C" unsigned int strxfrm_l(char *, const char *, unsigned int, struct __locale_struct *);

extern "C" char *strdup(const char *);

extern "C" char *strndup(const char *, unsigned int);

extern "C" char *strchr(const char *, int);

extern "C" char *strrchr(const char *, int);

extern "C" unsigned int strcspn(const char *, const char *);

extern "C" unsigned int strspn(const char *, const char *);

extern "C" char *strpbrk(const char *, const char *);

extern "C" char *strstr(const char *, const char *);

extern "C" char *strtok(char *, const char *);

extern "C" char *__strtok_r(char *, const char *, char **);

extern "C" char *strtok_r(char *, const char *, char **);

extern "C" unsigned int strlen(const char *);

extern "C" unsigned int strnlen(const char *, unsigned int);

extern "C" char *strerror(int);

extern "C" int __xpg_strerror_r(int, char *, unsigned int);

extern "C" char *strerror_l(int, struct __locale_struct *);

extern "C" void __bzero(void *, unsigned int);

extern "C" void bcopy(const void *, void *, unsigned int);

extern "C" void bzero(void *, unsigned int);

extern "C" int bcmp(const void *, const void *, unsigned int);

extern "C" char *index(const char *, int);

extern "C" char *rindex(const char *, int);

extern "C" int ffs(int);

extern "C" int strcasecmp(const char *, const char *);

extern "C" int strncasecmp(const char *, const char *, unsigned int);

extern "C" char *strsep(char **, const char *);

extern "C" char *strsignal(int);

extern "C" char *__stpcpy(char *, const char *);

extern "C" char *stpcpy(char *, const char *);

extern "C" char *__stpncpy(char *, const char *, unsigned int);

extern "C" char *stpncpy(char *, const char *, unsigned int);

extern "C" int select(int, fd_set *, fd_set *, fd_set *, struct timeval *);

extern "C" int pselect(int, fd_set *, fd_set *, fd_set *, const struct timespec *, const __sigset_t *);

int main(int, char *[]);
void canny(unsigned char *, int, int, float, float, float, unsigned char *, char *);
void radian_direction(short int *, short int *, int, int, float **, int, int);
double angle_radians(double, double);
void magnitude_x_y(short int *, short int *, int, int, short int **);
void derivative_x_y(short int *, int, int, short int **, short int **);
void gaussian_smooth(unsigned char *, int, int, float, short int **);
void make_gaussian_kernel(float, float **, int *);
void follow_edges(unsigned char *, short int *, short int, int);
void apply_hysteresis(short int *, unsigned char *, int, int, float, float, unsigned char *);
void non_max_supp(short int *, short int *, short int *, int, int, unsigned char *);
int read_pgm_image(char *, unsigned char *, int *, int *);
int write_pgm_image(char *, unsigned char *, int, int, char *, int);
int read_ppm_image(char *, unsigned char **, unsigned char **, unsigned char **, int *, int *);
int write_ppm_image(char *, unsigned char *, unsigned char *, unsigned char *, int, int, char *, int);
void _scc_bit4_err_handle(const _bit4&);
