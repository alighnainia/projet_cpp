#include "machine.h"
#include<QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"



machine::machine()
{

}

machine::machine( const QString &nom, const QString &code, const QString &prix)
        :  nom(nom), code(code), prix(prix) {}

const QString &machine::getnom() const {
    return nom;
}

void machine::setnom(const QString &nom) {
    machine::nom = nom;
}

const QString &machine::getcode() const {
    return code;
}

void machine::setcode(const QString &code) {
    machine::code = code;
}

const QString &machine::getprix() const {
    return prix;}
void machine::setprix(const QString &prix) {
    machine::prix = prix;
}
bool machine::add()
{
    QSqlQuery query;

        query.prepare("INSERT INTO MACHINE (NOM, CODE, PRIX) "
                      "VALUES (?, ?, ?)");
        query.bindValue(0, this->nom);
        query.bindValue(1, this->code);
        query.bindValue(2, this->prix);
        return query.exec();
}
QSqlQueryModel *machine::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from machine");


    return model;

}
bool machine::delet()

{
QSqlQuery query;
    query.prepare("delete from machine where code=:todelete");
            query.bindValue(":todelete",code);
            return query.exec();

}
QSqlQueryModel *machine::tri1()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from machine order by PRIX ");


    return model;

}
