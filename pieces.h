#ifndef PIECES_H
#define PIECES_H


#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>

class  pieces
{
public:
    QString reference;
        QString nom;
        QString quantite;
        QString prix;

public:
     pieces();
     pieces(const QString &reference, const QString &nom, const QString &quantite, const QString &prix);
     const QString &getNom() const;

     void setNom(const QString &nom);
     const QString &getreference() const;

    void setreference(const QString &reference);

    const QString &getquantite() const;

    void setquantite(const QString &quantite);

    const QString &getprix() const;

    void setprix(const QString &prix);
 bool add();
 QSqlQueryModel *list();
 bool delet();
 QSqlQueryModel *tri2();

};

#endif
