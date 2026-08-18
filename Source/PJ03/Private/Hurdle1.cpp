#include "Hurdle1.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

AHurdle1::AHurdle1()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);

	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/Models/vase1/brass_vase_01_2k.brass_vase_01_2k"));
	if (MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}
	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Models/vase1/brass_vase_001.brass_vase_001"));
	if (MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 25.0f;
	MoveSpeed = -450.0f;
}

void AHurdle1::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void AHurdle1::BeginPlay()
{
	Super::BeginPlay();
}

void AHurdle1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	AddActorLocalRotation(FRotator(0.0f, RotationSpeed * DeltaTime, 0.0f));

	AddActorWorldOffset(FVector(0.0f, MoveSpeed * DeltaTime, 0.0f));
}

void AHurdle1::Destroyed()
{
	Super::Destroyed();
}

void AHurdle1::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}

