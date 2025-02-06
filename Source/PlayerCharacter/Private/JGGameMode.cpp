#include "JGGameMode.h"
#include "JGCharacter.h"
#include "JGPlayerController.h"

AJGGameMode::AJGGameMode()
{
	DefaultPawnClass = AJGCharacter::StaticClass();
	PlayerControllerClass = AJGPlayerController::StaticClass();
}
