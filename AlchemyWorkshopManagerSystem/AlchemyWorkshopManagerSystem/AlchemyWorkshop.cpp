#include "AlchemyWorkshop.h"

void AlchemyWorkshop::addRecipe(const std::string& name, const std::vector<std::string>& ingredients) 
{
    recipeManager.addRecipe(name, ingredients);
    stockManager.InitializeStock(name);
    std::cout << ">> 새로운 레시피 '" << name << "'이(가) 추가되었습니다." << std::endl;

}

void AlchemyWorkshop::displayAllRecipes()
{
    vector<PotionRecipe> recipe = recipeManager.getAllRecipes();

    if (recipe.empty())
    {
        std::cout << "아직 등록된 레시피가 없습니다." << std::endl;
        return;
    }

    std::cout << "\n--- [ 전체 레시피 목록 ] ---" << std::endl;
    for (size_t i = 0; i < recipe.size(); ++i)
    {
        std::cout << "- 물약 이름: " << recipe[i].potionName << std::endl;
        std::cout << "  > 필요 재료: ";
        // 재료 목록을 순회하며 출력
        for (size_t j = 0; j < recipe[i].ingredients.size(); ++j)
        {
            std::cout << recipe[i].ingredients[j];
            // 마지막 재료가 아니면 쉼표로 구분
            if (j < recipe[i].ingredients.size() - 1)
            {
                std::cout << ", ";
            }
        }
        std::cout << std::endl;
        std::cout << "개수 : " << stockManager.GetStock(recipe[i].potionName) << std::endl;
    }
    std::cout << "---------------------------\n";
}

PotionRecipe AlchemyWorkshop::searchRecipeByName(string name)
{
    return recipeManager.searchRecipeByName(name);
}
vector<PotionRecipe> AlchemyWorkshop::searchRecipeByIngredient(string ingredient)
{
    return recipeManager.searchRecipeByIngredient(ingredient);
}

StockManager AlchemyWorkshop::GetStockManager()
{
    return stockManager;
}