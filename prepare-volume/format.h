#pragma once
#include "prepare-volume.h"
#include <winioctl.h>

typedef enum
{
    FCC_PROGRESS,
    FCC_DONE_WITH_STRUCTURE,
    FCC_UNKNOWN2,
    FCC_INCOMPATIBLE_FILE_SYSTEM,
    FCC_UNKNOWN4,
    FCC_UNKNOWN5,
    FCC_ACCESS_DENIED,
    FCC_MEDIA_WRITE_PROTECTED,
    FCC_VOLUME_IN_USE,
    FCC_CANT_QUICK_FORMAT,
    FCC_UNKNOWNA,
    FCC_DONE,
    FCC_BAD_LABEL,
    FCC_UNKNOWND,
    FCC_OUTPUT,
    FCC_STRUCTURE_PROGRESS,
    FCC_CLUSTER_SIZE_TOO_SMALL,
    FCC_CLUSTER_SIZE_TOO_BIG,
    FCC_VOLUME_TOO_SMALL,
    FCC_VOLUME_TOO_BIG,
    FCC_NO_MEDIA_IN_DRIVE,
    FCC_UNKNOWN15,
    FCC_UNKNOWN16,
    FCC_UNKNOWN17,
    FCC_DEVICE_NOT_READY,
    FCC_CHECKDISK_PROGRESS,
    FCC_UNKNOWN1A,
    FCC_UNKNOWN1B,
    FCC_UNKNOWN1C,
    FCC_UNKNOWN1D,
    FCC_UNKNOWN1E,
    FCC_UNKNOWN1F,
    FCC_READ_ONLY_MODE,
} FILE_SYSTEM_CALLBACK_COMMAND;

typedef BOOLEAN(WINAPI *FILE_SYSTEM_CALLBACK)(
    FILE_SYSTEM_CALLBACK_COMMAND Command,
    ULONG                        Action,
    PVOID                        pData
    );

typedef void(WINAPI *FormatEx_t)(
    PWCHAR               DriveRoot,
    MEDIA_TYPE           MediaType,		// See WinIoCtl.h
    PWCHAR               FileSystemTypeName,
    PWCHAR               Label,
    BOOL                 QuickFormat,
    ULONG                DesiredUnitAllocationSize,
    FILE_SYSTEM_CALLBACK Callback
    );

// Format the volume created by InitializeDisk.
BOOL FormatVolume(IN DWORD diskNumber);
