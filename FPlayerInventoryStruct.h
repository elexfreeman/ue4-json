#pragma once


#include "CoreMinimal.h"

#include "FPlayerInventoryStruct.generated.h"

USTRUCT(BlueprintType)
struct FPlayerInventoryStruct
{
    GENERATED_BODY()

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	int32 id = 0; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	FString name = ""; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AA")
	int32 count = 0; 



};