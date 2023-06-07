#include "MathUtil.h"

namespace mu {
  bool isDigit(const char c) {
    if ((c>='0') && (c<='9')) return true;
    return false;
  }

	bool verifyEquationValidity(String& equation) {
		bool inNumber = mu::isDigit(*equation.begin()) || *equation.begin() == '-';
		bool hadDot = false, wasLastDot = false, expectingDigit = false, wasDivision = false;

		if (!isDigit(*(equation.end() - 1))) return false;

		for (char c : equation) {
			if (c == '.' && !inNumber) return false;

			if (isDigit(c)) {
				if (wasDivision && c == '0') return false;
				wasDivision = false;
				wasLastDot = false;
				inNumber = true;
				expectingDigit = false;
				continue;
			} else if(!expectingDigit) {
				if (c == '.') {
					wasLastDot = true;
					if (!hadDot) {
						hadDot = true;
						continue;
					}
				} else if (Operator::isValid(c) && inNumber) {
					wasDivision = c == '/';
					inNumber = false;
					wasLastDot = false;
					hadDot = false;
					continue;
				}
				if (c == '-') {
					expectingDigit = true;
					inNumber = false;
					continue;
				}
			}

			return false;
		}

		return true;
	}

	Number solve(Vector<Number>& numbers, Vector<Operator>& operators) {
    for (int i = 0; i < operators.size(); i++) {
      for (int j = i; j < (operators.size()); j++) {
          if (operators[i] > operators[j]) {
            Operator o = operators[i];
            operators[i] = operators[j];
            operators[j] = o;
          }
      }
    }

		for (Operator o : operators) {
			short nextDown = findNextNonUsedDown(numbers, o.position), nextUp = findNextNonUsedUp(numbers, o.position + 1);
			Number n = o.operate(numbers[nextDown], numbers[nextUp]);
			numbers[nextDown] = n;
			numbers[nextUp].used = true;
		}

		return numbers[0];
	}

	short findNextNonUsedDown(Vector<Number>& numbers, short position) {
		for (position; position >= 0; position--) {
			if (!numbers[position].used) return position;
		}
		return -1;
	}

	short findNextNonUsedUp(Vector<Number>& numbers, short position) {
		for (position; position < numbers.size(); position++) {
			if (!numbers[position].used) return position;
		}
		return -1;
	}
}