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
const int SIZE = 40'000'000;
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

// --------------------------------------
// Single-threaded: Multiply all by 3
// --------------------------------------
void Method_SingleThread() {
	// Record the starting time point using the high-resolution clock
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

	MultiplyRange(0, SIZE); // Perform the actual work

	// Record the ending time point using the high-resolution clock
	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();

	// Calculate the elapsed time in milliseconds between start and end
	chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);

	cout << "[Single Thread] Done. Time = " << duration.count() << " ms" << endl;
}

void Method_TwinThreads() {
	int half = SIZE / 2;

	// Get the current (starting) time point from high_resolution_clock
	chrono::high_resolution_clock::time_point start = chrono::high_resolution_clock::now();

	//******************************
	thread t1(MultiplyRange, 0, half);          // Start a new thread (t1) and run the MultiplyRange function on the first half of the array
	thread t2(MultiplyRange, half, SIZE - half);// Start a new thread (t2) and run the MultiplyRange function on the second half of the array

	t1.join();  // Wait for thread t1 to finish before moving on
	t2.join();  // Wait for thread t2 to finish before moving on
	//******************************

	// Get another time point (ending time point) from high_resolution_clock
	chrono::high_resolution_clock::time_point end = chrono::high_resolution_clock::now();
	// Calculate the duration
	chrono::milliseconds duration = chrono::duration_cast<chrono::milliseconds>(end - start);

	cout << "[Twin Threads] Done. Time = " << duration.count() << " ms" << endl;
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


	// Twin-threaded
	InitializeDataArray();
	Method_TwinThreads();		

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