// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FPlayerStruct.h"

#include "Runtime/JsonUtilities/Public/JsonObjectConverter.h"


#include "JsonTest.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWN1_API UJsonTest : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UJsonTest();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	FPlayerStruct playerStruct;

	UFUNCTION(BlueprintCallable, Category = "AA")
	void fLoadJson();
		
	UFUNCTION(BlueprintCallable, Category = "AA")
	FString fPlayerStructToString(FPlayerStruct playerStruct);
		
};
