#ifndef PAGEWEATHER_H
#define PAGEWEATHER_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE


class PageWeather : public QFrame
{
    Q_OBJECT

public:
    explicit PageWeather(QWidget *parent = nullptr);
    QString pageTitle() const;

private:
    QLabel *m_lblPlaceholder = nullptr;
};


#endif
