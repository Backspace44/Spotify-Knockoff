//Creator.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "User.h"
#include "Album.h"
#include "BazaDate.h"

class Creator : public User
{
private:
	friend class BazaDate;
	std::vector<Melodie> Albumul;
	std::vector<Album> AlbumList;
	std::string all_time_favourite_album;

public:
	Creator() : User() {}
	Creator(std::string& nume, std::string& parola, std::string& email, std::string& profile_picture, std::string all_time_favourite_album) : User(nume, parola, email, profile_picture, all_time_favourite_album) {}
	void deleteAlbum(BazaDate& database, const std::string& albumName, const std::string& username, UserType userType);
	std::vector<Melodie> getAlbumul();
	std::vector<Album> getAlbumList();
	void setAlbumul(std::vector<Melodie> new_album);
	void setAlbumList(std::vector<Album> new_albumlist);
	void setAllTimeFavourite(std::string favourite_album);
};