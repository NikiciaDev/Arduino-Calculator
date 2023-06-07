#pragma once
#include <string.h>
#include <Vector.h>
#include "Number.h"
#include "Operator.h"

namespace mu {
	//returns 0 if the equation is not valid, returns non 0 when equation is valid
	bool verifyEquationValidity(String& equation);

	//solves the given equation if provided in a number vector and an operator vector
	Number solve(Vector<Number>& numbers, Vector<Operator>& operators);

  //returns true if c is a digit otherwise 0w
  bool isDigit(const char c);

	//helper function for solve()
	short findNextNonUsedDown(Vector<Number>& numbers, short position);

	//helper function for solve()
	short findNextNonUsedUp(Vector<Number>& numbers, short position);
}