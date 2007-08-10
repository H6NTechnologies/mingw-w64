/**
 * This file has no copyright assigned and is placed in the Public Domain.
 * This file is part of the w64 mingw-runtime package.
 * No warranty is given; refer to the file DISCLAIMER within this package.
 */
#ifndef _INC_TIME
#define _INC_TIME

#include <_mingw.h>

#ifndef _WIN32
#error Only Win32 target is supported!
#endif

#pragma pack(push,_CRT_PACKING)

#ifdef __cplusplus
extern "C" {
#endif

#ifndef _CRTIMP
#define _CRTIMP __declspec(dllimport)
#endif

#ifndef _WCHAR_T_DEFINED
#define _WCHAR_T_DEFINED
  typedef unsigned short wchar_t;
#endif

#ifndef _TIME32_T_DEFINED
#define _TIME32_T_DEFINED
  typedef long __time32_t;
#endif

#ifndef _TIME64_T_DEFINED
#define _TIME64_T_DEFINED
#if _INTEGRAL_MAX_BITS >= 64
  typedef __int64 __time64_t;
#endif
#endif

#ifndef _TIME_T_DEFINED
#define _TIME_T_DEFINED
#ifdef _USE_32BIT_TIME_T
  typedef __time32_t time_t;
#else
  typedef __time64_t time_t;
#endif
#endif

#ifndef _CLOCK_T_DEFINED
#define _CLOCK_T_DEFINED
  typedef long clock_t;
#endif

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
  typedef unsigned __int64 size_t;
#else
  typedef int ssize_t;
#endif
#endif

#ifndef _SSIZE_T_DEFINED
#define _SSIZE_T_DEFINED
#ifdef _WIN64
  typedef __int64 ssize_t;
#else
  typedef int ssize_t;
#endif
#endif

#ifndef NULL
#ifdef __cplusplus
#define NULL 0
#else
#define NULL ((void *)0)
#endif
#endif

#ifndef _TM_DEFINED
  struct tm {
    int tm_sec;
    int tm_min;
    int tm_hour;
    int tm_mday;
    int tm_mon;
    int tm_year;
    int tm_wday;
    int tm_yday;
    int tm_isdst;
  };
#define _TM_DEFINED
#endif

#define CLOCKS_PER_SEC 1000

  _CRTIMP int *__cdecl __daylight(void);
#define _daylight (*__daylight())

  _CRTIMP long *__cdecl __dstbias(void);
#define _dstbias (*__dstbias())

  _CRTIMP long *__cdecl __timezone(void);
#define _timezone (*__timezone())
  _CRTIMP char * _tzname[2];

  _CRTIMP errno_t __cdecl _get_daylight(int *_Daylight);
  _CRTIMP errno_t __cdecl _get_dstbias(long *_Daylight_savings_bias);
  _CRTIMP errno_t __cdecl _get_timezone(long *_Timezone);
  _CRTIMP errno_t __cdecl _get_tzname(size_t *_ReturnValue,char *_Buffer,size_t _SizeInBytes,int _Index);
  _CRTIMP char *__cdecl asctime(const struct tm *_Tm);
  _CRTIMP char *__cdecl _ctime32(const __time32_t *_Time);
  _CRTIMP errno_t __cdecl _ctime32_s(char *_Buf,size_t _SizeInBytes,const __time32_t *_Time);
  _CRTIMP clock_t __cdecl clock(void);
  _CRTIMP double __cdecl _difftime32(__time32_t _Time1,__time32_t _Time2);
  _CRTIMP struct tm *__cdecl _gmtime32(const __time32_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime32_s(struct tm *_Tm,const __time32_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime32(const __time32_t *_Time);
  _CRTIMP errno_t __cdecl _localtime32_s(struct tm *_Tm,const __time32_t *_Time);
  _CRTIMP size_t __cdecl strftime(char *_Buf,size_t _SizeInBytes,const char *_Format,const struct tm *_Tm);
  _CRTIMP size_t __cdecl _strftime_l(char *_Buf,size_t _Max_size,const char *_Format,const struct tm *_Tm,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _strdate_s(char *_Buf,size_t _SizeInBytes);
  _CRTIMP char *__cdecl _strdate(char *_Buffer);
  _CRTIMP errno_t __cdecl _strtime_s(char *_Buf ,size_t _SizeInBytes);
  _CRTIMP char *__cdecl _strtime(char *_Buffer);
  _CRTIMP __time32_t __cdecl _time32(__time32_t *_Time);
  _CRTIMP __time32_t __cdecl _mktime32(struct tm *_Tm);
  _CRTIMP __time32_t __cdecl _mkgmtime32(struct tm *_Tm);
#ifdef _POSIX_ || defined(__GNUC__)
  _CRTIMP void __cdecl tzset(void);
#else
  _CRTIMP void __cdecl _tzset(void);
#endif

#if _INTEGRAL_MAX_BITS >= 64
  _CRTIMP double __cdecl _difftime64(__time64_t _Time1,__time64_t _Time2);
  _CRTIMP char *__cdecl _ctime64(const __time64_t *_Time);
  _CRTIMP errno_t __cdecl _ctime64_s(char *_Buf,size_t _SizeInBytes,const __time64_t *_Time);
  _CRTIMP struct tm *__cdecl _gmtime64(const __time64_t *_Time);
  _CRTIMP errno_t __cdecl _gmtime64_s(struct tm *_Tm,const __time64_t *_Time);
  _CRTIMP struct tm *__cdecl _localtime64(const __time64_t *_Time);
  _CRTIMP errno_t __cdecl _localtime64_s(struct tm *_Tm,const __time64_t *_Time);
  _CRTIMP __time64_t __cdecl _mktime64(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _mkgmtime64(struct tm *_Tm);
  _CRTIMP __time64_t __cdecl _time64(__time64_t *_Time);
#endif
  unsigned __cdecl _getsystime(struct tm *_Tm);
  unsigned __cdecl _setsystime(struct tm *_Tm,unsigned _MilliSec);

#ifndef _SIZE_T_DEFINED
#define _SIZE_T_DEFINED
#ifdef _WIN64
  typedef unsigned __int64 size_t;
  typedef __int64 ssize_t;
#else
  typedef unsigned int size_t;
  typedef int ssize_t;
#endif
#endif

#ifndef _WTIME_DEFINED
  _CRTIMP wchar_t *__cdecl _wasctime(const struct tm *_Tm);
  _CRTIMP errno_t __cdecl _wasctime_s(wchar_t *_Buf,size_t _SizeInWords,const struct tm *_Tm);
  _CRTIMP wchar_t *__cdecl _wctime32(const __time32_t *_Time);
  _CRTIMP errno_t __cdecl _wctime32_s(wchar_t *_Buf,size_t _SizeInWords,const __time32_t *_Time);
  _CRTIMP size_t __cdecl wcsftime(wchar_t *_Buf,size_t _SizeInWords,const wchar_t *_Format,const struct tm *_Tm);
  _CRTIMP size_t __cdecl _wcsftime_l(wchar_t *_Buf,size_t _SizeInWords,const wchar_t *_Format,const struct tm *_Tm,_locale_t _Locale);
  _CRTIMP errno_t __cdecl _wstrdate_s(wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wstrdate(wchar_t *_Buffer);
  _CRTIMP errno_t __cdecl _wstrtime_s(wchar_t *_Buf,size_t _SizeInWords);
  _CRTIMP wchar_t *__cdecl _wstrtime(wchar_t *_Buffer);
#if _INTEGRAL_MAX_BITS >= 64
  _CRTIMP wchar_t *__cdecl _wctime64(const __time64_t *_Time);
  _CRTIMP errno_t __cdecl _wctime64_s(wchar_t *_Buf,size_t _SizeInWords,const __time64_t *_Time);
#endif

#ifndef RC_INVOKED
#include <wtime.inl>
#endif

#define _WTIME_DEFINED
#endif

#ifndef RC_INVOKED
#include <time.inl>
#endif

#if !defined(NO_OLDNAMES) || defined(_POSIX)
#define CLK_TCK CLOCKS_PER_SEC

  _CRTIMP extern int daylight;
  _CRTIMP extern long timezone;
  _CRTIMP extern char *tzname[2];
  _CRTIMP void __cdecl tzset(void);
#endif

#ifndef _TIMEVAL_DEFINED /* also in winsock[2].h */
#define _TIMEVAL_DEFINED
struct timeval {
  long tv_sec;
  long tv_usec;
};
#define timerisset(tvp) ((tvp)->tv_sec || (tvp)->tv_usec)
#define timercmp(tvp,uvp,cmp) ((tvp)->tv_sec cmp (uvp)->tv_sec || (tvp)->tv_sec==(uvp)->tv_sec && (tvp)->tv_usec cmp (uvp)->tv_usec)
#define timerclear(tvp) (tvp)->tv_sec = (tvp)->tv_usec = 0
#endif /* _TIMEVAL_DEFINED */

struct timezone {
  int tz_minuteswest;
  int tz_dsttime;
};

/* Disabled for libiberty sake.  */
#if 0
  extern int __cdecl gettimeofday (struct timeval *p, struct timezone *z);
#endif

#ifdef __cplusplus
}
#endif

#pragma pack(pop)
#endif
