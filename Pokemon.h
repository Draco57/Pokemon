#include <string>
#include <unordered_set>
#include "Attack.h"
#include "Type.h"
#include "Status.h"

#pragma once
class Pokemon
{
private:
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

// battle attributes
public:
	int currentHP;
	Attack attack1;
	Attack attack2;
	Attack attack3;
	Attack attack4;
	Status currentStatus;
	std::unordered_set<V_Status> volStatus;
	std::unordered_set<B_Status> battleStatus;

public:
	// default constuctor for Pokemon
	Pokemon();

	// custom constructor for Pokemon
	Pokemon(int id, std::string name, std::string ability, Type primary, Type secondary, int HP, int ATK, int DEF, int SPATK, int SPDEF, int SPD, float weight);

	// converts the enums into string type
	std::string typeString(Type type);

	//print out stats of Pokemon
	void printStats();

// battle methods
public:

	void changeStatus(Status status);
	void addVolatileStatus(V_Status status);
	void addBattleStatus(B_Status status);

	// mold breaker/teravolt/turboblze case
	void changeStatusMB(Status status);
	void addVolatileStatusMB(V_Status status);
};

