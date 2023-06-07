#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "Pokemon.h"

#define PRINT(X) std::cout << X << " ";
#define PRINTLN(X) std::cout << X << std::endl;
#define MAX_LINES 2000
#define TOTAL 1195

Type getType(std::string type);
void generateRandomPokemon(Pokemon* pokemon);
void printAllPokemon(Pokemon* pokemon);
Pokemon* loadPokemon();

int main() {

	Pokemon* pokemon = loadPokemon();

	generateRandomPokemon(pokemon);
	//printAllPokemon(pokemon);
 
	// clear pokemon array memory
	delete[] pokemon;
	return 0;
}

// loads pokemon from csv file
Pokemon* loadPokemon() {
	std::string myFilePath = "PokeDB.csv";
	std::ifstream file(myFilePath);
	Pokemon* pokemon = new Pokemon[MAX_LINES];

	// checks if file read failed
	if (file.fail()) {
		std::cerr << "Unable to open file: " << myFilePath << std::endl;
	}

	std::string line = "";
	int index = 0;
	srand(time(0));
	// read the .csv file and fill up pokemon array
	// skip the first line
	std::getline(file, line);
	while (std::getline(file, line)) {
		int ID;
		std::string name;
		std::string ability;
		Type primary, secondary;
		int HP;
		int ATK;
		int DEF;
		int SPATK;
		int SPDEF;
		int SPD;
		float weight;

		std::stringstream inputString(line);

		std::string tempString = "";
		getline(inputString, tempString, ',');
		ID = atoi(tempString.c_str());
		tempString = "";

		getline(inputString, name, ',');

		getline(inputString, tempString, ',');
		primary = getType(tempString);
		tempString = "";

		getline(inputString, tempString, ',');
		secondary = getType(tempString);
		tempString = "";

		getline(inputString, tempString, ',');
		HP = atoi(tempString.c_str());
		tempString = "";

		getline(inputString, tempString, ',');
		ATK = atoi(tempString.c_str());
		tempString = "";

		getline(inputString, tempString, ',');
		DEF = atoi(tempString.c_str());
		tempString = "";

		getline(inputString, tempString, ',');
		SPATK = atoi(tempString.c_str());
		tempString = "";

		getline(inputString, tempString, ',');
		SPDEF = atoi(tempString.c_str());
		tempString = "";

		getline(inputString, tempString, ',');
		SPD = atoi(tempString.c_str());
		tempString = "";

		//skip stat total
		getline(inputString, tempString, ',');
		tempString = "";

		getline(inputString, tempString, ',');
		weight = (float)atof(tempString.c_str());
		tempString = "";

		//getline(inputString, ability);
		std::string ability1 = "", ability2 = "", hidden = "";

		getline(inputString, ability1, ',');
		getline(inputString, ability2, ',');
		getline(inputString, hidden, ',');

		// generate random ability from legal abilities
		if (hidden.size() == 0 && ability2.size() == 0) {
			ability = ability1;
		}
		else if (ability2.size() == 0) {
			int randNum = rand() % 2;
			ability = randNum == 0 ? ability1 : hidden;
		}
		else {
			int randNum = rand() % 3;
			ability = randNum == 0 ? ability1 : (randNum == 1 ? ability2 : hidden);
		}

		Pokemon tempPokemon(ID, name, ability, primary, secondary, HP, ATK, DEF, SPATK, SPDEF, SPD, weight);
		pokemon[index] = tempPokemon;
		index++;
	}
	return pokemon;
}

//print stats of n random pokemon
void generateRandomPokemon(Pokemon* pokemon) {
	int n = 0;
	std::cout << "How many random Pokemon do you want to generate: " << std::endl;

	std::cin >> n;
	//srand(time(0));
	for (int i = 0; i < n; i++) {
		int randNum = rand() % TOTAL;
		pokemon[randNum].printStats();
	}
}

//print all pokemon in DB
void printAllPokemon(Pokemon* pokemon) {
	for (int i = 0; i < TOTAL; i++) {
		pokemon[i].printStats();
	}
}
// converts a string Pokemon Type to the enum type
Type getType(std::string type) {
	if (type.compare("Fire") == 0) {
		return FIRE;
	}
	else if (type.compare("Water") == 0) {
		return WATER;
	}
	else if (type.compare("Grass") == 0) {
		return GRASS;
	}
	else if (type.compare("Electric") == 0) {
		return ELECTRIC;
	}
	else if (type.compare("Ice") == 0) {
		return ICE;
	}
	else if (type.compare("Fighting") == 0) {
		return FIGHTING;
	}
	else if (type.compare("Ghost") == 0) {
		return GHOST;
	}
	else if (type.compare("Dark") == 0) {
		return DARK;
	}
	else if (type.compare("Psychic") == 0) {
		return PSYCHIC;
	}
	else if (type.compare("Bug") == 0) {
		return BUG;
	}
	else if (type.compare("Fairy") == 0) {
		return FAIRY;
	}
	else if (type.compare("Steel") == 0) {
		return STEEL;
	}
	else if (type.compare("Poison") == 0) {
		return POISON;
	}
	else if (type.compare("Dragon") == 0) {
		return DRAGON;
	}
	else if (type.compare("Normal") == 0) {
		return NORMAL;
	}
	else if (type.compare("Ground") == 0) {
		return GROUND;
	}
	else if (type.compare("Flying") == 0) {
		return FLYING;
	}
	else if (type.compare("Rock") == 0) {
		return ROCK;
	}
	else {
		return NEUTRAL;
	}
}
