// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BasePawn.h"
#include "Tank.generated.h"

/**
 * 
 */
UCLASS()
class TOONTANKS_API ATank : public ABasePawn
{
	GENERATED_BODY()
	public:
		ATank();

			// Called every frame
		virtual void Tick(float DeltaTime) override;

		// Called to bind functionality to input
		virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	protected:
		virtual void BeginPlay() override;

	private:
		UPROPERTY(VisibleAnywhere, Category="Components")
		class USpringArmComponent* SpringArm;


		UPROPERTY(VisibleAnywhere, Category="Components")
		class UCameraComponent* CameraComp;

		UPROPERTY(EditAnywhere,Category="Movement")
		float Speed = 200.f;
		UPROPERTY(EditAnywhere,Category="Rotation")
		float TurnRate = 45.f;

		void Move(float Value);
		void Turn(float Value);

		APlayerController* PLayerControllerRef;
};
