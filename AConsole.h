#pragma once
#include <string>

class AConsole							// abstract class
{
public:
	typedef std::string String;
	AConsole(String name);
	~AConsole() = default;

	String getName();
	virtual void onEnabled() = 0;		// to initialize the console from the first start
	virtual void display() = 0;			// drawing proper, called per frame
	virtual void process() = 0;			// to handle input commands (computation)

	String name;
	friend class ConsoleManager;		// to allow access to private members
};
