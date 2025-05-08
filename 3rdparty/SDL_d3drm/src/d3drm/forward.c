#define ENV_VARIABLE "D3DRM_PATH"
#define WIN_DLL "SDL3_d3drm.dll"
#define APPLE_DYLIB "libSDL3_d3drm.dylib"
#define UNIX_SO "libSDL3_d3drm.so"

#ifdef _WIN32
#include <windows.h>
#define DECLSPEC __stdcall
#else
#define DECLSPEC
typedef unsigned int HRESULT;
#endif

typedef unsigned int D3DCOLOR;
typedef float D3DVALUE;
typedef D3DVALUE D3DRMMATRIX4D[4][4];
typedef struct _D3DVECTOR D3DVECTOR;
typedef struct _D3DRMQUATERNION D3DRMQUATERNION;

#define FOREACH_EXPORTED_FUNCTION(X) \
    X(D3DRMColorGetAlpha,D3DVALUE,(D3DCOLOR a),(a),return) \
    X(D3DRMColorGetBlue,D3DVALUE,(D3DCOLOR a),(a),return) \
    X(D3DRMColorGetGreen,D3DVALUE,(D3DCOLOR a),(a),return) \
    X(D3DRMColorGetRed,D3DVALUE,(D3DCOLOR a),(a),return) \
    X(D3DRMCreateColorRGB,D3DCOLOR,(D3DVALUE a,D3DVALUE b,D3DVALUE c),(a,b,c),return) \
    X(D3DRMCreateColorRGBA,D3DCOLOR,(D3DVALUE a,D3DVALUE b,D3DVALUE c,D3DVALUE d),(a,b,c,d),return) \
    X(D3DRMMatrixFromQuaternion,void,(D3DRMMATRIX4D a, D3DRMQUATERNION *b),(a,b),) \
    X(D3DRMQuaternionFromRotation,D3DRMQUATERNION*,(D3DRMQUATERNION*a, D3DVECTOR*b, D3DVALUE c),(a,b,c),return) \
    X(D3DRMQuaternionMultiply,D3DRMQUATERNION*,(D3DRMQUATERNION*a, D3DRMQUATERNION*b, D3DRMQUATERNION*c),(a,b,c),return) \
    X(D3DRMQuaternionSlerp,D3DRMQUATERNION*,(D3DRMQUATERNION*a,D3DRMQUATERNION*b,D3DRMQUATERNION*c,D3DVALUE d),(a,b,c,d),return) \
    X(D3DRMVectorAdd,D3DVECTOR*,(D3DVECTOR*a,D3DVECTOR*b,D3DVECTOR*c),(a,b,c),return) \
    X(D3DRMVectorCrossProduct,D3DVECTOR*,(D3DVECTOR*a,D3DVECTOR*b,D3DVECTOR*c),(a,b,c),return) \
    X(D3DRMVectorDotProduct,D3DVALUE,(D3DVECTOR*a,D3DVECTOR*b),(a,b),return) \
    X(D3DRMVectorModulus,D3DVALUE,(D3DVECTOR*a),(a),return) \
    X(D3DRMVectorNormalize,D3DVECTOR*,(D3DVECTOR*a),(a),return) \
    X(D3DRMVectorRandom,D3DVECTOR*,(D3DVECTOR*a),(a),return) \
    X(D3DRMVectorReflect,D3DVECTOR*,(D3DVECTOR*a,D3DVECTOR*b,D3DVECTOR*c),(a,b,c),return) \
    X(D3DRMVectorRotate,D3DVECTOR*,(D3DVECTOR*a,D3DVECTOR*b,D3DVECTOR*c,D3DVALUE d),(a,b,c,d),return) \
    X(D3DRMVectorScale,D3DVECTOR*,(D3DVECTOR*a,D3DVECTOR*b,D3DVALUE c),(a,b,c),return) \
    X(D3DRMVectorSubtract,D3DVECTOR*,(D3DVECTOR*a,D3DVECTOR*b,D3DVECTOR*c),(a,b,c),return) \
    X(Direct3DRMCreate,HRESULT,(void**a),(a),return)

#include "common/common_forward.h"
