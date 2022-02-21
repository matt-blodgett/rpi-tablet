#ifndef WINDOWNAVBAR_H
#define WINDOWNAVBAR_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QPushButton;
QT_END_NAMESPACE


class WindowNavbar : public QFrame
{
    Q_OBJECT

public:
    explicit WindowNavbar(QWidget *parent = nullptr);

private:
    QPushButton *m_btnHome = nullptr;
    QPushButton *m_btnMusic = nullptr;
    QPushButton *m_btnWeather = nullptr;
    QPushButton *m_btnSettings = nullptr;

signals:
    void optionClicked(const QString &option);
};


#endif
