#-------------------------------------------------
#
# Project created by QtCreator 2012-11-21T08:39:28
#
#-------------------------------------------------

QT       += core gui phonon sql webkit

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = newPhonon
TEMPLATE = app

SOURCES += main.cpp\
        cutesong.cpp \
    classSQL.cpp \
    song.cpp \
    playlist.cpp \
    newplaylistdialog.cpp \
    existingplaylistdialog.cpp \
    renameplaylistdialog.cpp \
    tageditiondialog.cpp \
    importexport.cpp \
    existingplaylistimportdialog.cpp

HEADERS  += cutesong.h \
    classSQL.h \
    song.h \
    playlist.h \
    newplaylistdialog.h \
    existingplaylistdialog.h \
    renameplaylistdialog.h \
    tageditiondialog.h \
    importexport.h \
    existingplaylistimportdialog.h

FORMS    += cutesong.ui \
    newplaylistdialog.ui \
    existingplaylistdialog.ui \
    renameplaylistdialog.ui \
    tageditiondialog.ui \
    existingplaylistimportdialog.ui

win32:CONFIG(release, debug|release): LIBS += -L/usr/local/lib/release/ -ltag
else:win32:CONFIG(debug, debug|release): LIBS += -L/usr/local/lib/debug/ -ltag
else:symbian: LIBS += -ltag
else:unix: LIBS += -L/usr/local/lib/ -ltag

INCLUDEPATH += /usr/local/include
DEPENDPATH += /usr/local/include
