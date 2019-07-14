#ifndef EBC_EFI_NATIVE_H_
#define EBC_EFI_NATIVE_H_

#include "efi.h"

void ConOutOutputString(EFI_SYSTEM_TABLE *SystemTable, CHAR16 *String)
{
  asm("movnw %0, @%0 (5,24)\n" // SystemTable->ConOut
      "pushn %1\n" // String
      "pushn %0\n" // ConOut
      "call32exa @%0 (1,0)\n" // ConOut->OutputString
      "movqw r0, r0 (2,0)\n"
      ::"r"(SystemTable), "r"(String):);
}

#endif /* EBC_EFI_NATIVE_H_ */
