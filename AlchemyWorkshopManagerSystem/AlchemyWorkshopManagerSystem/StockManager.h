#pragma once
#include<string>
#include<iostream>
#include<algorithm>
#include<map>

using namespace std;
const int MAX_STOCK = 3;
class StockManager
{
public:
	StockManager(){}
	void InitializeStock(string potionName);//처음 등록
	bool DispensePotion(string potionName);//지급
	void ReturnPotion(string potionName);//반환
	int GetStock(string potionName);//조회
	map<string, int> getPotionStock();
private:
	map<string, int>::iterator FindPotion(const string& potionName);
	map<string, int> potionStock;
};

