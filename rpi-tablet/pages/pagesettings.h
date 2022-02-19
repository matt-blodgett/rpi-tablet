#ifndef PAGESETTINGS_H
#define PAGESETTINGS_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE


class PageSettings : public QFrame
{
    Q_OBJECT

public:
    explicit PageSettings(QWidget *parent = nullptr);
    QString pageTitle() const;

private:
    void initialize();
    void initializeObjects();
    void initializeLayout();

private:
    QLabel *m_lblPlaceholder = nullptr;
};


#endif
