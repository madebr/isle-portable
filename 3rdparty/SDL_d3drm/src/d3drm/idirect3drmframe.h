#ifndef IDIRECT3DRMFRAME_H
#define IDIRECT3DRMFRAME_H

#include "d3drm.h"

typedef struct Direct3DRMFrame {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMFrame interface_IDirect3DRMFrame;
    };
    IDirect3DRMFrame2 interface_IDirect3DRMFrame2;
    IDirect3DRMFrame3 interface_IDirect3DRMFrame3;
    SDL_AtomicInt ref_count;
    struct Direct3DRMFrame *parent;
} Direct3DRMFrame;

static inline Direct3DRMFrame *from_IDirect3DRMFrame(IDirect3DRMFrame *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMFrame *)((uintptr_t) frame - offsetof(Direct3DRMFrame, interface_IDirect3DRMFrame));
}

static inline Direct3DRMFrame *from_IDirect3DRMFrame2(IDirect3DRMFrame2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMFrame *)((uintptr_t) frame - offsetof(Direct3DRMFrame, interface_IDirect3DRMFrame2));
}

static inline Direct3DRMFrame *from_IDirect3DRMFrame3(IDirect3DRMFrame3 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (Direct3DRMFrame *)((uintptr_t) frame - offsetof(Direct3DRMFrame, interface_IDirect3DRMFrame3));
}

extern Direct3DRMFrame *SDL_CreateD3DRMFrame(Direct3DRMFrame *parent);

#endif // IDIRECT3DRMFRAME_H
