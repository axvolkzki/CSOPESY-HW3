#include "ConsoleManager.h"

#include <iostream>
#include <string>
#include "MainConsole.h"


ConsoleManager* ConsoleManager::sharedInstance = nullptr;
ConsoleManager* ConsoleManager::getInstance()
{
//	if (instance == nullptr) {
//		initializeInstance();
//	}
	return sharedInstance;
}

void ConsoleManager::initializeInstance()
{
	/*if (sharedInstance == nullptr) {
		sharedInstance = new ConsoleManager();
	}*/
	sharedInstance = new ConsoleManager();
}

void ConsoleManager::destroyInstance()
{
	/*if (sharedInstance != nullptr) {
		delete sharedInstance;
		sharedInstance = nullptr;
	}*/
	delete sharedInstance;
}

void ConsoleManager::drawConsole() const
{
	std::cout << "Drawing console...\n";

	if (this->currentConsole != nullptr) {
		this->currentConsole->display();
	}
	else {
		std::cerr << "There is no existing console to display. Please check\n";
	}
}

void ConsoleManager::process() const
{
	/*std::string command;
	std::cout << "Enter a command: ";
	std::cin >> command;
	if (MainConsole::isCommandValid(command)) {
		MainConsole::commandRecognize(command);
	}
	else {
		std::cout << "Command not recognized. \n";
	}*/
	if (this->currentConsole != nullptr) {
		this->currentConsole->process();
	}
	else {
		std::cerr << "There is no existing console to process. Please check\n";
	}
}

void ConsoleManager::switchConsole(String consoleName) const
{
	if(this->consoleTable.contains(consoleName))
	{
		system("cls");
		this->previousConsole = this->currentConsole;
		this->currentConsole = this->consoleTable[consoleName];
		this->currentConsole->onEnabled();
	}
	else
	{
		std::cerr << "The console name is not found in the table. Please check\n";
	}
}

void ConsoleManager::registerScreen(std::shared_ptr<BaseScreen> screenReference)
{
	if (this->consoleTable.contains(screenReference->getName()))
	{
		std::cerr << "The screen name is already registered. Please check\n";
		return;
	}

	this->consoleTable[screenReference->getName()] = screenReference;
}


void ConsoleManager::switchToScreen(String screenName)
{
	if (this->consoleTable.contains(screenName))
	{
		this->switchConsole(screenName);
	}
	else
	{
		std::cerr << "The screen name is not found in the table. Please check\n";
	}
}


void ConsoleManager::unregisteredScreen(String screenName)
{
	if (this->consoleTable.contains(screenName))
	{
		this->consoleTable.erase(screenName);
	}
	else
	{
		std::cerr << "The screen name is not found in the table. Please check\n";
	}
}


// Constructor
ConsoleManager::ConsoleManager()
{
	this->running = true;

	// initialize the main console
	this->consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);

	const std::shared_ptr<MainConsole> mainConsole = std::make_shared<MainConsole>();


	this->consoleHandle[MAIN_CONSOLE] = mainConsole;

	this->switchConsole(MAIN_CONSOLE);			// first console to be displayed is the main menu
}

void ConsoleManager::returnToPreviousConsole()
{
	if (this->previousConsole != nullptr)
	{
		this->currentConsole = this->previousConsole;
		this->previousConsole = nullptr;
	}
	else
	{
		std::cerr << "There is no previous console to return to. Please check\n";
	}
}


void ConsoleManager::exitApplication()
{
	this->running = false;
}

bool ConsoleManager::isRunning() const
{
	return this->running;
}