#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlTableModel>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_return_Button_clicked();

    void on_close_Button_clicked();


    void on_functionBox_currentTextChanged(const QString &arg1);

    void on_confirm_Button_clicked();

    void on_genderBox_currentTextChanged(const QString &arg1);

private:
    QSqlDatabase db;
    Ui::MainWindow *ui;
    QString func;
    QString gender;
    QSqlTableModel *m;
};

#endif // MAINWINDOW_H
