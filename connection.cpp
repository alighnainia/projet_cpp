#include "connection.h"
//test tutoriel git
Connection::Connection()
{

}

bool Connection::createconnect()
{
    bool test=false;
  QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
  db.setDatabaseName("smart factory");
  db.setUserName("test");
  db.setPassword("test");

  if (db.open())
      test=true;

  return test ;

}
