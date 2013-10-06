    #ifndef CLASSSQL_H
#define CLASSSQL_H

#include <QtSql>

/**
 * @class Bdd
 *
 * @brief Classe contenant les fonctions de gestion de la Bdd
 */
class Bdd {
    /**
     * @brief db
     *
     *  QSqlDataBase se référant a la base de donnée utilisée
     */
    QSqlDatabase db;

public :

    /**
     * @brief connexionBdd
     *
     *      Fonction de connexion a la base de donnée
     *
     *
     * @param driver : string contenant le driver de la base de donnée
     * @param hostname : string contenant le hostname
     * @param username : string contenant le nom d'utilisateur
     * @param passwd : string contenant le mot de passe
     * @param dbName : string contenant le mot de passe de la bdd
     */
    void connexionBdd (std::string driver, std::string hostname, std::string username, std::string passwd, std::string dbName);


    /**
     * @brief getDatabaseFromFile
     *
     *      Fonction permettant de se connecter a une bdd fichier
     *
     *
     * @param driver : string contenant le driver de la base de donnée
     * @param path : string contenant le chemin vers le  fichie de bdd
     */
    void getDatabaseFromFile (std::string driver, std::string path);


    /**
     * @brief updateBdd
     *
     *      Fontcion permettant de faire une requete de type "UPDATE" sur la connexion par défaut
     *
     *
     * @param table_name : string contenant le nom de la table a maj
     * @param setEntry : string contenant la clé du champs a modifier
     * @param setEntryValue : string contenant la valeur a donner a cette clé
     * @param where : string contenant les 'filtres' pour définir les lignes a modifier
     */
    void updateBdd (std::string table_name, std::string setEntry, std::string setEntryValue, std::string where);


    /**
     * @brief selectQuery
     *
     *      Fonction permettant d'effectuer de type 'SELECT' sur la connexion courante
     *
     *
     * @param what : string contenant le champs a récupérer
     * @param table_name : string contenant le nom de la table sur laquelle effectuer la requete
     * @param where : string contenant les 'filtres' pour définir les lignes a retourner
     *
     * @return retourne une QSqlQuery contenant le resultat de la requete
     *          (on ne sait pas le type ni le nombre d'info a traiter, or on
     *          sait a quoi s'attendre lorsque l'on appel la fonction, d'ou ce choix)
     */
    QSqlQuery selectQuery (std::string what, std::string table_name, std::string where);


    /**
     * @brief insertBdd
     *
     *
     *      Fonction permettant d'effectuer des requetes de type 'INSERT' sur la connexion par défaut
     *
     *
     * @param table_name : string contenant le nom de la table sur laquelle effectuer la requete
     * @param values : string contenant les valeurs a insérer
     */
    bool insertBdd (std::string table_name, std::string values);

    /**
     * @brief deleteQuery
     *
     *
     *      Fonction permettant d'effectuer des requetes de type 'DELETE' sur la connexion par defaut
     *
     *
     * @param table : string contenant le nom de la table sur laquelle effectuer la requete
     * @param where : string contenant les filtres pour savoir quoi supprimer
     */
    void deleteQuery (std::string table, std::string where);


    /**
     * @brief closeBdd
     *
     *
     *      Fonction permettant de fermer la connexion par défaut
     *
     *
     */
    void closeBdd ();


    /**
     * @brief getBdd
     *
     *      Getter sur l'attribut database de la classe Bdd
     *
     *
     * @return un QSqlDatabase contenant l'attribut db
     */
    QSqlDatabase getBdd ();
};



#endif // CLASSSQL_H
