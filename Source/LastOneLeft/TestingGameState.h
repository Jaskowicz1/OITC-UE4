// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EGameStateEnum.h"
#include "LobbyPlayerController.h"
#include "MainPlayerController.h"

#include "GameFramework/GameStateBase.h"
#include "TestingGameState.generated.h"

/**
 * 
 */
UCLASS()
class LASTONELEFT_API ATestingGameState : public AGameStateBase
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
			TArray<ALobbyPlayerController*> GetPlayersConnected();

//
//		=====================================================================
//
	
		UFUNCTION(BlueprintCallable, Category = "Players Info")
	        void AddPlayerConnected(ALobbyPlayerController* PlayerController);

		UFUNCTION(BlueprintCallable, Category = "Players Info")
	        void RemovePlayerConnected(ALobbyPlayerController* PlayerController);

//
//		=====================================================================
//

	private:
		UPROPERTY()
			EGameStateEnum CurrentGameState = EGameStateEnum::EState_Lobby;
	
		UPROPERTY(VisibleAnywhere, Category = "Players Info")
			TArray<ALobbyPlayerController*> PlayersConnected;
	
};
