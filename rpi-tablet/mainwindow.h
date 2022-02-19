#ifndef MAINWINDOW_H
#define MAINWINDOW_H


#include <QMainWindow>


QT_BEGIN_NAMESPACE
class QMediaPlayer;
QT_END_NAMESPACE


class WindowBanner;
class WindowNavbar;
class PageHome;
class PageMusic;
class PageWeather;
class PageSettings;


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
    WindowBanner *m_frmBanner = nullptr;
    WindowNavbar *m_frmNavbar = nullptr;
    PageHome *m_frmHome = nullptr;
    PageMusic *m_frmMusic = nullptr;
    PageWeather *m_frmWeather = nullptr;
    PageSettings *m_frmSettings = nullptr;

public slots:
    void changePage(const QString &name);
};


#endif
