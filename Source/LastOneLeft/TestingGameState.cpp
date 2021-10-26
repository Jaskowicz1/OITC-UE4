// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingGameState.h"

void ATestingGameState::SetGameState(EGameStateEnum GameState)
{
	CurrentGameState = GameState;
}

EGameStateEnum ATestingGameState::GetGameState()
{
	return CurrentGameState;
}

TArray<ALobbyPlayerController*> ATestingGameState::GetPlayersConnected()
{
	return PlayersConnected;
}

void ATestingGameState::AddPlayerConnected(ALobbyPlayerController* PlayerController)
{
	PlayersConnected.Add(PlayerController);
}

void ATestingGameState::RemovePlayerConnected(ALobbyPlayerController* PlayerController)
{
	PlayersConnected.Remove(PlayerController);
}