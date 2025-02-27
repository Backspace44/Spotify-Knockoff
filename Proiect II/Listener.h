//Listener.h
#pragma once
#include <unordered_map>
#include <vector>
#include <memory>
#include <string>
#include "User.h"

class Listener : public User
{
private:
	std::string all_time_favourite_song;
public:
	Listener() : User() {}
	Listener(const std::string& nume, const std::string& parola, const std::string& email, const std::string& profile_picture, const std::string& all_time_favourite_song)
		:User(nume, parola, email, profile_picture, all_time_favourite_song) {}
	void setAllTimeFavourite(std::string favourite_song);

};