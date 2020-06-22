#ifndef APARTMENT_H
#define APARTMENT_H

#include <iostream>
#include <fstream>
#include "Property.h"
#include "tenant.h"

using namespace std;

class Apartment: public Property {
	private:
		int num_rooms;
		tenant* tenants;
	public: 
		Apartment();
		~Apartment();
		Apartment(const Apartment&);
		const Apartment& operator=(const Apartment&);

		int get_num_rooms() const;
		tenant get_tenant(int) const;
		int get_num_tenants() const;
		string get_name() const;
		void set_rent_amount(int);

		void set_up_Apartment();
		string apartment_name();
		int collect_rent();
};

#endif
