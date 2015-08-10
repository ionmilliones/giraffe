#ifndef ANN_MOVE_EVALUATOR_H
#define ANN_MOVE_EVALUATOR_H

#include <iostream>
#include <string>
#include <vector>

#include "move_evaluator.h"

#include "ann_evaluator.h"
#include "ann.h"
#include "learn_ann.h"
#include "features_conv.h"
#include "board.h"

class ANNMoveEvaluator : public MoveEvaluatorIface
{
public:
	ANNMoveEvaluator(ANNEvaluator &annEval);

	void Train(const std::vector<std::string> &positions, const std::vector<std::string> &bestMoves);

	void Test(const std::vector<std::string> &positions, const std::vector<std::string> &bestMoves);

	virtual void EvaluateMoves(Board &board, SearchInfo &si, MoveInfoList &list, MoveList &ml);

	void Serialize(std::ostream &os);
	void Deserialize(std::istream &is);

private:
	void GenerateMoveConvInfo_(Board &board, MoveList &ml, FeaturesConv::ConvertMovesInfo &convInfo, ANNEvaluator &evaluator, SearchInfo &si);

	MoveEvalNet m_ann;

	// we need to have an ANN evaluator to generate signatures
	ANNEvaluator &m_annEval;
};

#endif // ANN_MOVE_EVALUATOR_H