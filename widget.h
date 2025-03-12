#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QProcess>
#include <QMessageBox>
#include <mainwindow.h>
#include <QSqlDatabase>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlTableModel>
#include <userwindow.h>
#include <signupwindow.h>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_confirm_Button_clicked();

    void on_cancel_Button_clicked();

    void on_commandLinkButton_clicked();

private:
    Ui::Widget *ui;
    QSqlDatabase db;
};
#endif // WIDGET_H
