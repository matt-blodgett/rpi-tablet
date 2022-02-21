#include "windowbanner.h"

#include <QGridLayout>
#include <QLabel>


#include <QDebug>


WindowBanner::WindowBanner(QWidget *parent) : QFrame(parent)
{
    m_lblTitle = new QLabel(this);
    m_lblClock = new QLabel(this);

    m_lblClock->setText("14:25");

    m_lblTitle->setObjectName("LabelTitle");
    m_lblClock->setObjectName("LabelTime");
    setObjectName("WindowBanner");

    QGridLayout *gridMain = new QGridLayout();
//    gridMain->setContentsMargins(0, 0, 0, 0);
//    gridMain->setHorizontalSpacing(0);
//    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_lblTitle, 0, 0, 1, 1, Qt::AlignLeft);
    gridMain->addWidget(m_lblClock, 0, 0, 1, 1, Qt::AlignCenter);
    gridMain->setRowStretch(0, 1);
    gridMain->setColumnStretch(0, 1);
    setLayout(gridMain);
}

void WindowBanner::setTitle(const QString &title)
{
    m_lblTitle->setText(title);
}
