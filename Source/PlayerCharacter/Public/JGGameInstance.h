#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "JGGameInstance.generated.h"

UCLASS()
class PLAYERCHARACTER_API UJGGameInstance : public UGameInstance
{
	GENERATED_BODY()

public:
	UJGGameInstance();

	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "GameData")
	int32 TotalScore;
	UPROPERTY(VisibleDefaultsOnly, BlueprintReadWrite, Category = "GameData")
	int32 CurrentLevelIndex;

	UFUNCTION(BlueprintCallable, Category = "GameData")
	void AddToScore(int32 Amount);
	
};
