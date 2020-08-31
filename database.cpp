//
// Created by ariel on 8/28/20.
//

#include "database.h"
#include <sqlite3.h>
#include <cstdio>
#include <iostream>


const char* getLibVersion()
{
    return sqlite3_libversion();
}

int database::openDB(){
    sqlite3_open(dbName, &db);
}

int database::closeDB(){
    sqlite3_close(db);
}

void database::generateQCreateTable(char qry [], char *tableName, char* columns){
    sprintf(qry, "CREATE TABLE %s (%s);", tableName, columns);
}

void database::generateQDropTable(char qry [],char *tableName){
    sprintf(qry, "DROP TABLE %s;", tableName);
}

void database::generateQShowInfo(char qry [],char *tableName){
    sprintf(qry, "SELECT * FROM %s;", tableName);
}

void database::generateQInsertData(char qry [], char *tableName, int number){
    //sprintf(qry, "INSERT INTO %s (dt) values ('%s');", tableName, name);
    sprintf(qry, "INSERT INTO %s (number) values (%d);", tableName, number);
}

void database::checkOK(){
    if( rc != SQLITE_OK ) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else {
        fprintf(stdout, "Operation done successfully\n");
    }
}

int database::insertQ(char qry[]){
    int rc =  sqlite3_exec(db, qry, 0, 0, &zErrMsg);
    return rc;
}

void database::create_table(char qry[], char *tableName, char* columns){
    generateQCreateTable(qry, tableName, columns);
    insertQ(qry);
    if (rc=SQLITE_OK){
        std::cout << "Table was successfully created" << std::endl;
    }else{
        std::cout << "Table was NOT created because it already exists" << std::endl;
    }
}

void database::insertData(char qry[], char *tableName, int number){
    generateQInsertData(qry, tableName, number);
    insertQ(qry);
    //checkOK();
}

void database::showData(char qry[], char *tableName){
    generateQShowInfo(qry, tableName);
    insertQ(qry);
    //checkOK();
}