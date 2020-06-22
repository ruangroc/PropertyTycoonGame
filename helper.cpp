#include "helper.h"

using namespace std;


/************************************************************************************
 * Function: check_option
 * Description: checks for valid menu option
 * Parameters: string input
 * Pre-conditions: input must be a string
 * Post-conditions: returns a bool
 * *********************************************************************************/
bool check_option(string input) {

	if (input.length() != 1) {
		return false;
	}

	if (input != "1" && input != "2" && input != "3" && input != "4") {
		return false;
	}

	return true;
}


/*********************************************************************************
 * Function: check_numbers
 * Description: checks that the string contains only numbers
 * Parameters: string input
 * Pre-conditions: input must be a string
 * Post-conditions: returns a bool
 * ******************************************************************************/
bool check_numbers(string input) {

	if (input.length() == 0) {
		return false;
	}

	for (int i = 0; i < input.length(); i++) {
		if ((int) input[i] < 48 || (int) input[i] > 57) {
			return false;
		}
	}

	return true;
}


/**********************************************************************************
 * Function: string_to_int
 * Description: converts a string into an int
 * Parameters: string input
 * Pre-conditions: input must be a string containing an int
 * Post-conditions: returns an int
 * *******************************************************************************/
int string_to_int(string input) {

	int valid_int = 0;
	int len = input.length();

	for (int i = 0; i < len; i++) {
		int num = ((int) input[i] - 48);
		valid_int += num * pow(10, (len-1-i));
	}

	return valid_int;
}



