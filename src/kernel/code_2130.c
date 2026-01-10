#include <uv_audio.h>

extern ALSndPlayer* gSndPlayer;
extern ALSndId* gSndVoiceTable;
extern uvaEmitter_t gSndEmitterTable[];

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/osSyncPrintf.s")
void osSyncPrintf(const char *fmt, ...) {
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_8020119C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802011F0.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterLookup.s")
u8 uvEmitterLookup(void) {
    u8 var_v1;

    osSyncPrintf("looking for emitter\n");
    var_v1 = 0; while (1) {
        if (gSndEmitterTable[var_v1].sound == 0xFF) {
            osSyncPrintf("Returning emitter %d\n", var_v1);
            return var_v1;
        }

        if (++var_v1 >= 0xFF) {
            _uvDebugPrintf("no free emitters\n");
            return 0xFFU;
        }
    }
}

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterFromModel.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802013F8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201444.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201494.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802015D8.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201614.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_8020165C.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201698.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_802016D4.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterProp.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterTrigger.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterRelease.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterStatus.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaSoundBegin.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaSoundEnd.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/uvEmitterFlush.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/func_80201D08.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaUpdatePlayList.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaPlaylistRemove.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaPlay.s")

#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaStartVoice.s")

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaUpdateVoice.s")
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

// #pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaStopVoice.s")
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

//#pragma GLOBAL_ASM("asm/nonmatchings/kernel/code_2130/_uvaStatus.s")
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

