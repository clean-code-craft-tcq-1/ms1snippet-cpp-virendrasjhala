#define CATCH_CONFIG_MAIN  // This tells Catch to provide a main() - only do this in one cpp file

#include "test/catch.hpp"
//#include "catch.hpp"
#include "sensor-validate.h"



TEST_CASE("reports error when soc jumps abruptly") {
	double socReadings[] = { 0.0, 0.01, 0.5, 0.51 };
	int numOfSocReadings = sizeof(socReadings) / sizeof(socReadings[0]);
	/*--------------------------------------------parameter Check--------------------------------------------*/
	validationForSOC obj1,obj2;
	REQUIRE(obj2.isParameterValid(socReadings) == true);

	/*--------------------------------------------Soc Check--------------------------------------------------*/
	REQUIRE(obj1.validateSOCreadings(socReadings, numOfSocReadings) == false);
	//system("pause");
}

TEST_CASE("reports error when current jumps abruptly") {
	double currentReadings[] = { 0.03, 0.03, 0.03, 0.33 };
	int numOfCurReadings = sizeof(currentReadings) / sizeof(currentReadings[0]);
	ValidationForCurrentreadings obj3, obj4;
	REQUIRE(obj3.isParameterValid(currentReadings) == true);
	REQUIRE(obj4.validateCurrentreadings(currentReadings, numOfCurReadings) == false);
	//system("pause");
}


