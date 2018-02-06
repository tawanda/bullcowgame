#include "FBullCowGame.h"

void FBullCowGame::Reset() {
	constexpr int CURRENT_TRY = 1;
	constexpr int MAX_TRIES = 8;

	MyCurrentTry = CURRENT_TRY;
	MyMaxTries = MAX_TRIES;
	return;
}

FBullCowGame::FBullCowGame() {
	Reset();
}

int FBullCowGame::GetMaxTries() const { return MyMaxTries; }
int FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }

void FBullCowGame::SetCurrentTry(int TryNumber) { MyCurrentTry = TryNumber; }

bool FBullCowGame::IsGameWon() const {
	return false;
}

bool FBullCowGame::CheckGuessValidity(std::string) const {
	return false;
}
