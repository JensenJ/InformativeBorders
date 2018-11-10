// Copyright Jensen Bradley 2018.

#include "IBCharacterAI.h"
#include "Perception/PawnSensingComponent.h"

// Sets default values
AIBCharacterAI::AIBCharacterAI()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PawnSensing = CreateDefaultSubobject<UPawnSensingComponent>(TEXT("PawnSensing"));
	//PawnSensing->SetPeripheralVisionAngle(70.0f);
	//PawnSensing->SetSensingInterval(0.1f);
}

// Called when the game starts or when spawned
void AIBCharacterAI::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AIBCharacterAI::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AIBCharacterAI::SetRole(FString newRole) {
	characterRole = newRole;
}

FString AIBCharacterAI::GetRole() {
	return characterRole;
}