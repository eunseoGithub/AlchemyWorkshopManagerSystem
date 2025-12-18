#include "PotionRecipe.h"

PotionRecipe::PotionRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
	potionName = name;
	this->ingredients = ingredients;
}