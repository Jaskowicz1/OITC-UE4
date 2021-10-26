// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingGameState2.h"

void ATestingGameState2::SetGameState(EGameStateEnum GameState)
{
	CurrentGameState = GameState;
}

EGameStateEnum ATestingGameState2::GetGameState()
{
	return CurrentGameState;
}

TArray<AMainPlayerController*> ATestingGameState2::GetPlayersConnected()
{
	return PlayersConnected;
}

TArray<AMainPlayerController*> ATestingGameState2::GetPlayersAlive()
{
	return PlayersAlive;
}

TArray<AMainPlayerController*> ATestingGameState2::GetPlayersDead()
{
	return PlayersDead;
}

TMap<AMainPlayerController*, int> ATestingGameState2::GetPlayersScore()
{
	return PlayersScore;
}


void ATestingGameState2::AddPlayerConnected(AMainPlayerController* PlayerController)
{
	PlayersConnected.Add(PlayerController);
}

void ATestingGameState2::AddPlayerDead(AMainPlayerController* PlayerController)
{
	PlayersDead.Add(PlayerController);
}

void ATestingGameState2::AddPlayerAlive(AMainPlayerController* PlayerController)
{
	PlayersAlive.Add(PlayerController);
}

void ATestingGameState2::SetPlayerScore(AMainPlayerController* PlayerController, int score)
{
	PlayersScore.Add(PlayerController, score);
}


void ATestingGameState2::RemovePlayerConnected(AMainPlayerController* PlayerController)
{
	PlayersConnected.Remove(PlayerController);
}

void ATestingGameState2::RemovePlayerAlive(AMainPlayerController* PlayerController)
{
	PlayersAlive.Remove(PlayerController);
}

void ATestingGameState2::RemovePlayerDead(AMainPlayerController* PlayerController)
{
	PlayersDead.Remove(PlayerController);
}

TMap<AMainPlayerController*, int> ATestingGameState2::GetTop3PlayersScore()
{

	TMap<AMainPlayerController*, int> tempScores = PlayersScore;
	
	TMap<AMainPlayerController*, int> scores;

	tempScores.ValueSort([](const int& A, const int& B) {
		return A > B; // sort strings by num.
	});

	int counted = 0;

	for(auto& Elem : tempScores)
	{
		scores.Add(Elem.Key, Elem.Value);

		counted++;

		if(counted == 3)
		{
			break;
		}
	}

	return scores;
}
