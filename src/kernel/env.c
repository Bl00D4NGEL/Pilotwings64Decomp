#include "common.h"

static f32 D_80248DE0[] = { 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 1, 0 };
static f32 D_80248E10 = 0;
static f32 D_80248E14[] = { 0, 0, 1 };

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/env/uvEnvProps.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/env/uvEnvProps2.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/env/uvEnvFunc.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/env/func_80218700.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/env/_uvEnvDraw.s")

