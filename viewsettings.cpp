#include "viewsettings.h"


namespace Viewer {
int RESOLUTIONS[4][2] = {
    {800,   600},       // 1
    {1024,  800},       // 2
    {1378,  764},       // 3
    {1980,  1080}       // 4
};
Qt::GlobalColor BACKGROUND_COLOR[17] = {
    Qt::white,          // 1
    Qt::black,          // 2
    Qt::red,            // 3
    Qt::darkRed,        // 4
    Qt::green,          // 5
    Qt::darkGreen,      // 6
    Qt::blue,           // 7
    Qt::darkBlue,       // 8
    Qt::cyan,           // 9
    Qt::darkCyan,       // 10
    Qt::magenta,        // 11
    Qt::darkMagenta,    // 12
    Qt::yellow,         // 13
    Qt::darkYellow,     // 14
    Qt::gray,           // 15
    Qt::darkGray,       // 16
    Qt::lightGray       // 17
};
}