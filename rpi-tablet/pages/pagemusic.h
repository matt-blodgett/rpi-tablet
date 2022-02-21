#ifndef PAGEMUSIC_H
#define PAGEMUSIC_H


#include <QFrame>


QT_BEGIN_NAMESPACE
class QPushButton;
class QLabel;
class QSlider;
QT_END_NAMESPACE


class SongListView;


class PageMusic : public QFrame
{
    Q_OBJECT

public:
    explicit PageMusic(QWidget *parent = nullptr);
    QString pageTitle() const;

private:
    SongListView *m_frmSongListView = nullptr;
    QWidget *m_frmAlbumArt = nullptr;
    QLabel *m_lblSongTitle = nullptr;
    QLabel *m_lblArtistName = nullptr;
    QSlider *m_sldPosition = nullptr;
    QLabel *m_lblTimeElapsed = nullptr;
    QLabel *m_lblTimeRemaining = nullptr;
    QPushButton *m_btnPlayPause = nullptr;
    QPushButton *m_btnNextSong = nullptr;
    QPushButton *m_btnBackSong = nullptr;
    QSlider *m_sldVolume = nullptr;
};


#endif
