#ifndef D3DRM_H
#define D3DRM_H

#include "ddraw.h"

typedef struct IDirect3DRM *LPDIRECT3DRM, **LPLPDIRECT3DRM;

#include "d3drmobj.h"
#include "winglue.h"

#include <SDL3/SDL.h>

DEFINE_GUID(IID_IDirect3DRM,    0x2bc49361, 0x8327, 0x11cf, 0xac, 0x4a, 0x00, 0x00, 0xc0, 0x38, 0x25, 0xa1);
DEFINE_GUID(IID_IDirect3DRM2,   0x4516ecc8, 0x8f20, 0x11d0, 0x9b, 0x6d, 0x00, 0x00, 0xc0, 0x78, 0x1b, 0xc3);
DEFINE_GUID(IID_IDirect3DRM3,   0x4516ec83, 0x8f20, 0x11d0, 0x9b, 0x6d, 0x00, 0x00, 0xc0, 0x78, 0x1b, 0xc3);

#define WIN_TYPES(itype, ptype) \
    typedef struct itype FAR *LP##ptype, FAR **LPLP##ptype
WIN_TYPES(IDirect3DRM, DIRECT3DRM);
WIN_TYPES(IDirect3DRM2, DIRECT3DRM2);
WIN_TYPES(IDirect3DRM3, DIRECT3DRM3);

