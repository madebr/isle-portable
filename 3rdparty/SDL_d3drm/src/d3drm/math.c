#include "d3drm.h"

#include <stdlib.h>

D3DRMQUATERNION * WINAPI D3DRMQuaternionFromRotation(D3DRMQUATERNION *x, D3DVECTOR *axis, D3DVALUE theta) {
    D3DRMVectorNormalize(axis);
    float c = SDL_cosf(0.5f * theta);
    float s = SDL_sinf(0.5f * theta);
    x->s = c;
    x->v.x = s * axis->x;
    x->v.y = s * axis->y;
    x->v.z = s * axis->z;
    return x;
}

D3DRMQUATERNION * WINAPI D3DRMQuaternionMultiply(D3DRMQUATERNION *ret, const D3DRMQUATERNION *x, const D3DRMQUATERNION *y) {
    D3DVECTOR a;
    D3DVECTOR b;
    D3DVALUE v = D3DRMVectorDotProduct(&x->v, &y->v);
    D3DRMVectorScale(&a, &y->v, x->s);
    D3DRMVectorScale(&b, &x->v, y->s);
    D3DRMVectorAdd(&a, &a, &b);
    D3DRMVectorCrossProduct(&b, &x->v, &y->v);
    D3DRMVectorAdd(&ret->v, &a, &b);
    ret->s = x->s * y->s - v;
    return ret;
}

D3DRMQUATERNION * WINAPI D3DRMQuaternionSlerp(D3DRMQUATERNION *ret, const D3DRMQUATERNION *x, const D3DRMQUATERNION *y, D3DVALUE alpha) {
    D3DVALUE c = x->s * y->s + D3DRMVectorDotProduct(&x->v, &y->v);
    const bool neg = c < 0.0f;
    D3DVALUE f_x, f_y;
    if (neg) {
        c = -c;
    }
    if (1.0f - c >= 0.0001f) {
        const D3DVALUE a = SDL_acosf(c);
        const D3DVALUE s = SDL_sinf(a);
        const D3DVALUE f = 1 / s;
        f_x = f * SDL_sinf(a - a * alpha);
        f_y = f * SDL_sinf(a * alpha);
    } else {
        f_x = 1.f - alpha;
        f_y = alpha;
    }
    if (neg) {
        f_y = -f_y;
    }
    ret->s   = f_x * x->s   + f_y * y->s;
    ret->v.x = f_x * x->v.x + f_y * y->v.x;
    ret->v.y = f_x * x->v.y + f_y * y->v.y;
    ret->v.z = f_x * x->v.z + f_y * y->v.z;
    return ret;
}

D3DVECTOR * WINAPI D3DRMVectorAdd(D3DVECTOR *ret, const D3DVECTOR *x, const D3DVECTOR *y) {
    ret->x = x->x + y->x;
    ret->y = x->y + y->y;
    ret->z = x->z + y->z;
    return ret;
}

D3DVECTOR * WINAPI D3DRMVectorCrossProduct(D3DVECTOR *ret, const D3DVECTOR *x, const D3DVECTOR *y) {
    const D3DVECTOR a = *x;
    const D3DVECTOR b = *y;
    ret->x = a.y * b.z - a.z * b.y;
    ret->y = a.z * b.x - a.x * b.z;
    ret->z = a.x * b.y - a.y * b.x;
    return ret;
}

D3DVALUE WINAPI D3DRMVectorDotProduct(const D3DVECTOR *x, const D3DVECTOR *y) {
    return x->x * y->x + x->y * y->y + x->z * y->z;
}

D3DVECTOR * WINAPI D3DRMVectorNormalize(D3DVECTOR *x) {
    D3DVALUE m = D3DRMVectorModulus(x);
    if (m == 0.f) {
        x->x = 1.f;
        x->y = 0.f;
        x->z = 0.f;
    } else {
        D3DVALUE s = 1.f / m;
        x->x *= s;
        x->y *= s;
        x->z *= s;
    }
    return x;
}

D3DVALUE WINAPI D3DRMVectorModulus(const D3DVECTOR *x) {
    const D3DVECTOR copy = *x;
    return SDL_sqrtf(copy.x * copy.x + copy.y * copy.y + copy.z * copy.z);
}

D3DVECTOR * WINAPI D3DRMVectorRandom(D3DVECTOR *ret) {
    D3DVALUE m;
    do {
        ret->x = 2.f * SDL_randf() - 1;
        ret->y = 2.f * SDL_randf() - 1;
        ret->z = 2.f * SDL_randf() - 1;
        m = D3DRMVectorModulus(ret);
    } while (m == 0.f);
    D3DVALUE s = 1.f / m;
    ret->x *= s;
    ret->y *= s;
    ret->z *= s;
    return ret;
}

