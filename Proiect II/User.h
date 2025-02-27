//User.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>

class User
{
private:
	static int nextID;
	int userID;
	std::string _name;
	std::string _parola;
	std::string _email;
	std::string _profile_picture;
	std::string _all_time_favourite;
	friend class BazaDate;
	friend class Admin;

public:
	User();
	User(std::string name, std::string password, std::string email, std::string profile_picture, std::string all_time_favourite);
	User(const User& obj);
	int getUserID();
	std::string getName();
	std::string getParola();
	std::string getEmail();
	std::string getProfilePicture();
	void setName(std::string new_name);
	void setParola(std::string new_parola);
	void setEmail(std::string new_email);
	void setProfilePicture(std::string new_profile_picture);
	//virtual void setAllTimeFavourite() = 0;
	//virtual ~User();
};