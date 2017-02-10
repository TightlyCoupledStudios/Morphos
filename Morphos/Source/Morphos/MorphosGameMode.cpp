// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.

#include "Morphos.h"
#include "MorphosGameMode.h"
#include "MorphosCharacter.h"

AMorphosGameMode::AMorphosGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
