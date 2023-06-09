#pragma once
#include "Attack.h"
#include "Status.h"
class DamageAttack : Attack
{
private:
	int power;
	float acc;
	std::vector<int> status;
	std::vector<float> chance;

public:
	DamageAttack();
	DamageAttack(std::string name, Type type, Category category, int power, float acc);
	void ApplyEffects(Pokemon p);

};

