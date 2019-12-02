#include <string>
#include <vector>

int people = 0;

class Person {
public:
	Person(int a, std::string n) {
		people++;
		age = a;
		name = n;
	}
	int get_age() {
		return age;
	}
	void set_age(int a) {
		age = a;
	}
	std::string get_name() {
		return name;
	}
private:
	int age;
	std::string name;
};