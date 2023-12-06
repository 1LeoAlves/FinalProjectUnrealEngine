
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "NiagaraComponent.h"
#include "SmokeEmitterActor.generated.h"

UCLASS()
class YOURPROJECT_API ASmokeEmitterActor : public AActor
{
    GENERATED_BODY()

public:
    // Sets default values for this actor's properties
    ASmokeEmitterActor();

protected:
    // Called when the game starts or when spawned
    virtual void BeginPlay() override;

public:
    // Called every frame
    virtual void Tick(float DeltaTime) override;

private:
    UPROPERTY(VisibleAnywhere)
        UNiagaraComponent* NiagaraComponent;
};