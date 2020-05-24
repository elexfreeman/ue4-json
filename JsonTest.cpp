// Fill out your copyright notice in the Description page of Project Settings.

#include "JsonTest.h"

// Sets default values for this component's properties
UJsonTest::UJsonTest()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}

// Called when the game starts
void UJsonTest::BeginPlay()
{
	Super::BeginPlay();

	// ...
}

// Called every frame
void UJsonTest::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction *ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UJsonTest::fLoadJson()
{
	/*  */
	bool bOk = true;

	/* имя файла */
	FString jsonFileName = "jsonData.json";

	//FString FullPath = "F:/UE4/TopDown1/Content/";
	/* путь до папки content */
	FString FullPath = FPaths::ProjectContentDir() + jsonFileName;

	/* строка с JSON */
	FString JsonStr;

	/* чекаем существования файла */
	if (!FPlatformFileManager::Get().GetPlatformFile().FileExists(*FullPath))
	{
		bOk = false;
	}

	if (bOk)
	{
		/* загружаем файл */
		FFileHelper::LoadFileToString(JsonStr, *FullPath);

		TSharedRef<TJsonReader<TCHAR>> JsonReader = TJsonReaderFactory<TCHAR>::Create(JsonStr);
		TSharedPtr<FJsonObject> JsonObject = MakeShareable(new FJsonObject);
		FJsonSerializer::Deserialize(JsonReader, JsonObject);

		TSharedPtr<FJsonObject> player = JsonObject->GetObjectField("player");

		/* разбираем поля игрока */
		this->playerStruct.name = player->GetStringField("name");
		this->playerStruct.HP = player->GetIntegerField("HP");
		this->playerStruct.MP = player->GetIntegerField("MP");
		this->playerStruct.AP = player->GetNumberField("AP");

		/* разбираем инвентарь */
		TArray<TSharedPtr<FJsonValue>> aInventory;
		aInventory = player->GetArrayField("inventory");

		FPlayerInventoryStruct item;
		for (int32 i = 0; i < aInventory.Num(); i++)
		{
			item.id = aInventory[i]->AsObject()->GetIntegerField("id");
			item.name = aInventory[i]->AsObject()->GetStringField("Name");
			item.count = aInventory[i]->AsObject()->GetIntegerField("count");

			this->playerStruct.aInventory.Add(item);
		}
	}

	if(!bOk)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Blue, TEXT("Could not Find File"));
	}
}


FString UJsonTest::fPlayerStructToString(FPlayerStruct playerStruct)
{
	FString resp = "";

	resp += "name: " + playerStruct.name + "\r\n";
	resp += "HP: " + FString::FromInt(playerStruct.HP) + "\r\n";
	resp += "MP: " + FString::FromInt(playerStruct.MP) + "\r\n";
	resp += "AP: " + FString::SanitizeFloat(playerStruct.AP) + "\r\n";

	resp += "\r\n";
	resp += "Inventory:" + "\r\n";
	for(int32 int i = 0; i < playerStruct.aInventory.Num(); i++)
	{
		resp += "------" + "\r\n";
		resp +=  FString::FromInt(playerStruct.aInventory[i].id) + "\r\n";
		resp +=  playerStruct.aInventory[i].name + "\r\n";
		resp +=  FString::FromInt(playerStruct.aInventory[i].count) + "\r\n";
	}

	return resp;
}
