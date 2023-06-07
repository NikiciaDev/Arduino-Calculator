#pragma once
#include <string.h>
#include "Number.h"
#include "MathUtil.h"

//lets you build a number instance using a string
class NumberBuilder {
private:
	Number numberObject;

public:
	String number;

	NumberBuilder();

	Number buildNumber(short position);

	void clear();
};