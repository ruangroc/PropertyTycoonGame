#include "Property.h"

using namespace std;

/***********************************************************************************
 * Function: Property constructor
 * Description: initializes variables in a new Property object
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: initializes all variables in a new Property object
 * ********************************************************************************/
Property::Property() {

	property_name = "";
	property_value = 0.0;
	location = "";
	mortgage = 0.0;
	mortgage_turns = 0;
	property_tax = 0.0;
	num_tenants = 0;
	rent = 0.0;
}

/**********************************************************************************
 * Function: accessor functions
 * Description: accessor functions for each Property variable
 * Parameters: none
 * Pre-conditions: variables have a value
 * Post-conditions: returns the value in the variable (int, string. or float)
 * *******************************************************************************/
float Property::get_property_value() {
	return property_value; 
}

string Property::get_location() {
	return location;
}

float Property::get_mortgage() {
	return mortgage;
}

int Property::get_mortgage_turns() {
	return mortgage_turns;
}

float Property::get_property_tax() {
	return property_tax;
}

int Property::get_num_tenants() {
	return num_tenants;
}

float Property::get_rent() {
	return rent;
}


/**********************************************************************************
 * Function: random_location
 * Description: returns a randomly selected location
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: returns a string
 * ********************************************************************************/
string Property::random_location() {

	int num = rand() % 5;

	if (num == 0) {
		return "SE";
	}

	else if (num == 1) {
		return "NE";
	}

	else if (num == 2) {
		return "Midwest";
	}

	else if (num == 3) {
		return "SW";
	}

	else if (num == 4) {
		return "NW";
	}
}


/***********************************************************************************
 * Function: random_property_value
 * Description: returns a randomized property value
 * Parameters: char type
 * Pre-conditions: input must be a char (h, a, or b)
 * Post-conditions: returns a float
 * ********************************************************************************/
float Property::random_property_value(char type) {

	int num = 0;

	if (type == 'h') {
		num = (rand() % 500000) + 100000;
	}

	else if (type == 'a') {
		num = (rand() % 300000) + 300000;
	}

	else if (type == 'b') {
		num = (rand() % 200000) + 400000;
	}

	return num;
}


/***********************************************************************************
 * Function: random_mortgage
 * Description: returns a randomized monthly mortgage amount
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: returns a float
 * ********************************************************************************/
float Property::random_mortgage() {

	int num = (rand() % 4500) + 500;
	return num;
}


/***********************************************************************************
 * Function: new_tenant
 * Description: returns a populated tenant
 * Parameters: char type
 * Pre-conditions: input must be a char (c for citizen or b for business)
 * Post-conditions: returns a populated tenant object
 * *********************************************************************************/
tenant Property::new_tenant(char tenant_type) {

	tenant t;

	if (tenant_type == 'c') {
		t.type = "citizen";
		t.budget = (rand() % 4500) + 500;
		t.name = citizen_name();
	}

	else if (tenant_type == 'b') {
		t.type = "business";
		t.budget = (rand() % 8000) + 2000;
		t.name = business_name();
	}

	t.agree = (rand() % 5) + 1;

	return t;
}


/**********************************************************************************
 * Function: citizen_name
 * Description: generates a random name for a tenant of type citizen
 * Parameters: none
 * Pre-conditions: citizen_names.txt is formatted as expected
 * Post-conditions: returns a string
 * *******************************************************************************/
string Property::citizen_name() {

	ifstream read;
	read.open("citizen_names.txt");
	
	int num = rand() % 156;
	string name = "";

	for (int i = 0; i < num; i++) {
		getline(read, name);
	}

	read.close();

	return name;
}


/***********************************************************************************
 * Function: business_name
 * Description: generates a random name for a tenant of type business
 * Parameters: none
 * Pre-conditions: property_names.txt is formatted as expected
 * Post-conditions: returns a string
 * ********************************************************************************/
string Property::business_name() {

	ifstream read;
	read.open("property_names.txt");

	int num = rand() % 20;
	string name = "";

	string ignore = "";
	while (ignore != "BUSINESS") {
		getline(read, ignore);
	}

	for (int i = 0; i < num; i++) {
		getline(read, name);
	}

	read.close();

	return name;
}


/***********************************************************************************
 * Function: print_property
 * Description: prints property info
 * Parameters: none
 * Pre-conditions: populated object
 * Post-conditions: prints to screen 
 * ********************************************************************************/
void Property::print_property() {

	cout << property_name << endl;
	cout << "Property Value: " << property_value << " | ";
	cout << "Location: " << location << " | ";
	cout << "Number of Tenants: " << num_tenants << endl;
	cout << "Mortgage: " << mortgage << " | ";
	cout << "Number of months left to pay off mortgage: " << mortgage_turns;
	if (rent != 0) {
		cout << endl << "Current rent amount: " << rent << endl;
	}
}


/***********************************************************************************
 * Function: pay_mortgage
 * Description: returns the mortgage payment amount
 * Parameters: none
 * Pre-conditions: object is populated
 * Post-conditions: returns an int
 * ********************************************************************************/
int Property::pay_mortgage() {

	if (mortgage_turns == 0) {
		return 0;
	}

	else {
		mortgage_turns--;
		return mortgage;
	}
}


/**********************************************************************************
 * Function: set_property_value
 * Description: mutator for property_value
 * Parameters: float new_value
 * Pre-conditions: input must be a float or int
 * Post-conditions: changes property_value
 * *******************************************************************************/
void Property::set_property_value(float new_value) {
	property_value = new_value;
}




