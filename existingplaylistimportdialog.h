#ifndef EXISTINGPLAYLISTIMPORTDIALOG_H
#define EXISTINGPLAYLISTIMPORTDIALOG_H

#include <QList>
#include <QDialog>

namespace Ui {
class ExistingPlaylistImportDialog;
}

class ExistingPlaylistImportDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit ExistingPlaylistImportDialog (QList<QString> list,std::string name, QWidget *parent = 0);
    ~ExistingPlaylistImportDialog();
    
private:
    Ui::ExistingPlaylistImportDialog *ui;
    std::string playlistName;
    QList<QString> playlist;

signals:
    void yes (QList<QString> list,QString playlist_name);
    void replace (QList<QString> list,QString playlist_name);

private slots:
    void on_yesButton_clicked();
    void on_noButton_clicked();
    void on_replaceButton_clicked();
};

#endif // EXISTINGPLAYLISTIMPORTDIALOG_H
