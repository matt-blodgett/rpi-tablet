#ifndef PAGEHOME_H
#define PAGEHOME_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QLabel;
QT_END_NAMESPACE


class PageHome : public QFrame
{
    Q_OBJECT

public:
    explicit PageHome(QWidget *parent = nullptr);
    QString pageTitle() const;

private:
    void initialize();
    void initializeObjects();
    void initializeLayout();

private:
    QLabel *m_lblPlaceholder = nullptr;
};


#endif
