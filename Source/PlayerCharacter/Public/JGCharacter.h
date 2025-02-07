#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "JGCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
struct FInputActionValue;

UCLASS()
class PLAYERCHARACTER_API AJGCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	AJGCharacter();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	USpringArmComponent* SpringArmComp;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Camera")
	UCameraComponent* CameraComp;

	UFUNCTION(BlueprintPure, Category = "Health")
	float GetHealth() const;
	UFUNCTION(BlueprintCallable, Category = "Health")
	void AddHealth(float Amount);

protected:

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "health")
	float MaxHealth;

	UPROPERTY(EditAnyWhere, BlueprintReadWrite, Category = "health")
	float Health;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	virtual float TakeDamage(
		float DamageAmount,
		struct FDamageEvent const& DamageEvent,
		AController* EventInstigator,
		AActor* DamageCauser) override;

	UFUNCTION()
	void Move(const FInputActionValue& value);
	
	UFUNCTION()
	void StartJump(const FInputActionValue& value);
	
	UFUNCTION()
	void StopJump(const FInputActionValue& value);
	
	UFUNCTION()
	void Look(const FInputActionValue& value);
	
	UFUNCTION()
	void StartSprint(const FInputActionValue& value);
	
	UFUNCTION()
	void StopSprint(const FInputActionValue& value);

	void OnDeath();

private:

	float NormalSpeed;
	float SprintSpeedMultiplier;
	float SprintSpeed;

};
