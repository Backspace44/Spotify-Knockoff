//Album.cpp
#include "Album.h"

Album::Album(const std::string& nume, const std::string& creator, const std::vector<std::shared_ptr<Melodie>> album)
    :nume(nume),
    creatorName(creator),
    album(album)
{}
std::string Album::getCreatorName() const
{
    return creatorName;
}
std::string Album::getName() const
{
    return nume;
}
const std::vector<std::shared_ptr<Melodie>>& Album::getMelodii() const
{
    return album;
}
void Album::setCreatorName(std::string new_creatorName)
{
    creatorName = new_creatorName;
}
void Album::setName(std::string new_nume)
{
    nume = new_nume;
}
void Album::setMelodii(std::vector<std::shared_ptr<Melodie>>& new_album)
{
    album = new_album;
}
