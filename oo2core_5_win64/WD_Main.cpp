#include "WD_Main.h"
#include "API_Console.h"

#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
using namespace moddingApi;

DWORD WINAPI WD_Main::Start()
{
	API_Console::InitializeConsole();

	// Console allocation
	AllocConsole();
	freopen("CONIN$", "r", stdin);
	freopen("CONOUT$", "w", stdout);

	cout << "====== Walking Dead: Modding Console ======" << endl;

	while (true)
	{
		std::string cmd;
		cout << "> ";
		cin >> cmd;

		API_Console::DoConsoleCommand(cmd);

		Sleep(100);
	}

	return 0;
}