/********************************************************************************
** Form generated from reading UI file 'existingplaylistimportdialog.ui'
**
** Created: Sat Jan 12 20:25:45 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXISTINGPLAYLISTIMPORTDIALOG_H
#define UI_EXISTINGPLAYLISTIMPORTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExistingPlaylistImportDialog
{
public:
    QPushButton *noButton;
    QPushButton *yesButton;
    QLabel *label;
    QPushButton *replaceButton;
    QLabel *label_2;

    void setupUi(QDialog *ExistingPlaylistImportDialog)
    {
        if (ExistingPlaylistImportDialog->objectName().isEmpty())
            ExistingPlaylistImportDialog->setObjectName(QString::fromUtf8("ExistingPlaylistImportDialog"));
        ExistingPlaylistImportDialog->resize(412, 121);
        noButton = new QPushButton(ExistingPlaylistImportDialog);
        noButton->setObjectName(QString::fromUtf8("noButton"));
        noButton->setGeometry(QRect(310, 70, 95, 31));
        yesButton = new QPushButton(ExistingPlaylistImportDialog);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(4, 70, 141, 31));
        label = new QLabel(ExistingPlaylistImportDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 0, 411, 31));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        replaceButton = new QPushButton(ExistingPlaylistImportDialog);
        replaceButton->setObjectName(QString::fromUtf8("replaceButton"));
        replaceButton->setGeometry(QRect(150, 70, 151, 31));
        label_2 = new QLabel(ExistingPlaylistImportDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(6, 20, 401, 31));
        label_2->setAlignment(Qt::AlignCenter);

        retranslateUi(ExistingPlaylistImportDialog);

        QMetaObject::connectSlotsByName(ExistingPlaylistImportDialog);
    } // setupUi

    void retranslateUi(QDialog *ExistingPlaylistImportDialog)
    {
        ExistingPlaylistImportDialog->setWindowTitle(QApplication::translate("ExistingPlaylistImportDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        noButton->setText(QApplication::translate("ExistingPlaylistImportDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        yesButton->setText(QApplication::translate("ExistingPlaylistImportDialog", "Add songs", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExistingPlaylistImportDialog", "A playlist with the same name already exists", 0, QApplication::UnicodeUTF8));
        replaceButton->setText(QApplication::translate("ExistingPlaylistImportDialog", "Replace playlist", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("ExistingPlaylistImportDialog", "Rename your .pls file or choose one on the option below", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExistingPlaylistImportDialog: public Ui_ExistingPlaylistImportDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPLAYLISTIMPORTDIALOG_H
