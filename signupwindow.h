#ifndef SIGNUPWINDOW_H
#define SIGNUPWINDOW_H
#include <QSqlDatabase>
#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>

namespace Ui {
class SignUpWindow;
}

class SignUpWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SignUpWindow(QWidget *parent = nullptr);
    ~SignUpWindow();

private slots:
    void on_confirm_Button_clicked();

    void on_return_Button_clicked();

private:
    Ui::SignUpWindow *ui;
    QSqlDatabase db;
};

#endif // SIGNUPWINDOW_H
