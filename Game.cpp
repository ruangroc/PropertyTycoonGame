#include "Game.h"

using namespace std;

/*********************************************************************************
 * Function: Game constructor
 * Description: initializes all variables/pointers in new Game object
 * Paramters: none
 * Pre-conditions: new Game object
 * Post-conditions: initializes object
 * *******************************************************************************/
Game::Game() {

	bank = 500000;
	num_turns = 0;
	num_owned_Houses = 0;
	owned_Houses = NULL;
	num_owned_Apartments = 0;
	owned_Apartments = NULL;
	num_owned_Businesses = 0;
	owned_Businesses = NULL;
	available_Houses = NULL;
	available_Apartments = NULL;
	available_Businesses = NULL;
}


/**********************************************************************************
 * Function: Game destructor
 * Description: deletes dynamic memory in a Game object
 * Parameters: none
 * Pre-conditions: none
 * Post-conditions: deletes dynamic memory
 * ********************************************************************************/
Game::~Game() {

	if (owned_Houses != NULL) {
		delete [] owned_Houses;
	}

	if (owned_Apartments != NULL) {
		delete [] owned_Apartments;
	}

	if (owned_Businesses != NULL) {
		delete [] owned_Businesses;
	}
	
	if (available_Houses != NULL) {
		delete [] available_Houses;
	}

	if (available_Apartments != NULL) {
		delete [] available_Apartments;
	}

	if (available_Businesses != NULL) {
		delete [] available_Businesses;
	}
}


/********************************************************************************
 * Function: Game copy constructor
 * Description: makes a deep copy of a Game object
 * Parameters: const Game & other
 * Pre-conditions: must pass a new Game object by const reference
 * Post-conditions: makes a deep copy of a Game object
 * *****************************************************************************/
Game::Game(const Game & other) {

	bank = other.get_bank();
	num_turns = other.get_num_turns();

	num_owned_Houses = other.get_num_owned_Houses();
	owned_Houses = new House[num_owned_Houses];
	for (int i = 0; i < num_owned_Houses; i++) {
		owned_Houses[i] = other.get_owned_House(i);
	}

	num_owned_Apartments = other.get_num_owned_Apartments();
	owned_Apartments = new Apartment[num_owned_Apartments];
	for (int i = 0; i < num_owned_Apartments; i++) {
		owned_Apartments[i] = other.get_owned_Apartment(i);
	}

	num_owned_Businesses = other.get_num_owned_Businesses();
	owned_Businesses = new Business[num_owned_Businesses];
	for (int i = 0; i < num_owned_Businesses; i++) {
		owned_Businesses[i] = other.get_owned_Business(i);
	}

	for (int i = 0; i < 3; i++) {
		available_Houses[i] = other.get_available_House(i);
		available_Apartments[i] = other.get_available_Apartment(i);
		available_Businesses[i] = other.get_available_Business(i);
	}
}


/*********************************************************************************
 * Function: Game assignment operator overload
 * Description: makes a deep copy for a Game oject
 * Paramters: const Game & other
 * Pre-conditions: none
 * Post-conditions: makes a deep copy
 * ******************************************************************************/
const Game& Game::operator=(const Game& other) {

	if (owned_Houses != NULL) {
		delete [] owned_Houses;
	}

	if (owned_Apartments != NULL) {
		delete [] owned_Apartments;
	}

	if (owned_Businesses != NULL) {
		delete [] owned_Businesses;
	}
	
	if (available_Houses != NULL) {
		delete [] available_Houses;
	}

	if (available_Apartments != NULL) {
		delete [] available_Apartments;
	}

	if (available_Businesses != NULL) {
		delete [] available_Businesses;
	}

	bank = other.get_bank();
	num_turns = other.get_num_turns();

	num_owned_Houses = other.get_num_owned_Houses();
	owned_Houses = new House[num_owned_Houses];
	for (int i = 0; i < num_owned_Houses; i++) {
		owned_Houses[i] = other.get_owned_House(i);
	}

	num_owned_Apartments = other.get_num_owned_Apartments();
	owned_Apartments = new Apartment[num_owned_Apartments];
	for (int i = 0; i < num_owned_Apartments; i++) {
		owned_Apartments[i] = other.get_owned_Apartment(i);
	}

	num_owned_Businesses = other.get_num_owned_Businesses();
	owned_Businesses = new Business[num_owned_Businesses];
	for (int i = 0; i < num_owned_Businesses; i++) {
		owned_Businesses[i] = other.get_owned_Business(i);
	}

	for (int i = 0; i < 3; i++) {
		available_Houses[i] = other.get_available_House(i);
		available_Apartments[i] = other.get_available_Apartment(i);
		available_Businesses[i] = other.get_available_Business(i);
	}
}


/**********************************************************************************
 * Function: accessors
 * Description: returns the Game's private variables
 * Parameters: none
 * Pre-conditions: variables have values
 * Post-conditions: returns a value (float, int, House, Apt, Business)
 * *******************************************************************************/
int Game::get_bank() const {
	return bank;
}

int Game::get_num_turns() const {
	return num_turns;
}

int Game::get_num_owned_Houses() const {
	return num_owned_Houses;
}

