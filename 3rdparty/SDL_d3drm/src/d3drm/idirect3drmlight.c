#include "idirect3drmlight.h"
#include "common/common_logging.h"

#include "d3drmobj.h"
#include "winglue.h"


static HRESULT STDCALL SDL_Direct3DRMLight_QueryInterface(SDL_Direct3DRMLight *this, REFIID a, void **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static ULONG STDCALL SDL_Direct3DRMLight_AddRef(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static ULONG STDCALL SDL_Direct3DRMLight_Release(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMLight_Clone(SDL_Direct3DRMLight *this, IUnknown *a, REFIID b, void **c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_AddDestroyCallback(SDL_Direct3DRMLight *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_DeleteDestroyCallback(SDL_Direct3DRMLight *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetAppData(SDL_Direct3DRMLight *this, LPVOID a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static LPVOID STDCALL SDL_Direct3DRMLight_GetAppData(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetName(SDL_Direct3DRMLight *this, const char *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_GetName(SDL_Direct3DRMLight *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_GetClassName(SDL_Direct3DRMLight *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetType(SDL_Direct3DRMLight *this, D3DRMLIGHTTYPE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetColor(SDL_Direct3DRMLight *this, D3DCOLOR a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetColorRGB(SDL_Direct3DRMLight *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetRange(SDL_Direct3DRMLight *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetUmbra(SDL_Direct3DRMLight *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetPenumbra(SDL_Direct3DRMLight *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetConstantAttenuation(SDL_Direct3DRMLight *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetLinearAttenuation(SDL_Direct3DRMLight *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetQuadraticAttenuation(SDL_Direct3DRMLight *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DVALUE STDCALL SDL_Direct3DRMLight_GetRange(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DVALUE STDCALL SDL_Direct3DRMLight_GetUmbra(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DVALUE STDCALL SDL_Direct3DRMLight_GetPenumbra(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DVALUE STDCALL SDL_Direct3DRMLight_GetConstantAttenuation(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DVALUE STDCALL SDL_Direct3DRMLight_GetLinearAttenuation(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DVALUE STDCALL SDL_Direct3DRMLight_GetQuadraticAttenuation(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DCOLOR STDCALL SDL_Direct3DRMLight_GetColor(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DRMLIGHTTYPE STDCALL SDL_Direct3DRMLight_GetType(SDL_Direct3DRMLight *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1;
}

static HRESULT STDCALL SDL_Direct3DRMLight_SetEnableFrame(SDL_Direct3DRMLight *this, IDirect3DRMFrame *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMLight_GetEnableFrame(SDL_Direct3DRMLight *this, IDirect3DRMFrame **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}


// IDirect3DRMLight interface

static HRESULT STDCALL SDL_IDirect3DRMLight_QueryInterface(IDirect3DRMLight *this, REFIID a, void **b) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMLight_AddRef(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMLight_Release(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_Clone(IDirect3DRMLight *this, IUnknown *a, REFIID b, void **c) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_AddDestroyCallback(IDirect3DRMLight *this, D3DRMOBJECTCALLBACK a, void *b) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_DeleteDestroyCallback(IDirect3DRMLight *this, D3DRMOBJECTCALLBACK a, void *b) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetAppData(IDirect3DRMLight *this, LPVOID a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMLight_GetAppData(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetName(IDirect3DRMLight *this, const char *a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_GetName(IDirect3DRMLight *this, DWORD *a, char *b) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_GetClassName(IDirect3DRMLight *this, DWORD *a, char *b) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetType(IDirect3DRMLight *this, D3DRMLIGHTTYPE a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetType(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetColor(IDirect3DRMLight *this, D3DCOLOR a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetColorRGB(IDirect3DRMLight *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetColorRGB(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetRange(IDirect3DRMLight *this, D3DVALUE a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetRange(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetUmbra(IDirect3DRMLight *this, D3DVALUE a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetUmbra(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetPenumbra(IDirect3DRMLight *this, D3DVALUE a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetPenumbra(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetConstantAttenuation(IDirect3DRMLight *this, D3DVALUE a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetConstantAttenuation(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetLinearAttenuation(IDirect3DRMLight *this, D3DVALUE a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetLinearAttenuation(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetQuadraticAttenuation(IDirect3DRMLight *this, D3DVALUE a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetQuadraticAttenuation(real_this, a);
}

static D3DVALUE STDCALL SDL_IDirect3DRMLight_GetRange(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetRange(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMLight_GetUmbra(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetUmbra(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMLight_GetPenumbra(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetPenumbra(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMLight_GetConstantAttenuation(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetConstantAttenuation(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMLight_GetLinearAttenuation(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetLinearAttenuation(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMLight_GetQuadraticAttenuation(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetQuadraticAttenuation(real_this);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMLight_GetColor(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetColor(real_this);
}

static D3DRMLIGHTTYPE STDCALL SDL_IDirect3DRMLight_GetType(IDirect3DRMLight *this) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetType(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_SetEnableFrame(IDirect3DRMLight *this, IDirect3DRMFrame *a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_SetEnableFrame(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMLight_GetEnableFrame(IDirect3DRMLight *this, IDirect3DRMFrame **a) {
    SDL_Direct3DRMLight *real_this = from_IDirect3DRMLight(this);
    return SDL_Direct3DRMLight_GetEnableFrame(real_this, a);
}


static IDirect3DRMLightVtbl SDL_IDirect3DRMLight_Vtable = {
    SDL_IDirect3DRMLight_QueryInterface,
    SDL_IDirect3DRMLight_AddRef,
    SDL_IDirect3DRMLight_Release,
    SDL_IDirect3DRMLight_Clone,
    SDL_IDirect3DRMLight_AddDestroyCallback,
    SDL_IDirect3DRMLight_DeleteDestroyCallback,
    SDL_IDirect3DRMLight_SetAppData,
    SDL_IDirect3DRMLight_GetAppData,
    SDL_IDirect3DRMLight_SetName,
    SDL_IDirect3DRMLight_GetName,
    SDL_IDirect3DRMLight_GetClassName,
    SDL_IDirect3DRMLight_SetType,
    SDL_IDirect3DRMLight_SetColor,
    SDL_IDirect3DRMLight_SetColorRGB,
    SDL_IDirect3DRMLight_SetRange,
    SDL_IDirect3DRMLight_SetUmbra,
    SDL_IDirect3DRMLight_SetPenumbra,
    SDL_IDirect3DRMLight_SetConstantAttenuation,
    SDL_IDirect3DRMLight_SetLinearAttenuation,
    SDL_IDirect3DRMLight_SetQuadraticAttenuation,
    SDL_IDirect3DRMLight_GetRange,
    SDL_IDirect3DRMLight_GetUmbra,
    SDL_IDirect3DRMLight_GetPenumbra,
    SDL_IDirect3DRMLight_GetConstantAttenuation,
    SDL_IDirect3DRMLight_GetLinearAttenuation,
    SDL_IDirect3DRMLight_GetQuadraticAttenuation,
    SDL_IDirect3DRMLight_GetColor,
    SDL_IDirect3DRMLight_GetType,
    SDL_IDirect3DRMLight_SetEnableFrame,
    SDL_IDirect3DRMLight_GetEnableFrame,
};
