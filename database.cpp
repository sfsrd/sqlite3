
#include "database.h"
#include <sqlite3.h>
#include <cstdio>
#include <iostream>


const char* getLibVersion()
{
    return sqlite3_libversion();
}

int database::openDB(){
    rc = sqlite3_open(dbName.c_str(), &db);
    return rc;
}

int database::closeDB(){
    rc = sqlite3_close(db);
    return rc;
}

std::string database::generateQCreateTable(std::string tableName, std::string columns){
    std::string qry = "CREATE TABLE "+tableName + " (" + columns + ");" ;
    return qry;
}

std::string database::generateQDropTable(std::string tableName){
    std::string qry = "DROP TABLE " + tableName +";";
    return qry;
}

std::string  database::generateQShowInfo(std::string tableName){
    std::string qry = "SELECT * FROM " + tableName + ";";
    return qry;
}

std::string  database::generateQInsertData(std::string tableName, int number){
    std::string qry = "INSERT INTO " + tableName + " (number) values (" + std::to_string(number) + ");";
    return qry;
}

void database::checkOK(){
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

int database::insertQ(std::string qry){
    rc =  sqlite3_exec(db, qry.c_str(), 0, 0, &zErrMsg);
    return rc;
}

void database::create_table(std::string tableName, std::string columns){
    std::string qry = generateQCreateTable(tableName, columns);
    std::cout << "qry = " << qry << std::endl;
    insertQ(qry);
}


void database::insertData(std::string tableName, int number){
    std::string qry = generateQInsertData(tableName, number);
    insertQ(qry);
}

void database::showData(std::string tableName){
    std::string qry = generateQShowInfo(tableName);
    insertQ(qry);
}
