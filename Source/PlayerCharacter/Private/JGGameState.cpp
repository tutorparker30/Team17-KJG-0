#include "JGGameState.h"
#include "Kismet/GameplayStatics.h"
#include "SpawnVolume.h"
#include "JGGameInstance.h"
#include "CoinItem.h"

AJGGameState::AJGGameState()
{
	Score = 0;
	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;
	LevelDuration = 30.0f;
	CurrentLevelIndex = 0;
	MaxLevels = 3;
}

void AJGGameState::BeginPlay()
{
	Super::BeginPlay();

	StartLevel();
}

int32 AJGGameState::GetScore() const
{
	return Score;
}

void AJGGameState::AddScore(int32 Amount)
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UJGGameInstance* JGGameInstance = Cast<UJGGameInstance>(GameInstance);
		if (JGGameInstance)
		{
			JGGameInstance->AddToScore(Amount);
		}
	}
}

void AJGGameState::StartLevel()
{
	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UJGGameInstance* JGGameInstance = Cast<UJGGameInstance>(GameInstance);
		if (JGGameInstance)
		{
			CurrentLevelIndex = JGGameInstance->CurrentLevelIndex;
		}
	}

	SpawnedCoinCount = 0;
	CollectedCoinCount = 0;

	TArray<AActor*> FoundVolumes;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ASpawnVolume::StaticClass(), FoundVolumes);

	const int32 ItemToSpawn = 40;

	for (int32 i = 0; i < ItemToSpawn; i++)
	{
		if (FoundVolumes.Num() > 0)
		{
			ASpawnVolume* SpawnVolume = Cast<ASpawnVolume>(FoundVolumes[0]);
			if (SpawnVolume)
			{
				AActor* SpawnedActor = SpawnVolume->SpawnRandomItem();
				if (SpawnedActor && SpawnedActor->IsA(ACoinItem::StaticClass()))
				{
					SpawnedCoinCount++;
				}
			}
		}
	}

	GetWorldTimerManager().SetTimer(
		LevelTimerHandle,
		this,
		&AJGGameState::OnLevelTimeUp,
		LevelDuration,
		false
	);

	UE_LOG(LogTemp, Warning, TEXT("Level &d Start!, Spawned %d coin"),
		CurrentLevelIndex + 1,
		SpawnedCoinCount);

}

void AJGGameState::OnLevelTimeUp()
{
	EndLevel();
}

void AJGGameState::OnCoinCollected()
{
	CollectedCoinCount++;
	UE_LOG(LogTemp, Warning, TEXT("Coin Collected: %d / %d"),
		CollectedCoinCount,
		SpawnedCoinCount)

		if (SpawnedCoinCount > 0 && CollectedCoinCount >= SpawnedCoinCount)
		{
			EndLevel();
		}
}

void AJGGameState::EndLevel()
{
	GetWorldTimerManager().ClearTimer(LevelTimerHandle);
	CurrentLevelIndex++;

	if (UGameInstance* GameInstance = GetGameInstance())
	{
		UJGGameInstance* JGGameInstance = Cast<UJGGameInstance>(GameInstance);
		if (JGGameInstance)
		{
			AddScore(Score);
			CurrentLevelIndex++;
			JGGameInstance->CurrentLevelIndex = CurrentLevelIndex;
		}
	}

	if (CurrentLevelIndex >= MaxLevels)
	{
		OnGameOver();
		return;
	}

	if (LevelMapNames.IsValidIndex(CurrentLevelIndex))
	{
		UGameplayStatics::OpenLevel(GetWorld(), LevelMapNames[CurrentLevelIndex]);
	}
	else
	{
		OnGameOver();
	}
}

void AJGGameState::OnGameOver()
{
	UE_LOG(LogTemp, Warning, TEXT("Game Over!!"));
}