#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QPIxmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QThread>
#include <mutex>
#include <QGraphicsView>
#include <QTimer>
#include <thread>




QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void Draw();
    void DrawThraed();

    std::thread networkThread;
    std::mutex networkMutex;
    QPixmap pixmap;
   // QGraphicsScene scene;
    double x, y, z;
    QColor color;

    QTimer* timer;

    void UpdateLabel();

private:
    Ui::MainWindow *ui;

};
#endif // MAINWINDOW_H
