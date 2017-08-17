//testing the Date library with main function

#include "stdafx.h"

void waitForInput();

int main()
{
	waitForInput();
	return 0;
}

void waitForInput()
{
	std::string s;
	std::getline(std::cin, s);
}