#ifndef VIEWSETTINGS_H
#define VIEWSETTINGS_H

#include <QApplication>


struct ViewSettings
{
    QString sceneFile;
    Qt::GlobalColor backgroundColor;
    float speed;
    struct {
        int width;
        int height;
    } resolution;
};


namespace Viewer {
extern int RESOLUTIONS[4][2];
extern Qt::GlobalColor BACKGROUND_COLOR[17];
}
#endif // VIEWSETTINGS_H