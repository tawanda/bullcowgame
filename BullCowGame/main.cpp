#include <iostream>
#include <string>
#include "FBullCowGame.h"

using FText = std::string;
using int32 = int;

void PrintIntro();
FText GetPlayerGuess();
bool AskToContinue();
void PlayGame();


FBullCowGame BCGame;

int main() {
	PrintIntro();


	PlayGame();
}

void PrintIntro(){
	constexpr int32 WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a Fun word game \n";
	std::cout << "Can you Guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
}

FText GetPlayerGuess(){	
	FText Guess = "hello";

	int32 CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try number [ " << CurrentTry  << " ]," << "Enter your guess >> ";
	std::getline(std::cin, Guess);
	std::cout << "Your guess was \"" << Guess << "\"\n" << std::endl;

	return Guess;
}

bool AskToContinue(){
	FText play = "N";

	std::cout << "Continue Playing (y/N)?";
	std::getline(std::cin, play);

	return (play == "y" ) || (play == "Y");
}

void PlayGame()
{
	BCGame.Reset();
	int32 MaxTries = BCGame.GetMaxTries();

	bool GameOn = true;

	do {
		for (int32 i = 1; i <= MaxTries; i++) {
			FText Guess = GetPlayerGuess();
			FBullCowCount BullCowCount = BCGame.SubmitGuess(Guess);

			std::cout << "Bulls = " << BullCowCount.Bulls << " Cows = " << BullCowCount.Cows << std::endl;
		}
		GameOn = AskToContinue();
	} while (GameOn == true);

	std::cout << "\nThank you for playing\n";

	// TODO summarise game
}
