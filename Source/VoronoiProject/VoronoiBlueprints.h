// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "VoronoiBlueprints.generated.h"

/**
 * 
 */
UCLASS()
class VORONOIPROJECT_API UVoronoiBlueprints : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

	UFUNCTION(BlueprintPure, meta = (DisplayName = "Min Position Bounds", CompactNodeTitle = "MinBounds", Keywords = "Min Position Bounds"), Category = Game)
	static FVector MinPositionBound(TArray<AActor*> actors);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Max Position Bounds", CompactNodeTitle = "MaxBounds", Keywords = "Max Position Bounds"), Category = Game)
	static FVector MaxPositionBound(TArray<AActor*> actors);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Snap To Closest", CompactNodeTitle = "SnapToClosest", Keywords = "Snap to Closest"), Category = Game)
	static int SnapToClosest(TArray<FVector> actors, TArray<FVector> offsets, int actorIdx, float snapDistance);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Snap Lerp Value", CompactNodeTitle = "SnapLerpValue", Keywords = "Snap Lerp Value"), Category = Game)
	static float SnapLerpValue(FVector v1, FVector v2, float snapClose, float damping);
	UFUNCTION(BlueprintPure, meta = (DisplayName = "Get Line Thickness", CompactNodeTitle = "GetLineThickness", Keywords = "Get Line Thickness"), Category = Game)
	static float GetLineThickness(FVector v1, FVector v2, float snapClose, float snapDistance);
};
