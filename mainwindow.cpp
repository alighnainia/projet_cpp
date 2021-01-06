#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "machine.h"
#include "pieces.h"

#include <QDoubleValidator>
#include <QDebug>
#include<QDesktopServices>
#include<QSystemTrayIcon>
#include <QSqlQueryModel>
#include<QSqlQuery>
#include<QSqlError>
#include<QMessageBox>
#include <QApplication>







MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked() //aajouetr machine
{
        QString nom = ui->le_nom->text();
        QString code = ui->le_code->text();
        QString prix = ui->le_prix->text();




        machine.setnom(nom);
        machine.setcode(code);
        machine.setprix(prix);


        if (machine.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}

void MainWindow::on_pushButton_5_clicked()//modifier machine
{
        QString NOM = ui->lineEdit_16->text();
        QString code = ui->lineEdit_17->text();
        QString prix = ui->lineEdit_18->text();

        machine.setnom(NOM);
        machine.setcode(code);
        machine.setprix(prix);
        QSqlQuery query;

        query.prepare("update machine set NOM=:NOM,CODE=:CODE,PRIX=:PRIX where CODE=:CODE");

        query.bindValue(":code",code);

        query.bindValue(":nom",NOM);
        query.bindValue(":code",code);
        query.bindValue(":prix",prix);
        query.exec();
        if(query.exec()){
            QMessageBox::information (this, "update", "machine updated");
            ui->lineEdit_14->setText("");
        }


        else {QMessageBox::critical (this, "Error", "unexpected error");}

}


void MainWindow::on_pushButton_3_clicked() // recherceh fil modifier
{
    QString code = ui->lineEdit_14->text();
        QSqlQuery query;
        query.prepare("Select * from machine where code=:id");
        query.bindValue(":id", code);
        query.exec();
        if(query.next())
        {
            ui->lineEdit_12->setText(query.value(0).toString());
            ui->lineEdit_5->setText(query.value(1).toString());
            ui->lineEdit_15->setText(query.value(2).toString());


        }
}

void MainWindow::on_pushButton_4_clicked()//afficher machine
{
    ui->tab_machine->setModel(machine.list());
}

void MainWindow::on_pushButton_6_clicked()//supp machine
{
    QString code = ui->lineEdit_11->text();
        machine.setcode(code);
        if (machine.delet())
        {
            QMessageBox::information(this, "success ", "supprimé avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}

void MainWindow::on_pushButton_8_clicked()// tier mach
{
    ui->tab_machine->setModel(machine.tri1());

}

void MainWindow::on_pushButton_2_clicked() //ajouter pieces
{
        QString nom = ui->le_nomm->text();
        QString reference = ui->le_reference->text();
        QString quantite = ui->le_quantite->text();
        QString prix = ui->le_pri->text();




        pieces.setNom(nom);
        pieces.setreference (reference);
        pieces.setquantite (quantite);
        pieces.setprix(prix);


        if (pieces.add())
        {
            QMessageBox::information(this, "success ", "ajouter avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}

void MainWindow::on_pushButton_13_clicked() // recherche fl mod
{
    QString reference = ui->lineEdit_19->text();
           QSqlQuery query;
           query.prepare("Select * from pieces where reference=:id");
           query.bindValue(":id", reference);
           query.exec();
           if(query.next())
           {
               ui->lineEdit_10->setText(query.value(0).toString());
               ui->lineEdit->setText(query.value(1).toString());
               ui->lineEdit_7->setText(query.value(2).toString());
           }
}


void MainWindow::on_pushButton_9_clicked()
{
    QString NOM = ui->lineEdit_2->text();
    QString reference = ui->lineEdit_19->text();
    QString quantite = ui->lineEdit_3->text();
    QString prix = ui->lineEdit_13->text();


    pieces.setNom(NOM);
    pieces.setquantite(quantite);
    pieces.setprix(prix);

    QSqlQuery query;

    query.prepare("update pieces set NOM=:NOM,QUANTITE=:QUANTITE,PRIX=:PRIX where REFERENCE=:REFERENCE");

    query.bindValue(":reference",reference);

    query.bindValue(":nom",NOM);
    query.bindValue(":quantite",quantite);
    query.bindValue(":prix",prix);
    query.exec();
    if(query.exec()){
        QMessageBox::information (this, "update", "pieces updated");
        ui->lineEdit_19->setText("");
    }


    else {QMessageBox::critical (this, "Error", "unexpected error");}

}

void MainWindow::on_pushButton_14_clicked()
{
    ui->tableView_4->setModel(pieces.list());

}

void MainWindow::on_pushButton_10_clicked()
{
    ui->tableView_4->setModel(pieces.tri2());

}

void MainWindow::on_pushButton_12_clicked()
{
    QString reference = ui->le_ref_supp->text();
        pieces.setreference(reference);
        if (pieces.delet())
        {
            QMessageBox::information(this, "success ", "supprimé avec success");  }

        else
        {
            QMessageBox::critical(this, "failure !", "completer les champs!");
        }
}

void MainWindow::on_pushButton_11_clicked()
{
    QString NOM = ui->lineEdit_4->text();
        QString REF = ui->lineEdit_6->text();
        if(NOM!="")
        {
            QSqlQuery query;
            query.prepare("Select * from pieces where NOM=:id");
            query.bindValue(":id", NOM);
            query.exec();
            if(query.next())
            {
                ui->lineEdit_4->setText(query.value(0).toString());
                ui->lineEdit_6->setText(query.value(1).toString());
                ui->lineEdit_9->setText(query.value(2).toString());
                ui->lineEdit_20->setText(query.value(3).toString());

            }
        }

        else
        {
            QSqlQuery query;
            query.prepare("Select * from pieces where Reference=:id");
            query.bindValue(":id", REF);
            query.exec();
            if(query.next())
            {
                ui->lineEdit_4->setText(query.value(0).toString());
                ui->lineEdit_6->setText(query.value(1).toString());
                ui->lineEdit_9->setText(query.value(2).toString());
                ui->lineEdit_20->setText(query.value(3).toString());

            }
        }
}


