#include "Business.h"

using namespace std;

/*********************************************************************************
 * Function: Business constructor
 * Description: initializes variables in a new Business object
 * Parameters: none
 * Pre-conditions: new Business object
 * Post-conditions: initializes variables
 * ******************************************************************************/
Business::Business() {

	num_spaces = 0;
	num_tenants = 0;
	spaces = NULL;
}


/*********************************************************************************
 * Function: Business destructor
 * Description: deletes dynamic memory
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: deletes dynamic memory
 * *******************************************************************************/
Business::~Business() {

	if (spaces != NULL) {
		delete [] spaces;
	}
}


/*********************************************************************************
 * Function: Business copy constructor
 * Description: makes a deep copy of a Business object
 * Parameters: const Business & other
 * Pre-conditions: copying into a new Business object
 * Post-conditions: makes a deep copy
 * *******************************************************************************/
Business::Business(const Business & other):Property(other) {

	num_spaces = other.get_num_spaces();
	num_tenants = other.get_num_tenants();

	spaces = new business_space[num_spaces];
	for (int i = 0; i < num_spaces; i++) {
		spaces[i] = other.get_business_space(i);
	}
}


/**********************************************************************************
 * Function: Business assignment operator overload
 * Description: makes a deep copy of a Business object
 * Parameters: const Business & other
 * Pre-conditions: none
 * Post-conditions: makes a deep copy
 * *******************************************************************************/
const Business& Business::operator=(const Business & other) {

	Property::operator=(other);

	if (spaces != NULL) {
		delete [] spaces;
	}

	num_spaces = other.get_num_spaces();
	num_tenants = other.get_num_tenants();

	spaces = new business_space[num_spaces];
	for (int i = 0; i < num_spaces; i++) {
		spaces[i] = other.get_business_space(i);
	}
}


/**********************************************************************************
 * Function: accessors
 * Description: returns variables from private section
 * Parameters: int index for the array
 * Pre-conditions: variables have values
 * Post-conditions: returns a business_space or an int
 * *******************************************************************************/
business_space Business::get_business_space(int index) const {
	return spaces[index];
}

int Business::get_num_spaces() const {
	return num_spaces;
}


int Business::get_num_tenants() const {
	return num_tenants;
}


/*********************************************************************************
 * Function: set_up_Business
 * Description: populates a Business object
 * Parameters: none
 * Pre-conditions: initialized Business object
 * Post-conditions: populates object
 * ******************************************************************************/
void Business::set_up_Business() {

	location = random_location();
	property_value = random_property_value('b');
	mortgage = random_mortgage();
	mortgage_turns = property_value / mortgage;
	property_tax = 0.015;

	num_tenants = (rand() % 5) + 1;
	num_spaces = num_tenants;
	spaces = new business_space[num_spaces];
	for (int i = 0; i < num_spaces; i++) {

		int num = rand() % 3;
		if (num == 0) {
			spaces[i].size = 'S';
		}
		else if (num == 1) {
			spaces[i].size = 'M';
		}
		else if (num == 2) {
			spaces[i].size = 'L';
		}
		
		spaces[i].t = new_tenant('b');
		spaces[i].rent_amount = 0;
	}
}


/*********************************************************************************
 * Function: collect_rent
 * Description: collects rent from businesses in the complex
 * Parameters: none
 * Pre-conditions: array of business spaces has been created and populated
 * Post-conditions: returns an int
 * ******************************************************************************/
int Business::collect_rent() {

	int rent_collected = 0;

	for (int i = 0; i < num_spaces; i++) {
		if (spaces[i].t.type == "business" && 
		    spaces[i].t.budget >= spaces[i].rent_amount) {
			rent_collected += spaces[i].rent_amount;
			property_value += (property_value * 0.01);
		} 

		else if (spaces[i].t.type == "business" &&
			 spaces[i].t.budget < spaces[i].rent_amount) {

			if (spaces[i].t.agree == 1) {
				cout << spaces[i].t.name;
				cout << " refuses to pay rent and refuses ";
				cout << "to leave the business complex." << endl;
			}

			else {
				cout << spaces[i].t.name;
				cout << " can no longer afford to stay in ";
				cout << "the business complex. Thay have moved out.";
				cout << endl;
				spaces[i].t.type = "none";
				spaces[i].t.name = "none";
				num_tenants--;
			}
		}
	}

	return rent_collected;
}


/**********************************************************************************
 * Function: set_rent_amount
 * Description: mutator for rent amount in a business_space in Business
 * Parameters: int index, int new_rent
 * Pre-conditions: populated objects, need to know which space adjusting rent for
 * Post-conditions: changes value of rent_amount
 * *******************************************************************************/
void Business::set_rent_amount(int index, int new_rent) {
	spaces[index].rent_amount = new_rent;
}


/**********************************************************************************
 * Function: print_property
 * Description: redefines print_property for Business
 * Parameters: none
 * Pre-conditions: populated Business object
 * Post-conditions: prints to screen 
 * ********************************************************************************/
void Business::print_property() {

	cout << "Property Value: " << property_value << " | ";
	cout << "Location: " << location << " | ";
	cout << "Number of tenants: " << num_tenants << endl;
	cout << "Mortgage: " << mortgage << " | ";
	cout << "Number of months left to pay off mortgage: " << mortgage_turns;
	cout << endl;

	if (spaces[0].rent_amount != 0) {
		for (int i = 0; i < num_spaces; i++) {
			cout << "Rent for space " << i+1 << ": ";
			cout << spaces[i].rent_amount << " | ";
			cout << "Occupied by: " << spaces[i].t.name << endl;
		}
	}
}




