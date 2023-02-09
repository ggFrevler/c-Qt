#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateLabel);
    timer->start(1000);

}

void MainWindow::Draw()
{
    networkThread = std::thread(std::bind(&MainWindow::DrawThraed, this));

}

void MainWindow::DrawThraed()
{
    QGraphicsScene scene;
    for (double x = -1; x <= 1; x += 0.1) {
        for (double y = -1; y <= 1; y += 0.1) {
            double z = (x * x) / 2 + (y * y) / 2;
            int v = (1 - z / 1) * 359;
            v = v < 0 ? 0 : v;
            v = v > 359 ? 359 : v;
            color.setHsv(v, 255, 255);
            scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
        }
    }

    QPixmap pixmap(600, 600);
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
   // scene.render(&painter);


   // networkMutex.lock();
    std::lock_guard<std::mutex> lock(networkMutex);
    this->pixmap = pixmap;
   // networkMutex.unlock();

}

void MainWindow::UpdateLabel()
{
    //networkMutex.lock();
    std::lock_guard<std::mutex> lock(networkMutex);
    ui->label->setPixmap(pixmap);
   // networkMutex.unlock();

}

MainWindow::~MainWindow()
{
    delete ui;
}











/*MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
ui->setupUi(this);
connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);
}

void MainWindow::Draw()
{
networkThread = std::thread(std::bind(&MainWindow::DrawThraed, this));
networkThread.detach();
timer = new QTimer(this);
connect(timer, &QTimer::timeout, this, &MainWindow::UpdateLabel);
timer->start(1000);
}

void MainWindow::DrawThraed()
{
QGraphicsScene scene;
for (double x = -2; x <= 2; x += 0.1) {
for (double y = -2; y <= 2; y += 0.1) {
double z = (x * x) / 2 + (y * y) / 2;
int v = (1 - z / 2) * 359;
v = v < 0 ? 0 : v;
v = v > 359 ? 359 : v;
color.setHsv(v, 255, 255);
scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
}
}
QPixmap pixmap(600, 600);
pixmap.fill(Qt::transparent);

QPainter painter(&pixmap);
scene.render(&painter);

std::lock_guard<std::mutex> lock(networkMutex);
this->pixmap = pixmap;

}

void MainWindow::UpdateLabel()
{
std::lock_guard<std::mutex> lock(networkMutex);
ui->label->setPixmap(pixmap);
}*/

/*#include <QtConcurrent/QtConcurrent>
#include <QImage>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);
}

void MainWindow::Draw()
{
    QtConcurrent::run(this, &MainWindow::DrawThraed);
}

void MainWindow::DrawThraed()
{
    QGraphicsScene scene;
    QColor color;
    for (double x = -5; x <= 5; x += 0.1) {
        for (double y = -5; y <= 5; y += 0.1) {
            double z = (x * x) / 2 + (y * y) / 2;
            int v = (1 - z / 5) * 359;
            v = v < 0 ? 0 : v;
            v = v > 359 ? 359 : v;
            color.setHsv(v, 255, 255);
            scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
        }
    }

    QImage image(500, 500, QImage::Format_ARGB32);
    image.fill(Qt::transparent);

    QPainter painter(&image);
    scene.render(&painter);

    QPixmap pixmap = QPixmap::fromImage(image);
    ui->graphicsView->setScene(&scene);
}
*/






/*MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);
    ui->graphicsView->setScene(&scene);

}

void MainWindow::Draw()
{
    QThread *thread = new QThread;
    connect(thread, &QThread::started, this, &MainWindow::DrawThraed);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();
}

void MainWindow::DrawThraed()
{
    QGraphicsScene scene;

    scene.clear();
    for (double x = -5; x <= 5; x += 0.1) {
        for (double y = -5; y <= 5; y += 0.1) {
            double z = (x * x) / 2 + (y * y) / 2;
            int v = (1 - z / 5) * 359;
            v = v < 0 ? 0 : v;
            v = v > 359 ? 359 : v;
            color.setHsv(v, 255, 255);
            scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
        }
    }

    QPixmap pixmap(ui->label->size());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    scene.render(&painter);

    std::lock_guard<std::mutex> lock(networkMutex);
    this->pixmap = pixmap;
    ui->label->setPixmap(pixmap);
    ui->graphicsView->setSceneRect(scene.itemsBoundingRect());

}
*/




