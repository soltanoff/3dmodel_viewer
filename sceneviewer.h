#ifndef SCENEVIEWER_H
#define SCENEVIEWER_H

#include <QFileDialog>
#include <QApplication>
#include "scenewalker.h"
#include "viewsettings.h"


class SceneViewer : public QObject
{
public:
    SceneViewer(ViewSettings params);
    ~SceneViewer();
    int exec(QString filename);

private:
    Qt3DExtras::Qt3DWindow _view;
    QApplication *m_app;

    Qt3DCore::QEntity *m_sceneRoot;
    Qt3DRender::QCamera *m_camera;
    Qt3DExtras::QOrbitCameraController *m_camController;
    Qt3DCore::QEntity *m_sceneLoaderEntity;
    Qt3DRender::QSceneLoader *m_sceneLoader;

    SceneWalker *m_sceneWalker;

    void setCameraSettings(float speed);
    void setSceneLoader();
};

#endif // SCENEVIEWER_H
