#ifndef IDIRECT3DRMVIVUALARRAY_H
#define IDIRECT3DRMVIVUALARRAY_H

#include "d3drm.h"

typedef struct {
    IDirect3DRMVisualArray interface_IDirect3DRMVisualArray;
    SDL_AtomicInt ref_count;
} SDL_Direct3DRMVisualArray;

static inline SDL_Direct3DRMVisualArray *from_IDirect3DRMVisualArray(IDirect3DRMVisualArray *array) {
    if (array == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMVisualArray *)((uintptr_t) array - offsetof(SDL_Direct3DRMVisualArray, interface_IDirect3DRMVisualArray));
}

#endif // IDIRECT3DRMVIVUALARRAY_H
