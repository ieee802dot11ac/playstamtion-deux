.PHONY: clean

BIN_NAME := testing.elf

CC ?= mips64r5900el-ps2-elf-gcc

SRCDIR := src

SRCFILE := main.c

ARGS := -Iinclude/ -I/usr/local/ps2dev -I/usr/local/ps2dev/ps2sdk/common/include/ -D_EE

clean:
	rm -r build

default:
	mkdir -p build
	$(CC) -o build/$(BIN_NAME) $(ARGS) $(SRCDIR)/$(SRCFILE)
