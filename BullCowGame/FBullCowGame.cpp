#include "FBullCowGame.h"

void FBullCowGame::Reset() {

	constexpr int32 MAX_TRIES = 8;
	this->MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "planet";

	this->MyCurrentTry = 1;
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString) {

	MyCurrentTry++;
	FBullCowCount BullCowCount;

	int32 HiddenWordLength = MyHiddenWord.length();

	for (int32 i = 0; i < HiddenWordLength; i++) {

		for (int32 j = 0; j < HiddenWordLength; j++) {
		}

	}

	return BullCowCount;
}

FBullCowGame::FBullCowGame() { Reset(); }

int32 FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
void FBullCowGame::SetCurrentTry(int32 TryNumber) { MyCurrentTry = TryNumber; }
bool FBullCowGame::IsGameWon() const { return false; }
bool FBullCowGame::CheckGuessValidity(FString) const { return false; }
