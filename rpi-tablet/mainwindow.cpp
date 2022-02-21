#include "mainwindow.h"
#include "window/windowbanner.h"
#include "window/windownavbar.h"
#include "pages/pagehome.h"
#include "pages/pagemusic.h"
#include "pages/pageweather.h"
#include "pages/pagesettings.h"

#include <QGridLayout>

#include <QMediaPlayer>
#include <QFile>

#include <QAction>
#include <QMenuBar>


#include <QDebug>


void MainWindow::refreshStylesheet()
{
    QFile file("/home/matt/Desktop/rpi-tablet/rpi-tablet/assets/styles/default.qss");
    if (file.open(QIODevice::ReadOnly)) {
        QString qss = file.readAll();
        setStyleSheet(qss);
    }
}


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    initialize();

    QAction *actRefreshStylesheet = new QAction("Refresh Stylesheet", this);
    connect(actRefreshStylesheet, &QAction::triggered, this, &MainWindow::refreshStylesheet);
    menuBar()->addAction(actRefreshStylesheet);

    // testing (should come from settings)
    setGeometry(2300, 250, 800, 480);
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
    m_frmBanner = new WindowBanner(this);
    m_frmNavbar = new WindowNavbar(this);
    m_frmHome = new PageHome(this);
    m_frmMusic = new PageMusic(this);
    m_frmWeather = new PageWeather(this);
    m_frmSettings = new PageSettings(this);

    connect(m_frmNavbar, &WindowNavbar::optionClicked, this, &MainWindow::changePage);
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
    gridMain->addWidget(m_frmBanner, 0, 0, 1, 2);
    gridMain->addWidget(m_frmNavbar, 1, 1, 1, 1);
    gridMain->addWidget(m_frmHome, 1, 0, 1, 1);
    gridMain->addWidget(m_frmMusic, 1, 0, 1, 1);
    gridMain->addWidget(m_frmWeather, 1, 0, 1, 1);
    gridMain->addWidget(m_frmSettings, 1, 0, 1, 1);
    gridMain->setRowStretch(1, 1);
    gridMain->setColumnStretch(0, 1);
    frmMain->setLayout(gridMain);

    setCentralWidget(frmMain);

    m_frmMusic->hide();
    m_frmWeather->hide();
    m_frmSettings->hide();
    m_frmBanner->setTitle(m_frmHome->pageTitle());
}
void MainWindow::initializeState()
{

}
void MainWindow::initializeStyle()
{
    QFile file(":/styles/default.qss");
    if (file.open(QIODevice::ReadOnly)) {
        QString qss = file.readAll();
        setStyleSheet(qss);
    }
}

void MainWindow::changePage(const QString &name)
{
    if (name == "home" && m_frmHome->isHidden()) {
        m_frmMusic->hide();
        m_frmWeather->hide();
        m_frmSettings->hide();
        m_frmHome->show();
        m_frmBanner->setTitle(m_frmHome->pageTitle());
    } else if (name == "music" && m_frmMusic->isHidden()) {
        m_frmHome->hide();
        m_frmWeather->hide();
        m_frmSettings->hide();
        m_frmMusic->show();
        m_frmBanner->setTitle(m_frmMusic->pageTitle());
    } else if (name == "weather" && m_frmWeather->isHidden()) {
        m_frmHome->hide();
        m_frmMusic->hide();
        m_frmSettings->hide();
        m_frmWeather->show();
        m_frmBanner->setTitle(m_frmWeather->pageTitle());
    } else if (name == "settings" && m_frmSettings->isHidden()) {
        m_frmHome->hide();
        m_frmMusic->hide();
        m_frmWeather->hide();
        m_frmSettings->show();
        m_frmBanner->setTitle(m_frmSettings->pageTitle());
    }
}
