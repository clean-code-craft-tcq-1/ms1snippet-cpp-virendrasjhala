#pragma once

class Batterty_Soc
{
public:

	bool SocReadingInRange(double value, double nextValue, double maxDelta);

	bool validateSOCreadings(double* values, int numOfValues);

	bool validateCurrentreadings(double* values, int numOfValues);


};

