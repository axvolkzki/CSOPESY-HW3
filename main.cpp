/*
* CSOPESY - S11
* Group 13	: Abenoja, Amelia Joyce
*			: Cuales, Bianca Mari
*			: Culala, Mary Erika
*			: Uy, Gleezell Vina
*
* Week 3 - Group Homework - Designing console layouts
* Last modified: 09/27/2024
*/


#include <iostream>
#include <windows.h>

#include "ConsoleManager.h"
#include "MainConsole.h"

using namespace std;


// col x rows
//void SetConsoleWindowSize(int width, int height)
//{
//	const HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
//	const COORD newSize = { static_cast<short>(width), static_cast<short>(height) };
//	SetConsoleScreenBufferSize(hConsole, newSize);
//
//	const SMALL_RECT rect = { 0, 0, newSize.X - 1, newSize.Y - 1 };
//	SetConsoleWindowInfo(hConsole, TRUE, &rect);
//}



int main()
{
	ConsoleManager::initializeInstance();

	bool running = true;

	while(running)
	{
		ConsoleManager::getInstance()->process();
		ConsoleManager::getInstance()->drawConsole();


		running = ConsoleManager::getInstance()->isRunning();
	}


	
	// Destroy all the instances
	ConsoleManager::destroyInstance();
	return 0;
}