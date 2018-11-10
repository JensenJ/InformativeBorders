// Copyright Jensen Bradley 2018.

#include "IBGameMode.h"
#include "UObject/ConstructorHelpers.h"

AIBGameMode::AIBGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/BP_IBCharacterPlayer"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
