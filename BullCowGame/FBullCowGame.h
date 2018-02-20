#pragma once
#include <string>

using FString = std::string;
using int32 = int;

struct FBullCowCount {
	int32 Bulls = 0;
	int32 Cows = 0;
};


enum class  EWordStatus {
	ok,
	not_isogram,
	wrong_length,
	not_lowercase,
};

enum class  EGuessStatus {
	ok,
	not_isogram,
	wrong_length,
	not_lowercase,
};



class FBullCowGame {
public:
	FBullCowGame();
	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	static bool IsGameWon();
	EGuessStatus CheckGuessValidity(const FString &Guess);
	void SetCurrentTry(int32 TryNumber);
	void Reset();

	FBullCowCount SubmitGuess(FString);

private:
	int32 MyCurrentTry{};
	int32 MyMaxTries{};
	FString MyHiddenWord;
};
