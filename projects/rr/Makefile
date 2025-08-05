include ../../env.mk


MAINOBJ = build/src/asm/header.o \
	build/src/c/Sp2x2Swap.o \
	build/src/c/Sp2x2InitPad.o \
	build/src/c/Sp2x2VSyncCallback.o \
	build/src/asm/main.o \
	build/src/c/Sp2x2LoadText.o

WAD72OBJ = build/src/c/Sp2x2.o \
	build/src/c/Sp2x2HelloWorld.o \
	build/src/c/Sp2x2InitSpyroTwin.o \
	build/src/c/Sp2x2LogicSpyro.o \
	build/src/c/Sp2x2LogicController.o \
	build/src/c/Sp2x2LogicCamera.o \
	build/src/c/Sp2x2RenderEntities.o \
	build/src/c/Sp2x2RenderParticles.o \
	build/src/c/Sp2x2TeleportSpyro.o \
	build/src/c/Sp2x280021610.o \
	build/src/c/Sp2x2Flame.o \
	build/src/c/Sp2x2Graphics.o

WAD74OBJ = build/src/c/Sp2x2UpdateMobys.o \
	build/src/c/Sp2x2LogicDialogue.o \
	build/src/c/Sp2x2GetSoundVolumeFromDistance.o \
	build/src/c/Sp2x2StopCutscene.o \
	build/src/c/Sp2x2LogicGameWrapper.o

