#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Hurdle1.generated.h"

UCLASS()
class PJ03_API AHurdle1 : public AActor
{
	GENERATED_BODY()

public:
	AHurdle1();

protected:
	USceneComponent* SceneRoot;
	UStaticMeshComponent* StaticMeshComp;

	float RotationSpeed;
	float MoveSpeed;

	virtual void PostInitializeComponents() override;
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void Destroyed() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

};
