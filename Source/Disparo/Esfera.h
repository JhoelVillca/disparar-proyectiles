// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Esfera.generated.h"

UCLASS()
class DISPARO_API AEsfera : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AEsfera();

	// Mesh component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Mesh")
	UStaticMeshComponent* EsferaMesh;

	// Movement component
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Movement")
	UProjectileMovementComponent* ProjectileMovement;

	void Initialize(const FVector& Direction);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
