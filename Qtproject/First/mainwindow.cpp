#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    auto x = ui->label->x();
    auto x1 = ui->label_2->x();
    auto y = ui->label->y();
    auto y1 = ui->label_2->y();
    ui->label->move(x-5, y);
    ui->label_2->move(x1-5, y1);
}



void MainWindow::on_pushButton_3_clicked()
{
    auto x = ui->label->x();
    auto y = ui->label->y();
    ui->label->move(x+5, y);

    auto x1 = ui->label_2->x();
    auto y1 = ui->label_2->y();
    ui->label_2->move(x1+5, y1);
}



void MainWindow::on_pushButton_5_clicked()
{
    auto x = ui->label->x();
    auto y = ui->label->y();
    ui->label->move(x, y+5);

    auto x1 = ui->label_2->x();
    auto y1 = ui->label_2->y();
    ui->label_2->move(x1, y1+5);

    auto x2 = ui->line_3->x();
    auto y2 = ui->line_3->y();
    ui->line_3->move(x2, y2+5);
}


void MainWindow::on_pushButton_2_clicked()
{
    auto x = ui->label->x();
    auto y = ui->label->y();
    ui->label->move(x, y-5);

    auto x1 = ui->label_2->x();
    auto y1 = ui->label_2->y();
    ui->label_2->move(x1, y1-5);

    auto x2 = ui->line_3->x();
    auto y2 = ui->line_3->y();
    ui->line_3->move(x2, y2-5);
}





