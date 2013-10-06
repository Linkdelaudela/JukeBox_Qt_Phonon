#include <iostream>
#include <sstream>
#include "playlist.h"
#include "classSQL.h"

typedef QMap<QListWidgetItem*, std::string> playlistMap;

Playlist::Playlist(playlistMap map, std::string name)
    :playlistName(name)
{
    playlistMap::Iterator it;

    for (it = map.begin(); it != map.end(); ++it)
    {
        songList.append(new Song(it.value().c_str()));
    }

    nbSong = songList.size();

    std::cout << "Playlist created" << std::endl;
}




Playlist::Playlist(QList<QString> pls, std::string name)
    :playlistName(name)
{
    foreach(QString song,pls)
        songList.append(new Song(song.toStdString().c_str()));

    nbSong = songList.size();

    std::cout << "Playlist created" << std::endl;
}




Playlist::~Playlist()
{
    QList<Song*>::Iterator it;

    for (it = songList.begin(); it != songList.end(); ++it)
    {
        delete *it;
    }
    songList.clear();
    std::cout << "Playlist deleted" << std::endl;
}




/// @todo p-e modifier classSQL pour passer liste des champs
void Playlist :: addToDb (Bdd database)
{
    std::cout << "add to db " << std::endl;
    std::ostringstream request;
    request << "'" << this->playlistName << "','" << this->nbSong << "'";
    database.insertBdd("tplaylist",request.str());


    foreach (Song *song, songList)
    {
        request.str("");
        request << "'" << song->getPath() << "','" << this->playlistName <<"'";
         std::cout << "add : " << song->getPath() << std::endl;
        database.insertBdd("tplaylist_music",request.str());
    }
}





void Playlist::deleteFromDb(Bdd database, std::string to_delete, std::string tablePlaylist, std::string tableMusic)
{
    QSqlQuery result;
    std::string where("playlist_name=\"");
    where += to_delete.c_str();
    where += "\"";

    result = database.selectQuery("path",tableMusic,where);

    while(result.next())
    {
        std::string path = result.value(0).toString().toStdString();
        std::cout << "nom : " << path << std::endl;
        where = "path=\"";
        where += path;
        where += "\"";
        database.deleteQuery(tableMusic,where);
    }

    where = "name=\"";
    where += to_delete.c_str();
    where += "\"";
    database.deleteQuery(tablePlaylist,where);
}





void Playlist::renameInDb(Bdd database, std::string oldName, std::string newName, std::string tablePlaylist, std::string tableMusic)
{
    QSqlQuery result;
    std::string where("playlist_name=\"");
    where += oldName.c_str();
    where += "\"";

    result = database.selectQuery("path",tableMusic,where);

    while(result.next())
    {
        std::string path = result.value(0).toString().toStdString();
        std::cout << "nom : " << path << std::endl;
        where = "path=\"";
        where += path;
        where += "\"";
        database.updateBdd(tableMusic,"playlist_name",newName,where);
    }

    where = "name=\"";
    where += oldName;
    where += "\"";
    database.updateBdd(tablePlaylist,"name",newName,where);
}





long Playlist::getNbSong()
{
    return nbSong;
}





QList<Song*> Playlist::getList()
{
    return songList;
}
