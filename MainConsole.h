#pragma once

class MainConsole
{
public:
	static void ASCIITextHeader();
	static bool isCommandValid(std::string command);
	static int commandRecognize(std::string command);
};