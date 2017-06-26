#include "sceneviewer.h"


SceneViewer::SceneViewer(ViewSettings params)
{
    this->_view.setTitle("[4332] Просмотр моделей");
    this->_view.defaultFramegraph()->setClearColor(params.backgroundColor);
    this->_view.setWidth(params.resolution.width);
    this->_view.setHeight(params.resolution.height);

    this->m_sceneRoot = new Qt3DCore::QEntity();

    this->m_camera = this->_view.camera();

    this->setCameraSettings(float(params.speed));
    this->setSceneLoader();
}


void SceneViewer::setCameraSettings(float speed=250.0f)
{
    // Scene Camera
    this->m_camera->setProjectionType(Qt3DRender::QCameraLens::PerspectiveProjection);
    this->m_camera->setViewCenter(QVector3D(0.0f, 0.0f, 0.0f));
    this->m_camera->setPosition(QVector3D(50.0f, 10.0f, 0.0f));
    this->m_camera->setNearPlane(0.001f);
    this->m_camera->setFarPlane(100.0f);
    // For camera controls
    this->m_camController = new Qt3DExtras::QOrbitCameraController(this->m_sceneRoot);
    this->m_camController->setLinearSpeed(speed);
    this->m_camController->setLookSpeed(speed);
    this->m_camController->setCamera(this->m_camera);
}


void SceneViewer::setSceneLoader()
{
    this->m_sceneLoaderEntity = new Qt3DCore::QEntity(this->m_sceneRoot);
    this->m_sceneLoader = new Qt3DRender::QSceneLoader(this->m_sceneLoaderEntity);
    this->m_sceneWalker = new SceneWalker(this->m_sceneLoader);

    QObject::connect(
        this->m_sceneLoader,
        &Qt3DRender::QSceneLoader::statusChanged,
        this->m_sceneWalker,
        &SceneWalker::onStatusChanged
    );
    this->m_sceneLoaderEntity->addComponent(this->m_sceneLoader);
}


int SceneViewer::exec(QString file)
{
    if (file.isEmpty())
        return 0;

    this->m_sceneLoader->setSource(QUrl("file:///" + file));

    this->_view.setRootEntity(this->m_sceneRoot);
    this->_view.show();

    return 0;
}


SceneViewer::~SceneViewer()
{
    delete this->m_app;

    delete this->m_sceneRoot;
    delete this->m_camera;
    delete this->m_camController;
    delete this->m_sceneLoaderEntity;
    delete this->m_sceneLoader;

    delete this->m_sceneWalker;
}