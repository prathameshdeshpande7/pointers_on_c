#include<stdio.h>
#include "inventor.h"

int main()
{
	Invrec *record;
	record = create_subassy_record(10);

	discard_inventory_record(record);
}
