// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Esfera.h" // Mueve esta línea aquí
#include "DisparoCharacter.generated.h"

UCLASS(config=Game)
class ADisparoCharacter : public ACharacter
{
	GENERATED_BODY()

	/** Side view camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* SideViewCameraComponent;

	/** Camera boom positioning the camera beside the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

protected:

	/** Called for side to side input */
	void MoveRight(float Val);

	/** Handle touch inputs. */
	void TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Handle touch stop event. */
	void TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Spawn Esfera function */
	void SpawnEsfera();

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* InputComponent) override;
	// End of APawn interface


public:
	ADisparoCharacter();

	/** Returns SideViewCameraComponent subobject **/
	FORCEINLINE class UCameraComponent* GetSideViewCameraComponent() const { return SideViewCameraComponent; }
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	TSubclassOf<AEsfera> EsferaClass;

	// Añade esta función
	void InitializeEsferaClass();
};