#define INTERFACE IDirect3DRM
DECLARE_INTERFACE_(IDirect3DRM, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    STDMETHOD(CreateObject)             (THIS_ REFCLSID rclsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) PURE;
    STDMETHOD(CreateFrame)              (THIS_ LPDIRECT3DRMFRAME, LPDIRECT3DRMFRAME *) PURE;
    STDMETHOD(CreateMesh)               (THIS_ LPDIRECT3DRMMESH *) PURE;
    STDMETHOD(CreateMeshBuilder)        (THIS_ LPDIRECT3DRMMESHBUILDER *) PURE;
    STDMETHOD(CreateFace)               (THIS_ LPDIRECT3DRMFACE *) PURE;
    STDMETHOD(CreateAnimation)          (THIS_ LPDIRECT3DRMANIMATION *) PURE;
    STDMETHOD(CreateAnimationSet)       (THIS_ LPDIRECT3DRMANIMATIONSET *) PURE;
    STDMETHOD(CreateTexture)            (THIS_ LPD3DRMIMAGE, LPDIRECT3DRMTEXTURE *) PURE;
    STDMETHOD(CreateLight)              (THIS_ D3DRMLIGHTTYPE, D3DCOLOR, LPDIRECT3DRMLIGHT *) PURE;
    STDMETHOD(CreateLightRGB)           (THIS_ D3DRMLIGHTTYPE, D3DVALUE, D3DVALUE, D3DVALUE, LPDIRECT3DRMLIGHT *) PURE;
    STDMETHOD(CreateMaterial)           (THIS_ D3DVALUE, LPDIRECT3DRMMATERIAL *) PURE;
    STDMETHOD(CreateDevice)             (THIS_ DWORD, DWORD, LPDIRECT3DRMDEVICE *) PURE;
    STDMETHOD(CreateDeviceFromSurface)  (THIS_ LPGUID lpGUID, LPDIRECTDRAW lpDD, LPDIRECTDRAWSURFACE lpDDSBack, LPDIRECT3DRMDEVICE *) PURE;
    STDMETHOD(CreateDeviceFromD3D)      (THIS_ LPDIRECT3D lpD3D, LPDIRECT3DDEVICE lpD3DDev, LPDIRECT3DRMDEVICE *) PURE;
    STDMETHOD(CreateDeviceFromClipper)  (THIS_ LPDIRECTDRAWCLIPPER lpDDClipper, LPGUID lpGUID, int width, int height, LPDIRECT3DRMDEVICE *) PURE;
    STDMETHOD(CreateTextureFromSurface) (THIS_ LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DRMTEXTURE *) PURE;
    STDMETHOD(CreateShadow)             (THIS_ LPDIRECT3DRMVISUAL, LPDIRECT3DRMLIGHT, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMVISUAL *) PURE;
    STDMETHOD(CreateViewport)           (THIS_ LPDIRECT3DRMDEVICE, LPDIRECT3DRMFRAME, DWORD, DWORD, DWORD, DWORD, LPDIRECT3DRMVIEWPORT *) PURE;
    STDMETHOD(CreateWrap)               (THIS_ D3DRMWRAPTYPE, LPDIRECT3DRMFRAME, D3DVALUE ox, D3DVALUE oy, D3DVALUE oz, D3DVALUE dx, D3DVALUE dy, D3DVALUE dz, D3DVALUE ux, D3DVALUE uy, D3DVALUE uz, D3DVALUE ou, D3DVALUE ov, D3DVALUE su, D3DVALUE sv, LPDIRECT3DRMWRAP *) PURE;
    STDMETHOD(CreateUserVisual)         (THIS_ D3DRMUSERVISUALCALLBACK, LPVOID lPArg, LPDIRECT3DRMUSERVISUAL *) PURE;
    STDMETHOD(LoadTexture)              (THIS_ const char *, LPDIRECT3DRMTEXTURE *) PURE;
    STDMETHOD(LoadTextureFromResource)  (THIS_ HRSRC rs, LPDIRECT3DRMTEXTURE *) PURE;
    STDMETHOD(SetSearchPath)            (THIS_ LPCSTR) PURE;
    STDMETHOD(AddSearchPath)            (THIS_ LPCSTR) PURE;
    STDMETHOD(GetSearchPath)            (THIS_ DWORD *size_return, LPSTR path_return) PURE;
    STDMETHOD(SetDefaultTextureColors)  (THIS_ DWORD) PURE;
    STDMETHOD(SetDefaultTextureShades)  (THIS_ DWORD) PURE;
    STDMETHOD(GetDevices)               (THIS_ LPDIRECT3DRMDEVICEARRAY *) PURE;
    STDMETHOD(GetNamedObject)           (THIS_ const char *, LPDIRECT3DRMOBJECT *) PURE;
    STDMETHOD(EnumerateObjects)         (THIS_ D3DRMOBJECTCALLBACK, LPVOID) PURE;
    STDMETHOD(Load)                     (THIS_ LPVOID, LPVOID, LPIID *, DWORD, D3DRMLOADOPTIONS, D3DRMLOADCALLBACK, LPVOID, D3DRMLOADTEXTURECALLBACK, LPVOID, LPDIRECT3DRMFRAME) PURE;
    STDMETHOD(Tick)                     (THIS_ D3DVALUE) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirect3DRM_QueryInterface(ptr,a,b)                             (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirect3DRM_AddRef(ptr)                                         (ptr)->lpVtbl->AddRef(ptr)
#define IDirect3DRM_Release(ptr)                                        (ptr)->lpVtbl->Release(ptr)
#define IDirect3DRM_CreateFrame(ptr,a,b)                                (ptr)->lpVtbl->CreateFrame(ptr,a,b)
#define IDirect3DRM_CreateMesh(ptr,a)                                   (ptr)->lpVtbl->CreateMesh(ptr,a)
#define IDirect3DRM_CreateMeshBuilder(ptr,a)                            (ptr)->lpVtbl->CreateMeshBuilder(ptr,a)
#define IDirect3DRM_CreateFace(ptr,a)                                   (ptr)->lpVtbl->CreateFace(ptr,a)
#define IDirect3DRM_CreateAnimation(ptr,a)                              (ptr)->lpVtbl->CreateAnimation(ptr,a)
#define IDirect3DRM_CreateAnimationSet(ptr,a)                           (ptr)->lpVtbl->CreateAnimationSet(ptr,a)
#define IDirect3DRM_CreateTexture(ptr,a,b)                              (ptr)->lpVtbl->CreateTexture(ptr,a,b)
#define IDirect3DRM_CreateLight(ptr,a,b,c)                              (ptr)->lpVtbl->CreateLight(ptr,a,b,c)
#define IDirect3DRM_CreateLightRGB(ptr,a,b,c,d,e)                       (ptr)->lpVtbl->CreateLightRGB(ptr,a,b,c,d,e)
#define IDirect3DRM_CreateMaterial(ptr,a,b)                             (ptr)->lpVtbl->CreateMaterial(ptr,a,b)
#define IDirect3DRM_CreateDevice(ptr,a,b,c)                             (ptr)->lpVtbl->CreateDevice(ptr,a,b,c)
#define IDirect3DRM_CreateDeviceFromSurface(ptr,a,b,c,d)                (ptr)->lpVtbl->CreateDeviceFromSurface(ptr,a,b,c,d)
#define IDirect3DRM_CreateDeviceFromD3D(ptr,a,b,c)                      (ptr)->lpVtbl->CreateDeviceFromD3D(ptr,a,b,c)
#define IDirect3DRM_CreateDeviceFromClipper(ptr,a,b,c,d,e)              (ptr)->lpVtbl->CreateDeviceFromClipper(ptr,a,b,c,d,e)
#define IDirect3DRM_CreateTextureFromSurface(ptr,a,b)                   (ptr)->lpVtbl->CreateTextureFromSurface(ptr,a,b)
#define IDirect3DRM_CreateShadow(ptr,a,b,c,d,e,f,g,h,i)                 (ptr)->lpVtbl->CreateShadow(ptr,a,b,c,d,e,f,g,h,i)
#define IDirect3DRM_CreateViewport(ptr,a,b,c,d,e,f,g)                   (ptr)->lpVtbl->CreateViewport(ptr,a,b,c,d,e,f,g)
#define IDirect3DRM_CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     (ptr)->lpVtbl->CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define IDirect3DRM_CreateUserVisual(ptr,a,b,c)                         (ptr)->lpVtbl->CreateUserVisual(ptr,a,b,c)
#define IDirect3DRM_LoadTexture(ptr,a,b)                                (ptr)->lpVtbl->LoadTexture(ptr,a,b)
#define IDirect3DRM_LoadTextureFromResource(ptr,a,b)                    (ptr)->lpVtbl->LoadTextureFromResource(ptr,a,b)
#define IDirect3DRM_SetSearchPath(ptr,a)                                (ptr)->lpVtbl->SetSearchPath(ptr,a)
#define IDirect3DRM_AddSearchPath(ptr,a)                                (ptr)->lpVtbl->AddSearchPath(ptr,a)
#define IDirect3DRM_GetSearchPath(ptr,a,b)                              (ptr)->lpVtbl->GetSearchPath(ptr,a,b)
#define IDirect3DRM_SetDefaultTextureColors(ptr,a)                      (ptr)->lpVtbl->SetDefaultTextureColors(ptr,a)
#define IDirect3DRM_SetDefaultTextureShades(ptr,a)                      (ptr)->lpVtbl->SetDefaultTextureShades(ptr,a)
#define IDirect3DRM_GetDevices(ptr,a)                                   (ptr)->lpVtbl->GetDevices(ptr,a)
#define IDirect3DRM_GetNamedObject(ptr,a,b)                             (ptr)->lpVtbl->GetNamedObject(ptr,a,b)
#define IDirect3DRM_EnumerateObjects(ptr,a,b)                           (ptr)->lpVtbl->EnumerateObjects(ptr,a,b)
#define IDirect3DRM_Load(ptr,a,b,c,d,e,f,g,h,i,j)                       (ptr)->lpVtbl->Load(ptr,a,b,c,d,e,f,g,h,i,j)
#define IDirect3DRM_Tick(ptr,a)                                         (ptr)->lpVtbl->Tick(ptr,a)
#else
#define IDirect3DRM_QueryInterface(ptr,a,b)                             (ptr)->QueryInterface(a,b)
#define IDirect3DRM_AddRef(ptr)                                         (ptr)->AddRef()
#define IDirect3DRM_Release(ptr)                                        (ptr)->Release()
#define IDirect3DRM_CreateFrame(ptr,a,b)                                (ptr)->CreateFrame(a,b)
#define IDirect3DRM_CreateMesh(ptr,a)                                   (ptr)->CreateMesh(a)
#define IDirect3DRM_CreateMeshBuilder(ptr,a)                            (ptr)->CreateMeshBuilder(a)
#define IDirect3DRM_CreateFace(ptr,a)                                   (ptr)->CreateFace(a)
#define IDirect3DRM_CreateAnimation(ptr,a)                              (ptr)->CreateAnimation(a)
#define IDirect3DRM_CreateAnimationSet(ptr,a)                           (ptr)->CreateAnimationSet(a)
#define IDirect3DRM_CreateTexture(ptr,a,b)                              (ptr)->CreateTexture(a,b)
#define IDirect3DRM_CreateLight(ptr,a,b,c)                              (ptr)->CreateLight(a,b,c)
#define IDirect3DRM_CreateLightRGB(ptr,a,b,c,d,e)                       (ptr)->CreateLightRGB(a,b,c,d,e)
#define IDirect3DRM_CreateMaterial(ptr,a,b)                             (ptr)->CreateMaterial(a,b)
#define IDirect3DRM_CreateDevice(ptr,a,b,c)                             (ptr)->CreateDevice(a,b,c)
#define IDirect3DRM_CreateDeviceFromSurface(ptr,a,b,c,d)                (ptr)->CreateDeviceFromSurface(a,b,c,d)
#define IDirect3DRM_CreateDeviceFromD3D(ptr,a,b,c)                      (ptr)->CreateDeviceFromD3D(a,b,c)
#define IDirect3DRM_CreateDeviceFromClipper(ptr,a,b,c,d,e)              (ptr)->CreateDeviceFromClipper(a,b,c,d,e)
#define IDirect3DRM_CreateTextureFromSurface(ptr,a,b)                   (ptr)->CreateTextureFromSurface(a,b)
#define IDirect3DRM_CreateShadow(ptr,a,b,c,d,e,f,g,h,i)                 (ptr)->CreateShadow(a,b,c,d,e,f,g,h,i)
#define IDirect3DRM_CreateViewport(ptr,a,b,c,d,e,f,g)                   (ptr)->CreateViewport(a,b,c,d,e,f,g)
#define IDirect3DRM_CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)     (ptr)->CreateWrap(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define IDirect3DRM_CreateUserVisual(ptr,a,b,c)                         (ptr)->CreateUserVisual(a,b,c)
#define IDirect3DRM_LoadTexture(ptr,a,b)                                (ptr)->LoadTexture(a,b)
#define IDirect3DRM_LoadTextureFromResource(ptr,a,b)                    (ptr)->LoadTextureFromResource(a,b)
#define IDirect3DRM_SetSearchPath(ptr,a)                                (ptr)->SetSearchPath(a)
#define IDirect3DRM_AddSearchPath(ptr,a)                                (ptr)->AddSearchPath(a)
#define IDirect3DRM_GetSearchPath(ptr,a,b)                              (ptr)->GetSearchPath(a,b)
#define IDirect3DRM_SetDefaultTextureColors(ptr,a)                      (ptr)->SetDefaultTextureColors(a)
#define IDirect3DRM_SetDefaultTextureShades(ptr,a)                      (ptr)->SetDefaultTextureShades(a)
#define IDirect3DRM_GetDevices(ptr,a)                                   (ptr)->GetDevices(a)
#define IDirect3DRM_GetNamedObject(ptr,a,b)                             (ptr)->GetNamedObject(a,b)
#define IDirect3DRM_EnumerateObjects(ptr,a,b)                           (ptr)->EnumerateObjects(a,b)
#define IDirect3DRM_Load(ptr,a,b,c,d,e,f,g,h,i,j)                       (ptr)->Load(a,b,c,d,e,f,g,h,i,j)
#define IDirect3DRM_Tick(ptr,a)                                         (ptr)->Tick(a)
#endif

#define INTERFACE IDirect3DRM2
DECLARE_INTERFACE_(IDirect3DRM2, IUnknown)
{
    /*0x00*/IUNKNOWN_METHODS(PURE);
    /*0x0c*/STDMETHOD(CreateObject)             (THIS_ REFCLSID rclsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) PURE;
    /*0x10*/STDMETHOD(CreateFrame)              (THIS_ LPDIRECT3DRMFRAME, LPDIRECT3DRMFRAME2 *) PURE;
    /*0x14*/STDMETHOD(CreateMesh)               (THIS_ LPDIRECT3DRMMESH *) PURE;
    /*0x18*/STDMETHOD(CreateMeshBuilder)        (THIS_ LPDIRECT3DRMMESHBUILDER2 *) PURE;
    /*0x1c*/STDMETHOD(CreateFace)               (THIS_ LPDIRECT3DRMFACE *) PURE;
    /*0x20*/STDMETHOD(CreateAnimation)          (THIS_ LPDIRECT3DRMANIMATION *) PURE;
    /*0x24*/STDMETHOD(CreateAnimationSet)       (THIS_ LPDIRECT3DRMANIMATIONSET *) PURE;
    /*0x28*/STDMETHOD(CreateTexture)            (THIS_ LPD3DRMIMAGE, LPDIRECT3DRMTEXTURE2 *) PURE;
    /*0x2c*/STDMETHOD(CreateLight)              (THIS_ D3DRMLIGHTTYPE, D3DCOLOR, LPDIRECT3DRMLIGHT *) PURE;
    /*0x30*/STDMETHOD(CreateLightRGB)           (THIS_ D3DRMLIGHTTYPE, D3DVALUE, D3DVALUE, D3DVALUE, LPDIRECT3DRMLIGHT *) PURE;
    /*0x34*/STDMETHOD(CreateMaterial)           (THIS_ D3DVALUE, LPDIRECT3DRMMATERIAL *) PURE;
    /*0x38*/STDMETHOD(CreateDevice)             (THIS_ DWORD, DWORD, LPDIRECT3DRMDEVICE2 *) PURE;
    /*0x3c*/STDMETHOD(CreateDeviceFromSurface)  (THIS_ LPGUID lpGUID, LPDIRECTDRAW lpDD, LPDIRECTDRAWSURFACE lpDDSBack, LPDIRECT3DRMDEVICE2 *) PURE;
    /*0x40*/STDMETHOD(CreateDeviceFromD3D)      (THIS_ LPDIRECT3D2 lpD3D, LPDIRECT3DDEVICE2 lpD3DDev, LPDIRECT3DRMDEVICE2 *) PURE;
    /*0x44*/STDMETHOD(CreateDeviceFromClipper)  (THIS_ LPDIRECTDRAWCLIPPER lpDDClipper, LPGUID lpGUID, int width, int height, LPDIRECT3DRMDEVICE2 *) PURE;
    /*0x48*/STDMETHOD(CreateTextureFromSurface) (THIS_ LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DRMTEXTURE2 *) PURE;
    /*0x4c*/STDMETHOD(CreateShadow)             (THIS_ LPDIRECT3DRMVISUAL, LPDIRECT3DRMLIGHT, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMVISUAL *) PURE;
    /*0x50*/STDMETHOD(CreateViewport)           (THIS_ LPDIRECT3DRMDEVICE, LPDIRECT3DRMFRAME, DWORD, DWORD, DWORD, DWORD, LPDIRECT3DRMVIEWPORT *) PURE;
    /*0x54*/STDMETHOD(CreateWrap)               (THIS_ D3DRMWRAPTYPE, LPDIRECT3DRMFRAME, D3DVALUE ox, D3DVALUE oy, D3DVALUE oz, D3DVALUE dx, D3DVALUE dy, D3DVALUE dz, D3DVALUE ux, D3DVALUE uy, D3DVALUE uz, D3DVALUE ou, D3DVALUE ov, D3DVALUE su, D3DVALUE sv, LPDIRECT3DRMWRAP *) PURE;
    /*0x58*/STDMETHOD(CreateUserVisual)         (THIS_ D3DRMUSERVISUALCALLBACK, LPVOID lPArg, LPDIRECT3DRMUSERVISUAL *) PURE;
    /*0x5c*/STDMETHOD(LoadTexture)              (THIS_ const char *, LPDIRECT3DRMTEXTURE2 *) PURE;
    /*0x60*/STDMETHOD(LoadTextureFromResource)  (THIS_ HMODULE HMODULE, LPCTSTR strName, LPCTSTR strType, LPDIRECT3DRMTEXTURE2 *) PURE;
    /*0x64*/STDMETHOD(SetSearchPath)            (THIS_ LPCSTR) PURE;
    /*0x68*/STDMETHOD(AddSearchPath)            (THIS_ LPCSTR) PURE;
    /*0x6c*/STDMETHOD(GetSearchPath)            (THIS_ DWORD *size_return, LPSTR path_return) PURE;
    /*0x70*/STDMETHOD(SetDefaultTextureColors)  (THIS_ DWORD) PURE;
    /*0x74*/STDMETHOD(SetDefaultTextureShades)  (THIS_ DWORD) PURE;
    /*0x78*/STDMETHOD(GetDevices)               (THIS_ LPDIRECT3DRMDEVICEARRAY *) PURE;
    /*0x7c*/STDMETHOD(GetNamedObject)           (THIS_ const char *, LPDIRECT3DRMOBJECT *) PURE;
    /*0x80*/STDMETHOD(EnumerateObjects)         (THIS_ D3DRMOBJECTCALLBACK, LPVOID) PURE;
    /*0x84*/STDMETHOD(Load)                     (THIS_ LPVOID, LPVOID, LPIID *, DWORD, D3DRMLOADOPTIONS, D3DRMLOADCALLBACK, LPVOID, D3DRMLOADTEXTURECALLBACK, LPVOID, LPDIRECT3DRMFRAME) PURE;
    /*0x88*/STDMETHOD(Tick)                     (THIS_ D3DVALUE) PURE;
    /*0x8c*/STDMETHOD(CreateProgressiveMeshCreateProgressiveMesh)    (THIS_ LPDIRECT3DRMPROGRESSIVEMESH *) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirect3DRM2_QueryInterface(ptr, a, b)                          (ptr)->lpVtbl->QueryInterface(ptr, a, b)
#define IDirect3DRM2_AddRef(ptr)                                        (ptr)->lpVtbl->AddRef(ptr)
#define IDirect3DRM2_Release(ptr)                                       (ptr)->lpVtbl->Release(ptr)
#define IDirect3DRM2_CreateObject(ptr,a,b,c,d)                          (ptr)->lpVtbl->CreateObject(ptr,a,b,c,d)
#define IDirect3DRM2_CreateFrame(ptr,a,b)                               (ptr)->lpVtbl->CreateFrame(ptr,a,b)
#define IDirect3DRM2_CreateMesh(ptr,a)                                  (ptr)->lpVtbl->CreateMesh(ptr,a)
#define IDirect3DRM2_CreateMeshBuilder(ptr,a)                           (ptr)->lpVtbl->CreateMeshBuilder(ptr,a)
#define IDirect3DRM2_CreateFace(ptr,a)                                  (ptr)->lpVtbl->CreateFace(ptr,a)
#define IDirect3DRM2_CreateAnimation(ptr,a)                             (ptr)->lpVtbl->CreateAnimation(ptr,a)
#define IDirect3DRM2_CreateAnimationSet(ptr,a)                          (ptr)->lpVtbl->CreateAnimationSet(ptr,a)
#define IDirect3DRM2_CreateTexture(ptr,a,b)                             (ptr)->lpVtbl->CreateTexture(ptr,a,b)
#define IDirect3DRM2_CreateLight(ptr,a,b,c)                             (ptr)->lpVtbl->CreateLight(ptr,a,b,c)
#define IDirect3DRM2_CreateLightRGB(ptr,a,b,c,d,e)                      (ptr)->lpVtbl->CreateLightRGB(ptr,a,b,c,d,e)
#define IDirect3DRM2_CreateMaterial(ptr,a,b)                            (ptr)->lpVtbl->CreateMaterial(ptr,a,b)
#define IDirect3DRM2_CreateDevice(ptr,a,b,c)                            (ptr)->lpVtbl->CreateDevice(ptr,a,b,c)
#define IDirect3DRM2_CreateDeviceFromSurface(ptr,a,b,c,d)               (ptr)->lpVtbl->CreateDeviceFromSurface(ptr,a,b,c,d)
#define IDirect3DRM2_CreateDeviceFromD3D(ptr,a,b,c)                     (ptr)->lpVtbl->CreateDeviceFromD3D(ptr,a,b,c)
#define IDirect3DRM2_CreateDeviceFromClipper(ptr,a,b,c,d,e)             (ptr)->lpVtbl->CreateDeviceFromClipper(ptr,a,b,c,d,e)
#define IDirect3DRM2_CreateTextureFromSurface(ptr,a,b)                  (ptr)->lpVtbl->CreateTextureFromSurface(ptr,a,b)
#define IDirect3DRM2_CreateShadow(ptr,a,b,c,d,e,f,g,h,i)                (ptr)->lpVtbl->CreateShadow(ptr,a,b,c,d,e,f,g,h,i)
#define IDirect3DRM2_CreateViewport(ptr,a,b,c,d,e,f,g)                  (ptr)->lpVtbl->CreateViewport(ptr,a,b,c,d,e,f,g)
#define IDirect3DRM2_CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)    (ptr)->lpVtbl->CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define IDirect3DRM2_CreateUserVisual(ptr,a,b,c)                        (ptr)->lpVtbl->CreateUserVisual(ptr,a,b,c)
#define IDirect3DRM2_LoadTexture(ptr,a,b)                               (ptr)->lpVtbl->LoadTexture(ptr,a,b)
#define IDirect3DRM2_LoadTextureFromResource(ptr,a,b,c,d)               (ptr)->lpVtbl->LoadTextureFromResource(ptr,a,b,c,d)
#define IDirect3DRM2_SetSearchPath(ptr,a)                               (ptr)->lpVtbl->SetSearchPath(ptr,a)
#define IDirect3DRM2_AddSearchPath(ptr,a)                               (ptr)->lpVtbl->AddSearchPath(ptr,a)
#define IDirect3DRM2_GetSearchPath(ptr,a,b)                             (ptr)->lpVtbl->GetSearchPath(ptr,a,b)
#define IDirect3DRM2_SetDefaultTextureColors(ptr,a)                     (ptr)->lpVtbl->SetDefaultTextureColors(ptr,a)
#define IDirect3DRM2_SetDefaultTextureShades(ptr,a)                     (ptr)->lpVtbl->SetDefaultTextureShades(ptr,a)
#define IDirect3DRM2_GetDevices(ptr,a)                                  (ptr)->lpVtbl->GetDevices(ptr,a)
#define IDirect3DRM2_GetNamedObject(ptr,a,b)                            (ptr)->lpVtbl->GetNamedObject(ptr,a,b)
#define IDirect3DRM2_EnumerateObjects(ptr,a,b)                          (ptr)->lpVtbl->EnumerateObjects(ptr,a,b)
#define IDirect3DRM2_Load(ptr,a,b,c,d,e,f,g,h,i,j)                      (ptr)->lpVtbl->Load(ptr,a,b,c,d,e,f,g,h,i,j)
#define IDirect3DRM2_Tick(ptr,a)                                        (ptr)->lpVtbl->Tick(ptr,a)
#define IDirect3DRM2_CreateProgressiveMesh(ptr,a)                       (ptr)->lpVtbl->CreateProgressiveMesh(ptr,a)
#else
#define IDirect3DRM2_QueryInterface(ptr, a, b)                          (ptr)->QueryInterface(a, b)
#define IDirect3DRM2_AddRef(ptr)                                        (ptr)->AddRef()
#define IDirect3DRM2_Release(ptr)                                       (ptr)->Release()
#define IDirect3DRM2_CreateObject(ptr,a,b,c,d)                          (ptr)->CreateObject(a,b,c,d)
#define IDirect3DRM2_CreateFrame(ptr,a,b)                               (ptr)->CreateFrame(a,b)
#define IDirect3DRM2_CreateMesh(ptr,a)                                  (ptr)->CreateMesh(a)
#define IDirect3DRM2_CreateMeshBuilder(ptr,a)                           (ptr)->CreateMeshBuilder(a)
#define IDirect3DRM2_CreateFace(ptr,a)                                  (ptr)->CreateFace(a)
#define IDirect3DRM2_CreateAnimation(ptr,a)                             (ptr)->CreateAnimation(a)
#define IDirect3DRM2_CreateAnimationSet(ptr,a)                          (ptr)->CreateAnimationSet(a)
#define IDirect3DRM2_CreateTexture(ptr,a,b)                             (ptr)->CreateTexture(a,b)
#define IDirect3DRM2_CreateLight(ptr,a,b,c)                             (ptr)->CreateLight(a,b,c)
#define IDirect3DRM2_CreateLightRGB(ptr,a,b,c,d,e)                      (ptr)->CreateLightRGB(a,b,c,d,e)
#define IDirect3DRM2_CreateMaterial(ptr,a,b)                            (ptr)->CreateMaterial(a,b)
#define IDirect3DRM2_CreateDevice(ptr,a,b,c)                            (ptr)->CreateDevice(a,b,c)
#define IDirect3DRM2_CreateDeviceFromSurface(ptr,a,b,c,d)               (ptr)->CreateDeviceFromSurface(a,b,c,d)
#define IDirect3DRM2_CreateDeviceFromD3D(ptr,a,b,c)                     (ptr)->CreateDeviceFromD3D(a,b,c)
#define IDirect3DRM2_CreateDeviceFromClipper(ptr,a,b,c,d,e)             (ptr)->CreateDeviceFromClipper(a,b,c,d,e)
#define IDirect3DRM2_CreateTextureFromSurface(ptr,a,b)                  (ptr)->CreateTextureFromSurface(a,b)
#define IDirect3DRM2_CreateShadow(ptr,a,b,c,d,e,f,g,h,i)                (ptr)->CreateShadow(a,b,c,d,e,f,g,h,i)
#define IDirect3DRM2_CreateViewport(ptr,a,b,c,d,e,f,g)                  (ptr)->CreateViewport(a,b,c,d,e,f,g)
#define IDirect3DRM2_CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)    (ptr)->CreateWrap(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define IDirect3DRM2_CreateUserVisual(ptr,a,b,c)                        (ptr)->CreateUserVisual(a,b,c)
#define IDirect3DRM2_LoadTexture(ptr,a,b)                               (ptr)->LoadTexture(a,b)
#define IDirect3DRM2_LoadTextureFromResource(ptr,a,b,c,d)               (ptr)->LoadTextureFromResource(a,b,c,d)
#define IDirect3DRM2_SetSearchPath(ptr,a)                               (ptr)->SetSearchPath(a)
#define IDirect3DRM2_AddSearchPath(ptr,a)                               (ptr)->AddSearchPath(a)
#define IDirect3DRM2_GetSearchPath(ptr,a,b)                             (ptr)->GetSearchPath(a,b)
#define IDirect3DRM2_SetDefaultTextureColors(ptr,a)                     (ptr)->SetDefaultTextureColors(a)
#define IDirect3DRM2_SetDefaultTextureShades(ptr,a)                     (ptr)->SetDefaultTextureShades(a)
#define IDirect3DRM2_GetDevices(ptr,a)                                  (ptr)->GetDevices(a)
#define IDirect3DRM2_GetNamedObject(ptr,a,b)                            (ptr)->GetNamedObject(a,b)
#define IDirect3DRM2_EnumerateObjects(ptr,a,b)                          (ptr)->EnumerateObjects(a,b)
#define IDirect3DRM2_Load(ptr,a,b,c,d,e,f,g,h,i,j)                      (ptr)->Load(a,b,c,d,e,f,g,h,i,j)
#define IDirect3DRM2_Tick(ptr,a)                                        (ptr)->Tick(a)
#define IDirect3DRM2_CreateProgressiveMesh(ptr,a)                       (ptr)->CreateProgressiveMesh(a)
#endif

#define INTERFACE IDirect3DRM3
DECLARE_INTERFACE_(IDirect3DRM3, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    STDMETHOD(CreateObject)             (THIS_ REFCLSID rclsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) PURE;
    STDMETHOD(CreateFrame)              (THIS_ LPDIRECT3DRMFRAME3, LPDIRECT3DRMFRAME3 *) PURE;
    STDMETHOD(CreateMesh)               (THIS_ LPDIRECT3DRMMESH *) PURE;
    STDMETHOD(CreateMeshBuilder)        (THIS_ LPDIRECT3DRMMESHBUILDER3 *) PURE;
    STDMETHOD(CreateFace)               (THIS_ LPDIRECT3DRMFACE2 *) PURE;
    STDMETHOD(CreateAnimation)          (THIS_ LPDIRECT3DRMANIMATION2 *) PURE;
    STDMETHOD(CreateAnimationSet)       (THIS_ LPDIRECT3DRMANIMATIONSET2 *) PURE;
    STDMETHOD(CreateTexture)            (THIS_ LPD3DRMIMAGE, LPDIRECT3DRMTEXTURE3 *) PURE;
    STDMETHOD(CreateLight)              (THIS_ D3DRMLIGHTTYPE, D3DCOLOR, LPDIRECT3DRMLIGHT *) PURE;
    STDMETHOD(CreateLightRGB)           (THIS_ D3DRMLIGHTTYPE, D3DVALUE, D3DVALUE, D3DVALUE, LPDIRECT3DRMLIGHT *) PURE;
    STDMETHOD(CreateMaterial)           (THIS_ D3DVALUE, LPDIRECT3DRMMATERIAL2 *) PURE;
    STDMETHOD(CreateDevice)             (THIS_ DWORD, DWORD, LPDIRECT3DRMDEVICE3 *) PURE;
    STDMETHOD(CreateDeviceFromSurface)  (THIS_ LPGUID lpGUID, LPDIRECTDRAW lpDD, LPDIRECTDRAWSURFACE lpDDSBack, DWORD dwFlags, LPDIRECT3DRMDEVICE3 * ) PURE;
    STDMETHOD(CreateDeviceFromD3D)      (THIS_ LPDIRECT3D2 lpD3D, LPDIRECT3DDEVICE2 lpD3DDev, LPDIRECT3DRMDEVICE3 * ) PURE;
    STDMETHOD(CreateDeviceFromClipper)  (THIS_ LPDIRECTDRAWCLIPPER lpDDClipper, LPGUID lpGUID, int width, int height, LPDIRECT3DRMDEVICE3 *) PURE;
    STDMETHOD(CreateTextureFromSurface) (THIS_ LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DRMTEXTURE3 *) PURE;
    STDMETHOD(CreateShadow)             (THIS_ LPUNKNOWN, LPDIRECT3DRMLIGHT, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMSHADOW2 *) PURE;
    STDMETHOD(CreateViewport)           (THIS_ LPDIRECT3DRMDEVICE3, LPDIRECT3DRMFRAME3, DWORD, DWORD, DWORD, DWORD, LPDIRECT3DRMVIEWPORT2 * ) PURE;
    STDMETHOD(CreateWrap)               (THIS_ D3DRMWRAPTYPE, LPDIRECT3DRMFRAME3, D3DVALUE ox, D3DVALUE oy, D3DVALUE oz, D3DVALUE dx, D3DVALUE dy, D3DVALUE dz, D3DVALUE ux, D3DVALUE uy, D3DVALUE uz, D3DVALUE ou, D3DVALUE ov, D3DVALUE su, D3DVALUE sv, LPDIRECT3DRMWRAP *) PURE;
    STDMETHOD(CreateUserVisual)         (THIS_ D3DRMUSERVISUALCALLBACK, LPVOID lPArg, LPDIRECT3DRMUSERVISUAL *) PURE;
    STDMETHOD(LoadTexture)              (THIS_ const char *, LPDIRECT3DRMTEXTURE3 *) PURE;
    STDMETHOD(LoadTextureFromResource)  (THIS_ HMODULE HMODULE, LPCTSTR strName, LPCTSTR strType, LPDIRECT3DRMTEXTURE3 *) PURE;
    STDMETHOD(SetSearchPath)            (THIS_ LPCSTR) PURE;
    STDMETHOD(AddSearchPath)            (THIS_ LPCSTR) PURE;
    STDMETHOD(GetSearchPath)            (THIS_ DWORD *size_return, LPSTR path_return) PURE;
    STDMETHOD(SetDefaultTextureColors)  (THIS_ DWORD) PURE;
    STDMETHOD(SetDefaultTextureShades)  (THIS_ DWORD) PURE;
    STDMETHOD(GetDevices)               (THIS_ LPDIRECT3DRMDEVICEARRAY *) PURE;
    STDMETHOD(GetNamedObject)           (THIS_ const char *, LPDIRECT3DRMOBJECT *) PURE;
    STDMETHOD(EnumerateObjects)         (THIS_ D3DRMOBJECTCALLBACK, LPVOID) PURE;
    STDMETHOD(Load)                     (THIS_ LPVOID, LPVOID, LPIID *, DWORD, D3DRMLOADOPTIONS, D3DRMLOADCALLBACK, LPVOID, D3DRMLOADTEXTURE3CALLBACK, LPVOID, LPDIRECT3DRMFRAME3 ) PURE;
    STDMETHOD(Tick)                     (THIS_ D3DVALUE) PURE;
    STDMETHOD(CreateProgressiveMesh)    (THIS_ LPDIRECT3DRMPROGRESSIVEMESH *) PURE;
    STDMETHOD(RegisterClient)           (THIS_ REFGUID rguid, LPDWORD lpdwID) PURE;
    STDMETHOD(UnregisterClient)         (THIS_ REFGUID rguid) PURE;
    STDMETHOD(CreateClippedVisual)      (THIS_ LPDIRECT3DRMVISUAL, LPDIRECT3DRMCLIPPEDVISUAL *) PURE;
    STDMETHOD(SetOptions)               (THIS_ DWORD options) PURE;
    STDMETHOD(GetOptions)               (THIS_ LPDWORD options) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirect3DRM3_QueryInterface(ptr,a,b)                            (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirect3DRM3_AddRef(ptr)                                        (ptr)->lpVtbl->AddRef(ptr)
#define IDirect3DRM3_Release(ptr)                                       (ptr)->lpVtbl->Release(ptr)
#define IDirect3DRM3_CreateObject(ptr,a,b,c,d)                          (ptr)->lpVtbl->CreateObject(ptr,a,b,c,d)
#define IDirect3DRM3_CreateFrame(ptr,a,b)                               (ptr)->lpVtbl->CreateFrame(ptr,a,b)
#define IDirect3DRM3_CreateMesh(ptr,a)                                  (ptr)->lpVtbl->CreateMesh(ptr,a)
#define IDirect3DRM3_CreateMeshBuilder(ptr,a)                           (ptr)->lpVtbl->CreateMeshBuilder(ptr,a)
#define IDirect3DRM3_CreateFace(ptr,a)                                  (ptr)->lpVtbl->CreateFace(ptr,a)
#define IDirect3DRM3_CreateAnimation(ptr,a)                             (ptr)->lpVtbl->CreateAnimation(ptr,a)
#define IDirect3DRM3_CreateAnimationSet(ptr,a)                          (ptr)->lpVtbl->CreateAnimationSet(ptr,a)
#define IDirect3DRM3_CreateTexture(ptr,a,b)                             (ptr)->lpVtbl->CreateTexture(ptr,a,b)
#define IDirect3DRM3_CreateLight(ptr,a,b,c)                             (ptr)->lpVtbl->CreateLight(ptr,a,b,c)
#define IDirect3DRM3_CreateLightRGB(ptr,a,b,c,d,e)                      (ptr)->lpVtbl->CreateLightRGB(ptr,a,b,c,d,e)
#define IDirect3DRM3_CreateMaterial(ptr,a,b)                            (ptr)->lpVtbl->CreateMaterial(ptr,a,b)
#define IDirect3DRM3_CreateDevice(ptr,a,b,c)                            (ptr)->lpVtbl->CreateDevice(ptr,a,b,c)
#define IDirect3DRM3_CreateDeviceFromSurface(ptr,a,b,c,d,e)             (ptr)->lpVtbl->CreateDeviceFromSurface(ptr,a,b,c,d,e)
#define IDirect3DRM3_CreateDeviceFromD3D(ptr,a,b,c)                     (ptr)->lpVtbl->CreateDeviceFromD3D(ptr,a,b,c)
#define IDirect3DRM3_CreateDeviceFromClipper(ptr,a,b,c,d,e)             (ptr)->lpVtbl->CreateDeviceFromClipper(ptr,a,b,c,d,e)
#define IDirect3DRM3_CreateTextureFromSurface(ptr,a,b)                  (ptr)->lpVtbl->CreateTextureFromSurface(ptr,a,b)
#define IDirect3DRM3_CreateShadow(ptr,a,b,c,d,e,f,g,h,i)                (ptr)->lpVtbl->CreateShadow(ptr,a,b,c,d,e,f,g,h,i)
#define IDirect3DRM3_CreateViewport(ptr,a,b,c,d,e,f,g)                  (ptr)->lpVtbl->CreateViewport(ptr,a,b,c,d,e,f,g)
#define IDirect3DRM3_CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)    (ptr)->lpVtbl->CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define IDirect3DRM3_CreateUserVisual(ptr,a,b,c)                        (ptr)->lpVtbl->CreateUserVisual(ptr,a,b,c)
#define IDirect3DRM3_LoadTexture(ptr,a,b)                               (ptr)->lpVtbl->LoadTexture(ptr,a,b)
#define IDirect3DRM3_LoadTextureFromResource(ptr,a,b,c,d)               (ptr)->lpVtbl->LoadTextureFromResource(ptr,a,b,c,d)
#define IDirect3DRM3_SetSearchPath(ptr,a)                               (ptr)->lpVtbl->SetSearchPath(ptr,a)
#define IDirect3DRM3_AddSearchPath(ptr,a)                               (ptr)->lpVtbl->AddSearchPath(ptr,a)
#define IDirect3DRM3_GetSearchPath(ptr,a,b)                             (ptr)->lpVtbl->GetSearchPath(ptr,a,b)
#define IDirect3DRM3_SetDefaultTextureColors(ptr,a)                     (ptr)->lpVtbl->SetDefaultTextureColors(ptr,a)
#define IDirect3DRM3_SetDefaultTextureShades(ptr,a)                     (ptr)->lpVtbl->SetDefaultTextureShades(ptr,a)
#define IDirect3DRM3_GetDevices(ptr,a)                                  (ptr)->lpVtbl->GetDevices(ptr,a)
#define IDirect3DRM3_GetNamedObject(ptr,a,b)                            (ptr)->lpVtbl->GetNamedObject(ptr,a,b)
#define IDirect3DRM3_EnumerateObjects(ptr,a,b)                          (ptr)->lpVtbl->EnumerateObjects(ptr,a,b)
#define IDirect3DRM3_Load(ptr,a,b,c,d,e,f,g,h,i,j)                      (ptr)->lpVtbl->Load(ptr,a,b,c,d,e,f,g,h,i,j)
#define IDirect3DRM3_Tick(ptr,a)                                        (ptr)->lpVtbl->Tick(ptr,a)
#define IDirect3DRM3_CreateProgressiveMesh(ptr,a)                       (ptr)->lpVtbl->CreateProgressiveMesh(ptr,a)
#define IDirect3DRM3_RegisterClient(ptr,a,b)                            (ptr)->lpVtbl->RegisterClient(ptr,a,b)
#define IDirect3DRM3_UnregisterClient(ptr,a)                            (ptr)->lpVtbl->UnregisterClient(ptr,a)
#define IDirect3DRM3_CreateClippedVisual(ptr,a,b)                       (ptr)->lpVtbl->CreateClippedVisual(ptr,a,b)
#define IDirect3DRM3_SetOptions(ptr,a);                                 (ptr)->lpVtbl->SetOptions(ptr,a);
#define IDirect3DRM3_GetOptions(ptr,a);                                 (ptr)->lpVtbl->GetOptions(ptr,a);
#else
#define IDirect3DRM3_QueryInterface(ptr,a,b)                            (ptr)->QueryInterface(a,b)
#define IDirect3DRM3_AddRef(ptr)                                        (ptr)->AddRef()
#define IDirect3DRM3_Release(ptr)                                       (ptr)->Release()
#define IDirect3DRM3_CreateObject(ptr,a,b,c,d)                          (ptr)->CreateObject(a,b,c,d)
#define IDirect3DRM3_CreateFrame(ptr,a,b)                               (ptr)->CreateFrame(a,b)
#define IDirect3DRM3_CreateMesh(ptr,a)                                  (ptr)->CreateMesh(a)
#define IDirect3DRM3_CreateMeshBuilder(ptr,a)                           (ptr)->CreateMeshBuilder(a)
#define IDirect3DRM3_CreateFace(ptr,a)                                  (ptr)->CreateFace(a)
#define IDirect3DRM3_CreateAnimation(ptr,a)                             (ptr)->CreateAnimation(a)
#define IDirect3DRM3_CreateAnimationSet(ptr,a)                          (ptr)->CreateAnimationSet(a)
#define IDirect3DRM3_CreateTexture(ptr,a,b)                             (ptr)->CreateTexture(a,b)
#define IDirect3DRM3_CreateLight(ptr,a,b,c)                             (ptr)->CreateLight(a,b,c)
#define IDirect3DRM3_CreateLightRGB(ptr,a,b,c,d,e)                      (ptr)->CreateLightRGB(a,b,c,d,e)
#define IDirect3DRM3_CreateMaterial(ptr,a,b)                            (ptr)->CreateMaterial(a,b)
#define IDirect3DRM3_CreateDevice(ptr,a,b,c)                            (ptr)->CreateDevice(a,b,c)
#define IDirect3DRM3_CreateDeviceFromSurface(ptr,a,b,c,d,e)             (ptr)->CreateDeviceFromSurface(a,b,c,d,e)
#define IDirect3DRM3_CreateDeviceFromD3D(ptr,a,b,c)                     (ptr)->CreateDeviceFromD3D(a,b,c)
#define IDirect3DRM3_CreateDeviceFromClipper(ptr,a,b,c,d,e)             (ptr)->CreateDeviceFromClipper(a,b,c,d,e)
#define IDirect3DRM3_CreateTextureFromSurface(ptr,a,b)                  (ptr)->CreateTextureFromSurface(a,b)
#define IDirect3DRM3_CreateShadow(ptr,a,b,c,d,e,f,g,h,i)                (ptr)->CreateShadow(a,b,c,d,e,f,g,h,i)
#define IDirect3DRM3_CreateViewport(ptr,a,b,c,d,e,f,g)                  (ptr)->CreateViewport(a,b,c,d,e,f,g)
#define IDirect3DRM3_CreateWrap(ptr,a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)    (ptr)->CreateWrap(a,b,c,d,e,f,g,h,i,j,k,l,m,n,o,p)
#define IDirect3DRM3_CreateUserVisual(ptr,a,b,c)                        (ptr)->CreateUserVisual(a,b,c)
#define IDirect3DRM3_LoadTexture(ptr,a,b)                               (ptr)->LoadTexture(a,b)
#define IDirect3DRM3_LoadTextureFromResource(ptr,a,b,c,d)               (ptr)->LoadTextureFromResource(a,b,c,d)
#define IDirect3DRM3_SetSearchPath(ptr,a)                               (ptr)->SetSearchPath(a)
#define IDirect3DRM3_AddSearchPath(ptr,a)                               (ptr)->AddSearchPath(a)
#define IDirect3DRM3_GetSearchPath(ptr,a,b)                             (ptr)->GetSearchPath(a,b)
#define IDirect3DRM3_SetDefaultTextureColors(ptr,a)                     (ptr)->SetDefaultTextureColors(a)
#define IDirect3DRM3_SetDefaultTextureShades(ptr,a)                     (ptr)->SetDefaultTextureShades(a)
#define IDirect3DRM3_GetDevices(ptr,a)                                  (ptr)->GetDevices(a)
#define IDirect3DRM3_GetNamedObject(ptr,a,b)                            (ptr)->GetNamedObject(a,b)
#define IDirect3DRM3_EnumerateObjects(ptr,a,b)                          (ptr)->EnumerateObjects(a,b)
#define IDirect3DRM3_Load(ptr,a,b,c,d,e,f,g,h,i,j)                      (ptr)->Load(a,b,c,d,e,f,g,h,i,j)
#define IDirect3DRM3_Tick(ptr,a)                                        (ptr)->Tick(a)
#define IDirect3DRM3_CreateProgressiveMesh(ptr,a)                       (ptr)->CreateProgressiveMesh(a)
#define IDirect3DRM3_RegisterClient(ptr,a,b)                            (ptr)->RegisterClient(a,b)
#define IDirect3DRM3_UnregisterClient(ptr,a)                            (ptr)->UnregisterClient(a)
#define IDirect3DRM3_CreateClippedVisual(ptr,a,b)                       (ptr)->CreateClippedVisual(a,b)
#define IDirect3DRM3_SetOptions(ptr,a);                                 (ptr)->SetOptions(a);
#define IDirect3DRM3_GetOptions(ptr,a);                                 (ptr)->GetOptions(a);
#endif

#ifdef __cplusplus
extern "C" {
#endif

STDAPI Direct3DRMCreate(LPDIRECT3DRM FAR *lplpDirect3DRM);

#ifdef __cplusplus
}
#endif


#define D3DRM_OK                        DD_OK
#define D3DRMERR_BADOBJECT              MAKE_DDHRESULT(781)
#define D3DRMERR_BADTYPE                MAKE_DDHRESULT(782)
#define D3DRMERR_BADALLOC               MAKE_DDHRESULT(783)
#define D3DRMERR_FACEUSED               MAKE_DDHRESULT(784)
#define D3DRMERR_NOTFOUND               MAKE_DDHRESULT(785)
#define D3DRMERR_NOTDONEYET             MAKE_DDHRESULT(786)
#define D3DRMERR_FILENOTFOUND           MAKE_DDHRESULT(787)
#define D3DRMERR_BADFILE                MAKE_DDHRESULT(788)
#define D3DRMERR_BADDEVICE              MAKE_DDHRESULT(789)
#define D3DRMERR_BADVALUE               MAKE_DDHRESULT(790)
#define D3DRMERR_BADMAJORVERSION        MAKE_DDHRESULT(791)
#define D3DRMERR_BADMINORVERSION        MAKE_DDHRESULT(792)
#define D3DRMERR_UNABLETOEXECUTE        MAKE_DDHRESULT(793)
#define D3DRMERR_LIBRARYNOTFOUND        MAKE_DDHRESULT(794)
#define D3DRMERR_INVALIDLIBRARY         MAKE_DDHRESULT(795)
#define D3DRMERR_PENDING                MAKE_DDHRESULT(796)
#define D3DRMERR_NOTENOUGHDATA          MAKE_DDHRESULT(797)
#define D3DRMERR_REQUESTTOOLARGE        MAKE_DDHRESULT(798)
#define D3DRMERR_REQUESTTOOSMALL        MAKE_DDHRESULT(799)
#define D3DRMERR_CONNECTIONLOST         MAKE_DDHRESULT(800)
#define D3DRMERR_LOADABORTED            MAKE_DDHRESULT(801)
#define D3DRMERR_NOINTERNET             MAKE_DDHRESULT(802)
#define D3DRMERR_BADCACHEFILE           MAKE_DDHRESULT(803)
#define D3DRMERR_BOXNOTSET              MAKE_DDHRESULT(804)
#define D3DRMERR_BADPMDATA              MAKE_DDHRESULT(805)
#define D3DRMERR_CLIENTNOTREGISTERED    MAKE_DDHRESULT(806)
#define D3DRMERR_NOTCREATEDFROMDDS      MAKE_DDHRESULT(807)
#define D3DRMERR_NOSUCHKEY              MAKE_DDHRESULT(808)
#define D3DRMERR_INCOMPATABLEKEY        MAKE_DDHRESULT(809)
#define D3DRMERR_ELEMENTINUSE           MAKE_DDHRESULT(810)
#define D3DRMERR_TEXTUREFORMATNOTFOUND  MAKE_DDHRESULT(811)
#define D3DRMERR_NOTAGGREGATED          MAKE_DDHRESULT(812)

#endif // D3DRM_H
