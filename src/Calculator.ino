#include "Keypad.h"
#include "Vector.h"
#include "Number.h"
#include "ExtractionUtil.h"
#include "Operator.h"
#include "MathUtil.h"

const byte rows = 4;
const byte cols = 4;

char hexaKeys[rows][cols] = {
 {'1','2','3','A'},
 {'4','5','6','B'},
 {'7','8','9','C'},
 {'*','0','#','D'}
};

byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols] = {5, 4, 3, 2};

Keypad pad = Keypad(makeKeymap(hexaKeys), rowPins, colPins, rows, cols);

const short ELEMENT_COUNT_MAX = 10;
Number storageN[ELEMENT_COUNT_MAX];
Operator storageO[ELEMENT_COUNT_MAX];
Vector<Number>* numbers = new Vector<Number>(storageN);
Vector<Operator>* operators = new Vector<Operator>(storageO);

String equation = "";

bool wld = false;

void setup(){
  Serial.begin(9600);
}

void loop() {
  char c = pad.getKey();
  bool skip = false;

  if(c == 'D') {
    if(wld) {
      equation.remove(equation.length() - 1);
      if(mu::verifyEquationValidity(equation)) {
        eu::extractNumbersAndOperators(equation, *numbers, *operators);
        if(numbers->size() == 1) goto Invalid;
        String result(mu::solve(*numbers, *operators).value, 5);
        Serial.print(equation + " = "); Serial.println(result);
        numbers->clear();
        operators->clear();
        equation = "";
      }else {
        Invalid:
        Serial.println("Equation not valid!");
        equation = "";
      }
      skip = true;
    }
  }

  if(!skip){
    if(convertCharToValidChar(c) != 'E') {
      equation += c;
      Serial.println(equation);
      wld = (c == '.');
    }
  }
}

char convertCharToValidChar(char& c) {
  if(isDigit(c)) return c;
  switch(c) {
    default:
      c = 'E';
    break;
    case 'D':
      c = '.';
    break;
    case 'A':
      c = '+';
    break;
    case 'B':
      c = '-';
    break;
    case '*':
    break;
    case '#':
      c = '/';
    break;
    case 'C':
      c = '^';
    break;
  }
  return c;
}
