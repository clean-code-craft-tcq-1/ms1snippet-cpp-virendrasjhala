#include "sensor-validate.h"

bool readingInRange(double value, double nextValue, double maxDelta) {
	if (nextValue - value > maxDelta) {
		return false;
	}
	return true;
}

bool isParameterValid(double* parameter){

	if(parameter)
		return true;
	return false;
}

bool validateSOCreadings(double* values, int numOfValues) {
	if (isParameterValid(values)) {
		int lastButOneIndex = numOfValues - 1;
		for (int i = 0; i < lastButOneIndex; i++) {
			if (!readingInRange(values[i], values[i + 1], 0.05)) {
				return false;
			}
		}
	}
	return true;
}


