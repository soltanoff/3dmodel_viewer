#include "maindialog.h"
#include "ui_maindialog.h"
#include "viewsettings.h"


MainDialog::MainDialog(QWidget *parent) :
        QDialog(parent),
        ui(new Ui::MainDialog)
{
    this->ui->setupUi(this);
    this->setWindowFlags(
        Qt::Window |
        Qt::WindowMinimizeButtonHint |
        Qt::CustomizeWindowHint
    );

    // CONNECTIONS
    connect(
        this->ui->btnOpenFile,
        SIGNAL (clicked()),
        this,
        SLOT(getSceneFile())
    );
    connect(
        this->ui->btnViewScene,
        SIGNAL (clicked()),
        this,
        SLOT(viewModel())
    );
    connect(
        this->ui->btnClose,
        SIGNAL (clicked()),
        this,
        SLOT(close())
    );
}


void MainDialog::setSpeedValue(int value)
{
    this->ui->lcdSpeed->display(value);
}


void MainDialog::getSceneFile()
{
    QUrl sourceFileName;

    QWidget *container = new QWidget();
    QFileDialog dialog;

    dialog.setFileMode(QFileDialog::AnyFile);
    sourceFileName = dialog.getOpenFileUrl(
        container,
        QStringLiteral("Выберете файл..."),
        QUrl("/example/"),
        "Файл сцены (*.obj *.dae *.3ds)"
    );

    this->ui->edtSceneFile->setText(
                sourceFileName.toString().mid(8)
    );
}


void MainDialog::viewModel()
{
    ViewSettings params;
    params.sceneFile = this->ui->edtSceneFile->text();
    params.backgroundColor = Viewer::BACKGROUND_COLOR[
        this->ui->cmbBackgroundColor->currentIndex()
    ];
    params.speed = float(this->ui->lcdSpeed->value());
    params.resolution.height = Viewer::RESOLUTIONS[
        this->ui->cmbResolution->currentIndex()
    ][1];
    params.resolution.width = Viewer::RESOLUTIONS[
        this->ui->cmbResolution->currentIndex()
    ][0];

    this->m_viewer = new SceneViewer(params);
    this->m_viewer->exec(this->ui->edtSceneFile->text());
}


MainDialog::~MainDialog()
{
    delete this->ui;
    delete this->m_viewer;
}