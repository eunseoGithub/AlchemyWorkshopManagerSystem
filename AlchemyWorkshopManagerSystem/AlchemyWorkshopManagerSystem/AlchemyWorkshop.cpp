#include "AlchemyWorkshop.h"

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) 
{
    recipes.push_back(PotionRecipe(name, ingredients));
    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;
}

void AlchemyWorkshop::displayAllRecipes() const
{
    if (recipes.empty()) 
    {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipes.size(); ++i) 
    {
        std::cout << "- 물약 이름: " << recipes[i].potionName << std::endl;
        std::cout << "  > 필요 재료: ";

        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipes[i].ingredients.size(); ++j) 
        {
            std::cout << recipes[i].ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipes[i].ingredients.size() - 1) 
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << "---------------------------\n";
}

PotionRecipe AlchemyWorkshop::searchRecipeByName(string name)
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
vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(string ingredient)
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