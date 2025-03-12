#include "userwindow.h"
#include "ui_userwindow.h"
#include <widget.h>

UserWindow::UserWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::UserWindow)
{
    ui->setupUi(this);
    QIcon con("E:\\picture\\emu.png");
    this->setWindowIcon(con);
    this->setWindowTitle("学生管理系统");

    connect(ui->confirm_Button,SIGNAL(&QPushButton::pressed),this,SLOT(on_confirm_Button_clicked()));
    connect(ui->return_Button,SIGNAL(&QPushButton:pressed),this,SLOT(on_return_Button_clicked()));
    connect(ui->close_Button,SIGNAL(&QPushButton:pressed),this,SLOT(on_close_Button_clicked()));

    db=QSqlDatabase::addDatabase("QODBC"); // jiasai bd qudong
    db.setPort(3306);
    db.setDatabaseName ("test");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("061532");
    db.open();

    m=new QSqlTableModel;
    m->setTable("student");
    m->setHeaderData(0, Qt::Horizontal, tr("姓名"));
    m->setHeaderData(1, Qt::Horizontal, tr("学号"));
    m->setHeaderData(2, Qt::Horizontal, tr("性别"));
    ui->tableView->setModel(m);
}

UserWindow::~UserWindow()
{
    delete ui;
}

void UserWindow::on_confirm_Button_clicked()
{
    QString name=ui->nameLine->text();
    QString id=ui->idLine->text();

    m->setTable("student");
    m->setHeaderData(0, Qt::Horizontal, tr("姓名"));
    m->setHeaderData(1, Qt::Horizontal, tr("学号"));
    m->setHeaderData(2, Qt::Horizontal, tr("性别"));
    if(name==""&&id==""){
        m->select();
    }
    else{
        m->setFilter(QString("id='%1'||name='%2'").arg(id,name));
        m->select();
    }
    ui->nameLine->clear();
    ui->idLine->clear();
}

void UserWindow::on_return_Button_clicked()
{
    this->close();
    Widget *w=new Widget;
    w->show();
}


void UserWindow::on_close_Button_clicked()
{
    this->close();
}

