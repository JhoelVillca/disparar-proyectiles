// Copyright Epic Games, Inc. All Rights Reserved.

#include "DisparoGameMode.h"
#include "DisparoCharacter.h"
#include "UObject/ConstructorHelpers.h"

ADisparoGameMode::ADisparoGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/SideScrollerCPP/Blueprints/SideScrollerCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
