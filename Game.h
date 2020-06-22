#include <iostream>
#include "Property.h"
#include "House.h"
#include "Apartment.h"
#include "Business.h"
#include "helper.h"

using namespace std;

class Game {
	private:
		int bank;
		int num_turns;

		int num_owned_Houses;
		House* owned_Houses;

		int num_owned_Apartments;
		Apartment* owned_Apartments;

		int num_owned_Businesses;
		Business* owned_Businesses;

		House* available_Houses;
		Apartment* available_Apartments;
		Business* available_Businesses;
	public:

		Game();
		~Game();
		Game(const Game&);
		const Game& operator=(const Game&);

		int get_bank() const;
		int get_num_turns() const;

		int get_num_owned_Houses() const;
		House get_owned_House(int) const;

		int get_num_owned_Apartments() const;
		Apartment get_owned_Apartment(int) const;

		int get_num_owned_Businesses() const;
		Business get_owned_Business(int) const;

		House get_available_House(int) const;
		Apartment get_available_Apartment(int) const;
		Business get_available_Business(int) const;
		void set_up();

		void add_House(House);
		void add_Apartment(Apartment);
		void add_Business(Business);

		void replenish_House(int);
		void replenish_Apartment(int);
		void replenish_Business(int);

		void print_game_stats();
		void take_turn(bool&);
		int collect_rent();
		int pay_mortgage();
		float pay_property_taxes();

		void random_event();
		void affected_Houses(string, string, float);
		void affected_Apartments(string, string, float);
		void affected_Businesses(string, string, float);
		void hurricane();
		void tornado();
		void earthquake();
		void wildfire();
		void stock_market_crash();
		void gentrification();	

		void buy_property();
		void set_rent_House(House&);
		void set_rent_Apartment(Apartment&);
		void set_rent_Business(Business&);

		void sell_property();
		void sell_price(float);
		void sell_House();
		bool remove_House(int);
		void sell_Apartment();
		bool remove_Apartment(int);
		void sell_Business();
		bool remove_Business(int);

		void adjust_rent();
		void adjust_rent_House();
		void adjust_rent_Apartment();
		void adjust_rent_Business();
};
