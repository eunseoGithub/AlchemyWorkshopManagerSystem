#include<iostream>
#include"PotionRecipe.h"
#include"AlchemyWorkshop.h"

int main()
{
    AlchemyWorkshop myWorkshop;

    while (true) 
    {
        std::cout << "⚗️ 연금술 공방 관리 시스템" << std::endl;
        std::cout << "1. 레시피 추가" << std::endl;
        std::cout << "2. 모든 레시피 출력" << std::endl;
        std::cout << "3. 포션 이름으로 레시피 검색 " << std::endl;
        std::cout << "4. 재료로 레시피 검색 " << std::endl;
        std::cout << "5. 포션 지급받기" << std::endl;
        std::cout << "6. 포션 반환하기 " << std::endl;
        std::cout << "선택: ";

        int choice;
        
        int* p = new int(10);

        std::cin >> choice;

        if (std::cin.fail()) 
        {
            std::cout << "잘못된 입력입니다. 숫자를 입력해주세요." << std::endl;
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            continue;
        }

        if (choice == 1) 
        {
            std::string name;
            std::cout << "물약 이름: ";
            std::cin.ignore(10000, '\n');
            std::getline(std::cin, name);

            // 여러 재료를 입력받기 위한 로직
            std::vector<std::string> ingredients_input;
            std::string ingredient;
            std::cout << "필요한 재료들을 입력하세요. (입력 완료 시 '끝' 입력)" << std::endl;

            while (true) 
            {
                std::cout << "재료 입력: ";
                std::getline(std::cin, ingredient);

                // 사용자가 '끝'을 입력하면 재료 입력 종료
                if (ingredient == "끝") {
                    break;
                }
                ingredients_input.push_back(ingredient);
            }

            // 입력받은 재료가 하나 이상 있을 때만 레시피 추가
            if (!ingredients_input.empty()) 
            {
                myWorkshop.addRecipe(name, ingredients_input);
            }
            else 
            {
                std::cout << ">> 재료가 입력되지 않아 레시피 추가를 취소합니다." << std::endl;
            }

        }
        else if (choice == 2) 
        {
            myWorkshop.displayAllRecipes();

        }
        else if (choice == 3)
        {
            string recipeName;
            cout << "레시피 이름을 검색합니다. : " << endl;
            cin >> recipeName;

            PotionRecipe p = myWorkshop.searchRecipeByName(recipeName);
            cout << p.potionName << endl;
            for (auto inIt : p.ingredients)
            {
                cout << inIt << endl;
            }
        }
        else if (choice == 4)
        {
            string ingredientName;
            cout << "재료 이름으로 레시피를 검색합니다. : ";
            cin >> ingredientName;
            vector<PotionRecipe> inPotionRecipe;
            inPotionRecipe = myWorkshop.searchRecipeByIngredient(ingredientName);
            for (auto it : inPotionRecipe)
            {
                cout << "-----------------" << endl;
                cout << it.potionName << endl;
                for (auto inIt : it.ingredients)
                {
                    cout << inIt << ", ";
                }
                cout << endl;
            }
        }
        else if (choice == 5)
        {
            string recipeName;
            cout << "레시피 이름을 검색합니다. : " << endl;
            cin >> recipeName;
            myWorkshop.GetStockManager().DispensePotion(recipeName);
        }
        else if (choice == 6)
        {
            string recipeName;
            cout << "레시피 이름을 검색합니다. : " << endl;
            cin >> recipeName;
            myWorkshop.GetStockManager().ReturnPotion(recipeName);
        }
        else if (choice == 7) 
        {
            std::cout << "공방 문을 닫습니다..." << std::endl;
            break;
        }
        else 
        {
            std::cout << "잘못된 선택입니다. 다시 시도하세요." << std::endl;
        }
    }

    return 0;
}