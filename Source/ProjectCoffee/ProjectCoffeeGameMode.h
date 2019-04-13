// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/GameModeBase.h"
#include "ProjectCoffeeGameMode.generated.h"

UCLASS(minimalapi)
class AProjectCoffeeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AProjectCoffeeGameMode();
	UFUNCTION(BlueprintCallable, Category = "UMG Game")
	void ChangeMenuWidget(TSubclassOf<UUserWidget> NewWidgetClass);

protected:
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "UMG Game")
	TSubclassOf<UUserWidget> StartingWidgetClass; 

	UPROPERTY()
		UUserWidget* CurrentWidget;
};



