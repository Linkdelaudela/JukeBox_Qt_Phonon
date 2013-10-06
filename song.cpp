#include "song.h"

#include <iostream>
#include <QMap>
#include <taglib/fileref.h>
#include <QUrl>
#include <QMessageBox>


Song::Song(const char *path)
{
    QMap<std::string, std::string> *data = getDataSong(path);

    _path = path;
    _filename = data->take("filename");
    _artist = data->take("artist");
    _album = data->take("album");
    _title = data->take("title");

    std::cout << "Chanson creer" << std::endl;

    delete(data);
}

Song::Song(Song *to_copy)
{
    QMap<std::string, std::string> *data = getDataSong(to_copy->getPath().c_str());

    _path = to_copy->getPath();
    _filename = data->take("filename");
    _artist = data->take("artist");
    _album = data->take("album");
    _title = data->take("title");

    std::cout << "Chanson copiee" << std::endl;

    delete(data);
}

Song::Song()
{
    std::cout << "constructeur vide de Song" << std::endl;
}

/*
Song::~Song()
{
   // std::cout << "Chanson supprimée" << std::endl;
}*/

std::string Song::getPath() const
{
    return _path;
}

std::string Song::getFilename() const
{
    return _filename;
}

std::string Song::getArtist() const
{
    return _artist;
}

std::string Song::getAlbum() const
{
    return _album;
}

std::string Song::getTitle() const
{
    return _title;
}

void Song::updateTag()
{
    QMap<std::string, std::string> *data = getDataSong(_path.c_str());

    _filename = data->take("filename");
    _artist = data->take("artist");
    _album = data->take("album");
    _title = data->take("title");

    std::cout << "tag updated" << std::endl;

    delete(data);
}


///  @brief Récupérer le nom d'un fichier a partir d'un chemin complet.
std::string Song :: getFilenameFromPath (const char* path)
{
    std::string fullPath (path);

    size_t found = fullPath.rfind('/');

    std::string filename = fullPath.substr(found,fullPath.length());
    filename.erase(filename.begin());
    //std::cout << "nom de fichier : " << filename << std::endl;

    return filename;
}


/// @brief Récupérer les tags d'un fichier grace a TagLib a partir de son chemin.
QMap<std::string, std::string>* Song::getDataSong(const char* path)
{
    TagLib::FileRef f(path);
    std::string album = f.tag()->album().to8Bit();
    std::string artist= f.tag()->artist().to8Bit();
    std::string title = f.tag()->title().to8Bit();
    QMap<std::string, std::string> *dataSong = new QMap<std::string, std::string>;

    dataSong->insert("path",path);
    dataSong->insert("filename", getFilenameFromPath(path));

    if (album.empty()) album = "Unknown";
    dataSong->insert("album", album);

    if (artist.empty()) artist = "Unknown";
    dataSong->insert("artist", artist);

    if (title.empty()) title = "Unknown";
    dataSong->insert("title", title);

    return dataSong;
}

QImage* Song::imageForTag(TagLib::ID3v2::Tag *tag)
{
   TagLib::ID3v2::FrameList l = tag->frameList("APIC");

   QImage *image = new QImage();

   if(l.isEmpty())
       return NULL;

   TagLib::ID3v2::AttachedPictureFrame *f =
       static_cast<TagLib::ID3v2::AttachedPictureFrame *>(l.front());

   image->loadFromData((const uchar *) f->picture().data(), f->picture().size());

   return image;
}


QImage* Song::imageForFile(const char *file)
{
   TagLib::MPEG::File f(file);

   if(!f.isValid() || !f.ID3v2Tag())
       return NULL;

   return imageForTag(f.ID3v2Tag());
}

void Song::changeCover(const char * path, TagLib::ByteVector & imageData)
{

    TagLib::MPEG::File audioFile(path);


    TagLib::ID3v2::Tag *tag = audioFile.ID3v2Tag(true);

    TagLib::ID3v2::AttachedPictureFrame *frame = new TagLib::ID3v2::AttachedPictureFrame;



    // recuperation image original pour la supprimer
    TagLib::ID3v2::FrameList l = tag->frameList("APIC");

    TagLib::ID3v2::AttachedPictureFrame *f =
        static_cast<TagLib::ID3v2::AttachedPictureFrame *>(l.front());
    //
    if(f==NULL)
    tag->removeFrame(f);

    frame->setMimeType("image/jpeg");

    frame->setPicture(imageData);

    tag->addFrame(frame);

    audioFile.save();
}
