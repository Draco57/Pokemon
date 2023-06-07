#include <string>
#pragma once
enum Type {
	NEUTRAL, FIRE, WATER, GRASS, ELECTRIC, ICE, STEEL, DARK, GHOST, DRAGON, FAIRY, GROUND, ROCK, NORMAL, BUG, PSYCHIC, FLYING, POISON, FIGHTING
};

class Pokemon
{
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
	Pokemon();

	// custom constructor for Pokemon
	Pokemon(int id, std::string name, std::string ability, Type primary, Type secondary, int HP, int ATK, int DEF, int SPATK, int SPDEF, int SPD, float weight);

	// converts the enums into string type
	std::string typeString(Type type);

	//print out stats of Pokemon
	void printStats();
};

