//
// Created by ariel on 8/28/20.
//

#ifndef TEST_DATABASE_H
#define TEST_DATABASE_H


#include "sqlite3.h"

class database {
private:
    sqlite3* db;
    char *dbName;
    int rc;
    char *zErrMsg;

public:
    database(sqlite3* db, char *dbName){
        this->db=db;
        this->dbName=dbName;
        this->rc = 0;
        this->zErrMsg="null";
    }

    char* getDBName(){
        return dbName;
    }

    int getRC(){
        return rc;
    }

    char* getzErrMsg(){
        return zErrMsg;
    }

    int openDB();
    int closeDB();

    //generating query
    void generateQCreateTable(char qry [], char *tableName, char *columns);
    void generateQDropTable(char qry [],char *tableName);
    void generateQShowInfo(char qry [],char *tableName);
    void generateQInsertData(char *qry, char *tableName, int number);

    int insertQ(char qry[]);
    void checkOK();


    void create_table(char qry[], char *tableName, char *columns);

    void insertData(char *qry, char *tableName, int number);

    void showData(char *qry, char *tableName);
};

const char* getLibVersion();


#endif //TEST_DATABASE_H
