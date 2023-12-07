// Shoot Them Up Game. All Rights Reserved 


#include "Weapon/STUBaseWeapon.h"
#include "Components/SkeletalMeshComponent.h"
#include "Engine/World.h"
#include "DrawDebugHelpers.h"
#include "GameFramework/Character.h"
#include "GameFramework/Controller.h"

ASTUBaseWeapon::ASTUBaseWeapon()
{
	PrimaryActorTick.bCanEverTick = true;

        WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("WeaponMesh");
        SetRootComponent(WeaponMesh);

}


void ASTUBaseWeapon::BeginPlay()
{
	Super::BeginPlay();

        check(WeaponMesh);
}

void ASTUBaseWeapon::Fire()
{
                MakeShot();
}

void ASTUBaseWeapon::MakeShot()
{
        if(!GetWorld()) return;

        const auto Player = Cast<ACharacter>(GetOwner());
        if (!Player) return;

        const auto Controller = Player->GetController<APlayerController>();
        if(!Controller) return;

        FVector ViewLocation;
        FRotator ViewRotation;
        Controller->GetPlayerViewPoint(ViewLocation, ViewRotation);
        
        const FTransform SocketTransform = WeaponMesh->GetSocketTransform(MuzzleSocketName);
        const FVector TraceStart = ViewLocation; //SocketTransform.GetLocation();
        const FVector ShootDirection = ViewRotation.Vector(); //SocketTransform.GetRotation().GetForwardVector();
        const FVector TraceEnd = TraceStart + ShootDirection * TraceMaxDistance;
        

        FCollisionQueryParams CollisionParams;
        CollisionParams.AddIgnoredActor(GetOwner());
        
        FHitResult HitResult;
        GetWorld()->LineTraceSingleByChannel(HitResult, TraceStart, TraceEnd, ECollisionChannel::ECC_Visibility, CollisionParams);

        if(HitResult.bBlockingHit)
        {
                DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), HitResult.ImpactPoint, FColor::Red, false, 3.0f, 0, 3.0f);
                DrawDebugSphere(GetWorld(), HitResult.ImpactPoint, 10.0f, 24, FColor::Red, false, 5.0f);
        } else
        {
                DrawDebugLine(GetWorld(), SocketTransform.GetLocation(), TraceEnd, FColor::Red, false, 3.0f, 0, 3.0f);
        }
}