#include "pieces.h"

#include<QDebug>
#include "ui_mainwindow.h"
#include "mainwindow.h"



pieces::pieces()
{

}

pieces::pieces( const QString &nom, const QString &reference, const QString &quantite, const QString &prix)
        :  nom(nom),reference(reference), quantite(quantite), prix(prix) {}


const QString &pieces::getNom() const {
    return nom;
}

void pieces::setNom(const QString &nom) {
    pieces::nom = nom;
}
const QString &pieces::getreference() const {
    return reference;
}

void pieces::setreference(const QString &reference) {
    pieces::reference = reference;
}

const QString &pieces::getquantite() const {
    return quantite;
}

void pieces::setquantite(const QString &quantite) {
    pieces::quantite = quantite;
}

const QString &pieces::getprix() const {
    return prix;}
void pieces::setprix(const QString &prix) {
    pieces::prix = prix;
}
bool pieces::add()
{
    QSqlQuery query;

        query.prepare("INSERT INTO pieces (NOM, REFERENCE, QUANTITE, PRIX) "
                      "VALUES (?, ?, ?, ?)");
        query.bindValue(0, this->nom);
        query.bindValue(1, this->reference);
        query.bindValue(2, this->quantite);
        query.bindValue(3, this->prix);
        return query.exec();
}
QSqlQueryModel *pieces::list()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from pieces");


    return model;

}
bool pieces::delet()

{
QSqlQuery query;
    query.prepare("delete from pieces where reference=:todelete");
            query.bindValue(":todelete",reference);
            return query.exec();

}
QSqlQueryModel *pieces::tri2()
{
    QSqlQueryModel * model=new QSqlQueryModel();
    model->setQuery("select * from pieces order by NOM ");


    return model;

}
