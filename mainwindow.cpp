#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <windows.h>
#include <QWindow>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_widget = nullptr;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_empotrarPushButton_clicked()
{
    HWND idWindow;
    LPCWSTR windowName;
    QWindow *window = nullptr;


    QString str = ui->nombreProgramaLineEdit->text();
    windowName = reinterpret_cast<LPCWSTR>(str.data());


    idWindow = FindWindow(nullptr,windowName);
    window = QWindow::fromWinId(WId(idWindow));
    window->setFlags(Qt::FramelessWindowHint);
    m_widget = QWidget::createWindowContainer(window, this);
    ui->verticalLayout->addWidget(m_widget);
}


void MainWindow::on_removerPushButton_clicked()
{
    if(m_widget != nullptr){
        ui->verticalLayout->removeWidget(m_widget);
        delete m_widget;
    }

}

