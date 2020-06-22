#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>
#include "Property.h"
#include "business_space.h"

using namespace std;

class Business: public Property {
	private:
		int num_spaces; 
		business_space* spaces;
	public:
		Business();
		~Business();
		Business(const Business&);
		const Business& operator=(const Business&);

		int get_num_spaces() const;
		int get_num_tenants() const;
		business_space get_business_space(int) const;
		void set_rent_amount(int, int);

		void set_up_Business();
		int collect_rent();
		void print_property();
};

#endif
