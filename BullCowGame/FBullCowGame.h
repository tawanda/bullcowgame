#pragma once
#include <string>

class FBullCowGame {
public:
	FBullCowGame();
	int GetMaxTries() const;
	int GetCurrentTry() const;
	void SetCurrentTry(int TryNumber);
	bool IsGameWon() const;
	bool CheckGuessValidity(std::string) const;
	void Reset();

private:
	int MyCurrentTry;
	int MyMaxTries;

};
