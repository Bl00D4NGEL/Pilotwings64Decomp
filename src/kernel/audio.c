#include "common.h"

extern s32 D_8025C5B0;
extern s32 D_8025C630;

static s32 D_80248C80 = 0x00000000;
static s32 D_80248C84 = 0x00000000;
static s32 D_80248C88 = 0x00000000;
static s32 D_80248C8C = 0x80000400;
s32* gSeqPlayer = &D_8025C5B0;
s32* gSndPlayer = &D_8025C630;

// clang-format off
static s32 D_80248C98[] = {
    0x00000008, 0x00001450, 0x00000000, 0x00000640, 0x00002666, 0xFFFFD99A,
    0x00000BB8, 0x00000000, 0x00000000, 0x00000000, 0x00000040, 0x00000E10,
    0x00002666, 0xFFFFD99A, 0x000007D0, 0x00000000, 0x00000000, 0x00005000,
    0x00000290, 0x00000800, 0x00004000, 0xFFFFC000, 0x000023D6, 0x00000000,
    0x00000000, 0x00000000, 0x000002D0, 0x00000670, 0x00002000, 0xFFFFE000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000A20, 0x000011A0,
    0x00004000, 0xFFFFC000, 0x000023D6, 0x00000000, 0x00000000, 0x00006000,
    0x00000A60, 0x00000EE0, 0x00002000, 0xFFFFE000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000EE0, 0x000010C0, 0x00002000, 0xFFFFE000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x000012B0,
    0x00004650, 0x00000000, 0x00000000, 0x00000000, 0x00000000, 0x00007000,
};

static s32 D_80248DA0[] = {
    0x00000001, 0x00000000, 0x00000000, 0x00000000,
};
// clang-format on

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/uvSysInitAudio.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/func_80203B08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/Thread_Audio.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/func_80203F4C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/uvGetSamples.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/func_80204168.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/func_802042E4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/func_8020431C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/func_80204438.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/audio/func_80204518.s")

