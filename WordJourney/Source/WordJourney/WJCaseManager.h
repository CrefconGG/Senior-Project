
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WJCaseTypes.h"
#include "WJCaseManager.generated.h"

UCLASS()
class WORDJOURNEY_API AWJCaseManager : public AActor
{
	GENERATED_BODY()

public:
	AWJCaseManager();
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category="Case")
	FWJCaseData CurrentCase;
	
	UPROPERTY(BlueprintReadOnly, Category="Case")
	EWJCasePhase Phase = EWJCasePhase::Dialogue;

	UPROPERTY(BlueprintReadOnly, Category="Case")
	int32 DialogueIndex = 0;

	UPROPERTY(BlueprintReadOnly, Category="Case")
	bool bAskedAtLeastOnce = false;

	UPROPERTY(BlueprintReadOnly, Category="Case")
	bool bViewedEvidence = false;

	UPROPERTY(BlueprintReadOnly, Category="Case")
	FName SelectedDecisionID = NAME_None;

	UFUNCTION(BlueprintCallable, Category="Case")
	void StartCase();

	UFUNCTION(BlueprintCallable, Category="Case")
	bool AdvanceDialogue(FText& OutLine);

	UFUNCTION(BlueprintCallable, Category="Case")
	bool AskNPC(FName QuestionID, FText& OutAnswer);

	UFUNCTION(BlueprintCallable, Category="Case")
	void MarkEvidenceViewed();

	UFUNCTION(BlueprintCallable, Category="Case")
	bool SubmitDecision(
		FName DecisionID,
		FWJDecisionData& OutDecision
	);

	UFUNCTION(BlueprintCallable, Category="Case")
	void ResetCase();
};
