/********************************************************************************
** Form generated from reading UI file 'renameplaylistdialog.ui'
**
** Created: Sat Jan 12 20:25:45 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RENAMEPLAYLISTDIALOG_H
#define UI_RENAMEPLAYLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_RenamePlaylistDialog
{
public:
    QPushButton *cancelButton;
    QPushButton *okButton;
    QLabel *label;
    QLineEdit *playlistName;

    void setupUi(QDialog *RenamePlaylistDialog)
    {
        if (RenamePlaylistDialog->objectName().isEmpty())
            RenamePlaylistDialog->setObjectName(QString::fromUtf8("RenamePlaylistDialog"));
        RenamePlaylistDialog->resize(400, 145);
        cancelButton = new QPushButton(RenamePlaylistDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(290, 100, 95, 31));
        okButton = new QPushButton(RenamePlaylistDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(180, 100, 95, 31));
        label = new QLabel(RenamePlaylistDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 401, 21));
        label->setAlignment(Qt::AlignCenter);
        playlistName = new QLineEdit(RenamePlaylistDialog);
        playlistName->setObjectName(QString::fromUtf8("playlistName"));
        playlistName->setGeometry(QRect(20, 50, 361, 31));
        QWidget::setTabOrder(playlistName, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(RenamePlaylistDialog);
        QObject::connect(playlistName, SIGNAL(returnPressed()), okButton, SLOT(click()));

        QMetaObject::connectSlotsByName(RenamePlaylistDialog);
    } // setupUi

    void retranslateUi(QDialog *RenamePlaylistDialog)
    {
        RenamePlaylistDialog->setWindowTitle(QApplication::translate("RenamePlaylistDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("RenamePlaylistDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("RenamePlaylistDialog", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("RenamePlaylistDialog", "Type a new name", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class RenamePlaylistDialog: public Ui_RenamePlaylistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RENAMEPLAYLISTDIALOG_H
