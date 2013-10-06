#ifndef IMPORTEXPORT_H
#define IMPORTEXPORT_H

#include<QModelIndex>
#include"playlist.h"

class ImportExport
{
public:
    ImportExport();
    void exporterPLS(Playlist*,std::string);
    QList<QString> importerPLS(std::string);

    std::string getNameFromPath (const char*);
};

#endif // IMPORTEXPORT_H
