// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"

#include "MainCharacterPlayerState.h"
#include "MainPlayerController.h"
#include "TestingGameState2.h"

#include "TestingGamemode2.generated.h"

/**
 * 
 */
UCLASS()
class LASTONELEFT_API ATestingGamemode2 : public AGameModeBase
{
	GENERATED_BODY()

	virtual void PostLogin(APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;

	public:
	
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
            void ShowGameUI(APlayerController* PlayerController);
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
			void CheckIfStart();
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
	        void StartGame();
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
			void EndGame();
	    UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Game Functions Events")
        	void RespawnPlayer(AMainPlayerController* playerController);
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
			void ReturnToLobby();
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Game Functions Events")
			void ChangeRespawningInText(AMainPlayerController* playerController, int time);
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
	        void ChangeStartingInText(int TimeLeftUntilStart);
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
			void ChangeTimeLeftText(int MatchTimeLeft);
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
			void ChangeReturningToLobbyText(int time);
		UFUNCTION(BlueprintCallable, Category = "LastOneLeft UI")
			int GetPlayersMeantToJoin();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
	        void StartGameCountdown();
	    UFUNCTION(BlueprintCallable, Category = "Game Functions")
	    	void StartRespawnCountdown(AMainPlayerController* playerController);
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			void StopMatchTimer();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			void StartReturnToLobbyCountdown();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			void StartMatchTimer();
		UFUNCTION(BlueprintCallable, Category = "UI Events")
			void SetPlayersFullyJoined(int fullyJoined);
		UFUNCTION(BlueprintCallable, Category = "UI Events")
			int GetPlayersFullyJoined();

		UFUNCTION(BlueprintCallable, Category = "UI Events")
			void AddPlayerFullyJoined();

	private:
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			UWorld* GetWorldFromPlayerController(APlayerController* PlayerController);
		UPROPERTY(VisibleAnywhere, Category = "Players Info")
			int playersMeantToJoin = 0;
		UPROPERTY(VisibleAnywhere, Category = "Players Info")
			int playersFullyJoined = 0;

		FTimerHandle StartingTimerHandle;
		int TimeLeftTilStart = 5;

		FTimerHandle LobbyReturnTimerHandle;
		int TimeLeftTilLobby = 10;
	
		UPROPERTY(VisibleAnywhere, Category = "Respawning Stuff")
			TMap<AMainPlayerController*, FTimerHandle> timerHandles;
		UPROPERTY(VisibleAnywhere, Category = "Respawning Stuff")
			TMap<AMainPlayerController*, int> playersRespawnTime;

		FTimerHandle MatchTimerHandle;
		int TimeLeftOfMatch = 600;

		void ProcessStartingTimer();

		void ProcessRespawnTimer(AMainPlayerController* PlayerController);

		void ProcessLobbyTimer();

		void ProcessMatchTimer();

		static bool IsHost(APlayerController* Controller)
		{
			if (Controller)
			{
				UWorld* World = GEngine->GetWorldFromContextObject(Controller, EGetWorldErrorMode::ReturnNull);

				if(World == nullptr)
				{
					if(GEngine != nullptr)
					{
						GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("There was an error getting the world."));
					}
						
					return false;
				}
					
				return GEngine->GetGamePlayer(World, 0)->PlayerController == Controller;
			}

			return false;
		}
	
};
