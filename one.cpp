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
		double getXP() const {
			return XP;
		}
	private:
		double XP = 1.0;
};

class Enemy : public Actor {
	public:
		void setLevel(int value) {
			Level = value;
		}
		int getLevel() const {
			return Level;
		}
		double DmgMlt = Level * 1.5;
	private:
		double Level = 1.0;
};

Player player;

void attack(Enemy &enemy) {
	srand(time(NULL));
	double atk = (double)rand() / (RAND_MAX + 1);
	cout << "You attack, dealing " << atk << " damage!\n";
	enemy.setHealth(enemy.getHealth()-atk);
	cout << "Enemy health: " << enemy.getHealth() << ".\n";
}

int flee(int enemy_level) {
	int chance = rand()%(1000-enemy_level);
	if (chance >= 500) {
		cout << "You escaped!\n";
		return 1;
	} else {
		cout << "You were caught!\n";
		return 2;
	}
}

void fight(Enemy &enemy) {
	cout << "Level " << enemy.getLevel() << " " << enemy.getName() << " has appeared!\nEnemy health: " << enemy.getHealth() << "\n";
	while(enemy.getHealth() > 0) {
		cout << "\t1. Attack\t2. Flee\t>>";
		int input;
		cin >> input;
		if (input == 1) {
			attack(enemy);
		} else if (input == 2) {
			switch(flee(enemy.getLevel())) {
				case 1:
					break;
			}
		} else {
			cout << "Invalid option.\n";
		}
	}
	if (enemy.getHealth() <= 0) {
		int xp_won = 10 * enemy.getLevel();
		player.addXP(xp_won);
		cout << "You defeated the " << enemy.getName() << "!\n";
		cout << xp_won << " XP earned! Current XP: " << player.getXP() << ".\n";
	}
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
	fight(zombie);
	return 0;
}