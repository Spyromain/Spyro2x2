#ifndef SP2_H_INCLUDED
#define SP2_H_INCLUDED

#define SP2_WAD_WAD_SECTOR 500


/* 0x80065fd8 */ extern unsigned char sp2_level_extras[40];

/* 0x8006c57c */ extern int sp2_letterbox_height;

/* 0x8006c580 */ extern int sp2_ticks;
/* 0x8006c5c4 */ extern int sp2_level_timer;
/* 0x8006c5fc */ extern int sp2_tick_counter;

/* 0x8006c5b4 */ extern int sp2_display_letterbox;

/* 0x8006c5b8 */ extern int sp2_is_demo_mode;

/* 0x8006c5d0 */ extern void (*sp2_update_mobys_function)(void);

/* 0x8006c5d4 */ extern void *sp2_8006c5d4;

/* 0x8006c620 */ extern void *sp2_primitives_end;

/* 0x8006c624 */ extern int sp2_8006c624;

/* 0x8006c630 */ extern int sp2_no_graphics;

/* 0x8006c650 */ extern void *sp2_last_primitive;

/* 0x8006c6a8 */ extern unsigned short **sp2_8006c6a8;

/* 0x8006c6b8 */ extern unsigned char sp2_actuator_data[4];

/* 0x8006c6c8 */ extern int sp2_primitives_size;

/* 0x8006c6e0 */ extern void *sp2_primitive_pointers;

/* 0x8006c6e8 */ extern void *sp2_first_particle;
/* 0x8006c6ec */ extern void *sp2_first_moby;

/* 0x8006c71c */ extern void *sp2_current_env;

/* 0x8006c724 */ extern void *sp2_first_dynamic_moby;

/* 0x8006c72c */ extern void *sp2_sparx;

/* 0x8006c728 */ extern int sp2_remaining_primitive_space_size;

/* 0x8006c774 */ extern int sp2_level_timer;

/* 0x8006c780 */ extern void *(*sp2_create_moby_function)(int moby_id, void *parent_moby);

/* 0x8006c7a0 */ extern int sp2_is_reticle_displayed;

/* 0x8006c7a4 */ extern void *(*sp2_create_particles_function)(int count, int id, ...);

/* 0x8006c7d0 */ extern int sp2_fading_alpha;

/* 0x8006c7e0 */ extern int sp2_8006c7e0;

/* 0x8006c7e8 */ extern int sp2_previous_vblank_periods;
/* 0x8006c7ec */ extern int sp2_current_vblank_periods;

/* 0x8006cda8 */ extern unsigned char sp2_spyro_flames[304];
/* 0x8006cfd8 */ extern void *sp2_models[768];
/* 0x8006dbf8 */ extern unsigned char sp2_spyro[708];
/* 0x8006dec0 */ extern unsigned char sp2_calculation_results[56];
/* 0x8006df14 */ extern int sp2_cd_counter;
/* 0x8006e0e0 */ extern unsigned char sp2_camera[500];
/* 0x8006e2d8 */ extern unsigned char sp2_env_1[116];
/* 0x8006e34c */ extern unsigned char sp2_env_2[116];
/* 0x8006eba8 */ extern unsigned char sp2_8006eba8[256];
/* 0x8006f0a8 */ extern unsigned char sp2_sound_queue[24][44];
/* 0x8006f518 */ extern unsigned char sp2_spyro_shadow[28];

/* 0x8006f538 */ extern unsigned char sp2_pad[128];
/* 0x8006f5c8 */ extern unsigned char sp2_pad_2[128];

/* 0x8006f670 */ extern unsigned char sp2_active_synchronised_mobys[32];
/* 0x8006fd90 */ extern void *sp2_active_mobys[384];

/* 0x80070390 */ extern int sp2_game_state;

/* 0x800703d0 */ extern unsigned char sp2_hud[124];

/* 0x80070690 */ extern unsigned char sp2_pad_port_1[32];
/* 0x800706b8 */ extern unsigned char sp2_pad_queue[64];
/* 0x800708f0 */ extern unsigned char sp2_pad_port_2[32];

/* 0x800722c0 */ extern int sp2_wad_header[196][2];

/* 0x800728e0 */ extern unsigned char sp2_extras[24];


/* 0x800141c4 */ extern void Sp2UpdatePadQueue(void);
/* 0x800145d8 */ extern void Sp2VSyncCallback(void);
/* 0x80014798 */ extern void Sp2LogicController(int player);

/* 0x8001588c */ extern void Sp2ReadCd(int start_file_position, unsigned int *start_ram_buffer, int size, int start_subfile_offset);

