#ifndef FRAMEWEATHER_H
#define FRAMEWEATHER_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class FrameWeather : public QFrame
{
    Q_OBJECT

public:
    explicit FrameWeather(QWidget *parent = nullptr);

private:
    QLabel *m_lblTitle = nullptr;
    QPushButton *m_btnLoad = nullptr;
};


#endif
