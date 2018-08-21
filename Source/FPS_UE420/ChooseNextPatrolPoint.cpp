// Fill out your copyright notice in the Description page of Project Settings.


#include "ChooseNextPatrolPoint.h"




EBTNodeResult::Type UChooseNextPatrolPoint::ExecuteTask(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory)
{
    //Testing
    
    //UE_LOG(LogTemp, Warning, TEXT("Patrolpoint index: %i"), Index);
    
    // Get the patrol points
    auto AIController = OwnerComp.GetAIOwner();
    auto ControlledPawn = AIController->GetPawn();
    //**********IMPORTANT***********//
    auto PatrollingGuard = Cast<APatrollingGuard>(ControlledPawn);
    //******************************//
    auto PatrolPoints = PatrollingGuard->PatrollPoints;
    
    // Set next patrol point
    auto BlackboardComp = OwnerComp.GetBlackboardComponent();
    auto Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
    BlackboardComp->SetValueAsObject(PatrolPointKey.SelectedKeyName, PatrolPoints[Index]);
    
    // Cycle the index
    BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, (Index+1)%PatrolPoints.Num());

    // TODO protect against empty patrol routes

    return EBTNodeResult::Succeeded;
}
