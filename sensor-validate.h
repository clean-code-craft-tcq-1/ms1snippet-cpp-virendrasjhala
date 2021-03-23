#pragma once
#include "iostream"
class validation
{
public:
	virtual bool readings_InRange(double value, double nextValue, double maxDelta) = 0;

	virtual bool isParameterValid(double* parameters) = 0;
};

class IParameterAccess
{
public:
	 bool readings_InRange(double value, double nextValue, double maxDelta) {
		std::cout << nextValue - value << " " << maxDelta << std::endl;
		if (nextValue - value > maxDelta) {
			return false;
		}
		return true;
	}

	 bool isParameterValid(double* parameters) {
		if (parameters == nullptr) {
			std::cout << " not valid parameter" << '\n';
			return false;
		}
		std::cout << " valid parameter" << '\n';
		return true;

	}
};

class validationForSOC:public IParameterAccess {
public:
	bool validateSOCreadings(double* values, int numOfValues);
};

class ValidationForCurrentreadings:public IParameterAccess {
public:
	bool validateCurrentreadings(double* values, int numOfValues);

};


