// Fill out your copyright notice in the Description page of Project Settings.


#include "VoronoiBlueprints.h"
#include "Engine/Classes/GameFramework/Actor.h"

FVector UVoronoiBlueprints::MinPositionBound(TArray<AActor*> actors)
{
	float minX = MAX_FLT, minY = MAX_FLT;

	for (AActor* actor : actors) {
		minX = FMath::Min(minX,actor->GetActorLocation().X);
		minY = FMath::Min(minY, actor->GetActorLocation().Y);
	}

	return FVector{ minX - 100, minY - 100, 0 };
}

FVector UVoronoiBlueprints::MaxPositionBound(TArray<AActor*> actors)
{
	float maxX = -MAX_FLT, maxY = -MAX_FLT;

	for (AActor* actor : actors) {
		maxX = FMath::Max(maxX, actor->GetActorLocation().X);
		maxY = FMath::Max(maxY, actor->GetActorLocation().Y);
	}

	return FVector{ maxX + 100, maxY + 100, 0 };
}
