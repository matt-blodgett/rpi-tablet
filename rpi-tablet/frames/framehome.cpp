#include "framehome.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>


#include <QDebug>


FrameHome::FrameHome(QWidget *parent) : QFrame(parent)
{
    m_lblTitle = new QLabel(this);
    m_btnLoad = new QPushButton(this);

    QGridLayout *gridMain = new QGridLayout();
    gridMain->setContentsMargins(0, 0, 0, 0);
    gridMain->setHorizontalSpacing(0);
    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_lblTitle, 0, 0, 1, 1);
    gridMain->addWidget(m_btnLoad, 1, 0, 1, 1);
    gridMain->setRowStretch(2, 1);
    gridMain->setColumnStretch(0, 1);
    setLayout(gridMain);

    m_lblTitle->setText("Home Page");
    m_btnLoad->setText("Load");
}
