#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mytcpclient.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->UiSetup();

    client = new MyTcpClient(this);




}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::UiSetup()
{
    this->ui->pbConnectToServer->setCheckable(true); //Przycisk connectToServer


}


void MainWindow::on_pbConnectToServer_clicked()
{
    if(this->ui->pbConnectToServer->isChecked()){
        client->doConnect();
    }else{
        client->disconnect();
    }
}

