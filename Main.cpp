#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <unordered_map>
#include "Pokemon.h"

#define PRINT(X) std::cout << X << " ";
#define PRINTLN(X) std::cout << X << std::endl;
#define MAX_LINES 2000
#define TOTAL 1195

Type getType(std::string type);
void generateRandomPokemon(std::unordered_map<std::string, Pokemon> map, std::string pokemonNames[]);
void printAllPokemon(std::unordered_map<std::string, Pokemon> map, std::string pokemonNames[]);
void loadPokemon(std::unordered_map<std::string, Pokemon>& map, std::string pokemonNames[]);

int main() {

	std::unordered_map<std::string, Pokemon> pokeMap;
	std::string *pokeNames = new std::string[TOTAL];
	loadPokemon(pokeMap, pokeNames);

	//printAllPokemon(pokemon);
	bool keepGoing = true;
	std::string tempInput = "";
	int decision = -1;
	std::cout << "Hello Trainer!" << std::endl;
	while (keepGoing) {
		std::cout << "1. Generate Random Pokemon" << std::endl;
		std::cout << "2. Find Specific Pokemon" << std::endl;
		std::cout << "3. Print All Pokemon" << std::endl;
		std::cout << "4. Exit" << std::endl;
		getline(std::cin, tempInput);
		decision = std::atoi(tempInput.c_str());
		if (decision < 1 || decision > 4) {
			std::cout << "Invalid Input! Please enter a number between 1 and 4!" << std::endl;
		}
		else {
			if (decision == 1) {
				generateRandomPokemon(pokeMap, pokeNames);
			}
			else if (decision == 2) {
				std::string inputPokemon = "fakePoke";
				while (pokeMap.find(inputPokemon) == pokeMap.end()) {
					std::cout << "Please enter a valid Pokemon name: " << std::endl;
					getline(std::cin, inputPokemon);
				}
				std::cout << std::endl;
				pokeMap[inputPokemon].printStats();
			}
			else if (decision == 3) {
				printAllPokemon(pokeMap, pokeNames);
			}
			else{
				keepGoing = false;
				std::cout << "Thank you for using the PokeDB service! Have a nice day!" << std::endl;
			}
		}
	}
	// clear pokemon array memory
	delete [] pokeNames;
	return 0;
}

// loads pokemon from csv file
void loadPokemon(std::unordered_map<std::string, Pokemon> &map, std::string pokemonNames[]) {
	std::string myFilePath = "PokeDB.csv";
	std::ifstream file(myFilePath);

	// checks if file read failed
	if (file.fail()) {
		std::cerr << "Unable to open file: " << myFilePath << std::endl;
	}

	std::string line = "";
	srand(time(0));
	// read the .csv file and fill up pokemon array
	// skip the first line
	std::getline(file, line);
	int index = 0;
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
		map[name] = tempPokemon;
		pokemonNames[index] = name;
		index++;
	}
}

//print stats of n random pokemon
void generateRandomPokemon(std::unordered_map<std::string, Pokemon> map, std::string pokemonNames[]) {
	int n = 0;
	std::cout << "How many random Pokemon do you want to generate: " << std::endl;
	std::string tempInput = "";
	getline(std::cin, tempInput);
	n = atoi(tempInput.c_str());
	srand(time(0));
	for (int i = 0; i < n; i++) {
		int randNum = rand() % TOTAL;
		map[pokemonNames[randNum]].printStats();
	}
}

//print all pokemon in DB
void printAllPokemon(std::unordered_map<std::string, Pokemon> map, std::string pokemonNames[]) {
	for (int i = 0; i < TOTAL; i++) {
		map[pokemonNames[i]].printStats();
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
