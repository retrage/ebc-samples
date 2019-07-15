#include "efi.h"
#include "efi_native.h"

char func0() { return 127; }

short func1() { return 32767; }

int func2() { return 2147483647; }

long func3() { return 9223372036854775807; }

CHAR16 *func4() { return L"foo bar"; }

EFI_STATUS efi_main(EFI_HANDLE ImageHandle, EFI_SYSTEM_TABLE *SystemTable)
{
  if (func0() == 127)
    ConOutOutputString(SystemTable, L"OK\r\n");
  else
    ConOutOutputString(SystemTable, L"NG\r\n");

  if (func1() == 32767)
    ConOutOutputString(SystemTable, L"OK\r\n");
  else
    ConOutOutputString(SystemTable, L"NG\r\n");

  if (func2() == 2147483647)
    ConOutOutputString(SystemTable, L"OK\r\n");
  else
    ConOutOutputString(SystemTable, L"NG\r\n");

  if (func3() == (long)9223372036854775807)
    ConOutOutputString(SystemTable, L"OK\r\n");
  else
    ConOutOutputString(SystemTable, L"NG\r\n");

  ConOutOutputString(SystemTable, func4());

  return EFI_SUCCESS;
}
