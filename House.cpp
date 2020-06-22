#include "House.h"

using namespace std;


/**********************************************************************************
 * Function: House constructor
 * Description: initializes tenant in the House
 * Parameters: none
 * Pre-conditions: new object
 * Post-conditions: initialized
 **********************************************************************************/
House::House() {
	t.type = "";
	t.budget = 0;
	t.agree = 0;
}


/***********************************************************************************
 * Function: get_tenant
 * Description: returns the tenant in the House
 * Parameters: none
 * Pre-conditions: tenant has values
 * Post-conditions: returns a tenant object
 * ********************************************************************************/
tenant House::get_tenant() const {
	return t;
}


/*********************************************************************************
 * Function: get_name
 * Description: accessor for property_name
 * Parameters: none
 * Pre-conditions: property_name has a value
 * Post-conditions: returns a string
 * ******************************************************************************/
string House::get_name() const {
	return property_name;
}


/**********************************************************************************
 * Function: set_up_House
 * Description: populates a House object with randomized values
 * Parameters: none
 * Pre-conditions: House object created
 * Post-conditions: populates House with randomized values
 * ********************************************************************************/
void House::set_up_House() {

	property_name = house_name();
	location = random_location();
	property_value = random_property_value('h');
	mortgage = random_mortgage();
	mortgage_turns = property_value / mortgage;
	property_tax = 0.015;
	num_tenants = 1;
	t = new_tenant('c');
}


/**********************************************************************************
 * Function: house_name
 * Description: generates a random name for a house
 * Parameters: none
 * Pre-conditions: property_names.txt is formatted as expected
 * Post-conditions: returns a string
 * *******************************************************************************/
string House::house_name() {

	ifstream read;
	read.open("property_names.txt");

	int num = rand() % 20;
	string name = "";

	string ignore = "";
	while (ignore != "HOUSE") {
		getline(read, ignore);
	}

	for (int i = 0; i < num; i++) {
		getline(read, name);
	}

	read.close();

	return name;
}


/**********************************************************************************
 * Function: collect_rent
 * Description: collects rent from tenant
 * Parameters: none
 * Pre-conditions: object has a populated tenant object
 * Post-condition: returns an int
 * *******************************************************************************/
int House::collect_rent() {

	int rent_collected = 0;

	if (num_tenants > 0 && t.type == "citizen" && t.budget >= rent) {
		rent_collected += rent;
	}

	else if (num_tenants > 0 && t.budget < rent) {
		if (t.agree == 1) {
			cout << t.name << " refuses to pay rent and ";
			cout << "refuses to leave the house." << endl;
		}

		else {
			cout << t.name << " can no longer afford to ";
			cout << "live in the house. They have moved out." << endl;
			t.type = "none";
			num_tenants--;
		}
	}

	return rent_collected;
}


/*********************************************************************************
 * Function: set_rent_amount
 * Description: mutator for rent
 * Parameters: int new_rent
 * Pre-conditions: input must be a valid, positive int
 * Post-conditions: changes value of rent in House object
 * ******************************************************************************/
void House::set_rent_amount(int new_rent) {
	rent = new_rent;
}







