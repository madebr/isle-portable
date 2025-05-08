#include "idirect3drmmeshbuilder.h"
#include "idirect3drmface.h"
#include "idirect3drmframe.h"
#include "idirect3drmmaterial.h"
#include "idirect3drmtexture.h"

#include "adapters.h"

#include <d3drmobj.h>
#include <winglue.h>

#include <dxfile.h>
#include <rmxftmpl.h>

#include "common/common_com.h"
#include "common/common_logging.h"


static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_QueryInterface(Direct3DRMMeshBuilder *this, REFIID riid, void **ppvObject) {
    if (SDL_memcmp(riid, &IID_IDirect3DRMMeshBuilder, sizeof(SDL_GUID)) == 0) {
        *ppvObject = &this->interface_IDirect3DRMMeshBuilder;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRMMeshBuilder2, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMMeshBuilder2;
        return S_OK;
    } else if (SDL_memcmp(riid, &IID_IDirect3DRMMeshBuilder3, sizeof(SDL_GUID)) == 0) {
        COM_INCREF(this);
        *ppvObject = &this->interface_IDirect3DRMMeshBuilder3;
        return S_OK;
    } else {
        *ppvObject = NULL;
        return E_NOINTERFACE;
    }
}

static ULONG STDCALL SDL_Direct3DRMMeshBuilder_AddRef(Direct3DRMMeshBuilder *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, 1);
    return prev_value + 1;
}

