// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ProjectCoffee.h"
#include "ProjectCoffeeCharacter.generated.h"

UCLASS(config=Game)
class AProjectCoffeeCharacter : public ACharacter
{
	GENERATED_BODY()

public:

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	class UCameraComponent* FollowCamera;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Base Character")
		float MaxHealth = 100;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Base Character")
		float Health = 100;

	UPROPERTY(BlueprintReadWrite, EditAnyWhere, Category = "Base Character")
		float CurrentHealth = Health/MaxHealth;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Base Character")
		bool isDead = false;

	virtual void CalculateDead();

	UFUNCTION(BlueprintCallable, Category = "Base Character")
		virtual void CalculateHealth(float delta);

#if WITH_EDITOR
	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
		override;
#endif // WITH_EDITOR


	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	//float MaxHealth;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Health")
	//float CrntHealth;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	//float MaxStamina;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	//float CrntStamina;

	//UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stamina")
	//UCurveFloat *StaminaCurve;

	//UPROPERTY(EditAnywhere, Category = "Health")
	//FTimeline myTimeLine;

	//UPROPERTY(EditAnywhere, Category = "Stamina")
	//FTimerHandle MemberTimerHandle;

	//UPROPERTY(EditAnywhere, Category = "Stamina")
	//FTimerHandle StaminaTimerHandle;

	//float CurveFloatValue;
	//float TimelineValue;
	//bool bCanUseStamina;

	//UFUNCTION(BlueprintPure, Category = "Health")
	//float GetHealth();

	//UFUNCTION(BlueprintPure, Category = "Health")
	//FText GetHealthText();

	//UFUNCTION(BlueprintPure, Category = "Stamina")
	//float GetStamina();

	//UFUNCTION(BlueprintPure, Category = "Stamina")
	//FText GetStaminaText();

	//UFUNCTION()
	//void DamageTimer();

	//UFUNCTION()
	//void SetDamageState();

	//UFUNCTION()
	//void SetDamageValue();

	//UFUNCTION()
	//void SetStaminaState();

	//UFUNCTION()
	//void SetStaminaChange(float StaminaValue);

	//UFUNCTION()
	//void UpdateStamina();

	//UFUNCTION(BlueprintPure, Category = "Health")
	//bool PlayFlash();

	//UFUNCTION()
	//void RecievePointDamage(float Damage, const UDamageType* DamageType, FVector HitLocation,
	//	FVector HitNormal, UPrimitiveComponent* HitComponent, FName BoneName, FVector ShotFromDirection,
	//	AController* InstigatedBy, AActor* DamageCauser, const FHitResult& HitInfo);

	//UFUNCTION(BlueprintCallable, Category = "Health")
	//void UpdateHealth(float HealthChange);

public:
	AProjectCoffeeCharacter();

	/** Base turn rate, in deg/sec. Other scaling may affect final turn rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseTurnRate;

	/** Base look up/down rate, in deg/sec. Other scaling may affect final rate. */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category=Camera)
	float BaseLookUpRate;

protected:

	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	/** Called for forwards/backward input */
	void MoveForward(float Value);

	/** Called for side to side input */
	void MoveRight(float Value);


protected:
	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	// End of APawn interface

public:
	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }
	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }
};

