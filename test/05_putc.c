#include "efi.h"

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  CHAR16 *String = L"Hello, EBC!\n";

  asm("movnw %0, @%0 (5,24)\n" // SystemTable->ConOut
      "pushn %1\n" // String
      "pushn %0\n" // SystemTable
      "call32exa @%0 (1,0)\n" // ConOut->OutputString
      "movqw r0, r0 (2,0)\n"
      ::"r"(SystemTable), "r"(String):);

  return EFI_SUCCESS;
}
