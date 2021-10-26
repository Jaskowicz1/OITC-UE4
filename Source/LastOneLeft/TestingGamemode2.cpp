// Fill out your copyright notice in the Description page of Project Settings.


#include "TestingGamemode2.h"

#include "Kismet/GameplayStatics.h"

void ATestingGamemode2::PostLogin(APlayerController* NewPlayer)
{

	if(playersMeantToJoin == 0)
	{
		FString playersInGame = UGameplayStatics::ParseOption(OptionsString, "PlayersJoined");
		playersMeantToJoin = FCString::Atoi(*playersInGame);
	}
	
	AMainCharacterPlayerState* playerState = Cast<AMainCharacterPlayerState>(NewPlayer->PlayerState);
	FString name = playerState->GetPlayerName();

	AMainPlayerController* MainPlayerController = Cast<AMainPlayerController>(NewPlayer);

	ATestingGameState2* TestingGameState = Cast<ATestingGameState2>(GameState);

	TestingGameState->AddPlayerConnected(MainPlayerController);

	Super::PostLogin(NewPlayer);

	ShowGameUI(NewPlayer);

	CheckIfStart();
}

void ATestingGamemode2::Logout(AController* Exiting)
{
	
	if(Exiting->IsPlayerController())
	{
		AMainPlayerController* PlayerController = Cast<AMainPlayerController>(Exiting);
		ATestingGameState2* TestingGameState = Cast<ATestingGameState2>(GameState);

		TestingGameState->RemovePlayerConnected(PlayerController);
		TestingGameState->RemovePlayerAlive(PlayerController);
		TestingGameState->RemovePlayerDead(PlayerController);
	}
	
	Super::Logout(Exiting);	
}

UWorld* ATestingGamemode2::GetWorldFromPlayerController(APlayerController* PlayerController)
{
	return GEngine->GetWorldFromContextObject(PlayerController, EGetWorldErrorMode::ReturnNull);
}

int ATestingGamemode2::GetPlayersMeantToJoin()
{
	return playersMeantToJoin;
}

void ATestingGamemode2::StartGameCountdown()
{
	TimeLeftTilStart = 5;

	GetWorldTimerManager().SetTimer(StartingTimerHandle, this, &ATestingGamemode2::ProcessStartingTimer, 1.f, true, 1.f);
}

void ATestingGamemode2::StartReturnToLobbyCountdown()
{
	TimeLeftTilLobby = 10;

	GetWorldTimerManager().SetTimer(LobbyReturnTimerHandle, this, &ATestingGamemode2::ProcessLobbyTimer, 1.f, true, 1.f);
}

void ATestingGamemode2::StartRespawnCountdown(AMainPlayerController* playerController)
{

	playersRespawnTime.Add(playerController, 5);

	FTimerDelegate RespawnDelegate = FTimerDelegate::CreateUObject(this, &ATestingGamemode2::ProcessRespawnTimer, playerController);

	FTimerHandle TimerHandle;

	timerHandles.Add(playerController, TimerHandle);
	
	GetWorldTimerManager().SetTimer(*timerHandles.Find(playerController), RespawnDelegate, 1.f, true);
}

void ATestingGamemode2::StartMatchTimer()
{
	TimeLeftOfMatch = 600;

	GetWorldTimerManager().SetTimer(MatchTimerHandle, this, &ATestingGamemode2::ProcessMatchTimer, 1.f, true, 1.f);
}

void ATestingGamemode2::StopMatchTimer()
{
	GetWorldTimerManager().ClearTimer(MatchTimerHandle);
}

void ATestingGamemode2::ProcessRespawnTimer(AMainPlayerController* playerController)
{
	
	int respawnTime = *playersRespawnTime.Find(playerController);

	respawnTime -= 1;

	playersRespawnTime.Add(playerController, respawnTime);

	if(respawnTime > 0)
	{
		ChangeRespawningInText(playerController, respawnTime);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(*timerHandles.Find(playerController));
		RespawnPlayer(playerController);
	}
}


void ATestingGamemode2::ProcessStartingTimer()
{
	TimeLeftTilStart -= 1;

	if(TimeLeftTilStart > 0)
	{
		ChangeStartingInText(TimeLeftTilStart);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(StartingTimerHandle);
		StartGame();
	}
}

void ATestingGamemode2::ProcessLobbyTimer()
{
	TimeLeftTilLobby -= 1;

	if(TimeLeftTilLobby > 0)
	{
		ChangeReturningToLobbyText(TimeLeftTilLobby);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(LobbyReturnTimerHandle);
		//ReturnToLobby();

		FString URL = "/Game/Maps/Lobby?listen";
	
		UWorld* World = GetWorld();
		//bUseSeamlessTravel = true;
		World->ServerTravel(URL);
	}
}

void ATestingGamemode2::ProcessMatchTimer()
{
	TimeLeftOfMatch -= 1;

	if(TimeLeftOfMatch > 0)
	{
		ChangeTimeLeftText(TimeLeftOfMatch);
	}
	else
	{
		GetWorldTimerManager().ClearTimer(MatchTimerHandle);
		EndGame();
	}
}

int ATestingGamemode2::GetPlayersFullyJoined()
{
	return playersFullyJoined;
}

void ATestingGamemode2::SetPlayersFullyJoined(int fullyJoined)
{
	playersFullyJoined = fullyJoined;
}


void ATestingGamemode2::AddPlayerFullyJoined()
{
	playersFullyJoined += 1;
}