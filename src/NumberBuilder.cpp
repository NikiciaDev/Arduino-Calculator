#include "NumberBuilder.h"

NumberBuilder::NumberBuilder() {}

Number NumberBuilder::buildNumber(short position) {
	return Number(this->number.toDouble(), position);
}

void NumberBuilder::clear() {
	this->number = "";
	this->numberObject.value = -1;
	this->numberObject.position = -1;
}