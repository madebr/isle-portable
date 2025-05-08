#ifndef IDirect3DRMAnimationSetSET_H
#define IDirect3DRMAnimationSetSET_H

#include "d3drm.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMAnimationSet interface_IDirect3DRMAnimationSet;
    };
    IDirect3DRMAnimationSet2 interface_IDirect3DRMAnimationSet2;
    SDL_AtomicInt ref_count;
} SDL_Direct3DRMAnimationSet;

static inline SDL_Direct3DRMAnimationSet *from_IDirect3DRMAnimationSet(IDirect3DRMAnimationSet *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMAnimationSet *)((uintptr_t) frame - offsetof(SDL_Direct3DRMAnimationSet, interface_IDirect3DRMAnimationSet));
}

static inline SDL_Direct3DRMAnimationSet *from_IDirect3DRMAnimationSet2(IDirect3DRMAnimationSet2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMAnimationSet *)((uintptr_t) frame - offsetof(SDL_Direct3DRMAnimationSet, interface_IDirect3DRMAnimationSet2));
}

#endif // IDirect3DRMAnimationSetSET_H
