#ifndef LEARN_ANN_H
#define LEARN_ANN_H

#include "ann_evaluator.h"

namespace LearnAnn
{

void Learn(
	const std::string &xFilename,
	const std::string &yFilename,
	const std::string &featuresFilename);
}

#endif // LEARN_ANN_H