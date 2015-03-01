// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "RenderCore.h"
#include "RenderUtils.h"
#include "TheEtchASketch.generated.h"

/**
 * 
 */
UCLASS()
class ETCHASKETCH_API ATheEtchASketch : public AActor
{
	GENERATED_UCLASS_BODY()

public:
	UFUNCTION()
	virtual void OnRecieveUpdate(class UCanvas* Canvas, int32 Width, int32 Height);

	UFUNCTION()
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = EAS)
	virtual void EtchASketchDraw(FVector2D Loc);

	UPROPERTY(BlueprintReadWrite, Category = EAS)
	class UTexture2D* DrawTexture;

	UPROPERTY(BlueprintReadWrite, Category = EAS)
	class UTexture2D* ClearTexture;

	UPROPERTY(BlueprintReadWrite, Category = EAS)
	class UMaterialInstanceDynamic* MaterialInstance;

private:
	bool Drawing;

	FVector2D DrawLoc;

	class UCanvasRenderTarget2D* CanvasTarget;
	
};
