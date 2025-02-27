//Admin.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "User.h"
//#include "Listener.h"
//#include "Creator.h"
#include "BazaDate.h"
#include "Album.h"

class Admin : public User
{
private:
	std::string all_time_favourite_listener;
public:
	Admin() : User() {}
	Admin(std::string& nume, std::string& parola, std::string& email, std::string& profile_picture, std::string all_time_favourite_listener) : User(nume, parola, email, profile_picture, all_time_favourite_listener) {}
	bool delete_listener(BazaDate& database, const std::string& username, UserType userType);
	bool delete_creator(BazaDate& database, const std::string& username,UserType userType);
	bool deleteTheAlbum(BazaDate& database, const std::string& username, const std::string& albumName, UserType userType);
	void setAllTimeFavourite(std::string favourite_listener);
};