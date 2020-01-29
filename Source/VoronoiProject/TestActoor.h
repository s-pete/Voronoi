// Just making sure I can do stuff, we can delete this if it looks messy

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TestActoor.generated.h"

UCLASS()
class VORONOIPROJECT_API ATestActoor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATestActoor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
