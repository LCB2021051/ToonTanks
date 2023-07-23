// Fill out your copyright notice in the Description page of Project Settings.


#include "Tower.h"
#include "Tank.h"
#include "Kismet/GameplayStatics.h"

void ATower::Tick(float DeltaTime){
    Super::Tick(DeltaTime);
    if(Tank){
        // find the distance to the tank 
        float Distance = FVector::Dist(GetActorLocation(),Tank->GetActorLocation());

        //check if the tank is in range 
        if(Distance <= FireRange){
            // if in range then rotate tower turret
            RotateTurret(Tank->GetActorLocation());
        }

    }


}

void ATower::BeginPlay(){
    Super::BeginPlay();
    Tank = Cast<ATank>(UGameplayStatics::GetPlayerPawn(this,0));
}
