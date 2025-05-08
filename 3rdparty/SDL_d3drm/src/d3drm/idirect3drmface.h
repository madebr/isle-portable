#ifndef IDIRECT3DRMFACE_H
#define IDIRECT3DRMFACE_H

#include "d3drm.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMFace interface_IDirect3DRMFace;
    };
    IDirect3DRMFace2 interface_IDirect3DRMFace2;
    SDL_AtomicInt ref_count;
} SDL_Direct3DRMFace;

static inline SDL_Direct3DRMFace *from_IDirect3DRMFace(IDirect3DRMFace *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMFace *)((uintptr_t) frame - offsetof(SDL_Direct3DRMFace, interface_IDirect3DRMFace));
}

static inline SDL_Direct3DRMFace *from_IDirect3DRMFace2(IDirect3DRMFace2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMFace *)((uintptr_t) frame - offsetof(SDL_Direct3DRMFace, interface_IDirect3DRMFace2));
}

#endif // IDIRECT3DRMFACE_H
