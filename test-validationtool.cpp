#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
//#include "catch.hpp"
#include "sensor-validate.h"


TEST_CASE("reports error when soc jumps abruptly") {
	double socReadings[] = { 0.0, 0.01, 0.5, 0.51 };
	int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
	/*--------------------------------------------parameter Check--------------------------------------------*/
	validation checkparameter,checksoc;
	REQUIRE(checkparameter.isParameterValid(socReadings) == true);
	/*--------------------------------------------Soc reading Check-------------------------------------------*/
	REQUIRE(checksoc.validateSOCreadings(socReadings, numOfSocReadings) == false);
	
}

TEST_CASE("reports error when current jumps abruptly") {
	double currentReadings[] = { 0.03, 0.03, 0.03, 0.33 };
	int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
	/*--------------------------------------------parameter Check--------------------------------------------*/
	validation checkparameter, checkcurrent;
	REQUIRE(checkparameter.isParameterValid(currentReadings) == true);
	/*--------------------------------------------current reading Check---------------------------------------*/
	REQUIRE(checkcurrent.validateCurrentreadings(currentReadings, numOfCurReadings) == false);
	
}


