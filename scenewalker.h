#ifndef SCENEWALKER_H
#define SCENEWALKER_H

#include <QObject>
#include <Qt3DRender/QCamera>
#include <Qt3DCore/QEntity>
#include <Qt3DCore/QAspectEngine>
#include <Qt3DInput/QInputAspect>
#include <Qt3DRender/QSceneLoader>
#include <Qt3DRender/QRenderAspect>
#include <Qt3DExtras/QForwardRenderer>
#include <Qt3DExtras/qt3dwindow.h>
#include <Qt3DExtras/QOrbitCameraController.h>


class SceneWalker : public QObject
{
public:
    SceneWalker(Qt3DRender::QSceneLoader *loader) : m_loader(loader) { }
    ~SceneWalker();
    void onStatusChanged();
private:
    void walkEntity(Qt3DCore::QEntity *e, int depth = 0);
    Qt3DRender::QSceneLoader *m_loader;
};

#endif // SCENEWALKER_H
