#include "windownavbar.h"

#include <QGridLayout>
#include <QPushButton>


#include <QDebug>


WindowNavbar::WindowNavbar(QWidget *parent) : QFrame(parent)
{
    initialize();
}

void WindowNavbar::initialize()
{
    initializeObjects();
    initializeLayout();
}
void WindowNavbar::initializeObjects()
{
    m_btnHome = new QPushButton(this);
    m_btnMusic = new QPushButton(this);
    m_btnWeather = new QPushButton(this);
    m_btnSettings = new QPushButton(this);

    m_btnHome->setIcon(QIcon(":/icons/navbar/home.png"));
    m_btnMusic->setIcon(QIcon(":/icons/navbar/music.png"));
    m_btnWeather->setIcon(QIcon(":/icons/navbar/weather.png"));
    m_btnSettings->setIcon(QIcon(":/icons/navbar/settings.png"));

    m_btnHome->setIconSize(QSize(48, 48));
    m_btnMusic->setIconSize(QSize(48, 48));
    m_btnWeather->setIconSize(QSize(48, 48));
    m_btnSettings->setIconSize(QSize(48, 48));

    connect(m_btnHome, &QPushButton::clicked, this, [=]{emit optionClicked("home");});
    connect(m_btnMusic, &QPushButton::clicked, this, [=]{emit optionClicked("music");});
    connect(m_btnWeather, &QPushButton::clicked, this, [=]{emit optionClicked("weather");});
    connect(m_btnSettings, &QPushButton::clicked, this, [=]{emit optionClicked("settings");});
}
void WindowNavbar::initializeLayout()
{
    QGridLayout *gridFrame = new QGridLayout();
//    gridFrame->setContentsMargins(5, 5, 5, 5);
//    gridFrame->setHorizontalSpacing(0);
//    gridFrame->setVerticalSpacing(0);
    gridFrame->addWidget(m_btnHome, 0, 0, 1, 1);
    gridFrame->addWidget(m_btnMusic, 1, 0, 1, 1);
    gridFrame->addWidget(m_btnWeather, 2, 0, 1, 1);
    gridFrame->addWidget(m_btnSettings, 3, 0, 1, 1);
    gridFrame->setRowStretch(4, 1);
    setLayout(gridFrame);
}
