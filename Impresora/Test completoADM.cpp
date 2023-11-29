#include <windows.h>
#include <tchar.h>
#include <cstdlib>
#include <iostream>
#include <conio.h>

using namespace std;

int main() {
	SHELLEXECUTEINFO sei = { sizeof(sei) };
	sei.lpVerb = _T("runas");
	sei.lpFile = _T("cmd.exe");
	cout<<"---------------By Diego Sanchez 2023---------------"<<endl;
	sei.lpParameters = _T("/C echo By Diego Sanchez 2023 && sc stop spooler && timeout /t 5 && del /f /q c:\\Windows\\system32\\spool\\PRINTERS\\*.* && timeout /t 3 && sc start spooler && echo By Diego Sanchez 2023 - PROGRAMA FINALIZADO && timeout /t 2");
	sei.hwnd = NULL;
	sei.nShow = SW_NORMAL;
	
	if (!ShellExecuteEx(&sei)) {
		DWORD dwError = GetLastError();
		if (dwError == ERROR_CANCELLED) {
			// El usuario se negó a permitir privilegios de administrador
			return 1;
		}
	}
	return 0;
}
