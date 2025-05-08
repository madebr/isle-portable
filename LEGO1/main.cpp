#ifdef _WIN32
#include <windows.h>

// FUNCTION: LEGO1 0x10091ee0
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved)
{
	return TRUE;
}
#endif

#define INITGUID
#include <d3drm.h>
#include <d3drmwin.h>
#include <ddraw.h>
