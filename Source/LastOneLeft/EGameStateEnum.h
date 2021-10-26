// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"


/**
 * 
 */
UENUM(BlueprintType)
enum class EGameStateEnum : uint8
{

    EState_Lobby				UMETA(DisplayName="Lobby"),
    EState_LobbyStarting		UMETA(DisplayName="LobbyStarting"),
    EState_Starting				UMETA(DisplayName="Starting"),
    EState_Started				UMETA(DisplayName="Started"),
    EState_Ended				UMETA(DisplayName="Ended")
};