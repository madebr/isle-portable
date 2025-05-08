#ifndef DXFILE_H
#define DXFILE_H

#include "winglue.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef DWORD DXFILEFORMAT;

#define DXFILEFORMAT_BINARY     0
#define DXFILEFORMAT_TEXT       1
#define DXFILEFORMAT_COMPRESSED 2

typedef DWORD DXFILELOADOPTIONS;

#define DXFILELOAD_FROMFILE  0x00L
#define DXFILELOAD_FROMRESOURCE 0x01L
#define DXFILELOAD_FROMMEMORY 0x02L
#define DXFILELOAD_FROMSTREAM 0x04L
#define DXFILELOAD_FROMURL 0x08L

typedef struct _DXFILELOADRESOURCE {
    HMODULE HMODULE;
    LPCTSTR lpName;
    LPCTSTR lpType;
}DXFILELOADRESOURCE, *LPDXFILELOADRESOURCE;

typedef struct _DXFILELOADMEMORY {
    LPVOID lpMemory;
    DWORD dSize;
}DXFILELOADMEMORY, *LPDXFILELOADMEMORY;

/*
 * DirectX File object types.
 */

#ifndef WIN_TYPES
#define WIN_TYPES(itype, ptype) \
    typedef struct itype FAR *LP##ptype, FAR **LPLP##ptype
#endif

WIN_TYPES(IDirectXFile,                 DIRECTXFILE);
WIN_TYPES(IDirectXFileEnumObject,       DIRECTXFILEENUMOBJECT);
WIN_TYPES(IDirectXFileSaveObject,       DIRECTXFILESAVEOBJECT);
WIN_TYPES(IDirectXFileObject,           DIRECTXFILEOBJECT);
WIN_TYPES(IDirectXFileData,             DIRECTXFILEDATA);
WIN_TYPES(IDirectXFileDataReference,    DIRECTXFILEDATAREFERENCE);
WIN_TYPES(IDirectXFileBinary,           DIRECTXFILEBINARY);

/*
 * API for creating IDirectXFile interface.
 */

STDAPI DirectXFileCreate(LPDIRECTXFILE *lplpDirectXFile);

/*
 * The methods for IDirectXFileObject
 */

#define IDIRECTXFILEOBJECT_METHODS(kind) \
    STDMETHOD(GetName) (THIS_ LPSTR, LPDWORD) kind; \
    STDMETHOD(GetId) (THIS_ LPGUID) kind

/*
 * DirectX File interfaces.
 */

