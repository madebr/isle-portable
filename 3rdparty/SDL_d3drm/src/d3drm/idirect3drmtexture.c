#include "idirect3drmtexture.h"
#include "common/common_com.h"

#include <d3drmobj.h>
#include <winglue.h>

#include "common/common_logging.h"

static HRESULT STDCALL SDL_Direct3DRMTexture_QueryInterface(Direct3DRMTexture *this, REFIID riid, void **ppvObject) {
    if (SDL_memcmp(riid, &IID_IDirect3DRMTexture, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMTexture;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRMTexture2, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMTexture2;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRMTexture3, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMTexture3;
        return S_OK;
    } else {
        *ppvObject = NULL;
        return E_NOINTERFACE;
    }
}

static ULONG STDCALL SDL_Direct3DRMTexture_AddRef(Direct3DRMTexture *this ) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, 1);
    return prev_value + 1;
}

static ULONG STDCALL SDL_Direct3DRMTexture_Release(Direct3DRMTexture *this ) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, -1);
    if (prev_value == 1) {
        SDL_free(this);
    }
    return (ULONG) prev_value - 1;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_Clone(Direct3DRMTexture *this, IUnknown *a, REFIID b, void **c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_AddDestroyCallback(Direct3DRMTexture *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_DeleteDestroyCallback(Direct3DRMTexture *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetAppData(Direct3DRMTexture *this, LPVOID a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static LPVOID STDCALL SDL_Direct3DRMTexture_GetAppData(Direct3DRMTexture *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetName(Direct3DRMTexture *this, const char *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_GetName(Direct3DRMTexture *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_GetClassName(Direct3DRMTexture *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_InitFromFile(Direct3DRMTexture *this, const char *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_InitFromSurface(Direct3DRMTexture *this, IDirectDrawSurface *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_InitFromResource(Direct3DRMTexture *this, HRSRC a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_Changed(Direct3DRMTexture *this, DWORD dwFlags, DWORD dwcRects, LPRECT pRects) {
    (void) this;
    (void) dwFlags;
    (void) dwcRects;
    (void) pRects;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetColors(Direct3DRMTexture *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetShades(Direct3DRMTexture *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetDecalSize(Direct3DRMTexture *this, D3DVALUE a, D3DVALUE b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetDecalOrigin(Direct3DRMTexture *this, LONG a, LONG b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetDecalScale(Direct3DRMTexture *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetDecalTransparency(Direct3DRMTexture *this, BOOL a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetDecalTransparentColor(Direct3DRMTexture *this, D3DCOLOR a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_GetDecalSize(Direct3DRMTexture *this, D3DVALUE *a, D3DVALUE *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_GetDecalOrigin(Direct3DRMTexture *this, LONG *a, LONG *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DRMIMAGE * STDCALL SDL_Direct3DRMTexture_GetImage(Direct3DRMTexture *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static DWORD STDCALL SDL_Direct3DRMTexture_GetShades(Direct3DRMTexture *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static DWORD STDCALL SDL_Direct3DRMTexture_GetColors(Direct3DRMTexture *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static DWORD STDCALL SDL_Direct3DRMTexture_GetDecalScale(Direct3DRMTexture *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static BOOL STDCALL SDL_Direct3DRMTexture_GetDecalTransparency(Direct3DRMTexture *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DCOLOR STDCALL SDL_Direct3DRMTexture_GetDecalTransparentColor(Direct3DRMTexture *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_InitFromImage(Direct3DRMTexture *this, D3DRMIMAGE *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_InitFromResource2(Direct3DRMTexture *this, HMODULE a, const char *b, const char *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_GenerateMIPMap(Direct3DRMTexture *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_GetSurface(Direct3DRMTexture *this, DWORD a, IDirectDrawSurface **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetCacheOptions(Direct3DRMTexture *this, LONG a, DWORD b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_GetCacheOptions(Direct3DRMTexture *this, LONG *a, DWORD *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetDownsampleCallback(Direct3DRMTexture *this, D3DRMDOWNSAMPLECALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMTexture_SetValidationCallback(Direct3DRMTexture *this, D3DRMVALIDATIONCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}


// IDirect3DRMTexture interface

static HRESULT STDCALL SDL_IDirect3DRMTexture_QueryInterface(IDirect3DRMTexture *this, REFIID a, void **b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMTexture_AddRef(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMTexture_Release(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_Clone(IDirect3DRMTexture *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_AddDestroyCallback(IDirect3DRMTexture *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_DeleteDestroyCallback(IDirect3DRMTexture *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetAppData(IDirect3DRMTexture *this, LPVOID a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMTexture_GetAppData(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetName(IDirect3DRMTexture *this, const char *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_GetName(IDirect3DRMTexture *this, DWORD *a, char *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_GetClassName(IDirect3DRMTexture *this, DWORD *a, char *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_InitFromFile(IDirect3DRMTexture *this, const char *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_InitFromFile(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_InitFromSurface(IDirect3DRMTexture *this, IDirectDrawSurface *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_InitFromSurface(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_InitFromResource(IDirect3DRMTexture *this, HRSRC a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_InitFromResource(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_Changed(IDirect3DRMTexture *this, BOOL bPixels, BOOL bPalette) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    DWORD flags = 0;
    if (bPixels) {
        flags |= D3DRMTEXTURE_CHANGEDPIXELS;
    }
    if (bPalette) {
        flags |= D3DRMTEXTURE_CHANGEDPALETTE;
    }
    return SDL_Direct3DRMTexture_Changed(real_this, flags, 0, NULL);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetColors(IDirect3DRMTexture *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetColors(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetShades(IDirect3DRMTexture *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetShades(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetDecalSize(IDirect3DRMTexture *this, D3DVALUE a, D3DVALUE b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetDecalSize(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetDecalOrigin(IDirect3DRMTexture *this, LONG a, LONG b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetDecalOrigin(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetDecalScale(IDirect3DRMTexture *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetDecalScale(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetDecalTransparency(IDirect3DRMTexture *this, BOOL a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetDecalTransparency(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_SetDecalTransparentColor(IDirect3DRMTexture *this, D3DCOLOR a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_SetDecalTransparentColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_GetDecalSize(IDirect3DRMTexture *this, D3DVALUE *a, D3DVALUE *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetDecalSize(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture_GetDecalOrigin(IDirect3DRMTexture *this, LONG *a, LONG *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetDecalOrigin(real_this, a, b);
}

static D3DRMIMAGE * STDCALL SDL_IDirect3DRMTexture_GetImage(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetImage(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture_GetShades(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetShades(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture_GetColors(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetColors(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture_GetDecalScale(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetDecalScale(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMTexture_GetDecalTransparency(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetDecalTransparency(real_this);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMTexture_GetDecalTransparentColor(IDirect3DRMTexture *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture(this);
    return SDL_Direct3DRMTexture_GetDecalTransparentColor(real_this);
}


static IDirect3DRMTextureVtbl SDL_IDirect3DRMTexture_Vtable = {
    SDL_IDirect3DRMTexture_QueryInterface,
    SDL_IDirect3DRMTexture_AddRef,
    SDL_IDirect3DRMTexture_Release,
    SDL_IDirect3DRMTexture_Clone,
    SDL_IDirect3DRMTexture_AddDestroyCallback,
    SDL_IDirect3DRMTexture_DeleteDestroyCallback,
    SDL_IDirect3DRMTexture_SetAppData,
    SDL_IDirect3DRMTexture_GetAppData,
    SDL_IDirect3DRMTexture_SetName,
    SDL_IDirect3DRMTexture_GetName,
    SDL_IDirect3DRMTexture_GetClassName,
    SDL_IDirect3DRMTexture_InitFromFile,
    SDL_IDirect3DRMTexture_InitFromSurface,
    SDL_IDirect3DRMTexture_InitFromResource,
    SDL_IDirect3DRMTexture_Changed,
    SDL_IDirect3DRMTexture_SetColors,
    SDL_IDirect3DRMTexture_SetShades,
    SDL_IDirect3DRMTexture_SetDecalSize,
    SDL_IDirect3DRMTexture_SetDecalOrigin,
    SDL_IDirect3DRMTexture_SetDecalScale,
    SDL_IDirect3DRMTexture_SetDecalTransparency,
    SDL_IDirect3DRMTexture_SetDecalTransparentColor,
    SDL_IDirect3DRMTexture_GetDecalSize,
    SDL_IDirect3DRMTexture_GetDecalOrigin,
    SDL_IDirect3DRMTexture_GetImage,
    SDL_IDirect3DRMTexture_GetShades,
    SDL_IDirect3DRMTexture_GetColors,
    SDL_IDirect3DRMTexture_GetDecalScale,
    SDL_IDirect3DRMTexture_GetDecalTransparency,
    SDL_IDirect3DRMTexture_GetDecalTransparentColor,
};

// IDirect3DRMTexture2 interface

static HRESULT STDCALL SDL_IDirect3DRMTexture2_QueryInterface(IDirect3DRMTexture2 *this, REFIID a, void **b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMTexture2_AddRef(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMTexture2_Release(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_Clone(IDirect3DRMTexture2 *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_AddDestroyCallback(IDirect3DRMTexture2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_DeleteDestroyCallback(IDirect3DRMTexture2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetAppData(IDirect3DRMTexture2 *this, LPVOID a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMTexture2_GetAppData(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetName(IDirect3DRMTexture2 *this, const char *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_GetName(IDirect3DRMTexture2 *this, DWORD *a, char *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_GetClassName(IDirect3DRMTexture2 *this, DWORD *a, char *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_InitFromFile(IDirect3DRMTexture2 *this, const char *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_InitFromFile(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_InitFromSurface(IDirect3DRMTexture2 *this, IDirectDrawSurface *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_InitFromSurface(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_InitFromResource(IDirect3DRMTexture2 *this, HRSRC a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_InitFromResource(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_Changed(IDirect3DRMTexture2 *this, BOOL bPixels, BOOL bPalette) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    DWORD flags = 0;
    if (bPixels) {
        flags |= D3DRMTEXTURE_CHANGEDPIXELS;
    }
    if (bPalette) {
        flags |= D3DRMTEXTURE_CHANGEDPALETTE;
    }
    return SDL_Direct3DRMTexture_Changed(real_this, flags, 0, NULL);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetColors(IDirect3DRMTexture2 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetColors(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetShades(IDirect3DRMTexture2 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetShades(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetDecalSize(IDirect3DRMTexture2 *this, D3DVALUE a, D3DVALUE b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetDecalSize(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetDecalOrigin(IDirect3DRMTexture2 *this, LONG a, LONG b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetDecalOrigin(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetDecalScale(IDirect3DRMTexture2 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetDecalScale(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetDecalTransparency(IDirect3DRMTexture2 *this, BOOL a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetDecalTransparency(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_SetDecalTransparentColor(IDirect3DRMTexture2 *this, D3DCOLOR a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_SetDecalTransparentColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_GetDecalSize(IDirect3DRMTexture2 *this, D3DVALUE *a, D3DVALUE *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetDecalSize(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_GetDecalOrigin(IDirect3DRMTexture2 *this, LONG *a, LONG *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetDecalOrigin(real_this, a, b);
}

static D3DRMIMAGE * STDCALL SDL_IDirect3DRMTexture2_GetImage(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetImage(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture2_GetShades(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetShades(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture2_GetColors(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetColors(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture2_GetDecalScale(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetDecalScale(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMTexture2_GetDecalTransparency(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetDecalTransparency(real_this);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMTexture2_GetDecalTransparentColor(IDirect3DRMTexture2 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GetDecalTransparentColor(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_InitFromImage(IDirect3DRMTexture2 *this, D3DRMIMAGE *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_InitFromImage(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_InitFromResource2(IDirect3DRMTexture2 *this, HMODULE a, const char *b, const char *c) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_InitFromResource2(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture2_GenerateMIPMap(IDirect3DRMTexture2 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture2(this);
    return SDL_Direct3DRMTexture_GenerateMIPMap(real_this, a);
}


static IDirect3DRMTexture2Vtbl SDL_IDirect3DRMTexture2_Vtable = {
    SDL_IDirect3DRMTexture2_QueryInterface,
    SDL_IDirect3DRMTexture2_AddRef,
    SDL_IDirect3DRMTexture2_Release,
    SDL_IDirect3DRMTexture2_Clone,
    SDL_IDirect3DRMTexture2_AddDestroyCallback,
    SDL_IDirect3DRMTexture2_DeleteDestroyCallback,
    SDL_IDirect3DRMTexture2_SetAppData,
    SDL_IDirect3DRMTexture2_GetAppData,
    SDL_IDirect3DRMTexture2_SetName,
    SDL_IDirect3DRMTexture2_GetName,
    SDL_IDirect3DRMTexture2_GetClassName,
    SDL_IDirect3DRMTexture2_InitFromFile,
    SDL_IDirect3DRMTexture2_InitFromSurface,
    SDL_IDirect3DRMTexture2_InitFromResource,
    SDL_IDirect3DRMTexture2_Changed,
    SDL_IDirect3DRMTexture2_SetColors,
    SDL_IDirect3DRMTexture2_SetShades,
    SDL_IDirect3DRMTexture2_SetDecalSize,
    SDL_IDirect3DRMTexture2_SetDecalOrigin,
    SDL_IDirect3DRMTexture2_SetDecalScale,
    SDL_IDirect3DRMTexture2_SetDecalTransparency,
    SDL_IDirect3DRMTexture2_SetDecalTransparentColor,
    SDL_IDirect3DRMTexture2_GetDecalSize,
    SDL_IDirect3DRMTexture2_GetDecalOrigin,
    SDL_IDirect3DRMTexture2_GetImage,
    SDL_IDirect3DRMTexture2_GetShades,
    SDL_IDirect3DRMTexture2_GetColors,
    SDL_IDirect3DRMTexture2_GetDecalScale,
    SDL_IDirect3DRMTexture2_GetDecalTransparency,
    SDL_IDirect3DRMTexture2_GetDecalTransparentColor,
    SDL_IDirect3DRMTexture2_InitFromImage,
    SDL_IDirect3DRMTexture2_InitFromResource2,
    SDL_IDirect3DRMTexture2_GenerateMIPMap,
};

// IDirect3DRMTexture3 interface

static HRESULT STDCALL SDL_IDirect3DRMTexture3_QueryInterface(IDirect3DRMTexture3 *this, REFIID a, void **b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMTexture3_AddRef(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMTexture3_Release(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_Clone(IDirect3DRMTexture3 *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_AddDestroyCallback(IDirect3DRMTexture3 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_DeleteDestroyCallback(IDirect3DRMTexture3 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetAppData(IDirect3DRMTexture3 *this, LPVOID a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMTexture3_GetAppData(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetName(IDirect3DRMTexture3 *this, const char *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_GetName(IDirect3DRMTexture3 *this, DWORD *a, char *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_GetClassName(IDirect3DRMTexture3 *this, DWORD *a, char *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_InitFromFile(IDirect3DRMTexture3 *this, const char *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_InitFromFile(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_InitFromSurface(IDirect3DRMTexture3 *this, IDirectDrawSurface *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_InitFromSurface(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_InitFromResource(IDirect3DRMTexture3 *this, HRSRC a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_InitFromResource(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_Changed(IDirect3DRMTexture3 *this, DWORD dwFlags, DWORD dwcRects, LPRECT pRects) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_Changed(real_this, dwFlags, dwcRects, pRects);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetColors(IDirect3DRMTexture3 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetColors(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetShades(IDirect3DRMTexture3 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetShades(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetDecalSize(IDirect3DRMTexture3 *this, D3DVALUE a, D3DVALUE b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetDecalSize(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetDecalOrigin(IDirect3DRMTexture3 *this, LONG a, LONG b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetDecalOrigin(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetDecalScale(IDirect3DRMTexture3 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetDecalScale(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetDecalTransparency(IDirect3DRMTexture3 *this, BOOL a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetDecalTransparency(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetDecalTransparentColor(IDirect3DRMTexture3 *this, D3DCOLOR a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetDecalTransparentColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_GetDecalSize(IDirect3DRMTexture3 *this, D3DVALUE *a, D3DVALUE *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetDecalSize(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_GetDecalOrigin(IDirect3DRMTexture3 *this, LONG *a, LONG *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetDecalOrigin(real_this, a, b);
}

static D3DRMIMAGE * STDCALL SDL_IDirect3DRMTexture3_GetImage(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetImage(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture3_GetShades(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetShades(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture3_GetColors(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetColors(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMTexture3_GetDecalScale(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetDecalScale(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMTexture3_GetDecalTransparency(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetDecalTransparency(real_this);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMTexture3_GetDecalTransparentColor(IDirect3DRMTexture3 *this) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetDecalTransparentColor(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_InitFromImage(IDirect3DRMTexture3 *this, D3DRMIMAGE *a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_InitFromImage(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_InitFromResource2(IDirect3DRMTexture3 *this, HMODULE a, const char *b, const char *c) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_InitFromResource2(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_GenerateMIPMap(IDirect3DRMTexture3 *this, DWORD a) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GenerateMIPMap(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_GetSurface(IDirect3DRMTexture3 *this, DWORD a, IDirectDrawSurface **b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetSurface(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetCacheOptions(IDirect3DRMTexture3 *this, LONG a, DWORD b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetCacheOptions(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_GetCacheOptions(IDirect3DRMTexture3 *this, LONG *a, DWORD *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_GetCacheOptions(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetDownsampleCallback(IDirect3DRMTexture3 *this, D3DRMDOWNSAMPLECALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetDownsampleCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMTexture3_SetValidationCallback(IDirect3DRMTexture3 *this, D3DRMVALIDATIONCALLBACK a, void *b) {
    Direct3DRMTexture *real_this = from_IDirect3DRMTexture3(this);
    return SDL_Direct3DRMTexture_SetValidationCallback(real_this, a, b);
}


static IDirect3DRMTexture3Vtbl SDL_IDirect3DRMTexture3_Vtable = {
    SDL_IDirect3DRMTexture3_QueryInterface,
    SDL_IDirect3DRMTexture3_AddRef,
    SDL_IDirect3DRMTexture3_Release,
    SDL_IDirect3DRMTexture3_Clone,
    SDL_IDirect3DRMTexture3_AddDestroyCallback,
    SDL_IDirect3DRMTexture3_DeleteDestroyCallback,
    SDL_IDirect3DRMTexture3_SetAppData,
    SDL_IDirect3DRMTexture3_GetAppData,
    SDL_IDirect3DRMTexture3_SetName,
    SDL_IDirect3DRMTexture3_GetName,
    SDL_IDirect3DRMTexture3_GetClassName,
    SDL_IDirect3DRMTexture3_InitFromFile,
    SDL_IDirect3DRMTexture3_InitFromSurface,
    SDL_IDirect3DRMTexture3_InitFromResource,
    SDL_IDirect3DRMTexture3_Changed,
    SDL_IDirect3DRMTexture3_SetColors,
    SDL_IDirect3DRMTexture3_SetShades,
    SDL_IDirect3DRMTexture3_SetDecalSize,
    SDL_IDirect3DRMTexture3_SetDecalOrigin,
    SDL_IDirect3DRMTexture3_SetDecalScale,
    SDL_IDirect3DRMTexture3_SetDecalTransparency,
    SDL_IDirect3DRMTexture3_SetDecalTransparentColor,
    SDL_IDirect3DRMTexture3_GetDecalSize,
    SDL_IDirect3DRMTexture3_GetDecalOrigin,
    SDL_IDirect3DRMTexture3_GetImage,
    SDL_IDirect3DRMTexture3_GetShades,
    SDL_IDirect3DRMTexture3_GetColors,
    SDL_IDirect3DRMTexture3_GetDecalScale,
    SDL_IDirect3DRMTexture3_GetDecalTransparency,
    SDL_IDirect3DRMTexture3_GetDecalTransparentColor,
    SDL_IDirect3DRMTexture3_InitFromImage,
    SDL_IDirect3DRMTexture3_InitFromResource2,
    SDL_IDirect3DRMTexture3_GenerateMIPMap,
    SDL_IDirect3DRMTexture3_GetSurface,
    SDL_IDirect3DRMTexture3_SetCacheOptions,
    SDL_IDirect3DRMTexture3_GetCacheOptions,
    SDL_IDirect3DRMTexture3_SetDownsampleCallback,
    SDL_IDirect3DRMTexture3_SetValidationCallback,
};