WADLIST = build/data/wad/WAD_000.WAD \
	build/data/wad/WAD_001.WAD \
	build/data/wad/WAD_002.WAD \
	build/data/wad/WAD_003.WAD \
	build/data/wad/WAD_004.WAD \
	build/data/wad/WAD_005.WAD \
	build/data/wad/WAD_006.WAD \
	build/data/wad/WAD_007.WAD \
	build/data/wad/WAD_008.WAD \
	build/data/wad/WAD_009.WAD \
	build/data/wad/WAD_010.WAD \
	build/data/wad/WAD_011.WAD \
	build/data/wad/WAD_012.WAD \
	build/data/wad/WAD_013.WAD \
	build/data/wad/WAD_014.WAD \
	build/data/wad/WAD_015.WAD \
	build/data/wad/WAD_016.WAD \
	build/data/wad/WAD_017.WAD \
	build/data/wad/WAD_018.WAD \
	build/data/wad/WAD_019.WAD \
	build/data/wad/WAD_020.WAD \
	build/data/wad/WAD_021.WAD \
	build/data/wad/WAD_022.WAD \
	build/data/wad/WAD_023.WAD \
	build/data/wad/WAD_024.WAD \
	build/data/wad/WAD_025.WAD \
	build/data/wad/WAD_026.WAD \
	build/data/wad/WAD_027.WAD \
	build/data/wad/WAD_028.WAD \
	build/data/wad/WAD_029.WAD \
	build/data/wad/WAD_030.WAD \
	build/data/wad/WAD_031.WAD \
	build/data/wad/WAD_032.WAD \
	build/data/wad/WAD_033.WAD \
	build/data/wad/WAD_034.WAD \
	build/data/wad/WAD_035.WAD \
	build/data/wad/WAD_036.WAD \
	build/data/wad/WAD_037.WAD \
	build/data/wad/WAD_038.WAD \
	build/data/wad/WAD_039.WAD \
	build/data/wad/WAD_040.WAD \
	build/data/wad/WAD_041.WAD \
	build/data/wad/WAD_042.WAD \
	build/data/wad/WAD_043.WAD \
	build/data/wad/WAD_044.WAD \
	build/data/wad/WAD_045.WAD \
	build/data/wad/WAD_046.WAD \
	build/data/wad/WAD_047.WAD \
	build/data/wad/WAD_048.WAD \
	build/data/wad/WAD_049.WAD \
	build/data/wad/WAD_050.WAD \
	build/data/wad/WAD_051.WAD \
	build/data/wad/WAD_052.WAD \
	build/data/wad/WAD_053.WAD \
	build/data/wad/WAD_054.WAD \
	build/data/wad/WAD_055.WAD \
	build/data/wad/WAD_056.WAD \
	build/data/wad/WAD_057.WAD \
	build/data/wad/WAD_058.WAD \
	build/data/wad/WAD_059.WAD \
	build/data/wad/WAD_060.WAD \
	build/data/wad/WAD_061.WAD \
	build/data/wad/WAD_062.WAD \
	build/data/wad/WAD_063.WAD \
	build/data/wad/WAD_064.WAD \
	build/data/wad/WAD_065.WAD \
	build/data/wad/WAD_066.WAD \
	build/data/wad/WAD_067.WAD \
	build/data/wad/WAD_068.WAD \
	build/data/wad/WAD_069.WAD \
	build/data/wad/WAD_070.WAD \
	build/data/wad/WAD_071.WAD \
	build/data/wad/WAD_072.WAD \
	build/data/wad/WAD_073.WAD \
	build/data/wad/WAD_074.WAD \
	build/data/wad/WAD_075.WAD \
	build/data/wad/WAD_076.WAD \
	build/data/wad/WAD_077.WAD \
	build/data/wad/WAD_078.WAD \
	build/data/wad/WAD_079.WAD \
	build/data/wad/WAD_080.WAD \
	build/data/wad/WAD_081.WAD \
	build/data/wad/WAD_082.WAD \
	build/data/wad/WAD_083.WAD \
	build/data/wad/WAD_084.WAD \
	build/data/wad/WAD_085.WAD \
	build/data/wad/WAD_086.WAD \
	build/data/wad/WAD_087.WAD \
	build/data/wad/WAD_088.WAD \
	build/data/wad/WAD_089.WAD \
	build/data/wad/WAD_090.WAD \
	build/data/wad/WAD_091.WAD \
	build/data/wad/WAD_092.WAD \
	build/data/wad/WAD_093.WAD \
	build/data/wad/WAD_094.WAD \
	build/data/wad/WAD_095.WAD \
	build/data/wad/WAD_096.WAD \
	build/data/wad/WAD_097.WAD \
	build/data/wad/WAD_098.WAD \
	build/data/wad/WAD_099.WAD \
	build/data/wad/WAD_100.WAD \
	build/data/wad/WAD_101.WAD \
	build/data/wad/WAD_102.WAD \
	build/data/wad/WAD_103.WAD \
	build/data/wad/WAD_104.WAD \
	build/data/wad/WAD_105.WAD \
	build/data/wad/WAD_106.WAD \
	build/data/wad/WAD_107.WAD \
	build/data/wad/WAD_108.WAD \
	build/data/wad/WAD_109.WAD \
	build/data/wad/WAD_110.WAD \
	build/data/wad/WAD_111.WAD \
	build/data/wad/WAD_112.WAD \
	build/data/wad/WAD_113.WAD \
	build/data/wad/WAD_114.WAD \
	build/data/wad/WAD_115.WAD \
	build/data/wad/WAD_116.WAD \
	build/data/wad/WAD_117.WAD \
	build/data/wad/WAD_118.WAD \
	build/data/wad/WAD_119.WAD \
	build/data/wad/WAD_120.WAD \
	build/data/wad/WAD_121.WAD \
	build/data/wad/WAD_122.WAD \
	build/data/wad/WAD_123.WAD \
	build/data/wad/WAD_124.WAD \
	build/data/wad/WAD_125.WAD \
	build/data/wad/WAD_126.WAD \
	build/data/wad/WAD_127.WAD \
	build/data/wad/WAD_128.WAD \
	build/data/wad/WAD_129.WAD \
	build/data/wad/WAD_130.WAD \
	build/data/wad/WAD_131.WAD \
	build/data/wad/WAD_132.WAD \
	build/data/wad/WAD_133.WAD \
	build/data/wad/WAD_134.WAD \
	build/data/wad/WAD_135.WAD \
	build/data/wad/WAD_136.WAD \
	build/data/wad/WAD_137.WAD \
	build/data/wad/WAD_138.WAD \
	build/data/wad/WAD_139.WAD \
	build/data/wad/WAD_140.WAD \
	build/data/wad/WAD_141.WAD \
	build/data/wad/WAD_142.WAD \
	build/data/wad/WAD_143.WAD \
	build/data/wad/WAD_144.WAD \
	build/data/wad/WAD_145.WAD \
	build/data/wad/WAD_146.WAD \
	build/data/wad/WAD_147.WAD \
	build/data/wad/WAD_148.WAD \
	build/data/wad/WAD_149.WAD \
	build/data/wad/WAD_150.WAD \
	build/data/wad/WAD_151.WAD \
	build/data/wad/WAD_152.WAD \
	build/data/wad/WAD_153.WAD \
	build/data/wad/WAD_154.WAD \
	build/data/wad/WAD_155.WAD \
	build/data/wad/WAD_156.WAD \
	build/data/wad/WAD_157.WAD \
	build/data/wad/WAD_158.WAD \
	build/data/wad/WAD_159.WAD \
	build/data/wad/WAD_160.WAD \
	build/data/wad/WAD_161.WAD \
	build/data/wad/WAD_162.WAD \
	build/data/wad/WAD_163.WAD \
	build/data/wad/WAD_164.WAD \
	build/data/wad/WAD_165.WAD \
	build/data/wad/WAD_166.WAD \
	build/data/wad/WAD_167.WAD \
	build/data/wad/WAD_168.WAD \
	build/data/wad/WAD_169.WAD \
	build/data/wad/WAD_170.WAD \
	build/data/wad/WAD_171.WAD \
	build/data/wad/WAD_172.WAD \
	build/data/wad/WAD_173.WAD \
	build/data/wad/WAD_174.WAD \
	build/data/wad/WAD_175.WAD \
	build/data/wad/WAD_176.WAD \
	build/data/wad/WAD_177.WAD \
	build/data/wad/WAD_178.WAD \
	build/data/wad/WAD_179.WAD \
	build/data/wad/WAD_180.WAD \
	build/data/wad/WAD_181.WAD \
	build/data/wad/WAD_182.WAD \
	build/data/wad/WAD_183.WAD \
	build/data/wad/WAD_184.WAD \
	build/data/wad/WAD_185.WAD \
	build/data/wad/WAD_186.WAD \
	build/data/wad/WAD_187.WAD \
	build/data/wad/WAD_188.WAD \
	build/data/wad/WAD_189.WAD \
	build/data/wad/WAD_190.WAD \
	build/data/wad/WAD_191.WAD \
	build/data/wad/WAD_192.WAD \
	build/data/wad/WAD_193.WAD \
	build/data/wad/WAD_194.WAD \
	build/data/wad/WAD_195.WAD \
	build/data/wad/WAD_196.WAD

