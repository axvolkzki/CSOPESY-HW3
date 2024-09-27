#pragma once
#include <memory>

#include "AConsole.h"
#include "Process.h"


class BaseScreen : public AConsole				// actual implementation of console
{
public:
	BaseScreen(std::shared_ptr<Process> process, String processName);
	void onEnabled() override;
	void display() override;
	void process() override;

private:
	void printProcessInfo() const;
	std::shared_ptr<Process> attachedProcess;
	bool refreshed = false;
};
