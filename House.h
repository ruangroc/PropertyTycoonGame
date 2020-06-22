#ifndef HOUSE_H
#define HOUSE_H

#include <iostream>
#include <fstream>
#include "helper.h"
#include "Property.h"

using namespace std;

class House: public Property {
	private:
		tenant t;
	public:
		House();
		tenant get_tenant() const;
		string get_name() const;
		void set_rent_amount(int);
		void set_up_House();
		string house_name();
		int collect_rent();
};

#endif
