add_library(SDL3_d3drm SHARED
    src/d3drm/idirect3drm.c
    src/d3drm/idirect3drm.h
    src/d3drm/idirect3drmdevice.c
    src/d3drm/idirect3drmdevice.h
    src/d3drm/idirect3drmframe.c
    src/d3drm/idirect3drmframe.h
    src/d3drm/idirect3drmlight.c
    src/d3drm/idirect3drmlight.h
    src/d3drm/idirect3drmmaterial.c
    src/d3drm/idirect3drmmaterial.h
    src/d3drm/idirect3drmmeshbuilder.c
    src/d3drm/idirect3drmmeshbuilder.h
    src/d3drm/idirect3drmtexture.c
    src/d3drm/idirect3drmtexture.h
    src/d3drm/idirect3drmviewport.c
    src/d3drm/idirect3drmviewport.h
    src/d3drm/math.c
)
target_include_directories(SDL3_d3drm PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/src")
target_include_directories(SDL3_d3drm PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")
if(NOT WIN32)
  target_include_directories(SDL3_d3drm PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include/fakewindows")
endif()
target_link_libraries(SDL3_d3drm PRIVATE SDL3::SDL3)

add_executable(SDL_d3drm_test src/d3drm/test/test.c)
target_link_libraries(SDL_d3drm_test PRIVATE SDL3_d3drm)
