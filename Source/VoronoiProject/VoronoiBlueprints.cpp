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

int UVoronoiBlueprints::SnapToClosest(TArray<FVector> actors, TArray<FVector> offsets, int actorIdx, float snapDistance)
{
	for (int i = 0; i < actorIdx; ++i) {
		float dist = FVector::Dist(actors[i], actors[actorIdx]);
		if (dist < snapDistance) {
			return i;
		}
	}

	return actorIdx;
}

float UVoronoiBlueprints::SnapLerpValue(FVector v1, FVector v2, float snapClose, float snapDistance)
{
	float distance = FVector::Distance(v1, v2);

	//float g = FMath::Max(FMath::Abs(distance) - snapClose, 0.0f) * FMath::Sign(distance);
	//float lerpValue = 1 - ((2 * FMath::Atan(g / damping)) / PI);

	float lerpValue = FMath::Max(distance - snapClose, 0.0f) / (snapDistance - snapClose);

	return 1 - lerpValue;
}

float UVoronoiBlueprints::GetLineThickness(FVector v1, FVector v2, float snapClose, float damping)
{
	float distance = FVector::Distance(v1, v2);
	if (distance < snapClose) {
		return 0;
	}

	float thickness = 1 - (1 / ((distance - snapClose / damping) + 1));

	return thickness;
}
