#pragma once
#include<string>
#include<vector>
#include<algorithm>
#include<iostream>
#include"PotionRecipe.h"

using namespace std;

class RecipeManager
{
public:
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    const vector<PotionRecipe>& getAllRecipes();
    PotionRecipe searchRecipeByName(string name);
    vector<PotionRecipe> searchRecipeByIngredient(string ingredient);
private:
    vector<PotionRecipe> recipes;
};

