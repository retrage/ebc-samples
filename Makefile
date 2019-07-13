CC=clang
CFLAGS=--target=ebc -fno-stack-protector -fshort-wchar -Iinclude
LD=lld-link
LDFLAGS=-subsystem:efi_application -nodefaultlib -dll

SRCS=$(wildcard test/*.c)
OBJS=$(SRCS:.c=.o)
BINS=$(OBJS:.o=.efi)
DMPS=$(BINS:.efi=.dump)

all: efi

efi: $(BINS)

dump: $(DMPS)

test/%.efi: test/%.o
	$(LD) $(LDFLAGS) -entry:efi_main $< -out:$@

test/%.dump: test/%.efi
	llvm-objdump -d $< > $@

ovmf: efi
	qemu-system-x86_64 \
	  -drive if=pflash,format=raw,readonly,file=bin/OVMF.fd \
	  -drive file=fat:rw:. \
	  -k en-us \
	  -m 4G \
	  -serial stdio

clean:
	@rm -f test/*.dump test/*.efi test/*.dll test/*.lib test/*.ll test/*.o

.PHONY: ovmf clean
