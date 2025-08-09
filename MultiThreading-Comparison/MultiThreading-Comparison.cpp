#include <iostream>
#include "ConsoleUtils.h"
using namespace std;

//*****************************************
//					MAIN
//*****************************************

int main()
{
#pragma region header
	ConsoleUtils utils;

	//--- setup console
	utils.enableVirtualTerminal();
	utils.setBackgroundColor(ConsoleColor::Blue);
	utils.clearConsole();

	//--- show app title
	utils.setForegroundColor(ConsoleColor::BrightWhite);
	cout << "+-------------------------------+\n";
	cout << "| App Name                      |\n";
	cout << "+-------------------------------+\n\n";
	utils.setForegroundColor(ConsoleColor::White);
#pragma endregion


	//--- App BODY --------------------------------

	
	//---------------------------------------------


#pragma region footer
	//--- show credits
	utils.showCredits();

	system("pause");
	// Disable option in Tools->Options->Debugging->General->"Automatically close the console when debugging stops"

	//--- return / finish
	return 0;
#pragma endregion
}