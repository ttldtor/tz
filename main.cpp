#define UNICODE 1
#define _UNICODE 1

#include <clocale>
#include <iostream>
#include <windows.h>

int main() {
  TIME_ZONE_INFORMATION timeZoneInformation = {};

  GetTimeZoneInformation(&timeZoneInformation);

  std::setlocale(LC_ALL, "en_US.utf8");

  std::wcout << L"Current time zone:" << std::endl;
  std::wcout << timeZoneInformation.StandardName << std::endl;

  std::wcout << L"\nAvailable time zones:" << std::endl;
  DYNAMIC_TIME_ZONE_INFORMATION dynamicTimezone = {};

  for (DWORD i = 0; EnumDynamicTimeZoneInformation(i, &dynamicTimezone) == ERROR_SUCCESS; i++) {
    std::wcout << dynamicTimezone.StandardName << L" <-> " << dynamicTimezone.TimeZoneKeyName << std::endl;
  }

  return 0;
}
