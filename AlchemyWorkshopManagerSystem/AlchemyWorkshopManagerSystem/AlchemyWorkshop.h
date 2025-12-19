#pragma once
#include<vector>
#include<string>
#include<iostream>
#include<algorithm>
#include "PotionRecipe.h"
#include "StockManager.h"
#include "RecipeManager.h"
using namespace std;

class AlchemyWorkshop {
private:
    StockManager stockManager;
    RecipeManager recipeManager;
public:
    // addRecipe 메서드: 재료 목록(vector)을 매개변수로 받도록 수정
    void addRecipe(const std::string& name, const std::vector<std::string>& ingredients);
    // 모든 레시피 출력 메서드
    void displayAllRecipes();
    PotionRecipe searchRecipeByName(string name);
    vector<PotionRecipe> searchRecipeByIngredient(string ingredient);
    StockManager GetStockManager();
};

