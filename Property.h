#ifndef PROPERTY_H
#define PROPERTY_H

#include <iostream>
#include <string>
#include <fstream>
#include "tenant.h"
#include "helper.h"

using namespace std;

class Property {
	protected:
		string property_name;
		float property_value;
		string location;
		float mortgage;
		int mortgage_turns;
		float property_tax;
		int num_tenants;
		float rent;
	public:
		Property();

		float get_property_value();
		string get_location();
		float get_mortgage();
		int get_mortgage_turns();
		float get_property_tax();
		int get_num_tenants();
		float get_rent();

		string random_location();
		float random_property_value(char);
		float random_mortgage();

		void print_property();

		tenant new_tenant(char);
		string citizen_name();
		string business_name();

		int pay_mortgage();

		void set_property_value(float);
};

#endif
