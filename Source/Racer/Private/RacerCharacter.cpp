// Fill out your copyright notice in the Description page of Project Settings.


#include "RacerCharacter.h"

// Sets default values
ARacerCharacter::ARacerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARacerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARacerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARacerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ARacerCharacter::FellOutOfWorld(const class UDamageType& dmgType)
{
	APlayerController* PlayerController = GetController <APlayerController>();
	if (PlayerController)
	{
		//We need to teleport the player to the last checkpoint 
		if (LastCheckpointPosition.IsNearlyZero())
		{
			PlayerController->RestartLevel();
		}
		else
		{
			SetActorLocation(LastCheckpointPosition);
		}
	}
}


