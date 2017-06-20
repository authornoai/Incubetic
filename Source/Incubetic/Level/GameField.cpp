// Fill out your copyright notice in the Description page of Project Settings.

#include "Incubetic.h"
#include "GameField.h"


// Sets default values
AGameField::AGameField()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Level = CreateDefaultSubobject<UProceduralMeshComponent>(TEXT("Level"));
	RootComponent = Level;
	

}

// Called when the game starts or when spawned
void AGameField::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameField::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AGameField::GenerateLevel(uint8 LevelType)
{
}

void AGameField::GenerateElement(uint8 ElementType, FVector ElementTypePosition, FVector ElementTypeSize)
{
	switch (ElementType)
	{
	case EElementType::ET_Platform:
		{
		FGameFieldElement* element = new FGameFieldElement();

		FVector* xVect = new FVector(ElementTypePosition.X + ElementTypeSize.X, 0, 0);
		FVector* yVect = new FVector(0, ElementTypePosition.Y + ElementTypeSize.Y, 0);
		FVector* zVect = new FVector(0, 0, ElementTypePosition.Z + ElementTypeSize.Z);

		element->vertices.Add(*xVect);
		element->vertices.Add(*yVect);
		element->vertices.Add(*zVect);

		element->triangles.Add(0);
		element->triangles.Add(1);
		element->triangles.Add(2);

		Level->CreateMeshSection(1, element->vertices, element->triangles, nullptr , nullptr, nullptr, nullptr, false);

		return;
		}
	}
}

