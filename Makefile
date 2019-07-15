CC=clang
CFLAGS=--target=ebc -fno-stack-protector -fshort-wchar -Iinclude
LD=lld-link
LDFLAGS=-subsystem:efi_application -nodefaultlib -dll -opt:noicf

SRCS=$(sort $(wildcard test/*.c))
OBJS=$(SRCS:.c=.o)
ASMS=$(SRCS:.c=.s)
BINS=$(OBJS:.o=.efi)
DMPS=$(BINS:.efi=.dump)

.PRECIOUS: $(OBJS)

all: $(BINS) $(DMPS)

asm: $(ASMS)

dump: $(DMPS)

test/%.efi: test/%.o
	$(LD) $(LDFLAGS) -entry:efi_main $< -out:$@

test/%.s: test/%.c
	$(CC) $(CFLAGS) -S $< -o $@

test/%.dump: test/%.efi
	llvm-objdump -d $< > $@

ovmf: $(BINS)
	qemu-system-x86_64 \
	  -drive if=pflash,format=raw,readonly,file=bin/OVMF.fd \
	  -drive file=fat:rw:. \
	  -k en-us \
	  -m 4G \
	  -serial stdio

clean:
	@rm -f $(DMPS) $(BINS) $(OBJS) $(ASMS) test/*.dll test/*.lib

.PHONY: clean asm dump ovmf
