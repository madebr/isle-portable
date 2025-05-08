#ifndef IDIRECT3DRMDEVICE_H
#define IDIRECT3DRMDEVICE_H

#include "d3drm.h"

typedef struct {
    union {
        IUnknown interface_IUnknown;
        IDirect3DRMDevice interface_IDirect3DRMDevice;
    };
    IDirect3DRMDevice2 interface_IDirect3DRMDevice2;
    IDirect3DRMDevice3 interface_IDirect3DRMDevice3;
    SDL_AtomicInt ref_count;
    HWND hWnd;
    int width;
    int height;
} SDL_Direct3DRMDevice;

static inline SDL_Direct3DRMDevice *from_IDirect3DRMDevice(IDirect3DRMDevice *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMDevice *)((uintptr_t) frame - offsetof(SDL_Direct3DRMDevice, interface_IDirect3DRMDevice));
}

static inline SDL_Direct3DRMDevice *from_IDirect3DRMDevice2(IDirect3DRMDevice2 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMDevice *)((uintptr_t) frame - offsetof(SDL_Direct3DRMDevice, interface_IDirect3DRMDevice2));
}

static inline SDL_Direct3DRMDevice *from_IDirect3DRMDevice3(IDirect3DRMDevice3 *frame) {
    if (frame == NULL) {
        return NULL;
    }
    return (SDL_Direct3DRMDevice *)((uintptr_t) frame - offsetof(SDL_Direct3DRMDevice, interface_IDirect3DRMDevice3));
}

extern SDL_Direct3DRMDevice *SDL_CreateD3DRMDevice(void);

extern HRESULT SDL_Direct3DRMDevice_InitFromClipper(SDL_Direct3DRMDevice *this, IDirectDrawClipper *clipper, SDL_GUID *guid, int width, int height);

#endif // IDIRECT3DRMDEVICE_H
