#ifndef RENAMEPLAYLISTDIALOG_H
#define RENAMEPLAYLISTDIALOG_H

#include <QDialog>

namespace Ui {
class RenamePlaylistDialog;
}

class RenamePlaylistDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit RenamePlaylistDialog(QWidget *parent = 0);
    ~RenamePlaylistDialog();
    
private slots:
    void on_okButton_clicked();

private:
    Ui::RenamePlaylistDialog *ui;

signals:
    void name(std::string);
};

#endif // RENAMEPLAYLISTDIALOG_H
