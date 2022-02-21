#include "pagesettings.h"

#include <QGridLayout>
#include <QLabel>


#include <QDebug>


PageSettings::PageSettings(QWidget *parent) : QFrame(parent)
{
    m_lblPlaceholder = new QLabel(this);
    m_lblPlaceholder->setText("This feature is not currently available.");
    m_lblPlaceholder->setObjectName("LabelPlaceholder");
    setObjectName("PageSettings");

    QGridLayout *gridMain = new QGridLayout();
    gridMain->setContentsMargins(0, 0, 0, 0);
    gridMain->setHorizontalSpacing(0);
    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_lblPlaceholder, 0, 0, 1, 1, Qt::AlignCenter);
    gridMain->setRowStretch(0, 1);
    gridMain->setColumnStretch(0, 1);
    setLayout(gridMain);
}
QString PageSettings::pageTitle() const
{
    return "Settings";
}
