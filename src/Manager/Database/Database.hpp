#pragma once
#include <algorithm>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/sqlite3/sqlite3.h> 
#include <Manager/Database/Table/PlayerTable.hpp>

enum eDatabaseTable {
    DATABASE_PLAYER_TABLE
};

class Database {
public:
    bool Connect();

    sqlpp::sqlite3::connection* GetConnection(); 
    void* GetTable(eDatabaseTable table);

public:
    Database() = default;
    ~Database() = default;


private:
    sqlpp::sqlite3::connection* m_pConnection; 
    PlayerTable* m_pPlayerTable;
};

Database* GetDatabase();