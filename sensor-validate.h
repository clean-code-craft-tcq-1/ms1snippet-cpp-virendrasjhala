#pragma once

class Batterty_Soc
{
public:

	bool readings_InRange(double value, double nextValue, double maxDelta);

	bool isParameterValid(double* parameters);

	bool validateSOCreadings(double* values, int numOfValues);

	bool validateCurrentreadings(double* values, int numOfValues);


};

