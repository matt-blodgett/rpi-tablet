#ifndef SONGLISTVIEW_H
#define SONGLISTVIEW_H



#include <QFrame>



QT_BEGIN_NAMESPACE
class QScrollArea;
class QLabel;
class QGridLayout;
QT_END_NAMESPACE



class Song : public QObject
{
    Q_OBJECT

public:
    explicit Song(QObject *parent = nullptr);

public:
    QString name;
    QString artist;
    QString path;
};


class SongListViewItem : public QFrame
{
    Q_OBJECT

public:
    explicit SongListViewItem(QWidget *parent = nullptr);

public:
    void setSong(const Song *song);

private:
    QLabel *m_lblName = nullptr;

protected:
    void mousePressEvent(QMouseEvent *event);
};


class SongListView : public QFrame
{
    Q_OBJECT

public:
    explicit SongListView(QWidget *parent = nullptr);

public:
    void test();

private:
    QScrollArea *m_frmScrollArea = nullptr;

    QWidget *m_frmSongs = nullptr;
    QGridLayout *m_gridSongs = nullptr;

    QVector<Song*> m_songs;

signals:

};


#endif
