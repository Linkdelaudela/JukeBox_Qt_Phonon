#include "existingplaylistdialog.h"
#include "ui_existingplaylistdialog.h"

ExistingPlaylistDialog::ExistingPlaylistDialog(std::string name, QWidget *parent):
    QDialog(parent),
    ui(new Ui::ExistingPlaylistDialog),
    playlistName(name)
{
    ui->setupUi(this);
    connect (this,SIGNAL(yes(QString)),parent,SLOT(exportPlaylistProcess(QString)));
    connect (this,SIGNAL(replace(QString)),parent,SLOT(deletePlaylist(QString)));
}

ExistingPlaylistDialog::~ExistingPlaylistDialog()
{
    delete ui;
}

void ExistingPlaylistDialog::on_yesButton_clicked()
{
    this->close();
    emit yes (QString(playlistName.c_str()));
}

void ExistingPlaylistDialog::on_noButton_clicked()
{
    this->close();
}

void ExistingPlaylistDialog::on_replaceButton_clicked()
{
    this->close();
    emit replace(QString(playlistName.c_str()));
}

