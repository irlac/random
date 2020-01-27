#include <iostream>
#include <vector>
using namespace std;

class Number {
	public:
		int digs(int);
		int divs(int);
		void prod(int);
		bool is_prime(int);	
};

int Number::digs(int x) {
	vector<int> dig;
	for (int i = 1; x / i > 0; i *= 10) {
		dig.push_back((x / i) % 10);
	}
	int sum = 0;
	for (int i = 0; i < dig.size(); i++) {
		sum += dig[i];
	}
	return sum;
}

int Number::divs(int x) {
	vector<int> div;
	for (int i = 1; i <= x; i++) {
		if (x % i == 0) {
			div.push_back(i);
		}
	}
	int sum = 0;
	for (int i = 0; i < div.size(); i++) {
		sum += div[i];
	}
	return sum;
}

void Number::prod(int x) {
	for (int i = 1; i <= x; i++) {
		if (is_prime(i)) {
			for (int n = 1; n <= x; n++) {
				if (is_prime(n)) {
					if (i * n == x) {
						cout << i << " * " << n << endl;
					}
				}
			}
		}
	}
}

bool Number::is_prime(int x) {
	int c = 0;
	for (int i = 2; i < x; i++) {
		if (x % i > 0) {
			c++;
		}
	}
	if (c == x-2) {
		return true;
	} else {
		return false;
	}
}

int main() {
	Number n;
	cout << n.digs(7) << endl;
	cout << n.divs(7) << endl;
	n.prod(7);
	return 0;
}