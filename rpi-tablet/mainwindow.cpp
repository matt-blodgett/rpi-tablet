#include "mainwindow.h"
#include "frames/framenavbar.h"
#include "frames/framehome.h"
#include "frames/framemusic.h"
#include "frames/frameweather.h"
#include "frames/framesettings.h"

#include <QMediaPlayer>

#include <QGridLayout>


#include <QDebug>


void MainWindow::initializeStyleSheet()
{
    centralWidget()->setObjectName("CentralWidget");
    m_frmNavbar->setObjectName("FrameNavbar");
    m_frmHome->setObjectName("FrameHome");
    m_frmMusic->setObjectName("FrameMusic");
    m_frmWeather->setObjectName("FrameWeather");
    m_frmSettings->setObjectName("FrameSettings");

    QString styleSheet = "";
//    styleSheet += "QWidget#CentralWidget { background-color: #00FF00; border: 1px solid #FF0000; } ";
    styleSheet += "QFrame#FrameNavbar { background-color: #00FF00; border: 1px solid #DDDDDD; } ";
    styleSheet += "QFrame#FrameHome { background-color: #CCCCFF; border: 1px solid #DDDDDD; } ";
    styleSheet += "QFrame#FrameMusic { background-color: #CCFFCC; border: 1px solid #DDDDDD; } ";
    styleSheet += "QFrame#FrameWeather { background-color: #FFCCCC; border: 1px solid #DDDDDD; } ";
    styleSheet += "QFrame#FrameSettings { background-color: #FF00FF; border: 1px solid #DDDDDD; } ";

    setStyleSheet(styleSheet);
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setFixedWidth(800);
    setFixedHeight(480);

    m_mediaPlayer = new QMediaPlayer(this);

    QWidget *frmMain = new QWidget(this);
    m_frmNavbar = new FrameNavbar(frmMain);
    m_frmHome = new FrameHome(frmMain);
    m_frmMusic = new FrameMusic(frmMain);
    m_frmWeather = new FrameWeather(frmMain);
    m_frmSettings = new FrameSettings(frmMain);

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
    centralWidget()->show();


    // testing
    initializeStyleSheet();

    connect(m_frmNavbar, &FrameNavbar::clickedOption, this, &MainWindow::changeFrame);
}
MainWindow::~MainWindow()
{

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
