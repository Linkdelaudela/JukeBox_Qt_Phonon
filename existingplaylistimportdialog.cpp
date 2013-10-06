#include "existingplaylistimportdialog.h"
#include "ui_existingplaylistimportdialog.h"

ExistingPlaylistImportDialog::ExistingPlaylistImportDialog(QList<QString> list, std::string name, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ExistingPlaylistImportDialog),
    playlistName(name),
    playlist(list)
{
    ui->setupUi(this);
    connect (this,SIGNAL(yes(QList<QString>,QString)),parent,SLOT(importPlaylistPls(QList<QString>, QString)));
    connect (this,SIGNAL(replace(QList<QString>,QString)),parent,SLOT(deletePlaylistImport(QList<QString>, QString)));
}

ExistingPlaylistImportDialog::~ExistingPlaylistImportDialog()
{
    delete ui;
}

void ExistingPlaylistImportDialog::on_yesButton_clicked()
{
    this->close();
    emit yes (playlist,QString(playlistName.c_str()));
}

void ExistingPlaylistImportDialog::on_noButton_clicked()
{
    this->close();
}

void ExistingPlaylistImportDialog::on_replaceButton_clicked()
{
    this->close();
    emit replace(playlist,QString(playlistName.c_str()));
}

