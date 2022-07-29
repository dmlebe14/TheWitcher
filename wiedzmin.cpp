#include <iostream>
#include <cmath>   
#include <string>
using namespace std;

enum Movement {walk, jog, run, gallop};
enum Enemies {humans, monsters};
enum Signs {Igni, Aard, Axii, Yrden, Quen};

class Human 
{
 
public: 
    
    string name;
    int age;
    float weight;
    float speed;
    Movement mov;
 
public: 
	Human();
	void getHuman();
	void changePerson(string name, int age, float weight);
	float getSpeed(Movement mov);
};

Human::Human()
{
	name = "Geralt of Rivia";
	age = 45;
	weight = 80;
	mov = walk;
}

void Human::getHuman()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight << endl;
}

void Human::changePerson(string new_name, int new_age, float new_weight)
{
	name = new_name;
	age = new_age;
	weight = new_weight;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight << endl;
}

float Human::getSpeed(Movement mov)
{
	if (mov == walk)
	speed = 1 + rand() % 7;
	else if (mov == jog)
	speed = 7 + rand() % 10;
	else if (mov == run)
	speed = 10 + rand() % 30;
	
	return speed;
}

class Horse 
{
 
public: 
    
    string name;
    int age;
    float weight;
    float speed;
    Movement mov;
 
public: 
	Horse();
	void getHorse();
	void changeHorse(string name, int age, float weight);
	float GetSpeed(Movement mov);
};

Horse::Horse()
{
	name = "Roach";
	age = 8;
	weight = 450;
	mov = walk;
}

void Horse::getHorse()
{
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight << endl;
}

void Horse::changeHorse(string new_name, int new_age, float new_weight)
{
	name = new_name;
	age = new_age;
	weight = new_weight;
	cout << "Name: " << name << endl;
	cout << "Age: " << age << endl;
	cout << "Weight: " << weight << endl;
}

float Horse::GetSpeed(Movement mov)
{
	if (mov == walk)
	speed = 1 + rand() % 7;
	else if (mov == jog)
	speed = 7 + rand() % 10;
	else if (mov == run)
	speed = 10 + rand() % 30;
	else
	speed = 30 + rand() % 65;

	return speed;
}

class Sword 
{
 
public: 

	string name;
	float weight;
	bool sharp;
	float length;
 
public: 
	Sword();
	bool IsItSharp(bool sharp);
	void changeSword(string new_name, bool new_sharp, float new_weight, float new_length);
	void getSword();
};

bool Sword::IsItSharp(bool sharp)
{
	if (sharp == true)
	cout << "The sword is sharp. " << endl;
	else
	cout << "The sword is blunt. " << endl;

	return sharp;
}	

Sword::Sword()
{
	name = "Aerondight";
	weight = 3;
	length = 1;
	sharp = true;
}

void Sword::changeSword(string new_name, bool new_sharp, float new_weight, float new_length)
{
	name = new_name;
	sharp = new_sharp;
	weight = new_weight;
	length = new_length;
	cout << "Name: " << name << endl;
	cout << "Weight: " << weight << endl;
	if (sharp == true)
	cout << name <<" is sharp." << endl;
	else
	cout << name <<" is blunt." << endl;

}

void Sword::getSword()
{
	cout << "Name: " << name << endl;
	cout << "Length: " << length << endl;
	cout << "Weight: " << weight << endl;
}

class SteelSword : public Sword
{
public:
	float damage;
	int level;
	Enemies foes; 
	
public:
	float GetDamage(float standard_damage, Enemies foe);
};

float SteelSword::GetDamage(float standard_damage, Enemies foes)
{
	damage = standard_damage;
	if (foes == monsters)
	{
	damage /= 2;
	}
	
	return damage;
}

class SilverSword : public Sword
{
public:
	float damage;
	int level;
	Enemies foes; 
	
public:
	float GetDamage(float standard_damage, Enemies foe);
};

float SilverSword::GetDamage(float standard_damage, Enemies foes)
{
	damage = standard_damage;
	if (foes == humans)
	{
	damage /= 2;
	}
	
	return damage;
}

class Witcher : public Human, virtual public SilverSword, virtual public SteelSword
{
public:
	float damage;
	int level;
	Signs sign; 
	float speed;
	
public:
	Witcher();
	void ChangeSign(int i);
	void GetSign();
	double GetDamage(float SilverSword_damage, float SteelSword_damage);
	void changeLevel(int i);
};

