/********************************************************************************
** Form generated from reading UI file 'existingplaylistdialogImport.ui'
**
** Created: Sat Jan 12 15:30:47 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EXISTINGPLAYLISTDIALOGIMPORT_H
#define UI_EXISTINGPLAYLISTDIALOGIMPORT_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLabel *label_2;
    QPushButton *yesButton;
    QPushButton *replaceButton;
    QPushButton *noButton;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QString::fromUtf8("Dialog"));
        Dialog->resize(409, 157);
        label = new QLabel(Dialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 20, 391, 21));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 40, 391, 21));
        label_2->setAlignment(Qt::AlignCenter);
        yesButton = new QPushButton(Dialog);
        yesButton->setObjectName(QString::fromUtf8("yesButton"));
        yesButton->setGeometry(QRect(4, 110, 141, 31));
        replaceButton = new QPushButton(Dialog);
        replaceButton->setObjectName(QString::fromUtf8("replaceButton"));
        replaceButton->setGeometry(QRect(150, 110, 151, 31));
        noButton = new QPushButton(Dialog);
        noButton->setObjectName(QString::fromUtf8("noButton"));
        noButton->setGeometry(QRect(310, 110, 95, 31));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("Dialog", "A playlist with the same name is already existing", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("Dialog", "rename your pls file or choose an option below", 0, QApplication::UnicodeUTF8));
        yesButton->setText(QApplication::translate("Dialog", "Add songs", 0, QApplication::UnicodeUTF8));
        replaceButton->setText(QApplication::translate("Dialog", "Replace playlist", 0, QApplication::UnicodeUTF8));
        noButton->setText(QApplication::translate("Dialog", "Cancel", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EXISTINGPLAYLISTDIALOGIMPORT_H
