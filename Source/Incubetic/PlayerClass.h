// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Pawn.h"
#include "PlayerClass.generated.h"

UCLASS()
class INCUBETIC_API APlayerClass : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APlayerClass();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	
	//Camera
	UPROPERTY(EditAnywhere)
	UCameraComponent* PlayerCamera;

	//Hands
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PlayerHandLeft;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* PlayerHandRight;
};
