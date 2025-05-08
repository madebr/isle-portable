#include <stdlib.h>
#ifdef _WIN32
#include <windows.h>
typedef HMODULE LIBRARY;
static LIBRARY load_library(const char *name) {
    return LoadLibraryA(name);
}
static void fatal_error(const char *title, const char *message) {
    OutputDebugStringA("Fatal Error [");
    OutputDebugStringA(title);
    OutputDebugStringA("] ");
    OutputDebugStringA(message);
    OutputDebugStringA("\n");
    MessageBoxA(NULL, message, title, MB_ICONERROR);
    ExitProcess(1);
}
void *get_library_symbol(LIBRARY library, const char *name) {
    void *symbol = GetProcAddress(library, name);
    if (symbol == NULL) {
        fatal_error("Symbol not found", name);
    }
    return symbol;
}
static void unload_library(LIBRARY library) {
    FreeLibrary(library);
}
static const char *get_platform_env_variable(const char *n) {
    static char buffer[MAX_PATH];
    if (!GetEnvironmentVariable(n, buffer, sizeof(buffer))) {
        return NULL;
    }
    buffer[sizeof(buffer) - 1] = '\0';
    return buffer;
}
#define EXPORT extern //__declspec(dllexport)
#else
#include <dlfcn.h>
#include <stdio.h>
typedef void *LIBRARY;
static void fatal_error(const char *title, const char *message) {
    fprintf(stderr, "%s: %s\n", title, message);
    abort();
    exit(1);
}
static LIBRARY load_library(const char *name) {
    LIBRARY lib = dlopen(name, RTLD_NOW);
    if (lib == NULL) {
        fatal_error("Failed to load library", name);
    }
    return lib;
}
void *get_library_symbol(LIBRARY library, const char *name) {
    void *symbol = dlsym(library, name);
    if (symbol == NULL) {
        fatal_error("Symbol not found", name);
        exit(1);
    }
    return symbol;
}
static void unload_library(LIBRARY library) {
    dlclose(library);
}
static const char *get_platform_env_variable(const char *n) {
    return getenv(n);
}
#define EXPORT extern
#endif

static const char *get_library_name(void) {
    const char *n = get_platform_env_variable(ENV_VARIABLE);
    if (n != NULL) {
        return n;
    }
#ifdef _WIN32
    return WIN_DLL;
#elif defined(__APPLE__)
    return APPLE_DYLIB;
#else
    return UNIX_SO;
#endif
}

#define X_SYMBOL(NAME,RET,ARGS,CALL,RETURN) \
    static RET (DECLSPEC * s_##NAME ) ARGS;

#define X_FORWARD(NAME,RET,ARGS,CALL,RETURN) \
    EXPORT RET DECLSPEC NAME ARGS;   \
    RET DECLSPEC NAME ARGS {  \
        RETURN s_##NAME CALL;  \
    }

#define X_LOAD(NAME,RET,ARGS,CALL,RETURN) \
    s_##NAME = (RET (DECLSPEC * )ARGS) get_library_symbol(s_library, #NAME); \
    if (s_##NAME == NAME) {               \
        fatal_error("Cannot load myself", "This will lead to infinite recursion"); \
    }

#define X_UNLOAD(NAME,RET,ARGS,CALL,RETURN) \
    s_##NAME = NULL;

static LIBRARY s_library;
FOREACH_EXPORTED_FUNCTION(X_SYMBOL)
FOREACH_EXPORTED_FUNCTION(X_FORWARD)

#ifndef _WIN32
static void load_symbols(void) __attribute__ ((constructor));
#endif
static void load_symbols(void) {
    if (s_library) {
        fatal_error("Cannot load library twice", "");
    }
    const char *library_name = get_library_name();
    s_library = load_library(library_name);
    FOREACH_EXPORTED_FUNCTION(X_LOAD)
}
#ifndef _WIN32
static void unload_symbols(void) __attribute__ ((destructor));
#endif
static void unload_symbols(void) {
    unload_library(s_library);
    s_library = NULL;
}

#ifdef _WIN32
BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpvReserved) {
    (void) hinstDLL;
    (void) lpvReserved;
    switch (fdwReason) {
        case DLL_PROCESS_ATTACH:
            load_symbols();
            break;
        case DLL_PROCESS_DETACH:
            unload_symbols();
            break;
        case DLL_THREAD_ATTACH:
            break;
        case DLL_THREAD_DETACH:
            break;
    }
    return TRUE;
}
#endif
