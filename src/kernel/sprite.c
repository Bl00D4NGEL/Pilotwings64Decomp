#include <uv_sprite.h>
#include "common.h"

extern Gfx* gGfxDisplayListHead;
extern s32 gSprtUnkIndex;
extern s32 gSprtUnkTable[];
extern uvSprite_t gSprtTable1[];
extern uvSprite_t gSprtTable2[];
extern uvSprite_t gSprtTable3[];

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/func_80230130.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/func_802301A4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/_uvTxtDraw.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/uvSprtFromBitmap.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/func_80230750.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/func_80230898.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/func_80230954.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/func_80230B98.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/func_80230D30.s")

void uvSprtDraw(s32 sprite_id) {
    uvSprite_t* sprite;

    if (sprite_id >= 0x1F) {
        _uvDebugPrintf("uvSprtDraw: invalid sprite id %d\n", sprite_id);
        return;
    }
    sprite = &gSprtTable1[sprite_id];
    if (sprite->unkA != 0xFFF) {
        spInit(&gGfxDisplayListHead);
        func_80230B98(sprite);
        spFinish(&gGfxDisplayListHead);
        gGfxDisplayListHead--;
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/uvSprtSetBlit.s")

s16 uvSprtGetUnk0(s32 sprite_id) {
    return gSprtTable2[sprite_id].unk0;
}

s16 uvSprtGetUnk1(s32 sprite_id) {
    return gSprtTable3[sprite_id].unk0;
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/sprite/uvSprtProps.s")

void uvSprtUpdateUnk(uvSprite_t* sprite) {
    if (sprite->unk18 != 0) {
        gSprtUnkTable[gSprtUnkIndex] = sprite->unk18;
        gSprtUnkIndex += 1;
    }
    if (sprite->unk1C != 0) {
        gSprtUnkTable[gSprtUnkIndex] = sprite->unk1C;
        gSprtUnkIndex += 1;
    }
}

void uvSprtResetUnk(void) {
    gSprtUnkIndex = 0;
}

