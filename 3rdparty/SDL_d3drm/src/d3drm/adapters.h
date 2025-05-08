#ifndef ADAPTERS_H
#define ADAPTERS_H

#include "idirect3drmframe.h"
#include "idirect3drmtexture.h"

typedef struct {
    enum {
        LOADTEXTURECALLBACK_VERSION1,
        LOADTEXTURECALLBACK_VERSION3,
    } type;
    union {
        D3DRMLOADTEXTURECALLBACK  callback1;
        D3DRMLOADTEXTURE3CALLBACK callback3;
    };
    void *arg;
} LoadTextureAdapterCallbackData;

static inline HRESULT CDECL LoadTextureAdapterCallback(char *tex_name, LoadTextureAdapterCallbackData *arg, Direct3DRMTexture **texture) {
    HRESULT res;
    switch (arg->type) {
    case LOADTEXTURECALLBACK_VERSION1:
        {
            IDirect3DRMTexture *interface_texture = NULL;
            res = arg->callback1(tex_name, arg->arg, &interface_texture);
            *texture = from_IDirect3DRMTexture(interface_texture);
        }
        break;
    case LOADTEXTURECALLBACK_VERSION3:
        {
            IDirect3DRMTexture3 *interface_texture = NULL;
            res = arg->callback3(tex_name, arg->arg, &interface_texture);
            *texture = from_IDirect3DRMTexture3(interface_texture);
        }
        break;
    default:
        *texture = NULL;
        res = E_FAIL;
        break;
    }
    return res;
}

static inline void adapt_D3DRMLOADTEXTURECALLBACK(LoadTextureAdapterCallbackData *storage, D3DRMLOADTEXTURECALLBACK loadProc, LPVOID lpArg) {
    storage->type = LOADTEXTURECALLBACK_VERSION1;
    storage->callback1 = loadProc;
    storage->arg = lpArg;
}

static inline void adapt_D3DRMLOADTEXTURE3CALLBACK(LoadTextureAdapterCallbackData *storage, D3DRMLOADTEXTURE3CALLBACK loadProc, LPVOID lpArg) {
    storage->type = LOADTEXTURECALLBACK_VERSION3;
    storage->callback3 = loadProc;
    storage->arg = lpArg;
}

typedef struct {
    enum {
        FRAMEMOVECALLBACK_VERSION1,
        FRAMEMOVECALLBACK_VERSION2,
        FRAMEMOVECALLBACK_VERSION3,
    } type;
    union {
        D3DRMFRAMEMOVECALLBACK  callback1;
        D3DRMFRAME2MOVECALLBACK callback2;
        D3DRMFRAME3MOVECALLBACK callback3;
    };
    void *arg;
} SDL_FrameMoveAdapterCallback;

static inline void CDECL FrameMoveAdapterCallback(Direct3DRMFrame *frame, SDL_FrameMoveAdapterCallback *arg, D3DVALUE delta) {
    switch (arg->type) {
    case FRAMEMOVECALLBACK_VERSION1:
        {
            arg->callback1(&frame->interface_IDirect3DRMFrame, arg->arg, delta);
        }
        break;
    case FRAMEMOVECALLBACK_VERSION2:
        {
            arg->callback2(&frame->interface_IDirect3DRMFrame2, arg->arg, delta);
        }
        break;
    case FRAMEMOVECALLBACK_VERSION3:
        {
            arg->callback3(&frame->interface_IDirect3DRMFrame3, arg->arg, delta);
        }
        break;
    default:
        break;
    }
}

static inline void adapt_D3DRMFRAMEMOVECALLBACK(SDL_FrameMoveAdapterCallback *storage, D3DRMFRAMEMOVECALLBACK loadProc, LPVOID lpArg) {
    storage->type = FRAMEMOVECALLBACK_VERSION1;
    storage->callback1 = loadProc;
    storage->arg = lpArg;
}

static inline void adapt_D3DRMFRAMEMOVECALLBACK2(SDL_FrameMoveAdapterCallback *storage, D3DRMFRAME2MOVECALLBACK loadProc, LPVOID lpArg) {
    storage->type = FRAMEMOVECALLBACK_VERSION2;
    storage->callback2 = loadProc;
    storage->arg = lpArg;
}

static inline void adapt_D3DRMFRAME3MOVECALLBACK(SDL_FrameMoveAdapterCallback *storage, D3DRMFRAME3MOVECALLBACK loadProc, LPVOID lpArg) {
    storage->type = FRAMEMOVECALLBACK_VERSION3;
    storage->callback3 = loadProc;
    storage->arg = lpArg;
}

#endif // ADAPTERS_H
