#ifndef _AUDIO_OUTPUT_DAC_H_
#define _AUDIO_OUTPUT_DAC_H_

#include "typedef.h"

struct audio_stream_dac_out {
    struct audio_stream_entry entry;
};
extern struct audio_stream_dac_out *audio_stream_dac_out_open(void);
extern void audio_stream_dac_out_close(struct audio_stream_dac_out *dac_out);

#define TYPE_DAC_AGAIN      (0x01)
#define TYPE_DAC_DGAIN      (0x02)

extern int audio_dac_vol_set(u8 type, u32 ch, u16 gain, u8 fade_en);
extern int audio_dac_vol_mute(u8 mute, u8 fade);
extern int audio_dac_vol_mute_lock(u8 lock);

struct audio_stream_dac_mix_out {
    struct audio_stream_entry entry;
    u8 dac_chls;
    s16 *last_out_buf;
    int last_out_buf_len;
};
struct audio_stream_dac_mix_out *audio_stream_dac_mix_out_open(u16 delay);
void audio_stream_dac_mix_out_close(struct audio_stream_dac_mix_out *dac_out);

#endif // _AUDIO_OUTPUT_DAC_H_