House Game::get_owned_House(int index) const {
	return owned_Houses[index];
}

int Game::get_num_owned_Apartments() const {
	return num_owned_Apartments;
}

Apartment Game::get_owned_Apartment(int index) const {
	return owned_Apartments[index];
}

int Game::get_num_owned_Businesses() const {
	return num_owned_Businesses;
}

Business Game::get_owned_Business(int index) const {
	return owned_Businesses[index];
}

House Game::get_available_House(int index) const {
	return available_Houses[index];
}

Apartment Game::get_available_Apartment(int index) const {
	return available_Apartments[index];
}

Business Game::get_available_Business(int index) const {
	return available_Businesses[index];
}


/********************************************************************************
 * Function: set_up
 * Description: populates a Game object for the real estate tycoon game
 * Parameters: none
 * Pre-conditions: Game object initialized
 * Post-conditions: populates a Game object
 * ******************************************************************************/
void Game::set_up() {

	bank = 500000.00;

	available_Houses = new House[3];
	available_Apartments = new Apartment[3];
	available_Businesses = new Business[3];

	for (int i = 0; i < 3; i++) {
		available_Houses[i].set_up_House();
		available_Apartments[i].set_up_Apartment();
		available_Businesses[i].set_up_Business();
	}
}


/**********************************************************************************
 * Function: print_game_stats
 * Description: prints player's status (bank account and owned properties)
 * Parameters: none
 * Pre-conditions: Game object populated
 * Post-conditions: prints to screen
 * ********************************************************************************/
void Game::print_game_stats() {

	cout << endl <<"*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*"<< endl;
	cout << "\033[36mMONTH " << num_turns << " UPDATE \033[0m" << endl;
	cout << "Bank account: " << bank << endl;

	cout << endl << "You own " << num_owned_Houses << " Houses" << endl;
	for (int i = 0; i < num_owned_Houses; i++) {
		cout << "---------------------------------------------" << endl;
		owned_Houses[i].print_property();
	}
	cout << "---------------------------------------------" << endl;
	
	cout << endl << "You own " << num_owned_Apartments << " Apartment Complexes";
	cout << endl;
	for (int i = 0; i < num_owned_Apartments; i++) {
		cout << "---------------------------------------------" << endl;
		owned_Apartments[i].print_property();
	}
	cout << "---------------------------------------------" << endl;

	cout << endl << "You own " << num_owned_Businesses << " Business Complexes";
	cout << endl;
	for (int i = 0; i < num_owned_Businesses; i++) {
		cout << "---------------------------------------------" << endl;
		owned_Businesses[i].print_property();
	}
	cout << "*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*-*-*-*" <<endl;
}


/**********************************************************************************
 * Function: take_turn
 * Description: allows user to take a turn (plays a new month)
 * Parameters: bool & play_game
 * Pre-conditions: input must be a bool for the while loop game is in
 * Post-conditions: prints to screen and allows player to do things
 * *******************************************************************************/
void Game::take_turn(bool & play_game) {

	num_turns++;

	cout << endl << endl << "\033[32mCollecting rent... \033[0m" << endl;
	int collected = collect_rent();
	bank += collected;
	cout << "\033[32mTotal rent collected: \033[0m" << collected << endl;

	cout << endl << "Paying mortgage..." << endl;
	int payment = pay_mortgage();
	bank -= payment;
	cout << "\033[35mMortgage payment total: \033[0m" << payment << endl;

	if (num_turns % 12 == 0) {
		cout << endl << "Paying property taxes..." << endl;
		float taxes = pay_property_taxes();
		bank -= taxes;
		cout << "\033[35mTotal taxes paid: \033[0m" << taxes << endl;
	}

	random_event();
	print_game_stats();

	if (bank <= 0 || bank >= 1000000) {
		play_game = false;
		return;
	}

	bool end_turn = false;
	string option = "";
	do {
		cout << endl << "What would you like to do?" << endl;
		cout << "(1) buy a property " << endl;
		cout << "(2) sell a property" << endl;
		cout << "(3) adjust rent on a property" << endl;
		cout << "(4) or end the turn" << endl;
		cout << "Selection: ";
		cin >> option;
		cin.ignore();
		cin.clear();
	} while (check_option(option) == false);

	if (option == "1") {
		buy_property();
	}

	else if (option == "2") {
		sell_property();
	}

	else if (option == "3") {
		adjust_rent();
	}

	else if (option == "4") {
		end_turn = true;
	}
}


/**********************************************************************************
 * Function: collect_rent
 * Description: goes through each owned property and collects rent
 * Parameters: none
 * Pre-condtions: arrays created and populated
 * Post-conditions: adds to bank account
 * *******************************************************************************/
int Game::collect_rent() {

	int rent_collected = 0;

	for (int i = 0; i < num_owned_Houses; i++) {
		cout << "Collecting rent from " << owned_Houses[i].get_name();
		cout << ":" << endl;
		rent_collected += owned_Houses[i].collect_rent();
	}

	for (int i = 0; i < num_owned_Apartments; i++) {
		cout << "Collecting rent from " << owned_Apartments[i].get_name();
		cout << ":" << endl;
		rent_collected += owned_Apartments[i].collect_rent();
	}

	for (int i = 0; i < num_owned_Businesses; i++) {
		cout << "Collecting rent from Business Complex " << (i+1);
		cout << ":" << endl;
		rent_collected += owned_Businesses[i].collect_rent();
	}

	return rent_collected;
}


