// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "MenuGamemode.generated.h"

/**
 * 
 */
UCLASS()
class LASTONELEFT_API AMenuGamemode : public AGameModeBase
{
	GENERATED_BODY()

	virtual void StartPlay() override;
	
	UFUNCTION( BlueprintPure, Category = "Extras" )
        bool IsWithEditor() const
        {
            #if WITH_EDITOR
                return true;
            #else
                return false;
            #endif
        }
	
};
