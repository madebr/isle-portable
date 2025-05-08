#include "idirect3drmframe.h"
#include "idirect3drmlight.h"
#include "idirect3drmmaterial.h"
#include "idirect3drmvisualarray.h"
#include "common/common_logging.h"

#include "adapters.h"

#include <d3drmobj.h>
#include <winglue.h>


static HRESULT STDCALL SDL_Direct3DRMFrame_QueryInterface(Direct3DRMFrame *this, REFIID a, void **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static ULONG STDCALL SDL_Direct3DRMFrame_AddRef(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static ULONG STDCALL SDL_Direct3DRMFrame_Release(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_Clone(Direct3DRMFrame *this, IUnknown *a, REFIID b, void **c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddDestroyCallback(Direct3DRMFrame *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_DeleteDestroyCallback(Direct3DRMFrame *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetAppData(Direct3DRMFrame *this, LPVOID a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static LPVOID STDCALL SDL_Direct3DRMFrame_GetAppData(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetName(Direct3DRMFrame *this, const char *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetName(Direct3DRMFrame *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetClassName(Direct3DRMFrame *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddChild(Direct3DRMFrame *this, Direct3DRMFrame *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddLight(Direct3DRMFrame *this, IDirect3DRMLight *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddMoveCallback(Direct3DRMFrame *this, SDL_FrameMoveAdapterCallback *a, DWORD b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddTransform(Direct3DRMFrame *this, D3DRMCOMBINETYPE a, D3DRMMATRIX4D b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddTranslation(Direct3DRMFrame *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddScale(Direct3DRMFrame *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddRotation(Direct3DRMFrame *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    (void) e;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_AddVisual(Direct3DRMFrame *this, IDirect3DRMVisual *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetChildren(Direct3DRMFrame *this, IDirect3DRMFrameArray **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DCOLOR STDCALL SDL_Direct3DRMFrame_GetColor(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetLights(Direct3DRMFrame *this, IDirect3DRMLightArray **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DRMMATERIALMODE STDCALL SDL_Direct3DRMFrame_GetMaterialMode(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return D3DRMMATERIAL_FROMPARENT;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetParent(Direct3DRMFrame *this, Direct3DRMFrame **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetPosition(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVECTOR *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetRotation(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVECTOR *b, D3DVALUE *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetScene(Direct3DRMFrame *this, Direct3DRMFrame **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DRMSORTMODE STDCALL SDL_Direct3DRMFrame_GetSortMode(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return D3DRMSORT_FROMPARENT;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetTexture(Direct3DRMFrame *this, Direct3DRMTexture **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetTransform(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DRMMATRIX4D b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetVelocity(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVECTOR *b, BOOL c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetOrientation(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVECTOR *b, D3DVECTOR *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetVisuals(Direct3DRMFrame *this, DWORD *a, IUnknown **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetVisualArray(Direct3DRMFrame *this, SDL_Direct3DRMVisualArray **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetTextureTopology(Direct3DRMFrame *this, BOOL *a, BOOL *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_InverseTransform(Direct3DRMFrame *this, D3DVECTOR *a, D3DVECTOR *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_Load(Direct3DRMFrame *this, void *a, void *b, D3DRMLOADOPTIONS c, LoadTextureAdapterCallbackData *d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_LookAt(Direct3DRMFrame *this, Direct3DRMFrame *a, Direct3DRMFrame *b, D3DRMFRAMECONSTRAINT c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_Move(Direct3DRMFrame *this, D3DVALUE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_DeleteChild(Direct3DRMFrame *this, Direct3DRMFrame *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_DeleteLight(Direct3DRMFrame *this, SDL_Direct3DRMLight *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_DeleteMoveCallback(Direct3DRMFrame *this, SDL_FrameMoveAdapterCallback *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_DeleteVisual(Direct3DRMFrame *this, IUnknown *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DCOLOR STDCALL SDL_Direct3DRMFrame_GetSceneBackground(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetSceneBackgroundDepth(Direct3DRMFrame *this, IDirectDrawSurface **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DCOLOR STDCALL SDL_Direct3DRMFrame_GetSceneFogColor(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static BOOL STDCALL SDL_Direct3DRMFrame_GetSceneFogEnable(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DRMFOGMODE STDCALL SDL_Direct3DRMFrame_GetSceneFogMode(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return D3DRMFOG_LINEAR;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetSceneFogParams(Direct3DRMFrame *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneBackground(Direct3DRMFrame *this, D3DCOLOR a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneBackgroundRGB(Direct3DRMFrame *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneBackgroundDepth(Direct3DRMFrame *this, IDirectDrawSurface *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneBackgroundImage(Direct3DRMFrame *this, Direct3DRMTexture *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneFogEnable(Direct3DRMFrame *this, BOOL a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneFogColor(Direct3DRMFrame *this, D3DCOLOR a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneFogMode(Direct3DRMFrame *this, D3DRMFOGMODE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneFogParams(Direct3DRMFrame *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetColor(Direct3DRMFrame *this, D3DCOLOR a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetColorRGB(Direct3DRMFrame *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DRMZBUFFERMODE STDCALL SDL_Direct3DRMFrame_GetZbufferMode(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return D3DRMZBUFFER_FROMPARENT;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetMaterialMode(Direct3DRMFrame *this, D3DRMMATERIALMODE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetOrientation(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e, D3DVALUE f, D3DVALUE g) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    (void) e;
    (void) f;
    (void) g;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetPosition(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetRotation(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    (void) e;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSortMode(Direct3DRMFrame *this, D3DRMSORTMODE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetTexture(Direct3DRMFrame *this, Direct3DRMTexture *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetTextureTopology(Direct3DRMFrame *this, BOOL bWrap_u, BOOL bWrap_v) {
    (void) this;
    (void) bWrap_u;
    (void) bWrap_v;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetVelocity(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, BOOL e) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    (void) e;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetZbufferMode(Direct3DRMFrame *this, D3DRMZBUFFERMODE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_Transform(Direct3DRMFrame *this, D3DVECTOR *a, D3DVECTOR *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetBox(Direct3DRMFrame *this, D3DRMBOX *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static BOOL STDCALL SDL_Direct3DRMFrame_GetBoxEnable(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetAxes(Direct3DRMFrame *this, D3DVECTOR *a, D3DVECTOR *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetMaterial(Direct3DRMFrame *this, Direct3DRMMaterial **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static BOOL STDCALL SDL_Direct3DRMFrame_GetInheritAxes(Direct3DRMFrame *this ) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetHierarchyBox(Direct3DRMFrame *this, D3DRMBOX *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetBox(Direct3DRMFrame *this, D3DRMBOX *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetBoxEnable(Direct3DRMFrame *this, BOOL a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetAxes(Direct3DRMFrame *this, D3DVALUE a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e, D3DVALUE f) {
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

static HRESULT STDCALL SDL_Direct3DRMFrame_SetInheritAxes(Direct3DRMFrame *this, BOOL a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetMaterial(Direct3DRMFrame *this, Direct3DRMMaterial *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetQuaternion(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DRMQUATERNION *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_RayPick(Direct3DRMFrame *this, Direct3DRMFrame *a, D3DRMRAY *b, DWORD c, IDirect3DRMPicked2Array **d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_Save(Direct3DRMFrame *this, const char *a, D3DRMXOFFORMAT b, D3DRMSAVEOPTIONS c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_TransformVectors(Direct3DRMFrame *this, Direct3DRMFrame *a, DWORD b, D3DVECTOR *c, D3DVECTOR *d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_InverseTransformVectors(Direct3DRMFrame *this, Direct3DRMFrame *a, DWORD b, D3DVECTOR *c, D3DVECTOR *d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetTraversalOptions(Direct3DRMFrame *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetTraversalOptions(Direct3DRMFrame *this, DWORD *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetSceneFogMethod(Direct3DRMFrame *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetSceneFogMethod(Direct3DRMFrame *this, DWORD *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_SetMaterialOverride(Direct3DRMFrame *this, D3DRMMATERIALOVERRIDE *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMFrame_GetMaterialOverride(Direct3DRMFrame *this, D3DRMMATERIALOVERRIDE *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}


// IDirect3DRMFrame interface

static HRESULT STDCALL SDL_IDirect3DRMFrame_QueryInterface(IDirect3DRMFrame *this, REFIID a, void **b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMFrame_AddRef(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMFrame_Release(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_Clone(IDirect3DRMFrame *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddDestroyCallback(IDirect3DRMFrame *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_DeleteDestroyCallback(IDirect3DRMFrame *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetAppData(IDirect3DRMFrame *this, LPVOID a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMFrame_GetAppData(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetName(IDirect3DRMFrame *this, const char *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetName(IDirect3DRMFrame *this, DWORD *a, char *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetClassName(IDirect3DRMFrame *this, DWORD *a, char *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddChild(IDirect3DRMFrame *this, IDirect3DRMFrame *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddChild(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddLight(IDirect3DRMFrame *this, IDirect3DRMLight *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddLight(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddMoveCallback(IDirect3DRMFrame *this, D3DRMFRAMEMOVECALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    SDL_FrameMoveAdapterCallback frame_move_callback_storage;
    adapt_D3DRMFRAMEMOVECALLBACK(&frame_move_callback_storage, a, b);
    return SDL_Direct3DRMFrame_AddMoveCallback(real_this, &frame_move_callback_storage, D3DRMCALLBACK_PREORDER);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddTransform(IDirect3DRMFrame *this, D3DRMCOMBINETYPE a, D3DRMMATRIX4D b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddTranslation(IDirect3DRMFrame *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddTranslation(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddScale(IDirect3DRMFrame *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddScale(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddRotation(IDirect3DRMFrame *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddRotation(real_this, a, b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_AddVisual(IDirect3DRMFrame *this, IDirect3DRMVisual *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_AddVisual(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetChildren(IDirect3DRMFrame *this, IDirect3DRMFrameArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetChildren(real_this, a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame_GetColor(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetColor(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetLights(IDirect3DRMFrame *this, IDirect3DRMLightArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetLights(real_this, a);
}

static D3DRMMATERIALMODE STDCALL SDL_IDirect3DRMFrame_GetMaterialMode(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetMaterialMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetParent(IDirect3DRMFrame *this, IDirect3DRMFrame **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetParent(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetPosition(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetPosition(real_this, from_IDirect3DRMFrame(a), b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetRotation(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVECTOR *b, D3DVALUE *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetRotation(real_this, from_IDirect3DRMFrame(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetScene(IDirect3DRMFrame *this, IDirect3DRMFrame **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    Direct3DRMFrame *frame;
    HRESULT res = SDL_Direct3DRMFrame_GetScene(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame;
    }
    return res;
}

static D3DRMSORTMODE STDCALL SDL_IDirect3DRMFrame_GetSortMode(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetSortMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetTexture(IDirect3DRMFrame *this, IDirect3DRMTexture **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetTexture(real_this, &texture);
    if (a) {
        *a = &texture->interface_IDirect3DRMTexture;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetTransform(IDirect3DRMFrame *this, D3DRMMATRIX4D a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetTransform(real_this, NULL, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetVelocity(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVECTOR *b, BOOL c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetVelocity(real_this, from_IDirect3DRMFrame(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetOrientation(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVECTOR *b, D3DVECTOR *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetOrientation(real_this, from_IDirect3DRMFrame(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetVisuals(IDirect3DRMFrame *this, IDirect3DRMVisualArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    SDL_Direct3DRMVisualArray *visual_array = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetVisualArray(real_this, &visual_array);
    if (a) {
        *a = &visual_array->interface_IDirect3DRMVisualArray;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetTextureTopology(IDirect3DRMFrame *this, BOOL *a, BOOL *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetTextureTopology(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_InverseTransform(IDirect3DRMFrame *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_InverseTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_Load(IDirect3DRMFrame *this, void *a, void *b, D3DRMLOADOPTIONS c, D3DRMLOADTEXTURECALLBACK loadTextureProc, void *lpArgLTP) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURECALLBACK(&load_texture_callback_storage, loadTextureProc, lpArgLTP);
    return SDL_Direct3DRMFrame_Load(real_this, a, b, c, &load_texture_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_LookAt(IDirect3DRMFrame *this, IDirect3DRMFrame *a, IDirect3DRMFrame *b, D3DRMFRAMECONSTRAINT c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_LookAt(real_this, from_IDirect3DRMFrame(a), from_IDirect3DRMFrame(b), c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_Move(IDirect3DRMFrame *this, D3DVALUE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_Move(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_DeleteChild(IDirect3DRMFrame *this, IDirect3DRMFrame *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_DeleteChild(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_DeleteLight(IDirect3DRMFrame *this, IDirect3DRMLight *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_DeleteLight(real_this, from_IDirect3DRMLight(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_DeleteMoveCallback(IDirect3DRMFrame *this, D3DRMFRAMEMOVECALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    SDL_FrameMoveAdapterCallback frame_move_callback_storage;
    adapt_D3DRMFRAMEMOVECALLBACK(&frame_move_callback_storage, a, b);
    return SDL_Direct3DRMFrame_DeleteMoveCallback(real_this, &frame_move_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_DeleteVisual(IDirect3DRMFrame *this, IDirect3DRMVisual *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_DeleteVisual(real_this, (IUnknown *) a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame_GetSceneBackground(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetSceneBackground(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetSceneBackgroundDepth(IDirect3DRMFrame *this, IDirectDrawSurface **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetSceneBackgroundDepth(real_this, a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame_GetSceneFogColor(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetSceneFogColor(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMFrame_GetSceneFogEnable(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetSceneFogEnable(real_this);
}

static D3DRMFOGMODE STDCALL SDL_IDirect3DRMFrame_GetSceneFogMode(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetSceneFogMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_GetSceneFogParams(IDirect3DRMFrame *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetSceneFogParams(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneBackground(IDirect3DRMFrame *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneBackground(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneBackgroundRGB(IDirect3DRMFrame *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundRGB(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneBackgroundDepth(IDirect3DRMFrame *this, IDirectDrawSurface *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundDepth(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneBackgroundImage(IDirect3DRMFrame *this, IDirect3DRMTexture *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundImage(real_this, from_IDirect3DRMTexture(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneFogEnable(IDirect3DRMFrame *this, BOOL a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneFogEnable(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneFogColor(IDirect3DRMFrame *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneFogColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneFogMode(IDirect3DRMFrame *this, D3DRMFOGMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneFogMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSceneFogParams(IDirect3DRMFrame *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSceneFogParams(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetColor(IDirect3DRMFrame *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetColorRGB(IDirect3DRMFrame *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetColorRGB(real_this, a, b, c);
}

static D3DRMZBUFFERMODE STDCALL SDL_IDirect3DRMFrame_GetZbufferMode(IDirect3DRMFrame *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_GetZbufferMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetMaterialMode(IDirect3DRMFrame *this, D3DRMMATERIALMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetMaterialMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetOrientation(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e, D3DVALUE f, D3DVALUE g) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetOrientation(real_this, from_IDirect3DRMFrame(a), b, c, d, e, f, g);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetPosition(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetPosition(real_this, from_IDirect3DRMFrame(a), b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetRotation(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetRotation(real_this, from_IDirect3DRMFrame(a), b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetSortMode(IDirect3DRMFrame *this, D3DRMSORTMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetSortMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetTexture(IDirect3DRMFrame *this, IDirect3DRMTexture *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetTexture(real_this, from_IDirect3DRMTexture(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetTextureTopology(IDirect3DRMFrame *this, BOOL bWrap_u, BOOL bWrap_v) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetTextureTopology(real_this, bWrap_u, bWrap_v);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetVelocity(IDirect3DRMFrame *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, BOOL e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetVelocity(real_this, from_IDirect3DRMFrame(a), b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_SetZbufferMode(IDirect3DRMFrame *this, D3DRMZBUFFERMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_SetZbufferMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame_Transform(IDirect3DRMFrame *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame(this);
    return SDL_Direct3DRMFrame_Transform(real_this, a, b);
}


static IDirect3DRMFrameVtbl SDL_IDirect3DRMFrame_Vtable = {
    SDL_IDirect3DRMFrame_QueryInterface,
    SDL_IDirect3DRMFrame_AddRef,
    SDL_IDirect3DRMFrame_Release,
    SDL_IDirect3DRMFrame_Clone,
    SDL_IDirect3DRMFrame_AddDestroyCallback,
    SDL_IDirect3DRMFrame_DeleteDestroyCallback,
    SDL_IDirect3DRMFrame_SetAppData,
    SDL_IDirect3DRMFrame_GetAppData,
    SDL_IDirect3DRMFrame_SetName,
    SDL_IDirect3DRMFrame_GetName,
    SDL_IDirect3DRMFrame_GetClassName,
    SDL_IDirect3DRMFrame_AddChild,
    SDL_IDirect3DRMFrame_AddLight,
    SDL_IDirect3DRMFrame_AddMoveCallback,
    SDL_IDirect3DRMFrame_AddTransform,
    SDL_IDirect3DRMFrame_AddTranslation,
    SDL_IDirect3DRMFrame_AddScale,
    SDL_IDirect3DRMFrame_AddRotation,
    SDL_IDirect3DRMFrame_AddVisual,
    SDL_IDirect3DRMFrame_GetChildren,
    SDL_IDirect3DRMFrame_GetColor,
    SDL_IDirect3DRMFrame_GetLights,
    SDL_IDirect3DRMFrame_GetMaterialMode,
    SDL_IDirect3DRMFrame_GetParent,
    SDL_IDirect3DRMFrame_GetPosition,
    SDL_IDirect3DRMFrame_GetRotation,
    SDL_IDirect3DRMFrame_GetScene,
    SDL_IDirect3DRMFrame_GetSortMode,
    SDL_IDirect3DRMFrame_GetTexture,
    SDL_IDirect3DRMFrame_GetTransform,
    SDL_IDirect3DRMFrame_GetVelocity,
    SDL_IDirect3DRMFrame_GetOrientation,
    SDL_IDirect3DRMFrame_GetVisuals,
    SDL_IDirect3DRMFrame_GetTextureTopology,
    SDL_IDirect3DRMFrame_InverseTransform,
    SDL_IDirect3DRMFrame_Load,
    SDL_IDirect3DRMFrame_LookAt,
    SDL_IDirect3DRMFrame_Move,
    SDL_IDirect3DRMFrame_DeleteChild,
    SDL_IDirect3DRMFrame_DeleteLight,
    SDL_IDirect3DRMFrame_DeleteMoveCallback,
    SDL_IDirect3DRMFrame_DeleteVisual,
    SDL_IDirect3DRMFrame_GetSceneBackground,
    SDL_IDirect3DRMFrame_GetSceneBackgroundDepth,
    SDL_IDirect3DRMFrame_GetSceneFogColor,
    SDL_IDirect3DRMFrame_GetSceneFogEnable,
    SDL_IDirect3DRMFrame_GetSceneFogMode,
    SDL_IDirect3DRMFrame_GetSceneFogParams,
    SDL_IDirect3DRMFrame_SetSceneBackground,
    SDL_IDirect3DRMFrame_SetSceneBackgroundRGB,
    SDL_IDirect3DRMFrame_SetSceneBackgroundDepth,
    SDL_IDirect3DRMFrame_SetSceneBackgroundImage,
    SDL_IDirect3DRMFrame_SetSceneFogEnable,
    SDL_IDirect3DRMFrame_SetSceneFogColor,
    SDL_IDirect3DRMFrame_SetSceneFogMode,
    SDL_IDirect3DRMFrame_SetSceneFogParams,
    SDL_IDirect3DRMFrame_SetColor,
    SDL_IDirect3DRMFrame_SetColorRGB,
    SDL_IDirect3DRMFrame_GetZbufferMode,
    SDL_IDirect3DRMFrame_SetMaterialMode,
    SDL_IDirect3DRMFrame_SetOrientation,
    SDL_IDirect3DRMFrame_SetPosition,
    SDL_IDirect3DRMFrame_SetRotation,
    SDL_IDirect3DRMFrame_SetSortMode,
    SDL_IDirect3DRMFrame_SetTexture,
    SDL_IDirect3DRMFrame_SetTextureTopology,
    SDL_IDirect3DRMFrame_SetVelocity,
    SDL_IDirect3DRMFrame_SetZbufferMode,
    SDL_IDirect3DRMFrame_Transform,
};

// IDirect3DRMFrame2 interface

static HRESULT STDCALL SDL_IDirect3DRMFrame2_QueryInterface(IDirect3DRMFrame2 *this, REFIID a, void **b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMFrame2_AddRef(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMFrame2_Release(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_Clone(IDirect3DRMFrame2 *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddDestroyCallback(IDirect3DRMFrame2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_DeleteDestroyCallback(IDirect3DRMFrame2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetAppData(IDirect3DRMFrame2 *this, LPVOID a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMFrame2_GetAppData(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetName(IDirect3DRMFrame2 *this, const char *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetName(IDirect3DRMFrame2 *this, DWORD *a, char *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetClassName(IDirect3DRMFrame2 *this, DWORD *a, char *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddChild(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddChild(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddLight(IDirect3DRMFrame2 *this, IDirect3DRMLight *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddLight(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddMoveCallback(IDirect3DRMFrame2 *this, D3DRMFRAMEMOVECALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    SDL_FrameMoveAdapterCallback frame_move_callback_storage;
    adapt_D3DRMFRAMEMOVECALLBACK(&frame_move_callback_storage, a, b);
    return SDL_Direct3DRMFrame_AddMoveCallback(real_this, &frame_move_callback_storage, D3DRMCALLBACK_PREORDER);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddTransform(IDirect3DRMFrame2 *this, D3DRMCOMBINETYPE a, D3DRMMATRIX4D b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddTranslation(IDirect3DRMFrame2 *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddTranslation(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddScale(IDirect3DRMFrame2 *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddScale(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddRotation(IDirect3DRMFrame2 *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddRotation(real_this, a, b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddVisual(IDirect3DRMFrame2 *this, IDirect3DRMVisual *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_AddVisual(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetChildren(IDirect3DRMFrame2 *this, IDirect3DRMFrameArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetChildren(real_this, a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame2_GetColor(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetColor(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetLights(IDirect3DRMFrame2 *this, IDirect3DRMLightArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetLights(real_this, a);
}

static D3DRMMATERIALMODE STDCALL SDL_IDirect3DRMFrame2_GetMaterialMode(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetMaterialMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetParent(IDirect3DRMFrame2 *this, IDirect3DRMFrame **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetParent(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetPosition(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetPosition(real_this, from_IDirect3DRMFrame(a), b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetRotation(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVECTOR *b, D3DVALUE *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetRotation(real_this, from_IDirect3DRMFrame(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetScene(IDirect3DRMFrame2 *this, IDirect3DRMFrame **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    Direct3DRMFrame *frame;
    HRESULT res = SDL_Direct3DRMFrame_GetScene(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame;
    }
    return res;
}

static D3DRMSORTMODE STDCALL SDL_IDirect3DRMFrame2_GetSortMode(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetSortMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetTexture(IDirect3DRMFrame2 *this, IDirect3DRMTexture **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetTexture(real_this, &texture);
    if (a) {
        *a = &texture->interface_IDirect3DRMTexture;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetTransform(IDirect3DRMFrame2 *this, D3DRMMATRIX4D a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetTransform(real_this, NULL, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetVelocity(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVECTOR *b, BOOL c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetVelocity(real_this, from_IDirect3DRMFrame(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetOrientation(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVECTOR *b, D3DVECTOR *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetOrientation(real_this, from_IDirect3DRMFrame(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetVisuals(IDirect3DRMFrame2 *this, IDirect3DRMVisualArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    SDL_Direct3DRMVisualArray *visual_array = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetVisualArray(real_this, &visual_array);
    if (a) {
        *a = &visual_array->interface_IDirect3DRMVisualArray;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetTextureTopology(IDirect3DRMFrame2 *this, BOOL *a, BOOL *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetTextureTopology(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_InverseTransform(IDirect3DRMFrame2 *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_InverseTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_Load(IDirect3DRMFrame2 *this, void *a, void *b, D3DRMLOADOPTIONS c, D3DRMLOADTEXTURECALLBACK loadTextureProc, void *lpArgLTP) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURECALLBACK(&load_texture_callback_storage, loadTextureProc, lpArgLTP);
    return SDL_Direct3DRMFrame_Load(real_this, a, b, c, &load_texture_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_LookAt(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, IDirect3DRMFrame *b, D3DRMFRAMECONSTRAINT c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_LookAt(real_this, from_IDirect3DRMFrame(a), from_IDirect3DRMFrame(b), c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_Move(IDirect3DRMFrame2 *this, D3DVALUE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_Move(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_DeleteChild(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_DeleteChild(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_DeleteLight(IDirect3DRMFrame2 *this, IDirect3DRMLight *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_DeleteLight(real_this, from_IDirect3DRMLight(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_DeleteMoveCallback(IDirect3DRMFrame2 *this, D3DRMFRAMEMOVECALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    SDL_FrameMoveAdapterCallback frame_move_callback_storage;
    adapt_D3DRMFRAMEMOVECALLBACK(&frame_move_callback_storage, a, b);
    return SDL_Direct3DRMFrame_DeleteMoveCallback(real_this, &frame_move_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_DeleteVisual(IDirect3DRMFrame2 *this, IDirect3DRMVisual *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_DeleteVisual(real_this, (IUnknown *) a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame2_GetSceneBackground(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetSceneBackground(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetSceneBackgroundDepth(IDirect3DRMFrame2 *this, IDirectDrawSurface **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetSceneBackgroundDepth(real_this, a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame2_GetSceneFogColor(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetSceneFogColor(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMFrame2_GetSceneFogEnable(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetSceneFogEnable(real_this);
}

static D3DRMFOGMODE STDCALL SDL_IDirect3DRMFrame2_GetSceneFogMode(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetSceneFogMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetSceneFogParams(IDirect3DRMFrame2 *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetSceneFogParams(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneBackground(IDirect3DRMFrame2 *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneBackground(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneBackgroundRGB(IDirect3DRMFrame2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundRGB(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneBackgroundDepth(IDirect3DRMFrame2 *this, IDirectDrawSurface *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundDepth(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneBackgroundImage(IDirect3DRMFrame2 *this, IDirect3DRMTexture *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundImage(real_this, from_IDirect3DRMTexture(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneFogEnable(IDirect3DRMFrame2 *this, BOOL a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneFogEnable(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneFogColor(IDirect3DRMFrame2 *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneFogColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneFogMode(IDirect3DRMFrame2 *this, D3DRMFOGMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneFogMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSceneFogParams(IDirect3DRMFrame2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSceneFogParams(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetColor(IDirect3DRMFrame2 *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetColorRGB(IDirect3DRMFrame2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetColorRGB(real_this, a, b, c);
}

static D3DRMZBUFFERMODE STDCALL SDL_IDirect3DRMFrame2_GetZbufferMode(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetZbufferMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetMaterialMode(IDirect3DRMFrame2 *this, D3DRMMATERIALMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetMaterialMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetOrientation(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e, D3DVALUE f, D3DVALUE g) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetOrientation(real_this, from_IDirect3DRMFrame(a), b, c, d, e, f, g);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetPosition(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetPosition(real_this, from_IDirect3DRMFrame(a), b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetRotation(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetRotation(real_this, from_IDirect3DRMFrame(a), b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetSortMode(IDirect3DRMFrame2 *this, D3DRMSORTMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetSortMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetTexture(IDirect3DRMFrame2 *this, IDirect3DRMTexture *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetTexture(real_this, from_IDirect3DRMTexture(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetTextureTopology(IDirect3DRMFrame2 *this, BOOL a, BOOL b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetTextureTopology(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetVelocity(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, BOOL e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetVelocity(real_this, from_IDirect3DRMFrame(a), b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetZbufferMode(IDirect3DRMFrame2 *this, D3DRMZBUFFERMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetZbufferMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_Transform(IDirect3DRMFrame2 *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_Transform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_AddMoveCallback2(IDirect3DRMFrame2 *this, D3DRMFRAME2MOVECALLBACK a, void *b, DWORD c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    SDL_FrameMoveAdapterCallback frame_move_callback_storage;
    adapt_D3DRMFRAMEMOVECALLBACK2(&frame_move_callback_storage, a, b);
    return SDL_Direct3DRMFrame_AddMoveCallback(real_this, &frame_move_callback_storage, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetBox(IDirect3DRMFrame2 *this, D3DRMBOX *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetBox(real_this, a);
}

static BOOL STDCALL SDL_IDirect3DRMFrame2_GetBoxEnable(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetBoxEnable(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetAxes(IDirect3DRMFrame2 *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetAxes(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetMaterial(IDirect3DRMFrame2 *this, IDirect3DRMMaterial **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    Direct3DRMMaterial *material = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetMaterial(real_this, &material);
    if (a) {
        *a = &material->interface_IDirect3DRMMaterial;
    }
    return res;
}

static BOOL STDCALL SDL_IDirect3DRMFrame2_GetInheritAxes(IDirect3DRMFrame2 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetInheritAxes(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_GetHierarchyBox(IDirect3DRMFrame2 *this, D3DRMBOX *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_GetHierarchyBox(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetBox(IDirect3DRMFrame2 *this, D3DRMBOX *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetBox(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetBoxEnable(IDirect3DRMFrame2 *this, BOOL a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetBoxEnable(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetAxes(IDirect3DRMFrame2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e, D3DVALUE f) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetAxes(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetInheritAxes(IDirect3DRMFrame2 *this, BOOL a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetInheritAxes(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetMaterial(IDirect3DRMFrame2 *this, IDirect3DRMMaterial *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetMaterial(real_this, from_IDirect3DRMMaterial(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_SetQuaternion(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DRMQUATERNION *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_SetQuaternion(real_this, from_IDirect3DRMFrame(a), b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_RayPick(IDirect3DRMFrame2 *this, IDirect3DRMFrame *a, D3DRMRAY *b, DWORD c, IDirect3DRMPicked2Array **d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_RayPick(real_this, from_IDirect3DRMFrame(a), b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame2_Save(IDirect3DRMFrame2 *this, const char *a, D3DRMXOFFORMAT b, D3DRMSAVEOPTIONS c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame2(this);
    return SDL_Direct3DRMFrame_Save(real_this, a, b, c);
}


static IDirect3DRMFrame2Vtbl SDL_IDirect3DRMFrame2_Vtable = {
    SDL_IDirect3DRMFrame2_QueryInterface,
    SDL_IDirect3DRMFrame2_AddRef,
    SDL_IDirect3DRMFrame2_Release,
    SDL_IDirect3DRMFrame2_Clone,
    SDL_IDirect3DRMFrame2_AddDestroyCallback,
    SDL_IDirect3DRMFrame2_DeleteDestroyCallback,
    SDL_IDirect3DRMFrame2_SetAppData,
    SDL_IDirect3DRMFrame2_GetAppData,
    SDL_IDirect3DRMFrame2_SetName,
    SDL_IDirect3DRMFrame2_GetName,
    SDL_IDirect3DRMFrame2_GetClassName,
    SDL_IDirect3DRMFrame2_AddChild,
    SDL_IDirect3DRMFrame2_AddLight,
    SDL_IDirect3DRMFrame2_AddMoveCallback,
    SDL_IDirect3DRMFrame2_AddTransform,
    SDL_IDirect3DRMFrame2_AddTranslation,
    SDL_IDirect3DRMFrame2_AddScale,
    SDL_IDirect3DRMFrame2_AddRotation,
    SDL_IDirect3DRMFrame2_AddVisual,
    SDL_IDirect3DRMFrame2_GetChildren,
    SDL_IDirect3DRMFrame2_GetColor,
    SDL_IDirect3DRMFrame2_GetLights,
    SDL_IDirect3DRMFrame2_GetMaterialMode,
    SDL_IDirect3DRMFrame2_GetParent,
    SDL_IDirect3DRMFrame2_GetPosition,
    SDL_IDirect3DRMFrame2_GetRotation,
    SDL_IDirect3DRMFrame2_GetScene,
    SDL_IDirect3DRMFrame2_GetSortMode,
    SDL_IDirect3DRMFrame2_GetTexture,
    SDL_IDirect3DRMFrame2_GetTransform,
    SDL_IDirect3DRMFrame2_GetVelocity,
    SDL_IDirect3DRMFrame2_GetOrientation,
    SDL_IDirect3DRMFrame2_GetVisuals,
    SDL_IDirect3DRMFrame2_GetTextureTopology,
    SDL_IDirect3DRMFrame2_InverseTransform,
    SDL_IDirect3DRMFrame2_Load,
    SDL_IDirect3DRMFrame2_LookAt,
    SDL_IDirect3DRMFrame2_Move,
    SDL_IDirect3DRMFrame2_DeleteChild,
    SDL_IDirect3DRMFrame2_DeleteLight,
    SDL_IDirect3DRMFrame2_DeleteMoveCallback,
    SDL_IDirect3DRMFrame2_DeleteVisual,
    SDL_IDirect3DRMFrame2_GetSceneBackground,
    SDL_IDirect3DRMFrame2_GetSceneBackgroundDepth,
    SDL_IDirect3DRMFrame2_GetSceneFogColor,
    SDL_IDirect3DRMFrame2_GetSceneFogEnable,
    SDL_IDirect3DRMFrame2_GetSceneFogMode,
    SDL_IDirect3DRMFrame2_GetSceneFogParams,
    SDL_IDirect3DRMFrame2_SetSceneBackground,
    SDL_IDirect3DRMFrame2_SetSceneBackgroundRGB,
    SDL_IDirect3DRMFrame2_SetSceneBackgroundDepth,
    SDL_IDirect3DRMFrame2_SetSceneBackgroundImage,
    SDL_IDirect3DRMFrame2_SetSceneFogEnable,
    SDL_IDirect3DRMFrame2_SetSceneFogColor,
    SDL_IDirect3DRMFrame2_SetSceneFogMode,
    SDL_IDirect3DRMFrame2_SetSceneFogParams,
    SDL_IDirect3DRMFrame2_SetColor,
    SDL_IDirect3DRMFrame2_SetColorRGB,
    SDL_IDirect3DRMFrame2_GetZbufferMode,
    SDL_IDirect3DRMFrame2_SetMaterialMode,
    SDL_IDirect3DRMFrame2_SetOrientation,
    SDL_IDirect3DRMFrame2_SetPosition,
    SDL_IDirect3DRMFrame2_SetRotation,
    SDL_IDirect3DRMFrame2_SetSortMode,
    SDL_IDirect3DRMFrame2_SetTexture,
    SDL_IDirect3DRMFrame2_SetTextureTopology,
    SDL_IDirect3DRMFrame2_SetVelocity,
    SDL_IDirect3DRMFrame2_SetZbufferMode,
    SDL_IDirect3DRMFrame2_Transform,
    SDL_IDirect3DRMFrame2_AddMoveCallback2,
    SDL_IDirect3DRMFrame2_GetBox,
    SDL_IDirect3DRMFrame2_GetBoxEnable,
    SDL_IDirect3DRMFrame2_GetAxes,
    SDL_IDirect3DRMFrame2_GetMaterial,
    SDL_IDirect3DRMFrame2_GetInheritAxes,
    SDL_IDirect3DRMFrame2_GetHierarchyBox,
    SDL_IDirect3DRMFrame2_SetBox,
    SDL_IDirect3DRMFrame2_SetBoxEnable,
    SDL_IDirect3DRMFrame2_SetAxes,
    SDL_IDirect3DRMFrame2_SetInheritAxes,
    SDL_IDirect3DRMFrame2_SetMaterial,
    SDL_IDirect3DRMFrame2_SetQuaternion,
    SDL_IDirect3DRMFrame2_RayPick,
    SDL_IDirect3DRMFrame2_Save,
};

// IDirect3DRMFrame3 interface

static HRESULT STDCALL SDL_IDirect3DRMFrame3_QueryInterface(IDirect3DRMFrame3 *this, REFIID a, void **b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMFrame3_AddRef(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMFrame3_Release(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_Clone(IDirect3DRMFrame3 *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddDestroyCallback(IDirect3DRMFrame3 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_DeleteDestroyCallback(IDirect3DRMFrame3 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetAppData(IDirect3DRMFrame3 *this, LPVOID a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMFrame3_GetAppData(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetName(IDirect3DRMFrame3 *this, const char *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetName(IDirect3DRMFrame3 *this, DWORD *a, char *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetClassName(IDirect3DRMFrame3 *this, DWORD *a, char *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddChild(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddChild(real_this, from_IDirect3DRMFrame3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddLight(IDirect3DRMFrame3 *this, IDirect3DRMLight *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddLight(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddMoveCallback(IDirect3DRMFrame3 *this, D3DRMFRAME3MOVECALLBACK d3drmFMC, void *lpArg, DWORD dwFlags) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    SDL_FrameMoveAdapterCallback frame_move_callback_storage;
    adapt_D3DRMFRAME3MOVECALLBACK(&frame_move_callback_storage, d3drmFMC, lpArg);
    return SDL_Direct3DRMFrame_AddMoveCallback(real_this, &frame_move_callback_storage, dwFlags);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddTransform(IDirect3DRMFrame3 *this, D3DRMCOMBINETYPE a, D3DRMMATRIX4D b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddTranslation(IDirect3DRMFrame3 *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddTranslation(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddScale(IDirect3DRMFrame3 *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddScale(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddRotation(IDirect3DRMFrame3 *this, D3DRMCOMBINETYPE a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddRotation(real_this, a, b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_AddVisual(IDirect3DRMFrame3 *this, IDirect3DRMVisual *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_AddVisual(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetChildren(IDirect3DRMFrame3 *this, IDirect3DRMFrameArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetChildren(real_this, a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame3_GetColor(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetColor(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetLights(IDirect3DRMFrame3 *this, IDirect3DRMLightArray **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetLights(real_this, a);
}

static D3DRMMATERIALMODE STDCALL SDL_IDirect3DRMFrame3_GetMaterialMode(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetMaterialMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetParent(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetParent(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame3;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetPosition(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetPosition(real_this, from_IDirect3DRMFrame3(a), b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetRotation(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVECTOR *b, D3DVALUE *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetRotation(real_this, from_IDirect3DRMFrame3(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetScene(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    Direct3DRMFrame *frame = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetScene(real_this, &frame);
    if (a) {
        *a = &frame->interface_IDirect3DRMFrame3;
    }
    return res;
}

static D3DRMSORTMODE STDCALL SDL_IDirect3DRMFrame3_GetSortMode(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSortMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetTexture(IDirect3DRMFrame3 *this, IDirect3DRMTexture3 **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    Direct3DRMTexture *texture = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetTexture(real_this, &texture);
    if (a) {
        *a = &texture->interface_IDirect3DRMTexture3;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetTransform(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DRMMATRIX4D b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetTransform(real_this, from_IDirect3DRMFrame3(a), b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetVelocity(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVECTOR *b, BOOL c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetVelocity(real_this, from_IDirect3DRMFrame3(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetOrientation(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVECTOR *b, D3DVECTOR *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetOrientation(real_this, from_IDirect3DRMFrame3(a), b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetVisuals(IDirect3DRMFrame3 *this, DWORD *a, IUnknown **b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetVisuals(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_InverseTransform(IDirect3DRMFrame3 *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_InverseTransform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_Load(IDirect3DRMFrame3 *this, void *a, void *b, D3DRMLOADOPTIONS c, D3DRMLOADTEXTURE3CALLBACK loadTextureProc, void *lpArgLTP) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURE3CALLBACK(&load_texture_callback_storage, loadTextureProc, lpArgLTP);
    return SDL_Direct3DRMFrame_Load(real_this, a, b, c, &load_texture_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_LookAt(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, IDirect3DRMFrame3 *b, D3DRMFRAMECONSTRAINT c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_LookAt(real_this, from_IDirect3DRMFrame3(a), from_IDirect3DRMFrame3(b), c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_Move(IDirect3DRMFrame3 *this, D3DVALUE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_Move(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_DeleteChild(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_DeleteChild(real_this, from_IDirect3DRMFrame3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_DeleteLight(IDirect3DRMFrame3 *this, IDirect3DRMLight *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_DeleteLight(real_this, from_IDirect3DRMLight(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_DeleteMoveCallback(IDirect3DRMFrame3 *this, D3DRMFRAME3MOVECALLBACK a, void *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    SDL_FrameMoveAdapterCallback frame_move_callback_storage;
    adapt_D3DRMFRAME3MOVECALLBACK(&frame_move_callback_storage, a, b);
    return SDL_Direct3DRMFrame_DeleteMoveCallback(real_this, &frame_move_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_DeleteVisual(IDirect3DRMFrame3 *this, IUnknown *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_DeleteVisual(real_this, a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame3_GetSceneBackground(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSceneBackground(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetSceneBackgroundDepth(IDirect3DRMFrame3 *this, IDirectDrawSurface **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSceneBackgroundDepth(real_this, a);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMFrame3_GetSceneFogColor(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSceneFogColor(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMFrame3_GetSceneFogEnable(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSceneFogEnable(real_this);
}

static D3DRMFOGMODE STDCALL SDL_IDirect3DRMFrame3_GetSceneFogMode(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSceneFogMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetSceneFogParams(IDirect3DRMFrame3 *this, D3DVALUE *a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSceneFogParams(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneBackground(IDirect3DRMFrame3 *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneBackground(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneBackgroundRGB(IDirect3DRMFrame3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundRGB(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneBackgroundDepth(IDirect3DRMFrame3 *this, IDirectDrawSurface *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundDepth(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneBackgroundImage(IDirect3DRMFrame3 *this, IDirect3DRMTexture3 *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneBackgroundImage(real_this, from_IDirect3DRMTexture3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneFogEnable(IDirect3DRMFrame3 *this, BOOL a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneFogEnable(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneFogColor(IDirect3DRMFrame3 *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneFogColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneFogMode(IDirect3DRMFrame3 *this, D3DRMFOGMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneFogMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneFogParams(IDirect3DRMFrame3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneFogParams(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetColor(IDirect3DRMFrame3 *this, D3DCOLOR a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetColorRGB(IDirect3DRMFrame3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetColorRGB(real_this, a, b, c);
}

static D3DRMZBUFFERMODE STDCALL SDL_IDirect3DRMFrame3_GetZbufferMode(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetZbufferMode(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetMaterialMode(IDirect3DRMFrame3 *this, D3DRMMATERIALMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetMaterialMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetOrientation(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e, D3DVALUE f, D3DVALUE g) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetOrientation(real_this, from_IDirect3DRMFrame3(a), b, c, d, e, f, g);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetPosition(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetPosition(real_this, from_IDirect3DRMFrame3(a), b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetRotation(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetRotation(real_this, from_IDirect3DRMFrame3(a), b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSortMode(IDirect3DRMFrame3 *this, D3DRMSORTMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSortMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetTexture(IDirect3DRMFrame3 *this, IDirect3DRMTexture3 *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetTexture(real_this, from_IDirect3DRMTexture3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetVelocity(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DVALUE b, D3DVALUE c, D3DVALUE d, BOOL e) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetVelocity(real_this, from_IDirect3DRMFrame3(a), b, c, d, e);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetZbufferMode(IDirect3DRMFrame3 *this, D3DRMZBUFFERMODE a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetZbufferMode(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_Transform(IDirect3DRMFrame3 *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_Transform(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetBox(IDirect3DRMFrame3 *this, D3DRMBOX *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetBox(real_this, a);
}

static BOOL STDCALL SDL_IDirect3DRMFrame3_GetBoxEnable(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetBoxEnable(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetAxes(IDirect3DRMFrame3 *this, D3DVECTOR *a, D3DVECTOR *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetAxes(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetMaterial(IDirect3DRMFrame3 *this, IDirect3DRMMaterial2 **a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    Direct3DRMMaterial *material = NULL;
    HRESULT res = SDL_Direct3DRMFrame_GetMaterial(real_this, &material);
    if (a) {
        *a = &material->interface_IDirect3DRMMaterial2;
    }
    return res;
}

static BOOL STDCALL SDL_IDirect3DRMFrame3_GetInheritAxes(IDirect3DRMFrame3 *this) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetInheritAxes(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetHierarchyBox(IDirect3DRMFrame3 *this, D3DRMBOX *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetHierarchyBox(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetBox(IDirect3DRMFrame3 *this, D3DRMBOX *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetBox(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetBoxEnable(IDirect3DRMFrame3 *this, BOOL a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetBoxEnable(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetAxes(IDirect3DRMFrame3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c, D3DVALUE d, D3DVALUE e, D3DVALUE f) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetAxes(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetInheritAxes(IDirect3DRMFrame3 *this, BOOL a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetInheritAxes(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetMaterial(IDirect3DRMFrame3 *this, IDirect3DRMMaterial2 *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetMaterial(real_this, from_IDirect3DRMMaterial2(a));
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetQuaternion(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DRMQUATERNION *b) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetQuaternion(real_this, from_IDirect3DRMFrame3(a), b);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_RayPick(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, D3DRMRAY *b, DWORD c, IDirect3DRMPicked2Array **d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_RayPick(real_this, from_IDirect3DRMFrame3(a), b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_Save(IDirect3DRMFrame3 *this, const char *a, D3DRMXOFFORMAT b, D3DRMSAVEOPTIONS c) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_Save(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_TransformVectors(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, DWORD b, D3DVECTOR *c, D3DVECTOR *d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_TransformVectors(real_this, from_IDirect3DRMFrame3(a), b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_InverseTransformVectors(IDirect3DRMFrame3 *this, IDirect3DRMFrame3 *a, DWORD b, D3DVECTOR *c, D3DVECTOR *d) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_InverseTransformVectors(real_this, from_IDirect3DRMFrame3(a), b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetTraversalOptions(IDirect3DRMFrame3 *this, DWORD a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetTraversalOptions(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetTraversalOptions(IDirect3DRMFrame3 *this, DWORD *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetTraversalOptions(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetSceneFogMethod(IDirect3DRMFrame3 *this, DWORD a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetSceneFogMethod(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetSceneFogMethod(IDirect3DRMFrame3 *this, DWORD *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetSceneFogMethod(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_SetMaterialOverride(IDirect3DRMFrame3 *this, D3DRMMATERIALOVERRIDE *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_SetMaterialOverride(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMFrame3_GetMaterialOverride(IDirect3DRMFrame3 *this, D3DRMMATERIALOVERRIDE *a) {
    Direct3DRMFrame *real_this = from_IDirect3DRMFrame3(this);
    return SDL_Direct3DRMFrame_GetMaterialOverride(real_this, a);
}


static IDirect3DRMFrame3Vtbl SDL_IDirect3DRMFrame3_Vtable = {
    SDL_IDirect3DRMFrame3_QueryInterface,
    SDL_IDirect3DRMFrame3_AddRef,
    SDL_IDirect3DRMFrame3_Release,
    SDL_IDirect3DRMFrame3_Clone,
    SDL_IDirect3DRMFrame3_AddDestroyCallback,
    SDL_IDirect3DRMFrame3_DeleteDestroyCallback,
    SDL_IDirect3DRMFrame3_SetAppData,
    SDL_IDirect3DRMFrame3_GetAppData,
    SDL_IDirect3DRMFrame3_SetName,
    SDL_IDirect3DRMFrame3_GetName,
    SDL_IDirect3DRMFrame3_GetClassName,
    SDL_IDirect3DRMFrame3_AddChild,
    SDL_IDirect3DRMFrame3_AddLight,
    SDL_IDirect3DRMFrame3_AddMoveCallback,
    SDL_IDirect3DRMFrame3_AddTransform,
    SDL_IDirect3DRMFrame3_AddTranslation,
    SDL_IDirect3DRMFrame3_AddScale,
    SDL_IDirect3DRMFrame3_AddRotation,
    SDL_IDirect3DRMFrame3_AddVisual,
    SDL_IDirect3DRMFrame3_GetChildren,
    SDL_IDirect3DRMFrame3_GetColor,
    SDL_IDirect3DRMFrame3_GetLights,
    SDL_IDirect3DRMFrame3_GetMaterialMode,
    SDL_IDirect3DRMFrame3_GetParent,
    SDL_IDirect3DRMFrame3_GetPosition,
    SDL_IDirect3DRMFrame3_GetRotation,
    SDL_IDirect3DRMFrame3_GetScene,
    SDL_IDirect3DRMFrame3_GetSortMode,
    SDL_IDirect3DRMFrame3_GetTexture,
    SDL_IDirect3DRMFrame3_GetTransform,
    SDL_IDirect3DRMFrame3_GetVelocity,
    SDL_IDirect3DRMFrame3_GetOrientation,
    SDL_IDirect3DRMFrame3_GetVisuals,
    SDL_IDirect3DRMFrame3_InverseTransform,
    SDL_IDirect3DRMFrame3_Load,
    SDL_IDirect3DRMFrame3_LookAt,
    SDL_IDirect3DRMFrame3_Move,
    SDL_IDirect3DRMFrame3_DeleteChild,
    SDL_IDirect3DRMFrame3_DeleteLight,
    SDL_IDirect3DRMFrame3_DeleteMoveCallback,
    SDL_IDirect3DRMFrame3_DeleteVisual,
    SDL_IDirect3DRMFrame3_GetSceneBackground,
    SDL_IDirect3DRMFrame3_GetSceneBackgroundDepth,
    SDL_IDirect3DRMFrame3_GetSceneFogColor,
    SDL_IDirect3DRMFrame3_GetSceneFogEnable,
    SDL_IDirect3DRMFrame3_GetSceneFogMode,
    SDL_IDirect3DRMFrame3_GetSceneFogParams,
    SDL_IDirect3DRMFrame3_SetSceneBackground,
    SDL_IDirect3DRMFrame3_SetSceneBackgroundRGB,
    SDL_IDirect3DRMFrame3_SetSceneBackgroundDepth,
    SDL_IDirect3DRMFrame3_SetSceneBackgroundImage,
    SDL_IDirect3DRMFrame3_SetSceneFogEnable,
    SDL_IDirect3DRMFrame3_SetSceneFogColor,
    SDL_IDirect3DRMFrame3_SetSceneFogMode,
    SDL_IDirect3DRMFrame3_SetSceneFogParams,
    SDL_IDirect3DRMFrame3_SetColor,
    SDL_IDirect3DRMFrame3_SetColorRGB,
    SDL_IDirect3DRMFrame3_GetZbufferMode,
    SDL_IDirect3DRMFrame3_SetMaterialMode,
    SDL_IDirect3DRMFrame3_SetOrientation,
    SDL_IDirect3DRMFrame3_SetPosition,
    SDL_IDirect3DRMFrame3_SetRotation,
    SDL_IDirect3DRMFrame3_SetSortMode,
    SDL_IDirect3DRMFrame3_SetTexture,
    SDL_IDirect3DRMFrame3_SetVelocity,
    SDL_IDirect3DRMFrame3_SetZbufferMode,
    SDL_IDirect3DRMFrame3_Transform,
    SDL_IDirect3DRMFrame3_GetBox,
    SDL_IDirect3DRMFrame3_GetBoxEnable,
    SDL_IDirect3DRMFrame3_GetAxes,
    SDL_IDirect3DRMFrame3_GetMaterial,
    SDL_IDirect3DRMFrame3_GetInheritAxes,
    SDL_IDirect3DRMFrame3_GetHierarchyBox,
    SDL_IDirect3DRMFrame3_SetBox,
    SDL_IDirect3DRMFrame3_SetBoxEnable,
    SDL_IDirect3DRMFrame3_SetAxes,
    SDL_IDirect3DRMFrame3_SetInheritAxes,
    SDL_IDirect3DRMFrame3_SetMaterial,
    SDL_IDirect3DRMFrame3_SetQuaternion,
    SDL_IDirect3DRMFrame3_RayPick,
    SDL_IDirect3DRMFrame3_Save,
    SDL_IDirect3DRMFrame3_TransformVectors,
    SDL_IDirect3DRMFrame3_InverseTransformVectors,
    SDL_IDirect3DRMFrame3_SetTraversalOptions,
    SDL_IDirect3DRMFrame3_GetTraversalOptions,
    SDL_IDirect3DRMFrame3_SetSceneFogMethod,
    SDL_IDirect3DRMFrame3_GetSceneFogMethod,
    SDL_IDirect3DRMFrame3_SetMaterialOverride,
    SDL_IDirect3DRMFrame3_GetMaterialOverride,
};

Direct3DRMFrame *SDL_CreateD3DRMFrame( Direct3DRMFrame *parent) {
    Direct3DRMFrame *frame = (Direct3DRMFrame *) SDL_calloc(1, sizeof(Direct3DRMFrame));
    if (frame == NULL) {
        return NULL;
    }
    frame->interface_IDirect3DRMFrame.lpVtbl = &SDL_IDirect3DRMFrame_Vtable;
    frame->interface_IDirect3DRMFrame2.lpVtbl = &SDL_IDirect3DRMFrame2_Vtable;
    frame->interface_IDirect3DRMFrame3.lpVtbl = &SDL_IDirect3DRMFrame3_Vtable;
    frame->parent = parent;
    return frame;
}
