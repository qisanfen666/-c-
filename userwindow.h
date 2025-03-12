#ifndef USERWINDOW_H
#define USERWINDOW_H

#include <QMainWindow>
#include <QSqlQuery>
#include <QSqlTableModel>

namespace Ui {
class UserWindow;
}

class UserWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit UserWindow(QWidget *parent = nullptr);
    ~UserWindow();

private slots:
    void on_confirm_Button_clicked();

    void on_return_Button_clicked();

    void on_close_Button_clicked();

private:
    Ui::UserWindow *ui;
    QSqlDatabase db;
    QString func;
    QString gender;
    QSqlTableModel *m;
};

#endif // USERWINDOW_H
