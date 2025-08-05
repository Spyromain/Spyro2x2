CCPREFIX = mipsel-unknown-linux-gnu
CC = $(CCPREFIX)-gcc
LD = $(CCPREFIX)-ld
OBJCOPY = $(CCPREFIX)-objcopy
CFLAGS = -fno-builtin -O2 -nostdlib -EL -march=r3000 -mno-abicalls -msoft-float -G0

PYTHON = python

CP = $(PYTHON) ../../scripts/cp.py
MKDIR = $(PYTHON) ../../scripts/mkdir.py
RM = $(PYTHON) ../../scripts/rm.py

DUMPSXISO = dumpsxiso
MKPSXISO = mkpsxiso
