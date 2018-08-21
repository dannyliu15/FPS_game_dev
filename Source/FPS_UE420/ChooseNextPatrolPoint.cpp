// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextPatrolPoint.h"




EBTNodeResult::Type UChooseNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
 
    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    UE_LOG(LogTemp, Warning, TEXT("Patrolpoint index: %i"), Index);
    return EBTNodeResult::Succeeded;
}
