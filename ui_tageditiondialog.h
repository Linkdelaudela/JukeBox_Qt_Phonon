/********************************************************************************
** Form generated from reading UI file 'tageditiondialog.ui'
**
** Created: Sat Jan 12 20:25:45 2013
**      by: Qt User Interface Compiler version 4.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TAGEDITIONDIALOG_H
#define UI_TAGEDITIONDIALOG_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QDialog>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QPlainTextEdit>
#include <QtGui/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_TagEditionDialog
{
public:
    QPlainTextEdit *artistEdit;
    QLabel *label;
    QPlainTextEdit *albumEdit;
    QLabel *label_2;
    QPlainTextEdit *titleEdit;
    QLabel *label_3;
    QPushButton *cancelButton;
    QPushButton *saveButton;

    void setupUi(QDialog *TagEditionDialog)
    {
        if (TagEditionDialog->objectName().isEmpty())
            TagEditionDialog->setObjectName(QString::fromUtf8("TagEditionDialog"));
        TagEditionDialog->resize(400, 309);
        artistEdit = new QPlainTextEdit(TagEditionDialog);
        artistEdit->setObjectName(QString::fromUtf8("artistEdit"));
        artistEdit->setGeometry(QRect(10, 30, 381, 61));
        label = new QLabel(TagEditionDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(6, 10, 81, 21));
        albumEdit = new QPlainTextEdit(TagEditionDialog);
        albumEdit->setObjectName(QString::fromUtf8("albumEdit"));
        albumEdit->setGeometry(QRect(10, 110, 381, 61));
        label_2 = new QLabel(TagEditionDialog);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(6, 90, 81, 21));
        titleEdit = new QPlainTextEdit(TagEditionDialog);
        titleEdit->setObjectName(QString::fromUtf8("titleEdit"));
        titleEdit->setGeometry(QRect(10, 190, 381, 61));
        label_3 = new QLabel(TagEditionDialog);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(6, 170, 81, 21));
        cancelButton = new QPushButton(TagEditionDialog);
        cancelButton->setObjectName(QString::fromUtf8("cancelButton"));
        cancelButton->setGeometry(QRect(10, 270, 95, 31));
        saveButton = new QPushButton(TagEditionDialog);
        saveButton->setObjectName(QString::fromUtf8("saveButton"));
        saveButton->setGeometry(QRect(290, 270, 95, 31));

        retranslateUi(TagEditionDialog);

        QMetaObject::connectSlotsByName(TagEditionDialog);
    } // setupUi

    void retranslateUi(QDialog *TagEditionDialog)
    {
        TagEditionDialog->setWindowTitle(QApplication::translate("TagEditionDialog", "Dialog", 0, QApplication::UnicodeUTF8));
        label->setText(QApplication::translate("TagEditionDialog", "Artist", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("TagEditionDialog", "Album", 0, QApplication::UnicodeUTF8));
        label_3->setText(QApplication::translate("TagEditionDialog", "Title", 0, QApplication::UnicodeUTF8));
        cancelButton->setText(QApplication::translate("TagEditionDialog", "Cancel", 0, QApplication::UnicodeUTF8));
        saveButton->setText(QApplication::translate("TagEditionDialog", "Save", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class TagEditionDialog: public Ui_TagEditionDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TAGEDITIONDIALOG_H
