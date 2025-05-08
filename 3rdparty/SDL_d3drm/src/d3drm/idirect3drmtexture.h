#ifndef IDIRECT3DRMTEXTURE_H
#define IDIRECT3DRMTEXTURE_H

#include "d3drm.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMTexture interface_IDirect3DRMTexture;
    };
    IDirect3DRMTexture2 interface_IDirect3DRMTexture2;
    IDirect3DRMTexture3 interface_IDirect3DRMTexture3;
    SDL_AtomicInt ref_count;
} Direct3DRMTexture;

static inline Direct3DRMTexture *from_IDirect3DRMTexture(IDirect3DRMTexture *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMTexture *)((uintptr_t) frame - offsetof(Direct3DRMTexture, interface_IDirect3DRMTexture));
}

static inline Direct3DRMTexture *from_IDirect3DRMTexture2(IDirect3DRMTexture2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMTexture *)((uintptr_t) frame - offsetof(Direct3DRMTexture, interface_IDirect3DRMTexture2));
}

static inline Direct3DRMTexture *from_IDirect3DRMTexture3(IDirect3DRMTexture3 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMTexture *)((uintptr_t) frame - offsetof(Direct3DRMTexture, interface_IDirect3DRMTexture3));
}

#endif // IDIRECT3DRMTEXTURE_H
