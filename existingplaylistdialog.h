#ifndef EXISTINGPLAYLISTDIALOG_H
#define EXISTINGPLAYLISTDIALOG_H

#include <QDialog>

namespace Ui {
class ExistingPlaylistDialog;
}

class ExistingPlaylistDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ExistingPlaylistDialog (std::string name, QWidget *parent = 0);
    ~ExistingPlaylistDialog();

private:
    Ui::ExistingPlaylistDialog *ui;
    std::string playlistName;

signals:
    void yes (QString playlist_name);
    void replace (QString playlist_name);

private slots:
    void on_yesButton_clicked();
    void on_noButton_clicked();
    void on_replaceButton_clicked();
};

#endif // EXISTINGPLAYLISTDIALOG_H