/**********************************************************************************
 * Function: pay_mortgage
 * Description: goes through each owned property to pay mortgage on each
 * Parameters: none
 * Pre-conditions: arrays created and populated
 * Post-conditions: subtracts from bank account
 * *******************************************************************************/
int Game::pay_mortgage() {

	int payment = 0;

	for (int i = 0; i < num_owned_Houses; i++) {
		payment += owned_Houses[i].pay_mortgage();
	}

	for (int i = 0; i < num_owned_Apartments; i++) {
		payment += owned_Apartments[i].pay_mortgage();
	}

	for (int i = 0; i < num_owned_Businesses; i++) {
		payment += owned_Businesses[i].pay_mortgage();
	}

	return payment;
}


/*********************************************************************************
 * Function: pay_property_taxes
 * Description: goes through each owned property and pays property taxes on each
 * Parameters: none
 * Pre-conditions: arrays created and populated
 * Post-conditions: subtracts from bank account
 * ******************************************************************************/
float Game::pay_property_taxes() {

	float payment = 0.0;

	for (int i = 0; i < num_owned_Houses; i++) {
		payment += owned_Houses[i].get_property_value() * 0.15;
	}

	for (int i = 0; i < num_owned_Apartments; i++) {
		payment += owned_Apartments[i].get_property_value() * 0.15;
	}
	
	for (int i = 0; i < num_owned_Businesses; i++) {
		payment += owned_Businesses[i].get_property_value() * 0.15;
	}

	return payment;
}


/*********************************************************************************
 * Function: add_House
 * Description: adds a House to the owned_Houses array
 * Parameters: House add
 * Pre-conditions: must pass in the House object to add to the array
 * Post-conditions: adds a House to the owned_Houses array
 ********************************************************************************/
void Game::add_House(House add) {

	House* temp = new House[num_owned_Houses + 1];
	for (int i = 0; i < num_owned_Houses; i++) {
		temp[i] = owned_Houses[i];
	}

	temp[num_owned_Houses] = add;

	delete [] owned_Houses;
	owned_Houses = temp;
	num_owned_Houses++;
}


/***********************************************************************************
 * Function: add_Apartment
 * Description: adds an Apartment to the owned_Apartments array
 * Parameters: Apartment add
 * Pre-conditions: must pass in the Apartment object to add to the array
 * Post-conditions: adds an Apartment to the owned_Apartments array
 * ********************************************************************************/
void Game::add_Apartment(Apartment add) {

	Apartment* temp = new Apartment[num_owned_Apartments + 1];
	for (int i = 0; i < num_owned_Apartments; i++) {
		temp[i] = owned_Apartments[i];
	}

	temp[num_owned_Apartments] = add;

	delete [] owned_Apartments;
	owned_Apartments = temp;
	num_owned_Apartments++;
}


/**********************************************************************************
 * Function: add_Business
 * Description: adds a Business to the owned_Businesses array
 * Parameters: Business add
 * Pre-conditions: must pass in the Business object to add to the array
 * Post-conditions: adds a Business to the owned_Businesses array
 * ********************************************************************************/
void Game::add_Business(Business add) {

	Business* temp = new Business[num_owned_Businesses + 1];
	for (int i = 0; i < num_owned_Businesses; i++) {
		temp[i] = owned_Businesses[i];
	}

	temp[num_owned_Businesses] = add;

	delete [] owned_Businesses;
	owned_Businesses = temp;
	num_owned_Businesses++;
}


/**********************************************************************************
 * Function: replenish_House
 * Description: creates a new House object for the available_Houses array
 * Parameters: int index
 * Pre-conditions: need the index for the replacement
 * Post-conditions: changes one of the Houses in the available_Houses array
 * *******************************************************************************/
void Game::replenish_House(int index) {

	House h;
	h.set_up_House();
	available_Houses[index] = h;
}


/**********************************************************************************
 * Function: replenish_Apartment
 * Description: creates a new Apartment object for the available_Apartments array
 * Parameters: int index
 * Pre-conditions: need the index for the replacement
 * Post-conditions: changes one of the Apartments in the available_Apartments array
 * *******************************************************************************/
void Game::replenish_Apartment(int index) {

	Apartment a;
	a.set_up_Apartment();
	available_Apartments[index] = a;
}


/**********************************************************************************
 * Function: replenish_Business
 * Description: creates a new Business object for the available_Businesses array
 * Parameters: int index
 * Pre-conditions: need the index for the replacement
 * Post-conditions: changes one of the Businesses in the available_Businesses array
 * *******************************************************************************/
void Game::replenish_Business(int index) {

	Business b;
	b.set_up_Business();
	available_Businesses[index] = b;
}


/********************************************************************************
 * Function: buy_property
 * Description: allows player to buy a property
 * Parameters: none
 * Pre-conditions: arrays of available properties created and populated
 * Post-condition: prints options to screen and potentially adds a property
 * *****************************************************************************/
