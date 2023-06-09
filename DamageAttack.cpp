#include "DamageAttack.h"

DamageAttack::DamageAttack() {
	Attack("Tackle", NORMAL, PHYSICAL);
	power = 50;
	acc = 1;
}

DamageAttack::DamageAttack(std::string name, Type type, Category category, int power, float acc) {
	Attack(name, type, category);
	this->power = power;
}

void ApplyEffects(Pokemon p) {
	// inflict stats on p, based on status & chance vector
}