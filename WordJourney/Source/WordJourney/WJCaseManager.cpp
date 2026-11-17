
#include "WJCaseManager.h"

AWJCaseManager::AWJCaseManager()
{
	PrimaryActorTick.bCanEverTick = false;
}

void AWJCaseManager::StartCase()
{
	Phase = EWJCasePhase::Dialogue;
	DialogueIndex = 0;
	bAskedAtLeastOnce = false;
	bViewedEvidence = false;
	SelectedDecisionID = NAME_None;
}

bool AWJCaseManager::AdvanceDialogue(FText& OutLine)
{
	if (!CurrentCase.InitialDialogue.IsValidIndex(DialogueIndex))
	{
		OutLine = FText::GetEmpty();
		Phase = EWJCasePhase::Investigation;
		return false;
	}

	OutLine = CurrentCase.InitialDialogue[DialogueIndex];
	++DialogueIndex;
	return true;
}

bool AWJCaseManager::AskNPC(
	FName QuestionID,
	FText& OutAnswer)
{
	OutAnswer = FText::GetEmpty();

	for (const FWJQuestionData& Question : CurrentCase.Questions)
	{
		if (Question.QuestionID == QuestionID)
		{
			OutAnswer = Question.AnswerText;
			bAskedAtLeastOnce = true;
			Phase = EWJCasePhase::Investigation;
			return true;
		}
	}

	return false;
}

void AWJCaseManager::MarkEvidenceViewed()
{
	bViewedEvidence = true;
}

bool AWJCaseManager::SubmitDecision(
	FName DecisionID,
	FWJDecisionData& OutDecision)
{
	for (const FWJDecisionData& Decision : CurrentCase.Decisions)
	{
		if (Decision.DecisionID == DecisionID)
		{
			SelectedDecisionID = DecisionID;
			OutDecision = Decision;
			return true;
		}
	}

	return false;
}

void AWJCaseManager::ResetCase()
{
	StartCase();
}

void AWJCaseManager::SetCasePhase(EWJCasePhase NewPhase)
{
	Phase = NewPhase;
}