/*MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::UpdateLabel);
    timer->start(1000);

}



void MainWindow::Draw()
{
    QThread *thread = new QThread;
    connect(thread, &QThread::started, this, &MainWindow::DrawThraed);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();
}

void MainWindow::DrawThraed()
{
    QGraphicsScene scene;
    for (double x = -5; x <= 5; x += 0.1) {
        for (double y = -5; y <= 5; y += 0.1) {
            double z = (x * x) / 2 + (y * y) / 2;
            int v = (1 - z / 5) * 359;
            v = v < 0 ? 0 : v;
            v = v > 359 ? 359 : v;
            color.setHsv(v, 255, 255);
            scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
        }
    }

    QPixmap pixmap(ui->label->size());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    scene.render(&painter);

    std::lock_guard<std::mutex> lock(networkMutex);
    this->pixmap = pixmap;

   // ui->label->setPixmap(pixmap);
    //std::lock_guard<std::mutex> unlock(networkMutex);
}

void MainWindow::UpdateLabel()
{
    std::lock_guard<std::mutex> lock(networkMutex);
    ui->label->setPixmap(pixmap);
}

/*MainWindow::MainWindow(QWidget *parent)
: QMainWindow(parent)
, ui(new Ui::MainWindow)
{
ui->setupUi(this);
connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);
}

void MainWindow::Draw()
{
QThread *thread = new QThread;
connect(thread, &QThread::started, this, &MainWindow::DrawThraed);
connect(thread, &QThread::finished, thread, &QThread::deleteLater);
thread->start();
}

void MainWindow::DrawThraed()
{
QGraphicsScene scene;
for (double x = -5; x <= 5; x += 0.1) {
for (double y = -5; y <= 5; y += 0.1) {
double z = (x * x) / 2 + (y * y) / 2;
int hue = (1 - z / 5) * 359;
hue = hue < 0 ? 0 : hue;
hue = hue > 359 ? 359 : hue;
color.setHsv(hue, 255, 255);
scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
}
}
QPixmap pixmap(ui->label->size());
pixmap.fill(Qt::transparent);

QPainter painter(&pixmap);
scene.render(&painter);

std::lock_guard<std::mutex> lock(networkMutex);
this->pixmap = pixmap;

emit ui->label->setPixmap(pixmap);
}

/*MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);
}


void MainWindow::Draw()
{
    QThread *thread = new QThread;
    connect(thread, &QThread::started, this, &MainWindow::DrawThraed);
    connect(thread, &QThread::finished, thread, &QThread::deleteLater);
    thread->start();
   // networkThread = std::thread([this] { DrawThraed(); });
}

void MainWindow::DrawThraed()
{
    QGraphicsScene scene;
    for (x = -10; x <= 10; x += 0.1) {
        for (y = -10; y <= 10; y += 0.1) {
            z = (x * x) / 2 + (y * y) / 2;
            int hue = (1 - z / 10) * 359;
            hue = hue < 0 ? 0 : hue;
            hue = hue > 359 ? 359 : hue;
            color.setHsv(hue, 255, 255);
            //color.setHsv((1 - z / 10) * 359, 255, 255);
            scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
        }
    }

    QPixmap pixmap(ui->label->size());
    pixmap.fill(Qt::transparent);

    QPainter painter(&pixmap);
    scene.render(&painter);

    std::lock_guard<std::mutex> lock(networkMutex);
    this->pixmap = pixmap;

    emit ui->label->setPixmap(pixmap);
}





/*void MainWindow::Draw()
{
    networkThread = std::thread(std::bind(&MainWindow::DrawThraed, this));

    ui->label->setPixmap(pixmap);


}


void MainWindow::DrawThraed()

{


QGraphicsScene scene;

for (x = -10; x <= 10; x += 0.1) {
    for (y = -10; y <= 10; y += 0.1) {
        z = (x*x)/2 + (y*y)/2;
        color.setHsv((1 - z / 10) * 359, 255, 255);
        scene.addEllipse(x - 0.1, y - 0.1, 0.1, 0.1, QPen(color), QBrush(color));
       }
   }

      QPixmap pixmap(ui->label->size());
       pixmap.fill(Qt::transparent);

       QPainter painter(&pixmap);
       scene.render(&painter);

       networkMutex.lock();
       this->pixmap = pixmap;
       networkMutex.unlock();
}
*/

