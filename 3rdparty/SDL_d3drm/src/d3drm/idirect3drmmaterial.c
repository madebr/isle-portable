#include "idirect3drmmaterial.h"
#include "common/common_logging.h"

#include "adapters.h"

#include <d3drmobj.h>
#include <winglue.h>


static HRESULT STDCALL SDL_Direct3DRMMaterial_QueryInterface(Direct3DRMMaterial *this, REFIID a, void **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static ULONG STDCALL SDL_Direct3DRMMaterial_AddRef(Direct3DRMMaterial *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static ULONG STDCALL SDL_Direct3DRMMaterial_Release(Direct3DRMMaterial *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_Clone(Direct3DRMMaterial *this, IUnknown *a, REFIID b, void **c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_AddDestroyCallback(Direct3DRMMaterial *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_DeleteDestroyCallback(Direct3DRMMaterial *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_SetAppData(Direct3DRMMaterial *this, LPVOID a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static LPVOID STDCALL SDL_Direct3DRMMaterial_GetAppData(Direct3DRMMaterial *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_SetName(Direct3DRMMaterial *this, const char *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_GetName(Direct3DRMMaterial *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_GetClassName(Direct3DRMMaterial *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_SetPower(Direct3DRMMaterial *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_SetSpecular(Direct3DRMMaterial *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_SetEmissive(Direct3DRMMaterial *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DVALUE STDCALL SDL_Direct3DRMMaterial_GetPower(Direct3DRMMaterial *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_GetSpecular(Direct3DRMMaterial *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_GetEmissive(Direct3DRMMaterial *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_GetAmbient(Direct3DRMMaterial *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMaterial_SetAmbient(Direct3DRMMaterial *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}


// IDirect3DRMMaterial interface

static HRESULT STDCALL SDL_IDirect3DRMMaterial_QueryInterface(IDirect3DRMMaterial *this, REFIID a, void **b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMMaterial_AddRef(IDirect3DRMMaterial *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMMaterial_Release(IDirect3DRMMaterial *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_Clone(IDirect3DRMMaterial *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_AddDestroyCallback(IDirect3DRMMaterial *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_DeleteDestroyCallback(IDirect3DRMMaterial *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_SetAppData(IDirect3DRMMaterial *this, LPVOID a) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMMaterial_GetAppData(IDirect3DRMMaterial *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_SetName(IDirect3DRMMaterial *this, const char *a) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_GetName(IDirect3DRMMaterial *this, DWORD *a, char *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_GetClassName(IDirect3DRMMaterial *this, DWORD *a, char *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_SetPower(IDirect3DRMMaterial *this, D3DVALUE a) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_SetPower(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_SetSpecular(IDirect3DRMMaterial *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_SetSpecular(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_SetEmissive(IDirect3DRMMaterial *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_SetEmissive(real_this, a, b, c);
}

static D3DVALUE STDCALL SDL_IDirect3DRMMaterial_GetPower(IDirect3DRMMaterial *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_GetPower(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_GetSpecular(IDirect3DRMMaterial *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_GetSpecular(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial_GetEmissive(IDirect3DRMMaterial *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial(this);
    return SDL_Direct3DRMMaterial_GetEmissive(real_this, a, b, c);
}


static IDirect3DRMMaterialVtbl SDL_IDirect3DRMMaterial_Vtable = {
    SDL_IDirect3DRMMaterial_QueryInterface,
    SDL_IDirect3DRMMaterial_AddRef,
    SDL_IDirect3DRMMaterial_Release,
    SDL_IDirect3DRMMaterial_Clone,
    SDL_IDirect3DRMMaterial_AddDestroyCallback,
    SDL_IDirect3DRMMaterial_DeleteDestroyCallback,
    SDL_IDirect3DRMMaterial_SetAppData,
    SDL_IDirect3DRMMaterial_GetAppData,
    SDL_IDirect3DRMMaterial_SetName,
    SDL_IDirect3DRMMaterial_GetName,
    SDL_IDirect3DRMMaterial_GetClassName,
    SDL_IDirect3DRMMaterial_SetPower,
    SDL_IDirect3DRMMaterial_SetSpecular,
    SDL_IDirect3DRMMaterial_SetEmissive,
    SDL_IDirect3DRMMaterial_GetPower,
    SDL_IDirect3DRMMaterial_GetSpecular,
    SDL_IDirect3DRMMaterial_GetEmissive,
};

// IDirect3DRMMaterial2 interface

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_QueryInterface(IDirect3DRMMaterial2 *this, REFIID a, void **b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMMaterial2_AddRef(IDirect3DRMMaterial2 *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMMaterial2_Release(IDirect3DRMMaterial2 *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_Clone(IDirect3DRMMaterial2 *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_AddDestroyCallback(IDirect3DRMMaterial2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_DeleteDestroyCallback(IDirect3DRMMaterial2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_SetAppData(IDirect3DRMMaterial2 *this, LPVOID a) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMMaterial2_GetAppData(IDirect3DRMMaterial2 *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_SetName(IDirect3DRMMaterial2 *this, const char *a) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_GetName(IDirect3DRMMaterial2 *this, DWORD *a, char *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_GetClassName(IDirect3DRMMaterial2 *this, DWORD *a, char *b) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_SetPower(IDirect3DRMMaterial2 *this, D3DVALUE a) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_SetPower(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_SetSpecular(IDirect3DRMMaterial2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_SetSpecular(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_SetEmissive(IDirect3DRMMaterial2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_SetEmissive(real_this, a, b, c);
}

static D3DVALUE STDCALL SDL_IDirect3DRMMaterial2_GetPower(IDirect3DRMMaterial2 *this) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_GetPower(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_GetSpecular(IDirect3DRMMaterial2 *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_GetSpecular(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_GetEmissive(IDirect3DRMMaterial2 *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_GetEmissive(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_GetAmbient(IDirect3DRMMaterial2 *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_GetAmbient(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMaterial2_SetAmbient(IDirect3DRMMaterial2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMaterial *real_this = from_IDirect3DRMMaterial2(this);
    return SDL_Direct3DRMMaterial_SetAmbient(real_this, a, b, c);
}


static IDirect3DRMMaterial2Vtbl SDL_IDirect3DRMMaterial2_Vtable = {
    SDL_IDirect3DRMMaterial2_QueryInterface,
    SDL_IDirect3DRMMaterial2_AddRef,
    SDL_IDirect3DRMMaterial2_Release,
    SDL_IDirect3DRMMaterial2_Clone,
    SDL_IDirect3DRMMaterial2_AddDestroyCallback,
    SDL_IDirect3DRMMaterial2_DeleteDestroyCallback,
    SDL_IDirect3DRMMaterial2_SetAppData,
    SDL_IDirect3DRMMaterial2_GetAppData,
    SDL_IDirect3DRMMaterial2_SetName,
    SDL_IDirect3DRMMaterial2_GetName,
    SDL_IDirect3DRMMaterial2_GetClassName,
    SDL_IDirect3DRMMaterial2_SetPower,
    SDL_IDirect3DRMMaterial2_SetSpecular,
    SDL_IDirect3DRMMaterial2_SetEmissive,
    SDL_IDirect3DRMMaterial2_GetPower,
    SDL_IDirect3DRMMaterial2_GetSpecular,
    SDL_IDirect3DRMMaterial2_GetEmissive,
    SDL_IDirect3DRMMaterial2_GetAmbient,
    SDL_IDirect3DRMMaterial2_SetAmbient,
};
