#include "Attack.h"

Attack::Attack() {
	name = "Tackle";
	type = NORMAL;
	category = PHYSICAL;
}

Attack::Attack(std::string name, Type type, Category category) {
	this->name = name;
	this->type = type;
	this->category = category;
}