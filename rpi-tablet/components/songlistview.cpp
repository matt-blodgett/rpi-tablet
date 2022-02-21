#include "songlistview.h"



#include <QGridLayout>
#include <QScrollArea>


#include <QLabel>
#include <QImage>


#include <QDir>


#include <QMouseEvent>
#include <QStyle>



#define DIR_MP3_FILES "/home/matt/Desktop/mpi3-files/songs"




//    QLabel *imageLabel = new QLabel(this);
//    QImage image("/home/matt/Desktop/image.png");
//    imageLabel->setPixmap(QPixmap::fromImage(image));

//    m_frmScrollArea->setBackgroundRole(QPalette::Dark);
//    m_frmScrollArea->setWidget(imageLabel);



QStringList getMp3Files() {
    QDir dir(DIR_MP3_FILES);
    QStringList allFiles = dir.entryList(QDir::Files);
    QStringList mp3Files;
    for (QString &file: allFiles) {
        if (file.endsWith(".mp3")) {
            mp3Files << file;
        }
    }
    return mp3Files;
}


Song::Song(QObject *parent) : QObject(parent)
{

}


SongListViewItem::SongListViewItem(QWidget *parent) : QFrame(parent)
{
    m_lblName = new QLabel(this);

    QGridLayout *gridMain = new QGridLayout();
    //    gridMain->setContentsMargins(0, 0, 0, 0);
    //    gridMain->setHorizontalSpacing(0);
    //    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_lblName, 0, 0, 1, 1);
    gridMain->setRowStretch(0, 1);
    gridMain->setColumnStretch(0, 1);
    setLayout(gridMain);

    m_lblName->setObjectName("SongListViewItemLabelName");
    setObjectName("SongListViewItem");
}

void SongListViewItem::setSong(const Song *song)
{
    m_lblName->setText(song->name);
}

void SongListViewItem::mousePressEvent(QMouseEvent *event)
{
    event->accept();
    setObjectName("SongListViewItem-Pressed");
    style()->unpolish(this);
    style()->polish(this);
}



SongListView::SongListView(QWidget *parent) : QFrame(parent)
{
    // ---------------------------------------------------------------------------
    for (int i = 0; i < 20; i++) {
        Song *song = new Song(this);
        song->name = "song" + QString::number(i);
        song->artist = "artist";
        song->path = "";

        m_songs << song;
    }


    // ---------------------------------------------------------------------------
    m_frmScrollArea = new QScrollArea(this);


    m_frmSongs = new QWidget(m_frmScrollArea);
    m_gridSongs = new QGridLayout();
    m_gridSongs->setContentsMargins(0, 0, 0, 0);
    m_gridSongs->setHorizontalSpacing(0);
    m_gridSongs->setVerticalSpacing(0);
    m_frmSongs->setLayout(m_gridSongs);
    m_frmSongs->setObjectName("SongListViewScrollAreaWidget");


    // ---------------------------------------------------------------------------
    m_frmScrollArea->setWidget(m_frmSongs);
    m_frmScrollArea->setWidgetResizable(true);
    m_frmScrollArea->setBackgroundRole(QPalette::Dark);


    // ---------------------------------------------------------------------------
    QGridLayout *gridMain = new QGridLayout();
    gridMain->setContentsMargins(0, 0, 0, 0);
    gridMain->setHorizontalSpacing(0);
    gridMain->setVerticalSpacing(0);
    gridMain->addWidget(m_frmScrollArea, 0, 0, 1, 1);
    gridMain->setRowStretch(0, 1);
    gridMain->setColumnStretch(0, 1);
    setLayout(gridMain);
}


void SongListView::test()
{
//    QLayoutItem *child;
//    while ((child = m_gridSongs->takeAt(0)) != nullptr) {
//        delete child->widget();
//        delete child;
//    }

    for (int i = 0; i < m_songs.length(); i++) {
        SongListViewItem *item = new SongListViewItem(m_frmSongs);
        item->setSong(m_songs[i]);
        m_gridSongs->addWidget(item, i + m_gridSongs->count(), 0, 1, 1);
    }

}













