#include <iostream>
#include <string>
#include <random>
#include <ctime>
using namespace std;

class Actor {
	public:
		void setName(string value) {
			Name = value;
		}
		string getName() const {
			return Name;
		}
		void setHealth(int value) {
			Health = value;
		}
		int getHealth() const {
			return Health;
		}
	private:
		string Name;
		int Health = 100;
};

class Player : public Actor {
	public:
		void addXP(int value) {
			XP += value;
		}
		int getXP() const {
			return XP;
		}
	private:
		int XP = 1;
};

class Enemy : public Actor {
	public:
		void setLevel(int value) {
			Level = value;
		}
		int getLevel() const {
			return Level;
		}
		int DmgMlt = Level * 1.5;
	private:
		int Level = 1;
};

Player player;

void attack(Enemy &enemy) {
	srand(time(NULL));
	int atk = rand()%(10*player.getXP()) + 1;
	cout << "You attack, dealing " << atk << " damage!\n";
	enemy.setHealth(enemy.getHealth()-atk);
	cout << "Enemy health: " << enemy.getHealth() << ".\n";
}

void flee(int enemy_level) {

}

void fight(Enemy &enemy) {
	cout << "Level " << enemy.getLevel() << " " << enemy.getName() << " has appeared!\nEnemy health: " << enemy.getHealth() << "\n";
	while(enemy.getHealth() > 0) {
		cout << "\t1. Attack\t2. Flee\t>>";
		int input;
		while(!(cin >> input)) {
			cout << "Invalid option.\n";
			cin >> input;
		}
		switch (input) {
			case 1:
				attack(enemy);
				break;
			case 2:
				flee(enemy.getLevel());
				break;
				break;
				break;
		}
	}
	player.addXP(2 * enemy.getLevel());
}

int main() {
	Enemy skeleton, zombie;
	skeleton.setName("Skeleton");
	zombie.setName("Zombie");
	string input;
	cout << "Welcome adventurer! What's your name? ";
	cin >> input;
	player.setName(input);
	cout << "Nice to meet you, " << player.getName() << "!\n";
	cout << "First mission: Kill this skeleton!\n";
	fight(skeleton);

	return 0;
}