#define INTERFACE IDirectXFile
DECLARE_INTERFACE_(IDirectXFile, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    STDMETHOD(CreateEnumObject) (THIS_ LPVOID, DXFILELOADOPTIONS, LPDIRECTXFILEENUMOBJECT *) PURE;
    STDMETHOD(CreateSaveObject) (THIS_ LPCSTR, DXFILEFORMAT, LPDIRECTXFILESAVEOBJECT *) PURE;
    STDMETHOD(RegisterTemplates) (THIS_ LPVOID, DWORD) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectXFile_QueryInterface(ptr,a,b)            (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirectXFile_AddRef(ptr)                        (ptr)->lpVtbl->AddRef(ptr)
#define IDirectXFile_Release(ptr)                       (ptr)->lpVtbl->Release(ptr)
#define IDirectXFile_CreateEnumObject(ptr,a,b,c)        (ptr)->lpVtbl->CreateEnumObject(ptr,a,b,c)
#define IDirectXFile_CreateSaveObject(ptr,a,b,c)        (ptr)->lpVtbl->CreateSaveObject(ptr,a,b,c)
#define IDirectXFile_RegisterTemplates(ptr,a,b)         (ptr)->lpVtbl->RegisterTemplates(ptr,a,b)
#else
#define IDirectXFile_QueryInterface(ptr,a,b)            (ptr)->QueryInterface(ptr,a,b)
#define IDirectXFile_AddRef(ptr)                        (ptr)->AddRef(ptr)
#define IDirectXFile_Release(ptr)                       (ptr)->Release(ptr)
#define IDirectXFile_CreateEnumObject(ptr,a,b,c)        (ptr)->CreateEnumObject(ptr,a,b,c)
#define IDirectXFile_CreateSaveObject(ptr,a,b,c)        (ptr)->CreateSaveObject(ptr,a,b,c)
#define IDirectXFile_RegisterTemplates(ptr,a,b)         (ptr)->RegisterTemplates(ptr,a,b)
#endif

#define INTERFACE IDirectXFileEnumObject
DECLARE_INTERFACE_(IDirectXFileEnumObject, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    STDMETHOD(GetNextDataObject)    (THIS_ LPDIRECTXFILEDATA *) PURE;
    STDMETHOD(GetDataObjectById)    (THIS_ REFGUID, LPDIRECTXFILEDATA *) PURE;
    STDMETHOD(GetDataObjectByName)  (THIS_ LPCSTR, LPDIRECTXFILEDATA *) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectXFileEnumObject_QueryInterface(ptr,a,b)          (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirectXFileEnumObject_AddRef(ptr)                      (ptr)->lpVtbl->AddRef(ptr)
#define IDirectXFileEnumObject_Release(ptr)                     (ptr)->lpVtbl->Release(ptr)
#define IDirectXFileEnumObject_GetNextDataObject(ptr,a)         (ptr)->lpVtbl->GetNextDataObject(ptr,a)
#define IDirectXFileEnumObject_GetDataObjectById(ptr,a,b)       (ptr)->lpVtbl->GetDataObjectById(ptr,a,b)
#define IDirectXFileEnumObject_GetDataObjectByName(ptr,a,b)     (ptr)->lpVtbl->GetDataObjectByName(ptr,a,b)
#else
#define IDirectXFileEnumObject_QueryInterface(ptr,a,b)          (ptr)->QueryInterface(ptr,a,b)
#define IDirectXFileEnumObject_AddRef(ptr)                      (ptr)->AddRef(ptr)
#define IDirectXFileEnumObject_Release(ptr)                     (ptr)->Release(ptr)
#define IDirectXFileEnumObject_GetNextDataObject(ptr,a)         (ptr)->GetNextDataObject(ptr,a)
#define IDirectXFileEnumObject_GetDataObjectById(ptr,a,b)       (ptr)->GetDataObjectById(ptr,a,b)
#define IDirectXFileEnumObject_GetDataObjectByName(ptr,a,b)     (ptr)->GetDataObjectByName(ptr,a,b)
#endif

#define INTERFACE IDirectXFileSaveObject
DECLARE_INTERFACE_(IDirectXFileSaveObject, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    STDMETHOD(SaveTemplates) (THIS_ DWORD, const GUID **) PURE;
    STDMETHOD(CreateDataObject) (THIS_ REFGUID, LPCSTR, const GUID *, DWORD, LPVOID, LPDIRECTXFILEDATA *) PURE;
    STDMETHOD(SaveData) (THIS_ LPDIRECTXFILEDATA) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectXFileSaveObject_QueryInterface(ptr,a,b)                  (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirectXFileSaveObject_AddRef(ptr)                              (ptr)->lpVtbl->AddRef(ptr)
#define IDirectXFileSaveObject_Release(ptr)                             (ptr)->lpVtbl->Release(ptr)
#define IDirectXFileSaveObject_SaveTemplates(ptr,a,b)                   (ptr)->lpVtbl->SaveTemplates(ptr,a,b)
#define IDirectXFileSaveObject_CreateDataObject(ptr,a,b,c,d,e,f)        (ptr)->lpVtbl->CreateDataObject(ptr,a,b,c,d,e,f)
#define IDirectXFileSaveObject_SaveData(ptr,a)                          (ptr)->lpVtbl->SaveData(ptr,a)
#else
#define IDirectXFileSaveObject_QueryInterface(ptr,a,b)                  (ptr)->QueryInterface(ptr,a,b)
#define IDirectXFileSaveObject_AddRef(ptr)                              (ptr)->AddRef(ptr)
#define IDirectXFileSaveObject_Release(ptr)                             (ptr)->Release(ptr)
#define IDirectXFileSaveObject_SaveTemplates(ptr,a,b)                   (ptr)->SaveTemplates(ptr,a,b)
#define IDirectXFileSaveObject_CreateDataObject(ptr,a,b,c,d,e,f)        (ptr)->CreateDataObject(ptr,a,b,c,d,e,f)
#define IDirectXFileSaveObject_SaveData(ptr,a)                          (ptr)->SaveData(ptr,a)
#endif

#define INTERFACE IDirectXFileObject
DECLARE_INTERFACE_(IDirectXFileObject, IUnknown)
{
    IUNKNOWN_METHODS(PURE);
    IDIRECTXFILEOBJECT_METHODS(PURE);
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectXFileObject_QueryInterface(ptr,a,b)                  (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirectXFileObject_AddRef(ptr)                              (ptr)->lpVtbl->AddRef(ptr)
#define IDirectXFileObject_Release(ptr)                             (ptr)->lpVtbl->Release(ptr)
#define IDirectXFileObject_GetName(ptr,a,b)                         (ptr)->lpVtbl->Getname(ptr,a,b)
#define IDirectXFileObject_GetId(ptr,a)                             (ptr)->lpVtbl->GetId(ptr,a)
#else
#define IDirectXFileObject_QueryInterface(ptr,a,b)                  (ptr)->QueryInterface(ptr,a,b)
#define IDirectXFileObject_AddRef(ptr)                              (ptr)->AddRef(ptr)
#define IDirectXFileObject_Release(ptr)                             (ptr)->Release(ptr)
#define IDirectXFileObject_GetName(ptr,a,b)                         (ptr)->Getname(ptr,a,b)
#define IDirectXFileObject_GetId(ptr,a)                             (ptr)->GetId(ptr,a)
#endif

#define INTERFACE IDirectXFileData
DECLARE_INTERFACE_(IDirectXFileData, IDirectXFileObject)
{
    IUNKNOWN_METHODS(PURE);
    IDIRECTXFILEOBJECT_METHODS(PURE);

    STDMETHOD(GetData)          (THIS_ LPCSTR, DWORD *, void **) PURE;
    STDMETHOD(GetType)          (THIS_ const GUID **) PURE;
    STDMETHOD(GetNextObject)    (THIS_ LPDIRECTXFILEOBJECT *) PURE;
    STDMETHOD(AddDataObject)    (THIS_ LPDIRECTXFILEDATA) PURE;
    STDMETHOD(AddDataReference) (THIS_ LPCSTR, const GUID *) PURE;
    STDMETHOD(AddBinaryObject)  (THIS_ LPCSTR, const GUID *, LPCSTR, LPVOID, DWORD) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectXFileData_QueryInterface(ptr,a,b)                (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirectXFileData_AddRef(ptr)                            (ptr)->lpVtbl->AddRef(ptr)
#define IDirectXFileData_Release(ptr)                           (ptr)->lpVtbl->Release(ptr)
#define IDirectXFileData_GetName(ptr,a,b)                       (ptr)->lpVtbl->Getname(ptr,a,b)
#define IDirectXFileData_GetId(ptr,a)                           (ptr)->lpVtbl->GetId(ptr,a)
#define IDirectXFileData_GetData(ptr,a,b,c)                     (ptr)->lpVtbl->GetData(ptr,a,b,c)
#define IDirectXFileData_GetType(ptr,a)                         (ptr)->lpVtbl->GetType(ptr,a)
#define IDirectXFileData_GetNextObject(ptr,a)                   (ptr)->lpVtbl->GetNextObject(ptr,a)
#define IDirectXFileData_AddDataObject(ptr,a)                   (ptr)->lpVtbl->AddDataObject(ptr,a)
#define IDirectXFileData_AddDataReference(ptr,a,b)              (ptr)->lpVtbl->AddDataReference(ptr,a,b)
#define IDirectXFileData_AddBinaryObject(ptr,a,b,c,d,e)         (ptr)->lpVtbl->AddBinaryObject(ptr,a,b,c,d,e)
#else
#define IDirectXFileData_QueryInterface(ptr,a,b)                (ptr)->QueryInterface(ptr,a,b)
#define IDirectXFileData_AddRef(ptr)                            (ptr)->AddRef(ptr)
#define IDirectXFileData_Release(ptr)                           (ptr)->Release(ptr)
#define IDirectXFileData_GetName(ptr,a,b)                       (ptr)->Getname(ptr,a,b)
#define IDirectXFileData_GetId(ptr,a)                           (ptr)->GetId(ptr,a)
#define IDirectXFileData_GetData(ptr,a,b,c)                     (ptr)->GetData(ptr,a,b,c)
#define IDirectXFileData_GetType(ptr,a)                         (ptr)->GetType(ptr,a)
#define IDirectXFileData_GetNextObject(ptr,a)                   (ptr)->GetNextObject(ptr,a)
#define IDirectXFileData_AddDataObject(ptr,a)                   (ptr)->AddDataObject(ptr,a)
#define IDirectXFileData_AddDataReference(ptr,a,b)              (ptr)->AddDataReference(ptr,a,b)
#define IDirectXFileData_AddBinaryObject(ptr,a,b,c,d,e)         (ptr)->AddBinaryObject(ptr,a,b,c,d,e)
#endif

#define INTERFACE IDirectXFileDataReference
DECLARE_INTERFACE_(IDirectXFileDataReference, IDirectXFileObject)
{
    IUNKNOWN_METHODS(PURE);
    IDIRECTXFILEOBJECT_METHODS(PURE);

    STDMETHOD(Resolve) (THIS_ LPDIRECTXFILEDATA *) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectXFileDataReference_QueryInterface(ptr,a,b)                (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirectXFileDataReference_AddRef(ptr)                            (ptr)->lpVtbl->AddRef(ptr)
#define IDirectXFileDataReference_Release(ptr)                           (ptr)->lpVtbl->Release(ptr)
#define IDirectXFileDataReference_GetName(ptr,a,b)                       (ptr)->lpVtbl->Getname(ptr,a,b)
#define IDirectXFileDataReference_GetId(ptr,a)                           (ptr)->lpVtbl->GetId(ptr,a)
#define IDirectXFileDataReference_Resolve(ptr,a)                         (ptr)->lpVtbl->Resolve(ptr,a)
#else
#define IDirectXFileDataReference_QueryInterface(ptr,a,b)                (ptr)->QueryInterface(ptr,a,b)
#define IDirectXFileDataReference_AddRef(ptr)                            (ptr)->AddRef(ptr)
#define IDirectXFileDataReference_Release(ptr)                           (ptr)->Release(ptr)
#define IDirectXFileDataReference_GetName(ptr,a,b)                       (ptr)->Getname(ptr,a,b)
#define IDirectXFileDataReference_GetId(ptr,a)                           (ptr)->GetId(ptr,a)
#define IDirectXFileDataReference_Resolve(ptr,a,b,c)                     (ptr)->Resolve(ptr,a)
#endif

#define INTERFACE IDirectXFileBinary
DECLARE_INTERFACE_(IDirectXFileBinary, IDirectXFileObject)
{
    IUNKNOWN_METHODS(PURE);
    IDIRECTXFILEOBJECT_METHODS(PURE);

    STDMETHOD(GetSize)      (THIS_ DWORD *) PURE;
    STDMETHOD(GetMimeType)  (THIS_ LPCSTR *) PURE;
    STDMETHOD(Read)         (THIS_ LPVOID, DWORD, LPDWORD) PURE;
};
#undef INTERFACE

#if !defined(__cplusplus) || defined(CINTERFACE)
#define IDirectXFileBinary_QueryInterface(ptr,a,b)                      (ptr)->lpVtbl->QueryInterface(ptr,a,b)
#define IDirectXFileBinary_AddRef(ptr)                                  (ptr)->lpVtbl->AddRef(ptr)
#define IDirectXFileBinary_Release(ptr)                                 (ptr)->lpVtbl->Release(ptr)
#define IDirectXFileBinary_GetName(ptr,a,b)                             (ptr)->lpVtbl->Getname(ptr,a,b)
#define IDirectXFileBinary_GetId(ptr,a)                                 (ptr)->lpVtbl->GetId(ptr,a)
#define IDirectXFileBinary_GetSize(ptr,a)                               (ptr)->lpVtbl->GetSize(ptr,a)
#define IDirectXFileBinary_GetMimeType(ptr,a)                           (ptr)->lpVtbl->GetMimeType(ptr,a)
#define IDirectXFileBinary_Read(ptr,a,b,c)                              (ptr)->lpVtbl->Read(ptr,a)
#else
#define IDirectXFileBinary_QueryInterface(ptr,a,b)                      (ptr)->QueryInterface(ptr,a,b)
#define IDirectXFileBinary_AddRef(ptr)                                  (ptr)->AddRef(ptr)
#define IDirectXFileBinary_Release(ptr)                                 (ptr)->Release(ptr)
#define IDirectXFileBinary_GetName(ptr,a,b)                             (ptr)->Getname(ptr,a,b)
#define IDirectXFileBinary_GetId(ptr,a)                                 (ptr)->GetId(ptr,a)
#define IDirectXFileBinary_GetSize(ptr,a)                               (ptr)->GetSize(ptr,a)
#define IDirectXFileBinary_GetMimeType(ptr,a)                           (ptr)->GetMimeType(ptr,a)
#define IDirectXFileBinary_Read(ptr,a,b,c)                              (ptr)->Read(ptr,a)
#endif

/*
 * DirectXFile Object Class Id (for CoCreateInstance())
 */

DEFINE_GUID(CLSID_CDirectXFile, 0x4516ec43, 0x8f20, 0x11d0, 0x9b, 0x6d, 0x00, 0x00, 0xc0, 0x78, 0x1b, 0xc3);

/*
 * DirectX File Interface GUIDs.
 */

DEFINE_GUID(IID_IDirectXFile,               0x3d82ab40, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);
DEFINE_GUID(IID_IDirectXFileEnumObject,     0x3d82ab41, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);
DEFINE_GUID(IID_IDirectXFileSaveObject,     0x3d82ab42, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);
DEFINE_GUID(IID_IDirectXFileObject,         0x3d82ab43, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);
DEFINE_GUID(IID_IDirectXFileData,           0x3d82ab44, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);
DEFINE_GUID(IID_IDirectXFileDataReference,  0x3d82ab45, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);
DEFINE_GUID(IID_IDirectXFileBinary,         0x3d82ab46, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);

/*
 * DirectX File Header template's GUID.
 */

DEFINE_GUID(TID_DXFILEHeader,   0x3d82ab43, 0x62da, 0x11cf, 0xab, 0x39, 0x0, 0x20, 0xaf, 0x71, 0xe4, 0x33);


/*
 * DirectX File errors.
 */

#define _FACDD  0x876
#define MAKE_DDHRESULT( code )  MAKE_HRESULT( 1, _FACDD, code )

#define DXFILE_OK   0

#define DXFILEERR_BADOBJECT                 MAKE_DDHRESULT(850)
#define DXFILEERR_BADVALUE                  MAKE_DDHRESULT(851)
#define DXFILEERR_BADTYPE                   MAKE_DDHRESULT(852)
#define DXFILEERR_BADSTREAMHANDLE           MAKE_DDHRESULT(853)
#define DXFILEERR_BADALLOC                  MAKE_DDHRESULT(854)
#define DXFILEERR_NOTFOUND                  MAKE_DDHRESULT(855)
#define DXFILEERR_NOTDONEYET                MAKE_DDHRESULT(856)
#define DXFILEERR_FILENOTFOUND              MAKE_DDHRESULT(857)
#define DXFILEERR_RESOURCENOTFOUND          MAKE_DDHRESULT(858)
#define DXFILEERR_URLNOTFOUND               MAKE_DDHRESULT(859)
#define DXFILEERR_BADRESOURCE               MAKE_DDHRESULT(860)
#define DXFILEERR_BADFILETYPE               MAKE_DDHRESULT(861)
#define DXFILEERR_BADFILEVERSION            MAKE_DDHRESULT(862)
#define DXFILEERR_BADFILEFLOATSIZE          MAKE_DDHRESULT(863)
#define DXFILEERR_BADFILECOMPRESSIONTYPE    MAKE_DDHRESULT(864)
#define DXFILEERR_BADFILE                   MAKE_DDHRESULT(865)
#define DXFILEERR_PARSEERROR                MAKE_DDHRESULT(866)
#define DXFILEERR_NOTEMPLATE                MAKE_DDHRESULT(867)
#define DXFILEERR_BADARRAYSIZE              MAKE_DDHRESULT(868)
#define DXFILEERR_BADDATAREFERENCE          MAKE_DDHRESULT(869)
#define DXFILEERR_INTERNALERROR             MAKE_DDHRESULT(870)
#define DXFILEERR_NOMOREOBJECTS             MAKE_DDHRESULT(871)
#define DXFILEERR_BADINTRINSICS             MAKE_DDHRESULT(872)
#define DXFILEERR_NOMORESTREAMHANDLES       MAKE_DDHRESULT(873)
#define DXFILEERR_NOMOREDATA                MAKE_DDHRESULT(874)
#define DXFILEERR_BADCACHEFILE              MAKE_DDHRESULT(875)
#define DXFILEERR_NOINTERNET                MAKE_DDHRESULT(876)


#ifdef __cplusplus
};
#endif

#endif  // DXFILE_H
