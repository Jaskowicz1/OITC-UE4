// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacterPlayerState.h"

AMainCharacterPlayerState::AMainCharacterPlayerState()
{

}

void AMainCharacterPlayerState::SetPlayerCharacter(AMainCharacter* _MainCharacter)
{
	MainCharacter = _MainCharacter;
}

AMainCharacter* AMainCharacterPlayerState::GetPlayerCharacter()
{
	return MainCharacter;
}

