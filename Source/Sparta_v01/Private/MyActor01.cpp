// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor01.h"

// Sets default values
AMyActor01::AMyActor01()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor01::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor01::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

