#pragma once
#include <string>
#include <filesystem>
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/sqlite3/sqlite3.h> 

class Configuration {
public:
    static constexpr const char* GetName() { return "Kukuri Tavern"; }
    static constexpr const char* GetVersion() { return "0.0.1"; }

    static std::string GetBaseHost() { return "127.0.0.1"; }
    static uint16_t GetBasePort() { return 16000; }

public:
    static std::shared_ptr<sqlpp::sqlite3::connection_config> GetSQLite() {
        auto pConfig = std::make_shared<sqlpp::sqlite3::connection_config>();
        std::filesystem::path dbPath = std::filesystem::current_path();

        if (std::filesystem::exists(dbPath / "dev.db")) {
            pConfig->sqliteDB = (dbPath / "dev.db").string();
        }

        else if (std::filesystem::exists(dbPath.parent_path() / "dev.db")) {
            pConfig->sqliteDB = (dbPath.parent_path() / "dev.db").string();
        }

        else {
            pConfig->sqliteDB = (dbPath / "dev.db").string();
        }

        pConfig->flags = SQLITE_OPEN_READWRITE | SQLITE_OPEN_CREATE;
        pConfig->debug = false; 
        return pConfig;
    }
};