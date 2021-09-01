#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QDate>
#include <QTextBlock>
#include <registro.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_calendarWidget_clicked(const QDate &date);
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    QDate dataTmp;
    QLabel GG;
    //Day giornoTmp;
    Activities activityTmp;
    registro registroPrincipale;
    int tmp;
    QTextBlock TxtAttività;
};
#endif // MAINWINDOW_H
