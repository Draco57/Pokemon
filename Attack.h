#pragma once
#include <string>
#include "Type.h"
#include "Category.h"

class Attack
{
private:
	std::string name;
	Type type;
	Category category;

public:
	Attack();
	Attack(std::string name, Type type, Category category);
	
};

