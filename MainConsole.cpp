
#include <iostream>
#include <Windows.h>
#include "MainConsole.h"



void MainConsole::ASCIITextHeader()
{
	std::cout << "  ____    ____      ___     ____    _______    ____    __   __		\n";
	std::cout << " / ___|  / ___|    / _ \\   |  _ \\   |  ___|   / ___|   \\ \\ / /	\n";
	std::cout << "| |      \\___ \\   | | | |  | |_) |  |  __|    \\___ \\    \\ V /	\n";
	std::cout << "| |___    ___) |  | |_| |  |  __/   | |___     ___) |    | |			\n";
	std::cout << " \\____|  |____/    \\___/   |_|      |_____|   |____/     |_|		\n";

	HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(console_color, 10);
	std::cout << "Hello, Welcome to CSOPESY commandline!\n";
	SetConsoleTextAttribute(console_color, 14);
	std::cout << "Type 'exit' to quit, 'clear' to clear the screen\n";
	SetConsoleTextAttribute(console_color, 15);
}

bool MainConsole::isCommandValid(std::string command)
{
	if (command == "initialize" || command == "screen" || command == "scheduler-test" || command == "scheduler-stop" || command == "report-util" || command == "clear" || command == "exit")
	{
		return true;
	}
	else
	{
		return false;
	}
}

int MainConsole::commandRecognize(std::string command)
{
	if (command == "initialize" ||
		command == "screen" ||
		command == "scheduler-test" ||
		command == "scheduler-stop" ||
		command == "report-util")
	{
		std::cout << command << " command recognized. Doing something.\n";
		return 0;
	}
	else if (command == "clear")
	{
		system("cls");
		ASCIITextHeader();
		return 0;
	}
	else if (command == "exit")
	{
		exit(0);
	}
	else
	{
		std::cout << "Command not recognized. \n";
		return 0;
	}
}