/* 0x80015a90 */ extern void Sp2GraphicsGame(void);
/* 0x800176d4 */ extern void Sp2Render(int flags);
/* 0x80017830 */ extern void Sp2Graphics(void);
/* 0x80017afc */ extern void Sp2LogicGameWrapper(void);
/* 0x800196e4 */ extern void Sp2LogicGuidebookRequested(void);
/* 0x80018468 */ extern void Sp2LogicDialogue(void);
/* 0x800197e4 */ extern void Sp2LogicGuidebook(void);
/* 0x8001b280 */ extern void Sp2InitChapterBook(int chapter_book_id);
/* 0x8001caf4 */ extern void Sp2IntroInit(void);
/* 0x8001d0c0 */ extern void Sp2LogicGame(int flags);

/* 0x8001d318 */ extern unsigned int *Sp2GetOTag(int);

/* 0x8001d47c */ extern void Sp2MemCpy(void *dest, void *src, int count);
/* 0x8001d454 */ extern void Sp2MemSetAlign16(void *dest, int fill_value, int count);

/* 0x8001d528 */ extern int Sp2Atan2(int x, int y, int result_size);
/* 0x8001da90 */ extern int Sp2Hypot(int *vector, int in_3d);
/* 0x8001de10 */ extern void Sp2Vec3Clear(int *dest);
/* 0x8001de20 */ extern void Sp2Vec3Move(int *dest, int *src);
/* 0x8001deac */ extern void Sp2Vec3Sub(int *dest, int *src1, int *src2);
/* 0x8001e018 */ extern int Sp2FastHypot2d(int *xy1, int *xy2);
/* 0x8001e3e8 */ extern void Sp2AnglesToMatrix(short * angles, int *matrix_2, int *matrix_1);

/* 0x8001f9e8 */ extern void Sp2LogicCamera(void);
/* 0x80020e38 */ extern void Sp280020e38(int *, int *, int);
/* 0x80021458 */ extern void Sp2StopCutscene(int, int);
/* 0x80023828 */ extern void Sp280023828(int);
/* 0x8002c1cc */ extern void Sp2LogicSpyro(void);

/* 0x8002d1c0 */ extern int Sp28002d1c0(int);

/* 0x8003a0f0 */ extern int Sp2SubstractTicks(void *value, int value_size);
/* 0x8003a3ec */ extern int Sp28003a3ec(void *moby);
/* 0x8003b878 */ extern void Sp2CollectGem(void *gem);
/* 0x800428bc */ extern void *Sp2Flame(int *, unsigned, unsigned, unsigned *, unsigned, void *);
/* 0x800431fc */ extern void *Sp2800431fc(void *);
/* 0x8004368c */ extern void Sp2RemoveMoby(void *moby);
/* 0x80043798 */ extern void Sp2StartMoby(void *moby);
/* 0x80043898 */ extern void Sp2UpdateMoby(void *moby, int flags);
/* 0x80043e18 */ extern void Sp280043e18(void *moby);

/* 0x8004411c */ extern void Sp2RenderSpyro(void);
/* 0x80045bb8 */ extern void Sp280045bb8(void);
/* 0x80046884 */ extern void Sp2RenderMobs(void);
/* 0x80049358 */ extern void Sp2RenderObjects(void);
/* 0x8004a4b8 */ extern void Sp2RenderParticles(void);
/* 0x8004b294 */ extern void Sp2RenderFlames(void);
/* 0x8004b978 */ extern void Sp2RenderSpyroShadow(void);
/* 0x8004bd64 */ extern void Sp2RenderMobShadows(void);
/* 0x8004e8d0 */ extern void Sp2RenderEntities(void);

/* 0x800529c4 */ extern int Sp2PlayMobySound(void *moby, int moby_sound_id, int flags);

/* 0x80058b08 */ extern void EnterCriticalSection(void);
/* 0x80058b18 */ extern void ExitCriticalSection(void);

/* 0x800592c8 */ extern int VSync(int mode);
/* 0x8005a344 */ extern int DrawSync(int mode);
/* 0x8005a938 */ extern void DrawOTag(unsigned int *p);
/* 0x8005a9a8 */ extern void *PutDrawEnv(void *env);
/* 0x8005ab74 */ extern void *PutDispEnv(void *env);
/* 0x8005cf08 */ extern void *SetDefDrawEnv(void *env, int x, int y, int w, int h);

/* 0x8005d6f8 */ extern int printf(char *fmt, ...);

/* 0x80079af8 */ extern void Sp2IntroLoadChapterBook(void);
/* 0x8007bdac */ extern void Sp2InitNewGame(void);


#endif /* SP2_H_INCLUDED */
