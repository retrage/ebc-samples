#include "efi.h"
#include "efi_native.h"

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  CHAR16 *String = L"Hello, EBC!\n";

  ConOutOutputString(SystemTable, String);

  return EFI_SUCCESS;
}