D3DVECTOR * WINAPI D3DRMVectorRotate(D3DVECTOR *ret, const D3DVECTOR *x, D3DVECTOR *axis, const D3DVALUE theta) {
    D3DRMVectorNormalize(axis);
    const D3DVALUE c = SDL_cosf(-theta);
    const D3DVALUE s = SDL_sinf(-theta);
    const D3DVALUE one_minus_c = 1.f - c;
    const D3DVECTOR l_axis = *axis;
    const D3DVECTOR l_x = *x;
    const D3DVALUE com1 = l_axis.x * one_minus_c;
    const D3DVALUE com2 = l_axis.y * one_minus_c * l_axis.z;
    ret->x = (com1 * l_axis.z - l_axis.y * s) * l_x.z + (l_axis.z * s + com1 * l_axis.y) * l_x.y + (com1 * l_axis.x + c)                   * l_x.x;
    ret->y = (com1 * l_axis.y - l_axis.z * s) * l_x.x + (l_axis.x * s + com2)            * l_x.z + (l_axis.y * one_minus_c * l_axis.y + c) * l_x.y;
    ret->z = (l_axis.y * s + com1 * l_axis.z) * l_x.x + (com2 - l_axis.x * s)            * l_x.y + (l_axis.z * one_minus_c * l_axis.z + c) * l_x.z;
    D3DRMVectorNormalize(ret);
    return ret;
}

D3DVECTOR * WINAPI D3DRMVectorReflect(D3DVECTOR *ret, const D3DVECTOR *ray, const D3DVECTOR *normal) {
    D3DVECTOR l_ray = *ray;
    D3DVECTOR l_normal = *normal;
    D3DVALUE dot_2 = 2.f * (l_normal.x * l_ray.x + l_normal.y * l_ray.y + l_normal.z * l_ray.z);
    ret->x = l_normal.x * dot_2 - l_ray.x;
    ret->y = l_normal.y * dot_2 - l_ray.y;
    ret->z = l_normal.z * dot_2 - l_ray.z;
    return ret;
}

D3DVECTOR * WINAPI D3DRMVectorScale(D3DVECTOR *ret, const D3DVECTOR *x, const D3DVALUE scale) {
    ret->x = x->x * scale;
    ret->y = x->y * scale;
    ret->z = x->z * scale;
    return ret;
}

D3DVECTOR * WINAPI D3DRMVectorSubtract(D3DVECTOR *ret, const D3DVECTOR *x, const D3DVECTOR *y) {
    ret->x = x->x - y->x;
    ret->y = x->y - y->y;
    ret->z = x->z - y->z;
    return ret;
}

D3DCOLOR WINAPI D3DRMCreateColorRGB(D3DVALUE r, D3DVALUE g, D3DVALUE b) {
    return RGBA_MAKE((int)(255.f * r), (int)(255.f * g), (int)(255.f * b), 0xff);
}

D3DCOLOR WINAPI D3DRMCreateColorRGBA(D3DVALUE r, D3DVALUE g, D3DVALUE b, D3DVALUE a) {
    return RGBA_MAKE((int)(255.f * r), (int)(255.f * g), (int)(255.f * b), (int)(255.f * a));
}

D3DVALUE WINAPI D3DRMColorGetAlpha(D3DCOLOR c) {
    return (float)RGBA_GETALPHA(c) / 255.f;
}

D3DVALUE WINAPI D3DRMColorGetBlue(D3DCOLOR c) {
    return (float)RGBA_GETBLUE(c) / 255.f;
}

D3DVALUE WINAPI D3DRMColorGetGreen(D3DCOLOR c) {
    return (float)RGBA_GETGREEN(c) / 255.f;
}

D3DVALUE WINAPI D3DRMColorGetRed(D3DCOLOR c) {
    return (float)RGBA_GETRED(c) / 255.f;
}

void WINAPI D3DRMMatrixFromQuaternion(D3DRMMATRIX4D m, const D3DRMQUATERNION *q) {
    const D3DRMQUATERNION l_q = *q;
    const D3DVALUE yy = 2.f * l_q.v.y * l_q.v.y;
    const D3DVALUE zz = 2.f * l_q.v.z * l_q.v.z;
    m[0][0] = 1.f - yy - zz;
    const D3DVALUE xy = 2.f * l_q.v.y * l_q.v.x;
    const D3DVALUE zs = 2.f * l_q.v.z * l_q.s;
    m[0][1] = xy - zs;
    const D3DVALUE zx = 2.f * l_q.v.z * l_q.v.x;
    const D3DVALUE ys = 2.f * l_q.v.y * l_q.s;
    m[0][2] = ys + zx;
    m[0][3] = 0.f;
    m[1][0] = zs + xy;
    const D3DVALUE xx = 1.f - 2.f * l_q.v.x * l_q.v.x;
    m[1][1] = xx - zz;
    const D3DVALUE yz = 2.f * l_q.v.y * l_q.v.z;
    const D3DVALUE xs = 2.f * l_q.v.x * l_q.s;
    m[1][2] = yz - xs;
    m[1][3] = 0.f;
    m[2][0] = zx - ys;
    m[2][1] = xs + yz;
    m[2][2] = xx - yy;
    m[2][3] = 0.f;
    m[3][0] = 0.f;
    m[3][1] = 0.f;
    m[3][2] = 0.f;
    m[3][3] = 1.f;
}
