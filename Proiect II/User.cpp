//User.cpp
#include "User.h"

int User::nextID = 1;

    User::User()
    {
        _name = "";
        _parola = "";
        _email = "";
        _profile_picture = "";
        _all_time_favourite = "";
    }
    User::User(std::string name, std::string parola, std::string email, std::string profile_picture, std::string all_time_favourite)
        : _name(name),
        _parola(parola),
        _email(email),
        _profile_picture(profile_picture),
        _all_time_favourite(all_time_favourite)
    {
        userID = nextID++;
    }
    User::User(const User& obj)
        : _name(obj._name),
        _parola(obj._name),
        _email(obj._email),
        _profile_picture(obj._profile_picture),
        _all_time_favourite(obj._all_time_favourite)
    {
    }
    int User::getUserID()
    {
        return userID;
    }
    std::string User::getName()
    {
        return _name;
    }
    std::string User::getParola()
    {
        return _parola;
    }
    std::string User::getEmail()
    {
        return _email;
    }
    std::string User::getProfilePicture()
    {
        return _profile_picture;
    }
    void User::setName(std::string new_name)
    {
        _name = new_name;
    }
    void User::setParola(std::string new_parola)
    {
        _parola = new_parola;
    }
    void User::setEmail(std::string new_email)
    {
        _email = new_email;
    }
    void User::setProfilePicture(std::string new_profile_picture)
    {
        _profile_picture = new_profile_picture;
    }
   // User::~User() {}