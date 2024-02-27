#include <stdio.h>
#include <windows.h>
#include <winnt.h>
#include <stdbool.h>

// Function to check the value of the Dynamic Base (ASLR) flag
bool isASLR(const char* peBuffer) {
    // Cast the buffer to the DOS header
    IMAGE_DOS_HEADER* dosHeader = (IMAGE_DOS_HEADER*)peBuffer;

    // Calculate the offset to the NT headers
    IMAGE_NT_HEADERS* ntHeader = (IMAGE_NT_HEADERS*)(peBuffer + dosHeader->e_lfanew);

    // Check the value of the Dynamic Base (ASLR) flag
    if (ntHeader->OptionalHeader.DllCharacteristics & IMAGE_DLLCHARACTERISTICS_DYNAMIC_BASE) {
        return true;
    } else {
        return false;
    }
}

int main() {
    // Get the base address of the current module (executable)
    HMODULE hModule = GetModuleHandle(NULL);
    if (hModule == NULL) {
        fprintf(stderr, "Failed to get module handle\n");
        return 1;
    }

    // Get the file path of the current module
    char filePath[MAX_PATH];
    GetModuleFileName(hModule, filePath, MAX_PATH);

    // Load the PE file into memory
    HANDLE hFile = CreateFile(filePath, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    if (hFile == INVALID_HANDLE_VALUE) {
        fprintf(stderr, "Failed to open file\n");
        return 1;
    }

    DWORD fileSize = GetFileSize(hFile, NULL);
    if (fileSize == INVALID_FILE_SIZE) {
        fprintf(stderr, "Failed to get file size\n");
        CloseHandle(hFile);
        return 1;
    }

    HANDLE hMapping = CreateFileMapping(hFile, NULL, PAGE_READONLY, 0, 0, NULL);
    if (hMapping == NULL) {
        fprintf(stderr, "Failed to create file mapping\n");
        CloseHandle(hFile);
        return 1;
    }

    const char* peBuffer = (const char*)MapViewOfFile(hMapping, FILE_MAP_READ, 0, 0, fileSize);
    if (peBuffer == NULL) {
        fprintf(stderr, "Failed to map view of file\n");
        CloseHandle(hMapping);
        CloseHandle(hFile);
        return 1;
    }

    // Check if ASLR is enabled
    if (isASLR(peBuffer)) {
        printf("ASLR is enabled, I'm running my evil payload!!\n");
    } else {
        printf("ASLR is disabled, I'm going to sleep until your sandbox times out.\n");
    }

    // Clean up
    UnmapViewOfFile(peBuffer);
    CloseHandle(hMapping);
    CloseHandle(hFile);

    return 0;
}
