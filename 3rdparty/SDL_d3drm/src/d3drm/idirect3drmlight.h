#ifndef IDIRECT3DRMLIGHT_H
#define IDIRECT3DRMLIGHT_H

#include "d3drm.h"

typedef struct {
    IDirect3DRMLight interface_IDirect3DRMLight;
    SDL_AtomicInt ref_count;
} SDL_Direct3DRMLight;

static inline SDL_Direct3DRMLight *from_IDirect3DRMLight(IDirect3DRMLight *light) {
    if (light == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMLight *)((uintptr_t) light - offsetof(SDL_Direct3DRMLight, interface_IDirect3DRMLight));
}

#endif // IDIRECT3DRMLIGHT_H
