#ifndef SONG_H
#define SONG_H

#include <QMap>
#include <QImage>
#include <taglib/id3v2tag.h>
#include <taglib/mpegfile.h>
#include <taglib/attachedpictureframe.h>


class Song
{
    std::string _path;
    std::string _filename;
    std::string _artist;
    std::string _album;
    std::string _title;

public:
    Song(const char *path);
    Song();
    Song(Song *to_copy);
    //~Song();

    std::string getPath() const;
    std::string getFilename() const;
    std::string getArtist() const;
    std::string getAlbum() const;
    std::string getTitle() const;

    void updateTag ();

    static std::string getFilenameFromPath (const char* path);

    static QMap<std::string, std::string>* getDataSong(const char* path);

    // Fonctions de recuperation de la cover
    static QImage* imageForTag(TagLib::ID3v2::Tag *tag);

    static QImage* imageForFile(const char *file);

    void changeCover(const char * path, TagLib::ByteVector & imageData);
};

#endif // SONG_H
