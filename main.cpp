#include <QApplication>

#include "sceneviewer.h"
#include "maindialog.h"


int main(int argc, char **argv)
{
    QApplication app(argc, argv);
    QStringList args = QCoreApplication::arguments();

    MainDialog *win = new MainDialog();
    win->show();

    return app.exec();
}