#include <World/World.hpp>

World::World() {
    // constructor
}

World::~World() {
    m_players.clear();
}

void World::AddPlayer(uint32_t connectId, Player* player) {
    if (!player) return;
    m_players[connectId] = player;
}

void World::RemovePlayer(uint32_t connectId) {
    if (m_players.find(connectId) != m_players.end()) {
        m_players.erase(connectId);
    }
}

Player* World::GetPlayer(uint32_t connectId) {
    auto it = m_players.find(connectId);
    if (it == m_players.end()) {
        return nullptr;
    }
    return it->second;
}

size_t World::GetPlayerCount() const {
    return m_players.size();
}
