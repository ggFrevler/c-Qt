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
    QImage image(600, 600, QImage::Format_RGB32);
    image.fill(Qt::transparent);
    QColor color;

    for (double x = -1; x <= 1; x += 0.1) {
        for (double y = -1; y <= 1; y += 0.1) {
            double z = (x * x) / 2 + (y * y) / 2;
            int v = (1 - z / 1) * 359;
            v = v < 0 ? 0 : v;
            v = v > 359 ? 359 : v;
            color.setHsv(v, 255, 255);
            for (int i = (x + 1) * 300; i < (x + 1.1) * 300; ++i) {
                for (int j = (y + 1) * 300; j < (y + 1.1) * 300; ++j) {
                    image.setPixelColor(i, j, color);
                }
            }
        }
    }

    std::lock_guard<std::mutex> lock(networkMutex);
    this->image = image;
}

void MainWindow::UpdateLabel()
{
    std::lock_guard<std::mutex> lock(networkMutex);
    ui->label->setPixmap(QPixmap::fromImage(image));
}

MainWindow::~MainWindow()
{
    timer->stop();

    if (networkThread.joinable())
    {
        networkThread.join();
    }

    delete ui;
}


/*for (int i = 0; i < 600; i++)
 {
     for (int j = 0; j < 600; j++)
     {

         double x = (i - 300)*1.0;
         double y = (300 -j)*1.0;

         double f = (x*x - y*y)*0.005;

         if (f > 127)
         {
             f = 127;
         }

         if (f < -128)
         {
             f = -128;
         }

         f += 128;

         image.setPixel(i,j,f);
     }
 }*/













