DISCLIST = build/rom/license_data.dat \
	build/rom/SCUS_944.25 \
	build/rom/SPEECH.STR \
	build/rom/SPYRO2.TRD \
	build/rom/SYSTEM.CNF \
	build/rom/WAD.WAD \
	build/rom/KART/KART.HWL \
	build/rom/KART/KARTDCH.BIN \
	build/rom/KART/KARTENG.BIN \
	build/rom/KART/KARTFRN.BIN \
	build/rom/KART/KARTGRM.BIN \
	build/rom/KART/KARTITL.BIN \
	build/rom/KART/KARTJPN.BIN \
	build/rom/KART/PSX.EXE \
	build/rom/KART/SAMPLE1.VRM \
	build/rom/KART/SAMPLE2.VRM \
	build/rom/KART/SAMPLE3.VRM \
	build/rom/KART/SAMPLE4.VRM \
	build/rom/KART/SAMPLE5.VRM \
	build/rom/KART/SAMPLER.BIG \
	build/rom/KART/XA/S00.XA


.PHONY: disc
disc: build/disc/spyro2x2.bin

build/disc/spyro2x2.bin: build/spyro2x2.xml $(DISCLIST)
	@$(MKDIR) -p $(@D)
	$(MKPSXISO) -y -lba build/spyro2x2.lba -c build/disc/spyro2x2.cue -o $@ $<

build/spyro2x2.xml: ../../scripts/create_mkpsxiso_xml.py spyro2.xml $(DISCLIST)
	@$(MKDIR) -p $(@D)
	$(PYTHON) $< spyro2.xml $@

build/rom/SCUS_944.25: build/spyro2x2.elf
	@$(MKDIR) -p $(@D)
	$(OBJCOPY) -O binary -j .header -j .main $< $@

build/spyro2x2.elf: spyro2x2.ld symbols.ld $(MAINOBJ) $(WAD72OBJ) $(WAD74OBJ)
	@$(MKDIR) -p $(@D)
	$(LD) --orphan-handling=discard -T $< -o $@

build/src/asm/%.o: src/asm/%.S
	@$(MKDIR) -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

build/src/c/%.o: ../../src/c/%.c
	@$(MKDIR) -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@ \
		-DSP2X2_DRAW_HEIGHT=0xd8 \
		-DSP2X2_DRAW_HMARGIN=0xc \
		-DSP2X2_BIOS2_WAD=72 \
		-DSP2X2_BIOS3_WAD=74

build/rom/WAD.WAD: ../../scripts/rewad.py $(WADLIST)
	@$(MKDIR) -p $(@D)
	$(PYTHON) $^ -o $@

build/data/wad/WAD_074.WAD: build/spyro2x2.elf
	@$(MKDIR) -p $(@D)
	$(OBJCOPY) -O binary -j .wad74 $< $@

build/data/wad/WAD_072.WAD: build/spyro2x2.elf
	@$(MKDIR) -p $(@D)
	$(OBJCOPY) -O binary -j .wad72 $< $@

build/data/wad/WAD_%.WAD: data/wad/WAD_%.WAD
	@$(MKDIR) -p $(@D)
	$(CP) $< $@

build/rom/%: rom/%
	@$(MKDIR) -p $(@D)
	$(CP) $< $@


.PHONY: setup
setup: disc/spyro2.bin
	$(DUMPSXISO) -x rom -s spyro2.xml $<
	$(PYTHON) ../../scripts/unwad.py rom/WAD.WAD data/wad


.PHONY: clean
clean:
	$(RM) -rf build
