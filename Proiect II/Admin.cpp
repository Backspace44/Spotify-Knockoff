//Admin.cpp
#include "Admin.h"

bool Admin::delete_listener(BazaDate& database, const std::string& username, UserType userType)
{
	return database.delete_listener(username, userType);
}
bool Admin::delete_creator(BazaDate& database, const std::string& username, UserType userType)
{
	return database.delete_creator(username, userType);
}
bool Admin::deleteTheAlbum(BazaDate& database, const std::string& username, const std::string& albumName, UserType userType)
{
	return database.delete_album(albumName, username, userType);
}
void Admin::setAllTimeFavourite(std::string favourite_listener)
{
	all_time_favourite_listener = favourite_listener;
}