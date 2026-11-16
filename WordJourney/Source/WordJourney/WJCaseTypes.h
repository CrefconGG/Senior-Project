
#pragma once

#include "CoreMinimal.h"
#include "WJCaseTypes.generated.h"

UENUM(BlueprintType)
enum class EWJCasePhase : uint8
{
	Dialogue,
	Investigation,
	Decision,
	Feedback
};

USTRUCT(BlueprintType)
struct FWJQuestionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName QuestionID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText QuestionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText AnswerText;
};

USTRUCT(BlueprintType)
struct FWJDecisionData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName DecisionID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText DecisionText;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bIsAppropriate = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText FeedbackTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText FeedbackExplanation;
};

USTRUCT(BlueprintType)
struct FWJCaseData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName CaseID = NAME_None;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText CaseTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText NPCName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FText> InitialDialogue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWJQuestionData> Questions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText EvidenceTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText EvidenceDetails;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText RulebookTitle;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText RulebookDetails;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWJDecisionData> Decisions;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText LearningTarget;
};
