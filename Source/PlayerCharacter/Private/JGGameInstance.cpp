#include "JGGameInstance.h"

UJGGameInstance::UJGGameInstance()
{
	TotalScore = 0;
	CurrentLevelIndex = 0;
}

void UJGGameInstance::AddToScore(int32 Amount)
{
	TotalScore += Amount;
	UE_LOG(LogTemp, Warning, TEXT("Total Score Updated: %d"), TotalScore);
}

