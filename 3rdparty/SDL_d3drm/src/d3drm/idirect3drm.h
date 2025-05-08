#ifndef IDIRECT3DRM_H
#define IDIRECT3DRM_H

#include "d3drm.h"

#include "common/common_list.h"

#include <stddef.h>

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRM interface_IDirect3DRM;
    };
    IDirect3DRM2 interface_IDirect3DRM2;
    IDirect3DRM3 interface_IDirect3DRM3;
    SDL_AtomicInt ref_count;
    common_linked_list *search_path;
} Direct3DRM;

static Direct3DRM *from_IDirect3DRM(IDirect3DRM *id3drm) {
    return (Direct3DRM *)((uintptr_t) id3drm - offsetof(Direct3DRM, interface_IDirect3DRM));
}

static Direct3DRM *from_IDirect3DRM2(IDirect3DRM2 *id3drm) {
    return (Direct3DRM *)((uintptr_t) id3drm - offsetof(Direct3DRM, interface_IDirect3DRM2));
}

static Direct3DRM *from_IDirect3DRM3(IDirect3DRM3 *id3drm) {
    return (Direct3DRM *)((uintptr_t) id3drm - offsetof(Direct3DRM, interface_IDirect3DRM3));
}

#endif // IDIRECT3DRM_H
