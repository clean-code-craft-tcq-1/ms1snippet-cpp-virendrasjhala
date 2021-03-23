#include "sensor-validate.h"
#include"iostream"
#define nullptr NULL

bool Batterty_Soc::readings_InRange(double value, double nextValue, double maxDelta) {
	std::cout << nextValue - value <<" " <<maxDelta << std::endl;
	if (nextValue - value > maxDelta) {
		return false;
	}
	return true;
}

bool Batterty_Soc::isParameterValid(double* parameters) {
	if (parameters == nullptr){
		std::cout << " not valid parameter"<<'\n';
		return false;	
	}
	std::cout << " valid parameter"<<'\n';
	return true;
	
}

bool Batterty_Soc::validateSOCreadings(double* values, int numOfValues) {

	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!readings_InRange(values[i], values[i + 1], 0.05)) {
			return false;
		}
	}
	
	return true;
}

bool Batterty_Soc::validateCurrentreadings(double* values, int numOfValues) {
	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!readings_InRange(values[i], values[i + 1], 0.1)) {
			return false;
		}
	}
	return true;
}
