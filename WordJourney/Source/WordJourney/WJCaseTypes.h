
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

UENUM(BlueprintType)
enum class EWJDialogueSpeaker : uint8
{
	NPC UMETA(DisplayName = "NPC"),
	Player UMETA(DisplayName = "Player")
};

USTRUCT(BlueprintType)
struct FWJDialogueLine
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWJDialogueSpeaker Speaker = EWJDialogueSpeaker::NPC;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText LineText;
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FText NPCResponse;
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
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<FWJDialogueLine> OpeningDialogue;
};
