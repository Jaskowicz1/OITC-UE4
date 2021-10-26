// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "EGameStateEnum.h"
#include "MainPlayerController.h"
#include "GameFramework/GameStateBase.h"
#include "TestingGameState2.generated.h"

/**
 * 
 */
UCLASS()
class LASTONELEFT_API ATestingGameState2 : public AGameStateBase
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Game State")
        void SetGameState(EGameStateEnum GameState);
	UFUNCTION(BlueprintCallable, Category = "Game State")
        EGameStateEnum GetGameState();
//
//		=====================================================================
//
	
	UFUNCTION(BlueprintCallable, Category = "Players Info")
        TArray<AMainPlayerController*> GetPlayersConnected();
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
		TArray<AMainPlayerController*> GetPlayersAlive();
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
        TArray<AMainPlayerController*> GetPlayersDead();
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
        TMap<AMainPlayerController*, int> GetPlayersScore();
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
		TMap<AMainPlayerController*, int> GetTop3PlayersScore();

//
//		=====================================================================
//
	
	UFUNCTION(BlueprintCallable, Category = "Players Info")
        void AddPlayerConnected(AMainPlayerController* PlayerController);
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
        void AddPlayerAlive(AMainPlayerController* PlayerController);
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
		void AddPlayerDead(AMainPlayerController* PlayerController);
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
		void SetPlayerScore(AMainPlayerController* PlayerController, int score);

	UFUNCTION(BlueprintCallable, Category = "Players Info")
        void RemovePlayerConnected(AMainPlayerController* PlayerController);
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
        void RemovePlayerAlive(AMainPlayerController* PlayerController);
	UFUNCTION(BlueprintCallable, Category = "Players In-Game Info")
        void RemovePlayerDead(AMainPlayerController* PlayerController);

private:
	UPROPERTY()
		EGameStateEnum CurrentGameState = EGameStateEnum::EState_Starting;

	UPROPERTY(VisibleAnywhere, Category = "Players Info")
		TArray<AMainPlayerController*> PlayersConnected;
	UPROPERTY(VisibleAnywhere, Category = "Players In-Game Info")
		TArray<AMainPlayerController*> PlayersAlive;
	UPROPERTY(VisibleAnywhere, Category = "Players In-Game Info")
		TArray<AMainPlayerController*> PlayersDead;
	UPROPERTY(VisibleAnywhere, Category = "Players In-Game Info")
		TMap<AMainPlayerController*, int> PlayersScore;

	
};
