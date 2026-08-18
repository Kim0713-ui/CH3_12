#include "Rolling.h"
#include "Components/SceneComponent.h"
#include "Components/StaticMeshComponent.h"
#include "UObject/ConstructorHelpers.h"

ARolling::ARolling()
{
	SceneRoot = CreateDefaultSubobject<USceneComponent>(TEXT("SceneRoot"));
	SetRootComponent(SceneRoot);
	
	StaticMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMeshComp->SetupAttachment(SceneRoot);

	static ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Engine/BasicShapes/Sphere.Sphere"));
	if(MeshAsset.Succeeded())
	{
		StaticMeshComp->SetStaticMesh(MeshAsset.Object);
	}

	static ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Material/M_RiverRolling.M_RiverRolling"));
	if(MaterialAsset.Succeeded())
	{
		StaticMeshComp->SetMaterial(0,MaterialAsset.Object);
	}
	PrimaryActorTick.bCanEverTick = true;
	RotationSpeed = 15.0f;
	MoveSpeed = 800.0f;
}

void ARolling::PostInitializeComponents()
{
	Super::PostInitializeComponents();
}

void ARolling::BeginPlay()
{
	Super::BeginPlay();

	SetActorLocation(FVector(0.0f, -1500.0f, 550.0f));
	SetActorRotation(FRotator(0.0f, 0.0f,0.0f)); //pitch = y, yaw = x, roll = z
	SetActorScale3D(FVector(12.0f));
}

void ARolling::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RotationSpeed += 5.0f * DeltaTime;

	AddActorLocalRotation(FRotator(0.0f, 0.0f, RotationSpeed * DeltaTime));

	MoveSpeed += 9.0f * DeltaTime;

	AddActorWorldOffset(FVector(0.0f, MoveSpeed*DeltaTime, 0.0f));
}

void ARolling::Destroyed()
{
	Super::Destroyed();
}

void ARolling::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
