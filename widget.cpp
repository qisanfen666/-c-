#include "widget.h"
#include "signupwindow.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    QIcon con("E:\\picture\\rana.png");
    this->setWindowIcon(con);
    this->setWindowTitle("登录");

    connect(ui->passwordLine,SIGNAL(returnPressed()),this,SLOT(on_confirm_Button_clicked()));
    connect(ui->cancel_Button,SIGNAL(&QPushButton::clicked),this,SLOT(on_ancel_Button_clicked()));

    db=QSqlDatabase::addDatabase("QODBC"); // jiasai bd qudong
    db.setPort(3306);
    db.setDatabaseName ("test");
    db.setHostName("localhost");
    db.setUserName("root");
    db.setPassword("061532");
    db.open();

    ui->picture->setIcon(con);
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_confirm_Button_clicked()
{
    QString account=ui->accountLine->text();
    QString pwd=ui->passwordLine->text();
    QSqlQuery query;

    QString sql=QString("select account,password,level from account;");

    if(query.exec(sql)){
        bool flag=0;
        while(query.next()){
            QString ret1=query.value(0).toString();
            QString ret2=query.value(1).toString();
            QString ret3=query.value(2).toString();

            if(ret1==account&&ret2==pwd&&ret3=="1"){
                QMessageBox::information(this,"提示","登陆成功");
                this->close();
                MainWindow* w1=new MainWindow;
                w1->show();
                flag=1;
                break;
            }
            if(ret1==account&&ret2==pwd&&ret3=="2"){
                QMessageBox::information(this,"提示","登陆成功");
                this->close();
                UserWindow* w2=new UserWindow;
                w2->show();
                flag=1;
                break;
            }
        }
        if(flag==0){
            QMessageBox::information(this,"提示","账号或密码错误");
        }
    }
}


void Widget::on_cancel_Button_clicked()
{
    this->close();
}


void Widget::on_commandLinkButton_clicked()
{
    this->close();
    SignUpWindow* signUp=new SignUpWindow;
    signUp->show();
}

