#include "sensor-validate.h"
#include"iostream"
#define nullptr NULL
bool Batterty_Soc::SocReadingInRange(double value, double nextValue, double maxDelta) {
	std::cout << nextValue - value <<" " <<maxDelta << std::endl;
	if (nextValue - value > maxDelta) {
		return false;
	}
	return true;
}

bool Batterty_Soc::readings(double* parameters, int numOfParameters)
{
	int lastButOneIndex = numOfParameters - 1;
	for (int i = 0; i < lastButOneIndex; i++) {
		if (!SocReadingInRange(parameters[i], parameters[i + 1], 0.05)) {
			return false;
		}
	}
	return true;
}

bool Batterty_Soc::validateSOCreadings(double* values, int numOfValues) {

	if (values != nullptr){
		return readings(values,numOfValues);
	}
}

