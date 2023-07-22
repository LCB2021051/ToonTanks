// Fill out your copyright notice in the Description page of Project Settings.


#include "Tank.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Kismet/GameplayStatics.h"

ATank::ATank(){
	PrimaryActorTick.bCanEverTick = true;

    SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("Spring Arm"));
    SpringArm->SetupAttachment(RootComponent);

    CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera Component"));
    CameraComp->SetupAttachment(SpringArm);
}

// Called to bind functionality to input
void ATank::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ATank::Move);
    PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ATank::Turn);
}

void ATank::Move(float Value){
    // UE_LOG(LogTemp, Warning, TEXT("Value : %f"),Value);

    FVector DeltaLocation = FVector::ZeroVector;
    //x = value * DeltaTime * Speed;

    float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);

    DeltaLocation.X = Value * DeltaTime * Speed;
    AddActorLocalOffset(DeltaLocation,true);
}

void ATank::Turn(float Value){

    FRotator DeltaRotation = FRotator::ZeroRotator;
    //x = value * DeltaTime * Speed;

    float DeltaTime = UGameplayStatics::GetWorldDeltaSeconds(this);
    //Yaw rotation around z axis
    DeltaRotation.Yaw = Value * DeltaTime * TurnRate;
    AddActorLocalRotation(DeltaRotation,true);
}