Witcher::Witcher()
{
	level = 1;
	sign = Aard;
	speed = Human::speed * 1.2;
}

void Witcher::changeLevel(int i)
{
	level = i;
}


double Witcher::GetDamage(float SilverSword_damage, float SteelSword_damage)
{
	SilverSword_damage *= level;
	SteelSword_damage *= level;
	
	if (SteelSword_damage >= SilverSword_damage)
	damage = SteelSword_damage;
	else
	damage = SilverSword_damage;

	return damage;
}

void Witcher::ChangeSign(int i)
{
	switch (i)
	{
		case 1:
		sign = Igni;
		cout << Human::name << " is now able to cast the fire" << endl;
		break;
		case 2:
		sign = Yrden;
		cout << Human::name << " is now able to set dangerous traps" << endl;
		break;
		case 3:
		sign = Axii;
		cout << Human::name << " is now able to affect minds of the others " << endl;
		break;
		case 4:
		sign = Quen;
		cout << Human::name << " is now able to create an impenetrable shield" << endl;
		break;
		default:
		sign = Aard;
		cout << "You decided not to change the Witcher's sign - it's still Aard" << endl;
		break;
	}
}

void Witcher::GetSign()
{
	switch (sign)
	{
		case Igni:
		cout << "Igni is now activated" << endl;
		break;
		case Aard:
		cout << "Aard is now activated" << endl;
		break;
		case Axii:
		cout << "Axii is now activated" << endl;
		break;
		case Yrden:
		cout << "Yrden is now activated" << endl;
		break;
		case Quen:
		cout << "Quen is now activated" << endl;
		break;
	}
}

class WitcherHorseman : virtual public Witcher, virtual public Horse // virtual введено для избежания ошибки мн. наследования методов
{
public:
	float damage;
	float speed;
	Movement mov;
	
public:
	WitcherHorseman();
	float GetDamage();
	float GetSpeed(Movement mov);
	
};

WitcherHorseman::WitcherHorseman()
{
	speed = 10;
	damage = 150;
}

float WitcherHorseman::GetDamage()
{
	return damage;
}

float WitcherHorseman::GetSpeed(Movement mov)
{
	if (mov == walk)
	speed = 1 + rand() % 7;
	else if (mov == jog)
	speed = 7 + rand() % 10;
	else if (mov == run)
	speed = 10 + rand() % 30;
	else
	speed = 30 + rand() % 65;

	return speed;
}

int main()
{	
	Movement mov;
	mov = walk;
	Signs sign;
	sign = Igni;
	Human man; Horse stallion; Witcher witcher; 
	Human();
	man.getHuman();
	Horse();
	stallion.getHorse();
	cout << "Horse's current speed is " << stallion.GetSpeed(mov) << " km/h" << endl;
	Witcher();
	witcher.GetSign();
	int i;
	cout << "Write down a number of a new sign" << endl;
	cin >> i;
	witcher.ChangeSign(i);
	witcher.GetSign();
	bool sharp = true;
	Sword sword;
	Sword();
	sword.getSword();
	sword.IsItSharp(sharp);
	Enemies foes;
	foes = monsters;
	SteelSword steel;
	float stnd_dmg = 12.5;
	cout << "Damage dealt by the steel sword is " << steel.GetDamage(stnd_dmg, foes) << " HP" << endl;
	if (foes == monsters)
	{
	cout << "The witcher's enemies are monsters" << endl;
	cout << "Switch your weapon to a silver sword" << endl;
	}
	foes = humans;
	SilverSword silver;
	cout << "Damage dealt by the silver sword is " << silver.GetDamage(stnd_dmg, foes) << " HP" << endl;
	if (foes == humans)
	{
	cout << "The witcher's enemies are humans" << endl;
	cout << "Switch your weapon to a steel sword" << endl;
	}
	witcher.changeLevel(10);
	cout << "Damage dealt on the 10th level by the steel sword is " << witcher.GetDamage(stnd_dmg, foes) << " HP" << endl;
	WitcherHorseman roach;
	WitcherHorseman();
	mov = gallop;
	cout << "Damage dealt by the Witcher on a horse is " << roach.GetDamage() << " HP" << endl;
	cout << "The Witcher's speed on a horse is " << roach.GetSpeed(mov) << " km/h" << endl;
	
}
