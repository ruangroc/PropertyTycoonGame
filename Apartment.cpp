#include "Apartment.h"

using namespace std;

/*********************************************************************************
 * Function: Apartment constructor
 * Description: initializes all variables and pointers in a new Apartment object
 * Parameters: none
 * Pre-conditions: new Apartment object
 * Post-conditions: initializes all variables
 * *******************************************************************************/
Apartment::Apartment():Property() {

	num_rooms = 0;
	num_tenants = 0;
	tenants = NULL;
}


/**********************************************************************************
 * Function: Apartment destructor
 * Description: deletes dynamic memory in Apartment object
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: deletes dynamic memory
 * *******************************************************************************/
Apartment::~Apartment() {

	if (tenants != NULL) {
		delete [] tenants;
	}
}


/*********************************************************************************
 * Function: Apartment copy constructor
 * Description: makes a deep copy of an Apartment object
 * Parameters: const Apartment & other
 * Pre-conditions: copying into a new Apartment object
 * Post-conditions: makes a deep copy
 * ******************************************************************************/
Apartment::Apartment(const Apartment & other):Property(other) {

	property_name = other.get_name();
	num_rooms = other.get_num_rooms();
	num_tenants = other.get_num_tenants();

	tenants = new tenant[num_rooms];
	for (int i = 0; i < num_rooms; i++) {
		tenants[i] = other.get_tenant(i);
	}
}


/*********************************************************************************
 * Function: Apartment assignment operator overload
 * Description: makes a deep copy of an Apartment object
 * Parameters: const Apartment & other
 * Pre-conditions: none
 * Post-conditions: makes a deep copy
 * ******************************************************************************/
const Apartment& Apartment::operator=(const Apartment& other) {

	Property::operator=(other);  //calls parent's AOO

	if (tenants != NULL) {
		delete [] tenants;
		tenants = NULL;
	}

	property_name = other.get_name();
	num_rooms = other.get_num_rooms();
	num_tenants = other.get_num_tenants();

	tenants = new tenant[num_rooms];
	for (int i = 0; i < num_rooms; i++) {
		tenants[i] = other.get_tenant(i);
	}
}


/********************************************************************************
 * Function: accessors
 * Description: returns variables from Apartment's private section
 * Parameters: int index for the get_tenant one
 * Pre-conditions: variables have values
 * Post-conditions: returns a tenant object or an int or a string
 * *****************************************************************************/
tenant Apartment::get_tenant(int index) const {
	return tenants[index];
}

int Apartment::get_num_rooms() const {
	return num_rooms;
}

int Apartment::get_num_tenants() const {
	return num_tenants;
}

string Apartment::get_name() const {
	return property_name;
}

/**********************************************************************************
 * Function: set_up_Apartment
 * Description: populates an Apartment object
 * Parameters: none
 * Pre-conditions: object has been initialized
 * Post-conditions: populates the object
 * ********************************************************************************/
void Apartment::set_up_Apartment() {

	property_name = apartment_name();
	location = random_location();
	property_value = random_property_value('a');
	mortgage = random_mortgage();
	mortgage_turns = property_value / mortgage;
	property_tax = 0.015;

	num_tenants = (rand() % 10) + 1;
	num_rooms = num_tenants;

	tenants = new tenant[num_rooms];
	for (int i = 0; i < num_rooms; i++) {
		tenants[i] = new_tenant('c');
	}
}


/**********************************************************************************
 * Function: apartment_name
 * Description: generates a random name for an apartment complex
 * Parameters: none
 * Pre-conditions: property_names.txt is formatted as expected
 * Post-conditions: returns a string
 * ********************************************************************************/
string Apartment::apartment_name() {

	ifstream read;
	read.open("property_names.txt");

	int num = rand() % 20;
	string name = "";

	string ignore = "";
	while (ignore != "APARTMENT") {
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
 * Description: collects rent from tenants
 * Parameters: none
 * Pre-condtions: array of tenants has been created and populated
 * Post-conditions: returns an int
 * *******************************************************************************/
int Apartment::collect_rent() {

	int rent_collected = 0;

	for (int i = 0; i < num_rooms; i++) {
		if (tenants[i].type == "citizen" && tenants[i].budget >= rent) {
			rent_collected += rent;
		}

		else if (tenants[i].type == "citizen" && tenants[i].budget < rent) {
			if (tenants[i].agree == 1) {
				cout << tenants[i].name;
				cout << " refuses to pay rent and refuses ";
				cout << "to leave the Apartment Complex." << endl;
			}

			else {
				cout << tenants[i].name;
				cout << " can no longer afford to live in ";
				cout << "the apartment. They have moved out." << endl;
				tenants[i].type = "none";
				num_tenants--;
			}
		}
	}

	return rent_collected;
}


/**********************************************************************************
 * Function: set_rent_amount
 * Description: mutator for rent
 * Parameters: int new_rent
 * Pre-conditions: input must be a valid, positive int
 * Post-conditions: changes value of rent
 * *******************************************************************************/
void Apartment::set_rent_amount(int new_rent) {
	rent = new_rent;
}





