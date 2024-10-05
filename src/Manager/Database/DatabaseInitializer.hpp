#pragma once
#include <sqlpp11/sqlpp11.h>
#include <sqlpp11/sqlite3/sqlite3.h>
#include <string>
#include <vector>

class DatabaseInitializer {
public:
    static bool Initialize(sqlpp::sqlite3::connection* conn) {
        try {
            std::vector<std::string> statements = {
                R"(
                CREATE TABLE IF NOT EXISTS PlayerDB (
                    id INTEGER PRIMARY KEY AUTOINCREMENT,
                    requestedName TEXT DEFAULT '',
                    tankIdName TEXT NOT NULL UNIQUE,
                    tankIdPass TEXT NOT NULL,
                    created_at DATETIME DEFAULT CURRENT_TIMESTAMP
                )
                )",
                "CREATE INDEX IF NOT EXISTS idx_tankIdName ON PlayerDB(tankIdName)"
            };

            for (const auto& sql : statements) {
                conn->execute(sql);
            }

            return true;
        }
        catch (const std::exception& e) {
            return false;
        }
    }
};