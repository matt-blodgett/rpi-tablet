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

private:
    void initialize();
    void initializeObjects();
    void initializeLayout();

private:
    QLabel *m_lblTitle = nullptr;
    QLabel *m_lblClock = nullptr;

public:
    void setTitle(const QString &title);
};


#endif
