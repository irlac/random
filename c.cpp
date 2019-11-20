#include <iostream>
#include <stdlib.h>
#include <errno.h>
#include <limits.h>
#include <string>
using namespace std;

char *p;

class yeetmachine {
public:
	void start() {
		cout << phrase;
	}
private:
	string phrase = "Yeet\n";
};

void colour(int c) {
	switch (c) {
		case 1:
			cout << "\u001b[31m";
			break;
		default:
			break;
	}
}

int main(int argc, char** argv) {
	if (argc == 0) cout << "Error\n";
	yeetmachine a;
	errno = 0;
		long conva = strtol(argv[2], &p, 10);
		if (conva < 0) conva += (-2 * conva);
		if (errno != 0 || *p != '\0' || conva > INT_MAX) {
			cout << "Invalid input \"" << argv[2] << "\".\n";
		} else {
			int val = conva;    
	    	colour(val);
		}
		long conv = strtol(argv[1], &p, 10);
		if (conv < 0) conv += (-2 * conv);
		if (errno != 0 || *p != '\0' || conv > INT_MAX) {
			cout << "Invalid input \"" << argv[1] << "\".\n";
		} else {
			int val = conv;    
	    	for (int i = 0; i < val; i++) a.start();
		}
	cout << "\u001b[0m";
	return 0;
}