void Game::buy_property() {

	cout << endl << "Here are some properties that are for sale:" << endl;

	int random1 = rand() % 3;
	House h = available_Houses[random1];
	cout << endl << "House" << endl << "--------------------------" << endl;
	h.print_property();
	cout << endl;

	int random2 = rand() % 3;
	Apartment a = available_Apartments[random2];
	cout << endl << "Apartment Complex" << endl;
	cout << "----------------------------" << endl;
	a.print_property();
	cout << endl;

	int random3 = rand() % 3;
	Business b = available_Businesses[random3];
	cout << endl << "Business Complex" << endl;
	cout << "----------------------------" << endl; 
	b.print_property();
	cout << endl;

	string option = "";
	do {
		cout << endl << "Would you like to:" << endl;
		cout << "(1) Buy the House" << endl;
		cout << "(2) Buy the Apartment Complex" << endl;
		cout << "(3) Buy the Business Complex " << endl;
		cout << "(4) Buy something next time" << endl;
		cout << "Selection: ";
		cin >> option;
		cin.ignore();
		cin.clear();
	} while (check_option(option) == false);

	if (option == "1") {
		set_rent_House(h);
		add_House(h);
		replenish_House(random1);
	}

	else if (option == "2") {
		set_rent_Apartment(a);
		add_Apartment(a);
		replenish_Apartment(random2);
	}

	else if (option == "3") {
		set_rent_Business(b);
		add_Business(b);
		replenish_Business(random3);
	}
	
	else if (option == "4") {
		cout << "We'll see you at the real estate office next time!" << endl;
	}
}


/*********************************************************************************
 * Function: set_rent_House
 * Description: allows user to set rent on a House they just bought
 * Parameters: none
 * Pre-conditions: newly bought House (rent still at 0)
 * Post-conditions: sets rent to user input
 * ******************************************************************************/
