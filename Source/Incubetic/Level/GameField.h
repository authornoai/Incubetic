// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProceduralMeshComponent.h"
#include "GameFramework/Actor.h"
#include "GameField.generated.h"

USTRUCT()
struct FGameFieldElement
{
	GENERATED_USTRUCT_BODY()
	TArray<FVector> vertices;
	TArray<int32> triangles;

};

UENUM()
enum class ELevelType : uint8
{
	LT_Default UMETA(DisplayedName = "Basic Level"),
	LT_HardLevel UMETA(DisplayedName = "Hard Level" ),
	LT_BonusLevel UMETA(DisplayedName = "Bonus Level")
};

UENUM()
enum class EElementType : uint8
{
	ET_Platform UMETA(DisplayedName = "Plate"),
	ET_Box UMETA(DisplayedName = "Box"),
	ET_Triangle UMETA(DisplayedName = "Triangle")
};

UCLASS()
class INCUBETIC_API AGameField : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGameField();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void GenerateLevel(uint8 LevelType);
	void GenerateElement(uint8 ElementType, FVector ElementTypePosition, FVector ElementTypeSize);

	UPROPERTY(VisibleAnywhere, Category = Materials)
	UProceduralMeshComponent* Level;

	TArray<FGameFieldElement> LevelStructure;
	
};
