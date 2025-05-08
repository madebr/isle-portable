#define SDL_INITGUID

#include "idirect3drm.h"
#include "idirect3drmanimation.h"
#include "idirect3drmanimationset.h"
#include "idirect3drmdevice.h"
#include "idirect3drmface.h"
#include "idirect3drmframe.h"
#include "idirect3drmmaterial.h"
#include "idirect3drmmeshbuilder.h"
#include "idirect3drmtexture.h"
#include "idirect3drmviewport.h"
#include "common/common_com.h"

#include "adapters.h"

#include "common/common_logging.h"

static HRESULT STDCALL SDL_Direct3DRM_QueryInterface(Direct3DRM *this, REFIID riid, void **ppvObject) {
    if (ppvObject == NULL) {
        return E_POINTER;
    }
    if (SDL_memcmp(riid, &IID_IDirect3DRM, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRM;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRM2, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRM2;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRM3, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRM3;
        return S_OK;
    } else {
        *ppvObject = NULL;
        return E_NOINTERFACE;
    }
}

static ULONG STDCALL SDL_Direct3DRM_AddRef(Direct3DRM *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, 1);
    return (ULONG) prev_value + 1;
}

static ULONG STDCALL SDL_Direct3DRM_Release(Direct3DRM *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, -1);
    if (prev_value == 1) {
        for (common_linked_list *l = this->search_path; l != NULL; ) {
            SDL_free(l->str);
            common_linked_list *next = l->next;
            SDL_free(l);
            l = next;
        }
        SDL_free(this);
    }
    return (ULONG) prev_value - 1;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateObject(Direct3DRM *this, REFCLSID rclsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) {
    (void) this;
    (void) rclsid;
    (void) pUnkOuter;
    (void) riid;
    (void) ppv;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateFrame(Direct3DRM *this, Direct3DRMFrame *lpD3DRMFrame, Direct3DRMFrame **lplpD3DRMFrame) {
    (void) this;
    (void) lpD3DRMFrame;
    (void) lplpD3DRMFrame;
    Direct3DRMFrame *frame;
    if (lplpD3DRMFrame == NULL) {
        return E_POINTER;
    }
    frame = SDL_CreateD3DRMFrame(lpD3DRMFrame);
    if (frame == NULL) {
        return E_POINTER;
    }
    *lplpD3DRMFrame = frame;
    return S_OK;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateMesh(Direct3DRM *this, LPDIRECT3DRMMESH *lplpD3DRMMesh) {
    (void) this;
    (void) lplpD3DRMMesh;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateMeshBuilder(Direct3DRM *this, Direct3DRMMeshBuilder **lplpD3DRMMeshBuilder) {
    (void) this;
    (void) lplpD3DRMMeshBuilder;
    Direct3DRMMeshBuilder *builder;
    if (lplpD3DRMMeshBuilder == NULL) {
        return E_POINTER;
    }
    builder = SDL_CreateD3DRMMeshBuilder();
    if (builder == NULL) {
        return E_POINTER;
    }
    *lplpD3DRMMeshBuilder = builder;
    return S_OK;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateFace(Direct3DRM *this, SDL_Direct3DRMFace **lplpd3drmFace) {
    (void) this;
    (void) lplpd3drmFace;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateAnimation(Direct3DRM *this, SDL_Direct3DRMAnimation **lplpD3DRMAnimation) {
    (void) this;
    (void) lplpD3DRMAnimation;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateAnimationSet(Direct3DRM *this, SDL_Direct3DRMAnimationSet **lplpD3DRMAnimationSet) {
    (void) this;
    (void) lplpD3DRMAnimationSet;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateTexture(Direct3DRM *this, LPD3DRMIMAGE lpImage, Direct3DRMTexture **lplpD3DRMTexture) {
    (void) this;
    (void) lpImage;
    (void) lplpD3DRMTexture;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateLight(Direct3DRM *this, D3DRMLIGHTTYPE d3drmltLightType, D3DCOLOR cColor, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    (void) this;
    (void) d3drmltLightType;
    (void) cColor;
    (void) lplpD3DRMLight;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateLightRGB(Direct3DRM *this, D3DRMLIGHTTYPE ltLightType, D3DVALUE vRed, D3DVALUE vGreen, D3DVALUE vBlue, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    (void) this;
    (void) ltLightType;
    (void) vRed;
    (void) vGreen;
    (void) vBlue;
    (void) lplpD3DRMLight;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateMaterial(Direct3DRM *this, D3DVALUE vPower, Direct3DRMMaterial **lplpD3DRMMaterial) {
    (void) this;
    (void) vPower;
    (void) lplpD3DRMMaterial;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateDevice(Direct3DRM *this, DWORD dwWidth, DWORD dwHeight, SDL_Direct3DRMDevice **lplpD3DRMDevice) {
    (void) this;
    (void) dwWidth;
    (void) dwHeight;
    (void) lplpD3DRMDevice;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateDeviceFromSurface(Direct3DRM *this, LPGUID lpGUID, LPDIRECTDRAW lpDD, LPDIRECTDRAWSURFACE lpDDSBack, DWORD dwFlags, SDL_Direct3DRMDevice **lplpD3DRMDevice) {
    (void) this;
    (void) lpGUID;
    (void) lpDD;
    (void) lpDDSBack;
    (void) dwFlags;
    (void) lplpD3DRMDevice;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateDeviceFromD3D(Direct3DRM *this, LPDIRECT3D lpD3D, LPDIRECT3DDEVICE lpD3DDev, SDL_Direct3DRMDevice **lplpD3DRMDevice) {
    (void) this;
    (void) lpD3D;
    (void) lpD3DDev;
    (void) lplpD3DRMDevice;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

// FIXME: how to combine LPDIRECT3D, LPDIRECT3D2 and LPDIRECT3D3?
static HRESULT STDCALL SDL_Direct3DRM_CreateDeviceFromD3D2(Direct3DRM *this, LPDIRECT3D2 lpD3D, LPDIRECT3DDEVICE2 lpD3DDev, SDL_Direct3DRMDevice **lplpD3DRMDevice) {
    (void) this;
    (void) lpD3D;
    (void) lpD3DDev;
    (void) lplpD3DRMDevice;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateDeviceFromClipper(Direct3DRM *this, LPDIRECTDRAWCLIPPER lpDDClipper, LPGUID lpGUID, int width, int height, SDL_Direct3DRMDevice **lplpD3DRMDevice) {
    (void) this;
    (void) lpDDClipper;
    (void) lpGUID;
    (void) width;
    (void) height;
    (void) lplpD3DRMDevice;
    SDL_Direct3DRMDevice *device;
    HRESULT res;
    if (lplpD3DRMDevice == NULL) {
        return E_POINTER;
    }
    if (lpGUID != NULL) {
        return E_NOTIMPL;
    }
    device = SDL_CreateD3DRMDevice();
    if (device == NULL) {
        return E_POINTER;
    }
    res = SDL_Direct3DRMDevice_InitFromClipper(device, lpDDClipper, lpGUID, width, height);
    if (FAILED(res)) {
        COM_DECREF(device);
        return res;
    }
    *lplpD3DRMDevice = device;
    return S_OK;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateTextureFromSurface(Direct3DRM *this, LPDIRECTDRAWSURFACE lpDDS, Direct3DRMTexture **lplpD3DRMTexture) {
    (void) this;
    (void) lpDDS;
    (void) lplpD3DRMTexture;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateShadow(Direct3DRM *this, LPDIRECT3DRMVISUAL lpVisual, LPDIRECT3DRMLIGHT lpLight, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMVISUAL *lplpShadow) {
    (void) this;
    (void) lpVisual;
    (void) lpLight;
    (void) px;
    (void) py;
    (void) pz;
    (void) nx;
    (void) ny;
    (void) nz;
    (void) lplpShadow;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateShadow2(Direct3DRM *this, LPUNKNOWN pUnk, LPDIRECT3DRMLIGHT lpLight, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMSHADOW2 * lplpShadow) {
    (void) this;
    (void) pUnk;
    (void) lpLight;
    (void) px;
    (void) py;
    (void) pz;
    (void) nx;
    (void) ny;
    (void) nz;
    (void) lplpShadow;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateViewport(Direct3DRM *this, SDL_Direct3DRMDevice *lpDev, Direct3DRMFrame *lpCamera, DWORD dwXPos, DWORD dwYPos, DWORD dwWidth, DWORD dwHeight, SDL_Direct3DRMViewport **lplpD3DRMViewport) {
    (void) this;
    (void) lpDev;
    (void) lpCamera;
    (void) dwXPos;
    (void) dwYPos;
    (void) dwWidth;
    (void) dwHeight;
    (void) lplpD3DRMViewport;
    SDL_Direct3DRMViewport *viewport = NULL;
    if (lplpD3DRMViewport == NULL) {
        return E_POINTER;
    }
    viewport = SDL_Allocate3DRMViewport(dwXPos, dwYPos, dwWidth, dwHeight);
    *lplpD3DRMViewport = viewport;
    return S_OK;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateWrap(Direct3DRM *this, D3DRMWRAPTYPE type, Direct3DRMFrame *lpRef, D3DVALUE ox, D3DVALUE oy, D3DVALUE oz, D3DVALUE dx, D3DVALUE dy, D3DVALUE dz, D3DVALUE ux, D3DVALUE uy, D3DVALUE uz, D3DVALUE ou, D3DVALUE ov, D3DVALUE su, D3DVALUE sv, LPDIRECT3DRMWRAP *lplpD3DRMWrap) {
    (void) this;
    (void) type;
    (void) lpRef;
    (void) ox;
    (void) oy;
    (void) oz;
    (void) dx;
    (void) dy;
    (void) dz;
    (void) ux;
    (void) uy;
    (void) uz;
    (void) ou;
    (void) ov;
    (void) su;
    (void) sv;
    (void) lplpD3DRMWrap;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateUserVisual(Direct3DRM *this, D3DRMUSERVISUALCALLBACK fn, LPVOID lpArg, LPDIRECT3DRMUSERVISUAL *lplpD3DRMUV) {
    (void) this;
    (void) fn;
    (void) lpArg;
    (void) lplpD3DRMUV;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_LoadTexture(Direct3DRM *this, const char *lpFileName, Direct3DRMTexture **lplpD3DRMTexture) {
    (void) this;
    (void) lpFileName;
    (void) lplpD3DRMTexture;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_LoadTextureFromResource(Direct3DRM *this, HRSRC rs, Direct3DRMTexture **lplpD3DRMTexture) {
    (void) this;
    (void) rs;
    (void) lplpD3DRMTexture;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_LoadTextureFromModule(Direct3DRM *this, HMODULE hModule, LPCTSTR strName, LPCTSTR strType, Direct3DRMTexture **lplpD3DRMTexture) {
    (void) this;
    (void) hModule;
    (void) strName;
    (void) strType;
    (void) lplpD3DRMTexture;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_SetSearchPath(Direct3DRM *this, LPCSTR lpPath) {
    (void) this;
    (void) lpPath;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_AddSearchPath(Direct3DRM *this, LPCSTR lpPath) {
    if (lpPath == NULL) {
        return E_POINTER;
    }
    common_linked_list_append(&this->search_path, SDL_strdup(lpPath));
    return S_OK;
}

static HRESULT STDCALL SDL_Direct3DRM_GetSearchPath(Direct3DRM *this, DWORD *lpdwSize, LPSTR lpszPath) {
    size_t len = 0;
    if (lpszPath == NULL || (lpdwSize != NULL && lpdwSize == 0)) {
        return E_POINTER;
    }
    for (common_linked_list *l = this->search_path; l != NULL; l = l->next) {
        size_t l_len = SDL_strlen(l->str);
        if (lpdwSize != NULL && *lpdwSize < len + l_len + 1) {
            lpszPath[len] = '\0';
            return E_OUTOFMEMORY;
        }
        SDL_memcpy(&lpszPath[len], l->str, l_len);
        len += l_len;
        if (l->next != NULL) {
            lpszPath[len] = ';';
            len += 1;
        }
    }
    lpszPath[len] = '\0';
    if (lpdwSize != NULL) {
        *lpdwSize = len;
    }
    return S_OK;
}

static HRESULT STDCALL SDL_Direct3DRM_SetDefaultTextureColors(Direct3DRM *this, DWORD dwColors) {
    (void) this;
    (void) dwColors;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_SetDefaultTextureShades(Direct3DRM *this, DWORD dwShades) {
    (void) this;
    (void) dwShades;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_GetDevices(Direct3DRM *this, LPDIRECT3DRMDEVICEARRAY *lplpDevArray) {
    (void) this;
    (void) lplpDevArray;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_GetNamedObject(Direct3DRM *this, const char *lpName, LPDIRECT3DRMOBJECT *lplpD3DRMObject) {
    (void) this;
    (void) lpName;
    (void) lplpD3DRMObject;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_EnumerateObjects(Direct3DRM *this, D3DRMOBJECTCALLBACK func, LPVOID lpArg) {
    (void) this;
    (void) func;
    (void) lpArg;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_Load(Direct3DRM *this, LPVOID lpvObjSource, LPVOID lpvObjID, LPIID *lplpGUIDs, DWORD dwcGUIDs, D3DRMLOADOPTIONS d3drmLOFlags, D3DRMLOADCALLBACK d3drmLoadProc, LPVOID lpArgLP, LoadTextureAdapterCallbackData *loadTextureProc, Direct3DRMFrame *lpParentFrame) {
    (void) this;
    (void) lpvObjSource;
    (void) lpParentFrame;
    (void) lpvObjSource;
    (void) lpvObjID;
    (void) lplpGUIDs;
    (void) dwcGUIDs;
    (void) d3drmLOFlags;
    (void) d3drmLoadProc;
    (void) lpArgLP;
    (void) loadTextureProc;
    (void) lpParentFrame;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_Tick(Direct3DRM *this, D3DVALUE d3dvalTick) {
    (void) this;
    (void) d3dvalTick;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateProgressiveMesh(Direct3DRM *this, LPDIRECT3DRMPROGRESSIVEMESH* lplpD3DRMProgressiveMesh) {
    (void) this;
    (void) lplpD3DRMProgressiveMesh;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_RegisterClient(Direct3DRM *this, REFGUID rguid, LPDWORD lpdwID) {
    (void) this;
    (void) rguid;
    (void) lpdwID;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_UnregisterClient(Direct3DRM *this, REFGUID rguid) {
    (void) this;
    (void) rguid;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_CreateClippedVisual(Direct3DRM *this, LPDIRECT3DRMVISUAL lpVisual, LPDIRECT3DRMCLIPPEDVISUAL *lpClippedVisual) {
    (void) this;
    (void) lpVisual;
    (void) lpClippedVisual;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_SetOptions(Direct3DRM *this, DWORD dwOptions) {
    (void) this;
    (void) dwOptions;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRM_GetOptions(Direct3DRM *this, LPDWORD dwOptions) {
    (void) this;
    (void) dwOptions;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

// IDirect3DRM interface

static HRESULT STDCALL SDL_IDirect3DRM_QueryInterface(IDirect3DRM *this, REFIID riid, void **ppvObject) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_QueryInterface(real_this, riid, ppvObject);
}

static ULONG STDCALL SDL_IDirect3DRM_AddRef(IDirect3DRM *this) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRM_Release(IDirect3DRM *this) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateObject(IDirect3DRM *this, REFCLSID rclsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_CreateObject(real_this, rclsid, pUnkOuter, riid, ppv);
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateFrame(IDirect3DRM *this, LPDIRECT3DRMFRAME lpD3DRMFrame, LPDIRECT3DRMFRAME *lplpD3DRMFrame) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRM_CreateFrame(real_this, from_IDirect3DRMFrame(lpD3DRMFrame), &frame);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMFrame != NULL) {
        *lplpD3DRMFrame = &frame->interface_IDirect3DRMFrame;
    } else {
        COM_DECREF(frame);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateMesh(IDirect3DRM *this, LPDIRECT3DRMMESH *lplpD3DRMMesh) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_CreateMesh(real_this, lplpD3DRMMesh);
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateMeshBuilder(IDirect3DRM *this, LPDIRECT3DRMMESHBUILDER *lplpD3DRMMeshBuilder) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    Direct3DRMMeshBuilder *builder = NULL;
    HRESULT res = SDL_Direct3DRM_CreateMeshBuilder(real_this, &builder);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMMeshBuilder != NULL) {
        *lplpD3DRMMeshBuilder = &builder->interface_IDirect3DRMMeshBuilder;
    } else {
        COM_DECREF(builder);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateFace(IDirect3DRM *this, LPDIRECT3DRMFACE *lplpd3drmFace) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMFace *face = NULL;
    HRESULT res = SDL_Direct3DRM_CreateFace(real_this, &face);
    if (FAILED(res)) {
        return res;
    }
    if (lplpd3drmFace != NULL) {
        *lplpd3drmFace = &face->interface_IDirect3DRMFace;
    } else {
        COM_DECREF(face);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateAnimation(IDirect3DRM *this, LPDIRECT3DRMANIMATION *lplpD3DRMAnimation) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMAnimation *animation = NULL;
    HRESULT res = SDL_Direct3DRM_CreateAnimation(real_this, &animation);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMAnimation != NULL) {
        *lplpD3DRMAnimation = &animation->interface_IDirect3DRMAnimation;
    } else {
        COM_DECREF(animation);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateAnimationSet(IDirect3DRM *this, LPDIRECT3DRMANIMATIONSET *lplpD3DRMAnimationSet) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMAnimationSet *animationset = NULL;
    HRESULT res = SDL_Direct3DRM_CreateAnimationSet(real_this, &animationset);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMAnimationSet != NULL) {
        *lplpD3DRMAnimationSet = &animationset->interface_IDirect3DRMAnimationSet;
    } else {
        COM_DECREF(animationset);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateTexture(IDirect3DRM *this, LPD3DRMIMAGE lpImage, LPDIRECT3DRMTEXTURE *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateTexture(real_this, lpImage, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateLight(IDirect3DRM *this, D3DRMLIGHTTYPE d3drmltLightType, D3DCOLOR cColor, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_CreateLight(real_this, d3drmltLightType, cColor, lplpD3DRMLight);
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateLightRGB(IDirect3DRM *this, D3DRMLIGHTTYPE ltLightType, D3DVALUE vRed, D3DVALUE vGreen, D3DVALUE vBlue, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_CreateLightRGB(real_this, ltLightType, vRed, vGreen, vBlue, lplpD3DRMLight);
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateMaterial(IDirect3DRM *this, D3DVALUE vPower, LPDIRECT3DRMMATERIAL *lplpD3DRMMaterial) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    Direct3DRMMaterial *material = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateMaterial(real_this, vPower, &material);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMMaterial != NULL) {
        *lplpD3DRMMaterial = &material->interface_IDirect3DRMMaterial;
    } else {
        COM_DECREF(material);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateDevice(IDirect3DRM *this, DWORD dwWidth, DWORD dwHeight, LPDIRECT3DRMDEVICE *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateDevice(real_this, dwWidth, dwHeight, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateDeviceFromSurface(IDirect3DRM *this, LPGUID lpGUID, LPDIRECTDRAW lpDD, LPDIRECTDRAWSURFACE lpDDSBack, LPDIRECT3DRMDEVICE *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromSurface(real_this, lpGUID, lpDD, lpDDSBack, 0, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateDeviceFromD3D(IDirect3DRM *this, LPDIRECT3D lpD3D, LPDIRECT3DDEVICE lpD3DDev, LPDIRECT3DRMDEVICE *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromD3D(real_this, lpD3D, lpD3DDev, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateDeviceFromClipper(IDirect3DRM *this, LPDIRECTDRAWCLIPPER lpDDClipper, LPGUID lpGUID, int width, int height, LPDIRECT3DRMDEVICE *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromClipper(real_this, lpDDClipper, lpGUID, width, height, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateTextureFromSurface(IDirect3DRM *this, LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DRMTEXTURE *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_CreateTextureFromSurface(real_this, lpDDS, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateShadow(IDirect3DRM *this, LPDIRECT3DRMVISUAL lpVisual, LPDIRECT3DRMLIGHT lpLight, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMVISUAL *lplpShadow) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_CreateShadow(real_this, lpVisual, lpLight, px, py, pz, nx, ny, nz, lplpShadow);
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateViewport(IDirect3DRM *this, LPDIRECT3DRMDEVICE lpDev, LPDIRECT3DRMFRAME lpCamera, DWORD dwXPos, DWORD dwYPos, DWORD dwWidth, DWORD dwHeight, LPDIRECT3DRMVIEWPORT *lplpD3DRMViewport) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    SDL_Direct3DRMViewport *viewport = NULL;
    HRESULT res = SDL_Direct3DRM_CreateViewport(real_this, from_IDirect3DRMDevice(lpDev), from_IDirect3DRMFrame(lpCamera), dwXPos, dwYPos, dwWidth, dwHeight, &viewport);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMViewport != NULL) {
        *lplpD3DRMViewport = &viewport->interface_IDirect3DRMViewport;
    } else {
        COM_DECREF(viewport);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateWrap(IDirect3DRM *this, D3DRMWRAPTYPE type, LPDIRECT3DRMFRAME lpRef, D3DVALUE ox, D3DVALUE oy, D3DVALUE oz, D3DVALUE dx, D3DVALUE dy, D3DVALUE dz, D3DVALUE ux, D3DVALUE uy, D3DVALUE uz, D3DVALUE ou, D3DVALUE ov, D3DVALUE su, D3DVALUE sv, LPDIRECT3DRMWRAP *lplpD3DRMWrap) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_CreateWrap(real_this, type, from_IDirect3DRMFrame(lpRef), ox, oy, oz, dx, dy, dz, ux, uy, uz, ou, ov, su, sv, lplpD3DRMWrap);
}

static HRESULT STDCALL SDL_IDirect3DRM_CreateUserVisual(IDirect3DRM *this, D3DRMUSERVISUALCALLBACK fn, LPVOID lpArg, LPDIRECT3DRMUSERVISUAL *lplpD3DRMUV) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_CreateUserVisual(real_this, fn, lpArg, lplpD3DRMUV);
}

static HRESULT STDCALL SDL_IDirect3DRM_LoadTexture(IDirect3DRM *this, const char *lpFileName, LPDIRECT3DRMTEXTURE *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_LoadTexture(real_this, lpFileName, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_LoadTextureFromResource(IDirect3DRM *this, HRSRC rs, LPDIRECT3DRMTEXTURE *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_LoadTextureFromResource(real_this, rs, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM_SetSearchPath(IDirect3DRM *this, LPCSTR lpPath) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_SetSearchPath(real_this, lpPath);
}

static HRESULT STDCALL SDL_IDirect3DRM_AddSearchPath(IDirect3DRM *this, LPCSTR lpPath) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_AddSearchPath(real_this, lpPath);
}

static HRESULT STDCALL SDL_IDirect3DRM_GetSearchPath(IDirect3DRM *this, DWORD *lpdwSize, LPSTR lpszPath) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_GetSearchPath(real_this, lpdwSize, lpszPath);
}

static HRESULT STDCALL SDL_IDirect3DRM_SetDefaultTextureColors(IDirect3DRM *this, DWORD dwColors) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_SetDefaultTextureColors(real_this, dwColors);
}

static HRESULT STDCALL SDL_IDirect3DRM_SetDefaultTextureShades(IDirect3DRM *this, DWORD dwShades) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_SetDefaultTextureShades(real_this, dwShades);
}

static HRESULT STDCALL SDL_IDirect3DRM_GetDevices(IDirect3DRM *this, LPDIRECT3DRMDEVICEARRAY *lplpDevArray) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_GetDevices(real_this, lplpDevArray);
}

static HRESULT STDCALL SDL_IDirect3DRM_GetNamedObject(IDirect3DRM *this, const char *lpName, LPDIRECT3DRMOBJECT *lplpD3DRMObject) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_GetNamedObject(real_this, lpName, lplpD3DRMObject);
}

static HRESULT STDCALL SDL_IDirect3DRM_EnumerateObjects(IDirect3DRM *this, D3DRMOBJECTCALLBACK func, LPVOID lpArg) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_EnumerateObjects(real_this, func, lpArg);
}

static HRESULT STDCALL SDL_IDirect3DRM_Load(IDirect3DRM *this, LPVOID lpvObjSource, LPVOID lpvObjID, LPIID *lplpGUIDs, DWORD dwcGUIDs, D3DRMLOADOPTIONS d3drmLOFlags, D3DRMLOADCALLBACK loadProc, LPVOID lpArgLP, D3DRMLOADTEXTURECALLBACK loadTextureProc, LPVOID lpArgLTP, LPDIRECT3DRMFRAME lpParentFrame) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURECALLBACK(&load_texture_callback_storage, loadTextureProc, lpArgLTP);
    return SDL_Direct3DRM_Load(real_this, lpvObjSource, lpvObjID, lplpGUIDs, dwcGUIDs, d3drmLOFlags, loadProc, lpArgLP, &load_texture_callback_storage, from_IDirect3DRMFrame(lpParentFrame));
}

static HRESULT STDCALL SDL_IDirect3DRM_Tick(IDirect3DRM *this, D3DVALUE d3dvalTick) {
    Direct3DRM *real_this = from_IDirect3DRM(this);
    return SDL_Direct3DRM_Tick(real_this, d3dvalTick);
}

static IDirect3DRMVtbl SDL_IDirect3DRM_Vtable = {
    SDL_IDirect3DRM_QueryInterface,
    SDL_IDirect3DRM_AddRef,
    SDL_IDirect3DRM_Release,
    SDL_IDirect3DRM_CreateObject,
    SDL_IDirect3DRM_CreateFrame,
    SDL_IDirect3DRM_CreateMesh,
    SDL_IDirect3DRM_CreateMeshBuilder,
    SDL_IDirect3DRM_CreateFace,
    SDL_IDirect3DRM_CreateAnimation,
    SDL_IDirect3DRM_CreateAnimationSet,
    SDL_IDirect3DRM_CreateTexture,
    SDL_IDirect3DRM_CreateLight,
    SDL_IDirect3DRM_CreateLightRGB,
    SDL_IDirect3DRM_CreateMaterial,
    SDL_IDirect3DRM_CreateDevice,
    SDL_IDirect3DRM_CreateDeviceFromSurface,
    SDL_IDirect3DRM_CreateDeviceFromD3D,
    SDL_IDirect3DRM_CreateDeviceFromClipper,
    SDL_IDirect3DRM_CreateTextureFromSurface,
    SDL_IDirect3DRM_CreateShadow,
    SDL_IDirect3DRM_CreateViewport,
    SDL_IDirect3DRM_CreateWrap,
    SDL_IDirect3DRM_CreateUserVisual,
    SDL_IDirect3DRM_LoadTexture,
    SDL_IDirect3DRM_LoadTextureFromResource,
    SDL_IDirect3DRM_SetSearchPath,
    SDL_IDirect3DRM_AddSearchPath,
    SDL_IDirect3DRM_GetSearchPath,
    SDL_IDirect3DRM_SetDefaultTextureColors,
    SDL_IDirect3DRM_SetDefaultTextureShades,
    SDL_IDirect3DRM_GetDevices,
    SDL_IDirect3DRM_GetNamedObject,
    SDL_IDirect3DRM_EnumerateObjects,
    SDL_IDirect3DRM_Load,
    SDL_IDirect3DRM_Tick,
};

// IDirect3DRM2 interface

static HRESULT STDCALL SDL_IDirect3DRM2_QueryInterface(IDirect3DRM2 *this, REFIID riid, void **ppvObject) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_QueryInterface(real_this, riid, ppvObject);
}

static ULONG STDCALL SDL_IDirect3DRM2_AddRef(IDirect3DRM2 *this) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRM2_Release(IDirect3DRM2 *this) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateObject(IDirect3DRM2 *this, REFCLSID rclsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateObject(real_this, rclsid, pUnkOuter, riid, ppv);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateFrame(IDirect3DRM2 *this, LPDIRECT3DRMFRAME lpD3DRMFrame, LPDIRECT3DRMFRAME2 *lplpD3DRMFrame) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRM_CreateFrame(real_this, from_IDirect3DRMFrame(lpD3DRMFrame), &frame);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMFrame != NULL) {
        *lplpD3DRMFrame = &frame->interface_IDirect3DRMFrame2;
    } else {
        COM_DECREF(frame);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateMesh(IDirect3DRM2 *this, LPDIRECT3DRMMESH *lplpD3DRMMesh) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateMesh(real_this, lplpD3DRMMesh);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateMeshBuilder(IDirect3DRM2 *this, LPDIRECT3DRMMESHBUILDER2 *lplpD3DRMMeshBuilder) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    Direct3DRMMeshBuilder *builder = NULL;
    HRESULT res = SDL_Direct3DRM_CreateMeshBuilder(real_this, &builder);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMMeshBuilder != NULL) {
        *lplpD3DRMMeshBuilder = &builder->interface_IDirect3DRMMeshBuilder2;
    } else {
        COM_DECREF(builder);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateFace(IDirect3DRM2 *this, LPDIRECT3DRMFACE *lplpd3drmFace) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMFace *face = NULL;
    HRESULT res = SDL_Direct3DRM_CreateFace(real_this, &face);
    if (FAILED(res)) {
        return res;
    }
    if (lplpd3drmFace != NULL) {
        *lplpd3drmFace = &face->interface_IDirect3DRMFace;
    } else {
        COM_DECREF(face);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateAnimation(IDirect3DRM2 *this, LPDIRECT3DRMANIMATION *lplpD3DRMAnimation) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMAnimation *animation = NULL;
    HRESULT res = SDL_Direct3DRM_CreateAnimation(real_this, &animation);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMAnimation != NULL) {
        *lplpD3DRMAnimation = &animation->interface_IDirect3DRMAnimation;
    } else {
        COM_DECREF(animation);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateAnimationSet(IDirect3DRM2 *this, LPDIRECT3DRMANIMATIONSET *lplpD3DRMAnimationSet) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMAnimationSet *animationset = NULL;
    HRESULT res = SDL_Direct3DRM_CreateAnimationSet(real_this, &animationset);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMAnimationSet != NULL) {
        *lplpD3DRMAnimationSet = &animationset->interface_IDirect3DRMAnimationSet;
    } else {
        COM_DECREF(animationset);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateTexture(IDirect3DRM2 *this, LPD3DRMIMAGE lpImage, LPDIRECT3DRMTEXTURE2 *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateTexture(real_this, lpImage, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture2;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateLight(IDirect3DRM2 *this, D3DRMLIGHTTYPE d3drmltLightType, D3DCOLOR cColor, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateLight(real_this, d3drmltLightType, cColor, lplpD3DRMLight);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateLightRGB(IDirect3DRM2 *this, D3DRMLIGHTTYPE ltLightType, D3DVALUE vRed, D3DVALUE vGreen, D3DVALUE vBlue, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateLightRGB(real_this, ltLightType, vRed, vGreen, vBlue, lplpD3DRMLight);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateMaterial(IDirect3DRM2 *this, D3DVALUE vPower, LPDIRECT3DRMMATERIAL *lplpD3DRMMaterial) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    Direct3DRMMaterial *material = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateMaterial(real_this, vPower, &material);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMMaterial != NULL) {
        *lplpD3DRMMaterial = &material->interface_IDirect3DRMMaterial;
    } else {
        COM_DECREF(material);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateDevice(IDirect3DRM2 *this, DWORD dwWidth, DWORD dwHeight, LPDIRECT3DRMDEVICE2 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateDevice(real_this, dwWidth, dwHeight, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice2;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateDeviceFromSurface(IDirect3DRM2 *this, LPGUID lpGUID, LPDIRECTDRAW lpDD, LPDIRECTDRAWSURFACE lpDDSBack, LPDIRECT3DRMDEVICE2 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromSurface(real_this, lpGUID, lpDD, lpDDSBack, 0, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice2;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateDeviceFromD3D(IDirect3DRM2 *this, LPDIRECT3D2 lpD3D, LPDIRECT3DDEVICE2 lpD3DDev, LPDIRECT3DRMDEVICE2 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromD3D2(real_this, lpD3D, lpD3DDev, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice2;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateDeviceFromClipper(IDirect3DRM2 *this, LPDIRECTDRAWCLIPPER lpDDClipper, LPGUID lpGUID, int width, int height, LPDIRECT3DRMDEVICE2 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromClipper(real_this, lpDDClipper, lpGUID, width, height, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice2;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateTextureFromSurface(IDirect3DRM2 *this, LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DRMTEXTURE2 *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_CreateTextureFromSurface(real_this, lpDDS, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture2;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateShadow(IDirect3DRM2 *this, LPDIRECT3DRMVISUAL lpVisual, LPDIRECT3DRMLIGHT lpLight, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMVISUAL *lplpShadow) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateShadow(real_this, lpVisual, lpLight, px, py, pz, nx, ny, nz, lplpShadow);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateViewport(IDirect3DRM2 *this, LPDIRECT3DRMDEVICE lpDev, LPDIRECT3DRMFRAME lpCamera, DWORD dwXPos, DWORD dwYPos, DWORD dwWidth, DWORD dwHeight, LPDIRECT3DRMVIEWPORT *lplpD3DRMViewport) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    SDL_Direct3DRMViewport *viewport = NULL;
    HRESULT res = SDL_Direct3DRM_CreateViewport(real_this, from_IDirect3DRMDevice(lpDev), from_IDirect3DRMFrame(lpCamera), dwXPos, dwYPos, dwWidth, dwHeight, &viewport);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMViewport != NULL) {
        *lplpD3DRMViewport = &viewport->interface_IDirect3DRMViewport;
    } else {
        COM_DECREF(viewport);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateWrap(IDirect3DRM2 *this, D3DRMWRAPTYPE type, LPDIRECT3DRMFRAME lpRef, D3DVALUE ox, D3DVALUE oy, D3DVALUE oz, D3DVALUE dx, D3DVALUE dy, D3DVALUE dz, D3DVALUE ux, D3DVALUE uy, D3DVALUE uz, D3DVALUE ou, D3DVALUE ov, D3DVALUE su, D3DVALUE sv, LPDIRECT3DRMWRAP *lplpD3DRMWrap) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateWrap(real_this, type, from_IDirect3DRMFrame(lpRef), ox, oy, oz, dx, dy, dz, ux, uy, uz, ou, ov, su, sv, lplpD3DRMWrap);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateUserVisual(IDirect3DRM2 *this, D3DRMUSERVISUALCALLBACK fn, LPVOID lpArg, LPDIRECT3DRMUSERVISUAL *lplpD3DRMUV) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateUserVisual(real_this, fn, lpArg, lplpD3DRMUV);
}

static HRESULT STDCALL SDL_IDirect3DRM2_LoadTexture(IDirect3DRM2 *this, const char *lpFileName, LPDIRECT3DRMTEXTURE2 *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_LoadTexture(real_this, lpFileName, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture2;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_LoadTextureFromResource(IDirect3DRM2 *this, HMODULE hModule, LPCTSTR strName, LPCTSTR strType, LPDIRECT3DRMTEXTURE2 * lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_LoadTextureFromModule(real_this, hModule, strName, strType, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture2;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM2_SetSearchPath(IDirect3DRM2 *this, LPCSTR lpPath) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_SetSearchPath(real_this, lpPath);
}

static HRESULT STDCALL SDL_IDirect3DRM2_AddSearchPath(IDirect3DRM2 *this, LPCSTR lpPath) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_AddSearchPath(real_this, lpPath);
}

static HRESULT STDCALL SDL_IDirect3DRM2_GetSearchPath(IDirect3DRM2 *this, DWORD *lpdwSize, LPSTR lpszPath) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_GetSearchPath(real_this, lpdwSize, lpszPath);
}

static HRESULT STDCALL SDL_IDirect3DRM2_SetDefaultTextureColors(IDirect3DRM2 *this, DWORD dwColors) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_SetDefaultTextureColors(real_this, dwColors);
}

static HRESULT STDCALL SDL_IDirect3DRM2_SetDefaultTextureShades(IDirect3DRM2 *this, DWORD dwShades) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_SetDefaultTextureShades(real_this, dwShades);
}

static HRESULT STDCALL SDL_IDirect3DRM2_GetDevices(IDirect3DRM2 *this, LPDIRECT3DRMDEVICEARRAY *lplpDevArray) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_GetDevices(real_this, lplpDevArray);
}

static HRESULT STDCALL SDL_IDirect3DRM2_GetNamedObject(IDirect3DRM2 *this, const char *lpName, LPDIRECT3DRMOBJECT *lplpD3DRMObject) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_GetNamedObject(real_this, lpName, lplpD3DRMObject);
}

static HRESULT STDCALL SDL_IDirect3DRM2_EnumerateObjects(IDirect3DRM2 *this, D3DRMOBJECTCALLBACK func, LPVOID lpArg) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_EnumerateObjects(real_this, func, lpArg);
}

static HRESULT STDCALL SDL_IDirect3DRM2_Load(IDirect3DRM2 *this, LPVOID lpvObjSource, LPVOID lpvObjID, LPIID *lplpGUIDs, DWORD dwcGUIDs, D3DRMLOADOPTIONS d3drmLOFlags, D3DRMLOADCALLBACK d3drmLoadProc, LPVOID lpArgLP, D3DRMLOADTEXTURECALLBACK d3drmLoadTextureProc, LPVOID lpArgLTP, LPDIRECT3DRMFRAME lpParentFrame) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURECALLBACK(&load_texture_callback_storage, d3drmLoadTextureProc, lpArgLTP);
    return SDL_Direct3DRM_Load(real_this, lpvObjSource, lpvObjID, lplpGUIDs, dwcGUIDs, d3drmLOFlags, d3drmLoadProc, lpArgLP, &load_texture_callback_storage, from_IDirect3DRMFrame(lpParentFrame));
}

static HRESULT STDCALL SDL_IDirect3DRM2_Tick(IDirect3DRM2 *this, D3DVALUE d3dvalTick) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_Tick(real_this, d3dvalTick);
}

static HRESULT STDCALL SDL_IDirect3DRM2_CreateProgressiveMesh(IDirect3DRM2 *this, LPDIRECT3DRMPROGRESSIVEMESH* lplpD3DRMProgressiveMesh) {
    Direct3DRM *real_this = from_IDirect3DRM2(this);
    return SDL_Direct3DRM_CreateProgressiveMesh(real_this, lplpD3DRMProgressiveMesh);
}

static IDirect3DRM2Vtbl SDL_IDirect3DRM2_Vtable = {
    SDL_IDirect3DRM2_QueryInterface,
    SDL_IDirect3DRM2_AddRef,
    SDL_IDirect3DRM2_Release,
    SDL_IDirect3DRM2_CreateObject,
    SDL_IDirect3DRM2_CreateFrame,
    SDL_IDirect3DRM2_CreateMesh,
    SDL_IDirect3DRM2_CreateMeshBuilder,
    SDL_IDirect3DRM2_CreateFace,
    SDL_IDirect3DRM2_CreateAnimation,
    SDL_IDirect3DRM2_CreateAnimationSet,
    SDL_IDirect3DRM2_CreateTexture,
    SDL_IDirect3DRM2_CreateLight,
    SDL_IDirect3DRM2_CreateLightRGB,
    SDL_IDirect3DRM2_CreateMaterial,
    SDL_IDirect3DRM2_CreateDevice,
    SDL_IDirect3DRM2_CreateDeviceFromSurface,
    SDL_IDirect3DRM2_CreateDeviceFromD3D,
    SDL_IDirect3DRM2_CreateDeviceFromClipper,
    SDL_IDirect3DRM2_CreateTextureFromSurface,
    SDL_IDirect3DRM2_CreateShadow,
    SDL_IDirect3DRM2_CreateViewport,
    SDL_IDirect3DRM2_CreateWrap,
    SDL_IDirect3DRM2_CreateUserVisual,
    SDL_IDirect3DRM2_LoadTexture,
    SDL_IDirect3DRM2_LoadTextureFromResource,
    SDL_IDirect3DRM2_SetSearchPath,
    SDL_IDirect3DRM2_AddSearchPath,
    SDL_IDirect3DRM2_GetSearchPath,
    SDL_IDirect3DRM2_SetDefaultTextureColors,
    SDL_IDirect3DRM2_SetDefaultTextureShades,
    SDL_IDirect3DRM2_GetDevices,
    SDL_IDirect3DRM2_GetNamedObject,
    SDL_IDirect3DRM2_EnumerateObjects,
    SDL_IDirect3DRM2_Load,
    SDL_IDirect3DRM2_Tick,
    SDL_IDirect3DRM2_CreateProgressiveMesh,
};

// IDirect3DRM3 interface

static HRESULT STDCALL SDL_IDirect3DRM3_QueryInterface(IDirect3DRM3 *this, REFIID riid, void **ppvObject) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_QueryInterface(real_this, riid, ppvObject);
}

static ULONG STDCALL SDL_IDirect3DRM3_AddRef(IDirect3DRM3 *this) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRM3_Release(IDirect3DRM3 *this) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateObject(IDirect3DRM3 *this, REFCLSID rclsid, LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateObject(real_this, rclsid, pUnkOuter, riid, ppv);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateFrame(IDirect3DRM3 *this, LPDIRECT3DRMFRAME3 lpD3DRMFrame, LPDIRECT3DRMFRAME3 *lplpD3DRMFrame) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRM_CreateFrame(real_this, from_IDirect3DRMFrame3(lpD3DRMFrame), &frame);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMFrame != NULL) {
        *lplpD3DRMFrame = &frame->interface_IDirect3DRMFrame3;
    } else {
        COM_DECREF(frame);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateMesh(IDirect3DRM3 *this, LPDIRECT3DRMMESH *lplpD3DRMMesh) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateMesh(real_this, lplpD3DRMMesh);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateMeshBuilder(IDirect3DRM3 *this, LPDIRECT3DRMMESHBUILDER3 *lplpD3DRMMeshBuilder) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    Direct3DRMMeshBuilder *builder = NULL;
    HRESULT res = SDL_Direct3DRM_CreateMeshBuilder(real_this, &builder);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMMeshBuilder != NULL) {
        *lplpD3DRMMeshBuilder = &builder->interface_IDirect3DRMMeshBuilder3;
    } else {
        COM_DECREF(builder);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateFace(IDirect3DRM3 *this, LPDIRECT3DRMFACE2 *lplpd3drmFace) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMFace *face = NULL;
    HRESULT res = SDL_Direct3DRM_CreateFace(real_this, &face);
    if (FAILED(res)) {
        return res;
    }
    if (lplpd3drmFace != NULL) {
        *lplpd3drmFace = &face->interface_IDirect3DRMFace2;
    } else {
        COM_DECREF(face);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateAnimation(IDirect3DRM3 *this, LPDIRECT3DRMANIMATION2 *lplpD3DRMAnimation) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMAnimation *animation = NULL;
    HRESULT res = SDL_Direct3DRM_CreateAnimation(real_this, &animation);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMAnimation != NULL) {
        *lplpD3DRMAnimation = &animation->interface_IDirect3DRMAnimation2;
    } else {
        COM_DECREF(animation);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateAnimationSet(IDirect3DRM3 *this, LPDIRECT3DRMANIMATIONSET2 *lplpD3DRMAnimationSet) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMAnimationSet *animationset = NULL;
    HRESULT res = SDL_Direct3DRM_CreateAnimationSet(real_this, &animationset);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMAnimationSet != NULL) {
        *lplpD3DRMAnimationSet = &animationset->interface_IDirect3DRMAnimationSet2;
    } else {
        COM_DECREF(animationset);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateTexture(IDirect3DRM3 *this, LPD3DRMIMAGE lpImage, LPDIRECT3DRMTEXTURE3 *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateTexture(real_this, lpImage, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture3;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateLight(IDirect3DRM3 *this, D3DRMLIGHTTYPE d3drmltLightType, D3DCOLOR cColor, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateLight(real_this, d3drmltLightType, cColor, lplpD3DRMLight);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateLightRGB(IDirect3DRM3 *this, D3DRMLIGHTTYPE ltLightType, D3DVALUE vRed, D3DVALUE vGreen, D3DVALUE vBlue, LPDIRECT3DRMLIGHT *lplpD3DRMLight) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateLightRGB(real_this, ltLightType, vRed, vGreen, vBlue, lplpD3DRMLight);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateMaterial(IDirect3DRM3 *this, D3DVALUE vPower, LPDIRECT3DRMMATERIAL2 *lplpD3DRMMaterial) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    Direct3DRMMaterial *material = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateMaterial(real_this, vPower, &material);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMMaterial != NULL) {
        *lplpD3DRMMaterial = &material->interface_IDirect3DRMMaterial2;
    } else {
        COM_DECREF(material);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateDevice(IDirect3DRM3 *this, DWORD dwWidth, DWORD dwHeight, LPDIRECT3DRMDEVICE3 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res =  SDL_Direct3DRM_CreateDevice(real_this, dwWidth, dwHeight, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice3;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateDeviceFromSurface(IDirect3DRM3 *this, LPGUID lpGUID, LPDIRECTDRAW lpDD, LPDIRECTDRAWSURFACE lpDDSBack, DWORD dwFlags, LPDIRECT3DRMDEVICE3 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromSurface(real_this, lpGUID, lpDD, lpDDSBack, dwFlags, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice3;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateDeviceFromD3D(IDirect3DRM3 *this, LPDIRECT3D2 lpD3D, LPDIRECT3DDEVICE2 lpD3DDev, LPDIRECT3DRMDEVICE3 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromD3D2(real_this, lpD3D, lpD3DDev, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice3;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateDeviceFromClipper(IDirect3DRM3 *this, LPDIRECTDRAWCLIPPER lpDDClipper, LPGUID lpGUID, int width, int height, LPDIRECT3DRMDEVICE3 *lplpD3DRMDevice) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMDevice *device = NULL;
    HRESULT res = SDL_Direct3DRM_CreateDeviceFromClipper(real_this, lpDDClipper, lpGUID, width, height, &device);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMDevice != NULL) {
        *lplpD3DRMDevice = &device->interface_IDirect3DRMDevice3;
    } else {
        COM_DECREF(device);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateTextureFromSurface(IDirect3DRM3 *this, LPDIRECTDRAWSURFACE lpDDS, LPDIRECT3DRMTEXTURE3 *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_CreateTextureFromSurface(real_this, lpDDS, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture3;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateShadow(IDirect3DRM3 *this, LPUNKNOWN pUnk, LPDIRECT3DRMLIGHT lpLight, D3DVALUE px, D3DVALUE py, D3DVALUE pz, D3DVALUE nx, D3DVALUE ny, D3DVALUE nz, LPDIRECT3DRMSHADOW2 * lplpShadow) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateShadow2(real_this, pUnk, lpLight, px, py, pz, nx, ny, nz, lplpShadow);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateViewport(IDirect3DRM3 *this, LPDIRECT3DRMDEVICE3 lpDev, LPDIRECT3DRMFRAME3 lpCamera, DWORD dwXPos, DWORD dwYPos, DWORD dwWidth, DWORD dwHeight, LPDIRECT3DRMVIEWPORT2 *lplpD3DRMViewport) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    SDL_Direct3DRMViewport *viewport = NULL;
    HRESULT res = SDL_Direct3DRM_CreateViewport(real_this, from_IDirect3DRMDevice3(lpDev), from_IDirect3DRMFrame3(lpCamera), dwXPos, dwYPos, dwWidth, dwHeight, &viewport);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMViewport != NULL) {
        *lplpD3DRMViewport = &viewport->interface_IDirect3DRMViewport2;
    } else {
        COM_DECREF(viewport);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateWrap(IDirect3DRM3 *this, D3DRMWRAPTYPE type, LPDIRECT3DRMFRAME3 lpRef, D3DVALUE ox, D3DVALUE oy, D3DVALUE oz, D3DVALUE dx, D3DVALUE dy, D3DVALUE dz, D3DVALUE ux, D3DVALUE uy, D3DVALUE uz, D3DVALUE ou, D3DVALUE ov, D3DVALUE su, D3DVALUE sv, LPDIRECT3DRMWRAP *lplpD3DRMWrap) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateWrap(real_this, type, from_IDirect3DRMFrame3(lpRef), ox, oy, oz, dx, dy, dz, ux, uy, uz, ou, ov, su, sv, lplpD3DRMWrap);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateUserVisual(IDirect3DRM3 *this, D3DRMUSERVISUALCALLBACK fn, LPVOID lpArg, LPDIRECT3DRMUSERVISUAL *lplpD3DRMUV) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateUserVisual(real_this, fn, lpArg, lplpD3DRMUV);
}

static HRESULT STDCALL SDL_IDirect3DRM3_LoadTexture(IDirect3DRM3 *this, const char *lpFileName, LPDIRECT3DRMTEXTURE3 *lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_LoadTexture(real_this, lpFileName, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture3;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_LoadTextureFromResource(IDirect3DRM3 *this, HMODULE hModule, LPCTSTR strName, LPCTSTR strType, LPDIRECT3DRMTEXTURE3 * lplpD3DRMTexture) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRM_LoadTextureFromModule(real_this, hModule, strName, strType, &texture);
    if (FAILED(res)) {
        return res;
    }
    if (lplpD3DRMTexture != NULL) {
        *lplpD3DRMTexture = &texture->interface_IDirect3DRMTexture3;
    } else {
        COM_DECREF(texture);
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRM3_SetSearchPath(IDirect3DRM3 *this, LPCSTR lpPath) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_SetSearchPath(real_this, lpPath);
}

static HRESULT STDCALL SDL_IDirect3DRM3_AddSearchPath(IDirect3DRM3 *this, LPCSTR lpPath) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_AddSearchPath(real_this, lpPath);
}

static HRESULT STDCALL SDL_IDirect3DRM3_GetSearchPath(IDirect3DRM3 *this, DWORD *lpdwSize, LPSTR lpszPath) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_GetSearchPath(real_this, lpdwSize, lpszPath);
}

static HRESULT STDCALL SDL_IDirect3DRM3_SetDefaultTextureColors(IDirect3DRM3 *this, DWORD dwColors) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_SetDefaultTextureColors(real_this, dwColors);
}

static HRESULT STDCALL SDL_IDirect3DRM3_SetDefaultTextureShades(IDirect3DRM3 *this, DWORD dwShades) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_SetDefaultTextureShades(real_this, dwShades);
}

static HRESULT STDCALL SDL_IDirect3DRM3_GetDevices(IDirect3DRM3 *this, LPDIRECT3DRMDEVICEARRAY *lplpDevArray) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_GetDevices(real_this, lplpDevArray);
}

static HRESULT STDCALL SDL_IDirect3DRM3_GetNamedObject(IDirect3DRM3 *this, const char *lpName, LPDIRECT3DRMOBJECT *lplpD3DRMObject) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_GetNamedObject(real_this, lpName, lplpD3DRMObject);
}

static HRESULT STDCALL SDL_IDirect3DRM3_EnumerateObjects(IDirect3DRM3 *this, D3DRMOBJECTCALLBACK func, LPVOID lpArg) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_EnumerateObjects(real_this, func, lpArg);
}

static HRESULT STDCALL SDL_IDirect3DRM3_Load(IDirect3DRM3 *this, LPVOID lpvObjSource, LPVOID lpvObjID, LPIID *lplpGUIDs, DWORD dwcGUIDs, D3DRMLOADOPTIONS d3drmLOFlags, D3DRMLOADCALLBACK d3drmLoadProc, LPVOID lpArgLP, D3DRMLOADTEXTURE3CALLBACK d3drmLoadTextureProc, LPVOID lpArgLTP, LPDIRECT3DRMFRAME3 lpParentFrame) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURE3CALLBACK(&load_texture_callback_storage, d3drmLoadTextureProc, lpArgLTP);
    return SDL_Direct3DRM_Load(real_this, lpvObjSource, lpvObjID, lplpGUIDs, dwcGUIDs, d3drmLOFlags, d3drmLoadProc, lpArgLP, &load_texture_callback_storage, from_IDirect3DRMFrame3(lpParentFrame));
}

static HRESULT STDCALL SDL_IDirect3DRM3_Tick(IDirect3DRM3 *this, D3DVALUE d3dvalTick) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_Tick(real_this, d3dvalTick);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateProgressiveMesh(IDirect3DRM3 *this, LPDIRECT3DRMPROGRESSIVEMESH* lplpD3DRMProgressiveMesh) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateProgressiveMesh(real_this, lplpD3DRMProgressiveMesh);
}

static HRESULT STDCALL SDL_IDirect3DRM3_RegisterClient(IDirect3DRM3 *this, REFGUID rguid, LPDWORD lpdwID) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_RegisterClient(real_this, rguid, lpdwID);
}

static HRESULT STDCALL SDL_IDirect3DRM3_UnregisterClient(IDirect3DRM3 *this, REFGUID rguid) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_UnregisterClient(real_this, rguid);
}

static HRESULT STDCALL SDL_IDirect3DRM3_CreateClippedVisual(IDirect3DRM3 *this, LPDIRECT3DRMVISUAL lpVisual, LPDIRECT3DRMCLIPPEDVISUAL *lpClippedVisual) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_CreateClippedVisual(real_this, lpVisual, lpClippedVisual);
}

static HRESULT STDCALL SDL_IDirect3DRM3_SetOptions(IDirect3DRM3 *this, DWORD dwOptions) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_SetOptions(real_this, dwOptions);
}

static HRESULT STDCALL SDL_IDirect3DRM3_GetOptions(IDirect3DRM3 *this, LPDWORD dwOptions) {
    Direct3DRM *real_this = from_IDirect3DRM3(this);
    return SDL_Direct3DRM_GetOptions(real_this, dwOptions);
}

static IDirect3DRM3Vtbl SDL_IDirect3DRM3_Vtable = {
    SDL_IDirect3DRM3_QueryInterface,
    SDL_IDirect3DRM3_AddRef,
    SDL_IDirect3DRM3_Release,
    SDL_IDirect3DRM3_CreateObject,
    SDL_IDirect3DRM3_CreateFrame,
    SDL_IDirect3DRM3_CreateMesh,
    SDL_IDirect3DRM3_CreateMeshBuilder,
    SDL_IDirect3DRM3_CreateFace,
    SDL_IDirect3DRM3_CreateAnimation,
    SDL_IDirect3DRM3_CreateAnimationSet,
    SDL_IDirect3DRM3_CreateTexture,
    SDL_IDirect3DRM3_CreateLight,
    SDL_IDirect3DRM3_CreateLightRGB,
    SDL_IDirect3DRM3_CreateMaterial,
    SDL_IDirect3DRM3_CreateDevice,
    SDL_IDirect3DRM3_CreateDeviceFromSurface,
    SDL_IDirect3DRM3_CreateDeviceFromD3D,
    SDL_IDirect3DRM3_CreateDeviceFromClipper,
    SDL_IDirect3DRM3_CreateTextureFromSurface,
    SDL_IDirect3DRM3_CreateShadow,
    SDL_IDirect3DRM3_CreateViewport,
    SDL_IDirect3DRM3_CreateWrap,
    SDL_IDirect3DRM3_CreateUserVisual,
    SDL_IDirect3DRM3_LoadTexture,
    SDL_IDirect3DRM3_LoadTextureFromResource,
    SDL_IDirect3DRM3_SetSearchPath,
    SDL_IDirect3DRM3_AddSearchPath,
    SDL_IDirect3DRM3_GetSearchPath,
    SDL_IDirect3DRM3_SetDefaultTextureColors,
    SDL_IDirect3DRM3_SetDefaultTextureShades,
    SDL_IDirect3DRM3_GetDevices,
    SDL_IDirect3DRM3_GetNamedObject,
    SDL_IDirect3DRM3_EnumerateObjects,
    SDL_IDirect3DRM3_Load,
    SDL_IDirect3DRM3_Tick,
    SDL_IDirect3DRM3_CreateProgressiveMesh,
    SDL_IDirect3DRM3_RegisterClient,
    SDL_IDirect3DRM3_UnregisterClient,
    SDL_IDirect3DRM3_CreateClippedVisual,
    SDL_IDirect3DRM3_SetOptions,
    SDL_IDirect3DRM3_GetOptions,
};

STDAPI Direct3DRMCreate(LPDIRECT3DRM FAR *lplpDirect3DRM) {
    Direct3DRM *d3drm;
    if (lplpDirect3DRM == NULL) {
        return E_POINTER;
    }
    d3drm = (Direct3DRM *) SDL_calloc(1, sizeof(Direct3DRM));
    if (d3drm == NULL) {
        return E_POINTER;
    }
    d3drm->interface_IDirect3DRM.lpVtbl = &SDL_IDirect3DRM_Vtable;
    d3drm->interface_IDirect3DRM2.lpVtbl = &SDL_IDirect3DRM2_Vtable;
    d3drm->interface_IDirect3DRM3.lpVtbl = &SDL_IDirect3DRM3_Vtable;
    d3drm->ref_count.value = 1;
    *lplpDirect3DRM = &d3drm->interface_IDirect3DRM;
    return S_OK;
}
