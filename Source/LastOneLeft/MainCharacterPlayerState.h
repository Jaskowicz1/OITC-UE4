// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "MainCharacter.h"
#include "GameFramework/PlayerState.h"
#include "MainCharacterPlayerState.generated.h"

/**
 * 
 */
UCLASS()
class LASTONELEFT_API AMainCharacterPlayerState : public APlayerState
{
	GENERATED_BODY()

public:
	AMainCharacterPlayerState();

	//UFUNCTION(Category = "Player Data Setting")
	//	void setPlayerName(FString playerName);
	//
	//UPROPERTY(VisibleAnywhere, Category = "Player Data")
	//	FString playerName;

	UFUNCTION(BlueprintCallable, Category = "Player Data")
		void SetPlayerCharacter(AMainCharacter* _MainCharacter);
	UFUNCTION(BlueprintCallable, Category = "Player Data")
        AMainCharacter* GetPlayerCharacter();

private:
	UPROPERTY()
		AMainCharacter* MainCharacter;
		
	
};
