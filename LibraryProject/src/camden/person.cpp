#include <string>

class Person {
	public:
		Person(int a, const char* n) {
			age = a;
			name = n;
		}
		int get_age() {
			return age;
		}
		const char* get_name() {
			return name;
		}
	private:
		int age;
		const char* name;
};
/*
Person::Person(int a, const char* n) {

}

int Person::get_age() {
	return age;
}

const char* Person::get_name() {
	return name;
}
*/