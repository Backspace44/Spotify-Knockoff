//Melodie.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
#include "Data_aparitie.h"

class Melodie
{
private:
	std::string _song;
	std::string _name;
	std::string _artist;
	std::string _cover;
	std::string _album_name;
	Data_aparitie _data;
public:
	Melodie();
	Melodie(std::string song, std::string name, std::string artist, std::string cover, std::string album_name, Data_aparitie data);
	Melodie(const Melodie& obj);
	bool operator==(const Melodie& melodie);
	std::string getSong();
	std::string getName();
	std::string getArtist();
	std::string getCover();
	std::string getAlbumName();
	Data_aparitie getData();
	void setSong(std::string new_song);
	void setName(std::string new_name);
	void setArtist(std::string new_artist);
	void setCover(std::string new_cover);
	void setAlbumName(std::string new_album_name);
	void setData(const Data_aparitie& new_data);
};


