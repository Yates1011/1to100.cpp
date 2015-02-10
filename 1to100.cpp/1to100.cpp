#include <iostream>
#include <cstdlib>
#include <ctime>

int main(void) {
	srand(time(NULL)); // To not have the same numbers over and over again.

	while (true) { // Main loop.
		// Initialize and allocate.
		int number = rand() % 99 + 2; // System number is stored in here.
		int guess; // User guess is stored in here.
		int tries = 0; // Number of tries is stored here.
		char answer; // User answer to question is stored here.

		//std::cout << number << "\n"; // Was used for debug...

		while (true) { // Get user number loop.
			// Get number.
			std::cout << "Enter a number between 1 and 100 (" << 20 - tries << " tries left): ";
			std::cin >> guess;
			std::cin.ignore();

			// Check is tries are taken up.
			if (tries >= 20) {
				break;
			}

			// Check number.
			if (guess > number) {
				std::cout << "Too high! Try again.\n";
			}
			else if (guess < number) {
				std::cout << "Too low! Try again.\n";
			}
			else {
				break;
			}

			// If not number, increment tries.
			tries++;
		}

		// Check for tries.
		if (tries >= 20) {
			std::cout << "You ran out of tries!\n\n";
		}
		else {
			// Or, user won.
			std::cout << "Congratulations!! " << std::endl;
			std::cout << "You got the right number in " << tries << " tries!\n";
		}

		while (true) { // Loop to ask user is he/she would like to play again.
			// Get user response.
			std::cout << "Would you like to play again (Y/N)? ";
			std::cin >> answer;
			std::cin.ignore();

			// Check if proper response.
			if (answer == 'n' || answer == 'N' || answer == 'y' || answer == 'Y') {
				break;
			}
			else {
				std::cout << "Please enter \'Y\' or \'N\'...\n";
			}
		}

		// Check user's input and run again or exit;
		if (answer == 'n' || answer == 'N') {
			std::cout << "Thank you for playing!";
			break;
		}
		else {
			std::cout << "\n\n\n";
		}
	}

	// Safely exit.
	std::cout << "\n\nEnter anything to exit. . . ";
	std::cin.ignore();
	return 0;
}