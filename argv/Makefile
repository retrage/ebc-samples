CC=clang
CFLAGS=--target=ebc -fno-stack-protector -fshort-wchar -I.
LD=lld-link
LDFLAGS=-subsystem:efi_application -nodefaultlib -dll

all: main.efi

%.efi: %.o
	$(LD) $(LDFLAGS) -entry:efi_main $< -out:$@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@rm -f *.efi *.dll *.o
