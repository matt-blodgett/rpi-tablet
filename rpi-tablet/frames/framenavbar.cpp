#include "framenavbar.h"

#include <QGridLayout>
#include <QPushButton>


#include <QDebug>


FrameNavbar::FrameNavbar(QWidget *parent) : QFrame(parent)
{
    m_btnHome = new QPushButton(this);
    m_btnMusic = new QPushButton(this);
    m_btnWeather = new QPushButton(this);
    m_btnSettings = new QPushButton(this);

    QGridLayout *gridMain = new QGridLayout();
//    gridMain->setContentsMargins(5, 5, 5, 5);
//    gridMain->setHorizontalSpacing(0);
//    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_btnHome, 0, 0, 1, 1);
    gridMain->addWidget(m_btnMusic, 1, 0, 1, 1);
    gridMain->addWidget(m_btnWeather, 2, 0, 1, 1);
    gridMain->addWidget(m_btnSettings, 3, 0, 1, 1);
    gridMain->setRowStretch(4, 1);
    setLayout(gridMain);

    m_btnHome->setText("1");
    m_btnMusic->setText("2");
    m_btnWeather->setText("3");
    m_btnSettings->setText("4");

    connect(m_btnHome, &QPushButton::clicked, this, [=]{emit clickedOption("home");});
    connect(m_btnMusic, &QPushButton::clicked, this, [=]{emit clickedOption("music");});
    connect(m_btnWeather, &QPushButton::clicked, this, [=]{emit clickedOption("weather");});
    connect(m_btnSettings, &QPushButton::clicked, this, [=]{emit clickedOption("settings");});
}
