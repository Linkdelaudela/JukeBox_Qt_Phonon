#include "newplaylistdialog.h"
#include "ui_newplaylistdialog.h"


newPlaylistDialog::newPlaylistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::newPlaylistDialog)
{
    ui->setupUi(this);
    connect(this,SIGNAL(name(QString)),parent,SLOT(exportCurrentPlaylist(QString)));
}

newPlaylistDialog::~newPlaylistDialog()
{
    delete ui;
}

void newPlaylistDialog::ok()
{
    QString nom = ui->playlistName->text();
    this->close();
    emit name(ui->playlistName->text());
}
