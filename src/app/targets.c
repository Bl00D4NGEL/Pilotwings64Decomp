#include "common.h"
#include "targets.h"
#include "code_9A960.h"
#include "hud.h"
#include <uv_dobj.h>

typedef struct {
    Vec3F position;
    Vec3F angle;
    u8 targetType;
    u8 unk19;
    s32 pad1C;
} MissileTarget; // size = 0x20


f32 D_803506A0[] = {
    0.0f, 0.0f, 0.0f, 0.0f,  0.0f,  0.0f, 0.0f, 0.0f, 1.0f,  5.0f,  0.05f, 0.0f, 0.0f,  0.975f, 5.5f,  0.06f, 0.04f, 0.03f, 0.88f, 6.0f,
    0.0f, 0.0f, 0.0f, 0.0f,  17.0f, 0.0f, 0.0f, 0.0f, 0.0f,  18.0f, 0.0f,  0.0f, 0.01f, 0.15f,  18.5f, 0.0f,  0.01f, 0.03f, 0.25f, 19.0f,
    0.0f, 0.0f, 0.0f, 0.65f, 19.5f, 0.0f, 0.0f, 0.0f, 0.96f, 20.0f, 0.0f,  0.0f, 0.0f,  0.99f,  24.0f, 0.0f,  0.0f,  0.0f,  1.0f,
};
s32 D_8035078C = 0;

extern MissileTarget* sMissileTargets;
extern u8 sMissileTargetCount;

void func_80344290(void) {
    s32 i;

    for (i = 0; i < ARRAY_COUNT(D_80378CF8); i++) {
        D_80378CF8[i].unk0 = 0xFFFF;
        D_80378CF8[i].unk46 = 0;
        D_80378CF8[i].unk47 = 0;
        D_80378CF8[i].unk48 = 0xFF;
    }
}

void func_803442F8(void) {
    Unk80378CF8* var_s1;
    s32 i;
    MissileTarget* missileTarget;

    if (D_80362690->unkA0 == 0) {
        return;
    }
    sMissileTargetCount = levelDataGetTARG((void**)&sMissileTargets);
    if (sMissileTargetCount > ARRAY_COUNT(D_80378CF8)) {
        _uvDebugPrintf("targets : too many missile targets defined in level [%d]\n", sMissileTargetCount);
        sMissileTargetCount = 0;
        return;
    }

    if (sMissileTargetCount == 0) {
        return;
    }

    uvLevelAppend(0x12);
    for (i = 0; i < sMissileTargetCount; i++) {
        var_s1 = &D_80378CF8[i];
        missileTarget = &sMissileTargets[i];
        if (var_s1->unk46 == 0) {
            if (var_s1->unk47 == 0) {
                var_s1->unk44 = missileTarget->targetType;
                var_s1->unk45 = missileTarget->unk19;
                func_80313640(missileTarget->position.x, missileTarget->position.y, missileTarget->position.z, missileTarget->angle.x * 0.0174533f, missileTarget->angle.y * 0.0174533f, missileTarget->angle.z * 0.0174533f, &var_s1->unk4);
                var_s1->unk47 = 1;
            }
            var_s1->unk0 = uvDobjAllocIdx();
            var_s1->unk48 = hud_8031A6C8(missileTarget->position.x, missileTarget->position.y, missileTarget->position.z);
            switch (missileTarget->targetType) {
            case 0:
                uvDobjModel(var_s1->unk0, 0xF9);
                break;
            case 1:
                uvDobjModel(var_s1->unk0, 0xF8);
                break;
            case 2:
                uvDobjModel(var_s1->unk0, 0xF7);
                break;
            default:
                _uvDebugPrintf("targets : unknwwon target type [%d]\n", missileTarget->targetType);
                break;
            }
            uvDobjPosm(var_s1->unk0, 0, &var_s1->unk4);
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/targets/func_8034450C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/targets/func_8034467C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/app/targets/func_8034473C.s")

u8 func_803448F4(void) {
    u8 ret;
    s32 i;

    ret = 0;
    for (i = 0; i < sMissileTargetCount; i++) {
        ret += D_80378CF8[i].unk46;
    }
    return ret;
}

#pragma GLOBAL_ASM("asm/nonmatchings/app/targets/func_80344948.s")
