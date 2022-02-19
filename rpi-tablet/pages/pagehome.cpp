#include "pagehome.h"

#include <QGridLayout>
#include <QLabel>


#include <QDebug>


PageHome::PageHome(QWidget *parent) : QFrame(parent)
{
    initialize();
}
QString PageHome::pageTitle() const
{
    return "Home";
}

void PageHome::initialize()
{
    initializeObjects();
    initializeLayout();
}
void PageHome::initializeObjects()
{
    m_lblPlaceholder = new QLabel(this);
    m_lblPlaceholder->setText("Welcome to the project!");
    m_lblPlaceholder->setObjectName("PagePlaceholder");
}
void PageHome::initializeLayout()
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
