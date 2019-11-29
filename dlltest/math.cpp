class Math {
public:
	int difference(int x, int y) {
		int diff;
		if (x > y) {
			diff = x - y;
		} else {
			diff = y - x;
		}
		return diff;
	}
	int sum(int x, int y) {
		return (x + y);
	}
};