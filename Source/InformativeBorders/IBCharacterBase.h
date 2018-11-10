// Copyright Jensen Bradley 2018.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "IBCharacterBase.generated.h"

UCLASS()
class INFORMATIVEBORDERS_API AIBCharacterBase : public ACharacter
{
	GENERATED_BODY()

private:
	UPROPERTY(VisibleAnywhere, Category = "Attributes")
	int32 health = 100;
	UPROPERTY(VisibleAnywhere, Category = "Attributes")
	int32 stamina = 100;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Sets default values for this character's properties
	AIBCharacterBase();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetHealth(int32 newHealth);
	UFUNCTION(BlueprintPure, Category = "Attributes")
	int32 GetHealth();

	UFUNCTION(BlueprintCallable, Category = "Attributes")
	void SetStamina(int32 newStamina);
	UFUNCTION(BlueprintPure, Category = "Attributes")
	int32 GetStamina();
};
