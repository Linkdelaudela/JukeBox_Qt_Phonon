#ifndef TAGEDITIONDIALOG_H
#define TAGEDITIONDIALOG_H

#include <QDialog>
#include <taglib/fileref.h>

namespace Ui {
class TagEditionDialog;
}

class TagEditionDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit TagEditionDialog( std::string path, QWidget *parent = 0);
    ~TagEditionDialog();
    
private slots:
    void on_saveButton_clicked();

private:
    Ui::TagEditionDialog *ui;
    std::string path;

signals:
    void tagChanged (std::string path, QString artist, QString album, QString title);
};

#endif // TAGEDITIONDIALOG_H