static ULONG STDCALL SDL_Direct3DRMMeshBuilder_Release(Direct3DRMMeshBuilder *this) {
    int prev_value = SDL_AddAtomicInt(&this->ref_count, -1);
    if (prev_value == 1) {
        IDirectXFile_Release(this->xfile);
        SDL_free(this);
    }
    return (ULONG) prev_value - 1;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Clone(Direct3DRMMeshBuilder *this, IUnknown *a, REFIID b, void **c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddDestroyCallback(Direct3DRMMeshBuilder *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_DeleteDestroyCallback(Direct3DRMMeshBuilder *this, D3DRMOBJECTCALLBACK a, void *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetAppData(Direct3DRMMeshBuilder *this, LPVOID a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static LPVOID STDCALL SDL_Direct3DRMMeshBuilder_GetAppData(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return NULL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetName(Direct3DRMMeshBuilder *this, const char *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetName(Direct3DRMMeshBuilder *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetClassName(Direct3DRMMeshBuilder *this, DWORD *a, char *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Load(Direct3DRMMeshBuilder *this, void *a, void *b, D3DRMLOADOPTIONS c, LoadTextureAdapterCallbackData *loadTextureCB) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) loadTextureCB;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Save(Direct3DRMMeshBuilder *this, const char *a, D3DRMXOFFORMAT b, D3DRMSAVEOPTIONS c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Scale(Direct3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Translate(Direct3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetColorSource(Direct3DRMMeshBuilder *this, D3DRMCOLORSOURCE a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetBox(Direct3DRMMeshBuilder *this, D3DRMBOX *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GenerateNormalsFromCreaseAngle(Direct3DRMMeshBuilder *this, D3DVALUE dvCreaseAngle, DWORD dwFlags) {
    (void) this;
    (void) dvCreaseAngle;
    (void) dwFlags;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GenerateNormals(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DRMCOLORSOURCE STDCALL SDL_Direct3DRMMeshBuilder_GetColorSource(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return D3DRMCOLOR_FROMFACE;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddMesh(Direct3DRMMeshBuilder *this, IDirect3DRMMesh *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddMeshBuilder(Direct3DRMMeshBuilder *this, Direct3DRMMeshBuilder *a, DWORD b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddFrame(Direct3DRMMeshBuilder *this, Direct3DRMFrame *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddFace(Direct3DRMMeshBuilder *this, SDL_Direct3DRMFace *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddFaces(Direct3DRMMeshBuilder *this, DWORD a, D3DVECTOR *b, DWORD c, D3DVECTOR *d, DWORD *e, struct IDirect3DRMFaceArray **f) {
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

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_ReserveSpace(Direct3DRMMeshBuilder *this, DWORD a, DWORD b, DWORD c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetColorRGB(Direct3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetColor(Direct3DRMMeshBuilder *this, D3DCOLOR a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetTexture(Direct3DRMMeshBuilder *this, Direct3DRMTexture *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetMaterial(Direct3DRMMeshBuilder *this, Direct3DRMMaterial *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetTextureTopology(Direct3DRMMeshBuilder *this, BOOL a, BOOL b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetQuality(Direct3DRMMeshBuilder *this, D3DRMRENDERQUALITY a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetPerspective(Direct3DRMMeshBuilder *this, BOOL a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetVertex(Direct3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetNormal(Direct3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetTextureCoordinates(Direct3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetVertexColor(Direct3DRMMeshBuilder *this, DWORD a, D3DCOLOR b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetVertexColorRGB(Direct3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetFaces(Direct3DRMMeshBuilder *this, struct IDirect3DRMFaceArray **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetGeometry(Direct3DRMMeshBuilder *this, DWORD *a, D3DVECTOR *b, DWORD *c, D3DVECTOR *d, DWORD *e, DWORD *f) {
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

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetTextureCoordinates(Direct3DRMMeshBuilder *this, DWORD a, D3DVALUE *b, D3DVALUE *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static int STDCALL SDL_Direct3DRMMeshBuilder_AddVertex(Direct3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static int STDCALL SDL_Direct3DRMMeshBuilder_AddNormal(Direct3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_CreateFace(Direct3DRMMeshBuilder *this, SDL_Direct3DRMFace **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static D3DRMRENDERQUALITY STDCALL SDL_Direct3DRMMeshBuilder_GetQuality(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static BOOL STDCALL SDL_Direct3DRMMeshBuilder_GetPerspective(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static int STDCALL SDL_Direct3DRMMeshBuilder_GetFaceCount(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static int STDCALL SDL_Direct3DRMMeshBuilder_GetVertexCount(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static D3DCOLOR STDCALL SDL_Direct3DRMMeshBuilder_GetVertexColor(Direct3DRMMeshBuilder *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_CreateMesh(Direct3DRMMeshBuilder *this, IDirect3DRMMesh **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetFace(Direct3DRMMeshBuilder *this, DWORD a, SDL_Direct3DRMFace **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetVertex(Direct3DRMMeshBuilder *this, DWORD a, D3DVECTOR *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetNormal(Direct3DRMMeshBuilder *this, DWORD a, D3DVECTOR *b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_DeleteVertices(Direct3DRMMeshBuilder *this, DWORD a, DWORD b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_DeleteNormals(Direct3DRMMeshBuilder *this, DWORD a, DWORD b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_DeleteFace(Direct3DRMMeshBuilder *this, IDirect3DRMFace2 *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Empty(Direct3DRMMeshBuilder *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Optimize(Direct3DRMMeshBuilder *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddFacesIndexed(Direct3DRMMeshBuilder *this, DWORD a, DWORD *b, DWORD *c, DWORD *d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_CreateSubMesh(Direct3DRMMeshBuilder *this, IUnknown **a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetParentMesh(Direct3DRMMeshBuilder *this, DWORD a, IUnknown **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetSubMeshes(Direct3DRMMeshBuilder *this, DWORD *a, IUnknown **b) {
    (void) this;
    (void) a;
    (void) b;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_DeleteSubMesh(Direct3DRMMeshBuilder *this, IUnknown *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_Enable(Direct3DRMMeshBuilder *this, DWORD a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetEnable(Direct3DRMMeshBuilder *this, DWORD *a) {
    (void) this;
    (void) a;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_AddTriangles(Direct3DRMMeshBuilder *this, DWORD a, DWORD b, DWORD c, void *d) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    (void) d;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetVertices(Direct3DRMMeshBuilder *this, DWORD a, DWORD b, D3DVECTOR *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetVertices(Direct3DRMMeshBuilder *this, DWORD dwFirst, DWORD *lpdwCount, D3DVECTOR *lpdvVector) {
    (void) this;
    (void) dwFirst;
    (void) lpdwCount;
    (void) lpdvVector;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetAllVertices(Direct3DRMMeshBuilder *this, DWORD *vcount, D3DVECTOR *vertices, DWORD *ncount, D3DVECTOR *normals, DWORD *face_data_size, DWORD *face_data) {
    (void) this;
    (void) vcount;
    (void) vertices;
    (void) ncount;
    (void) normals;
    (void) face_data_size;
    (void) face_data;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_SetNormals(Direct3DRMMeshBuilder *this, DWORD a, DWORD b, D3DVECTOR *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static HRESULT STDCALL SDL_Direct3DRMMeshBuilder_GetNormals(Direct3DRMMeshBuilder *this, DWORD a, DWORD *b, D3DVECTOR *c) {
    (void) this;
    (void) a;
    (void) b;
    (void) c;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return E_NOTIMPL;
}

static int STDCALL SDL_Direct3DRMMeshBuilder_GetNormalCount(Direct3DRMMeshBuilder *this) {
    (void) this;
    SDL_LogError(D3DRM_CATEGORY, "%s: not implemented", __FUNCTION__);
    return 0;
}

// IDirect3DRMMeshBuilder interface

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_QueryInterface(IDirect3DRMMeshBuilder *this, REFIID a, void **b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMMeshBuilder_AddRef(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMMeshBuilder_Release(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_Clone(IDirect3DRMMeshBuilder *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_AddDestroyCallback(IDirect3DRMMeshBuilder *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_DeleteDestroyCallback(IDirect3DRMMeshBuilder *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetAppData(IDirect3DRMMeshBuilder *this, LPVOID a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMMeshBuilder_GetAppData(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetName(IDirect3DRMMeshBuilder *this, const char *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_GetName(IDirect3DRMMeshBuilder *this, DWORD *a, char *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_GetClassName(IDirect3DRMMeshBuilder *this, DWORD *a, char *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_Load(IDirect3DRMMeshBuilder *this, void *a, void *b, D3DRMLOADOPTIONS c, D3DRMLOADTEXTURECALLBACK d, void *e) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURECALLBACK(&load_texture_callback_storage, d, e);
    return SDL_Direct3DRMMeshBuilder_Load(real_this, a, b, c, &load_texture_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_Save(IDirect3DRMMeshBuilder *this, const char *a, D3DRMXOFFORMAT b, D3DRMSAVEOPTIONS c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_Save(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_Scale(IDirect3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_Scale(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_Translate(IDirect3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_Translate(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetColorSource(IDirect3DRMMeshBuilder *this, D3DRMCOLORSOURCE a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetColorSource(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_GetBox(IDirect3DRMMeshBuilder *this, D3DRMBOX *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetBox(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_GenerateNormals(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GenerateNormals(real_this);
}

static D3DRMCOLORSOURCE STDCALL SDL_IDirect3DRMMeshBuilder_GetColorSource(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetColorSource(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_AddMesh(IDirect3DRMMeshBuilder *this, IDirect3DRMMesh *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddMesh(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_AddMeshBuilder(IDirect3DRMMeshBuilder *this, IDirect3DRMMeshBuilder *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddMeshBuilder(real_this, from_IDirect3DRMMeshBuilder(a), 0);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_AddFrame(IDirect3DRMMeshBuilder *this, IDirect3DRMFrame *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddFrame(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_AddFace(IDirect3DRMMeshBuilder *this, IDirect3DRMFace *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddFace(real_this, from_IDirect3DRMFace(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_AddFaces(IDirect3DRMMeshBuilder *this, DWORD a, D3DVECTOR *b, DWORD c, D3DVECTOR *d, DWORD *e, struct IDirect3DRMFaceArray **f) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddFaces(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_ReserveSpace(IDirect3DRMMeshBuilder *this, DWORD a, DWORD b, DWORD c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_ReserveSpace(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetColorRGB(IDirect3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetColorRGB(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetColor(IDirect3DRMMeshBuilder *this, D3DCOLOR a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetTexture(IDirect3DRMMeshBuilder *this, struct IDirect3DRMTexture *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetTexture(real_this, from_IDirect3DRMTexture(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetMaterial(IDirect3DRMMeshBuilder *this, struct IDirect3DRMMaterial *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetMaterial(real_this, from_IDirect3DRMMaterial(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetTextureTopology(IDirect3DRMMeshBuilder *this, BOOL a, BOOL b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetTextureTopology(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetQuality(IDirect3DRMMeshBuilder *this, D3DRMRENDERQUALITY a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetQuality(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetPerspective(IDirect3DRMMeshBuilder *this, BOOL a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetPerspective(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetVertex(IDirect3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetVertex(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetNormal(IDirect3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetNormal(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetTextureCoordinates(IDirect3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetTextureCoordinates(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetVertexColor(IDirect3DRMMeshBuilder *this, DWORD a, D3DCOLOR b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetVertexColor(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_SetVertexColorRGB(IDirect3DRMMeshBuilder *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_SetVertexColorRGB(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_GetFaces(IDirect3DRMMeshBuilder *this, struct IDirect3DRMFaceArray **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetFaces(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_GetVertices(IDirect3DRMMeshBuilder *this, DWORD *a, D3DVECTOR *b, DWORD *c, D3DVECTOR *d, DWORD *e, DWORD *f) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetAllVertices(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_GetTextureCoordinates(IDirect3DRMMeshBuilder *this, DWORD a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetTextureCoordinates(real_this, a, b, c);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder_AddVertex(IDirect3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddVertex(real_this, a, b, c);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder_AddNormal(IDirect3DRMMeshBuilder *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_AddNormal(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_CreateFace(IDirect3DRMMeshBuilder *this, IDirect3DRMFace **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    SDL_Direct3DRMFace *face;
    HRESULT res = SDL_Direct3DRMMeshBuilder_CreateFace(real_this, &face);
    if (a) {
        *a = &face->interface_IDirect3DRMFace;
    }
    return res;
}

static D3DRMRENDERQUALITY STDCALL SDL_IDirect3DRMMeshBuilder_GetQuality(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetQuality(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMMeshBuilder_GetPerspective(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetPerspective(real_this);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder_GetFaceCount(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetFaceCount(real_this);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder_GetVertexCount(IDirect3DRMMeshBuilder *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetVertexCount(real_this);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMMeshBuilder_GetVertexColor(IDirect3DRMMeshBuilder *this, DWORD a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_GetVertexColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder_CreateMesh(IDirect3DRMMeshBuilder *this, IDirect3DRMMesh **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder(this);
    return SDL_Direct3DRMMeshBuilder_CreateMesh(real_this, a);
}

static IDirect3DRMMeshBuilderVtbl SDL_IDirect3DRMMeshBuilder_Vtable = {
    SDL_IDirect3DRMMeshBuilder_QueryInterface,
    SDL_IDirect3DRMMeshBuilder_AddRef,
    SDL_IDirect3DRMMeshBuilder_Release,
    SDL_IDirect3DRMMeshBuilder_Clone,
    SDL_IDirect3DRMMeshBuilder_AddDestroyCallback,
    SDL_IDirect3DRMMeshBuilder_DeleteDestroyCallback,
    SDL_IDirect3DRMMeshBuilder_SetAppData,
    SDL_IDirect3DRMMeshBuilder_GetAppData,
    SDL_IDirect3DRMMeshBuilder_SetName,
    SDL_IDirect3DRMMeshBuilder_GetName,
    SDL_IDirect3DRMMeshBuilder_GetClassName,
    SDL_IDirect3DRMMeshBuilder_Load,
    SDL_IDirect3DRMMeshBuilder_Save,
    SDL_IDirect3DRMMeshBuilder_Scale,
    SDL_IDirect3DRMMeshBuilder_Translate,
    SDL_IDirect3DRMMeshBuilder_SetColorSource,
    SDL_IDirect3DRMMeshBuilder_GetBox,
    SDL_IDirect3DRMMeshBuilder_GenerateNormals,
    SDL_IDirect3DRMMeshBuilder_GetColorSource,
    SDL_IDirect3DRMMeshBuilder_AddMesh,
    SDL_IDirect3DRMMeshBuilder_AddMeshBuilder,
    SDL_IDirect3DRMMeshBuilder_AddFrame,
    SDL_IDirect3DRMMeshBuilder_AddFace,
    SDL_IDirect3DRMMeshBuilder_AddFaces,
    SDL_IDirect3DRMMeshBuilder_ReserveSpace,
    SDL_IDirect3DRMMeshBuilder_SetColorRGB,
    SDL_IDirect3DRMMeshBuilder_SetColor,
    SDL_IDirect3DRMMeshBuilder_SetTexture,
    SDL_IDirect3DRMMeshBuilder_SetMaterial,
    SDL_IDirect3DRMMeshBuilder_SetTextureTopology,
    SDL_IDirect3DRMMeshBuilder_SetQuality,
    SDL_IDirect3DRMMeshBuilder_SetPerspective,
    SDL_IDirect3DRMMeshBuilder_SetVertex,
    SDL_IDirect3DRMMeshBuilder_SetNormal,
    SDL_IDirect3DRMMeshBuilder_SetTextureCoordinates,
    SDL_IDirect3DRMMeshBuilder_SetVertexColor,
    SDL_IDirect3DRMMeshBuilder_SetVertexColorRGB,
    SDL_IDirect3DRMMeshBuilder_GetFaces,
    SDL_IDirect3DRMMeshBuilder_GetVertices,
    SDL_IDirect3DRMMeshBuilder_GetTextureCoordinates,
    SDL_IDirect3DRMMeshBuilder_AddVertex,
    SDL_IDirect3DRMMeshBuilder_AddNormal,
    SDL_IDirect3DRMMeshBuilder_CreateFace,
    SDL_IDirect3DRMMeshBuilder_GetQuality,
    SDL_IDirect3DRMMeshBuilder_GetPerspective,
    SDL_IDirect3DRMMeshBuilder_GetFaceCount,
    SDL_IDirect3DRMMeshBuilder_GetVertexCount,
    SDL_IDirect3DRMMeshBuilder_GetVertexColor,
    SDL_IDirect3DRMMeshBuilder_CreateMesh,
};

// IDirect3DRMMeshBuilder2 interface

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_QueryInterface(IDirect3DRMMeshBuilder2 *this, REFIID a, void **b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMMeshBuilder2_AddRef(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMMeshBuilder2_Release(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_Clone(IDirect3DRMMeshBuilder2 *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_AddDestroyCallback(IDirect3DRMMeshBuilder2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_DeleteDestroyCallback(IDirect3DRMMeshBuilder2 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetAppData(IDirect3DRMMeshBuilder2 *this, LPVOID a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMMeshBuilder2_GetAppData(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetName(IDirect3DRMMeshBuilder2 *this, const char *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GetName(IDirect3DRMMeshBuilder2 *this, DWORD *a, char *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GetClassName(IDirect3DRMMeshBuilder2 *this, DWORD *a, char *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_Load(IDirect3DRMMeshBuilder2 *this, void *a, void *b, D3DRMLOADOPTIONS c, D3DRMLOADTEXTURECALLBACK d, void *e) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURECALLBACK(&load_texture_callback_storage, d, e);
    return SDL_Direct3DRMMeshBuilder_Load(real_this, a, b, c, &load_texture_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_Save(IDirect3DRMMeshBuilder2 *this, const char *a, D3DRMXOFFORMAT b, D3DRMSAVEOPTIONS c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_Save(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_Scale(IDirect3DRMMeshBuilder2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_Scale(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_Translate(IDirect3DRMMeshBuilder2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_Translate(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetColorSource(IDirect3DRMMeshBuilder2 *this, D3DRMCOLORSOURCE a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetColorSource(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GetBox(IDirect3DRMMeshBuilder2 *this, D3DRMBOX *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetBox(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GenerateNormals(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GenerateNormals(real_this);
}

static D3DRMCOLORSOURCE STDCALL SDL_IDirect3DRMMeshBuilder2_GetColorSource(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetColorSource(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_AddMesh(IDirect3DRMMeshBuilder2 *this, IDirect3DRMMesh *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddMesh(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_AddMeshBuilder(IDirect3DRMMeshBuilder2 *this, IDirect3DRMMeshBuilder *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddMeshBuilder(real_this, from_IDirect3DRMMeshBuilder(a), 0);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_AddFrame(IDirect3DRMMeshBuilder2 *this, IDirect3DRMFrame *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddFrame(real_this, from_IDirect3DRMFrame(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_AddFace(IDirect3DRMMeshBuilder2 *this, IDirect3DRMFace *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddFace(real_this, from_IDirect3DRMFace(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_AddFaces(IDirect3DRMMeshBuilder2 *this, DWORD a, D3DVECTOR *b, DWORD c, D3DVECTOR *d, DWORD *e, struct IDirect3DRMFaceArray **f) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddFaces(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_ReserveSpace(IDirect3DRMMeshBuilder2 *this, DWORD a, DWORD b, DWORD c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_ReserveSpace(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetColorRGB(IDirect3DRMMeshBuilder2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetColorRGB(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetColor(IDirect3DRMMeshBuilder2 *this, D3DCOLOR a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetTexture(IDirect3DRMMeshBuilder2 *this, struct IDirect3DRMTexture *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetTexture(real_this, from_IDirect3DRMTexture(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetMaterial(IDirect3DRMMeshBuilder2 *this, struct IDirect3DRMMaterial *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetMaterial(real_this, from_IDirect3DRMMaterial(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetTextureTopology(IDirect3DRMMeshBuilder2 *this, BOOL a, BOOL b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetTextureTopology(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetQuality(IDirect3DRMMeshBuilder2 *this, D3DRMRENDERQUALITY a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetQuality(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetPerspective(IDirect3DRMMeshBuilder2 *this, BOOL a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetPerspective(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetVertex(IDirect3DRMMeshBuilder2 *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetVertex(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetNormal(IDirect3DRMMeshBuilder2 *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetNormal(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetTextureCoordinates(IDirect3DRMMeshBuilder2 *this, DWORD a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetTextureCoordinates(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetVertexColor(IDirect3DRMMeshBuilder2 *this, DWORD a, D3DCOLOR b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetVertexColor(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_SetVertexColorRGB(IDirect3DRMMeshBuilder2 *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_SetVertexColorRGB(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GetFaces(IDirect3DRMMeshBuilder2 *this, struct IDirect3DRMFaceArray **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetFaces(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GetVertices(IDirect3DRMMeshBuilder2 *this, DWORD *a, D3DVECTOR *b, DWORD *c, D3DVECTOR *d, DWORD *e, DWORD *f) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetAllVertices(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GetTextureCoordinates(IDirect3DRMMeshBuilder2 *this, DWORD a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetTextureCoordinates(real_this, a, b, c);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder2_AddVertex(IDirect3DRMMeshBuilder2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddVertex(real_this, a, b, c);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder2_AddNormal(IDirect3DRMMeshBuilder2 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_AddNormal(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_CreateFace(IDirect3DRMMeshBuilder2 *this, IDirect3DRMFace **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    SDL_Direct3DRMFace *face;
    HRESULT res = SDL_Direct3DRMMeshBuilder_CreateFace(real_this, &face);
    if (a) {
        *a = &face->interface_IDirect3DRMFace;
    }
    return res;
}

static D3DRMRENDERQUALITY STDCALL SDL_IDirect3DRMMeshBuilder2_GetQuality(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetQuality(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMMeshBuilder2_GetPerspective(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetPerspective(real_this);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder2_GetFaceCount(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetFaceCount(real_this);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder2_GetVertexCount(IDirect3DRMMeshBuilder2 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetVertexCount(real_this);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMMeshBuilder2_GetVertexColor(IDirect3DRMMeshBuilder2 *this, DWORD a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GetVertexColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_CreateMesh(IDirect3DRMMeshBuilder2 *this, IDirect3DRMMesh **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_CreateMesh(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GenerateNormals2(IDirect3DRMMeshBuilder2 *this, D3DVALUE a, DWORD b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    return SDL_Direct3DRMMeshBuilder_GenerateNormalsFromCreaseAngle(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder2_GetFace(IDirect3DRMMeshBuilder2 *this, DWORD a, IDirect3DRMFace **b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder2(this);
    SDL_Direct3DRMFace *face = NULL;
    HRESULT res = SDL_Direct3DRMMeshBuilder_GetFace(real_this, a, &face);
    if (b) {
        *b = &face->interface_IDirect3DRMFace;
    }
    return res;
}

static IDirect3DRMMeshBuilder2Vtbl SDL_IDirect3DRMMeshBuilder2_Vtable = {
    SDL_IDirect3DRMMeshBuilder2_QueryInterface,
    SDL_IDirect3DRMMeshBuilder2_AddRef,
    SDL_IDirect3DRMMeshBuilder2_Release,
    SDL_IDirect3DRMMeshBuilder2_Clone,
    SDL_IDirect3DRMMeshBuilder2_AddDestroyCallback,
    SDL_IDirect3DRMMeshBuilder2_DeleteDestroyCallback,
    SDL_IDirect3DRMMeshBuilder2_SetAppData,
    SDL_IDirect3DRMMeshBuilder2_GetAppData,
    SDL_IDirect3DRMMeshBuilder2_SetName,
    SDL_IDirect3DRMMeshBuilder2_GetName,
    SDL_IDirect3DRMMeshBuilder2_GetClassName,
    SDL_IDirect3DRMMeshBuilder2_Load,
    SDL_IDirect3DRMMeshBuilder2_Save,
    SDL_IDirect3DRMMeshBuilder2_Scale,
    SDL_IDirect3DRMMeshBuilder2_Translate,
    SDL_IDirect3DRMMeshBuilder2_SetColorSource,
    SDL_IDirect3DRMMeshBuilder2_GetBox,
    SDL_IDirect3DRMMeshBuilder2_GenerateNormals,
    SDL_IDirect3DRMMeshBuilder2_GetColorSource,
    SDL_IDirect3DRMMeshBuilder2_AddMesh,
    SDL_IDirect3DRMMeshBuilder2_AddMeshBuilder,
    SDL_IDirect3DRMMeshBuilder2_AddFrame,
    SDL_IDirect3DRMMeshBuilder2_AddFace,
    SDL_IDirect3DRMMeshBuilder2_AddFaces,
    SDL_IDirect3DRMMeshBuilder2_ReserveSpace,
    SDL_IDirect3DRMMeshBuilder2_SetColorRGB,
    SDL_IDirect3DRMMeshBuilder2_SetColor,
    SDL_IDirect3DRMMeshBuilder2_SetTexture,
    SDL_IDirect3DRMMeshBuilder2_SetMaterial,
    SDL_IDirect3DRMMeshBuilder2_SetTextureTopology,
    SDL_IDirect3DRMMeshBuilder2_SetQuality,
    SDL_IDirect3DRMMeshBuilder2_SetPerspective,
    SDL_IDirect3DRMMeshBuilder2_SetVertex,
    SDL_IDirect3DRMMeshBuilder2_SetNormal,
    SDL_IDirect3DRMMeshBuilder2_SetTextureCoordinates,
    SDL_IDirect3DRMMeshBuilder2_SetVertexColor,
    SDL_IDirect3DRMMeshBuilder2_SetVertexColorRGB,
    SDL_IDirect3DRMMeshBuilder2_GetFaces,
    SDL_IDirect3DRMMeshBuilder2_GetVertices,
    SDL_IDirect3DRMMeshBuilder2_GetTextureCoordinates,
    SDL_IDirect3DRMMeshBuilder2_AddVertex,
    SDL_IDirect3DRMMeshBuilder2_AddNormal,
    SDL_IDirect3DRMMeshBuilder2_CreateFace,
    SDL_IDirect3DRMMeshBuilder2_GetQuality,
    SDL_IDirect3DRMMeshBuilder2_GetPerspective,
    SDL_IDirect3DRMMeshBuilder2_GetFaceCount,
    SDL_IDirect3DRMMeshBuilder2_GetVertexCount,
    SDL_IDirect3DRMMeshBuilder2_GetVertexColor,
    SDL_IDirect3DRMMeshBuilder2_CreateMesh,
    SDL_IDirect3DRMMeshBuilder2_GenerateNormals2,
    SDL_IDirect3DRMMeshBuilder2_GetFace,
};

// IDirect3DRMMeshBuilder3 interface

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_QueryInterface(IDirect3DRMMeshBuilder3 *this, REFIID a, void **b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_QueryInterface(real_this, a, b);
}

static ULONG STDCALL SDL_IDirect3DRMMeshBuilder3_AddRef(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddRef(real_this);
}

static ULONG STDCALL SDL_IDirect3DRMMeshBuilder3_Release(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Release(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Clone(IDirect3DRMMeshBuilder3 *this, IUnknown *a, REFIID b, void **c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Clone(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddDestroyCallback(IDirect3DRMMeshBuilder3 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_DeleteDestroyCallback(IDirect3DRMMeshBuilder3 *this, D3DRMOBJECTCALLBACK a, void *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_DeleteDestroyCallback(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetAppData(IDirect3DRMMeshBuilder3 *this, LPVOID a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetAppData(real_this, a);
}

static LPVOID STDCALL SDL_IDirect3DRMMeshBuilder3_GetAppData(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetAppData(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetName(IDirect3DRMMeshBuilder3 *this, const char *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetName(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetName(IDirect3DRMMeshBuilder3 *this, DWORD *a, char *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetClassName(IDirect3DRMMeshBuilder3 *this, DWORD *a, char *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetClassName(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Load(IDirect3DRMMeshBuilder3 *this, void *a, void *b, D3DRMLOADOPTIONS c, D3DRMLOADTEXTURE3CALLBACK d, void *e) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    LoadTextureAdapterCallbackData load_texture_callback_storage;
    adapt_D3DRMLOADTEXTURE3CALLBACK(&load_texture_callback_storage, d, e);
    return SDL_Direct3DRMMeshBuilder_Load(real_this, a, b, c, &load_texture_callback_storage);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Save(IDirect3DRMMeshBuilder3 *this, const char *a, D3DRMXOFFORMAT b, D3DRMSAVEOPTIONS c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Save(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Scale(IDirect3DRMMeshBuilder3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Scale(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Translate(IDirect3DRMMeshBuilder3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Translate(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetColorSource(IDirect3DRMMeshBuilder3 *this, D3DRMCOLORSOURCE a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetColorSource(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetBox(IDirect3DRMMeshBuilder3 *this, D3DRMBOX *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetBox(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GenerateNormals(IDirect3DRMMeshBuilder3 *this, D3DVALUE dvCreaseAngle, DWORD dwFlags) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GenerateNormalsFromCreaseAngle(real_this, dvCreaseAngle, dwFlags);
}

static D3DRMCOLORSOURCE STDCALL SDL_IDirect3DRMMeshBuilder3_GetColorSource(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetColorSource(real_this);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddMesh(IDirect3DRMMeshBuilder3 *this, IDirect3DRMMesh *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddMesh(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddMeshBuilder(IDirect3DRMMeshBuilder3 *this, IDirect3DRMMeshBuilder3 *a, DWORD b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddMeshBuilder(real_this, from_IDirect3DRMMeshBuilder3(a), b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddFrame(IDirect3DRMMeshBuilder3 *this, IDirect3DRMFrame3 *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddFrame(real_this, from_IDirect3DRMFrame3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddFace(IDirect3DRMMeshBuilder3 *this, IDirect3DRMFace2 *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddFace(real_this, from_IDirect3DRMFace2(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddFaces(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVECTOR *b, DWORD c, D3DVECTOR *d, DWORD *e, struct IDirect3DRMFaceArray **f) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddFaces(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_ReserveSpace(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD b, DWORD c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_ReserveSpace(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetColorRGB(IDirect3DRMMeshBuilder3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetColorRGB(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetColor(IDirect3DRMMeshBuilder3 *this, D3DCOLOR a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetTexture(IDirect3DRMMeshBuilder3 *this, struct IDirect3DRMTexture3 *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetTexture(real_this, from_IDirect3DRMTexture3(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetMaterial(IDirect3DRMMeshBuilder3 *this, struct IDirect3DRMMaterial2 *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetMaterial(real_this, from_IDirect3DRMMaterial2(a));
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetTextureTopology(IDirect3DRMMeshBuilder3 *this, BOOL a, BOOL b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetTextureTopology(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetQuality(IDirect3DRMMeshBuilder3 *this, D3DRMRENDERQUALITY a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetQuality(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetPerspective(IDirect3DRMMeshBuilder3 *this, BOOL a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetPerspective(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetVertex(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetVertex(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetNormal(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetNormal(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetTextureCoordinates(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetTextureCoordinates(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetVertexColor(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DCOLOR b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetVertexColor(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetVertexColorRGB(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVALUE b, D3DVALUE c, D3DVALUE d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetVertexColorRGB(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetFaces(IDirect3DRMMeshBuilder3 *this, struct IDirect3DRMFaceArray **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetFaces(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetGeometry(IDirect3DRMMeshBuilder3 *this, DWORD *a, D3DVECTOR *b, DWORD *c, D3DVECTOR *d, DWORD *e, DWORD *f) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetGeometry(real_this, a, b, c, d, e, f);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetTextureCoordinates(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVALUE *b, D3DVALUE *c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetTextureCoordinates(real_this, a, b, c);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder3_AddVertex(IDirect3DRMMeshBuilder3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddVertex(real_this, a, b, c);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder3_AddNormal(IDirect3DRMMeshBuilder3 *this, D3DVALUE a, D3DVALUE b, D3DVALUE c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddNormal(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_CreateFace(IDirect3DRMMeshBuilder3 *this, IDirect3DRMFace2 **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    SDL_Direct3DRMFace *face;
    HRESULT res = SDL_Direct3DRMMeshBuilder_CreateFace(real_this, &face);
    if (a) {
        *a = &face->interface_IDirect3DRMFace2;
    }
    return res;
}

static D3DRMRENDERQUALITY STDCALL SDL_IDirect3DRMMeshBuilder3_GetQuality(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetQuality(real_this);
}

static BOOL STDCALL SDL_IDirect3DRMMeshBuilder3_GetPerspective(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetPerspective(real_this);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder3_GetFaceCount(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetFaceCount(real_this);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder3_GetVertexCount(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetVertexCount(real_this);
}

static D3DCOLOR STDCALL SDL_IDirect3DRMMeshBuilder3_GetVertexColor(IDirect3DRMMeshBuilder3 *this, DWORD a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetVertexColor(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_CreateMesh(IDirect3DRMMeshBuilder3 *this, IDirect3DRMMesh **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_CreateMesh(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetFace(IDirect3DRMMeshBuilder3 *this, DWORD a, IDirect3DRMFace2 **b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    SDL_Direct3DRMFace *face = NULL;
    HRESULT res = SDL_Direct3DRMMeshBuilder_GetFace(real_this, a, &face);
    if (b) {
        *b = &face->interface_IDirect3DRMFace2;
    }
    return res;
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetVertex(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVECTOR *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetVertex(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetNormal(IDirect3DRMMeshBuilder3 *this, DWORD a, D3DVECTOR *b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetNormal(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_DeleteVertices(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_DeleteVertices(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_DeleteNormals(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_DeleteNormals(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_DeleteFace(IDirect3DRMMeshBuilder3 *this, IDirect3DRMFace2 *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_DeleteFace(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Empty(IDirect3DRMMeshBuilder3 *this, DWORD a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Empty(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Optimize(IDirect3DRMMeshBuilder3 *this, DWORD a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Optimize(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddFacesIndexed(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD *b, DWORD *c, DWORD *d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddFacesIndexed(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_CreateSubMesh(IDirect3DRMMeshBuilder3 *this, IUnknown **a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_CreateSubMesh(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetParentMesh(IDirect3DRMMeshBuilder3 *this, DWORD a, IUnknown **b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetParentMesh(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetSubMeshes(IDirect3DRMMeshBuilder3 *this, DWORD *a, IUnknown **b) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetSubMeshes(real_this, a, b);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_DeleteSubMesh(IDirect3DRMMeshBuilder3 *this, IUnknown *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_DeleteSubMesh(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_Enable(IDirect3DRMMeshBuilder3 *this, DWORD a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_Enable(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetEnable(IDirect3DRMMeshBuilder3 *this, DWORD *a) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetEnable(real_this, a);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_AddTriangles(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD b, DWORD c, void *d) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_AddTriangles(real_this, a, b, c, d);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetVertices(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD b, D3DVECTOR *c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetVertices(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetVertices(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD *b, D3DVECTOR *c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetVertices(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_SetNormals(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD b, D3DVECTOR *c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_SetNormals(real_this, a, b, c);
}

static HRESULT STDCALL SDL_IDirect3DRMMeshBuilder3_GetNormals(IDirect3DRMMeshBuilder3 *this, DWORD a, DWORD *b, D3DVECTOR *c) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetNormals(real_this, a, b, c);
}

static int STDCALL SDL_IDirect3DRMMeshBuilder3_GetNormalCount(IDirect3DRMMeshBuilder3 *this) {
    Direct3DRMMeshBuilder *real_this = from_IDirect3DRMMeshBuilder3(this);
    return SDL_Direct3DRMMeshBuilder_GetNormalCount(real_this);
}

static IDirect3DRMMeshBuilder3Vtbl SDL_IDirect3DRMMeshBuilder3_Vtable = {
    SDL_IDirect3DRMMeshBuilder3_QueryInterface,
    SDL_IDirect3DRMMeshBuilder3_AddRef,
    SDL_IDirect3DRMMeshBuilder3_Release,
    SDL_IDirect3DRMMeshBuilder3_Clone,
    SDL_IDirect3DRMMeshBuilder3_AddDestroyCallback,
    SDL_IDirect3DRMMeshBuilder3_DeleteDestroyCallback,
    SDL_IDirect3DRMMeshBuilder3_SetAppData,
    SDL_IDirect3DRMMeshBuilder3_GetAppData,
    SDL_IDirect3DRMMeshBuilder3_SetName,
    SDL_IDirect3DRMMeshBuilder3_GetName,
    SDL_IDirect3DRMMeshBuilder3_GetClassName,
    SDL_IDirect3DRMMeshBuilder3_Load,
    SDL_IDirect3DRMMeshBuilder3_Save,
    SDL_IDirect3DRMMeshBuilder3_Scale,
    SDL_IDirect3DRMMeshBuilder3_Translate,
    SDL_IDirect3DRMMeshBuilder3_SetColorSource,
    SDL_IDirect3DRMMeshBuilder3_GetBox,
    SDL_IDirect3DRMMeshBuilder3_GenerateNormals,
    SDL_IDirect3DRMMeshBuilder3_GetColorSource,
    SDL_IDirect3DRMMeshBuilder3_AddMesh,
    SDL_IDirect3DRMMeshBuilder3_AddMeshBuilder,
    SDL_IDirect3DRMMeshBuilder3_AddFrame,
    SDL_IDirect3DRMMeshBuilder3_AddFace,
    SDL_IDirect3DRMMeshBuilder3_AddFaces,
    SDL_IDirect3DRMMeshBuilder3_ReserveSpace,
    SDL_IDirect3DRMMeshBuilder3_SetColorRGB,
    SDL_IDirect3DRMMeshBuilder3_SetColor,
    SDL_IDirect3DRMMeshBuilder3_SetTexture,
    SDL_IDirect3DRMMeshBuilder3_SetMaterial,
    SDL_IDirect3DRMMeshBuilder3_SetTextureTopology,
    SDL_IDirect3DRMMeshBuilder3_SetQuality,
    SDL_IDirect3DRMMeshBuilder3_SetPerspective,
    SDL_IDirect3DRMMeshBuilder3_SetVertex,
    SDL_IDirect3DRMMeshBuilder3_SetNormal,
    SDL_IDirect3DRMMeshBuilder3_SetTextureCoordinates,
    SDL_IDirect3DRMMeshBuilder3_SetVertexColor,
    SDL_IDirect3DRMMeshBuilder3_SetVertexColorRGB,
    SDL_IDirect3DRMMeshBuilder3_GetFaces,
    SDL_IDirect3DRMMeshBuilder3_GetGeometry,
    SDL_IDirect3DRMMeshBuilder3_GetTextureCoordinates,
    SDL_IDirect3DRMMeshBuilder3_AddVertex,
    SDL_IDirect3DRMMeshBuilder3_AddNormal,
    SDL_IDirect3DRMMeshBuilder3_CreateFace,
    SDL_IDirect3DRMMeshBuilder3_GetQuality,
    SDL_IDirect3DRMMeshBuilder3_GetPerspective,
    SDL_IDirect3DRMMeshBuilder3_GetFaceCount,
    SDL_IDirect3DRMMeshBuilder3_GetVertexCount,
    SDL_IDirect3DRMMeshBuilder3_GetVertexColor,
    SDL_IDirect3DRMMeshBuilder3_CreateMesh,
    SDL_IDirect3DRMMeshBuilder3_GetFace,
    SDL_IDirect3DRMMeshBuilder3_GetVertex,
    SDL_IDirect3DRMMeshBuilder3_GetNormal,
    SDL_IDirect3DRMMeshBuilder3_DeleteVertices,
    SDL_IDirect3DRMMeshBuilder3_DeleteNormals,
    SDL_IDirect3DRMMeshBuilder3_DeleteFace,
    SDL_IDirect3DRMMeshBuilder3_Empty,
    SDL_IDirect3DRMMeshBuilder3_Optimize,
    SDL_IDirect3DRMMeshBuilder3_AddFacesIndexed,
    SDL_IDirect3DRMMeshBuilder3_CreateSubMesh,
    SDL_IDirect3DRMMeshBuilder3_GetParentMesh,
    SDL_IDirect3DRMMeshBuilder3_GetSubMeshes,
    SDL_IDirect3DRMMeshBuilder3_DeleteSubMesh,
    SDL_IDirect3DRMMeshBuilder3_Enable,
    SDL_IDirect3DRMMeshBuilder3_GetEnable,
    SDL_IDirect3DRMMeshBuilder3_AddTriangles,
    SDL_IDirect3DRMMeshBuilder3_SetVertices,
    SDL_IDirect3DRMMeshBuilder3_GetVertices,
    SDL_IDirect3DRMMeshBuilder3_SetNormals,
    SDL_IDirect3DRMMeshBuilder3_GetNormals,
    SDL_IDirect3DRMMeshBuilder3_GetNormalCount,
};

Direct3DRMMeshBuilder *SDL_CreateD3DRMMeshBuilder(void) {
    HRESULT hr;
    Direct3DRMMeshBuilder *this = (Direct3DRMMeshBuilder *) SDL_calloc(1, sizeof(Direct3DRMMeshBuilder));
    if (this == NULL) {
        return NULL;
    }
    this->interface_IDirect3DRMMeshBuilder.lpVtbl = &SDL_IDirect3DRMMeshBuilder_Vtable;
    this->interface_IDirect3DRMMeshBuilder2.lpVtbl = &SDL_IDirect3DRMMeshBuilder2_Vtable;
    this->interface_IDirect3DRMMeshBuilder3.lpVtbl = &SDL_IDirect3DRMMeshBuilder3_Vtable;

    hr = DirectXFileCreate(&this->xfile);
    if (FAILED(hr)) {
        goto failure;
    }

    hr = IDirectXFile_RegisterTemplates(this->xfile, (LPVOID)D3DRM_XTEMPLATES, D3DRM_XTEMPLATE_BYTES);
    if (FAILED(hr)) {
        goto failure;
    }

    return this;
failure:
    IDirectXFile_Release(this->xfile);
    SDL_free(this);
    return NULL;
}
