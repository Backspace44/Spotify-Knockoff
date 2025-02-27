//Data_aparitie.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

class Data_aparitie
{
private:
	int _zi;
	std::string _luna;
	int _an;
public:
	Data_aparitie();
	Data_aparitie(int zi, std::string luna, int an);
	Data_aparitie(const Data_aparitie& obj);
	bool operator==(const Data_aparitie& d);

};
