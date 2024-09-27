#pragma once
#include <memory>
#include <vector>
#include "AConsole.h"
#include <unordered_map>
#include <Windows.h>




const String MAIN_CONSOLE = "MAIN_CONSOLE";

class ConsoleManager
{
public:
	typedef std::unordered_map<String, std::shared_ptr<AConsole>> ConsoleTable;		// collection of key-value pairs

	static ConsoleManager* getInstance();
	static void initializeInstance();
	static void destroyInstance();

	void drawConsole() const;
	void process() const;
	void switchConsole() const;

	void registerScreen(std::shared_ptr<BaseScreen> screenReference);		// to add a screen to the table
	void switchToScreen(String screenName);
	void unregisteredScreen(String screenName);

	void returnToPreviousConsole();
	void exitApplication();
	bool isRunning() const;

	HANDLE getConsoleHandle() const;

	void setCursorPosition(int posX, int posY) const;

private:
	ConsoleManager();
	~ConsoleManager() = default;
	ConsoleManager(ConsoleManager const&) {};				// copy constructor is private
	ConsoleManager& operator=(ConsoleManager const&) {};	// assignment operator is private
	static ConsoleManager* sharedInstance;

	ConsoleTable consoleTable;
	std::shared_ptr<AConsole> currentConsole;
	std::shared_ptr<AConsole> previousConsole;

	HANDLE consoleHandle;
	bool running = true;
};
