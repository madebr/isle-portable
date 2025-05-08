#ifndef COMMON_COM_H
#define COMMON_COM_H

#define COM_INCREF(OBJ)                                                   \
    do {                                                                      \
        (OBJ)->interface_IUnknown.lpVtbl->AddRef(&(OBJ)->interface_IUnknown); \
    } while (0)

#define COM_DECREF(OBJ)                                                    \
    do {                                                                       \
        (OBJ)->interface_IUnknown.lpVtbl->Release(&(OBJ)->interface_IUnknown); \
    } while (0)

#endif // COMMON_COM_H
