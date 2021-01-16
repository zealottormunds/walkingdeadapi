#include <windows.h>
#include <stdio.h>
#include <string>
#include <vector>
#include <iostream>

#include "API_Console.h"

using namespace std;
using namespace moddingApi;

// Console Functions
vector<string> consoleCommands;
vector<uintptr_t> consoleFunctions;
vector<int> consoleParams;
void AddCommand(string, uintptr_t, int);
int GetCommandIndex(string);

// Command Functions
void c_Help();
void c_ConvertMessage();

void API_Console::InitializeConsole()
{
	AddCommand("Help", (uintptr_t)c_Help, 0);
	AddCommand("ConvertMessage", (uintptr_t)c_ConvertMessage, 1);
}

typedef void(__stdcall * f)();
f Function;

void API_Console::DoConsoleCommand(string Input)
{
	string Command = Input;

	int ind = GetCommandIndex(Command);
	if (ind != -1)
	{
		Function = (f)consoleFunctions[ind];
		Function();

		cout << endl;
	}
	else
	{
		cout << "Command not found" << endl;
	}
}

void c_Help()
{
	cout << endl;
	cout << "Available commands:" << endl;
	for (int x = 0; x < consoleCommands.size(); x++)
	{
		cout << consoleCommands[x] << endl;
	}
}

#include "Scene.h"
void c_ConvertMessage()
{
	std::string param1;

	//cout << "MSG >> ";
	//cin >> param1;
	//char * param1_c = strcpy(new char[param1.length() + 1], param1.c_str());

	cout << "Scene: " << Scene::GetWorldSceneName() << endl;
}

void AddCommand(string command, uintptr_t function, int paramCount)
{
	consoleCommands.push_back(command);
	consoleFunctions.push_back(function);
	consoleParams.push_back(paramCount);
}

int GetCommandIndex(string command)
{
	int cmd = -1;

	for (int x = 0; x < consoleCommands.size(); x++)
	{
		if (command == consoleCommands[x])
		{
			cmd = x;
			x = consoleCommands.size();
		}
	}

	return cmd;
}