#include "Number.h"

Number::Number() {
	value = -1;
	position = -1;
	used = false;
}

Number::Number(double value, short position) : value(value), position(position), used(false) {}