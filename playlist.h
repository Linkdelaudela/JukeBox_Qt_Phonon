#ifndef PLAYLIST_H
#define PLAYLIST_H

#include "song.h"
#include "classSQL.h"
#include <QListWidgetItem>
#include <QMap>
#include <QList>

typedef QMap<QListWidgetItem*, std::string> playlistMap;


class Playlist
{
private :
    QList<Song*> songList;
    std::string playlistName;
    long nbSong;


public:
    Playlist(playlistMap map, std::string name);
    Playlist(QList<QString> pls, std::string name);
    ~Playlist ();

    /**
     * @brief addToDb
     *
     *
     *      Fonction permettant d'ajouter la playlist a la base
     *      de donnee passee en paramaetre.
     *
     *
     * @param database : Bdd contenant la base de donnee
     */
    void addToDb (Bdd database);

    static void deleteFromDb (Bdd database, std::string to_delete, std::string tablePlaylist, std::string tableMusic);

    static void renameInDb(Bdd database, std::string oldName, std::string newName, std::string tablePlaylist, std::string tableMusic);

    long getNbSong();

    QList<Song*> getList();
};

#endif // PLAYLIST_H
