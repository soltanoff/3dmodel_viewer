#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include "sceneviewer.h"
#include <QDialog>


namespace Ui {
class MainDialog;
}
class MainDialog : public QDialog
{
    Q_OBJECT

public:
    MainDialog(QWidget *parent = 0);
    ~MainDialog();

private:
    Ui::MainDialog *ui;
    SceneViewer *m_viewer;

private slots:
    void getSceneFile();
    void viewModel();
    void setSpeedValue(int value);
};

#endif // MAINDIALOG_H
