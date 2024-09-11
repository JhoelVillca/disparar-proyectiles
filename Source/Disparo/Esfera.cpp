// Fill out your copyright notice in the Description page of Project Settings.


#include "Esfera.h"
#include "UObject/ConstructorHelpers.h"
#include "Materials/Material.h"

// Sets default values
AEsfera::AEsfera()
{
	PrimaryActorTick.bCanEverTick = true;

	EsferaMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EsferaMesh"));
	RootComponent = EsferaMesh;

	static ConstructorHelpers::FObjectFinder<UStaticMesh> EsferaMeshAsset(TEXT("StaticMesh'/Game/StarterContent/Shapes/Shape_Sphere.Shape_Sphere'"));
	if (EsferaMeshAsset.Succeeded())
	{
		EsferaMesh->SetStaticMesh(EsferaMeshAsset.Object);
		EsferaMesh->SetWorldScale3D(FVector(0.5f)); // Ajusta el tamaño según sea necesario
		EsferaMesh->SetMaterial(0, LoadObject<UMaterial>(nullptr, TEXT("Material'/Game/StarterContent/Materials/M_Metal_Gold.M_Metal_Gold'")));
	}

	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileMovement"));
	ProjectileMovement->UpdatedComponent = EsferaMesh;
	ProjectileMovement->InitialSpeed = 100.f; // Velocidad inicial lenta
	ProjectileMovement->MaxSpeed = 100.f; // Velocidad máxima
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;
	ProjectileMovement->Bounciness = 0.3f;
	ProjectileMovement->ProjectileGravityScale = 0.0f; // Sin gravedad
}

void AEsfera::Initialize(const FVector& Direction)
{
	ProjectileMovement->Velocity = Direction * ProjectileMovement->InitialSpeed;
}

// Called when the game starts or when spawned
void AEsfera::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AEsfera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

