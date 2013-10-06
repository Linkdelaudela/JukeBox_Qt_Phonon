/********************************************************************************
** Form generated from reading UI file 'newplaylistdialog.ui'
**
** Created: Sat Jan 12 20:25:45 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPLAYLISTDIALOG_H
#define UI_NEWPLAYLISTDIALOG_H

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

class Ui_newPlaylistDialog
{
public:
    QPushButton *cancelButton;
    QPushButton *okButton;
    QLabel *label;
    QLineEdit *playlistName;

    void setupUi(QDialog *newPlaylistDialog)
    {
        if (newPlaylistDialog->objectName().isEmpty())
            newPlaylistDialog->setObjectName(QString::fromUtf8("newPlaylistDialog"));
        newPlaylistDialog->resize(399, 159);
        cancelButton = new QPushButton(newPlaylistDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(40, 120, 131, 31));
        okButton = new QPushButton(newPlaylistDialog);
        okButton->setObjectName(QString::fromUtf8("okButton"));
        okButton->setGeometry(QRect(220, 120, 141, 31));
        label = new QLabel(newPlaylistDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(80, 10, 221, 21));
        label->setAlignment(Qt::AlignCenter);
        playlistName = new QLineEdit(newPlaylistDialog);
        playlistName->setObjectName(QString::fromUtf8("playlistName"));
        playlistName->setGeometry(QRect(10, 50, 381, 31));
        QWidget::setTabOrder(playlistName, okButton);
        QWidget::setTabOrder(okButton, cancelButton);

        retranslateUi(newPlaylistDialog);
        QObject::connect(cancelButton, SIGNAL(clicked()), newPlaylistDialog, SLOT(close()));
        QObject::connect(okButton, SIGNAL(clicked()), newPlaylistDialog, SLOT(ok()));
        QObject::connect(playlistName, SIGNAL(returnPressed()), okButton, SLOT(click()));

        QMetaObject::connectSlotsByName(newPlaylistDialog);
    } // setupUi

    void retranslateUi(QDialog *newPlaylistDialog)
    {
        newPlaylistDialog->setWindowTitle(QApplication::translate("newPlaylistDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("newPlaylistDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        okButton->setText(QApplication::translate("newPlaylistDialog", "OK", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("newPlaylistDialog", "Give a name to your playlist", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class newPlaylistDialog: public Ui_newPlaylistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPLAYLISTDIALOG_H
