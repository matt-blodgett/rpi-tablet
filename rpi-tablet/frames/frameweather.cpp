#include "frameweather.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>


#include <QDebug>


FrameWeather::FrameWeather(QWidget *parent) : QFrame(parent)
{
    m_lblTitle = new QLabel(this);
    m_btnLoad = new QPushButton(this);

    QGridLayout *gridMain = new QGridLayout();
    gridMain->setContentsMargins(0, 0, 0, 0);
    gridMain->addWidget(m_lblTitle, 0, 0, 1, 1);
    gridMain->addWidget(m_btnLoad, 1, 0, 1, 1);
    gridMain->setRowStretch(2, 1);
    gridMain->setColumnStretch(0, 1);
    setLayout(gridMain);

    m_lblTitle->setText("Weather Report");
    m_btnLoad->setText("Load");
}
