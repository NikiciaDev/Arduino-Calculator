#include "Operator.h"

Operator::Operator() {
	sign = -1;
	preference = -1;
	position = -1;
}

Operator::Operator(char sign, short preference, short position) : sign(sign), preference(preference), position(position) {}

bool Operator::isValid(char sign) {
	return sign == '+' || sign == '-' || sign == '*' || sign == '/' || sign == '^';
}

short Operator::evaluatePreference(char sign) {
	switch (sign) {
	default:
		return -1;
		break;
	case '+':
		return 0;
		break;
	case '-':
		return 0;
		break;
	case '*':
		return 1;
		break;
	case '/':
		return 1;
		break;
	case '^':
		return 2;
		break;
	}
}

Number Operator::operate(Number number1, Number number2) {
	Number numberOut;
	numberOut.position = number1.position;

	switch (this->sign) {
	case '+':
		numberOut.value = number1.value + number2.value;
		break;
	case '-':
		numberOut.value = number1.value - number2.value;
		break;
	case '*':
		numberOut.value = number1.value * number2.value;
		break;
	case '/':
		numberOut.value = number1.value / number2.value;
		break;
	case '^':
		numberOut.value = pow(number1.value, number2.value);
		break;
	}
	return numberOut;
}

bool Operator::operator < (const Operator& _operator) {
	if (this->preference == _operator.preference) return this->position < _operator.position;
	return this->preference > _operator.preference;
}

bool Operator::operator > (const Operator& _operator) {
	if (this->preference == _operator.preference) return this->position > _operator.position;
	return this->preference < _operator.preference;
}
