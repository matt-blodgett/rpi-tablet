#ifndef FRAMESETTINGS_H
#define FRAMESETTINGS_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
QT_END_NAMESPACE


class FrameSettings : public QFrame
{
    Q_OBJECT

public:
    explicit FrameSettings(QWidget *parent = nullptr);

private:
    QLabel *m_lblTitle = nullptr;
    QPushButton *m_btnLoad = nullptr;
};


#endif
