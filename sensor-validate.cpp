#include "sensor-validate.h"
#include"iostream"
#define nullptr NULL


bool validationForSOC::validateSOCreadings(double* values, int numOfValues) {
	validationForSOC v_SOC;
	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!v_SOC.readings_InRange(values[i], values[i + 1], 0.05)) {
			return false;
		}
	}
	
	return true;
}

bool ValidationForCurrentreadings::validateCurrentreadings(double* values, int numOfValues) {
	ValidationForCurrentreadings V_readings;
	int lastButOneIndex = numOfValues - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!V_readings.readings_InRange(values[i], values[i + 1], 0.1)) {
			return false;
		}
	}
	return true;
}
