#include "MainConsole.h"
#include "TypedefRepo.h"
#include "ConsoleManager.h"				// For exit command
#include <iostream>
#include <Windows.h>


// Constructor: Set the name of the console when MainConsole is instantiated
MainConsole::MainConsole() : AConsole("MainConsole") {}

// Override of onEnabled: This is called when the screen is shown for the first time
void MainConsole::onEnabled() {
	ASCIITextHeader();
}

// Override of display: Called to draw the screen each frame
void MainConsole::display() {
	ASCIITextHeader();
}

// Override of process: Handle input commands or other processes here
void MainConsole::process() {
	String command;
	bool isValidCommand;

	while (true) {
		std::cout << "Enter a command: ";
		std::getline(std::cin, command);

		isValidCommand = validateCommand(command);

		if (!isValidCommand) {
			std::cout << "Command not recognized. Please try again." << std::endl;
			continue; // Re-prompt for the command without displaying the header
		}

		// If the command is recognized
		if (command == "exit") {
			ConsoleManager::getInstance()->exitApplication();
			break;
		}
		else if (command == "clear") {
			system("cls");
			display();
		}
		else {
			recognizeCommand(command);
			continue;
		}
	}
}


void MainConsole::ASCIITextHeader() const {
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


bool MainConsole::validateCommand(String &input) const {
	bool isValid = false;

	String commandList[] = { "initialize", "exit", "clear",
							"scheduler-test", "scheduler-stop", "report-util",
							"screen" };

	// Check if the first word of the input is a valid command
	String inputCommand = input.substr(0, input.find(" "));

	for (String command : commandList) {
		if (inputCommand == command) {
			if (command == "screen") {
				if (isValidScreenCommand(input)) {
					isValid = true;
					break;
				}
			}
			else {
				isValid = true;
				break;
			}
		}
	}


	return isValid;
}

bool MainConsole::isValidScreenCommand(String command) const {
	bool isValid = false;

	String screenCommandList[] = { "screen -s", "screen -ls", "screen -r"};

	for (String screenCommand : screenCommandList) {
		if (command.substr(0, 9) == screenCommand) {
			isValid = true;
			break;
		}
		else if (command.substr(0, 10) == screenCommand) {
			isValid = true;
			break;
		}
	}

	return isValid;
}

void MainConsole::recognizeCommand(String command) const {
	std::cout << command << " command recognized. Doing something...\n";
}