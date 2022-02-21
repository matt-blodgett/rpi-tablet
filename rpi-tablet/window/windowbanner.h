#ifndef WINDOWBANNER_H
#define WINDOWBANNER_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE


class WindowBanner : public QFrame
{
    Q_OBJECT

public:
    explicit WindowBanner(QWidget *parent = nullptr);

public:
    void setTitle(const QString &title);

private:
    QLabel *m_lblTitle = nullptr;
    QLabel *m_lblClock = nullptr;
};


#endif
