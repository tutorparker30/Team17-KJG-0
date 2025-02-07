#include "CoinItem.h"
#include "Engine/World.h"
#include "JGGameState.h"

ACoinItem::ACoinItem()
{
	PointValue = 0;
	ItemType = "DefalutCoin";
}

void ACoinItem::ActivateItem(AActor* Activator)
{
	if (Activator && Activator->ActorHasTag("Player"))
	{
		if (UWorld* World = GetWorld())
		{
			if (AJGGameState* GameState = World->GetGameState<AJGGameState>())
			{
				GameState->AddScore(PointValue);
				GameState->OnCoinCollected();
			}
		}
		DestroyItem();
	}
}
