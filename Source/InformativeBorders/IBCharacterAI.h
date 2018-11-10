// Copyright Jensen Bradley 2018.

#pragma once

#include "CoreMinimal.h"
#include "IBCharacterBase.h"
#include "IBCharacterAI.generated.h"

/**
 * 
 */
UCLASS()
class INFORMATIVEBORDERS_API AIBCharacterAI : public AIBCharacterBase
{
	GENERATED_BODY()

	/** Pawn Sensing */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Awareness, meta = (AllowPrivateAccess = "true"))
	class UPawnSensingComponent* PawnSensing;

private:
	UPROPERTY(VisibleAnywhere, Category = "Attributes")
	FString characterRole = "DEFAULT";

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this character's properties
	AIBCharacterAI();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetRole(FString newRole);

	UFUNCTION(BlueprintPure, Category = "Attributes")
	FString GetRole();
};