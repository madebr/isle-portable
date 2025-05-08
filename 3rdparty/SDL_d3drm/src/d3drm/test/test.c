#include <d3drm.h>
#include <SDL3/SDL.h>
#include <SDL3/SDL_test.h>

#define EPSILON 2e-5f

static double float_delta(float a, float b) {
    return SDL_fabs(a - b);
}

static int SDLCALL d3drm_D3DRMColorGetRed(void *arg) {
    const struct {
        D3DCOLOR in;
        D3DVALUE out;
    } test_cases[] = {
        { 0x00000000, 0.f },
        { 0xff000000, 0.f },
        { 0x80000000, 0.f },
        { 0x00ff0000, 1.f },
        { 0x00fe0000, 254.f/255.f },
        { 0x00fd0000, 253.f/255.f },
        { 0x00800000, 128.f/255.f },
        { 0x00400000, 64.f/255.f },
        { 0x00020000, 2.f/255.f },
        { 0x00010000, 1.f/255.f },
        { 0x0000ff00, 0.f },
        { 0x00008000, 0.f },
        { 0x0000ff00, 0.f },
        { 0x00008000, 0.f },
        { 0x000000ff, 0.f },
        { 0x00000080, 0.f },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DCOLOR ref_in = test_cases[i].in;
        const D3DVALUE ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMColorGetRed(0x%08" SDL_PRIx32 ")", ref_in);
        D3DVALUE actual = D3DRMColorGetRed(ref_in);
        double delta = float_delta(actual, ref_out);
        SDLTest_AssertCheck(delta < EPSILON, "Got %f, expected %f (delta=%g)", actual, ref_out, delta);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMColorGetRed  = {
    d3drm_D3DRMColorGetRed, "d3drm_D3DRMColorGetRed", "Test D3DRMColorGetRed", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMColorGetGreen(void *arg) {
    const struct {
        D3DCOLOR in;
        D3DVALUE out;
    } test_cases[] = {
        { 0x00000000, 0.f },
        { 0xff000000, 0.f },
        { 0x80000000, 0.f },
        { 0x00ff0000, 0.f },
        { 0x00800000, 0.f },
        { 0x0000ff00, 1.f },
        { 0x0000fe00, 254.f/255.f },
        { 0x0000fd00, 253.f/255.f },
        { 0x00008000, 128.f/255.f },
        { 0x00004000, 64.f/255.f },
        { 0x00000200, 2.f/255.f },
        { 0x00000100, 1.f/255.f },
        { 0x000000ff, 0.f },
        { 0x00000080, 0.f },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DCOLOR ref_in = test_cases[i].in;
        const D3DVALUE ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMColorGetGreen(0x%08" SDL_PRIx32 ")", ref_in);
        D3DVALUE actual = D3DRMColorGetGreen(ref_in);
        double delta = float_delta(actual, ref_out);
        SDLTest_AssertCheck(delta < EPSILON, "Got %f, expected %f (delta=%g)", actual, ref_out, delta);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMColorGetGreen  = {
    d3drm_D3DRMColorGetGreen, "d3drm_D3DRMColorGetGreen", "Test D3DRMColorGetGreen", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMColorGetBlue(void *arg) {
    const struct {
        D3DCOLOR in;
        D3DVALUE out;
    } test_cases[] = {
        { 0x00000000, 0.f },
        { 0xff000000, 0.f },
        { 0x80000000, 0.f },
        { 0x00ff0000, 0.f },
        { 0x00800000, 0.f },
        { 0x0000ff00, 0.f },
        { 0x00008000, 0.f },
        { 0x000000ff, 1.f },
        { 0x000000fe, 254.f/255.f },
        { 0x000000fd, 253.f/255.f },
        { 0x00000080, 128.f/255.f },
        { 0x00000040, 64.f/255.f },
        { 0x00000002, 2.f/255.f },
        { 0x00000001, 1.f/255.f },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DCOLOR ref_in = test_cases[i].in;
        const D3DVALUE ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMColorGetBlue(0x%08" SDL_PRIx32 ")", ref_in);
        D3DVALUE actual = D3DRMColorGetBlue(ref_in);
        double delta = float_delta(actual, ref_out);
        SDLTest_AssertCheck(delta < EPSILON, "Got %f, expected %f (delta=%g)", actual, ref_out, delta);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMColorGetBlue  = {
    d3drm_D3DRMColorGetBlue, "d3drm_D3DRMColorGetBlue", "Test D3DRMColorGetBlue", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMColorGetAlpha(void *arg) {
    const struct {
        D3DCOLOR in;
        D3DVALUE out;
    } test_cases[] = {
        { 0x00000000, 0.f },
        { 0xff000000, 1.f },
        { 0xfe000000, 254.f/255.f },
        { 0xfd000000, 253.f/255.f },
        { 0x80000000, 128.f/255.f },
        { 0x40000000, 64.f/255.f },
        { 0x02000000, 2.f/255.f },
        { 0x01000000, 1.f/255.f },
        { 0x00ff0000, 0.f },
        { 0x00800000, 0.f },
        { 0x0000ff00, 0.f },
        { 0x00008000, 0.f },
        { 0x000000ff, 0.f },
        { 0x00000080, 0.f },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DCOLOR ref_in = test_cases[i].in;
        const D3DVALUE ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMColorGetAlpha(0x%08" SDL_PRIx32 ")", ref_in);
        D3DVALUE actual = D3DRMColorGetAlpha(ref_in);
        double delta = float_delta(actual, ref_out);
        SDLTest_AssertCheck(delta < EPSILON, "Got %f, expected %f (delta=%g)", actual, ref_out, delta);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMColorGetAlpha  = {
    d3drm_D3DRMColorGetAlpha, "d3drm_D3DRMColorGetAlpha", "Test D3DRMColorGetAlpha", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMCreateColorRGB(void *arg) {
    const struct {
        D3DVALUE r, g, b;
        D3DCOLOR out;
    } test_cases[] = {
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    0xff000000 },
        { 1.5f/255.f,   0.f/255.f,    0.f/255.f,    0xff010000 },
        { 2.5f/255.f,   0.f/255.f,    0.f/255.f,    0xff020000 },
        { 128.5f/255.f, 0.f/255.f,    0.f/255.f,    0xff800000 },
        { 253.5f/255.f, 0.f/255.f,    0.f/255.f,    0xfffd0000 },
        { 254.5f/255.f, 0.f/255.f,    0.f/255.f,    0xfffe0000 },
        { 255.f/255.f,  0.f/255.f,    0.f/255.f,    0xffff0000 },
        { 0.f/255.f,    1.5f/255.f,   0.f/255.f,    0xff000100 },
        { 0.f/255.f,    2.5f/255.f,   0.f/255.f,    0xff000200 },
        { 0.f/255.f,    128.5f/255.f, 0.f/255.f,    0xff008000 },
        { 0.f/255.f,    253.5f/255.f, 0.f/255.f,    0xff00fd00 },
        { 0.f/255.f,    254.5f/255.f, 0.f/255.f,    0xff00fe00 },
        { 0.f/255.f,    255.f/255.f,  0.f/255.f,    0xff00ff00 },
        { 0.f/255.f,    0.f/255.f,    1.5f/255.f,   0xff000001 },
        { 0.f/255.f,    0.f/255.f,    2.5f/255.f,   0xff000002 },
        { 0.f/255.f,    0.f/255.f,    128.5f/255.f, 0xff000080 },
        { 0.f/255.f,    0.f/255.f,    253.5f/255.f, 0xff0000fd },
        { 0.f/255.f,    0.f/255.f,    254.5f/255.f, 0xff0000fe },
        { 0.f/255.f,    0.f/255.f,    255.f/255.f,  0xff0000ff },
        { 0.f/255.f,    255.f/255.f,  255.f/255.f,  0xff00ffff },
        { 255.f/255.f,  255.f/255.f,  255.f/255.f,  0xffffffff },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVALUE r = test_cases[i].r;
        const D3DVALUE g = test_cases[i].g;
        const D3DVALUE b = test_cases[i].b;
        const D3DCOLOR ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMCreateColorRGB(%f, %f, %f)", r, g, b);
        D3DCOLOR actual = D3DRMCreateColorRGB(r, g, b);
        SDLTest_AssertCheck(actual == ref_out, "Got 0x%08" SDL_PRIx32 ", expected 0x%08" SDL_PRIx32, actual, ref_out);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMCreateColorRGB  = {
    d3drm_D3DRMCreateColorRGB, "d3drm_D3DRMCreateColorRGB", "Test D3DRMCreateColorRGB", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMCreateColorRGBA(void *arg) {
    const struct {
        D3DVALUE r, g, b, a;
        D3DCOLOR out;
    } test_cases[] = {
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    0.f/255.f,    0x00000000 },
        { 1.5f/255.f,   0.f/255.f,    0.f/255.f,    0.f/255.f,    0x00010000 },
        { 2.5f/255.f,   0.f/255.f,    0.f/255.f,    0.f/255.f,    0x00020000 },
        { 128.5f/255.f, 0.f/255.f,    0.f/255.f,    0.f/255.f,    0x00800000 },
        { 253.5f/255.f, 0.f/255.f,    0.f/255.f,    0.f/255.f,    0x00fd0000 },
        { 254.5f/255.f, 0.f/255.f,    0.f/255.f,    0.f/255.f,    0x00fe0000 },
        { 255.f/255.f,  0.f/255.f,    0.f/255.f,    0.f/255.f,    0x00ff0000 },
        { 0.f/255.f,    1.5f/255.f,   0.f/255.f,    0.f/255.f,    0x00000100 },
        { 0.f/255.f,    2.5f/255.f,   0.f/255.f,    0.f/255.f,    0x00000200 },
        { 0.f/255.f,    128.5f/255.f, 0.f/255.f,    0.f/255.f,    0x00008000 },
        { 0.f/255.f,    253.5f/255.f, 0.f/255.f,    0.f/255.f,    0x0000fd00 },
        { 0.f/255.f,    254.5f/255.f, 0.f/255.f,    0.f/255.f,    0x0000fe00 },
        { 0.f/255.f,    255.f/255.f,  0.f/255.f,    0.f/255.f,    0x0000ff00 },
        { 0.f/255.f,    0.f/255.f,    1.5f/255.f,   0.f/255.f,    0x00000001 },
        { 0.f/255.f,    0.f/255.f,    2.5f/255.f,   0.f/255.f,    0x00000002 },
        { 0.f/255.f,    0.f/255.f,    128.5f/255.f, 0.f/255.f,    0x00000080 },
        { 0.f/255.f,    0.f/255.f,    253.5f/255.f, 0.f/255.f,    0x000000fd },
        { 0.f/255.f,    0.f/255.f,    254.5f/255.f, 0.f/255.f,    0x000000fe },
        { 0.f/255.f,    0.f/255.f,    255.f/255.f,  0.f/255.f,    0x000000ff },
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    1.5f/255.f,   0x01000000 },
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    2.5f/255.f,   0x02000000 },
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    128.5f/255.f, 0x80000000 },
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    253.5f/255.f, 0xfd000000 },
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    254.5f/255.f, 0xfe000000 },
        { 0.f/255.f,    0.f/255.f,    0.f/255.f,    255.f/255.f,  0xff000000 },
        { 0.f/255.f,    255.f/255.f,  255.f/255.f,  0.f/255.f,    0x0000ffff },
        { 255.f/255.f,  255.f/255.f,  255.f/255.f,  128.5f/255.f, 0x80ffffff },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVALUE r = test_cases[i].r;
        const D3DVALUE g = test_cases[i].g;
        const D3DVALUE b = test_cases[i].b;
        const D3DVALUE a = test_cases[i].a;
        const D3DCOLOR ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMCreateColorRGBA(%f, %f, %f, %f)", r, g, b, a);
        D3DCOLOR actual = D3DRMCreateColorRGBA(r, g, b, a);
        SDLTest_AssertCheck(actual == ref_out, "Got 0x%08" SDL_PRIx32 ", expected 0x%08" SDL_PRIx32, actual, ref_out);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMCreateColorRGBA  = {
    d3drm_D3DRMCreateColorRGBA, "d3drm_D3DRMCreateColorRGBA", "Test D3DRMCreateColorRGBA", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorAdd(void *arg) {
    const struct {
        D3DVECTOR x, y;
        D3DVECTOR out;
    } test_cases[] = {
        { {{0.f},   {0.f},    {0.f}},   {{0.f},     {0.f},  {0.f}},     {{0.f},     {0.f},      {0.f}} },
        { {{1.f},   {0.f},    {0.f}},   {{0.f},     {0.f},  {0.f}},     {{1.f},     {0.f},      {0.f}} },
        { {{1.f},   {0.f},    {0.f}},   {{1.f},     {0.f},  {0.f}},     {{2.f},     {0.f},      {0.f}} },
        { {{1.f},   {-10.f},  {0.f}},   {{1.f},     {0.f},  {10.f}},    {{2.f},     {-10.f},    {10.f}} },
        { {{1234.f},{-10.f},  {97.f}},  {{-40.f},   {0.f},  {80.f}},    {{1194.f},  {-10.f},    {177.f}} },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR x = test_cases[i].x;
        const D3DVECTOR y = test_cases[i].y;
        const D3DVECTOR ref_out = test_cases[i].out;
        D3DVECTOR out;
        D3DVECTOR *rc;
        SDLTest_AssertPass("D3DRMVectorAdd({%f, %f, %f}, {%f, %f, %f})", x.x, x.y, x.z, y.x, y.y, y.z);
        rc = D3DRMVectorAdd(&out, &x, &y);
        SDLTest_AssertCheck(rc == &out, "D3DRMVectorAdd returns correct pointer: got %p, expected %p", rc, &out);
        double delta1 = float_delta(out.x, ref_out.x);
        double delta2 = float_delta(out.y, ref_out.y);
        double delta3 = float_delta(out.z, ref_out.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON,
            "Got {%f, %f, %f}, expected {%f, %f, %f} (delta={%g, %g, %g}", out.x, out.y, out.z, ref_out.x, ref_out.y, ref_out.z, delta1, delta2, delta3);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorAdd  = {
    d3drm_D3DRMVectorAdd, "d3drm_D3DRMVectorAdd", "Test D3DRMVectorAdd", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorSubtract(void *arg) {
    const struct {
        D3DVECTOR x, y;
        D3DVECTOR out;
    } test_cases[] = {
        { {{0.f},   {0.f},    {0.f}},   {{0.f},     {0.f},  {0.f}},     {{0.f},     {0.f},      {0.f}} },
        { {{1.f},   {0.f},    {0.f}},   {{0.f},     {0.f},  {0.f}},     {{1.f},     {0.f},      {0.f}} },
        { {{1.f},   {0.f},    {0.f}},   {{1.f},     {0.f},  {0.f}},     {{0.f},     {0.f},      {0.f}} },
        { {{1.f},   {-10.f},  {0.f}},   {{1.f},     {0.f},  {10.f}},    {{0.f},     {-10.f},    {-10.f}} },
        { {{1234.f},{-10.f},  {97.f}},  {{-40.f},   {0.f},  {80.f}},    {{1274.f},  {-10.f},    {17.f}} },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR x = test_cases[i].x;
        const D3DVECTOR y = test_cases[i].y;
        const D3DVECTOR ref_out = test_cases[i].out;
        D3DVECTOR out;
        D3DVECTOR *rc;
        SDLTest_AssertPass("D3DRMVectorSubtract({%f, %f, %f}, {%f, %f, %f})", x.x, x.y, x.z, y.x, y.y, y.z);
        rc = D3DRMVectorSubtract(&out, &x, &y);
        SDLTest_AssertCheck(rc == &out, "D3DRMVectorSubtract returns correct pointer: got %p, expected %p", rc, &out);
        double delta1 = float_delta(out.x, ref_out.x);
        double delta2 = float_delta(out.y, ref_out.y);
        double delta3 = float_delta(out.z, ref_out.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON,
            "Got {%f, %f, %f}, expected {%f, %f, %f} (delta={%g, %g, %g})", out.x, out.y, out.z, ref_out.x, ref_out.y, ref_out.z, delta1, delta2, delta3);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorSubtract  = {
    d3drm_D3DRMVectorSubtract, "d3drm_D3DRMVectorSubtract", "Test D3DRMVectorSubtract", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorModulus(void *arg) {
    const struct {
        D3DVECTOR in;
        D3DVALUE out;
    } test_cases[] = {
        { {{0.f},   {0.f},    {0.f}},   0.f },
        { {{3.f},   {4.f},    {0.f}},   5.f },
        { {{0.f},   {3.f},    {4.f}},   5.f },
        { {{3.f},   {0.f},    {4.f}},   5.f },
        { {{3.f},   {4.f},    {12.f}},  13.f },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR in = test_cases[i].in;
        const D3DVALUE ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMVectorModulus({%f, %f, %f})", in.x, in.y, in.z);
        D3DVALUE out = D3DRMVectorModulus(&in);
        double delta = float_delta(ref_out, out);
        SDLTest_AssertCheck(delta < EPSILON, "Got %f, expected %f (delta=%g)", out, ref_out, delta);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorModulus  = {
    d3drm_D3DRMVectorModulus, "d3drm_D3DRMVectorModulus", "Test D3DRMVectorModulus", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorRandom(void *arg) {
    (void) arg;
    for (unsigned i = 0; i < 50; i++) {
        D3DVECTOR v;
        SDLTest_AssertPass("D3DRMVectorRandom(%p)", &v);
        D3DVECTOR *rc = D3DRMVectorRandom(&v);
        SDLTest_AssertCheck(rc == &v, "D3DRMVectorRandom returns correct pointer: got %p, expected %p", rc, &v);
        float m = SDL_sqrtf(v.x * v.x + v.y * v.y + v.z * v.z);
        double delta = float_delta(m, 1.f);
        SDLTest_AssertCheck(delta <= EPSILON, "{%f, %f, %f}: Length = %f, expected = 1.00 (delta = %g)", v.x, v.y, v.z, m, delta);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorRandom  = {
    d3drm_D3DRMVectorRandom, "d3drm_D3DRMVectorRandom", "Test D3DRMVectorRandom", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorNormalize(void *arg) {
    const struct {
        D3DVECTOR in;
        D3DVECTOR out;
    } test_cases[] = {
            { {{0.f},   {0.f},    {0.f}},   {{1.f},   {0.f},    {0.f}},  },
            { {{1.f},   {0.f},    {0.f}},   {{1.f},   {0.f},    {0.f}},  },
            { {{0.f},   {1.7f},   {0.f}},   {{0.f},   {1.f},    {0.f}},  },
            { {{0.f},   {0.f},    {0.9f}},  {{0.f},   {0.f},    {1.f}},  },
            { {{3.f},   {4.f},    {0.f}},   {{.6f},   {.8f},    {0.f}},  },
            { {{0.f},   {3.f},    {4.f}},   {{0.f},   {.6f},    {.8f}},  },
            { {{3.f},   {0.f},    {4.f}},   {{.6f},   {0.f},    {.8f}},  },
            { {{3.f},   {4.f},    {12.f}},  {{3.f/13.f},  {4.f/13.f},    {12.f/13.f}}, },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        D3DVECTOR in = test_cases[i].in;
        const D3DVECTOR ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMVectorNormalize({%f, %f, %f})", in.x, in.y, in.z);
        D3DVECTOR *rc = D3DRMVectorNormalize(&in);
        SDLTest_AssertCheck(rc == &in, "D3DRMVectorRandom returns correct pointer: got %p, expected %p", rc, &in);
        double delta1 = float_delta(in.x, ref_out.x);
        double delta2 = float_delta(in.y, ref_out.y);
        double delta3 = float_delta(in.z, ref_out.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON, "Got {%f, %f, %f}, expected {%f, %f, %f} (delta={%g, %g, %g})", in.x, in.y, in.z, ref_out.x, ref_out.y, ref_out.z, delta1, delta2, delta3);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorNormalize  = {
    d3drm_D3DRMVectorNormalize, "d3drm_D3DRMVectorNormalize", "Test D3DRMVectorNormalize", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorScale(void *arg) {
    const struct {
        D3DVECTOR v_in;
        D3DVALUE scale_in;
        D3DVECTOR out;
    } test_cases[] = {
            { {{0.f},   {0.f},    {0.f}},   2.f, {{0.f},   {0.f},    {0.f}},  },
            { {{1.f},   {0.f},    {0.f}},   7.f, {{7.f},   {0.f},    {0.f}},  },
            { {{0.f},   {1.7f},   {0.f}},   3.f, {{0.f},   {5.1f},   {0.f}},  },
            { {{0.f},   {0.f},    {0.9f}},  4.f, {{0.f},   {0.f},    {3.6f}}, },
            { {{3.f},   {4.f},    {0.f}},   .2f, {{.6f},   {.8f},    {0.f}},  },
            { {{0.f},   {3.f},    {4.f}},   3.f, {{0.f},   {9.f},    {12.f}}, },
            { {{3.f},   {0.f},    {4.f}},   .2f, {{.6f},   {0.f},    {.8f}},  },
            { {{3.f},   {4.f},    {12.f}},  3.f, {{9.f},   {12.f},   {36.f}}, },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR v_in = test_cases[i].v_in;
        const D3DVALUE scale_in = test_cases[i].scale_in;
        const D3DVECTOR ref_out = test_cases[i].out;
        D3DVECTOR out;
        SDLTest_AssertPass("D3DRMVectorScale({%f, %f, %f}, %f)", v_in.x, v_in.y, v_in.z, scale_in);
        D3DVECTOR *rc = D3DRMVectorScale(&out, &v_in, scale_in);
        SDLTest_AssertCheck(rc == &out, "D3DRMVectorRandom returns correct pointer: got %p, expected %p", rc, &out);
        double delta1 = float_delta(out.x, ref_out.x);
        double delta2 = float_delta(out.y, ref_out.y);
        double delta3 = float_delta(out.z, ref_out.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON, "Got {%f, %f, %f}, expected {%f, %f, %f} (delta={%g, %g, %g})", out.x, out.y, out.z, ref_out.x, ref_out.y, ref_out.z, delta1, delta2, delta3);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorScale  = {
    d3drm_D3DRMVectorScale, "d3drm_D3DRMVectorScale", "Test D3DRMVectorScale", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorDotProduct(void *arg) {
    const struct {
        D3DVECTOR v_in1;
        D3DVECTOR v_in2;
        D3DVALUE out;
    } test_cases[] = {
            { {{0.f},   {0.f},    {0.f}},   {{0.f},   {0.f},    {0.f}},  0.f },
            { {{1.f},   {0.f},    {0.f}},   {{7.f},   {0.f},    {0.f}},  7.f },
            { {{0.f},   {1.7f},   {0.f}},   {{0.f},   {5.1f},   {0.f}},  8.67f },
            { {{0.f},   {0.f},    {0.9f}},  {{0.f},   {0.f},    {3.6f}}, 3.24f },
            { {{3.f},   {4.f},    {0.f}},   {{.6f},   {.8f},    {0.f}},  5.f },
            { {{0.f},   {3.f},    {4.f}},   {{0.f},   {9.f},    {12.f}}, 75.f },
            { {{3.f},   {0.f},    {4.f}},   {{.6f},   {0.f},    {.8f}},  5.f },
            { {{3.f},   {4.f},    {12.f}},  {{9.f},   {12.f},   {36.f}}, 507.f },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR v_in1 = test_cases[i].v_in1;
        const D3DVECTOR v_in2 = test_cases[i].v_in2;
        const D3DVALUE ref_out = test_cases[i].out;
        SDLTest_AssertPass("D3DRMVectorDotProduct({%f, %f, %f}, {%f, %f, %f})", v_in1.x, v_in1.y, v_in1.z, v_in2.x, v_in2.y, v_in2.z);
        D3DVALUE out = D3DRMVectorDotProduct(&v_in1, &v_in2);
        double delta = float_delta(out, ref_out);
        SDLTest_AssertCheck(delta < EPSILON, "Got %f, expected %f (delta=%g)", out, ref_out, delta);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorDotProduct  = {
    d3drm_D3DRMVectorDotProduct, "d3drm_D3DRMVectorDotProduct", "Test D3DRMVectorDotProduct", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMQuaternionFromRotation(void *arg) {
    const float SQRT2_F = SDL_sqrtf(2.f);
    const float SQRT3_F = SDL_sqrtf(3.f);
    const struct {
        D3DVECTOR v_in;
        D3DVALUE rot_in;
        D3DRMQUATERNION out;
    } test_cases[] = {
            { {{1.f},   {0.f},    {0.f}},   SDL_PI_F,   {0.f,       {{1.f},             {0.f},              {0.f}} }},
            { {{.3f},   {.4f},    {0.f}},   SDL_PI_F/2, {SQRT2_F/2, {{SQRT2_F*.3f},     {SQRT2_F*.4f},      {0.f}} }},
            { {{1.f},   {1.f},    {1.f}},   SDL_PI_F/3, {SQRT3_F/2, {{1/SQRT3_F/2},     {1/SQRT3_F/2},      {1/SQRT3_F/2}} }},
            { {{0.f},   {3.f},    {4.f}},   -SDL_PI_F/2,{SQRT2_F/2, {{0.f},             {-SQRT2_F*.3f},     {-SQRT2_F*.4f}} }},
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR v_in = test_cases[i].v_in;
        const D3DVALUE rot_in = test_cases[i].rot_in;
        const D3DRMQUATERNION ref_out = test_cases[i].out;
        D3DRMQUATERNION out;
        D3DVECTOR in = v_in;
        SDLTest_AssertPass("D3DRMQuaternionFromRotation({%f, %f, %f}, %f)", v_in.x, v_in.y, v_in.z, rot_in);
        D3DRMQUATERNION *rc = D3DRMQuaternionFromRotation(&out, &in, rot_in);
        SDLTest_AssertCheck(rc == &out, "D3DRMQuaternionFromRotation returns correct pointer: got %p, expected %p", rc, &out);
        D3DVALUE norm_in_2 = in.x * in.x + in.y * in.y + in.z * in.z;
        double delta = float_delta(norm_in_2, 1.);
        SDLTest_AssertCheck(delta < EPSILON, "Input is now an input vector: norm^2 = %f (delta=%g)", norm_in_2, delta);
        double delta1 = float_delta(out.s, ref_out.s);
        double delta2 = float_delta(out.v.x, ref_out.v.x);
        double delta3 = float_delta(out.v.y, ref_out.v.y);
        double delta4 = float_delta(out.v.z, ref_out.v.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON && delta4 < EPSILON,
            "Got {%f, {%f, %f, %f}}, expected {%f, {%f, %f, %f}} (delta={%g,{%g, %g, %g}})",
            out.s, out.v.x, out.v.y, out.v.z, ref_out.s, ref_out.v.x, ref_out.v.y, ref_out.v.z, delta1, delta2, delta3, delta4);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMQuaternionFromRotation  = {
    d3drm_D3DRMQuaternionFromRotation, "d3drm_D3DRMQuaternionFromRotation", "Test D3DRMQuaternionFromRotation", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorCrossProduct(void *arg) {
    const struct {
        D3DVECTOR v_in1;
        D3DVECTOR v_in2;
        D3DVECTOR out;
    } test_cases[] = {
        { {{1.f},   {0.f},    {0.f}},   {{0.f},   {1.f},    {0.f}}, {{0.f},   {0.f},    {1.f}}},
        { {{0.f},   {1.f},    {0.f}},   {{1.f},   {0.f},    {0.f}}, {{0.f},   {0.f},    {-1.f}}},
        { {{0.f},   {1.f},    {0.f}},   {{0.f},   {0.f},    {1.f}}, {{1.f},   {0.f},    {0.f}}},
        { {{0.f},   {0.f},    {1.f}},   {{0.f},   {1.f},    {0.f}}, {{-1.f},  {0.f},    {0.f}}},
        { {{0.f},   {0.f},    {1.f}},   {{1.f},   {0.f},    {0.f}}, {{0.f},   {1.f},    {0.f}}},
        { {{1.f},   {0.f},    {0.f}},   {{0.f},   {0.f},    {1.f}}, {{0.f},   {-1.f},    {0.f}}},
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR v_in1 = test_cases[i].v_in1;
        const D3DVECTOR v_in2 = test_cases[i].v_in2;
        const D3DVECTOR ref_out = test_cases[i].out;
        D3DVECTOR out;
        SDLTest_AssertPass("D3DRMVectorCrossProduct({%f, %f, %f}, {%f, %f, %f})", v_in1.x, v_in1.y, v_in1.z, v_in2.x, v_in2.y, v_in2.z);
        D3DVECTOR *rc = D3DRMVectorCrossProduct(&out, &v_in1, &v_in2);
        SDLTest_AssertCheck(rc == &out, "D3DRMVectorCrossProduct returns correct pointer: got %p, expected %p", rc, &out);
        double delta1 = float_delta(out.x, ref_out.x);
        double delta2 = float_delta(out.y, ref_out.y);
        double delta3 = float_delta(out.z, ref_out.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON,
            "Got {%f, %f, %f}, expected {%f, %f, %f} (delta={%g, %g, %g})",
            out.x, out.y, out.z, ref_out.x, ref_out.y, ref_out.z, delta1, delta2, delta3);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorCrossProduct  = {
    d3drm_D3DRMVectorCrossProduct, "d3drm_D3DRMVectorCrossProduct", "Test D3DRMVectorCrossProduct", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMQuaternionMultiply(void *arg) {
    const float SQRT2_F = SDL_sqrtf(2.f);
    const float SQRT3_F = SDL_sqrtf(3.f);
    const struct {
        D3DRMQUATERNION quat_in1;
        D3DRMQUATERNION quat_in2;
        D3DRMQUATERNION out;
    } test_cases[] = {
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                {1.f,       {{0.f},               {0.f},              {0.f}}},                  {1.f,       {{0.f},               {0.f},              {0.f}}} },
        { {-1.f,      {{0.f},               {0.f},              {0.f}}},                {1.f,       {{0.f},               {0.f},              {0.f}}},                  {-1.f,      {{0.f},               {0.f},              {0.f}}} },
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                {-1.f,      {{0.f},               {0.f},              {0.f}}},                  {-1.f,      {{0.f},               {0.f},              {0.f}}} },
        { {-1.f,      {{0.f},               {0.f},              {0.f}}},                {-1.f,      {{0.f},               {0.f},              {0.f}}},                  {1.f,       {{0.f},               {0.f},              {0.f}}} },
        { {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}},          {1.f,       {{0.f},               {0.f},              {0.f}}},                  {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}} },
        { {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}},          {1.f,       {{0.f},               {0.f},              {0.f}}},                  {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}} },
        { {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}},          {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}},            {-1.f,      {{0.f},               {0.f},              {0.f}}} },
        { {1/SQRT2_F, {{1/SQRT3_F/SQRT2_F}, {1/SQRT3_F/SQRT2_F},{1/SQRT3_F/SQRT2_F}}},  {1/SQRT2_F, {{1/SQRT3_F/SQRT2_F}, {1/SQRT3_F/SQRT2_F},{1/SQRT3_F/SQRT2_F}}},    {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}} },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DRMQUATERNION quat_in1 = test_cases[i].quat_in1;
        const D3DRMQUATERNION quat_in2 = test_cases[i].quat_in2;
        const D3DRMQUATERNION ref_out = test_cases[i].out;
        D3DRMQUATERNION out;
        SDLTest_AssertPass("D3DRMQuaternionMultiply({%f, {%f, %f, %f}}, {%f, {%f, %f, %f}})", quat_in1.s, quat_in1.v.x, quat_in1.v.y, quat_in1.v.z, quat_in2.s, quat_in2.v.x, quat_in2.v.y, quat_in2.v.z);
        D3DRMQUATERNION *rc = D3DRMQuaternionMultiply(&out, &quat_in1, &quat_in2);
        SDLTest_AssertCheck(rc == &out, "D3DRMQuaternionMultiply returns correct pointer: got %p, expected %p", rc, &out);
        double delta1 = float_delta(out.s, ref_out.s);
        double delta2 = float_delta(out.v.x, ref_out.v.x);
        double delta3 = float_delta(out.v.y, ref_out.v.y);
        double delta4 = float_delta(out.v.z, ref_out.v.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON && delta4 < EPSILON,
            "Got {%f, {%f, %f, %f}}, expected {%f, {%f, %f, %f}} (delta={%g, {%g, %g, %g}})",
            out.s, out.v.x, out.v.y, out.v.z, ref_out.s, ref_out.v.x, ref_out.v.y, ref_out.v.z, delta1, delta2, delta3, delta4);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMQuaternionMultiply  = {
    d3drm_D3DRMQuaternionMultiply, "d3drm_D3DRMQuaternionMultiply", "Test D3DRMQuaternionMultiply", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMQuaternionSlerp(void *arg) {
    const float SQRT2_F = SDL_sqrtf(2.f);
    const float SQRT3_F = SDL_sqrtf(3.f);
    const struct {
        D3DRMQUATERNION quat_in1;
        D3DRMQUATERNION quat_in2;
        D3DVALUE alpha_in;
        D3DRMQUATERNION out;
    } test_cases[] = {
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                {-1.f,      {{0.f},               {0.f},              {0.f}}},                  0.f,    {1.f,       {{0.f},               {0.f},              {0.f}}} },
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                {-1.f,      {{0.f},               {0.f},              {0.f}}},                  1.f,    {1.f,       {{0.f},               {0.f},              {0.f}}} },
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                { 0.f,      {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}},            0.f,    {1.f,       {{0.f},               {0.f},              {0.f}}} },
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                { 0.f,      {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}},            .5f,    {1/SQRT2_F, {{1/SQRT3_F/SQRT2_F}, {1/SQRT3_F/SQRT2_F},{1/SQRT3_F/SQRT2_F}}} },
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                { 0.f,      {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}},            1.f,    {0.f,       {{1/SQRT3_F},         {1/SQRT3_F},        {1/SQRT3_F}}} },
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                {-1.f,      {{0.f},               {0.f},              {0.f}}},                  0.f,    {1.f,       {{0.f},               {0.f},              {0.f}}} },
        { {1.f,       {{0.f},               {0.f},              {0.f}}},                {-1.f,      {{0.f},               {0.f},              {0.f}}},                  1.f,    {1.f,       {{0.f},               {0.f},              {0.f}}} },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DRMQUATERNION quat_in1 = test_cases[i].quat_in1;
        const D3DRMQUATERNION quat_in2 = test_cases[i].quat_in2;
        const D3DVALUE alpha_in = test_cases[i].alpha_in;
        const D3DRMQUATERNION ref_out = test_cases[i].out;
        D3DRMQUATERNION out;
        SDLTest_AssertPass("D3DRMQuaternionSlerp({%f, {%f, %f, %f}}, {%f, {%f, %f, %f}}, %f)", quat_in1.s, quat_in1.v.x, quat_in1.v.y, quat_in1.v.z, quat_in2.s, quat_in2.v.x, quat_in2.v.y, quat_in2.v.z, alpha_in);
        D3DRMQUATERNION *rc = D3DRMQuaternionSlerp(&out, &quat_in1, &quat_in2, alpha_in);
        SDLTest_AssertCheck(rc == &out, "D3DRMQuaternionSlerp returns correct pointer: got %p, expected %p", rc, &out);
        double delta1 = float_delta(out.s, ref_out.s);
        double delta2 = float_delta(out.v.x, ref_out.v.x);
        double delta3 = float_delta(out.v.y, ref_out.v.y);
        double delta4 = float_delta(out.v.z, ref_out.v.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON && delta4 < EPSILON,
            "Got {%f, {%f, %f, %f}}, expected {%f, {%f, %f, %f}} (delta={%g, {%g, %g, %g}})",
            out.s, out.v.x, out.v.y, out.v.z, ref_out.s, ref_out.v.x, ref_out.v.y, ref_out.v.z, delta1, delta2, delta3, delta4);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMQuaternionSlerp  = {
    d3drm_D3DRMQuaternionSlerp, "d3drm_D3DRMQuaternionSlerp", "Test D3DRMQuaternionSlerp", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorRotate(void *arg) {
    const float SQRT3_F = SDL_sqrtf(3.f);
    const struct {
        D3DVECTOR vec_in;
        D3DVECTOR axis_in;
        D3DVALUE angle_in;
        D3DVECTOR out;
    } test_cases[] = {
        { {{4.f}, {0.f}, {0.f}},  {{0.f}, {0.f}, {5.f}},   SDL_PI_F,    {{-1.f}, { 0.f}, { 0.f}} },
        { {{9.f}, {0.f}, {0.f}},  {{0.f}, {0.f}, {5.f}},   SDL_PI_F/2,  {{ 0.f}, { 1.f}, { 0.f}} },
        { {{3.f}, {0.f}, {0.f}},  {{0.f}, {0.f}, {5.f}},  -SDL_PI_F/2,  {{ 0.f}, {-1.f}, { 0.f}} },
        { {{0.f}, {2.f}, {0.f}},  {{4.f}, {0.f}, {0.f}},   SDL_PI_F/2,  {{ 0.f}, { 0.f}, { 1.f}} },
        { {{0.f}, {2.f}, {0.f}},  {{4.f}, {0.f}, {0.f}},  -SDL_PI_F/2,  {{ 0.f}, { 0.f}, {-1.f}} },
        { {{0.f}, {0.f}, {2.f}},  {{4.f}, {0.f}, {0.f}},   SDL_PI_F/2,  {{ 0.f}, {-1.f}, { 0.f}} },
        { {{0.f}, {0.f}, {2.f}},  {{4.f}, {0.f}, {0.f}},  -SDL_PI_F/2,  {{ 0.f}, { 1.f}, { 0.f}} },
        { {{4.f}, {4.f}, {4.f}},  {{0.f}, {0.f}, {1.f}},   SDL_PI_F,    {{-1.f/SQRT3_F}, {-1.f/SQRT3_F}, { 1.f/SQRT3_F}} },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR vec_in = test_cases[i].vec_in;
        D3DVECTOR axis_in = test_cases[i].axis_in;
        const D3DVALUE angle_in = test_cases[i].angle_in;
        const D3DVECTOR ref_out = test_cases[i].out;
        D3DVECTOR out;
        SDLTest_AssertPass("D3DRMVectorRotate({%f, %f, %f}, {%f, %f, %f}, %f)", vec_in.x, vec_in.y, vec_in.z, axis_in.x, axis_in.y, axis_in.z, angle_in);
        D3DVECTOR *rc = D3DRMVectorRotate(&out, &vec_in, &axis_in, angle_in);
        SDLTest_AssertCheck(rc == &out, "D3DRMVectorRotate returns correct pointer: got %p, expected %p", rc, &out);
        D3DVALUE norm_axis = axis_in.x * axis_in.x + axis_in.y * axis_in.y + axis_in.z * axis_in.z;
        double delta_one = float_delta(1., norm_axis);
        SDLTest_AssertCheck(delta_one < EPSILON, "D3DRMVectorRotate made normalized axis");
        double delta1 = float_delta(out.x, ref_out.x);
        double delta2 = float_delta(out.y, ref_out.y);
        double delta3 = float_delta(out.z, ref_out.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON,
            "Got {%f, %f, %f}, expected {%f, %f, %f} (delta={%g, %g, %g})",
            out.x, out.y, out.z, ref_out.x, ref_out.y, ref_out.z, delta1, delta2, delta3);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorRotate  = {
    d3drm_D3DRMVectorRotate, "d3drm_D3DRMVectorRotate", "Test D3DRMVectorRotate", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMVectorReflect(void *arg) {
    const float SQRT2_F = SDL_sqrtf(2.f);
    const struct {
        D3DVECTOR ray;
        D3DVECTOR normal;
        D3DVECTOR out;
    } test_cases[] = {
        { {{ 0.f}, { 0.f}, { 1.f}},  {{ 0.f}, { 1.f}, { 0.f}}, {{ 0.f}, { 0.f}, {-1.f}} },
        { {{-3.f}, {-4.f}, { 0.f}},  {{ 0.f}, { 1.f}, { 0.f}}, {{ 3.f}, {-4.f}, { 0.f}} },
        { {{ 1.f}, { 1.f}, { 0.f}},  {{ -1/SQRT2_F}, { -1/SQRT2_F}, { 0.f}}, {{1.f}, {1.f}, { 0.f}} },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DVECTOR ray_in = test_cases[i].ray;
        const D3DVECTOR normal_in = test_cases[i].normal;
        const D3DVECTOR ref_out = test_cases[i].out;
        D3DVECTOR out;
        SDLTest_AssertPass("D3DRMVectorReflect({%f, %f, %f}, {%f, %f, %f})", ray_in.x, ray_in.y, ray_in.z, normal_in.x, normal_in.y, normal_in.z);
        D3DVECTOR *rc = D3DRMVectorReflect(&out, &ray_in, &normal_in);
        SDLTest_AssertCheck(rc == &out, "D3DRMVectorReflect returns correct pointer: got %p, expected %p", rc, &out);
        double delta1 = float_delta(out.x, ref_out.x);
        double delta2 = float_delta(out.y, ref_out.y);
        double delta3 = float_delta(out.z, ref_out.z);
        SDLTest_AssertCheck(delta1 < EPSILON && delta2 < EPSILON && delta3 < EPSILON,
            "Got {%f, %f, %f}, expected {%f, %f, %f} (delta={%g, %g, %g})",
            out.x, out.y, out.z, ref_out.x, ref_out.y, ref_out.z, delta1, delta2, delta3);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMVectorReflect  = {
    d3drm_D3DRMVectorReflect, "d3drm_D3DRMVectorReflect", "Test D3DRMVectorReflect", TEST_ENABLED
};

static int SDLCALL d3drm_D3DRMMatrixFromQuaternion(void *arg) {
    const float COS45_F = SDL_cosf(SDL_PI_F / 4);
    const float SIN45_F = SDL_sinf(SDL_PI_F / 4);
    const float COS22_5_F = SDL_cosf(SDL_PI_F / 8);
    const float SIN22_5_F = SDL_sinf(SDL_PI_F / 8);
    const struct {
        D3DRMQUATERNION rot;
        D3DRMMATRIX4D out;
    } test_cases[] = {
        { { 1.f, { {0.f}, {0.f}, {0.f} }},         { { 1.f, 0.f, 0.f, 0.f}, { 0.f, 1.f, 0.f, 0.f}, { 0.f, 0.f, 1.f, 0.f}, { 0.f, 0.f, 0.f, 1.f} } },
        { { 0.f, { {1.f}, {0.f}, {0.f} }},         { { 1.f, 0.f, 0.f, 0.f}, { 0.f,-1.f, 0.f, 0.f}, { 0.f, 0.f,-1.f, 0.f}, { 0.f, 0.f, 0.f, 1.f} } },
        { { COS45_F, { {SIN45_F}, {0.f}, {0.f} }}, { { 1.f, 0.f, 0.f, 0.f}, { 0.f, 0.f,-1.f, 0.f}, { 0.f, 1.f, 0.f, 0.f}, { 0.f, 0.f, 0.f, 1.f} } },
        { { COS45_F, { {0.f}, {SIN45_F}, {0.f} }}, { { 0.f, 0.f, 1.f, 0.f}, { 0.f, 1.f, 0.f, 0.f}, {-1.f, 0.f, 0.f, 0.f}, { 0.f, 0.f, 0.f, 1.f} } },
        { { COS45_F, { {0.f}, {0.f}, {SIN45_F} }}, { { 0.f,-1.f, 0.f, 0.f}, { 1.f, 0.f, 0.f, 0.f}, { 0.f, 0.f, 1.f, 0.f}, { 0.f, 0.f, 0.f, 1.f} } },
        { { COS22_5_F, { {0.f}, {0.f}, {SIN22_5_F} }}, { { COS45_F,-SIN45_F, 0.f, 0.f}, { SIN45_F, COS45_F, 0.f, 0.f}, { 0.f, 0.f, 1.f, 0.f}, { 0.f, 0.f, 0.f, 1.f} } },
    };
    (void) arg;
    for (unsigned i = 0; i < SDL_arraysize(test_cases); i++) {
        const D3DRMQUATERNION rot_in = test_cases[i].rot;
        D3DRMMATRIX4D ref_out;
        SDL_memcpy(ref_out, test_cases[i].out, sizeof(ref_out));
        D3DRMMATRIX4D out;
        SDLTest_AssertPass("D3DRMMatrixFromQuaternion({%f, {%f, %f, %f})", rot_in.s, rot_in.v.x, rot_in.v.y, rot_in.v.z);
        D3DRMMatrixFromQuaternion(out, &rot_in);
        double deltas[4][4];
        bool good = true;
        for (unsigned j = 0; j < 4; j++) {
            for (unsigned k = 0; k < 4; k++) {
                deltas[j][k] = float_delta(ref_out[j][k], out[j][k]);
                good = good && deltas[j][k] < EPSILON;
            }
        }
        SDLTest_Log("Got {{%f, %f, %f, %f}, {%f, %f, %f, %f}, {%f, %f, %f, %f}, {%f, %f, %f, %f}},",
            out[0][0], out[0][1], out[0][2], out[0][3], out[1][0], out[1][1], out[1][2], out[1][3], out[2][0], out[2][1], out[2][2], out[2][3], out[3][0], out[3][1], out[3][2], out[3][3]);
        SDLTest_Log("expected {{%f, %f, %f, %f}, {%f, %f, %f, %f}, {%f, %f, %f, %f}, {%f, %f, %f, %f}},",
            ref_out[0][0], ref_out[0][1], ref_out[0][2], ref_out[0][3], ref_out[1][0], ref_out[1][1], ref_out[1][2], ref_out[1][3], ref_out[2][0], ref_out[2][1], ref_out[2][2], ref_out[2][3], ref_out[3][0], ref_out[3][1], ref_out[3][2], ref_out[3][3]);
        SDLTest_AssertCheck(good, "deltas={{%g, %g, %g, %g}, {%g, %g, %g, %g}, {%g, %g, %g, %g}, {%g, %g, %g, %g}},",
            deltas[0][0], deltas[0][1], deltas[0][2], deltas[0][3], deltas[1][0], deltas[1][1], deltas[1][2], deltas[1][3], deltas[2][0], deltas[2][1], deltas[2][2], deltas[2][3], deltas[3][0], deltas[3][1], deltas[3][2], deltas[3][3]);
    }
    return TEST_COMPLETED;
}

static const SDLTest_TestCaseReference d3drmD3DRMMatrixFromQuaternion  = {
    d3drm_D3DRMMatrixFromQuaternion, "d3drm_D3DRMMatrixFromQuaternion", "Test D3DRMMatrixFromQuaternion", TEST_ENABLED
};

static const SDLTest_TestCaseReference *d3drmTests[] = {
    &d3drmD3DRMColorGetRed,
    &d3drmD3DRMColorGetGreen,
    &d3drmD3DRMColorGetBlue,
    &d3drmD3DRMColorGetAlpha,
    &d3drmD3DRMCreateColorRGB,
    &d3drmD3DRMCreateColorRGBA,
    &d3drmD3DRMVectorAdd,
    &d3drmD3DRMVectorSubtract,
    &d3drmD3DRMVectorModulus,
    &d3drmD3DRMVectorRandom,
    &d3drmD3DRMVectorNormalize,
    &d3drmD3DRMVectorScale,
    &d3drmD3DRMVectorDotProduct,
    &d3drmD3DRMQuaternionFromRotation,
    &d3drmD3DRMVectorCrossProduct,
    &d3drmD3DRMQuaternionMultiply,
    &d3drmD3DRMQuaternionSlerp,
    &d3drmD3DRMVectorRotate,
    &d3drmD3DRMVectorReflect,
    &d3drmD3DRMMatrixFromQuaternion,
    NULL
};

static SDLTest_TestSuiteReference d3drmTestSuite = {
    "d3drm",
    NULL,
    d3drmTests,
    NULL
};

static SDLTest_TestSuiteReference *testSuites[] = {
    &d3drmTestSuite,
    NULL
};

static const char *options[] = {
    NULL
};

int main(int argc, char *argv[])
{
    int i;
    int result;
    SDLTest_CommonState *state;
    SDLTest_TestSuiteRunner *runner;

    /* Initialize test framework */
    state = SDLTest_CommonCreateState(argv, 0);
    if (!state) {
        return 1;
    }

    runner = SDLTest_CreateTestSuiteRunner(state, testSuites);

    /* Parse commandline */
    for (i = 1; i < argc;) {
        int consumed;

        consumed = SDLTest_CommonArg(state, i);
        if (!consumed) {
            /* Parse extra arguments here */
        }
        if (consumed <= 0) {
            SDLTest_CommonLogUsage(state, argv[0], options);
            return 1;
        }

        i += consumed;
    }

    result = SDLTest_ExecuteTestSuiteRunner(runner);

    SDL_Quit();
    SDLTest_DestroyTestSuiteRunner(runner);
    SDLTest_CommonDestroyState(state);
    return result;
}
