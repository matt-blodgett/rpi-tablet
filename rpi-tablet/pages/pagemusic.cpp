#include "pagemusic.h"

#include <QGridLayout>
#include <QPushButton>
#include <QLabel>
#include <QSlider>


#include <QDebug>


// playback icones = 40x40



#include <components/songlistview.h>


PageMusic::PageMusic(QWidget *parent) : QFrame(parent)
{
    m_frmSongListView = new SongListView(this);
    m_frmAlbumArt = new QWidget(this);
    m_lblSongTitle = new QLabel(this);
    m_lblArtistName = new QLabel(this);
    m_sldPosition = new QSlider(this);
    m_lblTimeElapsed = new QLabel(this);
    m_lblTimeRemaining = new QLabel(this);
    m_btnPlayPause = new QPushButton(this);
    m_btnNextSong = new QPushButton(this);
    m_btnBackSong = new QPushButton(this);
    m_sldVolume = new QSlider(this);

    m_lblSongTitle->setText("Song Title");
    m_lblArtistName->setText("Artist Name");
    m_sldPosition->setOrientation(Qt::Horizontal);
    m_lblTimeElapsed->setText("00:00");
    m_lblTimeRemaining->setText("00:00");
    m_sldVolume->setOrientation(Qt::Horizontal);

    m_frmAlbumArt->setFixedWidth(150);
    m_frmAlbumArt->setFixedHeight(150);


    connect(m_btnPlayPause, &QPushButton::clicked, this, [=]{m_frmSongListView->test();});


    m_frmAlbumArt->setObjectName("FrameAlbumArt");
    m_lblSongTitle->setObjectName("LabelSongTitle");
    m_lblArtistName->setObjectName("LabelArtistName");
    m_sldPosition->setObjectName("SliderPosition");
    m_lblTimeElapsed->setObjectName("LabelTimeElapsed");
    m_lblTimeRemaining->setObjectName("LabelTimeRemaining");
    m_btnPlayPause->setObjectName("ButtonPlayPause");
    m_btnNextSong->setObjectName("ButtonNextSong");
    m_btnBackSong->setObjectName("ButtonBackSong");
    m_sldVolume->setObjectName("SliderVolume");
    setObjectName("PageMusic");


    QGridLayout *grid1 = new QGridLayout();
    grid1->setContentsMargins(0, 0, 0, 0);
    grid1->setHorizontalSpacing(0);
    grid1->setVerticalSpacing(0);
    grid1->addWidget(m_frmAlbumArt, 0, 0, 4, 1);
    grid1->addWidget(m_lblSongTitle, 1, 1, 1, 1);
    grid1->addWidget(m_lblArtistName, 2, 1, 1, 1);
    grid1->setRowStretch(0, 1);
    grid1->setRowStretch(3, 1);
    grid1->setColumnStretch(1, 1);

    QGridLayout *grid2 = new QGridLayout();
    grid2->setContentsMargins(0, 0, 0, 0);
    grid2->setHorizontalSpacing(0);
    grid2->setVerticalSpacing(0);
    grid2->addWidget(m_sldPosition, 0, 0, 1, 3);
    grid2->addWidget(m_lblTimeElapsed, 1, 0, 1, 1);
    grid2->addWidget(m_lblTimeRemaining, 1, 2, 1, 1);
    grid2->setColumnStretch(1, 1);

    QGridLayout *grid3 = new QGridLayout();
    grid3->setContentsMargins(0, 0, 0, 0);
    grid3->setHorizontalSpacing(0);
    grid3->setVerticalSpacing(0);
    grid3->addWidget(m_btnBackSong, 0, 0, 1, 1);
    grid3->addWidget(m_btnPlayPause, 0, 1, 1, 1);
    grid3->addWidget(m_btnNextSong, 0, 2, 1, 1);
    grid3->addWidget(m_sldVolume, 1, 0, 1, 3);

    QGridLayout *gridRight = new QGridLayout();
    gridRight->addLayout(grid1, 0, 0, 1, 1, Qt::AlignTop);
    gridRight->addLayout(grid2, 1, 0, 1, 1, Qt::AlignCenter);
    gridRight->addLayout(grid3, 2, 0, 1, 1, Qt::AlignBottom);
    gridRight->setRowStretch(0, 1);
    gridRight->setRowStretch(1, 1);
    gridRight->setRowStretch(2, 1);
    gridRight->setColumnStretch(0, 1);

    QGridLayout *gridLeft = new QGridLayout();
    gridLeft->setContentsMargins(0, 0, 0, 0);
    gridLeft->setHorizontalSpacing(0);
    gridLeft->setVerticalSpacing(0);
    gridLeft->addWidget(m_frmSongListView, 0, 0, 1, 1);

    QGridLayout *gridMain = new QGridLayout();
//    gridMain->setContentsMargins(0, 0, 0, 0);
//    gridMain->setHorizontalSpacing(0);
//    gridMain->setVerticalSpacing(0);
    gridMain->addLayout(gridLeft, 0, 0, 1, 1);
    gridMain->addLayout(gridRight, 0, 1, 1, 1);
    gridMain->setRowStretch(0, 1);
    gridMain->setColumnStretch(0, 1);
    gridMain->setColumnStretch(1, 1);
    setLayout(gridMain);
}
QString PageMusic::pageTitle() const
{
    return "Music";
}

