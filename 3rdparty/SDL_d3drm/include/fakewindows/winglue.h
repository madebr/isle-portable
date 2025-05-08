#ifndef WINGLUE_H
#define WINGLUE_H

#include <SDL3/SDL.h>

#ifdef __cplusplus
#define EXTERN_C extern "C"
#else
#define EXTERN_C extern
#endif

#define FAR

#ifdef _WIN32
#define CDECL __cdecl
#define STDCALL __stdcall
#else
#define CDECL
#define STDCALL
#endif

#define CALLBACK STDCALL

typedef int BOOL;
typedef BOOL WINBOOL;
typedef SDL_GUID GUID;
typedef GUID *LPGUID;
#ifdef __cplusplus
typedef const GUID &REFIID;
#else
typedef const GUID *REFIID;
#endif
typedef GUID IID;
typedef IID *LPIID;
#ifdef __cplusplus
#define REFGUID const GUID &
#else
#define REFGUID const GUID *
#endif
typedef GUID REFCLSID;
typedef Uint32 ULONG;
typedef Sint32 LONG;
typedef Sint32 HRESULT;
typedef Uint32 DWORD;
typedef unsigned int UINT;
typedef Uint16 WORD;
typedef Uint8 BYTE;
typedef BOOL *LPBOOL;
typedef LONG *LPLONG;
typedef DWORD *LPDWORD;
typedef WORD *LPWORD;
typedef void *HMODULE;
typedef void *HWND;
typedef void *HDC;
typedef void *LPVOID;
typedef void *HANDLE;
typedef void *HRSRC;
typedef const char *LPCSTR;
typedef char *LPSTR;
typedef wchar_t *LPWSTR;
typedef Sint64 __int64;
typedef __int64 LONGLONG;
typedef unsigned char byte;
typedef byte cs_byte;
typedef unsigned char boolean;
#ifdef UNICODE
typedef const wchar_t *LPCTSTR;
#else
typedef const char LPCTSTR;
#endif
#define STDAPI HRESULT STDCALL
#define WINAPI STDCALL
#define PASCAL STDCALL

#ifdef INITGUID
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C const GUID name = {{ (l >> 0) & 0xff, (l >> 8) & 0xff, (l >> 16) & 0xff, (l >> 24) & 0xff, (w1 >> 0) & 0xff, (w1 >> 8) & 0xff, (w2 >> 0) & 0xff, (w2 >> 8) & 0xff, b1, b2, b3, b4, b5, b6, b7, b8 }}
#else
/* __declspec(selectany) must be applied to initialized objects on GCC 5 hence must not be used here. */
#define DEFINE_GUID(name,l,w1,w2,b1,b2,b3,b4,b5,b6,b7,b8) EXTERN_C const GUID name
#endif

#ifdef __cplusplus
#define DECLARE_INTERFACE(iface) \
    struct iface
#define DECLARE_INTERFACE_(iface, baseiface) \
    struct iface : public baseiface
