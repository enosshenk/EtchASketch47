// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine/CanvasRenderTarget2D.h"
#include "EASCanvasRenderTarget2D.generated.h"

/**
 * 
 */
UCLASS()
class ETCHASKETCH_API UEASCanvasRenderTarget2D : public UCanvasRenderTarget2D
{
	GENERATED_BODY()

	UEASCanvasRenderTarget2D(const FObjectInitializer& ObjectInitializer);

	virtual void UpdateResource() override;

	UFUNCTION(BlueprintCallable, Category = "EAS Canvas Render Target 2D", meta = (HidePin = "WorldContextObject", DefaultToSelf = "WorldContextObject"))
	static UCanvasRenderTarget2D* EASCreateCanvasRenderTarget2D(UObject* WorldContextObject, TSubclassOf<UCanvasRenderTarget2D> CanvasRenderTarget2DClass, int32 Width = 1024, int32 Height = 1024);
};
