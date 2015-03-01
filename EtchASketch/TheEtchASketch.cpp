// Fill out your copyright notice in the Description page of Project Settings.

#include "EtchASketch.h"
#include "TheEtchASketch.h"
#include "Engine/CanvasRenderTarget2D.h"
#include "RenderUtils.h"

ATheEtchASketch::ATheEtchASketch(const class FObjectInitializer& PCIP)
: Super(PCIP), DrawTexture(nullptr), ClearTexture(nullptr), MaterialInstance(nullptr), Drawing(false), DrawLoc(FVector2D(0,0))
{
	PrimaryActorTick.bCanEverTick = true;
	PrimaryActorTick.bStartWithTickEnabled = true;
}

void ATheEtchASketch::BeginPlay()
{
	Super::BeginPlay();

	if (CanvasTarget == nullptr)
	{
		CanvasTarget = UCanvasRenderTarget2D::CreateCanvasRenderTarget2D(this, UCanvasRenderTarget2D::StaticClass(), 1024, 1024);

		if (CanvasTarget != nullptr)
		{
			CanvasTarget->OnCanvasRenderTargetUpdate.AddDynamic(this, &ATheEtchASketch::OnRecieveUpdate);
			CanvasTarget->UpdateResource();
		}
	}

	if (MaterialInstance != nullptr)
	{
		MaterialInstance->SetTextureParameterValue(FName("Mask"), CanvasTarget);
	}

}

void ATheEtchASketch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Drawing)
	{
		CanvasTarget->UpdateResource();
		Drawing = false;
	}
}

void ATheEtchASketch::EtchASketchDraw(FVector2D inLoc)
{
	DrawLoc = inLoc;

	Drawing = true;
}


void ATheEtchASketch::OnRecieveUpdate(class UCanvas* Canvas, int32 Width, int32 Height)
{
	if (Canvas != nullptr)
	{
		if (ClearTexture != nullptr)
		{
			FCanvasTileItem ClearTex(FVector2D(0, 0), ClearTexture->Resource, FVector2D(1024, 1024), FVector2D(0, 0), FVector2D(1, 1), FLinearColor(0.0f, 0.0f, 0.0f));
			Canvas->DrawItem(ClearTex);
		}

		if (Drawing)
		{
			FCanvasTileItem Tile(DrawLoc, DrawTexture->Resource, FVector2D(2,2), FVector2D(0, 0), FVector2D(1, 1), FLinearColor(1.0f, 1.0f, 1.0f));
			Canvas->DrawItem(Tile);
		}
	}
}


