//Melodie.cpp
#include "Melodie.h"

Melodie::Melodie()
        :_song(""),
        _name(""),
        _artist(""),
        _cover(""),
        _album_name("")
    {
        _data = Data_aparitie();
    }
Melodie::Melodie(std::string song, std::string name, std::string artist, std::string cover, std::string album_name, Data_aparitie data)
        : _song(song),
        _name(name),
        _artist(artist),
        _cover(cover),
        _album_name(album_name),
        _data(data)
    {
    }
Melodie::Melodie(const Melodie& obj)
        : _song(obj._song),
        _name(obj._name),
        _artist(obj._artist),
        _cover(obj._cover),
        _album_name(obj._album_name),
        _data(obj._data)
    {
    }
    bool Melodie::operator==(const Melodie& melodie)
    {
        return _song == melodie._song && _name == melodie._name && _artist == melodie._artist && _cover == melodie._cover && _album_name == melodie._album_name && (_data == melodie._data);
    }
    std::string Melodie::getSong()
    {
        return _song;
    }
    std::string Melodie::getName()
    {
        return _name;
    }
    std::string Melodie::getArtist()
    {
        return _artist;
    }
    std::string Melodie::getCover()
    {
        return _cover;
    }

    std::string Melodie::getAlbumName()
    {
        return _album_name;
    }
    Data_aparitie Melodie::getData()
    {
        return _data;
    }
    void Melodie::setSong(std::string new_song)
    {
        _song = new_song;
    }
    void Melodie::setName(std::string new_name)
    {
        _name = new_name;
    }
    void Melodie::setArtist(std::string new_artist)
    {
        _artist = new_artist;
    }
    void Melodie::setCover(std::string new_cover)
    {
        _cover = new_cover;
    }
    void Melodie::setAlbumName(std::string new_album_name)
    {
        _album_name = new_album_name;
    }
    void Melodie::setData(const Data_aparitie& new_data)
    {
        _data = new_data;
    }

