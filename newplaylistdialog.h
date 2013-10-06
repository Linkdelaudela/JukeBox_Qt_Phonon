#ifndef NEWPLAYLISTDIALOG_H
#define NEWPLAYLISTDIALOG_H

#include <QDialog>

namespace Ui {

/**
 *  @class Classe pour gerer la fenetre de creation de playlist
 */
class newPlaylistDialog;
}

class newPlaylistDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit newPlaylistDialog(QWidget *parent = 0);
    ~newPlaylistDialog();
    
private:
    Ui::newPlaylistDialog *ui;

signals :
    /**
     * @brief name
     *
     *
     *      Signal associé a l'envoi du nom passer en parametre
     *
     *
     * @param name : QString contenant le nom a envoyer
     */
    void name (QString name);

private slots :

    /**
     * @brief ok
     *
     *      Slot associe au bouton Ok
     *
     *
     *      Fonction qui envoi le signal name avec le nom entrer dans la fenetre.
     */
    void ok (void);
};

#endif // NEWPLAYLISTDIALOG_H
