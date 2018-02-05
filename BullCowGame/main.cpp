#include <iostream>
#include <string>


void PrintIntro();
std::string GetPlayerGuess(int count);
bool AskToContinue();

int main() {

	std::string guess = "";
	bool GameOn = true;
	constexpr int NUMBER_OF_TURNS = 5;
	

	PrintIntro();

	do{
	for (int i = NUMBER_OF_TURNS; i >= 1; i--) {
		guess = GetPlayerGuess(i);
	} 
	GameOn = AskToContinue();
	} while(GameOn == true);

	std::cout << guess;


}

void PrintIntro(){
	constexpr int WORD_LENGTH = 9;

	std::cout << "Welcome to Bulls and Cows, a Fun word game \n";
	std::cout << "Can you Guess the " << WORD_LENGTH << " letter isogram I'm thinking of? \n";
	std::cout << std::endl;
}

std::string GetPlayerGuess(int count){	
	std::string Guess = "hello";

	std::cout << "You are left with [ " << count  << " ] chances," << "Enter your guess >> ";
	std::getline(std::cin, Guess);
	std::cout << "Your guess was \"" << Guess << "\"\n" << std::endl;

	return Guess;
}

bool AskToContinue(){
	std::string play = "N";

	std::cout << "Continue Playing (Y/N)?";
	std::getline(std::cin, play);

	return (play == "y" ) || (play == "Y");
}
