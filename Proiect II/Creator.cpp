//Creator.cpp
#include "Creator.h"

void Creator::deleteAlbum(BazaDate& database,const std::string& albumName, const std::string& username, UserType userType)
{
	database.delete_album(albumName, username, userType);
}

std::vector<Melodie> Creator::getAlbumul()
{
	return Albumul;
}

std::vector<Album> Creator::getAlbumList()
{
	return AlbumList;
}

void Creator::setAlbumul(std::vector<Melodie> new_album)
{
	Albumul = new_album;
}

void Creator::setAlbumList(std::vector<Album> new_albumlist)
{
	AlbumList = new_albumlist;
}
void Creator::setAllTimeFavourite(std::string favourite_album)
{
	all_time_favourite_album = favourite_album;
}