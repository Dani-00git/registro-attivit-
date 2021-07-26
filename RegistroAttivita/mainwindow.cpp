#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QtWidgets>
#include <qdialog.h>
#include <day.h>
#include <vector>
#include <stdlib.h>
#include <registro.h>
#include <QDate>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    tmp = 0;
    ui->setupUi(this);
    ui->textBrowser_9->close();
    ui->textBrowser_10->close();
    ui->textBrowser_11->close();
    ui->textBrowser_12->close();
    ui->textBrowser_13->close();
    ui->textBrowser_14->close();
    ui->textBrowser_15->close();
    ui->textBrowser_16->close();
    ui->textBrowser_17->close();
    ui->textBrowser_18->close();
    ui->progressBar->close();
    ui->progressBar_2->close();
    ui->progressBar_3->close();
    ui->progressBar_4->close();
    ui->progressBar_5->close();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_calendarWidget_clicked(const QDate &date)
{
    dataTmp = date;
    ui->label->clear();
    ui->textBrowser_9->clear();
    ui->textBrowser_10->clear();
    ui->progressBar->close();

    ui->label->setText(QString::number(date.day()) +"/"+
                       QString::number(date.month()) +"/"+
                       QString::number(date.year()));
    ui->textBrowser_6->setText(QString::number(date.day()) +"/"+
                               QString::number(date.month()) +"/"+
                               QString::number(date.year()));
    int i=registroPrincipale.searchDay(date);

    if(i >= 0) {
        ui->progressBar->setValue(activityTmp.getImportanza());     //1
        ui->progressBar->show();
        giornoTmp = registroPrincipale.getDay(i);
        int n = giornoTmp.numOfActivities();                 //PROBLEMA: n (numero di attività nel giorno) è sempre uguale a zero
        activityTmp = giornoTmp.getActivity(0);
        ui->textBrowser_9->show();
        ui->textBrowser_9->setPlainText("      ore       "+ QString::fromStdString(activityTmp.getInizio()) + " - "
                                        + QString::fromStdString(activityTmp.getFine()));
        ui->textBrowser_10->show();
        ui->textBrowser_10->setPlainText( QString::number(n)+QString::fromStdString(activityTmp.getDescrizione()));

        if(n>=1){
        ui->progressBar_2->setValue(activityTmp.getImportanza());     //2
        ui->progressBar_2->show();
        activityTmp = giornoTmp.getActivity(1);
        ui->textBrowser_12->show();
        ui->textBrowser_12->setPlainText("      ore       "+ QString::fromStdString(activityTmp.getInizio()) + " - "
                                        + QString::fromStdString(activityTmp.getFine()));
        ui->textBrowser_13->show();
        ui->textBrowser_13->setPlainText( QString::fromStdString(activityTmp.getDescrizione()));

        if(n>=2){
        ui->progressBar_3->setValue(activityTmp.getImportanza());     //3
        ui->progressBar_3->show();
        activityTmp = giornoTmp.getActivity(2);
        ui->textBrowser_14->show();
        ui->textBrowser_14->setPlainText("      ore       "+ QString::fromStdString(activityTmp.getInizio()) + " - "
                                        + QString::fromStdString(activityTmp.getFine()));
        ui->textBrowser_15->show();
        ui->textBrowser_15->setPlainText( QString::fromStdString(activityTmp.getDescrizione()));


        if(n>=3){
        ui->progressBar_4->setValue(activityTmp.getImportanza());     //4
        ui->progressBar_4->show();
        activityTmp = giornoTmp.getActivity(3);
        ui->textBrowser_11->show();
        ui->textBrowser_11->setPlainText("      ore       "+ QString::fromStdString(activityTmp.getInizio()) + " - "
                                        + QString::fromStdString(activityTmp.getFine()));
        ui->textBrowser_16->show();
        ui->textBrowser_16->setPlainText( QString::fromStdString(activityTmp.getDescrizione()));


        if(n>=4){
        ui->progressBar_5->setValue(activityTmp.getImportanza());     //5
        ui->progressBar_5->show();
        activityTmp = giornoTmp.getActivity(3);
        ui->textBrowser_17->show();
        ui->textBrowser_17->setPlainText("      ore       "+ QString::fromStdString(activityTmp.getInizio()) + " - "
                                        + QString::fromStdString(activityTmp.getFine()));
        ui->textBrowser_18->show();
        ui->textBrowser_18->setPlainText( QString::fromStdString(activityTmp.getDescrizione()));
        }}}}}
}

void MainWindow::on_pushButton_clicked()
{
    int i = registroPrincipale.searchDay(dataTmp);
    Activities activityTmp (ui->lineEdit->text(),
                            ui->lineEdit_2->text(),
                            ui->textEdit->toPlainText(),
                            ui->horizontalSlider->tickInterval());
    if(i == -1){
        Day giornoTmp(dataTmp, activityTmp);
        registroPrincipale.addDay(giornoTmp);
    }
    else{
        Day giornoTmp = registroPrincipale.getDay(i);
    }
    giornoTmp.toDayActivities.push_back(activityTmp);
    int n = giornoTmp.numOfActivities();    // perchè rimane zero?
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->textEdit->clear();
    ui->label->setText(QString::number(n)+"/"+QString::number(giornoTmp.getDay()) +"/"+
                       QString::number(giornoTmp.getMonth()) +"/"+
                       QString::number(giornoTmp.getYear()));
    ui->textBrowser_6->setText(QString::number(giornoTmp.getDay()) +"/"+
                               QString::number(giornoTmp.getMonth()) +"/"+
                               QString::number(giornoTmp.getYear()));
    ui->textBrowser_9->setText(QString::fromStdString(giornoTmp.getActivity(0).getInizio()) + QString::fromStdString(giornoTmp.getActivity(0).getFine()));

}
