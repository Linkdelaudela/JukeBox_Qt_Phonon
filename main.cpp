#include <QApplication>
#include "cutesong.h"

int main(int argc, char *argv[])
{
    // Prise en cgarge des accents.
    QTextCodec::setCodecForCStrings(QTextCodec::codecForName("UTF-8"));
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    QApplication a(argc, argv);

    // Necessaire a PulseAudio
    a.setApplicationName("CuteSong");

    CuteSong w;

    w.show();

    return a.exec();
}
