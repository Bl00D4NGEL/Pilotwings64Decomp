#include "common.h"
#include <uv_util.h>
#include <uv_memory.h>
#include <uv_filesystem.h>
#include <uv_vector.h>
#include "code_9A960.h"
#include "code_A6000.h"
#include "code_D19D0.h"

// can be static as soon as func_8034A4F8 is matched
/* static */ s32 func_8034A4A0(void) {
    s32 i;

    for (i = 0; i < 6; i++) {
        if (D_8037DCA0[i].unk350 == 0) {
            return i;
        }
    }

    _uvDebugPrintf("UserPaths : Too many outstanding paths\n");
    return -1;
}

// https://decomp.me/scratch/HFJwu
Unk8037DCA0* func_8034A4F8(s32 arg0);
#pragma GLOBAL_ASM("asm/nonmatchings/app/code_D19D0/func_8034A4F8.s")

void func_8034A840(s32 path) {
    if (D_8037DCA0[path].unk350 != 1) {
        _uvDebugPrintf("UserPaths: Freed unused path %d\n", path);
        return;
    }
    D_8037DCA0[path].unk350 = 0;
}

void func_8034A8B0(Unk8037DCA0* arg0, u8 arg1, f32 arg2) {
    if (arg1) {
        arg0->unk40 = 1;
    } else {
        arg0->unk40 = 0;
        arg0->unk44 = 0.0f;
        arg0->unk48 = 0.0f;
    }
    arg0->unk44 += D_8034F854;
    arg0->unk48 = arg2;
    uvPathPoseLine(&D_8037F098, arg0, arg2);
    func_8031EE48(arg0->unk352, &D_8037F098, 1.0f, 1.0f, 1.0f);
}

void func_8034A950(Unk8034A950 arg0, f32* arg183) {
    arg183[0] = arg0.unk190.f[0];
    arg183[1] = arg0.unk190.f[1];
    arg183[2] = arg0.unk190.f[2];
    arg183[3] = arg0.unk0.f[0];
    arg183[4] = arg0.unk0.f[1];
    arg183[5] = arg0.unk0.f[2];
    arg183[6] = arg0.unk0.f[3];
}
