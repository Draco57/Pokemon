#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#define PRINT(X) std::cout << X << " ";
#define PRINTLN(X) std::cout << X << std::endl;
#define MAX_LINES 2000
#define TOTAL 1195

enum Type {
	NEUTRAL, FIRE, WATER, GRASS, ELECTRIC, ICE, STEEL, DARK, GHOST, DRAGON, FAIRY, GROUND, ROCK, NORMAL, BUG, PSYCHIC, FLYING, POISON, FIGHTING
};

class Pokemon {
	
public:
	int id;
	std::string name;
	Type primary, secondary;
	int HP;
	int ATK;
	int DEF;
	int SPATK;
	int SPDEF;
	int SPD;
	float weight;
	std::string ability;

public:
	// default constuctor for Pokemon
	Pokemon() {
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
	Pokemon(int id, std::string name, std::string ability, Type primary, Type secondary, int HP, int ATK, int DEF, int SPATK, int SPDEF, int SPD, float weight) {
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
	std::string typeString(Type type) {
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
	void printStats() {
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
};

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
