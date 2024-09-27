#include "BaseScreen.h"

#include "ConsoleManager.h"

#include <iostream>   // For displaying output (if needed)

// Constructor Implementation
BaseScreen::BaseScreen(std::shared_ptr<Process> process, String processName)
    : attachedProcess(process), refreshed(false)
{
    // You can initialize processName or handle it here if necessary
    // Example: store or log processName
}

// Overrides the onEnabled function from AConsole
void BaseScreen::onEnabled()
{
    // Implement the logic when the BaseScreen is enabled
    std::cout << "BaseScreen enabled!" << std::endl;
    refreshed = false;  // Example: reset refresh status
}

// Overrides the display function from AConsole
void BaseScreen::display()
{
    // Implement the logic to display information on the console
    std::cout << "Displaying BaseScreen content..." << std::endl;
    printProcessInfo();  // Optionally display process info
}

// Overrides the process function from AConsole
void BaseScreen::process()
{
    // Implement the logic to process input or data
    std::cout << "Processing BaseScreen..." << std::endl;

    // Example processing logic could go here
    // Check if the process has been refreshed and act accordingly
    if (!refreshed)
    {
        // Assume this refreshes or processes the data
        std::cout << "Refreshing process info..." << std::endl;
        refreshed = true;  // Mark as refreshed
    }
}

// Private method to print process information
void BaseScreen::printProcessInfo() const
{
    // Implement the logic to print information about the attached process
    if (attachedProcess)  // Check if attachedProcess is valid
    {
        std::cout << "Process info: " << attachedProcess->getInfo() << std::endl;
    }
    else
    {
        std::cout << "No process attached." << std::endl;
    }
}
