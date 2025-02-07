#include "JGGameMode.h"
#include "JGCharacter.h"
#include "JGPlayerController.h"
#include "JGGameState.h"

AJGGameMode::AJGGameMode()
{
	DefaultPawnClass = AJGCharacter::StaticClass();
	PlayerControllerClass = AJGPlayerController::StaticClass();
	GameStateClass = AJGGameState::StaticClass();
}
