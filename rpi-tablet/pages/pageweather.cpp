#include "pageweather.h"

#include <QGridLayout>
#include <QLabel>


#include <QDebug>


PageWeather::PageWeather(QWidget *parent) : QFrame(parent)
{
    initialize();
}
QString PageWeather::pageTitle() const
{
    return "Weather";
}

void PageWeather::initialize()
{
    initializeObjects();
    initializeLayout();
}
void PageWeather::initializeObjects()
{
    m_lblPlaceholder = new QLabel(this);
    m_lblPlaceholder->setText("This feature is not currently available.");
    m_lblPlaceholder->setObjectName("PagePlaceholder");
}
void PageWeather::initializeLayout()
{
    QGridLayout *gridMain = new QGridLayout();
    gridMain->setContentsMargins(0, 0, 0, 0);
    gridMain->setHorizontalSpacing(0);
    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_lblPlaceholder, 0, 0, 1, 1, Qt::AlignCenter);
    gridMain->setRowStretch(0, 1);
    gridMain->setColumnStretch(0, 1);
    setLayout(gridMain);
}
