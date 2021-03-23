#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
//#include "catch.hpp"
#include "sensor-validate.h"



TEST_CASE("reports error when soc jumps abruptly") {
	double socReadings[] = { 0.0, 0.01, 0.5, 0.51 };
	int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
	/*--------------------------------------------parameter Check--------------------------------------------*/
	Batterty_Soc checkparameter;
	REQUIRE(checkparameter.isParameterValid(socReadings) == true);

	/*--------------------------------------------Soc Check--------------------------------------------------*/
	Batterty_Soc B_Soc;
	REQUIRE(B_Soc.validateSOCreadings(socReadings, numOfSocReadings) == false);
	//system("pause");
}

TEST_CASE("reports error when current jumps abruptly") {
	double currentReadings[] = { 0.03, 0.03, 0.03, 0.33 };
	int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);

	Batterty_Soc c_parameter;
	REQUIRE(c_parameter.isParameterValid(currentReadings) == true);
        /*
	Batterty_Soc Batterty_Soc;
	REQUIRE(Batterty_Soc.validateCurrentreadings(currentReadings, numOfCurReadings) == false);
	//system("pause");
	*\
}


