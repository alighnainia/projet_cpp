#ifndef MACHINE_H
#define MACHINE_H
#include <QString>
#include <QSql>
#include <QSqlQuery>
#include <QMessageBox>
#include <QSqlQueryModel>


class machine
{
public:
        QString nom;
        QString code;
        QString prix;

public:
    machine();
    machine( const QString &nom, const QString &code, const QString &prix);

    const QString &getnom() const;

    void setnom(const QString &nom);

    const QString &getcode() const;

    void setcode(const QString &code);

    const QString &getprix() const;

    void setprix(const QString &prix);
 bool add();
 QSqlQueryModel *list();
 bool delet();
QSqlQueryModel *tri1();
};

#endif
