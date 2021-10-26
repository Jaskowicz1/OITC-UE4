// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MainCharacterPlayerState.h"
#include "TestingGameState.h"
#include "Runtime/UMG/Public/UMG.h"
#include "TestingGamemode.generated.h"

/**
 * 
 */
UCLASS()
class LASTONELEFT_API ATestingGamemode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void PostLogin(class APlayerController* NewPlayer) override;

	virtual void Logout(AController* Exiting) override;

	public:
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
			void ShowLobbyUI(APlayerController* PlayerController);
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "LastOneLeft UI")
			void ChangeLobbyStartingText(int TimeLeftUntilStart);
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Game Functions")
			void FadeIntoGame();
		UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Game Functions")
        	void FadeOutIntoGame();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			void StartGame();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			void StopGameStart();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			int GetTimeTilStart();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			bool IsStarting();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			UWorld* GetWorldFromPlayerController(APlayerController* PlayerController);
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			void LoadIntoActualGame();
		UFUNCTION(BlueprintCallable, Category = "Game Functions")
			bool isInEditor();
	private:

		FTimerHandle StartingTimerHandle;
		int TimeLeftTilStart = 60;
		bool isStarting = false;

		void ProcessStartingTimer();
	
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
