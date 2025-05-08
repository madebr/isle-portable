#ifndef IDIRECT3DRMANIMATION_H
#define IDIRECT3DRMANIMATION_H

#include "d3drm.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMAnimation interface_IDirect3DRMAnimation;
    };
    IDirect3DRMAnimation2 interface_IDirect3DRMAnimation2;
    SDL_AtomicInt ref_count;
} SDL_Direct3DRMAnimation;

static inline SDL_Direct3DRMAnimation *from_IDirect3DRMAnimation(IDirect3DRMAnimation *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMAnimation *)((uintptr_t) frame - offsetof(SDL_Direct3DRMAnimation, interface_IDirect3DRMAnimation));
}

static inline SDL_Direct3DRMAnimation *from_IDirect3DRMAnimation2(IDirect3DRMAnimation2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMAnimation *)((uintptr_t) frame - offsetof(SDL_Direct3DRMAnimation, interface_IDirect3DRMAnimation2));
}

#endif // IDIRECT3DRMANIMATION_H
