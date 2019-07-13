CC=clang
CFLAGS=--target=ebc -fno-stack-protector -fshort-wchar -Iinclude
LD=lld-link
LDFLAGS=-subsystem:efi_application -nodefaultlib -dll
LLC=llc
LLCFLAGS=-mtriple=ebc

SRCS=$(wildcard test/*.c)
OBJS=$(SRCS:.c=.o)
BINS=$(OBJS:.o=.efi)

all: efi

efi: $(BINS)

test/%.efi: test/%.o
	$(LD) $(LDFLAGS) -entry:efi_main $< -out:$@

ovmf: efi
	qemu-system-x86_64 \
	  -drive if=pflash,format=raw,readonly,file=bin/OVMF.fd \
	  -drive file=fat:rw:. \
	  -k en-us \
	  -m 4G \
	  -serial stdio

clean:
	@rm -f test/*.efi test/*.dll test/*.lib test/*.ll test/*.o

.PHONY: ovmf clean
