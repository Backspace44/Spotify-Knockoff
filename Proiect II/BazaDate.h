//BazaDate.h
#pragma once
#include <string>
#include <vector>
#include <memory>
#include <unordered_map>
//#include "Melodie.h"
//#include "Album.h"
//#include "User.h"

class Creator;
class Listener;
class Melodie;
class Album;
class User;

using MusicId = size_t;
using AlbumId = size_t;
using CreatorId = size_t;
using ListenerId = size_t;

enum class UserType
{
	Listener,
	Creator,
	Admin
};

class BazaDate
{
private:
	std::unordered_map<CreatorId, Creator> creators;
	std::unordered_map<std::string, CreatorId> lookup_creators;
	std::unordered_map<ListenerId, Listener> listeners;
	std::unordered_map<std::string, ListenerId> lookup_listeners;
	std::unordered_map<MusicId, std::shared_ptr<Melodie>> melodii;
	std::unordered_map<AlbumId, Album> albume;
	std::unordered_map<std::string, AlbumId> lookup_album;
	Album& get_mutable_album(AlbumId id);
	friend class Admin;
	friend class Creator;
	void initializareDate();
protected:
	bool delete_album(const std::string& name, const std::string& creatorName, UserType userType);
	bool delete_listener(const std::string& username, UserType userType);
	bool delete_creator(const std::string& username, UserType userType);
public:
	BazaDate();
	std::unordered_map<CreatorId, Creator> getCreators();
	std::unordered_map<std::string, CreatorId> getLookup_Creators();
	std::unordered_map<ListenerId, Listener> getListeners();
	std::unordered_map<std::string, ListenerId> getLookup_Listeners();
	std::unordered_map<MusicId, std::shared_ptr<Melodie>> getMelodii();
	std::unordered_map<AlbumId, Album> getAlbume();
	std::unordered_map<std::string, AlbumId> getLookup_Album();
	const Album& get_album(const std::string& nume);
	AlbumId get_albumid(const std::string& name);
};
