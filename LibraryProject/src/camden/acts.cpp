#include <iostream>
#include "person.h"
#include "person.cpp"

void run(Person p) {
	std::cout << p.get_name() << " is running!\n";
}