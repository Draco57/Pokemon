#include "Pokemon.h"
#include <iostream>

	// default constuctor for Pokemon
	Pokemon::Pokemon() {
		id = 0;
		name = "Pokemon";
		primary = NORMAL;
		secondary = NEUTRAL;
		HP = 100;
		ATK = 100;
		DEF = 100;
		SPATK = 100;
		SPDEF = 100;
		SPD = 100;
		weight = 100;
		ability = "Run Away";
	}

	// custom constructor for Pokemon
	Pokemon::Pokemon(int id, std::string name, std::string ability, Type primary, Type secondary, int HP, int ATK, int DEF, int SPATK, int SPDEF, int SPD, float weight) {
		this->id = id;
		this->name = name;
		this->ability = ability;
		this->primary = primary;
		this->secondary = secondary;
		this->HP = HP;
		this->ATK = ATK;
		this->DEF = DEF;
		this->SPATK = SPATK;
		this->SPDEF = SPDEF;
		this->SPD = SPD;
		this->weight = weight;
	}

	// converts the enums into string type
	std::string Pokemon::typeString(Type type) {
		switch (type) {
		case 1:
			return "Fire";
		case 2:
			return "Water";
		case 3:
			return "Grass";
		case 4:
			return "Electric";
		case 5:
			return "Ice";
		case 6:
			return "Steel";
		case 7:
			return "Dark";
		case 8:
			return "Ghost";
		case 9:
			return "Dragon";
		case 10:
			return "Fairy";
		case 11:
			return "Ground";
		case 12:
			return "Rock";
		case 13:
			return "Normal";
		case 14:
			return "Bug";
		case 15:
			return "Psychic";
		case 16:
			return "Flying";
		case 17:
			return "Poison";
		case 18:
			return "Fighting";
		default:
			return "None";
		}
	}

	//print out stats of Pokemon
	void Pokemon::printStats() {
		std::cout << name << std::endl;
		if (typeString(secondary).compare("None") == 0) {
			std::cout << "Type: " << typeString(primary) << std::endl;
		}
		else {
			std::cout << "Type: " << typeString(primary) << "/" << typeString(secondary) << std::endl;
		}
		std::cout << "Ability: " << ability << std::endl;
		std::cout << "HP: " << HP << std::endl;
		std::cout << "ATK: " << ATK << std::endl;
		std::cout << "DEF: " << DEF << std::endl;
		std::cout << "SP.ATK: " << SPATK << std::endl;
		std::cout << "SP.DEF: " << SPDEF << std::endl;
		std::cout << "SPD: " << SPD << std::endl;
		std::cout << "Weighs " << weight << " kgs." << std::endl;
		std::cout << std::endl;
	}