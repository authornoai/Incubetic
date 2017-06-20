// Fill out your copyright notice in the Description page of Project Settings.

#include "Incubetic.h"
#include "PlayerClass.h"


// Sets default values
APlayerClass::APlayerClass()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scene"));
	PlayerCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	PlayerHandLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Left Hand"));
	PlayerHandRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Right Hand"));

	PlayerCamera->SetupAttachment(RootComponent);
	PlayerHandLeft->SetupAttachment(RootComponent);
	PlayerHandRight->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APlayerClass::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APlayerClass::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APlayerClass::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

