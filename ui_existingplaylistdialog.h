/********************************************************************************
** Form generated from reading UI file 'existingplaylistdialog.ui'
**
** Created: Sat Jan 12 20:25:45 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXISTINGPLAYLISTDIALOG_H
#define UI_EXISTINGPLAYLISTDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_ExistingPlaylistDialog
{
public:
    QLabel *label;
    QPushButton *yesButton;
    QPushButton *noButton;
    QPushButton *replaceButton;

    void setupUi(QDialog *ExistingPlaylistDialog)
    {
        if (ExistingPlaylistDialog->objectName().isEmpty())
            ExistingPlaylistDialog->setObjectName(QString::fromUtf8("ExistingPlaylistDialog"));
        ExistingPlaylistDialog->resize(407, 127);
        label = new QLabel(ExistingPlaylistDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(0, 20, 411, 51));
        label->setTextFormat(Qt::AutoText);
        label->setAlignment(Qt::AlignCenter);
        yesButton = new QPushButton(ExistingPlaylistDialog);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(4, 90, 141, 31));
        noButton = new QPushButton(ExistingPlaylistDialog);
        noButton->setObjectName(QString::fromUtf8("noButton"));
        noButton->setGeometry(QRect(310, 90, 95, 31));
        replaceButton = new QPushButton(ExistingPlaylistDialog);
        replaceButton->setObjectName(QString::fromUtf8("replaceButton"));
        replaceButton->setGeometry(QRect(150, 90, 151, 31));
        QWidget::setTabOrder(noButton, yesButton);
        QWidget::setTabOrder(yesButton, replaceButton);

        retranslateUi(ExistingPlaylistDialog);

        QMetaObject::connectSlotsByName(ExistingPlaylistDialog);
    } // setupUi

    void retranslateUi(QDialog *ExistingPlaylistDialog)
    {
        ExistingPlaylistDialog->setWindowTitle(QApplication::translate("ExistingPlaylistDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("ExistingPlaylistDialog", "A playlist with the same name already exists", 0, QApplication::UnicodeUTF8));
        yesButton->setText(QApplication::translate("ExistingPlaylistDialog", "Add songs", 0, QApplication::UnicodeUTF8));
        noButton->setText(QApplication::translate("ExistingPlaylistDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        replaceButton->setText(QApplication::translate("ExistingPlaylistDialog", "Replace playlist", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class ExistingPlaylistDialog: public Ui_ExistingPlaylistDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPLAYLISTDIALOG_H
