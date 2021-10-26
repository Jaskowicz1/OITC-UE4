// Fill out your copyright notice in the Description page of Project Settings.


#include "AWorldCamera.h"

// Sets default values
AAWorldCamera::AAWorldCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

}

// Called when the game starts or when spawned
void AAWorldCamera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AAWorldCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AAWorldCamera::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

