#include "weapon.h"
#include <stdlib.h>
#include <time.h>

//Constructor for creating custom weapon
Weapon::Weapon(std::string name, int element, int power) {
	weaponName = name;
	weaponElement = element;
	weaponPower = power;
}

//Default constructor
Weapon::Weapon() {
	weaponElement = rand() % 4;//Assigns a weapon element type from 0-3, corresponding to fire, frost, arcane, or poison, respectively.

	weaponName = weapon_name(weaponElement);//Sets weapon name

	weaponPower = 50 + 50 * (rand() % 3);//Assigns a weapon power from 50-150, in increments of 50
}

//Function to set weapon name based on element type
std::string Weapon::weapon_name(int element) {
	std::string elementName;
	std::string weaponType;

	int randElementName = rand() % 4;//There are 4 possible element names within each type
	int randWeaponType = rand() % 6;//Assigns a weapon type from 0-5, corresponding to axe, crossbow, flail, mace, staff, or sword, respectively.
	int randWeapon = rand() % 4;//There are 4 possible weapons in each weapon type category

	//Elemental Type Names
	std::string fire [4] = { "Cinder", "Smoldering", "Infernal", "Fiery" };
	std::string frost [4] = { "Frosted", "Frozen", "Crystalline", "Icy" };
	std::string arcane [4] = { "Spellbound", "Hypnotic", "Magical", "Enchanted" };
	std::string poison [4] = { "Spiteful", "Venomous", "Blighted", "Toxic" };

	//Weapon Type Names
	std::string axe [4] = { "Axe", "Broadaxe", "Cleaver", "Hatchet" };
	std::string crossbow [4] = { "Crossbow", "Ballista", "Longbow", "Arbalest" };
	std::string flail [4] = { "Flail", "Chain", "Thresher", "Lash" };
	std::string mace [4] = { "Mace", "Hammer", "Gavel", "Crusher" };
	std::string staff [4] = { "Staff", "Ward", "Scepter", "Quarterstaff" };
	std::string sword [4] = { "Sword", "Edge", "Blade", "Saber" };

	//Set element name
	if ( element == 0 ) {
		elementName = fire[randElementName];
	} else if ( element  == 1 ) {
		elementName = frost[randElementName];
	} else if ( element  == 2 ) {
		elementName = arcane[randElementName];
	} else {
		elementName = poison[randElementName];
	}

	//Set weapon type
	if ( randWeaponType == 0 ) {
		weaponType = axe[randWeapon];
	} else if ( randWeaponType == 1 ) {
		weaponType = crossbow[randWeapon];
	} else if ( randWeaponType == 2 ) {
		weaponType = flail[randWeapon];
	} else if ( randWeaponType == 3 ) {
		weaponType = mace[randWeapon];
	} else if ( randWeaponType == 4 ) {
		weaponType = staff[randWeapon];
	} else {
		weaponType = sword[randWeapon];
	}

	return elementName + " " + weaponType;
}

//Returns weapon name
std::string Weapon::get_name() {
	return weaponName;
}

//Returns weapon element
int Weapon::get_element() {
	return weaponElement;
}

//Returns weapon attack power
int Weapon::get_power() {
	return weaponPower;
}