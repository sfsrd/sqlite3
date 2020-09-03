#include <iostream>
#include <sqlite3.h>
#include <chrono>
#include "database.h"

int main(int argc, char* argv[]) {
    sqlite3 *db;
    std::string dbName = "sensor_data.db";
    std::string tableName = "Info";
    std::string columns = "id INTEGER PRIMARY KEY AUTOINCREMENT, number INTEGER";
    int64_t now;
    database DB(db, dbName);
    DB.openDB();
    DB.create_table(tableName, columns);

    for (int i =0; i<5; i++){
        now = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::system_clock::now().time_since_epoch()).count();
        DB.insertData(tableName, now);
    }
    DB.closeDB();
    return 0;
}
