#include "idirect3drmdevice.h"
#include "common/common_com.h"

#include "d3drmobj.h"
#include "winglue.h"

#include "common/common_logging.h"

static HRESULT SDL_Direct3DRMDevice_QueryInterface(SDL_Direct3DRMDevice *this, REFIID riid, void **ppvObject) {
    if (SDL_memcmp(riid, &IID_IDirect3DRMDevice, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMDevice;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRMDevice2, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMDevice2;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRMDevice3, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMDevice3;
        return S_OK;
    } else {
        *ppvObject = NULL;
        return E_NOINTERFACE;
    }
}

static ULONG SDL_Direct3DRMDevice_AddRef(SDL_Direct3DRMDevice *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, 1);
    return prev_value + 1;
}

static ULONG SDL_Direct3DRMDevice_Release(SDL_Direct3DRMDevice *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, -1);
    if (prev_value == 1) {
        SDL_free(this);
    }
    return (ULONG) prev_value - 1;
}

static HRESULT SDL_Direct3DRMDevice_Clone(SDL_Direct3DRMDevice *this, IUnknown *outer, REFIID iid, void **out) {
    (void) this;
    (void) outer;
    (void) iid;
    (void) out;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_AddDestroyCallback(SDL_Direct3DRMDevice *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    (void) this;
    (void) cb;
    (void) ctx;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_DeleteDestroyCallback(SDL_Direct3DRMDevice *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    (void) this;
    (void) cb;
    (void) ctx;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_SetAppData(SDL_Direct3DRMDevice *this, LPVOID data) {
    (void) this;
    (void) data;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static LPVOID SDL_Direct3DRMDevice_GetAppData(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static HRESULT SDL_Direct3DRMDevice_SetName(SDL_Direct3DRMDevice *this, const char *name) {
    (void) this;
    (void) name;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_GetName(SDL_Direct3DRMDevice *this, DWORD *size, char *name) {
    (void) this;
    (void) size;
    (void) name;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_GetClassName(SDL_Direct3DRMDevice *this, DWORD *size, char *name) {
    (void) this;
    (void) size;
    (void) name;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_Init(SDL_Direct3DRMDevice *this, ULONG width, ULONG height) {
    (void) this;
    (void) width;
    (void) height;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_InitFromD3D(SDL_Direct3DRMDevice *this, IDirect3D *d3d, IDirect3DDevice *d3d_device) {
    (void) this;
    (void) d3d;
    (void) d3d_device;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

extern HRESULT SDL_Direct3DRMDevice_InitFromClipper(SDL_Direct3DRMDevice *this, IDirectDrawClipper *clipper, SDL_GUID *guid, int width, int height) {
    (void) this;
    (void) guid;
#ifdef _WIN32
    HWND hWnd;
    HRESULT res = IDirectDrawClipper_GetHWnd(clipper, &hWnd);
    if (FAILED(res)) {
        return res;
    }
    if (hWnd == NULL) {
        return E_POINTER;
    }
    this->hWnd = hWnd;
    this->width = width;
    this->height = height;
    return S_OK;
#else
    (void) clipper;
    (void) width;
    (void) height;
    return E_NOTIMPL;
#endif
}

static HRESULT SDL_Direct3DRMDevice_Update(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_AddUpdateCallback(SDL_Direct3DRMDevice *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    (void) this;
    (void) cb;
    (void) ctx;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_DeleteUpdateCallback(SDL_Direct3DRMDevice *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    (void) this;
    (void) cb;
    (void) ctx;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_SetBufferCount(SDL_Direct3DRMDevice *this, DWORD count) {
    (void) this;
    (void) count;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static DWORD SDL_Direct3DRMDevice_GetBufferCount(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT SDL_Direct3DRMDevice_SetDither(SDL_Direct3DRMDevice *this, BOOL enable) {
    (void) this;
    (void) enable;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_SetShades(SDL_Direct3DRMDevice *this, DWORD shades) {
    (void) this;
    (void) shades;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_SetQuality(SDL_Direct3DRMDevice *this, D3DRMRENDERQUALITY quality) {
    (void) this;
    (void) quality;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_SetTextureQuality(SDL_Direct3DRMDevice *this, D3DRMTEXTUREQUALITY quality) {
    (void) this;
    (void) quality;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_GetViewports(SDL_Direct3DRMDevice *this, IDirect3DRMViewportArray **array) {
    (void) this;
    (void) array;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static BOOL SDL_Direct3DRMDevice_GetDither(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static DWORD SDL_Direct3DRMDevice_GetShades(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static DWORD SDL_Direct3DRMDevice_GetHeight(SDL_Direct3DRMDevice *this) {
    return this->height;
}

static DWORD SDL_Direct3DRMDevice_GetWidth(SDL_Direct3DRMDevice *this) {
    return this->width;
}

static DWORD SDL_Direct3DRMDevice_GetTrianglesDrawn(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static DWORD SDL_Direct3DRMDevice_GetWireframeOptions(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DRMRENDERQUALITY SDL_Direct3DRMDevice_GetQuality(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DCOLORMODEL SDL_Direct3DRMDevice_GetColorModel(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DRMTEXTUREQUALITY SDL_Direct3DRMDevice_GetTextureQuality(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT SDL_Direct3DRMDevice_GetDirect3DDevice(SDL_Direct3DRMDevice *this, IDirect3DDevice **d3d_device) {
    (void) this;
    (void) d3d_device;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_InitFromD3D2(SDL_Direct3DRMDevice *this, IDirect3D2 *d3d, IDirect3DDevice2 *device) {
    (void) this;
    (void) d3d;
    (void) device;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_InitFromSurface(SDL_Direct3DRMDevice *this, SDL_GUID *guid, IDirectDraw *ddraw, IDirectDrawSurface *surface) {
    (void) this;
    (void) guid;
    (void) ddraw;
    (void) surface;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_SetRenderMode(SDL_Direct3DRMDevice *this, DWORD flags) {
    (void) this;
    (void) flags;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static DWORD SDL_Direct3DRMDevice_GetRenderMode(SDL_Direct3DRMDevice *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT SDL_Direct3DRMDevice_GetDirect3DDevice2(SDL_Direct3DRMDevice *this, IDirect3DDevice2 **device) {
    (void) this;
    (void) device;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_FindPreferredTextureFormat(SDL_Direct3DRMDevice *this, DWORD BitDepths, DWORD flags, DDPIXELFORMAT *format) {
    (void) this;
    (void) BitDepths;
    (void) flags;
    (void) format;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_RenderStateChange(SDL_Direct3DRMDevice *this, D3DRENDERSTATETYPE drsType, DWORD val, DWORD flags) {
    (void) this;
    (void) drsType;
    (void) val;
    (void) flags;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_LightStateChange(SDL_Direct3DRMDevice *this, D3DLIGHTSTATETYPE drsType, DWORD val, DWORD flags) {
    (void) this;
    (void) drsType;
    (void) val;
    (void) flags;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_GetStateChangeOptions(SDL_Direct3DRMDevice *this, DWORD state_class, DWORD state_idx, DWORD *flags) {
    (void) this;
    (void) state_class;
    (void) state_idx;
    (void) flags;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT SDL_Direct3DRMDevice_SetStateChangeOptions(SDL_Direct3DRMDevice *this, DWORD StateClass, DWORD StateNum, DWORD flags) {
    (void) this;
    (void) StateClass;
    (void) StateNum;
    (void) flags;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

// IDirect3DRMDevice interface

static HRESULT STDCALL SDL_IDirect3DRMDevice_QueryInterface(IDirect3DRMDevice *this, REFIID riid, void** ppvObject) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_QueryInterface(real_this, riid, ppvObject);
}

static ULONG STDCALL SDL_IDirect3DRMDevice_AddRef(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMDevice_Release(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_Clone(IDirect3DRMDevice *this, IUnknown *outer, REFIID iid, void **out) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_Clone(real_this, outer, iid, out);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_AddDestroyCallback(IDirect3DRMDevice *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_AddDestroyCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_DeleteDestroyCallback(IDirect3DRMDevice *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_DeleteDestroyCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_SetAppData(IDirect3DRMDevice *this, LPVOID data) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_SetAppData(real_this, data);
}

static LPVOID STDCALL SDL_IDirect3DRMDevice_GetAppData(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_SetName(IDirect3DRMDevice *this, const char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_SetName(real_this, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_GetName(IDirect3DRMDevice *this, DWORD *size, char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetName(real_this, size, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_GetClassName(IDirect3DRMDevice *this, DWORD *size, char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetClassName(real_this, size, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_Init(IDirect3DRMDevice *this, ULONG width, ULONG height) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_Init(real_this, width, height);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_InitFromD3D(IDirect3DRMDevice *this, IDirect3D *d3d, IDirect3DDevice *d3d_device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_InitFromD3D(real_this, d3d, d3d_device);

}

static HRESULT STDCALL SDL_IDirect3DRMDevice_InitFromClipper(IDirect3DRMDevice *this, IDirectDrawClipper *clipper, SDL_GUID *guid, int width, int height) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_InitFromClipper(real_this, clipper, guid, width, height);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_Update(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_Update(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_AddUpdateCallback(IDirect3DRMDevice *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_AddUpdateCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_DeleteUpdateCallback(IDirect3DRMDevice *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_DeleteUpdateCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_SetBufferCount(IDirect3DRMDevice *this, DWORD count) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_SetBufferCount(real_this, count);
}

static DWORD STDCALL SDL_IDirect3DRMDevice_GetBufferCount(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetBufferCount(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_SetDither(IDirect3DRMDevice *this, BOOL enable) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_SetDither(real_this, enable);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_SetShades(IDirect3DRMDevice *this, DWORD shades) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_SetShades(real_this, shades);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_SetQuality(IDirect3DRMDevice *this, D3DRMRENDERQUALITY quality) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_SetQuality(real_this, quality);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_SetTextureQuality(IDirect3DRMDevice *this, D3DRMTEXTUREQUALITY quality) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_SetTextureQuality(real_this, quality);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_GetViewports(IDirect3DRMDevice *this, struct IDirect3DRMViewportArray **array) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetViewports(real_this, array);
}

static BOOL STDCALL SDL_IDirect3DRMDevice_GetDither(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetDither(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice_GetShades(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetShades(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice_GetHeight(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetHeight(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice_GetWidth(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetWidth(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice_GetTrianglesDrawn(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetTrianglesDrawn(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice_GetWireframeOptions(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetWireframeOptions(real_this);
}

static D3DRMRENDERQUALITY STDCALL SDL_IDirect3DRMDevice_GetQuality(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetQuality(real_this);
}

static D3DCOLORMODEL STDCALL SDL_IDirect3DRMDevice_GetColorModel(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetColorModel(real_this);
}

static D3DRMTEXTUREQUALITY STDCALL SDL_IDirect3DRMDevice_GetTextureQuality(IDirect3DRMDevice *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetTextureQuality(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice_GetDirect3DDevice(IDirect3DRMDevice *this, IDirect3DDevice **d3d_device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice(this);
    return SDL_Direct3DRMDevice_GetDirect3DDevice(real_this, d3d_device);
}

static IDirect3DRMDeviceVtbl SDL_IDirect3DRMDevice_Vtable = {
    SDL_IDirect3DRMDevice_QueryInterface,
    SDL_IDirect3DRMDevice_AddRef,
    SDL_IDirect3DRMDevice_Release,
    SDL_IDirect3DRMDevice_Clone,
    SDL_IDirect3DRMDevice_AddDestroyCallback,
    SDL_IDirect3DRMDevice_DeleteDestroyCallback,
    SDL_IDirect3DRMDevice_SetAppData,
    SDL_IDirect3DRMDevice_GetAppData,
    SDL_IDirect3DRMDevice_SetName,
    SDL_IDirect3DRMDevice_GetName,
    SDL_IDirect3DRMDevice_GetClassName,
    SDL_IDirect3DRMDevice_Init,
    SDL_IDirect3DRMDevice_InitFromD3D,
    SDL_IDirect3DRMDevice_InitFromClipper,
    SDL_IDirect3DRMDevice_Update,
    SDL_IDirect3DRMDevice_AddUpdateCallback,
    SDL_IDirect3DRMDevice_DeleteUpdateCallback,
    SDL_IDirect3DRMDevice_SetBufferCount,
    SDL_IDirect3DRMDevice_GetBufferCount,
    SDL_IDirect3DRMDevice_SetDither,
    SDL_IDirect3DRMDevice_SetShades,
    SDL_IDirect3DRMDevice_SetQuality,
    SDL_IDirect3DRMDevice_SetTextureQuality,
    SDL_IDirect3DRMDevice_GetViewports,
    SDL_IDirect3DRMDevice_GetDither,
    SDL_IDirect3DRMDevice_GetShades,
    SDL_IDirect3DRMDevice_GetHeight,
    SDL_IDirect3DRMDevice_GetWidth,
    SDL_IDirect3DRMDevice_GetTrianglesDrawn,
    SDL_IDirect3DRMDevice_GetWireframeOptions,
    SDL_IDirect3DRMDevice_GetQuality,
    SDL_IDirect3DRMDevice_GetColorModel,
    SDL_IDirect3DRMDevice_GetTextureQuality,
    SDL_IDirect3DRMDevice_GetDirect3DDevice,
};

// IDirect3DRMDevice2 interface

static HRESULT STDCALL SDL_IDirect3DRMDevice2_QueryInterface(IDirect3DRMDevice2 *this, REFIID riid, void **ppvObject) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_QueryInterface(real_this, riid, ppvObject);
}

static ULONG STDCALL SDL_IDirect3DRMDevice2_AddRef(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMDevice2_Release(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_Clone(IDirect3DRMDevice2 *this, IUnknown *outer, REFIID iid, void **out) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_Clone(real_this, outer, iid, out);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_AddDestroyCallback(IDirect3DRMDevice2 *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_AddDestroyCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_DeleteDestroyCallback(IDirect3DRMDevice2 *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_DeleteDestroyCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetAppData(IDirect3DRMDevice2 *this, LPVOID data) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetAppData(real_this, data);
}

static LPVOID STDCALL SDL_IDirect3DRMDevice2_GetAppData(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetName(IDirect3DRMDevice2 *this, const char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetName(real_this, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_GetName(IDirect3DRMDevice2 *this, DWORD *size, char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetName(real_this, size, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_GetClassName(IDirect3DRMDevice2 *this, DWORD *size, char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetClassName(real_this, size, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_Init(IDirect3DRMDevice2 *this, ULONG width, ULONG height) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_Init(real_this, width, height);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_InitFromD3D(IDirect3DRMDevice2 *this, IDirect3D *d3d, IDirect3DDevice *d3d_device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_InitFromD3D(real_this, d3d, d3d_device);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_InitFromClipper(IDirect3DRMDevice2 *this, IDirectDrawClipper *clipper, SDL_GUID *guid, int width, int height) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_InitFromClipper(real_this, clipper, guid, width, height);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_Update(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_Update(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_AddUpdateCallback(IDirect3DRMDevice2 *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_AddUpdateCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_DeleteUpdateCallback(IDirect3DRMDevice2 *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_DeleteUpdateCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetBufferCount(IDirect3DRMDevice2 *this, DWORD count) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetBufferCount(real_this, count);
}

static DWORD STDCALL SDL_IDirect3DRMDevice2_GetBufferCount(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetBufferCount(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetDither(IDirect3DRMDevice2 *this, BOOL enable) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetDither(real_this, enable);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetShades(IDirect3DRMDevice2 *this, DWORD shades) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetShades(real_this, shades);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetQuality(IDirect3DRMDevice2 *this, D3DRMRENDERQUALITY quality) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetQuality(real_this, quality);

}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetTextureQuality(IDirect3DRMDevice2 *this, D3DRMTEXTUREQUALITY quality) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetTextureQuality(real_this, quality);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_GetViewports(IDirect3DRMDevice2 *this, struct IDirect3DRMViewportArray **array) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetViewports(real_this, array);
}

static BOOL STDCALL SDL_IDirect3DRMDevice2_GetDither(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetDither(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice2_GetShades(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetShades(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice2_GetHeight(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetHeight(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice2_GetWidth(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetWidth(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice2_GetTrianglesDrawn(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetTrianglesDrawn(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice2_GetWireframeOptions(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetWireframeOptions(real_this);
}

static D3DRMRENDERQUALITY STDCALL SDL_IDirect3DRMDevice2_GetQuality(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetQuality(real_this);
}

static D3DCOLORMODEL STDCALL SDL_IDirect3DRMDevice2_GetColorModel(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetColorModel(real_this);
}

static D3DRMTEXTUREQUALITY STDCALL SDL_IDirect3DRMDevice2_GetTextureQuality(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetTextureQuality(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_GetDirect3DDevice(IDirect3DRMDevice2 *this, IDirect3DDevice **d3d_device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetDirect3DDevice(real_this, d3d_device);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_InitFromD3D2(IDirect3DRMDevice2 *this, IDirect3D2 *d3d, IDirect3DDevice2 *device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_InitFromD3D2(real_this, d3d, device);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_InitFromSurface(IDirect3DRMDevice2 *this, SDL_GUID *guid, IDirectDraw *ddraw, IDirectDrawSurface *surface) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_InitFromSurface(real_this, guid, ddraw, surface);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_SetRenderMode(IDirect3DRMDevice2 *this, DWORD flags) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_SetRenderMode(real_this, flags);
}

static DWORD STDCALL SDL_IDirect3DRMDevice2_GetRenderMode(IDirect3DRMDevice2 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetRenderMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice2_GetDirect3DDevice2(IDirect3DRMDevice2 *this, IDirect3DDevice2 **device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice2(this);
    return SDL_Direct3DRMDevice_GetDirect3DDevice2(real_this, device);
}

static IDirect3DRMDevice2Vtbl SDL_IDirect3DRMDevice2_Vtable = {
    SDL_IDirect3DRMDevice2_QueryInterface,
    SDL_IDirect3DRMDevice2_AddRef,
    SDL_IDirect3DRMDevice2_Release,
    SDL_IDirect3DRMDevice2_Clone,
    SDL_IDirect3DRMDevice2_AddDestroyCallback,
    SDL_IDirect3DRMDevice2_DeleteDestroyCallback,
    SDL_IDirect3DRMDevice2_SetAppData,
    SDL_IDirect3DRMDevice2_GetAppData,
    SDL_IDirect3DRMDevice2_SetName,
    SDL_IDirect3DRMDevice2_GetName,
    SDL_IDirect3DRMDevice2_GetClassName,
    SDL_IDirect3DRMDevice2_Init,
    SDL_IDirect3DRMDevice2_InitFromD3D,
    SDL_IDirect3DRMDevice2_InitFromClipper,
    SDL_IDirect3DRMDevice2_Update,
    SDL_IDirect3DRMDevice2_AddUpdateCallback,
    SDL_IDirect3DRMDevice2_DeleteUpdateCallback,
    SDL_IDirect3DRMDevice2_SetBufferCount,
    SDL_IDirect3DRMDevice2_GetBufferCount,
    SDL_IDirect3DRMDevice2_SetDither,
    SDL_IDirect3DRMDevice2_SetShades,
    SDL_IDirect3DRMDevice2_SetQuality,
    SDL_IDirect3DRMDevice2_SetTextureQuality,
    SDL_IDirect3DRMDevice2_GetViewports,
    SDL_IDirect3DRMDevice2_GetDither,
    SDL_IDirect3DRMDevice2_GetShades,
    SDL_IDirect3DRMDevice2_GetHeight,
    SDL_IDirect3DRMDevice2_GetWidth,
    SDL_IDirect3DRMDevice2_GetTrianglesDrawn,
    SDL_IDirect3DRMDevice2_GetWireframeOptions,
    SDL_IDirect3DRMDevice2_GetQuality,
    SDL_IDirect3DRMDevice2_GetColorModel,
    SDL_IDirect3DRMDevice2_GetTextureQuality,
    SDL_IDirect3DRMDevice2_GetDirect3DDevice,
    SDL_IDirect3DRMDevice2_InitFromD3D2,
    SDL_IDirect3DRMDevice2_InitFromSurface,
    SDL_IDirect3DRMDevice2_SetRenderMode,
    SDL_IDirect3DRMDevice2_GetRenderMode,
    SDL_IDirect3DRMDevice2_GetDirect3DDevice2,
};

// IDirect3DRMDevice3 interface

static HRESULT STDCALL SDL_IDirect3DRMDevice3_QueryInterface(IDirect3DRMDevice3 *this, REFIID riid, void **ppvObject) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_QueryInterface(real_this, riid, ppvObject);
}

static ULONG STDCALL SDL_IDirect3DRMDevice3_AddRef(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMDevice3_Release(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_Clone(IDirect3DRMDevice3 *this, IUnknown *outer, REFIID iid, void **out) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_Clone(real_this, outer, iid, out);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_AddDestroyCallback(IDirect3DRMDevice3 *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_AddDestroyCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_DeleteDestroyCallback(IDirect3DRMDevice3 *this, D3DRMOBJECTCALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_DeleteDestroyCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetAppData(IDirect3DRMDevice3 *this, LPVOID data) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetAppData(real_this, data);
}

static LPVOID STDCALL SDL_IDirect3DRMDevice3_GetAppData(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetName(IDirect3DRMDevice3 *this, const char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetName(real_this, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_GetName(IDirect3DRMDevice3 *this, DWORD *size, char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetName(real_this, size, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_GetClassName(IDirect3DRMDevice3 *this, DWORD *size, char *name) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetClassName(real_this, size, name);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_Init(IDirect3DRMDevice3 *this, ULONG width, ULONG height) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_Init(real_this, width, height);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_InitFromD3D(IDirect3DRMDevice3 *this, IDirect3D *d3d, IDirect3DDevice *d3d_device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_InitFromD3D(real_this, d3d, d3d_device);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_InitFromClipper(IDirect3DRMDevice3 *this, IDirectDrawClipper *clipper, SDL_GUID *guid, int width, int height) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_InitFromClipper(real_this, clipper, guid, width, height);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_Update(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_Update(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_AddUpdateCallback(IDirect3DRMDevice3 *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_AddUpdateCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_DeleteUpdateCallback(IDirect3DRMDevice3 *this, D3DRMUPDATECALLBACK cb, void *ctx) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_DeleteUpdateCallback(real_this, cb, ctx);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetBufferCount(IDirect3DRMDevice3 *this, DWORD count) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetBufferCount(real_this, count);
}

static DWORD STDCALL SDL_IDirect3DRMDevice3_GetBufferCount(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetBufferCount(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetDither(IDirect3DRMDevice3 *this, BOOL enable) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetDither(real_this, enable);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetShades(IDirect3DRMDevice3 *this, DWORD shades) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetShades(real_this, shades);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetQuality(IDirect3DRMDevice3 *this, D3DRMRENDERQUALITY quality) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetQuality(real_this, quality);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetTextureQuality(IDirect3DRMDevice3 *this, D3DRMTEXTUREQUALITY quality) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetTextureQuality(real_this, quality);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_GetViewports(IDirect3DRMDevice3 *this, IDirect3DRMViewportArray **array) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetViewports(real_this, array);
}

static BOOL STDCALL SDL_IDirect3DRMDevice3_GetDither(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetDither(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice3_GetShades(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetShades(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice3_GetHeight(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetHeight(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice3_GetWidth(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetWidth(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice3_GetTrianglesDrawn(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetTrianglesDrawn(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMDevice3_GetWireframeOptions(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetWireframeOptions(real_this);
}

static D3DRMRENDERQUALITY STDCALL SDL_IDirect3DRMDevice3_GetQuality(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetQuality(real_this);
}

static D3DCOLORMODEL STDCALL SDL_IDirect3DRMDevice3_GetColorModel(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetColorModel(real_this);
}

static D3DRMTEXTUREQUALITY STDCALL SDL_IDirect3DRMDevice3_GetTextureQuality(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetTextureQuality(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_GetDirect3DDevice(IDirect3DRMDevice3 *this, IDirect3DDevice **d3d_device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetDirect3DDevice(real_this, d3d_device);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_InitFromD3D2(IDirect3DRMDevice3 *this, IDirect3D2 *d3d, IDirect3DDevice2 *device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_InitFromD3D2(real_this, d3d, device);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_InitFromSurface(IDirect3DRMDevice3 *this, SDL_GUID *guid, IDirectDraw *ddraw, IDirectDrawSurface *surface) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_InitFromSurface(real_this, guid, ddraw, surface);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetRenderMode(IDirect3DRMDevice3 *this, DWORD flags) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetRenderMode(real_this, flags);
}

static DWORD STDCALL SDL_IDirect3DRMDevice3_GetRenderMode(IDirect3DRMDevice3 *this) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetRenderMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_GetDirect3DDevice2(IDirect3DRMDevice3 *this, IDirect3DDevice2 **device) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetDirect3DDevice2(real_this, device);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_FindPreferredTextureFormat(IDirect3DRMDevice3 *this, DWORD BitDepths, DWORD flags, DDPIXELFORMAT *format) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_FindPreferredTextureFormat(real_this, BitDepths, flags, format);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_RenderStateChange(IDirect3DRMDevice3 *this, D3DRENDERSTATETYPE drsType, DWORD val, DWORD flags) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_RenderStateChange(real_this, drsType, val, flags);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_LightStateChange(IDirect3DRMDevice3 *this, D3DLIGHTSTATETYPE drsType, DWORD val, DWORD flags) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_LightStateChange(real_this, drsType, val, flags);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_GetStateChangeOptions(IDirect3DRMDevice3 *this, DWORD state_class, DWORD state_idx, DWORD *flags) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_GetStateChangeOptions(real_this, state_class, state_idx, flags);
}

static HRESULT STDCALL SDL_IDirect3DRMDevice3_SetStateChangeOptions(IDirect3DRMDevice3 *this, DWORD StateClass, DWORD StateNum, DWORD flags) {
    SDL_Direct3DRMDevice *real_this = from_IDirect3DRMDevice3(this);
    return SDL_Direct3DRMDevice_SetStateChangeOptions(real_this, StateClass, StateNum, flags);
}

static IDirect3DRMDevice3Vtbl SDL_IDirect3DRMDevice3_Vtable = {
    SDL_IDirect3DRMDevice3_QueryInterface,
    SDL_IDirect3DRMDevice3_AddRef,
    SDL_IDirect3DRMDevice3_Release,
    SDL_IDirect3DRMDevice3_Clone,
    SDL_IDirect3DRMDevice3_AddDestroyCallback,
    SDL_IDirect3DRMDevice3_DeleteDestroyCallback,
    SDL_IDirect3DRMDevice3_SetAppData,
    SDL_IDirect3DRMDevice3_GetAppData,
    SDL_IDirect3DRMDevice3_SetName,
    SDL_IDirect3DRMDevice3_GetName,
    SDL_IDirect3DRMDevice3_GetClassName,
    SDL_IDirect3DRMDevice3_Init,
    SDL_IDirect3DRMDevice3_InitFromD3D,
    SDL_IDirect3DRMDevice3_InitFromClipper,
    SDL_IDirect3DRMDevice3_Update,
    SDL_IDirect3DRMDevice3_AddUpdateCallback,
    SDL_IDirect3DRMDevice3_DeleteUpdateCallback,
    SDL_IDirect3DRMDevice3_SetBufferCount,
    SDL_IDirect3DRMDevice3_GetBufferCount,
    SDL_IDirect3DRMDevice3_SetDither,
    SDL_IDirect3DRMDevice3_SetShades,
    SDL_IDirect3DRMDevice3_SetQuality,
    SDL_IDirect3DRMDevice3_SetTextureQuality,
    SDL_IDirect3DRMDevice3_GetViewports,
    SDL_IDirect3DRMDevice3_GetDither,
    SDL_IDirect3DRMDevice3_GetShades,
    SDL_IDirect3DRMDevice3_GetHeight,
    SDL_IDirect3DRMDevice3_GetWidth,
    SDL_IDirect3DRMDevice3_GetTrianglesDrawn,
    SDL_IDirect3DRMDevice3_GetWireframeOptions,
    SDL_IDirect3DRMDevice3_GetQuality,
    SDL_IDirect3DRMDevice3_GetColorModel,
    SDL_IDirect3DRMDevice3_GetTextureQuality,
    SDL_IDirect3DRMDevice3_GetDirect3DDevice,
    SDL_IDirect3DRMDevice3_InitFromD3D2,
    SDL_IDirect3DRMDevice3_InitFromSurface,
    SDL_IDirect3DRMDevice3_SetRenderMode,
    SDL_IDirect3DRMDevice3_GetRenderMode,
    SDL_IDirect3DRMDevice3_GetDirect3DDevice2,
    SDL_IDirect3DRMDevice3_FindPreferredTextureFormat,
    SDL_IDirect3DRMDevice3_RenderStateChange,
    SDL_IDirect3DRMDevice3_LightStateChange,
    SDL_IDirect3DRMDevice3_GetStateChangeOptions,
    SDL_IDirect3DRMDevice3_SetStateChangeOptions,
};

SDL_Direct3DRMDevice *SDL_CreateD3DRMDevice(void) {
    SDL_Direct3DRMDevice *device = (SDL_Direct3DRMDevice *) SDL_calloc(1, sizeof(SDL_Direct3DRMDevice));
    device->interface_IDirect3DRMDevice.lpVtbl = &SDL_IDirect3DRMDevice_Vtable;
    device->interface_IDirect3DRMDevice2.lpVtbl = &SDL_IDirect3DRMDevice2_Vtable;
    device->interface_IDirect3DRMDevice3.lpVtbl = &SDL_IDirect3DRMDevice3_Vtable;
    device->ref_count.value = 1;
    return device;
}
