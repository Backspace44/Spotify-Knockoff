#include "BazaDate.h"
#include "User.h"
#include "Listener.h"
#include "Creator.h"
#include "Album.h"
#include "Melodie.h"

BazaDate::BazaDate()
{
	initializareDate();
}

std::unordered_map<CreatorId, Creator> BazaDate:: getCreators()
{
	return creators;
}

std::unordered_map<std::string, CreatorId> BazaDate:: getLookup_Creators()
{
	return lookup_creators;
}

std::unordered_map<ListenerId, Listener> BazaDate:: getListeners()
{
	return listeners;
}

std::unordered_map<std::string, ListenerId> BazaDate:: getLookup_Listeners()
{
	return lookup_listeners;
}

std::unordered_map<MusicId, std::shared_ptr<Melodie>> BazaDate:: getMelodii()
{
	return melodii;
}

std::unordered_map<AlbumId, Album> BazaDate::getAlbume()
{
	return albume;
}

std::unordered_map<std::string, AlbumId> BazaDate::getLookup_Album()
{
	return lookup_album;
}

const Album& BazaDate::get_album(const std::string& nume)
{
	AlbumId id = lookup_album[nume];
	return albume[id];
}

AlbumId BazaDate::get_albumid(const std::string& name)
{
	return lookup_album[name];
}

Album& BazaDate::get_mutable_album(AlbumId id)
{
	return albume[id];
}

bool BazaDate::delete_album(const std::string& name, const std::string& creatorName, UserType userType)
{
	for (auto it = albume.begin(); it != albume.end(); ++it)
	{
		const Album& album = it->second;
		if (album.getName() == name && album.getCreatorName() == creatorName)
		{
			if (userType == UserType::Creator || userType == UserType::Admin)
			{
				albume.erase(it);
				return true;
			}
		}
	}
	return false;
}
	bool BazaDate::delete_listener(const std::string & username, UserType userType)
	{
		ListenerId id = lookup_listeners[username];
		auto it = listeners.find(id);
		if (it != listeners.end())
		{
			if (userType == UserType::Listener || userType == UserType::Admin)
			{
				listeners.erase(it);
				return true;
			}

		}
		else
		{
			return false;
		}
	}
	bool BazaDate::delete_creator(const std::string& username, UserType userType)
	{
		CreatorId id = lookup_creators[username];
		auto it = creators.find(id);
		if (it != creators.end())
		{
			if (userType == UserType::Creator || userType == UserType::Admin)
			{
				creators.erase(it);
				return true;
			}

		}
		else
		{
			return false;
		}
	}

	void BazaDate::initializareDate()
	{
		std::shared_ptr<Listener> david = std::make_shared<Listener>(std::string("David"), std::string("amtemegrele329"), std::string("daviddumitrescu329@gmail.com"), std::string("poze/david.jpg"), std::string("link/to/song"));
		listeners.emplace(david->getUserID(), david);

		std::shared_ptr<Listener> matei = std::make_shared<Listener>(std::string("Matei"), std::string("mafacutmamaolte@n"), std::string("mateipredescu576@gmail.com"), std::string("poze/matei.jpg"), std::string("Link/to/second/song"));
		listeners.emplace(matei->getUserID(), matei);

		std::shared_ptr<Listener> adrian = std::make_shared<Listener>(std::string("Adrian"), std::string("parola123"), std::string("adrianpopescu112@gmail.com"), std::string("poze/adrian.jpg"), std::string("Link/to/third/song"));
		listeners.emplace(adrian->getUserID(), adrian);
	}

