#ifndef PILOTWINGS64_UV_AUDIO
#define PILOTWINGS64_UV_AUDIO

#include <ultra64.h>
#include <uv_util.h>

typedef struct uvaEmitter {
/* 00 */ u8 pad[0x88];
/* 88 */ s32 priority;
/* 8C */ u8 sound;
/* 8D */ u8 unk8D;
/* 8E */ u8 unk8E;
/* 8F */ u8 unk8F;
/* 90 */ float near;
/* 94 */ float far;
/* 98 */ s32 unk98;
/* 9C */ float playPitch;
/* A0 */ s32 playState;
/* A4 */ s32 playVolume;
/* A8 */ s32 state;
/* AC */ u8 playVoice;
/* AD */ u8 playPan;
/* AE */ u8 playMix;
/* AF */ u8 playTimeout;
} uvaEmitter_t;

void uvaSeqPlay(void);
void uvaSeqSetTempo(f32 tempo);
void uvaSeqSetVol(f32 vol);
void uvaSeqStop(void);

#endif // PILOTWINGS64_UV_AUDIO

