#include "FBullCowGame.h"

void FBullCowGame::Reset() 
{

	constexpr int32 MAX_TRIES = 8;
	this->MyMaxTries = MAX_TRIES;

	const FString HIDDEN_WORD = "antsdvdggdgodfgdfgdfgf";
	this->MyHiddenWord = HIDDEN_WORD;

	this->MyCurrentTry = 1;
	return;
}

FBullCowCount FBullCowGame::SubmitGuess(FString Guess) 
{

	this->MyCurrentTry++;
	FBullCowCount BullCowCount;

	const int32 HiddenWordLength = this->MyHiddenWord.length();

	int32 GuessWordLength = 0;
	
	// Fix the bug of out of range when Guess length is bigger than word length
	(Guess.length() > HiddenWordLength) ? (GuessWordLength = HiddenWordLength) : (GuessWordLength = Guess.length());

	for (int32 i = 0; i < GuessWordLength; i++) 
	{
		if (Guess[i] == this->MyHiddenWord[i]) 
		{
			BullCowCount.Bulls++; 
		}

		for (int32 j = 0; j < HiddenWordLength; j++) 
		{
			if (Guess[i] == this->MyHiddenWord[j] && i!=j) 
			{ 
				BullCowCount.Cows++; 
			}
		}
	}

	return BullCowCount;
}

FBullCowGame::FBullCowGame()
{
	Reset();
}

int32 FBullCowGame::GetMaxTries() const
{
	return this->MyMaxTries;
}

int32 FBullCowGame::GetCurrentTry() const
{
	return this->MyCurrentTry;
}

int32 FBullCowGame::GetHiddenWordLength() const
{
	return this->MyHiddenWord.length();
}

void FBullCowGame::SetCurrentTry(int32 TryNumber)
{
	this->MyCurrentTry = TryNumber;
}

bool FBullCowGame::IsGameWon()
{
	return false;
}


//EGuessStatus CheckLength (FString Word)
//{
//	if Word.length() == 
//	
//}

EGuessStatus FBullCowGame::CheckGuessValidity(const FString &Guess)
{

	const int word_length = this->GetHiddenWordLength();

	if (Guess.length() != word_length)
	{	
		return EGuessStatus::wrong_length;
		
	}
	else if (false)
	{
		return EGuessStatus::not_lowercase;
	}
	else if (false)
	{
		return EGuessStatus::not_isogram;
	}
	else
	{
		return EGuessStatus::ok;
	}

} 