#define THIS
#define THIS_
#define PURE =0
#define STDMETHOD(name) virtual HRESULT STDCALL name
#define STDMETHOD_(ret,name) virtual ret STDCALL name
#else
#define DECLARE_INTERFACE(iface) \
    typedef struct iface { const struct iface ## Vtbl *lpVtbl; } iface; typedef const struct iface ## Vtbl iface##Vtbl; struct iface##Vtbl
#define DECLARE_INTERFACE_(iface, baseiface) \
    DECLARE_INTERFACE(iface)
#define THIS INTERFACE*
#define THIS_ INTERFACE*,
#define PURE
#define STDMETHOD(name) HRESULT (STDCALL * name)
#define STDMETHOD_(ret,name) ret (STDCALL * name)
#endif

#ifndef TRUE
#define TRUE 1
#endif
#ifndef FALSE
#define FALSE 1
#endif

#define IUNKNOWN_METHODS(kind) \
    STDMETHOD_(HRESULT,QueryInterface)(THIS_ REFIID riid, void** ppvObject) kind; \
    STDMETHOD_(ULONG,AddRef)(THIS) kind; \
    STDMETHOD_(ULONG,Release)(THIS) kind

#define INTERFACE IUnknown
DECLARE_INTERFACE(IUnknown)
{
    IUNKNOWN_METHODS(PURE);
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IUnknown_QueryInterface(ptr,a,b)    ptr->lpVtbl->QueryInterface(ptr,a,b)
#define IUnknown_AddRef(ptr)                ptr->lpVtbl->AddRef(ptr)
#define IUnknown_Release(ptr)               ptr->lpVtbl->Release(ptr)
#endif

typedef struct {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECT,*PRECT,*NPRECT,*LPRECT;

typedef struct _RECTL {
    LONG left;
    LONG top;
    LONG right;
    LONG bottom;
} RECTL,*PRECTL,*LPRECTL;

typedef const RECTL *LPCRECTL;

typedef struct tagPOINT {
    LONG x;
    LONG y;
} POINT,*PPOINT,*NPPOINT,*LPPOINT;

typedef struct _POINTL {
    LONG x;
    LONG y;
} POINTL,*PPOINTL;

typedef struct tagSIZE {
    LONG cx;
    LONG cy;
} SIZE,*PSIZE,*LPSIZE;

typedef IUnknown *LPUNKNOWN;

typedef struct {
    BYTE peRed;
    BYTE peGreen;
    BYTE peBlue;
    BYTE peFlags;
} PALETTEENTRY,*PPALETTEENTRY,*LPPALETTEENTRY;

typedef struct {
    DWORD dwSize;
    DWORD iType;
    DWORD nCount;
    DWORD nRgnSize;
    RECT rcBound;
} RGNDATAHEADER,*PRGNDATAHEADER;

typedef struct {
    RGNDATAHEADER rdh;
    char Buffer[1];
} RGNDATA,*PRGNDATA,*NPRGNDATA,*LPRGNDATA;

typedef union _LARGE_INTEGER {
  struct {
    DWORD LowPart;
    LONG HighPart;
  };
  struct {
    DWORD LowPart;
    LONG HighPart;
  } u;
  LONGLONG QuadPart;
} LARGE_INTEGER;

typedef struct tagBITMAPINFOHEADER {
    DWORD biSize;
    LONG biWidth;
    LONG biHeight;
    WORD biPlanes;
    WORD biBitCount;
    DWORD biCompression;
    DWORD biSizeImage;
    LONG biXPelsPerMeter;
    LONG biYPelsPerMeter;
    DWORD biClrUsed;
    DWORD biClrImportant;
} BITMAPINFOHEADER,*LPBITMAPINFOHEADER,*PBITMAPINFOHEADER;

typedef struct tagRGBQUAD {
  BYTE rgbBlue;
  BYTE rgbGreen;
  BYTE rgbRed;
  BYTE rgbReserved;
} RGBQUAD;

typedef RGBQUAD *LPRGBQUAD;

typedef struct tagBITMAPINFO {
  BITMAPINFOHEADER bmiHeader;
  RGBQUAD bmiColors[1];
} BITMAPINFO,*LPBITMAPINFO,*PBITMAPINFO;

typedef void *HFONT;
typedef void *HPALETTE;

#define MAXSHORT 0x7fff
#ifndef USHRT_MAX
#define USHRT_MAX 0xffffU
#endif

#ifndef INT_MIN
#define INT_MIN -2147483648
#endif
#ifndef INT_MAX
#define INT_MAX 2147483647
#endif

#define _HRESULT_TYPEDEF_(_sc) ((HRESULT)_sc)

#define S_OK            _HRESULT_TYPEDEF_(0x00000000)
#define E_ABORT         _HRESULT_TYPEDEF_(0x80004004)
#define E_ACCESSDENIED  _HRESULT_TYPEDEF_(0x80070005)
#define E_FAIL          _HRESULT_TYPEDEF_(0x80004005)
#define E_HANDLE        _HRESULT_TYPEDEF_(0x80070006)
#define E_INVALIDARG    _HRESULT_TYPEDEF_(0x80070057)
#define E_NOINTERFACE   _HRESULT_TYPEDEF_(0x80004002)
#define E_NOTIMPL       _HRESULT_TYPEDEF_(0x80004001)
#define E_OUTOFMEMORY   _HRESULT_TYPEDEF_(0x8007000E)
#define E_POINTER       _HRESULT_TYPEDEF_(0x80004003)
#define E_UNEXPECTED    _HRESULT_TYPEDEF_(0x8000FFFF)

#define SUCCEEDED(hr)   ((HRESULT)(hr) >= 0)
#define FAILED(hr)      ((HRESULT)(hr) < 0)

#define MAKE_HRESULT(sev,fac,code) ((HRESULT) (((Uint32)(sev)<<31) | ((Uint32)(fac)<<16) | ((Uint32)(code))))

#ifndef __MSABI_LONG
#  ifndef __LP64__
#    define __MSABI_LONG(x) x ## l
#  else
#    define __MSABI_LONG(x) x
#  endif
#endif

#define BI_RGB __MSABI_LONG(0)
#define BI_RLE8 __MSABI_LONG(1)
#define BI_RLE4 __MSABI_LONG(2)
#define BI_BITFIELDS __MSABI_LONG(3)
#define BI_JPEG __MSABI_LONG(4)
#define BI_PNG __MSABI_LONG(5)

#include <pshpack2.h>
  typedef struct tagBITMAPFILEHEADER {
    WORD bfType;
    DWORD bfSize;
    WORD bfReserved1;
    WORD bfReserved2;
    DWORD bfOffBits;
  } BITMAPFILEHEADER,*LPBITMAPFILEHEADER,*PBITMAPFILEHEADER;
#include <poppack.h>

#define __declspec(X)

#define SRCCOPY (DWORD)0x00CC0020

#define PC_RESERVED 0x01
#define PC_EXPLICIT 0x02
#define PC_NOCOLLAPSE 0x04

#define WM_CLOSE 0x0010
#define WM_QUIT 0x0012
#define WM_TIMER 0x0113
#endif // WINGLUE_H
