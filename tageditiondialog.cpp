#include "tageditiondialog.h"
#include "ui_tageditiondialog.h"

TagEditionDialog::TagEditionDialog(std::string path, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TagEditionDialog),
    path(path)
{
    ui->setupUi(this);
    TagLib::FileRef ref(path.c_str());


    ui->albumEdit->setPlainText(QString(ref.tag()->album().toCString()));
    ui->artistEdit->setPlainText(QString(ref.tag()->artist().toCString()));
    ui->titleEdit->setPlainText(QString(ref.tag()->title().toCString()));

    connect(this,SIGNAL(tagChanged(std::string,QString,QString,QString)),parent,
                SLOT(editCurrentSongTagProcess (std::string, QString, QString, QString)));
    connect(ui->cancelButton,SIGNAL(clicked()),this,SLOT(close()));
}

TagEditionDialog::~TagEditionDialog()
{
    delete ui;
}

void TagEditionDialog::on_saveButton_clicked()
{
    emit tagChanged(path, ui->artistEdit->toPlainText(),ui->albumEdit->toPlainText(),ui->titleEdit->toPlainText());
    close();
}
