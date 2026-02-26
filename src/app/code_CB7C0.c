#include "common.h"
#include "code_CB7C0.h"

f32 D_803506A0[] = {
    0.0f, 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f,  5.0f,  0.05f, 0.0f, 0.0f,  0.975f, 5.5f,  0.06f, 0.04f, 0.03f, 0.88f, 6.0f,
    0.0f, 0.0f, 0.0f, 0.0f,  17.0f, 0.0f, 0.0f, 0.0f, 0.0f,  18.0f, 0.0f,  0.0f, 0.01f, 0.15f,  18.5f, 0.0f,  0.01f, 0.03f, 0.25f, 19.0f,
    0.0f, 0.0f, 0.0f, 0.65f, 19.5f, 0.0f, 0.0f, 0.0f, 0.96f, 20.0f, 0.0f,  0.0f, 0.0f,  0.99f,  24.0f, 0.0f,  0.0f,  0.0f,  1.0f,
};
s32 D_8035078C = 0;

extern u8 D_80378CF4;

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CB7C0/func_80344290.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CB7C0/func_803442F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CB7C0/func_8034450C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CB7C0/func_8034467C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CB7C0/func_8034473C.s")

u8 func_803448F4(void) {
    u8 ret;
    s32 i;

    ret = 0;
    for (i = 0; i < D_80378CF4; i++) {
        ret += D_80378CF8[i].unk46;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/code_CB7C0/func_80344948.s")
