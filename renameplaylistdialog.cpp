#include "renameplaylistdialog.h"
#include "ui_renameplaylistdialog.h"

RenamePlaylistDialog::RenamePlaylistDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::RenamePlaylistDialog)
{
    ui->setupUi(this);
    connect(this->ui->cancelButton, SIGNAL(clicked()), this,SLOT(close()));
    connect(this,SIGNAL(name(std::string)), parent, SLOT(renamePlaylistProcess(std::string)));
}

RenamePlaylistDialog::~RenamePlaylistDialog()
{
    delete ui;
}

void RenamePlaylistDialog::on_okButton_clicked()
{
    emit name(ui->playlistName->text().toStdString());
    close();
}
