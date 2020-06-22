#ifndef BUSINESS_SPACE_H
#define BUSINESS_SPACE_H

#include "tenant.h"

using namespace std; 

struct business_space {
	char size;
	int rent_amount;
	tenant t;
};

#endif
