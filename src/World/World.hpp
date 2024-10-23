#pragma once
#include <unordered_map>
#include <cstdint>
#include <Player/Player.hpp> 

class World {
public:
    World();
    ~World();

    void AddPlayer(uint32_t connectId, Player* player);
    void RemovePlayer(uint32_t connectId);
    Player* GetPlayer(uint32_t connectId);
    size_t GetPlayerCount() const;

private:
    std::unordered_map<uint32_t, Player*> m_players;
};
