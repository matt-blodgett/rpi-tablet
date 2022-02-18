#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QMediaPlayer;
QT_END_NAMESPACE


class FrameNavbar;
class FrameHome;
class FrameMusic;
class FrameWeather;
class FrameSettings;


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    void initialize();
    void initializeObjects();
    void initializeLayout();
    void initializeState();
    void initializeStyle();

private:
    QMediaPlayer *m_mediaPlayer = nullptr;
    FrameNavbar *m_frmNavbar = nullptr;
    FrameHome *m_frmHome = nullptr;
    FrameMusic *m_frmMusic = nullptr;
    FrameWeather *m_frmWeather = nullptr;
    FrameSettings *m_frmSettings = nullptr;

public slots:
    void changeFrame(const QString &name);
};


#endif
