#include "RecipeManager.h"

void RecipeManager::addRecipe(const std::string& name, const std::vector<std::string>& ingredients)
{
    if (!recipes.empty())
    {
        auto it = find_if(recipes.begin(), recipes.end(), [name](const PotionRecipe& recipe)
            {
                return recipe.potionName == name;
            });
        if (it != recipes.end())
        {
            cout << "이미 레시피가 존재합니다" << endl;
            return;
        }
    }

    recipes.push_back(PotionRecipe(name, ingredients));
    //stockManager.InitializeStock(name);
    //std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;

}
const vector<PotionRecipe>& RecipeManager::getAllRecipes()
{
    return recipes;
}
PotionRecipe RecipeManager::searchRecipeByName(string name)
{
    auto it = find_if(recipes.begin(), recipes.end(), [name](const PotionRecipe& recipe)
        {
            return recipe.potionName == name;
        });
    if (it != recipes.end())
    {
        return *it;
    }
    else
    {
        cout << "찾으시는 레시피가 존재하지 않습니다" << endl;
        return PotionRecipe{};
    }
}
vector<PotionRecipe> RecipeManager::searchRecipeByIngredient(string ingredient)
{
    vector<PotionRecipe> ingredientRecipe;
    for (int i = 0; i < recipes.size(); i++)
    {
        auto it = find(recipes[i].ingredients.begin(), recipes[i].ingredients.end(), ingredient);
        if (it != recipes[i].ingredients.end())
        {
            ingredientRecipe.push_back(recipes[i]);
        }
    }
    if (ingredientRecipe.size() == 0)
        cout << "재료가 포함된 레시피가 존재하지 않습니다" << endl;
    return ingredientRecipe;
}