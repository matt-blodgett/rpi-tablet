#include "mainwindow.h"
#include "frames/framenavbar.h"
#include "frames/framehome.h"
#include "frames/framemusic.h"
#include "frames/frameweather.h"
#include "frames/framesettings.h"

#include <QMediaPlayer>
#include <QFile>

#include <QGridLayout>


#include <QDebug>


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initialize();
}
MainWindow::~MainWindow()
{

}

void MainWindow::initialize()
{
    initializeObjects();
    initializeLayout();
    initializeState();
    initializeStyle();
    centralWidget()->show();
}
void MainWindow::initializeObjects()
{
    m_mediaPlayer = new QMediaPlayer(this);
    m_frmNavbar = new FrameNavbar(this);
    m_frmHome = new FrameHome(this);
    m_frmMusic = new FrameMusic(this);
    m_frmWeather = new FrameWeather(this);
    m_frmSettings = new FrameSettings(this);

    connect(m_frmNavbar, &FrameNavbar::clickedOption, this, &MainWindow::changeFrame);
}
void MainWindow::initializeLayout()
{
    setFixedWidth(800);
    setFixedHeight(480);

    QWidget *frmMain = new QWidget(this);
    QGridLayout *gridMain = new QGridLayout();
    gridMain->setContentsMargins(0, 0, 0, 0);
    gridMain->setHorizontalSpacing(0);
    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_frmNavbar, 0, 1, 1, 1);
    gridMain->addWidget(m_frmHome, 0, 0, 1, 1);
    gridMain->addWidget(m_frmMusic, 0, 0, 1, 1);
    gridMain->addWidget(m_frmWeather, 0, 0, 1, 1);
    gridMain->addWidget(m_frmSettings, 0, 0, 1, 1);
    gridMain->setRowStretch(0, 1);
    gridMain->setColumnStretch(0, 1);
    frmMain->setLayout(gridMain);

    m_frmMusic->hide();
    m_frmWeather->hide();
    m_frmSettings->hide();

    setCentralWidget(frmMain);
}
void MainWindow::initializeState()
{

}
void MainWindow::initializeStyle()
{
    m_frmNavbar->setObjectName("FrameNavbar");
    m_frmHome->setObjectName("FrameHome");
    m_frmMusic->setObjectName("FrameMusic");
    m_frmWeather->setObjectName("FrameWeather");
    m_frmSettings->setObjectName("FrameSettings");

    QFile file(":/styles/default.qss");
    if (file.open(QIODevice::ReadOnly)) {
        QString qss = file.readAll();
        setStyleSheet(qss);
    }
}

void MainWindow::changeFrame(const QString &name)
{
    if (name == "home" && m_frmHome->isHidden()) {
        m_frmMusic->hide();
        m_frmWeather->hide();
        m_frmSettings->hide();
        m_frmHome->show();
    } else if (name == "music" && m_frmMusic->isHidden()) {
        m_frmHome->hide();
        m_frmWeather->hide();
        m_frmSettings->hide();
        m_frmMusic->show();
    } else if (name == "weather" && m_frmWeather->isHidden()) {
        m_frmHome->hide();
        m_frmMusic->hide();
        m_frmSettings->hide();
        m_frmWeather->show();
    } else if (name == "settings" && m_frmSettings->isHidden()) {
        m_frmHome->hide();
        m_frmMusic->hide();
        m_frmWeather->hide();
        m_frmSettings->show();
    }
}
