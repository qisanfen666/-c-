#include "signupwindow.h"
#include "ui_signupwindow.h"
#include <widget.h>

SignUpWindow::SignUpWindow(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SignUpWindow)
{
    ui->setupUi(this);
    QIcon con("E:\\picture\\rana.png");
    this->setWindowIcon(con);
    this->setWindowTitle("注册");
    connect(ui->passwordLine,SIGNAL(returnPressed()),this,SLOT(on_confirm_Button_clicked()));
    connect(ui->return_Button,SIGNAL(&QPushButton::clicked),this,SLOT(on_return_Button_clicked()));

    db=QSqlDatabase::addDatabase("QODBC"); // jiasai bd qudong
    db.setPort(3306);
    db.setDatabaseName ("test");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("061532");
    db.open();

    ui->picture->setIcon(con);
}

SignUpWindow::~SignUpWindow()
{
    delete ui;
}

void SignUpWindow::on_confirm_Button_clicked()
{
    QString account=ui->accountLine->text();
    QString pwd=ui->passwordLine->text();
    QString pwd1=ui->pwdConfirm->text();
    QSqlQuery query;
    QString sql=QString("insert into account (account,password) values ('%1','%2');").arg(account,pwd);

    if(pwd==pwd1 && query.exec(sql)){
        QMessageBox::information(this,"提示","注册成功");
    }
    else{
        QMessageBox::information(this,"失败","账号已注册或非法");
    }
}


void SignUpWindow::on_return_Button_clicked()
{
    this->close();
    Widget* signIn=new Widget;
    signIn->show();
}

