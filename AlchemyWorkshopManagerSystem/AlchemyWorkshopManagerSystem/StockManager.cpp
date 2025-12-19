#include "StockManager.h"

void StockManager::InitializeStock(string potionName)
{
	auto it = potionStock.find(potionName);
	if (it != potionStock.end())
	{
		cout << "이미 존재합니다" << endl;
		return;
	}
	potionStock.insert({ potionName,MAX_STOCK });
}

bool StockManager::DispensePotion(string potionName)
{
	map<string, int>::iterator it = FindPotion(potionName);
	if(it != potionStock.end())
	{
		if (it->second <= 0)
		{
			cout << "포션 개수가 부족합니다." << endl;
			return false;
		}
		else
		{
			it->second--;
			return true;
		}
	}
	return false;
}

void StockManager::ReturnPotion(string potionName)
{
	map<string, int>::iterator it = FindPotion(potionName);
	if (it != potionStock.end())
	{
		if (it->second >= MAX_STOCK)
		{
			cout << "포션 개수가 꽉 차있습니다" << endl;
		}
		else
		{
			it->second++;
		}
	}
}

int StockManager::GetStock(string potionName)
{
	map<string, int>::iterator it = FindPotion(potionName);
	if (it != potionStock.end())
	{
		return it->second;
	}
}

map<string, int> StockManager::getPotionStock()
{
	return potionStock;
}

map<string, int>::iterator StockManager::FindPotion(const string& potionName)
{
	map<string, int>::iterator it = potionStock.find(potionName);
	if (it == potionStock.end())
	{
		cout << "포션을 찾을 수 없습니다" << endl;
	}
	return it;
}