#include "idirect3drmviewport.h"
#include "idirect3drmdevice.h"
#include "idirect3drmframe.h"
#include "common/common_logging.h"

#include "adapters.h"

#include <d3drmobj.h>
#include <winglue.h>

static HRESULT STDCALL SDL_Direct3DRMViewport_QueryInterface(SDL_Direct3DRMViewport *this, REFIID riid, void **ppvObject) {
    if (SDL_memcmp(riid, &IID_IDirect3DRMViewport, sizeof(SDL_GUID)) == 0) {
        *ppvObject = &this->interface_IDirect3DRMViewport;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRMViewport2, sizeof(SDL_GUID)) == 0) {
        *ppvObject = &this->interface_IDirect3DRMViewport2;
        return S_OK;
    } else {
        *ppvObject = NULL;
        return E_NOINTERFACE;
    }
}

static ULONG STDCALL SDL_Direct3DRMViewport_AddRef(SDL_Direct3DRMViewport *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, 1);
    return prev_value + 1;
}

static ULONG STDCALL SDL_Direct3DRMViewport_Release(SDL_Direct3DRMViewport *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, -1);
    if (prev_value == 1) {
        SDL_free(this);
    }
    return (ULONG) prev_value - 1;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_Clone(SDL_Direct3DRMViewport *this, IUnknown *a, REFIID b, void **c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_AddDestroyCallback(SDL_Direct3DRMViewport *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_DeleteDestroyCallback(SDL_Direct3DRMViewport *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetAppData(SDL_Direct3DRMViewport *this, LPVOID a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static LPVOID STDCALL SDL_Direct3DRMViewport_GetAppData(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetName(SDL_Direct3DRMViewport *this, const char *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_GetName(SDL_Direct3DRMViewport *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_GetClassName(SDL_Direct3DRMViewport *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_Init(SDL_Direct3DRMViewport *this, SDL_Direct3DRMDevice *a, Direct3DRMFrame *b, DWORD c, DWORD d, DWORD e, DWORD f) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    (void) e;
    (void) f;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_Clear(SDL_Direct3DRMViewport *this, DWORD dwFlags) {
    (void) this;
    (void) dwFlags;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_Render(SDL_Direct3DRMViewport *this, Direct3DRMFrame *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetFront(SDL_Direct3DRMViewport *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetBack(SDL_Direct3DRMViewport *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetField(SDL_Direct3DRMViewport *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetUniformScaling(SDL_Direct3DRMViewport *this, BOOL a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetCamera(SDL_Direct3DRMViewport *this, Direct3DRMFrame *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetProjection(SDL_Direct3DRMViewport *this, D3DRMPROJECTIONTYPE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_Transform(SDL_Direct3DRMViewport *this, D3DRMVECTOR4D *a, D3DVECTOR *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_InverseTransform(SDL_Direct3DRMViewport *this, D3DVECTOR *a, D3DRMVECTOR4D *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_Configure(SDL_Direct3DRMViewport *this, LONG a, LONG b, DWORD c, DWORD d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_ForceUpdate(SDL_Direct3DRMViewport *this, DWORD a, DWORD b, DWORD c, DWORD d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_SetPlane(SDL_Direct3DRMViewport *this, D3DVALUE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_GetCamera(SDL_Direct3DRMViewport *this, Direct3DRMFrame **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_GetDevice(SDL_Direct3DRMViewport *this, SDL_Direct3DRMDevice **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_GetPlane(SDL_Direct3DRMViewport *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c, D3DVALUE *d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_Pick(SDL_Direct3DRMViewport *this, LONG a, LONG b, struct IDirect3DRMPickedArray **c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static BOOL STDCALL SDL_Direct3DRMViewport_GetUniformScaling(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static LONG STDCALL SDL_Direct3DRMViewport_GetX(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1;
}

static LONG STDCALL SDL_Direct3DRMViewport_GetY(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1;
}

static DWORD STDCALL SDL_Direct3DRMViewport_GetWidth(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static DWORD STDCALL SDL_Direct3DRMViewport_GetHeight(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DVALUE STDCALL SDL_Direct3DRMViewport_GetField(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DVALUE STDCALL SDL_Direct3DRMViewport_GetBack(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DVALUE STDCALL SDL_Direct3DRMViewport_GetFront(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return -1.f;
}

static D3DRMPROJECTIONTYPE STDCALL SDL_Direct3DRMViewport_GetProjection(SDL_Direct3DRMViewport *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return D3DRMPROJECT_PERSPECTIVE;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_GetDirect3DViewport(SDL_Direct3DRMViewport *this, IDirect3DViewport **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_TransformVectors(SDL_Direct3DRMViewport *this, DWORD a, D3DRMVECTOR4D *b, D3DVECTOR *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMViewport_InverseTransformVectors(SDL_Direct3DRMViewport *this, DWORD a, D3DVECTOR *b, D3DRMVECTOR4D *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}


// IDirect3DRMViewport interface

static HRESULT STDCALL SDL_IDirect3DRMViewport_QueryInterface(IDirect3DRMViewport *this, REFIID a, void **b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMViewport_AddRef(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMViewport_Release(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_Clone(IDirect3DRMViewport *this, IUnknown *a, REFIID b, void **c) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_AddDestroyCallback(IDirect3DRMViewport *this, D3DRMOBJECTCALLBACK a, void *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_DeleteDestroyCallback(IDirect3DRMViewport *this, D3DRMOBJECTCALLBACK a, void *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetAppData(IDirect3DRMViewport *this, LPVOID a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMViewport_GetAppData(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetName(IDirect3DRMViewport *this, const char *a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_GetName(IDirect3DRMViewport *this, DWORD *a, char *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_GetClassName(IDirect3DRMViewport *this, DWORD *a, char *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_Init(IDirect3DRMViewport *this, IDirect3DRMDevice *a, struct IDirect3DRMFrame *b, DWORD c, DWORD d, DWORD e, DWORD f) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Init(real_this, from_IDirect3DRMDevice(a), from_IDirect3DRMFrame(b), c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_Clear(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Clear(real_this, 0);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_Render(IDirect3DRMViewport *this, IDirect3DRMFrame *a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Render(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetFront(IDirect3DRMViewport *this, D3DVALUE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetFront(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetBack(IDirect3DRMViewport *this, D3DVALUE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetBack(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetField(IDirect3DRMViewport *this, D3DVALUE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetField(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetUniformScaling(IDirect3DRMViewport *this, BOOL a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetUniformScaling(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetCamera(IDirect3DRMViewport *this, IDirect3DRMFrame *a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetCamera(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetProjection(IDirect3DRMViewport *this, D3DRMPROJECTIONTYPE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetProjection(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_Transform(IDirect3DRMViewport *this, D3DRMVECTOR4D *a, D3DVECTOR *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Transform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_InverseTransform(IDirect3DRMViewport *this, D3DVECTOR *a, D3DRMVECTOR4D *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_InverseTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_Configure(IDirect3DRMViewport *this, LONG a, LONG b, DWORD c, DWORD d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Configure(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_ForceUpdate(IDirect3DRMViewport *this, DWORD a, DWORD b, DWORD c, DWORD d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_ForceUpdate(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_SetPlane(IDirect3DRMViewport *this, D3DVALUE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_SetPlane(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_GetCamera(IDirect3DRMViewport *this, IDirect3DRMFrame **a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRMViewport_GetCamera(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_GetDevice(IDirect3DRMViewport *this, IDirect3DRMDevice **a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRMViewport_GetDevice(real_this, &device);
    if (a) {
        *a = &device->interface_IDirect3DRMDevice;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_GetPlane(IDirect3DRMViewport *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c, D3DVALUE *d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetPlane(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_Pick(IDirect3DRMViewport *this, LONG a, LONG b, IDirect3DRMPickedArray **c) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_Pick(real_this, a, b, c);
}

static BOOL STDCALL SDL_IDirect3DRMViewport_GetUniformScaling(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetUniformScaling(real_this);
}

static LONG STDCALL SDL_IDirect3DRMViewport_GetX(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetX(real_this);
}

static LONG STDCALL SDL_IDirect3DRMViewport_GetY(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetY(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMViewport_GetWidth(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetWidth(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMViewport_GetHeight(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetHeight(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMViewport_GetField(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetField(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMViewport_GetBack(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetBack(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMViewport_GetFront(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetFront(real_this);
}

static D3DRMPROJECTIONTYPE STDCALL SDL_IDirect3DRMViewport_GetProjection(IDirect3DRMViewport *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetProjection(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport_GetDirect3DViewport(IDirect3DRMViewport *this, IDirect3DViewport **a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport(this);
    return SDL_Direct3DRMViewport_GetDirect3DViewport(real_this, a);
}


static IDirect3DRMViewportVtbl SDL_IDirect3DRMViewport_Vtable = {
    SDL_IDirect3DRMViewport_QueryInterface,
    SDL_IDirect3DRMViewport_AddRef,
    SDL_IDirect3DRMViewport_Release,
    SDL_IDirect3DRMViewport_Clone,
    SDL_IDirect3DRMViewport_AddDestroyCallback,
    SDL_IDirect3DRMViewport_DeleteDestroyCallback,
    SDL_IDirect3DRMViewport_SetAppData,
    SDL_IDirect3DRMViewport_GetAppData,
    SDL_IDirect3DRMViewport_SetName,
    SDL_IDirect3DRMViewport_GetName,
    SDL_IDirect3DRMViewport_GetClassName,
    SDL_IDirect3DRMViewport_Init,
    SDL_IDirect3DRMViewport_Clear,
    SDL_IDirect3DRMViewport_Render,
    SDL_IDirect3DRMViewport_SetFront,
    SDL_IDirect3DRMViewport_SetBack,
    SDL_IDirect3DRMViewport_SetField,
    SDL_IDirect3DRMViewport_SetUniformScaling,
    SDL_IDirect3DRMViewport_SetCamera,
    SDL_IDirect3DRMViewport_SetProjection,
    SDL_IDirect3DRMViewport_Transform,
    SDL_IDirect3DRMViewport_InverseTransform,
    SDL_IDirect3DRMViewport_Configure,
    SDL_IDirect3DRMViewport_ForceUpdate,
    SDL_IDirect3DRMViewport_SetPlane,
    SDL_IDirect3DRMViewport_GetCamera,
    SDL_IDirect3DRMViewport_GetDevice,
    SDL_IDirect3DRMViewport_GetPlane,
    SDL_IDirect3DRMViewport_Pick,
    SDL_IDirect3DRMViewport_GetUniformScaling,
    SDL_IDirect3DRMViewport_GetX,
    SDL_IDirect3DRMViewport_GetY,
    SDL_IDirect3DRMViewport_GetWidth,
    SDL_IDirect3DRMViewport_GetHeight,
    SDL_IDirect3DRMViewport_GetField,
    SDL_IDirect3DRMViewport_GetBack,
    SDL_IDirect3DRMViewport_GetFront,
    SDL_IDirect3DRMViewport_GetProjection,
    SDL_IDirect3DRMViewport_GetDirect3DViewport,
};

// IDirect3DRMViewport2 interface

static HRESULT STDCALL SDL_IDirect3DRMViewport2_QueryInterface(IDirect3DRMViewport2 *this, REFIID a, void **b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMViewport2_AddRef(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMViewport2_Release(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_Clone(IDirect3DRMViewport2 *this, IUnknown *a, REFIID b, void **c) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_AddDestroyCallback(IDirect3DRMViewport2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_DeleteDestroyCallback(IDirect3DRMViewport2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetAppData(IDirect3DRMViewport2 *this, LPVOID a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMViewport2_GetAppData(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetName(IDirect3DRMViewport2 *this, const char *a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_GetName(IDirect3DRMViewport2 *this, DWORD *a, char *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_GetClassName(IDirect3DRMViewport2 *this, DWORD *a, char *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_Init(IDirect3DRMViewport2 *this, IDirect3DRMDevice3 *a, struct IDirect3DRMFrame3 *b, DWORD c, DWORD d, DWORD e, DWORD f) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Init(real_this, from_IDirect3DRMDevice3(a), from_IDirect3DRMFrame3(b), c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_Clear(IDirect3DRMViewport2 *this, DWORD a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Clear(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_Render(IDirect3DRMViewport2 *this, IDirect3DRMFrame3 *a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Render(real_this, from_IDirect3DRMFrame3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetFront(IDirect3DRMViewport2 *this, D3DVALUE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetFront(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetBack(IDirect3DRMViewport2 *this, D3DVALUE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetBack(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetField(IDirect3DRMViewport2 *this, D3DVALUE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetField(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetUniformScaling(IDirect3DRMViewport2 *this, BOOL a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetUniformScaling(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetCamera(IDirect3DRMViewport2 *this, IDirect3DRMFrame3 *a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetCamera(real_this, from_IDirect3DRMFrame3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetProjection(IDirect3DRMViewport2 *this, D3DRMPROJECTIONTYPE a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetProjection(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_Transform(IDirect3DRMViewport2 *this, D3DRMVECTOR4D *a, D3DVECTOR *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Transform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_InverseTransform(IDirect3DRMViewport2 *this, D3DVECTOR *a, D3DRMVECTOR4D *b) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_InverseTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_Configure(IDirect3DRMViewport2 *this, LONG a, LONG b, DWORD c, DWORD d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Configure(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_ForceUpdate(IDirect3DRMViewport2 *this, DWORD a, DWORD b, DWORD c, DWORD d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_ForceUpdate(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_SetPlane(IDirect3DRMViewport2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_SetPlane(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_GetCamera(IDirect3DRMViewport2 *this, struct IDirect3DRMFrame3 **a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRMViewport_GetCamera(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame3;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_GetDevice(IDirect3DRMViewport2 *this, IDirect3DRMDevice3 **a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRMViewport_GetDevice(real_this, &device);
    if (a) {
        *a = &device->interface_IDirect3DRMDevice3;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_GetPlane(IDirect3DRMViewport2 *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c, D3DVALUE *d) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetPlane(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_Pick(IDirect3DRMViewport2 *this, LONG a, LONG b, struct IDirect3DRMPickedArray **c) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_Pick(real_this, a, b, c);
}

static BOOL STDCALL SDL_IDirect3DRMViewport2_GetUniformScaling(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetUniformScaling(real_this);
}

static LONG STDCALL SDL_IDirect3DRMViewport2_GetX(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetX(real_this);
}

static LONG STDCALL SDL_IDirect3DRMViewport2_GetY(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetY(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMViewport2_GetWidth(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetWidth(real_this);
}

static DWORD STDCALL SDL_IDirect3DRMViewport2_GetHeight(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetHeight(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMViewport2_GetField(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetField(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMViewport2_GetBack(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetBack(real_this);
}

static D3DVALUE STDCALL SDL_IDirect3DRMViewport2_GetFront(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetFront(real_this);
}

static D3DRMPROJECTIONTYPE STDCALL SDL_IDirect3DRMViewport2_GetProjection(IDirect3DRMViewport2 *this) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetProjection(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_GetDirect3DViewport(IDirect3DRMViewport2 *this, IDirect3DViewport **a) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_GetDirect3DViewport(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_TransformVectors(IDirect3DRMViewport2 *this, DWORD a, D3DRMVECTOR4D *b, D3DVECTOR *c) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_TransformVectors(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMViewport2_InverseTransformVectors(IDirect3DRMViewport2 *this, DWORD a, D3DVECTOR *b, D3DRMVECTOR4D *c) {
    SDL_Direct3DRMViewport *real_this = from_IDirect3DRMViewport2(this);
    return SDL_Direct3DRMViewport_InverseTransformVectors(real_this, a, b, c);
}


static IDirect3DRMViewport2Vtbl SDL_IDirect3DRMViewport2_Vtable = {
    SDL_IDirect3DRMViewport2_QueryInterface,
    SDL_IDirect3DRMViewport2_AddRef,
    SDL_IDirect3DRMViewport2_Release,
    SDL_IDirect3DRMViewport2_Clone,
    SDL_IDirect3DRMViewport2_AddDestroyCallback,
    SDL_IDirect3DRMViewport2_DeleteDestroyCallback,
    SDL_IDirect3DRMViewport2_SetAppData,
    SDL_IDirect3DRMViewport2_GetAppData,
    SDL_IDirect3DRMViewport2_SetName,
    SDL_IDirect3DRMViewport2_GetName,
    SDL_IDirect3DRMViewport2_GetClassName,
    SDL_IDirect3DRMViewport2_Init,
    SDL_IDirect3DRMViewport2_Clear,
    SDL_IDirect3DRMViewport2_Render,
    SDL_IDirect3DRMViewport2_SetFront,
    SDL_IDirect3DRMViewport2_SetBack,
    SDL_IDirect3DRMViewport2_SetField,
    SDL_IDirect3DRMViewport2_SetUniformScaling,
    SDL_IDirect3DRMViewport2_SetCamera,
    SDL_IDirect3DRMViewport2_SetProjection,
    SDL_IDirect3DRMViewport2_Transform,
    SDL_IDirect3DRMViewport2_InverseTransform,
    SDL_IDirect3DRMViewport2_Configure,
    SDL_IDirect3DRMViewport2_ForceUpdate,
    SDL_IDirect3DRMViewport2_SetPlane,
    SDL_IDirect3DRMViewport2_GetCamera,
    SDL_IDirect3DRMViewport2_GetDevice,
    SDL_IDirect3DRMViewport2_GetPlane,
    SDL_IDirect3DRMViewport2_Pick,
    SDL_IDirect3DRMViewport2_GetUniformScaling,
    SDL_IDirect3DRMViewport2_GetX,
    SDL_IDirect3DRMViewport2_GetY,
    SDL_IDirect3DRMViewport2_GetWidth,
    SDL_IDirect3DRMViewport2_GetHeight,
    SDL_IDirect3DRMViewport2_GetField,
    SDL_IDirect3DRMViewport2_GetBack,
    SDL_IDirect3DRMViewport2_GetFront,
    SDL_IDirect3DRMViewport2_GetProjection,
    SDL_IDirect3DRMViewport2_GetDirect3DViewport,
    SDL_IDirect3DRMViewport2_TransformVectors,
    SDL_IDirect3DRMViewport2_InverseTransformVectors,
};

extern SDL_Direct3DRMViewport *SDL_Allocate3DRMViewport(int x, int y, int width, int height) {
    SDL_Direct3DRMViewport *viewport = (SDL_Direct3DRMViewport *) SDL_calloc(1, sizeof(SDL_Direct3DRMViewport));
    if (viewport == NULL) {
        return NULL;
    }
    viewport->x = x;
    viewport->y = y;
    viewport->width = width;
    viewport->height = height;
    viewport->interface_IDirect3DRMViewport.lpVtbl = &SDL_IDirect3DRMViewport_Vtable;
    viewport->interface_IDirect3DRMViewport2.lpVtbl = &SDL_IDirect3DRMViewport2_Vtable;
    return viewport;
}
