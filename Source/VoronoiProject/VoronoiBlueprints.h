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
	
};