void Game::set_rent_House(House & h) {

	cout << endl << "Congratulations on your new house!" << endl;

	string answer = "";
	do {
		cout << "What would you like to set the rent to? ";
		cout << "Please enter a whole number: ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false);

	int new_rent = string_to_int(answer);
	h.set_rent_amount(new_rent);
}


/*********************************************************************************
 * Function: set_rent_Apartment
 * Description: allows user to set rent on an Apartment Complex they just bought
 * Parameters: none
 * Pre-conditions: newly bought Apartment (rent still at 0)
 * Post-conditions: sets rent to user input
 * ******************************************************************************/
void Game::set_rent_Apartment(Apartment & a) {

	cout << endl << "Congratulations on your new Apartment Complex!" << endl;

	string answer = "";
	do {
		cout << "What would you like to set the rent to? ";
		cout << "Please enter a whole number: ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false);

	int new_rent = string_to_int(answer);
	a.set_rent_amount(new_rent);
}


/*********************************************************************************
 * Function: set_rent_Business
 * Description: allows user to set rent on a Business Complex they just bought
 * Parameters: none
 * Pre-conditions: newly bought Business (rent still at 0)
 * Post-conditions: sets rent to user input
 * *******************************************************************************/
void Game::set_rent_Business(Business & b) {

	cout << endl << "Congratulations on your new Business Complex!" << endl;
	cout << "There are " << b.get_num_spaces() << " business spaces ";
	cout << "to set rent for." << endl;

	string answer = "";
	int new_rent = 0;
	for (int i = 0; i < b.get_num_spaces(); i++) {
		do {
			cout << "Please set the rent for one of them by ";
			cout << "entering a whole number: ";
			cin >> answer;
			cin.ignore();
			cin.clear();
		} while (check_numbers(answer) == false);

		new_rent = string_to_int(answer);
		b.set_rent_amount(i, new_rent);
	}
}


/**********************************************************************************
 * Function: sell_property
 * Description: allows user to sell a vacant property
 * Parameters: none
 * Pre-conditions: player owns at least one house
 * Post-conditions: removes a house from an owned array and adds to bank
 * *******************************************************************************/
void Game::sell_property() {

	string answer = "";
	do {
		cout << endl << "Would you like to:" << endl;
		cout << "(1) Sell a House" << endl;
		cout << "(2) Sell an Apartment Complex" << endl;
		cout << "(3) Sell a Business Complex" << endl;
		cout << "(4) Not sell anything" << endl;
		cout << "Selection: ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_option(answer) == false);

	if (answer == "1") {
		if (num_owned_Houses == 0) {
			cout << "You don't own any houses!" << endl;
		}
		else if (num_owned_Houses > 0) {
			sell_House();
		}
	}

	else if (answer == "2") {
		if (num_owned_Apartments == 0) {
			cout << "You don't own any apartment complexes!" << endl;
		}
		else if (num_owned_Apartments > 0) {
			sell_Apartment();
		}
	}

	else if (answer == "3") {
		if (num_owned_Businesses == 0) {
			cout << "You don't own any business complexes!" << endl;
		}
		else if (num_owned_Businesses > 0) {
			sell_Business();
		}
	}

	else if (answer == "4") {
		cout << "We'll see you at the real estate office next time!" << endl;
	}
}


/*********************************************************************************
 * Function: sell_price
 * Description: allows user to set asking price 
 * Parameters: float property_value
 * Pre-conditons: property being sold has a property value
 * Post-conditons: adds an amount to the bank
 * ******************************************************************************/
void Game::sell_price(float property_value) {

	string answer = "";
	do {	
		cout << endl <<  "Please enter an asking price: ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false);

	int asking_price = string_to_int(answer);

	int random = rand() % 3;

	if (random == 0) {
		cout << "\033[32mYou received the asking price! \033[0m" << endl;
		bank += asking_price;
	}

	else if (random == 1) {
		cout << "\033[32mYou received the property value: ]033[0m";
		cout << property_value << endl;
		bank += property_value;
	}

	else if (random == 2) {
		cout << "\033[32mYou received 10 percent less than property ";
		cout << "value: " << (property_value * 0.9) << "\033[0m" << endl;
		bank += (property_value * 0.9);
	}
}


/**********************************************************************************
 * Function: sell_House
 * Description: allows user to sell a House
 * Parameters: none
 * Pre-conditions: owned_Houses has at least one house
 * Post-conditions: removes a House, adds to bank
 * *******************************************************************************/
void Game::sell_House() {

	cout << endl << "Here are the houses you currently own:" << endl;
	for (int i = 0; i < num_owned_Houses; i++) {
		cout << endl <<  "House Number " << (i+1) << endl;
		cout << "-----------------------------------------------" << endl;
		owned_Houses[i].print_property();
	}

	string answer = "";
	do {
		cout << "Which house would you like to sell? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false || 
		 string_to_int(answer) > num_owned_Houses);

	int remove_index = (string_to_int(answer) - 1);
	int sell_property_value = owned_Houses[remove_index].get_property_value();
	if (remove_House(remove_index) == true) {
		sell_price(sell_property_value);
	}
}


/**********************************************************************************
 * Function: remove_House
 * Description: removes a House from owned_Houses
 * Paramters: int remove_index
 * Pre-conditions: owned_Houses array has a house at given index
 * Post-conditions: removes House from owned_Houses
 * *******************************************************************************/
bool Game::remove_House(int remove_index) {

	if (owned_Houses[remove_index].get_num_tenants() != 0) {
		cout << "Oops! You can't sell this house. ";
		cout << "Someone is living there!" << endl;
		return false;
	}

	else {
		House* temp = new House[num_owned_Houses - 1];
		int index = 0;
		for (int i = 0; i < num_owned_Houses; i++) {
			if (i != remove_index) {
				temp[index] = owned_Houses[i];
				index++;
			}
		}

		delete [] owned_Houses;
		owned_Houses = temp;
		num_owned_Houses--;
	}

	return true;
}


/**********************************************************************************
 * Function: sell_Apartment
 * Description: allows user to sell an Apartment
 * Parameters: none
 * Pre-conditions: owned_Apartments has at least one Apartment
 * Post-conditions: removes an Apartment, adds to bank
 * *******************************************************************************/
void Game::sell_Apartment() {

	cout << endl;
	cout << "Here are the apartment complexes you currently own:" << endl;
	for (int i = 0; i < num_owned_Apartments; i++) {
		cout << endl << "Apartment Complex Number " << (i+1) << endl;
		cout << "-----------------------------------------------" << endl;
		owned_Apartments[i].print_property();
	}

	string answer = "";
	do {
		cout << "Which apartment complex would you like to sell? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false || 
		 string_to_int(answer) > num_owned_Apartments);

	int remove_index = string_to_int(answer) - 1;
	int sell_property_value =owned_Apartments[remove_index].get_property_value();
	if (remove_Apartment(remove_index) == true) {
		sell_price(sell_property_value);
	}
}


/**********************************************************************************
 * Function: remove_Apartment
 * Description: removes an Apartment from owned_Apartments
 * Paramters: int remove_index
 * Pre-conditions: owned_Apartments array has an Apartment at given index
 * Post-conditions: removes Apartment from owned_Apartments
 * *******************************************************************************/
bool Game::remove_Apartment(int remove_index) {

	if (owned_Apartments[remove_index].get_num_tenants() != 0) {
		cout << "Oops! You can't sell this apartment complex. ";
		cout << "Someone is living there!" << endl;
		return false;
	}

	else {
		Apartment* temp = new Apartment[num_owned_Apartments - 1];
		int index = 0;
		for (int i = 0; i < num_owned_Apartments; i++) {
			if (i != remove_index) {
				temp[index] = owned_Apartments[i];
				index++;
			}
		}

		delete [] owned_Apartments;
		owned_Apartments = temp;
		num_owned_Apartments--;
	}

	return true;
}


/**********************************************************************************
 * Function: sell_Business
 * Description: allows user to sell a Business
 * Parameters: none
 * Pre-conditions: owned_Businesses has at least one Business
 * Post-conditions: removes a Business, adds to bank
 * *******************************************************************************/
void Game::sell_Business() {

	cout << endl << "Here are the business complexes you currently own:" << endl;
	for (int i = 0; i < num_owned_Businesses; i++) {
		cout << endl << "Business Complex Number " << (i+1) << endl;
		cout << "-----------------------------------------------" << endl;
		owned_Businesses[i].print_property();
	}

	string answer = "";
	do {
		cout << "Which business complex would you like to sell? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false || 
		 string_to_int(answer) > num_owned_Businesses);

	int remove_index = string_to_int(answer) - 1;
	int sell_property_value =owned_Businesses[remove_index].get_property_value();
	if (remove_Business(remove_index) == true) {
		sell_price(sell_property_value);
	}
}


/**********************************************************************************
 * Function: remove_Business
 * Description: removes a Business from owned_Businesses
 * Paramters: int remove_index
 * Pre-conditions: owned_Businesses array has a Business at given index
 * Post-conditions: removes a Business from owned_Businesses
 * *******************************************************************************/
bool Game::remove_Business(int remove_index) {

	if (owned_Businesses[remove_index].get_num_tenants() != 0) {
		cout << "Oops! You can't sell this business complex. ";
		cout << "There is still a business there!" << endl;
		return false;
	}

	else {
		Business* temp = new Business[num_owned_Businesses - 1];
		int index = 0;
		for (int i = 0; i < num_owned_Businesses; i++) {
			if (i != remove_index) {
				temp[index] = owned_Businesses[i];
				index++;
			}
		}

		delete [] owned_Businesses;
		owned_Businesses = temp;
		num_owned_Businesses--;
	}

	return true;
}


/**********************************************************************************
 * Function: adjust_rent
 * Description: allows user to adjust rent on a property they own
 * Parameters: none
 * Pre-conditions: player owns at least one property
 * Post-conditions: changes rent value of the property chosen
 * ********************************************************************************/
void Game::adjust_rent() {

	string answer = "";
	do {
		cout << endl << "Would you like to adjust rent on:" << endl;
		cout << "(1) a House" << endl;
		cout << "(2) an Apartment Complex" << endl;
		cout << "(3) a Business Complex" << endl;
		cout << "(4) or go back" << endl;
		cout << "Selection: ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_option(answer) == false);

	if (answer == "1") {
		if (num_owned_Houses == 0) {
			cout << "You don't own any houses!" << endl;
		}
		else if (num_owned_Houses > 0) {
			adjust_rent_House();
		}
	}

	else if (answer == "2") {
		if (num_owned_Apartments == 0) {
			cout << "You don't own any apartment complexes!" << endl;
		}
		else if (num_owned_Apartments > 0) {
			adjust_rent_Apartment();
		}
	}

	else if (answer == "3") {
		if (num_owned_Businesses == 0) {
			cout << "You don't own any business complexes!" << endl;
		}
		else if (num_owned_Businesses > 0) {
			adjust_rent_Business();
		}
	}

	else if (answer == "4") {
		cout << "We'll see you at the real estate office next time!" << endl;
	}
}


/*********************************************************************************
 * Function: adjust_rent_House
 * Description: adjusts rent for an owned House
 * Parameters: none
 * Pre-conditions: owned_Houses has at least one House
 * Post-conditions: changes rent amount for a House
 * ******************************************************************************/
void Game::adjust_rent_House() {

	cout << endl << "Here are the houses you currently own:" << endl;
	for (int i = 0; i < num_owned_Houses; i++) {
		cout << endl <<  "House Number " << (i+1) << endl;
		cout << "-----------------------------------------------" << endl;
		owned_Houses[i].print_property();
	}

	string answer = "";
	do {
		cout << endl << "Which house would you like to adjust rent for? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false || 
		 (string_to_int(answer) > num_owned_Houses));

	int index = string_to_int(answer) - 1;
	
	do {
		cout << "What would you like to set the rent to? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false);

	int new_rent = string_to_int(answer);

	owned_Houses[index].set_rent_amount(new_rent);
}


/*********************************************************************************
 * Function: adjust_rent_Apartment
 * Description: adjusts rent for an owned Apartment
 * Parameters: none
 * Pre-conditions: owned_Apartments has at least one Apartment
 * Post-conditions: changes rent amount for an Apartment
 * ******************************************************************************/
void Game::adjust_rent_Apartment() {

	cout << endl;
	cout << "Here are the apartment complexes you currently own:" << endl;
	for (int i = 0; i < num_owned_Apartments; i++) {
		cout << endl << "Apartment Complex Number " << (i+1) << endl;
		cout << "-----------------------------------------------" << endl;
		owned_Apartments[i].print_property();
	}

	string answer = "";
	do {
		cout << endl << "Which apartment complex would you like to ";
		cout << "adjust rent for? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false || 
		 string_to_int(answer) > num_owned_Apartments);

	int index = string_to_int(answer) - 1;

	do {
		cout << "What would you like to set the rent to? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false);

	int new_rent = string_to_int(answer);

	owned_Apartments[index].set_rent_amount(new_rent);
}


/*********************************************************************************
 * Function: adjust_rent_Business
 * Description: adjusts rent for an owned Business
 * Parameters: none
 * Pre-conditions: owned_Businesses has at least one Business
 * Post-conditions: changes rent amount for a Business
 * ******************************************************************************/
void Game::adjust_rent_Business() {

	cout << endl << "Here are the business complexes you currently own:" << endl;
	for (int i = 0; i < num_owned_Businesses; i++) {
		cout << endl << "Business Complex Number " << (i+1) << endl;
		cout << "-----------------------------------------------" << endl;
		owned_Businesses[i].print_property();
	}

	string answer = "";
	do {
		cout << endl;
		cout << "Which business complex would you like to adjust rent for? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false || 
		 string_to_int(answer) > num_owned_Businesses);

	int index = string_to_int(answer) - 1;

	do {
		cout << "Which space would you like to change the rent of? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false &&
		 string_to_int(answer) > owned_Businesses[index].get_num_spaces());

	int space = string_to_int(answer) - 1;

	do {
		cout << "What would you like to set the rent to? ";
		cin >> answer;
		cin.ignore();
		cin.clear();
	} while (check_numbers(answer) == false);

	int new_rent = string_to_int(answer);

	owned_Businesses[index].set_rent_amount(space, new_rent);
}


/**********************************************************************************
 * Function: random_event
 * Description: random event occurs and impacts property values
 * Parameters: none
 * Pre-conditions: arrays of properties created and popualted
 * Post-conditions: changes property values
 * *******************************************************************************/
void Game::random_event() {

	int num = rand() % 6;

	if (num == 0) {
		hurricane();
	}

	else if (num == 1) {
		tornado();
	}

	else if (num == 2) {
		earthquake();
	}

	else if (num == 3) {
		wildfire();
	}

	else if (num == 4) {
		stock_market_crash();
	}

	else if (num == 5) {
		gentrification();
	}
}


/********************************************************************************
 * Function: affected_Houses
 * Description: changes property value of Houses meeting criteria
 * Parameters: string location, string change, float percent_change
 * Pre-conditions: must know affected location, whether the change is positive or negative, and the percent change
 * *****************************************************************************/
void Game::affected_Houses(string location, string change, float percent_change) {

	for (int i = 0; i < num_owned_Houses; i++) {
		if (owned_Houses[i].get_location() == location) {

			float value = owned_Houses[i].get_property_value();
			float amt_change = value * percent_change;

			if (change == "increase") {
				float new_value = value + amt_change;
				owned_Houses[i].set_property_value(new_value);
			}

			else if (change == "decrease") {
				float new_value = value - amt_change;
				owned_Houses[i].set_property_value(new_value);
			}	
		} 
	}

	for (int i = 0; i < 3; i++) {
		if (available_Houses[i].get_location() == location) {

			float value = available_Houses[i].get_property_value();
			float amt_change = value * percent_change;

			if (change == "increase") {
				float new_value = value + amt_change;
				available_Houses[i].set_property_value(new_value);
			}

			else if (change == "decrease") {
				float new_value = value - amt_change;
				available_Houses[i].set_property_value(new_value);
			}	
		}
	}
}


/********************************************************************************
 * Function: affected_Apartments
 * Description: changes property value of Apartments meeting criteria
 * Parameters: string location, string change, float percent_change
 * Pre-conditions: must know affected location, whether the change is positive or negative, and the percent change
 * *****************************************************************************/
void Game::affected_Apartments(string location, string change, float percent_change){

	for (int i = 0; i < num_owned_Apartments; i++) {
		if (owned_Apartments[i].get_location() == location) {

			float value = owned_Apartments[i].get_property_value();
			float amt_change = value * percent_change;

			if (change == "increase") {
				float new_value = value + amt_change;
				owned_Apartments[i].set_property_value(new_value);
			}

			else if (change == "decrease") {
				float new_value = value - amt_change;
				owned_Apartments[i].set_property_value(new_value);
			}	
		} 
	}

	for (int i = 0; i < 3; i++) {
		if (available_Apartments[i].get_location() == location) {

			float value = available_Apartments[i].get_property_value();
			float amt_change = value * percent_change;

			if (change == "increase") {
				float new_val = value + amt_change;
				available_Apartments[i].set_property_value(new_val);
			}

			else if (change == "decrease") {
				float new_val = value - amt_change;
				available_Apartments[i].set_property_value(new_val);
			}	
		}
	}
}


/********************************************************************************
 * Function: affected_Businesses
 * Description: changes property value of Businesses meeting criteria
 * Parameters: string location, string change, float percent_change
 * Pre-conditions: must know affected location, whether the change is positive or negative, and the percent change
 * *****************************************************************************/
void Game::affected_Businesses(string location, string change, float percent_change){

	for (int i = 0; i < num_owned_Businesses; i++) {
		if (owned_Businesses[i].get_location() == location) {

			float value = owned_Businesses[i].get_property_value();
			float amt_change = value * percent_change;

			if (change == "increase") {
				float new_value = value + amt_change;
				owned_Businesses[i].set_property_value(new_value);
			}

			else if (change == "decrease") {
				float new_value = value - amt_change;
				owned_Businesses[i].set_property_value(new_value);
			}	
		} 
	}

	for (int i = 0; i < 3; i++) {
		if (available_Businesses[i].get_location() == location) {

			float value = available_Businesses[i].get_property_value();
			float amt_change = value * percent_change;

			if (change == "increase") {
				float new_val = value + amt_change;
				available_Businesses[i].set_property_value(new_val);
			}

			else if (change == "decrease") {
				float new_val = value - amt_change;
				available_Businesses[i].set_property_value(new_val);
			}	
		}
	}
}


/*********************************************************************************
 * Function: hurricane
 * Description: lowers property value of SE properties by 50%
 * Parameters: none
 * Pre-conditions: arrays of properties are populated
 * Post-conditions: alters property values
 * ******************************************************************************/
void Game::hurricane() {

	cout << endl << "\033[31mOh no! A hurricane has hit the SE region! \033[0m";
	cout << endl <<"Property values in the SE have been decreased by 50%"<< endl;

	affected_Houses("SE", "decrease", 0.5);
	affected_Apartments("SE", "decrease", 0.5);
	affected_Businesses("SE", "decrease", 0.5);
}


/*********************************************************************************
 * Function: tornado
 * Description: lowers property value of Midwest properties by 30%
 * Parameters: none
 * Pre-conditions: arrays of properties are populated
 * Post-conditions: alters property values
 * ******************************************************************************/
void Game::tornado() {

	cout << endl << "\033[31mOh no! A tornado has hit the Midwest region!";
	cout << "\033[0m" << endl;
	cout << "Property values in the Midwest have been decreased by 30%" << endl;

	affected_Houses("Midwest", "decrease", 0.3);
	affected_Apartments("Midwest", "decrease", 0.3);
	affected_Businesses("Midwest", "decrease", 0.3);
}


/*********************************************************************************
 * Function: earthquake
 * Description: lowers property value of NW properties to 10%
 * Parameters: none
 * Pre-conditions: arrays of properties are populated
 * Post-conditions: alters property values
 * ******************************************************************************/
void Game::earthquake() {

	cout << endl << "\033[31mOh no! An earthquake has hit the NW region!";
	cout << "\033[0m" << endl;
	cout << "Property values in the NW have been decreased by 90%" << endl;

	affected_Houses("NW", "decrease", 0.9);
	affected_Apartments("NW", "decrease", 0.9);
	affected_Businesses("NW", "decrease", 0.9);	
}


/*********************************************************************************
 * Function: wildfire
 * Description: lowers property value of SW properties by 25%
 * Parameters: none
 * Pre-conditions: arrays of properties are populated
 * Post-conditions: alters property values
 * ******************************************************************************/
void Game::wildfire() {

	cout << endl << "\033[31mOh no! A wildfire has hit the SW region! \033[0m";
	cout << endl <<"Property values in the SW have been decreased by 25%"<< endl;

	affected_Houses("SW", "decrease", 0.25);
	affected_Apartments("SW", "decrease", 0.25);
	affected_Businesses("SW", "decrease", 0.25);
}


/*********************************************************************************
 * Function: stock_market_crash
 * Description: lowers property value of all properties by 30%
 * Parameters: none
 * Pre-conditions: arrays of properties are populated
 * Post-conditions: alters property values
 * ******************************************************************************/
void Game::stock_market_crash() {

	cout << endl <<"\033[31mOh no! The stock market has crashed! \033[0m"<<endl;
	cout << "Property values everywhere have been decreased by 30%" << endl;

	affected_Houses("SE", "decrease", 0.3);
	affected_Apartments("SE", "decrease", 0.3);
	affected_Businesses("SE", "decrease", 0.3);

	affected_Houses("NE", "decrease", 0.3);
	affected_Apartments("NE", "decrease", 0.3);
	affected_Businesses("NE", "decrease", 0.3);

	affected_Houses("Midwest", "decrease", 0.3);
	affected_Apartments("Midwest", "decrease", 0.3);
	affected_Businesses("Midwest", "decrease", 0.3);

	affected_Houses("SW", "decrease", 0.3);
	affected_Apartments("SW", "decrease", 0.3);
	affected_Businesses("SW", "decrease", 0.3);

	affected_Houses("NW", "decrease", 0.3);
	affected_Apartments("NW", "decrease", 0.3);
	affected_Businesses("NW", "decrease", 0.3);
}


/*********************************************************************************
 * Function: gentrification
 * Description: increases property value of certain properties by 20%
 * Parameters: none
 * Pre-conditions: arrays of properties are populated
 * Post-conditions: alters property values
 * ******************************************************************************/
void Game::gentrification() {

	string region = "";
	int num = rand() % 5;

	if (num == 0) {
		region = "NE";	
	}
	else if (num == 1) {
		region = "SE";
	}
	else if (num == 2) {
		region = "Midwest";
	}
	else if (num == 3) {
		region = "SW";
	}
	else if (num == 4) {
		region = "NW";
	}

	int prompt = rand() % 3;

	if (prompt == 0) {
		cout << endl << "\033[94mA big business has moved into the ";
		cout << region << "\033[0m" << endl;
	}	
	else if (prompt == 1) {
		cout << endl << "\033[94mNew natural resource discovered in the ";
		cout << region << "\033[0m" << endl;
	}
	else if (prompt == 2) {
		cout << endl << "\033[94mThere's been positive press about the ";
		cout << region << "\033[0m" << endl;
	}

	cout << "Property values in the " << region;
	cout << " have been increased by 20%" << endl;

	affected_Houses(region, "increase", 0.2);
	affected_Apartments(region, "increase", 0.2);
	affected_Businesses(region, "increase", 0.2);
}



