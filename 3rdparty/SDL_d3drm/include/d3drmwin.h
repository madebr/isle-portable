#ifndef D3DRMWIN_H
#define D3DRMWIN_H

#include "d3drm.h"

#include "ddraw.h"
#include "d3d.h"

DEFINE_GUID(IID_IDirect3DRMWinDevice,   0xc5016cc0, 0xd273, 0x11ce, 0xac, 0x48, 0x0, 0x0, 0xc0, 0x38, 0x25, 0xa1);

WIN_TYPES(IDirect3DRMWinDevice, DIRECT3DRMWINDEVICE);

#define INTERFACE IDirect3DRMWinDevice
DECLARE_INTERFACE_(IDirect3DRMWinDevice, IDirect3DRMObject)
{
        /*** IUnknown methods ***/
    /*0x00*/IUNKNOWN_METHODS(PURE);
        /*** IDirect3DRMObject methods ***/
    /*0x0c*/STDMETHOD(Clone)(THIS_ IUnknown *outer, REFIID iid, void **out) PURE;
    /*0x10*/STDMETHOD(AddDestroyCallback)(THIS_ D3DRMOBJECTCALLBACK cb, void *ctx) PURE;
    /*0x14*/STDMETHOD(DeleteDestroyCallback)(THIS_ D3DRMOBJECTCALLBACK cb, void *ctx) PURE;
    /*0x18*/STDMETHOD(SetAppData)(THIS_ LPVOID data) PURE;
    /*0x1c*/STDMETHOD_(LPVOID, GetAppData)(THIS) PURE;
    /*0x20*/STDMETHOD(SetName)(THIS_ const char *name) PURE;
    /*0x24*/STDMETHOD(GetName)(THIS_ DWORD *size, char *name) PURE;
    /*0x28*/STDMETHOD(GetClassName)(THIS_ DWORD *size, char *name) PURE;
        /*** IDirect3DRMWinDevice methods ***/
    /*0x2c*/STDMETHOD(HandlePaint)(THIS_ HDC hdc) PURE;
    /*0x30*/STDMETHOD(HandleActivate)(THIS_ WORD wparam) PURE;
};


#endif // D3DRMWIN_H
