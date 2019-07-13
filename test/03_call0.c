#include "efi.h"

void func()
{
  int i = 128;
}

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  func();

  return EFI_SUCCESS;
}
