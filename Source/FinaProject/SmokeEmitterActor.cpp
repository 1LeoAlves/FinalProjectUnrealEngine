// Fill out your copyright notice in the Description page of Project Settings.

#include "SmokeEmitterActor.h"
#include "NiagaraFunctionLibrary.h"

// Sets default values
ASmokeEmitterActor::ASmokeEmitterActor()
{
    // Set this actor to call Tick() every frame
    PrimaryActorTick.bCanEverTick = true;

    // Create NiagaraComponent
    NiagaraComponent = CreateDefaultSubobject<UNiagaraComponent>(TEXT("NiagaraComponent"));
    RootComponent = NiagaraComponent;
}

// Called when the game starts or when spawned
void ASmokeEmitterActor::BeginPlay()
{
    Super::BeginPlay();

    // Bind function to OnComponentHit event
    OnHit.AddDynamic(this, &ASmokeEmitterActor::OnHit);
}

// Called every frame
void ASmokeEmitterActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Function called when the actor is hit
void ASmokeEmitterActor::OnHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
    // Spawn Niagara effect on hit
    UNiagaraFunctionLibrary::SpawnSystemAtLocation(GetWorld(), NiagaraSystem, GetActorLocation(), GetActorRotation());
}