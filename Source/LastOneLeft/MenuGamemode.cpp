// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuGamemode.h"

void AMenuGamemode::StartPlay()
{
	Super::StartPlay();

	check(GEngine != nullptr);

	// Display a message for 5 seconds.
	// The -1 key value argument prevents the message from being update or refreshed
	//GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("Hello World, this is the main menu gamemode base!"));
}

