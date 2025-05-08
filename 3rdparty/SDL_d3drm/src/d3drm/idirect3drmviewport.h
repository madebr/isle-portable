#ifndef IDIRECT3DRMVIEWPORT_H
#define IDIRECT3DRMVIEWPORT_H

#include "d3drm.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMViewport interface_IDirect3DRMViewport;
    };
    IDirect3DRMViewport2 interface_IDirect3DRMViewport2;
    SDL_AtomicInt ref_count;
    int x;
    int y;
    int width;
    int height;
} SDL_Direct3DRMViewport;

static inline SDL_Direct3DRMViewport *from_IDirect3DRMViewport(IDirect3DRMViewport *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMViewport *)((uintptr_t) frame - offsetof(SDL_Direct3DRMViewport, interface_IDirect3DRMViewport));
}

static inline SDL_Direct3DRMViewport *from_IDirect3DRMViewport2(IDirect3DRMViewport2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMViewport *)((uintptr_t) frame - offsetof(SDL_Direct3DRMViewport, interface_IDirect3DRMViewport2));
}

extern SDL_Direct3DRMViewport *SDL_Allocate3DRMViewport(int x, int y, int width, int height);

#endif // IDIRECT3DRMVIEWPORT_H
