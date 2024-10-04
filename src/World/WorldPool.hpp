#pragma once
#include <memory>
#include <unordered_map>
#include <World/World.hpp>
#include <string>
#include <unordered_map>

class WorldPool {
public:
    WorldPool() = default;
    ~WorldPool();

public:
    std::unordered_map<std::string, std::shared_ptr<World>> GetWorlds();
    size_t GetActiveWorlds() const;

    std::shared_ptr<World> NewWorld(std::string vName);
    void RemoveWorld(std::string vName);
    std::shared_ptr<World> GetWorld(std::string vName);

private:
    std::unordered_map<std::string, std::shared_ptr<World>> m_worlds{};
};