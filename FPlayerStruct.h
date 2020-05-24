#pragma once


#include "CoreMinimal.h"
#include "FPlayerInventoryStruct.h"

#include "FPlayerStruct.generated.h"

USTRUCT(BlueprintType)
struct FPlayerStruct
{
    GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA", meta = (ToolTip = "Имя"))
	FString name = ""; // Имя

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA", meta = (ToolTip = "Жизни"))
	int32 HP = 15; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA", meta = (ToolTip = "Мана"))
	int32 MP = 15; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA", meta = (ToolTip = "Сила атаки"))
	float AP = 10.0f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA", meta = (ToolTip = "Инвентарь"))
	TArray<FPlayerInventoryStruct> aInventory;

};