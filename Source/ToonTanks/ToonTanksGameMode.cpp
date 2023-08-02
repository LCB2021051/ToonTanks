// Fill out your copyright notice in the Description page of Project Settings.


#include "ToonTanksGameMode.h"
#include "kismet/GameplayStatics.h"
#include "Tank.h"
#include "Tower.h"
#include "ToonTankPlayerController.h"

void AToonTanksGameMode::ActorDied(AActor* DeadActor){
    if(DeadActor == Tank){
        Tank->HandleDestruction();

        if(ToonTankPlayerController){
            ToonTankPlayerController->SetPlayerEnabledState(false);
        }
    }
    else if(ATower* DestroyedTower = Cast<ATower>(DeadActor)){
        DestroyedTower->HandleDestruction();
    }
}

void AToonTanksGameMode::BeginPlay(){
    Super::BeginPlay();

    HandleGameStart();
}

void AToonTanksGameMode::HandleGameStart(){

    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
    ToonTankPlayerController = Cast<AToonTankPlayerController>(UGameplayStatics::GetPlayerController(this,0));

    if(ToonTankPlayerController){
        ToonTankPlayerController->SetPlayerEnabledState(false);
        FTimerHandle PlayerEnableTimerHandle;
        FTimerDelegate PLayerEnableTimerDelegate = FTimerDelegate::CreateUObject(
            ToonTankPlayerController,
            &AToonTankPlayerController::SetPlayerEnabledState,
            true
        );
        GetWorldTimerManager().SetTimer(
            PlayerEnableTimerHandle,
            PLayerEnableTimerDelegate,
            StartDelay,
            false
        );
    }
}
