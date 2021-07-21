// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerVolume.h"
#include "RacerCheckpointVolume.generated.h"

class ARacerCheckpointVolume;

DECLARE_DYNAMIC_MULTICAST_SPARSE_DELEGATE_OneParam(FActorReachedFinishLine, ARacerCheckpointVolume, OnActorReachedFinishLine, class ARacerCharacter*, RacerCharacter);

UCLASS(BlueprintType, Blueprintable)
class RACER_API ARacerCheckpointVolume : public ATriggerVolume
{
	GENERATED_BODY()

public:
	ARacerCheckpointVolume();
	virtual void BeginPlay() override;
	
	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);
	    

	UPROPERTY(BlueprintAssignable, Category = "Racer")
		FActorReachedFinishLine OnActorReachedFinishLine;

	UFUNCTION(BlueprintPure)
		bool GetIsFinishLine() const { return IsFinishLine; }

protected:
	UPROPERTY(EditAnywhere)
		bool IsFinishLine = false;
	
};
