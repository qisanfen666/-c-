#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <widget.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIcon con("E:\\picture\\emu.png");
    this->setWindowIcon(con);
    this->setWindowTitle("学生管理系统");

    connect(ui->return_Button,SIGNAL(&QPushButton::pressed),this,SLOT(on_return_Button_clicked()));
    connect(ui->close_Button,SIGNAL(&QPushButton::pressed),this,SLOT(on_close_Button_clicked()));
    connect(ui->confirm_Button,SIGNAL(&QPushButton::pressed),this,SLOT(on_confirm_Button_clicked()));

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

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_return_Button_clicked()
{
    this->close();
    Widget *w=new Widget;
    w->show();
}


void MainWindow::on_close_Button_clicked()
{
    this->close();
}





void MainWindow::on_functionBox_currentTextChanged(const QString &arg1)
{
    this->func=arg1;
}


void MainWindow::on_confirm_Button_clicked()
{
    QString name=ui->nameLine->text();
    QString id=ui->idLine->text();
    QString gender=this->gender;

    QSqlQuery query;
    if(func=="增加"){
        QString sql=QString("insert into student value('%1','%2','%3');").arg(name,id,gender);
        if(query.exec(sql)){
            QMessageBox::information(this,"提示","添加成功");
        }
        else{
            QMessageBox::information(this,"提示","添加失败");
        }
    }
    if(func=="删除"){
        QString sql=QString("delete from student where name='%1'&&id='%2' ;").arg(name,id);
        if(query.exec(sql)){
            QMessageBox::information(this,"提示","删除成功");
        }
        else{
             QMessageBox::information(this,"提示","删除失败");
        }
    }
    if(func=="修改"){
        QString sql=QString("update student set id='%1',gender='%2' where name='%3'").arg(id,gender,name);
        if(query.exec(sql)){
            QMessageBox::information(this,"提示","修改成功");
        }
        else{
            QMessageBox::information(this,"提示","修改失败");
        }
    }
    if(func=="查询"){
        m->setTable("student");
        m->setHeaderData(0, Qt::Horizontal, tr("姓名"));
        m->setHeaderData(1, Qt::Horizontal, tr("学号"));
        m->setHeaderData(2, Qt::Horizontal, tr("性别"));
        if(name==""&&id==""){
            m->select();
        }
        else{
            m->setFilter(QString("id='%1'|| name='%2'").arg(id,name));
            m->select();
        }
    }
    ui->nameLine->clear();
    ui->idLine->clear();
    ui->genderBox->setCurrentIndex(0);
}


void MainWindow::on_genderBox_currentTextChanged(const QString &arg1)
{
    this->gender=arg1;
}

