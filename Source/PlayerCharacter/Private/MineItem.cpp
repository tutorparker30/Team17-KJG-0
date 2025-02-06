#include "MineItem.h"

AMineItem::AMineItem()
{
	ExplosionDelay = 5.0;
	ExplosionRadius = 300.0f;
	ExplosionDamage = 30.0;
	
	ItemType = "Mine";
}

void AMineItem::ActivateItem(AActor* Activator)
{
	DestroyItem();
}

