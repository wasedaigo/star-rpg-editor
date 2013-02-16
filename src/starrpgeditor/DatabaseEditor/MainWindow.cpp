#include "MainWindow.h"
#include "ui_main_window.h"

MainWindow::MainWindow(QWidget *parent) :
    QDialog(parent),
    mUI(new Ui::MainWindow)
{
    mUI->setupUi(this);
}

MainWindow::~MainWindow()
{
}
