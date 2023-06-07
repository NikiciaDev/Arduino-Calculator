#include "ExtractionUtil.h"

namespace eu {
void extractNumbersAndOperators(const String& equation, Vector<Number>& numbers, Vector<Operator>& operators) {
		short posInNum = 0, posInOp = 0;
		NumberBuilder numberBuilder;

		for (short s = 0; s <= equation.length(); s++) {
			const char c = equation[s];

			if (s == equation.length() + 1 || (!mu::isDigit(c) && c != '.' && numberBuilder.number.length() != 0)) {
				numbers.push_back(numberBuilder.buildNumber(posInNum));
				numberBuilder.clear();
				if (s < equation.length()) {
					operators.push_back(Operator(c, Operator::evaluatePreference(c), posInOp));
					posInOp++;
				}

				posInNum++;
				continue;
			}

			numberBuilder.number += c;
		}
	}
}