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

	void Pokemon::changeStatusMB(Status status) {
		if (currentStatus == HEALTHY) {
			if (status == BURN && (primary != FIRE && secondary != FIRE)) {
				currentStatus = status;
				return;
			}
			if (status == PARALYSIS && (primary != ELECTRIC && secondary != ELECTRIC)) {
				currentStatus = status;
				return;
			}
			if (status == FREEZE && (primary != ICE && secondary != ICE)) {
				currentStatus = status;
				return;
			}
			if (status == POISONED && ((primary != POISON && secondary != POISON) && (primary != STEEL && secondary != STEEL))) {
				currentStatus = status;
				return;
			}
			if (status == BAD_POISONED && ((primary != POISON && secondary != POISON) && (primary != STEEL && secondary != STEEL))) {
				currentStatus = status;
				return;
			}
			currentStatus = status;
		}	
	}

	void Pokemon::addVolatileStatusMB(V_Status status) {
		// ghost types cannot be trapped
		if (status == TRAPPED && (primary != GHOST && secondary != GHOST)) {
			volStatus.insert(status);
			return;
		}
		if (status == TELEKINESIS && (volStatus.find(GROUNDED) == volStatus.end())) {
			volStatus.insert(status);
			return;
		}
		if (status == SEEDED && (primary != GRASS && secondary != GRASS)) {
			volStatus.insert(status);
			return;
		}
		if (!(status != SEEDED || status == TELEKINESIS || status == TRAPPED)) {
			volStatus.insert(status);
			return;
		}
		std::cout << name << " is not affected!";
	}
	// Handle type change seperately from other volatile status

	void Pokemon::addBattleStatus(B_Status status) {
		battleStatus.insert(status);
	}

	void Pokemon::changeStatus(Status status) {
		// Comatose and Purifying Salt mons cannot be statused
		if (currentStatus == HEALTHY || ability.compare("Comatose") == 0 || ability.compare("Purifying Salt")) {
			if (status == BURN && (primary != FIRE && secondary != FIRE)) {
				// Water Veil and Water Bubble Mons cannot be burned
				if (ability.compare("Water Veil") != 0 && ability.compare("Water Bubble")) {
					currentStatus = status;
				}
				return;
			}
			if (status == PARALYSIS && (primary != ELECTRIC && secondary != ELECTRIC)) {
				// Limber mons cannot be paralyzed
				if (ability.compare("Limber") != 0) {
					currentStatus = status;
				}
				return;
			}
			if (status == FREEZE && (primary != ICE && secondary != ICE)) {
				// Magma armor mons cannot be frozen
				if (ability.compare("Magma Armor") != 0) {
					currentStatus = status;
				}
				return;
			}
			if (status == POISONED && ((primary != POISON && secondary != POISON) && (primary != STEEL && secondary != STEEL))) {
				// Immunity mons cannot be poisoned
				if (ability.compare("Immunity") != 0) {
					currentStatus = status;
				}
				return;
			}
			if (status == BAD_POISONED && ((primary != POISON && secondary != POISON) && (primary != STEEL && secondary != STEEL))) {
				// Immunity mons cannot be badly poisoned
				if (ability.compare("Immunity") != 0) {
					currentStatus = status;
				}
				return;
			}
			// Insomnia mons cannot be slept
			if (status == SLEEP && ability.compare("Insomnia") != 0) {
				currentStatus = status;
			}
		}
		std::cout << name << " is not affected!";
	}

	void Pokemon::addVolatileStatus(V_Status status) {
		// ghost types cannot be trapped
		if (status == TRAPPED && (primary != GHOST && secondary != GHOST)) {
			volStatus.insert(status);
			return;
		}
		if (status == TELEKINESIS && (volStatus.find(GROUNDED) == volStatus.end())) {
			volStatus.insert(status);
			return;
		}
		volStatus.insert(status);
	}