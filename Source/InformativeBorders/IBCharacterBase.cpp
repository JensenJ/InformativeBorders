// Copyright Jensen Bradley 2018.

#include "IBCharacterBase.h"
#include "Engine.h"
#include "Components/CapsuleComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AIBCharacterBase::AIBCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Face in the direction we are moving..
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->GravityScale = 2.f;
	GetCharacterMovement()->AirControl = 0.80f;
	GetCharacterMovement()->JumpZVelocity = 1000.f;
	GetCharacterMovement()->GroundFriction = 3.f;
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
	GetCharacterMovement()->MaxFlySpeed = 600.f;
}

// Called when the game starts or when spawned
void AIBCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AIBCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//GEngine->AddOnScreenDebugMessage(-1, 3.0f, FColor::Red, FString::Printf(TEXT("%f"), ComponentAttributes->health));
}

void AIBCharacterBase::SetHealth(int32 newHealth) {
	health = newHealth;
}

int32 AIBCharacterBase::GetHealth() {
	return health;
}

void AIBCharacterBase::SetStamina(int32 newStamina) {
	stamina = newStamina;
}

int32 AIBCharacterBase::GetStamina() {
	return stamina;
}