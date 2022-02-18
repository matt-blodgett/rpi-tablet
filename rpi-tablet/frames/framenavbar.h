#ifndef FRAMENAVBAR_H
#define FRAMENAVBAR_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE


class FrameNavbar : public QFrame
{
    Q_OBJECT

public:
    explicit FrameNavbar(QWidget *parent = nullptr);

private:
    QPushButton *m_btnHome = nullptr;
    QPushButton *m_btnMusic = nullptr;
    QPushButton *m_btnWeather = nullptr;
    QPushButton *m_btnSettings = nullptr;

signals:
    void clickedOption(const QString &option);
};


#endif
