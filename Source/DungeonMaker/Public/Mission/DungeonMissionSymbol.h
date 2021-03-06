// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GraphNode.h"

#include "Grammar/GrammarAlphabet.h"
#include "RoomReplacementPattern.h"

#include "DungeonMissionSymbol.generated.h"

class ADungeonRoom;

USTRUCT(BlueprintType)
struct DUNGEONMAKER_API FMissionSpaceData
{
	GENERATED_BODY()
public:
	FMissionSpaceData()
	{
		WallSize = 3;
		CeilingHeight = 1;
	}

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "3"))
	int32 WallSize;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (ClampMin = "1"))
	int32 CeilingHeight;
};

/**
 * 
 */
UCLASS(BlueprintType)
class DUNGEONMAKER_API UDungeonMissionSymbol : public UGraphNode
{
	GENERATED_BODY()
public:
	// This is the type of room associated with this symbol.
	// Only used if this is a terminal symbol.
	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	TArray<TSubclassOf<ADungeonRoom>> RoomTypes;

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	bool bAllowedToHaveChildren;

	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TMap<class UGraphNode*, float> SymbolSkipChances;

public:
	UDungeonMissionSymbol();

public:
	TSubclassOf<ADungeonRoom> GetRoomType(FRandomStream& Rng) const;
};
