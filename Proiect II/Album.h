//Album.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Melodie.h"
//#include "BazaDate.h"

class Album
{
private:
	std::string nume;
	std::string creatorName;
	std::vector<std::shared_ptr<Melodie>> album;
	friend class Admin;
	friend class Creator;
public:
	Album() = default;
	Album(const std::string& nume, const std::string& creator, const std::vector<std::shared_ptr<Melodie>> album);
	std::string getCreatorName() const;
	std::string getName() const;
	const std::vector<std::shared_ptr<Melodie>>& getMelodii() const;
	void setCreatorName(std::string new_creatorName);
	void setName(std::string new_nume);
	void setMelodii(std::vector<std::shared_ptr<Melodie>>& new_album);
};
