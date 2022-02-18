#ifndef FRAMEHOME_H
#define FRAMEHOME_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class FrameHome : public QFrame
{
    Q_OBJECT

public:
    explicit FrameHome(QWidget *parent = nullptr);

private:
    QLabel *m_lblTitle = nullptr;
    QPushButton *m_btnLoad = nullptr;
};


#endif
