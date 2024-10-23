#include <Manager/Database/Database.hpp>
#include <Manager/Database/DatabaseInitializer.hpp>
#include <config.hpp>
#include <sqlpp11/sqlite3/connection.h> 
#include <Logger/Logger.hpp>

Database g_database;
Database* GetDatabase() {
    return &g_database;
}

bool Database::Connect() {
    try {
        auto config = Configuration::GetSQLite();

        Logger::Print(eLoggerType::INFO, "Current working directory: {}", std::filesystem::current_path().string());
        Logger::Print(eLoggerType::INFO, "Attempting to connect to database at: {}", config->path_to_database);

        auto dbPath = std::filesystem::path(config->path_to_database);
        if (!std::filesystem::exists(dbPath.parent_path())) {
            Logger::Print(eLoggerType::WARNING, "Database directory does not exist: {}", dbPath.parent_path().string());
            try {
                std::filesystem::create_directories(dbPath.parent_path());
                Logger::Print(eLoggerType::INFO, "Created database directory: {}", dbPath.parent_path().string());
            }
            catch (const std::filesystem::filesystem_error& e) {
                Logger::Print(eLoggerType::EXCEPTION, "Failed to create database directory: {}", e.what());
                return false;
            }
        }

        m_pConnection = new sqlpp::sqlite3::connection{ config };

        if (!DatabaseInitializer::Initialize(m_pConnection)) {
            Logger::Print(eLoggerType::EXCEPTION, "Failed to initialize database schema");
            return false;
        }

        Logger::Print(eLoggerType::INFO, "Successfully connected to database at: {}", config->path_to_database);

        m_pPlayerTable = new PlayerTable(m_pConnection);
        return true;
    }
    catch (const sqlpp::exception& e) {
        Logger::Print(eLoggerType::EXCEPTION, "SQLite connection error: {}", e.what());
        return false;
    }
    catch (const std::exception& e) {
        Logger::Print(eLoggerType::EXCEPTION, "General error: {}", e.what());
        return false;
    }
    catch (...) {
        Logger::Print(eLoggerType::EXCEPTION, "Unknown error occurred while connecting to database");
        return false;
    }
}

void* Database::GetTable(eDatabaseTable table) {
    switch (table) {
    case DATABASE_PLAYER_TABLE: return m_pPlayerTable;
    default:
        return nullptr;
    }
    return nullptr;
}
