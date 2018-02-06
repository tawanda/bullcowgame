#include <iostream>
#include <string>
#include "FBullCowGame.h"



void PrintIntro();
std::string GetPlayerGuess();
bool AskToContinue();
void PlayGame();


FBullCowGame BCGame;

int main() {
	PrintIntro();
	PlayGame();
	
}

void PrintIntro(){
	constexpr int WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a Fun word game \n";
	std::cout << "Can you Guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
}

std::string GetPlayerGuess(){	
	std::string Guess = "hello";

	int CurrentTry = BCGame.GetCurrentTry();

	std::cout << "Try number [ " << CurrentTry  << " ]," << "Enter your guess >> ";
	std::getline(std::cin, Guess);
	std::cout << "Your guess was \"" << Guess << "\"\n" << std::endl;

	return Guess;
}

bool AskToContinue(){
	std::string play = "N";

	std::cout << "Continue Playing (y/N)?";
	std::getline(std::cin, play);

	return (play == "y" ) || (play == "Y");
}

void PlayGame()
{

	std::string guess = "";
	bool GameOn = true;

	constexpr int NUMBER_OF_TURNS = 5;

	do {
		for (int i = 1; i <= NUMBER_OF_TURNS; i++) {
			BCGame.SetCurrentTry(i);
			guess = GetPlayerGuess();
		}
		GameOn = AskToContinue();
	} while (GameOn == true);

	std::cout << "\nThank you for playing\n";

}
