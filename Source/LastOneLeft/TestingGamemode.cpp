// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingGamemode.h"

#include "AWorldCamera.h"
#include "LobbyPlayerState.h"

void ATestingGamemode::PostLogin(APlayerController* NewPlayer)
{

	ALobbyPlayerState* playerState = Cast<ALobbyPlayerState>(NewPlayer->PlayerState);
	FString name = playerState->GetPlayerName();

	ALobbyPlayerController* MainPlayerController = Cast<ALobbyPlayerController>(NewPlayer);

	ATestingGameState* TestingGameState = Cast<ATestingGameState>(GameState);

	if(TestingGameState->GetGameState() == EGameStateEnum::EState_Lobby || TestingGameState->GetGameState() == EGameStateEnum::EState_LobbyStarting)
	{
		// Code to stop timer?
	}

	TestingGameState->AddPlayerConnected(MainPlayerController);

	// Put this here so BP sees the new player connected in the array.
	Super::PostLogin(NewPlayer);

	ShowLobbyUI(NewPlayer);
}

void ATestingGamemode::StartGame()
{
	TimeLeftTilStart = 60;

	isStarting = true;

	GetWorldTimerManager().SetTimer(StartingTimerHandle, this, &ATestingGamemode::ProcessStartingTimer, 1.f, true, 1.f);
}

int ATestingGamemode::GetTimeTilStart()
{
	return TimeLeftTilStart;
}

bool ATestingGamemode::IsStarting()
{
	return isStarting;
}

void ATestingGamemode::StopGameStart()
{
	ATestingGameState* TestingGameState = Cast<ATestingGameState>(GameState);

	TestingGameState->SetGameState(EGameStateEnum::EState_Lobby);

	GetWorldTimerManager().ClearTimer(StartingTimerHandle);

	TimeLeftTilStart = 60;

	isStarting = false;
}

void ATestingGamemode::ProcessStartingTimer()
{
	TimeLeftTilStart -= 1;

	if(TimeLeftTilStart > 0)
	{
		ChangeLobbyStartingText(TimeLeftTilStart);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(StartingTimerHandle);
		FadeIntoGame();
	}
}

void ATestingGamemode::Logout(AController* Exiting)
{
	
	if(Exiting->IsPlayerController())
	{
		ALobbyPlayerController* PlayerController = Cast<ALobbyPlayerController>(Exiting);
		ATestingGameState* TestingGameState = Cast<ATestingGameState>(GameState);

		TestingGameState->RemovePlayerConnected(PlayerController);
	}

	Super::Logout(Exiting);
}

UWorld* ATestingGamemode::GetWorldFromPlayerController(APlayerController* PlayerController)
{
	return GEngine->GetWorldFromContextObject(PlayerController, EGetWorldErrorMode::ReturnNull);
}

void ATestingGamemode::LoadIntoActualGame()
{
	ATestingGameState* TestingGameState = Cast<ATestingGameState>(GameState);

	TestingGameState->SetGameState(EGameStateEnum::EState_Starting);

	FString URL = "/Game/Maps/TestLevel2?playersjoined=";
	URL.Append(FString::FromInt(TestingGameState->GetPlayersConnected().Num()));
	URL.Append("?listen");
	
	UWorld* World = GetWorld();
	World->ServerTravel(URL);
}

bool ATestingGamemode::isInEditor()
{
	#if WITH_EDITOR
		return true;
	#else
		return false;
	#endif
}