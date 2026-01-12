#include "common.h"
#include <uv_matrix.h>

extern s32 D_8024B2C0;

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvRandSeed.s")
void uvRandSeed(s32 seed) {
    D_8024B2C0 = seed;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/func_802315EC.s")

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvRandF.s")
#else
f32 uvRandF(void) {
    D_8024B2C0 = (D_8024B2C0 * 0x41C64E6D) + 0x3039;
    if (((D_8024B2C0 >> 0x10) & 0x7FFF) < 0) {
        return ((D_8024B2C0 >> 0x10) & 0x7FFF) + 4294967296.0f;
    }
    return ((D_8024B2C0 >> 0x10) & 0x7FFF) / 32767.0f;
}

#endif

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvAbs.s")
s32 uvAbs(s32 x) {
    if (x > 0) {
        return x;
    } else {
        return -x;
    }
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3Len.s")
f32 uvVec3Len(Vec3F_t v) {
    f32 x = v[0];
    f32 y = v[1];
    f32 z = v[2];
    return SqrtF((x * x) + (y * y) + (z * z));
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec2Dot.s")
f32 uvVec2Dot(Vec3F_t v0, Vec3F_t v1) {
    return (v0[1] * v1[1]) + (v1[0] * v0[0]);
}

#if 1
#pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3Dot.s")
#else
f32 uvVec3Dot(Vec3F_t v0, Vec3F_t v1) {
    return (v0[0] * v1[0]) + (v0[1] * v1[1]) + (v1[2] * v0[2]);
}
#endif

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3Copy.s")
void uvVec3Copy(Vec3F_t vdst, Vec3F_t vsrc) {
    vdst[0] = vsrc[0];
    vdst[1] = vsrc[1];
    vdst[2] = vsrc[2];
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3ScalarProj.s")
f32 uvVec3ScalarProj(Vec3F_t v0, Vec3F_t v1) {
    f32 len;
    f32 dot;

    dot = uvVec3Dot(v0, v1);
    len = uvVec3Len(v0);
    return dot / (uvVec3Len(v1) * len);
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3Cross.s")
void uvVec3Cross(Vec3F_t vd, Vec3F_t va, Vec3F_t vb) {
    f32 ax = va[0], ay = va[1], az = va[2];
    f32 bx = vb[0], by = vb[1], bz = vb[2];

    vd[0] =  ((ay * bz) - (az * by));
    vd[1] = -((ax * bz) - (az * bx));
    vd[2] =  ((ax * by) - (ay * bx));
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3Add.s")
void uvVec3Add(Vec3F_t vd, Vec3F_t va, Vec3F_t vb) {
    vd[0] = vb[0] + va[0];
    vd[1] = vb[1] + va[1];
    vd[2] = vb[2] + va[2];
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3Mul.s")
void uvVec3Mul(Vec3F_t vd, Vec3F_t va, f32 sb) {
    vd[0] = va[0] * sb;
    vd[1] = va[1] * sb;
    vd[2] = va[2] * sb;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/math/uvVec3Normal.s")
s32 uvVec3Normal(Vec3F_t vd, Vec3F_t va) {
    f32 ax = va[0], ay = va[1], az = va[2];
    f32 len, len_inv;

    len = SqrtF((ax * ax) + (ay * ay) + (az * az));
    if (len == 0.0f) {
        return 0;
    }
    len_inv = 1.0f / len;
    vd[0] = (f32) (ax * len_inv);
    vd[1] = (f32) (ay * len_inv);
    vd[2] = (f32) (az * len_inv);
    return 1;
}

