// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"
#include "TimerManager.h"
#include "GameFramework/Actor.h"

void ATower::Tick(float DeltaTime){
    Super::Tick(DeltaTime);

    if(InFireRange()){
        // if in range then rotate tower turret
        RotateTurret(Tank->GetActorLocation());
        //set timer
        
    }
}

void ATower::HandleDestruction(){
    Super::HandleDestruction();
    Destroy();
}


void ATower::BeginPlay(){
    Super::BeginPlay();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));

    GetWorldTimerManager().SetTimer(
        FireRateTimerHandle,
        this,
        &ATower::CheckFireCondition,
        FireRate,
        true);
}

void ATower::CheckFireCondition(){
    if(InFireRange())
        Fire();
}

bool ATower::InFireRange(){
    if(Tank){
        float distance = FVector::Dist(GetActorLocation(),Tank->GetActorLocation());
            if(distance<=FireRange) 
                return true;
    }
    return false;
}