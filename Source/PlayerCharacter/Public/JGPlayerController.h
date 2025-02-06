#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "JGPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

UCLASS()
class PLAYERCHARACTER_API AJGPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AJGPlayerController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputMappingContext* InputMappingContext;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* MoveAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* JumpAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* LookAction;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Input")
	UInputAction* SprintAction;

	virtual void BeginPlay() override;
	
};
