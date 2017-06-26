#include "scenewalker.h"


void SceneWalker::onStatusChanged()
{
    if (this->m_loader->status() != Qt3DRender::QSceneLoader::Ready)
        return;

    QVector<Qt3DCore::QEntity *> entities = this->m_loader->entities();

    if (entities.isEmpty())
        return;

    Qt3DCore::QEntity *root = entities[0];
    walkEntity(root);
}


void SceneWalker::walkEntity(Qt3DCore::QEntity *e, int depth)
{
    Qt3DCore::QNodeVector nodes = e->childNodes();
    for (int i = 0; i < nodes.count(); ++i)
    {
        Qt3DCore::QNode *node = nodes[i];
        Qt3DCore::QEntity *entity = qobject_cast<Qt3DCore::QEntity *>(node);
        if (entity)
        {
            QString indent;
            indent.fill(' ', depth * 2);
            walkEntity(entity, depth + 1);
        }
    }
}


SceneWalker::~SceneWalker()
{
    delete this->m_loader;
}
