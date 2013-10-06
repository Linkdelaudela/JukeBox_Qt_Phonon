#include<QFileDialog>
#include<QDesktopServices>
#include<iostream>


#include "importexport.h"
#include "playlist.h"

#include <fstream>
#include <string>
#include <sstream>
#include <stdio.h>


ImportExport::ImportExport()
{
}

void ImportExport :: exporterPLS(Playlist* List,std::string name)
{

    std::ofstream pls((name+".pls").c_str());
    std::string request;
    std::ostringstream number;
    int count=1;
    request = "[Playlist]\nNumberOfEntries=" ;
    number << List->getNbSong() ;
    request += number.str();
    number.str("");
    request += "\n\n";
    pls<<request;

    foreach (Song *song, List->getList())
    {

        request = "File";
        number << count ;
        request += number.str();
        number.str("");
        request += "=" ;
        request += song->getPath() ;
        request += "\n";
        pls << request;

        request = "Title" ;
        number << count ;
        request += number.str();
        number.str("");
        request += "=" ;
        request += song->getFilename() ;
        request += "\n";
        pls << request;

        request = "Length";
        number << count ;
        request += number.str();
        number.str("");
        request += "=" ;
        number << 1 ;
        request += number.str();
        number.str("");
        request += "\n\n";

        pls << request;
        count++;
    }

    request = "Version=2";

    pls << request;

    pls.close();
    return ;

}

QList<QString> ImportExport :: importerPLS(std::string path)
{
    std::ifstream pls(path.c_str());
    QList<QString>playlist;

     std::string line;
     getline(pls,line);

     std::cout << line << std::endl;

     if(line =="[playlist]")
     {
         getline(pls,line);

         line.replace(0,16,"");
         std::istringstream tri(line);
         int entry;
         tri >> entry;
         std::cout << entry << std::endl;

         getline(pls,line);

         for(int i=0;i<entry;++i)
         {

             getline(pls,line);
             std::string path=line;
             std::cout << path<< std::endl;
             path.erase(0,6);

             getline(pls,line);
             std::string title=line;
             std::cout << title << std::endl;
             title.erase(0,7);

             getline(pls,line);
             std::string length=line;
             std::cout << length << std::endl;
             length.erase(0,8);
             getline(pls,line);

             QString lengthQ(length.c_str()),titleQ(title.c_str()),pathQ(path.c_str());

             if(lengthQ.toInt() == -1 || pathQ.begin()->toAscii() !='/')
             {}
             else
                 playlist.push_front(pathQ);
         }
     }
     foreach(QString path,playlist)
         std::cout << path.toStdString() << std::endl;
     return playlist;
}

///  @brief RÃ©cupÃ©rer le nom d'un fichier a partir d'un chemin complet.
std::string ImportExport :: getNameFromPath (const char* path)
{
    std::string fullPath (path);

    size_t found = fullPath.rfind('/');

    std::string filename = fullPath.substr(found,fullPath.length());

    found =filename.rfind('.');

    std::string name = filename.substr(0,found);

name.erase(name.begin());


    return name;
}
