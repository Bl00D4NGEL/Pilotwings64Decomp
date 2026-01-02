#ifndef PILOTWINGS64_UV_MATRIX
#define PILOTWINGS64_UV_MATRIX

#include <ultra64.h>

typedef float Mtx4F_t[4][4];

typedef union {
    Mtx4F_t mf;
    struct {
        float xx, yx, zx, wx,
              xy, yy, zy, wy,
              xz, yz, zz, wz,
              xw, yw, zw, ww;
    };
} MtxF;

void Mat4_Copy(Mtx4F_t m_dst, Mtx4F_t m_src);
void Mat3_Copy(Mtx4F_t m_dst, Mtx4F_t m_src);
void Mat4_SetIdentity(Mtx4F_t arg0);
void Mat4_SetUnk1(Mtx_t mat);

#endif // PILOTWINGS64_UV_MATRIX

