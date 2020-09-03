//
// Created by ariel on 9/3/20.
//

#ifndef TEST_SQLITE3_DATABASE_H
#define TEST_SQLITE3_DATABASE_H

#include <string>
#include "sqlite3.h"

class database {
private:
    sqlite3* db;
    std::string dbName;
    int rc;
    char *zErrMsg;

public:
    database(sqlite3* db, std::string dbName){
        this->db=db;
        this->dbName=dbName;
        this->rc = 0;
        this->zErrMsg="null";
    }

    std::string getDBName(){
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
    void checkOK();

    std::string generateQCreateTable(std::string tableName, std::string columns);

    int insertQ(std::string qry);

    void create_table(std::string tableName, std::string columns);

    void insertData(std::string tableName, int number);

    void showData(std::string tableName);

    std::string generateQShowInfo(std::string tableName);

    std::string generateQInsertData(std::string tableName, int number);

    std::string generateQDropTable(std::string tableName);

    void create_table_char();
};

const char* getLibVersion();

#endif //TEST_SQLITE3_DATABASE_H
