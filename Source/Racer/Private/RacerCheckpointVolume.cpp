// Fill out your copyright notice in the Description page of Project Settings.


#include "RacerCheckpointVolume.h"
#include "RacerCharacter.h"


ARacerCheckpointVolume::ARacerCheckpointVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &ARacerCheckpointVolume::OnOverlapBegin);
}

void ARacerCheckpointVolume::BeginPlay()
{
	
}


void ARacerCheckpointVolume::OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor)
{
w	if (ARacerCharacter* RacerCharacter = Cast<ARacerCharacter>(OtherActor))
	{
	
		{
			if (IsFinishLine)
			{
				OnActorReachedFinishLine.Broadcast(RacerCharacter);
			}
			else
			{
				//We are going to update the checkpoint on the player
				RacerCharacter->SetLastCheckpointPosition(OverlappedActor->GetActorLocation());
				
			}
		}
	}

}