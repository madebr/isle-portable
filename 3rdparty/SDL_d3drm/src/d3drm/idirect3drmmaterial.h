#ifndef IDIRECT3DRMMATERIAL_H
#define IDIRECT3DRMMATERIAL_H

#include "d3drm.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMMaterial interface_IDirect3DRMMaterial;
    };
    IDirect3DRMMaterial2 interface_IDirect3DRMMaterial2;
    SDL_AtomicInt ref_count;
} Direct3DRMMaterial;

static inline Direct3DRMMaterial *from_IDirect3DRMMaterial(IDirect3DRMMaterial *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMMaterial *)((uintptr_t) frame - offsetof(Direct3DRMMaterial, interface_IDirect3DRMMaterial));
}

static inline Direct3DRMMaterial *from_IDirect3DRMMaterial2(IDirect3DRMMaterial2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMMaterial *)((uintptr_t) frame - offsetof(Direct3DRMMaterial, interface_IDirect3DRMMaterial2));
}

#endif // IDIRECT3DRMMATERIAL_H
