#include <iostream>
#include <string>
#include <vector>
#include "person.cpp"
#include "math.cpp"
using namespace std;

Math math;
vector<Person> person;

void addYear();
void makePerson(int, string);

int main(int argc, char const *argv[]) {
	makePerson(17, "Camden");
	makePerson(23, "Bob");
	for (int i = 0; i < people; ++i)
	{
		cout << person[i].get_name() << "'s age: " << person[i].get_age() << endl;
	}
	addYear();
	for (int i = 0; i < people; ++i)
	{
		cout << person[i].get_name() << "'s age: " << person[i].get_age() << endl;
	}
	cout << "Difference between " << person[0].get_name() << " and " << person[1].get_name() << "'s ages: " << math.difference(person[0].get_age(), person[1].get_age()) << " years.\n";
	cout << "Sum of " << person[0].get_name() << " and " << person[1].get_name() << "'s ages: " << math.sum(person[0].get_age(), person[1].get_age()) << " years.\n";
	return 0;
}

void addYear() {
	cout << "One year passes...\n";
	for (int i = 0; i < people; i++) {
		person[i].set_age(person[i].get_age()+1);
	}
}

void makePerson(int age, string name) {
	Person x(age, name);
	person.push_back(x);
}