#include <uv_audio.h>

extern ALSndPlayer* gSndPlayer;
extern ALSndId* gSndVoiceTable;
extern uvaEmitter_t gSndEmitterTable[];
extern uvaEmitter_t D_8025BE48;

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/osSyncPrintf.s")
void osSyncPrintf(const char *fmt, ...) {
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterInitTable.s")
void uvEmitterInitTable(void) {
    uvaEmitter_t *term = &D_8025BE48, *iter = gSndEmitterTable;
    do {
        uvEmitterInit(iter);
        iter++;
    } while (iter != term);
    uvEmitterInit(term);
}


// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterInit.s")
void uvEmitterInit(uvaEmitter_t* obj) {
    Mtx4F_t temp;

    Mat4_SetIdentity(temp);
    obj->playVoice = 0x11;
    obj->playState = 0;
    obj->playVolume = 0x7FFF;
    obj->playPan = 0x40;
    obj->playMix = 0;
    obj->playTimeout = 0;
    obj->playPitch = 1.0f;

    Mat4_Copy(obj->m1, temp);
    obj->sound = 0xFF;
    obj->priority = 0;
    obj->unk98 = 0;
    obj->state = 0;

    obj->m2[0][0] = 0.0f;
    obj->m2[0][1] = 0.0f;
    obj->m2[0][2] = 0.0f;
    obj->m2[0][3] = 0.0f;

    obj->m2[1][0] = 0.0f;
    obj->m2[1][1] = 0.0f;

    obj->m2[3][0] = 1.0f;
    obj->m2[3][1] = 1.0f;
    obj->m2[3][2] = 0.0f;
    obj->m2[3][3] = 0.0f;

    obj->unk80 = 0.0f;
    obj->unk84 = 0.0f;
    obj->near = 0.0f;
    obj->far = 1000.0f;
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterLookup.s")
u8 uvEmitterLookup(void) {
    u8 obj_id;

    osSyncPrintf("looking for emitter\n");
    obj_id = 0; while (1) {
        if (gSndEmitterTable[obj_id].sound == 0xFF) {
            osSyncPrintf("Returning emitter %d\n", obj_id);
            return obj_id;
        }

        if (++obj_id >= 0xFF) {
            _uvDebugPrintf("no free emitters\n");
            return 0xFFU;
        }
    }
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterFromModel.s")
void uvEmitterFromModel(u8 obj_id, u8 mdl_id) {
    osSyncPrintf("assigning model %d to emitter %d\n", mdl_id, obj_id);
    if (obj_id < 0xFF) {
        if (gSndEmitterTable[obj_id].playState != 0x11) {
            _uvaStopVoice(gSndEmitterTable[obj_id].playVoice);
            gSndEmitterTable[obj_id].playState = 0;
            gSndEmitterTable[obj_id].playVoice = 0x11U;
            gSndEmitterTable[obj_id].playTimeout = 0;
        }
        uvEmitterInit(&gSndEmitterTable[obj_id]);
        gSndEmitterTable[obj_id].sound = mdl_id;
    }
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_802013F8.s")
void uvEmitterSetMatrix(u8 obj_id, Mtx4F_t msrc) {
    if (obj_id < 0xFF) {
        Mat4_Copy(gSndEmitterTable[obj_id].m1, msrc);
    }
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_80201444.s")
void uvEmitterGetMatrix(u8 obj_id, Mtx4F_t mdst) {
    if (obj_id < 0xFF) {
        Mat4_Copy(mdst, gSndEmitterTable[obj_id].m1);
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_80201494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_802015D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_80201614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_8020165C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_80201698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_802016D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterProp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterTrigger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterRelease.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterStatus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaSoundBegin.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaSoundEnd.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/uvEmitterFlush.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/func_80201D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaUpdatePlayList.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaPlaylistRemove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaPlay.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaStartVoice.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaUpdateVoice.s")
void _uvaUpdateVoice(u8 obj_id) {
    uvaEmitter_t* obj;

    obj = &gSndEmitterTable[obj_id];
    osSyncPrintf("\n  updating voice %d on object %d\n", obj->playVoice, obj_id);

    alSndpSetSound(gSndPlayer, gSndVoiceTable[obj->playVoice]);
    alSndpSetVol(gSndPlayer, obj->playVolume);
    alSndpSetPitch(gSndPlayer, obj->playPitch);
    alSndpSetFXMix(gSndPlayer, obj->playMix);
    alSndpSetPan(gSndPlayer, obj->playPan);
}

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaStopVoice.s")
void _uvaStopVoice(u8 voice_id) {
    if (voice_id < 0x10) {
        osSyncPrintf("stopping voice%d\n", voice_id);
        alSndpSetSound(gSndPlayer, gSndVoiceTable[voice_id]);
        if (alSndpGetState(gSndPlayer) == 1) {
            alSndpSetVol(gSndPlayer, 0);
        }
        alSndpStop(gSndPlayer);
        return;
    }
    osSyncPrintf("%d is not a valid voice\n", voice_id);
}

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/emitter/_uvaStatus.s")
void _uvaStatus(u8 obj_id) {
    uvaEmitter_t* obj;

    obj = &gSndEmitterTable[obj_id];
    osSyncPrintf("-----object %d------\n", obj_id);
    osSyncPrintf("playVoice  = %d\n", obj->playVoice);
    osSyncPrintf("playState  = %d\n", obj->playState);
    osSyncPrintf("playTimeout= %d\n", obj->playTimeout);
    osSyncPrintf("playVolume = %d\n", obj->playVolume);
    osSyncPrintf("playPitch  = %f\n", obj->playPitch);
    osSyncPrintf("playPan    = %d\n", obj->playPan);
    osSyncPrintf("near       = %f\n", obj->near);
    osSyncPrintf("far        = %f\n", obj->far);
    osSyncPrintf("sound      = %d\n", obj->sound);
    osSyncPrintf("priority   = %d\n", obj->priority);
    osSyncPrintf("state      = %d\n", obj->state);
}

