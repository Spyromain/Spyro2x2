#ifndef SP2X2_H_INCLUDED
#define SP2X2_H_INCLUDED


extern int sp2x2_current_player;
extern int sp2x2_current_dialogue_player;

extern int sp2x2_tick_counter;
extern int sp2x2_ticks;
extern int sp2x2_level_timer;

extern unsigned char sp2x2_actuator_data[4];

extern int sp2x2_is_reticle_displayed;

extern int sp2x2_8006c7e0;

extern unsigned char sp2x2_spyro_flames[304];
extern unsigned char sp2x2_spyro[708];
extern unsigned char sp2x2_calculation_results[56];
extern unsigned char sp2x2_camera[500];
extern unsigned char sp2x2_8006eba8[256];
extern unsigned char sp2x2_spyro_shadow[28];

extern unsigned char sp2x2_pad[128];
extern unsigned char sp2x2_pad_2[128];
extern unsigned char sp2x2_pad_queue[64];

extern void *sp2x2_rayz;

extern unsigned char sp2x2_skin_color;


extern void Sp2x2LoadText(void);
extern void Sp2x2HelloWorld(void);
extern void Sp2x2Swap(void *restrict first, void *restrict second, int count);
extern void Sp2x2InitPad(void);
extern void Sp2x2VSyncCallback(void);
extern void Sp2x2InitSpyroTwin(void);
extern void Sp2x2LogicSpyro(void);
extern void Sp2x2LogicController(void);
extern void Sp2x2RenderSpyro(void);
extern void Sp2x2StopCutscene(int param_1);


#endif /* SP2X2_H_INCLUDED */
