#pragma once
#include <string.h>
#include <Vector.h>
#include "Number.h"
#include "Operator.h"
#include "NumberBuilder.h"

namespace eu {
	//extracts numbers and operators from the given equation and fills them into the given vectors
	void extractNumbersAndOperators(const String& equation, Vector<Number>& numbers, Vector<Operator>& operators);
}