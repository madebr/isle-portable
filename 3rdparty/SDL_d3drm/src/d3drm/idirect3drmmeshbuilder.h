#ifndef IDIRECT3DRMMESHBUILDER_H
#define IDIRECT3DRMMESHBUILDER_H

#include "d3drm.h"
#include "dxfile.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMMeshBuilder interface_IDirect3DRMMeshBuilder;
    };
    IDirect3DRMMeshBuilder2 interface_IDirect3DRMMeshBuilder2;
    IDirect3DRMMeshBuilder3 interface_IDirect3DRMMeshBuilder3;
    SDL_AtomicInt ref_count;
    IDirectXFile *xfile;
} Direct3DRMMeshBuilder;

static inline Direct3DRMMeshBuilder *from_IDirect3DRMMeshBuilder(IDirect3DRMMeshBuilder *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMMeshBuilder *)((uintptr_t) frame - offsetof(Direct3DRMMeshBuilder, interface_IDirect3DRMMeshBuilder));
}

static inline Direct3DRMMeshBuilder *from_IDirect3DRMMeshBuilder2(IDirect3DRMMeshBuilder2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMMeshBuilder *)((uintptr_t) frame - offsetof(Direct3DRMMeshBuilder, interface_IDirect3DRMMeshBuilder2));
}

static inline Direct3DRMMeshBuilder *from_IDirect3DRMMeshBuilder3(IDirect3DRMMeshBuilder3 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMMeshBuilder *)((uintptr_t) frame - offsetof(Direct3DRMMeshBuilder, interface_IDirect3DRMMeshBuilder3));
}

extern Direct3DRMMeshBuilder *SDL_CreateD3DRMMeshBuilder(void);

#endif // IDIRECT3DRMMESHBUILDER_H
