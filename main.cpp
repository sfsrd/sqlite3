#include <iostream>
#include "database.h"

int main() {
    sqlite3* db;
    char *tableName = "Info";
    char *columns = "id INTEGER PRIMARY KEY AUTOINCREMENT, number INTEGER";
    char qry[500];

    database DB(db, "info.db");
    DB.openDB();
    DB.create_table(qry, tableName, columns);

    for (int i =0; i<5; i++){
        DB.insertData(qry, tableName, i);
    }
    DB.checkOK();
    DB.closeDB();
    return 0;
}
