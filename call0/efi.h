#ifndef EFI_H_
#define EFI_H_

typedef unsigned char uint8_t;
typedef char int8_t;
typedef unsigned short uint16_t;
typedef short int16_t;
typedef unsigned int uint32_t;
typedef int int32_t;
typedef unsigned long uint64_t;
typedef long int64_t;

#define IN
#define OUT

#define TRUE true
#define FALSE false

#define EFI_SUCCESS 0x0000000000000000
#define EFI_ERROR   0x8000000000000000

typedef uint8_t   BOOLEAN;
typedef int8_t    INT8;
typedef uint8_t   UINT8;
typedef uint8_t   CHAR8;
typedef int16_t   INT16;
typedef uint16_t  UINT16;
typedef uint16_t  CHAR16;
typedef int32_t   INT32;
typedef uint32_t  UINT32;
typedef int64_t   INT64;
typedef uint64_t  UINT64;
typedef int64_t   INTN;
typedef uint64_t  UINTN;
typedef UINTN   EFI_STATUS;
typedef UINTN   EFI_HANDLE;

typedef struct EFI_MAIN_PARAMETERS {
  EFI_HANDLE        ImageHandle;
  void              *SystemTable; 
} EFI_MAIN_PARAMETERS;

typedef struct EFI_TABLE_HEADER {
  UINT64            Signature;
  UINT32            Revision;
  UINT32            HeaderSize;
  UINT32            CRC32;
  UINT32            Reserved;
} EFI_TABLE_HEADER;

typedef struct EFI_SYSTEM_TABLE {
  EFI_TABLE_HEADER  Hdr;
  void              *FirmwareVendor;
  UINT32            FirmwareRevision;
  EFI_HANDLE        ConsoleInHandle;
  void              *ConIn;
  EFI_HANDLE        ConsoleOutHandle;
  void              *ConOut;
  EFI_HANDLE        StandardErrorHandle;
  void              *StdErr;
  void              *RuntimeServices;
  void              *BootServices;
  UINTN             NumberOfTableEntries;
  void              *ConfigurationTable;
} EFI_SYSTEM_TABLE;

typedef struct EFI_RUNTIME_SERVICES {
  EFI_TABLE_HEADER  Hdr;
  void              *GetTime;
  void              *SetTime;
  void              *GetWakeupTime;
  void              *SetWakeupTime;
  void              *SetVirtualAddressMap;
  void              *ConvertPointer;
  void              *GetVariable;
  void              *GetNextVariableName;
  void              *SetVariable;
  void              *GetNextHighMonotonicCount;
  void              *ResetSystem;
  void              *UpdateCapsule;
  void              *QueryCapsuleCapabilities;
  void              *QueryVariableInfo;
} EFI_RUNTIME_SERVICES;

typedef struct EFI_SIMPLE_TEXT_OUT_PROTOCOL {
  void              *Reset;
  void              *OutputString;
  void              *TestString;
  void              *QueryMode;
  void              *SetMode;
  void              *SetAttribute;
  void              *ClearScreen;
  void              *SetCursorPosition;
  void              *EnableCursor;
  void              *Mode;
} EFI_SIMPLE_TEXT_OUT_PROTOCOL;

typedef struct EFI_SIMPLE_TEXT_IN_PROTOCOL {
  void              *Reset;
  void              *ReadKeyStroke;
  void              *WaitForKey;
} EFI_SIMPLE_TEXT_IN_PROTOCOL;

typedef struct EFI_BOOT_SERVICES {
  EFI_TABLE_HEADER  Hdr;
  void              *RaiseTPL;
  void              *RestoreTPL;
  void              *AllocatePages;
  void              *FreePages;
  void              *GetMemoryMap;
  void              *AllocatePool;
  void              *FreePool;
  void              *CreateEvent;
  void              *SetTimer;
  void              *WaitForEvent;
  void              *SignalEvent;
  void              *CloseEvent;
  void              *CheckEvent;
  void              *InstallProtocolInterface;
  void              *ReinstallProtocolInterface;
  void              *UninstallProtocolInterface;
  void              *HandleProtocol;
  void              *PCHandleProtocol;
  void              *RegisterProtocolNotify;
  void              *LocateHandle;
  void              *LocateDevicePath;
  void              *InstallConfigurationTable;
  void              *LoadImage;
  void              *StartImage;
  void              *Exit;
  void              *UnloadImage;
  void              *ExitBootServices;
  void              *GetNextMonotonicCount;
  void              *Stall;
  void              *SetWatchdogTimer;
  void              *ConnectController;
  void              *DisconnectController;
  void              *OpenProtocolInformation;
  void              *ProtocolPerHandle;
  void              *LocateHandleBuffer;
  void              *LocateProtocol;
  void              *InstallMultipleProtocolInterfaces;
  void              *UninstallMultipleProtocolInterfaces;
  void              *CalculateCrc32;
  void              *CopyMem;
  void              *SetMem;
  void              *CreateEventEx;
} EFI_BOOT_SERVICES;

typedef struct EFI_INPUT_KEY {
  UINT16            ScanCode;
  CHAR16            UnicodeChar;
} EFI_INPUT_KEY;

#endif /* EFI_H_ */
