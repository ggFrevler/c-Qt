#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::Draw);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::Draw()

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

       ui->label->setPixmap(pixmap);
}

