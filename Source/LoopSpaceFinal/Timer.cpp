// Fill out your copyright notice in the Description page of Project Settings.

#include "LoopSpaceFinal.h"
#include "Timer.h"


// Sets default values
ATimer::ATimer()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CountdownText = CreateDefaultSubobject<UTextRenderComponent>(TEXT("CTime"));
	CountdownText->SetHorizontalAlignment(EHTA_Center);
	RootComponent = CountdownText;
}

// Called when the game starts or when spawned
void ATimer::BeginPlay()
{
	Super::BeginPlay();
	CTime = StartTime;

}

// Called every frame
void ATimer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	CTime += DeltaTime;
	UpdateTimerDisplay();
}

void ATimer::UpdateTimerDisplay()
{
	int mins = ((int)(CTime) / 60);
	int hrs = mins / 60;
	mins %= 60;
	int secs = (int)(CTime) % 60;

	FString hrstring = FString::FromInt(hrs);
	FString minstring = FString::FromInt(mins);
	FString secstring = FString::FromInt(secs);

	if (secs < 10)
	{
		secstring.InsertAt(0, "0");
	}
	if (mins < 10)
	{
		minstring.InsertAt(0, "0");
	}

	//FText newText = FText::FromString(hrstring + ":" + minstring + ":" + secstring);
	FText newText = FText::FromString(minstring + ":" + secstring);

	CountdownText->SetText(newText);
}