#include "efi.h"

void func(EFI_SYSTEM_TABLE *SystemTable)
{
  EFI_SYSTEM_TABLE *ST = SystemTable;
}

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  func(SystemTable);

  return EFI_SUCCESS;
}
