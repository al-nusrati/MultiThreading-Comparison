// MultithreadingOnArray
//============================================================================================
#include <iostream>
#include <thread>   // Include the thread library to use std::thread for multi-threading
#include <chrono>   // C++11
#include "ConsoleUtils.h"

using namespace std;

//*****************************************
//					MAIN
//*****************************************
const int SIZE = 4'000'000;
int Data[SIZE];

// --------------------------------------
// Initializes array with 7s
// --------------------------------------
void InitializeDataArray() {
	for (int i = 0; i < SIZE; i++)
		Data[i] = 7;
}

// --------------------------------------
// Multiplies a range of elements by 3
// --------------------------------------
void MultiplyRange(int startIndex, int count) {
	int endIndex = startIndex + count;
	for (int i = startIndex; i < endIndex; i++) {
		Data[i] *= 3;
	}
}

// ---------------------------------------------
// Single-threaded: Multiply complete array by 3
// ---------------------------------------------
void Method_SingleThread() {
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

	MultiplyRange(0, SIZE);

	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);

	cout << "[Single Thread] Done. Time = " << duration.count() << " ms" << endl;
}

// ======================================
// Entry point
// ======================================
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
	cout << "|  Multi Threading Comparison   |\n";
	cout << "+-------------------------------+\n\n";
	utils.setForegroundColor(ConsoleColor::White);
#pragma endregion

	//--- App BODY --------------------------------

	// Single-threaded
	InitializeDataArray();
	Method_SingleThread();

	//---------------------------------------------

#pragma region footer

	cout << "\n\n";
	//--- show credits
	utils.showCredits();

	system("pause");
	// Disable option in Tools->Options->Debugging->General->"Automatically close the console when debugging stops"

	//--- return / finish
	return 0;
#pragma endregion
}