// Copyright Jensen Bradley 2018.

#include "IBCharacterPlayer.h"

#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

AIBCharacterPlayer::AIBCharacterPlayer()
{
	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.0f, 96.0f);

	// Don't rotate when the controller rotates.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Create a camera boom attached to the root (capsule)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->bAbsoluteRotation = true; // Rotation of the character should not affect rotation of boom
	CameraBoom->bDoCollisionTest = false;
	CameraBoom->TargetArmLength = 750.f;
	CameraBoom->SocketOffset = FVector(0.0f, 0.0f, 75.0f);
	CameraBoom->RelativeRotation = FRotator(0.0f, 180.0f, 0.0f);

	// Create a camera and attach to boom
	SideViewCameraComponent = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	SideViewCameraComponent->SetupAttachment(CameraBoom, USpringArmComponent::SocketName);
	SideViewCameraComponent->bUsePawnControlRotation = false; // We don't want the controller rotating the camera

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AIBCharacterPlayer::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	// set up gameplay key bindings
	//PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	//PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);
	PlayerInputComponent->BindAxis("MoveRight", this, &AIBCharacterPlayer::MoveRight);
	PlayerInputComponent->BindAxis("MoveForward", this, &AIBCharacterPlayer::MoveForward);

	PlayerInputComponent->BindTouch(IE_Pressed, this, &AIBCharacterPlayer::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AIBCharacterPlayer::TouchStopped);
}

void AIBCharacterPlayer::MoveRight(float Value)
{
	// add movement in that direction
	AddMovementInput(FVector(0.0f, -1.0f, 0.0f), Value);
}

void AIBCharacterPlayer::MoveForward(float Value) {
	AddMovementInput(FVector(-1.0f, 0.0f, 0.0f), Value);
}

void AIBCharacterPlayer::TouchStarted(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	// jump on any touch
	//Jump();
}

void AIBCharacterPlayer::TouchStopped(const ETouchIndex::Type FingerIndex, const FVector Location)
{
	//StopJumping();
}