#include <iostream>
#include <sstream>

#include "classSQL.h"


/// @brief Fonction de connexion a une bdd
void Bdd :: connexionBdd (std::string driver, std::string hostname, std::string username, std::string passwd, std::string dbName)
{
    db = QSqlDatabase::addDatabase(QString(driver.c_str()));
    db.setHostName(hostname.c_str());
    db.setUserName(username.c_str());
    db.setPassword(passwd.c_str());
    db.setDatabaseName(dbName.c_str());
    if(db.open())
    {
        std::cout << "Vous êtes maintenant connecté à " << db.hostName().toStdString()<< std::endl;
        db.close();
    }
    else
    {
        std::cout << "La connexion a échouée, désolé" << std::endl;
    }
}


/// @brief fonction de connexion a une bdd en fichier
void Bdd :: getDatabaseFromFile (std::string driver, std::string path)
{
    db = QSqlDatabase::addDatabase(QString(driver.c_str()));
    db.setDatabaseName(path.c_str());
    if(db.open())
    {
        std::cout << "Vous êtes maintenant sur la bdd " << db.databaseName().toStdString()<< std::endl;
    }
    else
    {
        std::cout << "La connexion a échouée, désolé" << std::endl;
    }
}


/// @brief Fonction pour effectuer des requets de types 'UPDATE'
void Bdd :: updateBdd (std::string table_name, std::string setEntry, std::string setEntryValue, std::string where)
{
    QSqlQuery query;
    std::string SQLquery;
    std::ostringstream oss;

    oss << "UPDATE " << table_name << " SET " << setEntry << "=\"" << setEntryValue << "\" WHERE ";
    oss << where ;
    SQLquery = oss.str();
    std::cout << "SQL query : " << SQLquery << std::endl;

    if(query.exec(QString(SQLquery.c_str())))
    {
        std::cout << "Changmement effecté avec succés." << std::endl;
    }

    else
    {
        std::cout << "Une erreur s'est produite..." << std::endl << query.lastError().text().toStdString() << std::endl;
    }
}

/// @brief Fonction pour effectuer des requetes de type 'SELECT'
QSqlQuery Bdd :: selectQuery (std::string what, std::string table_name, std::string where="")
{
    QSqlQuery query;
    std::string SQLquery;
    std::ostringstream oss;

    oss << "SELECT ";

    oss << what;

    oss << " FROM " << table_name;

    if (!where.empty())
        oss << " WHERE " << where;

    SQLquery = oss.str();

    std::cout << "SQL query : " << SQLquery << std::endl;

    if(query.exec(QString(SQLquery.c_str())))
    {
        std::cout << "Changmement effecté avec succés." << std::endl;
    }

    else
    {
        std::cout << "Une erreur s'est produite..." << std::endl << query.lastError().text().toStdString() << std::endl;
    }
    return query;
}


/// @brief Fonction pour effetuer des requetes de type 'INSERT'
bool Bdd::insertBdd(std::string table_name, std::string values)
{
    QSqlQuery query;
    std::string SQLquery;
    std::ostringstream oss;

    oss << "INSERT INTO " << table_name << " VALUES (" << values << ")";

    SQLquery = oss.str();
    std::cout << "SQL query : " << SQLquery << std::endl;

    if(query.exec(QString(SQLquery.c_str())))
    {
        std::cout << "Changmement effecté avec succés." << std::endl;
        return true;
    }

    else
    {
        std::cout << "Une erreur s'est produite..." << std::endl << query.lastError().text().toStdString() << std::endl;
        return false;
    }
}



void Bdd::deleteQuery(std::string table, std::string where)
{
    QSqlQuery query;
    std::string SQLquery;
    std::ostringstream oss;

    oss << "DELETE FROM " << table << " WHERE " << where;

    SQLquery = oss.str();
    std::cout << "SQL query : " << SQLquery << std::endl;

    if(query.exec(QString(SQLquery.c_str())))
    {
        std::cout << "Changmement effecté avec succés." << std::endl;
    }

    else
    {
        std::cout << "Une erreur s'est produite..." << std::endl << query.lastError().text().toStdString() << std::endl;
    }
}




/// @brief Fonction pour fermer la connexion a la bdd
void Bdd :: closeBdd ()
{
    db.close();
    std::cout << "Connexion a la bdd fermée" << std::endl;
}



/// @brief Getter sur l'attribut db
QSqlDatabase Bdd ::  getBdd ()
{
    return db;
}
