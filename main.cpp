#include <thread>
#include <config.hpp>
#include <fmt/color.h>
#include <Logger/Logger.hpp>
#include <Manager/Item/ItemManager.hpp>
#include <Manager/Database/Database.hpp>
#include <Network/HTTPServer.hpp>
#include <Event/EventPool.hpp>
#include <Server/ServerPool.hpp>
#include <Utils/Utils.hpp>
#include <format>

// Handle Shutdown
void HandleShutdown() {
    for (auto [instanceId, server] : GetServerPool()->GetServers()) {
        if (!GetServerPool()->StopInstance(instanceId)) {
            Logger::Print(WARNING,
                "Failed to shutdown InstanceId {}, this instance doesn't found on {}",
                fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "{}", instanceId),
                fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Server Pool")
            );
        }
    }
}

std::string GetServerInfo() {
    std::string data;

    // Server Information
    data.append(fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Server Information\n"))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Active Servers"),
            fmt::format("{}/4", GetServerPool()->GetActiveServers())))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Active Players (All Servers)"),
            GetServerPool()->GetActivePlayers()))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Active Worlds (All Servers)"),
            GetServerPool()->GetActiveWorlds()));

    // Servers Stats
    data.append(fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Servers Stats\n"));
    for (auto [instanceId, server] : GetServerPool()->GetServers()) {
        data.append(fmt::format("{} | Uptime: {} [Players: {}, Worlds: {}] | In/Out PPS: {}/{}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "S{}", instanceId),
            server->GetUptime(),
            server->GetActivePlayers(),
            server->GetActiveWorlds(),
            server->GetHost()->incomingBandwidth,
            server->GetHost()->outgoingBandwidth
        ));
    }

    data.resize(data.length() - 1);
    return data;
}

std::string GetHardwareInfo() {
    std::string username = Console::Execute("whoami");
    std::string threadsUsage = Console::Execute(fmt::format("ps huH p {} | wc -l", ::getpid()));

    username.resize(username.length() - 1);
    threadsUsage.resize(threadsUsage.length() - 1);

    std::string data{ fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Hardware Information\n") };
    data.append(fmt::format("{}: {}\n",
        fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Hostname"),
        Console::GetHostname()))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Username"),
            username))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Process Id"),
            ::getpid()))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Thread Concurrency"),
            std::thread::hardware_concurrency()))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Threads Used"),
            threadsUsage))
        .append(fmt::format("{}: {}\n",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "CPU Load"),
            Console::GetLoadAverage()));

    data.resize(data.length() - 1);
    return data;
}

bool InitializeServer() {
    // Initialize HTTP Server
    if (!GetHTTP()->Listen()) {
        Logger::Print(WARNING, "Failed to starting {}, please run an external service.",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "HTTP Server"));
    }

    // Initialize Database
    if (!GetDatabase()->Connect()) {
        Logger::Print(WARNING, "Failed to connect {}, please check server configuration.",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "SQLite Database"));
        return false;
    }

    // Initialize Item Manager
    if (!GetItemManager()->Serialize()) {
        Logger::Print(EXCEPTION, "{} >> failed to load items.dat, please make sure the file is on /cache",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "ItemManager"));
        return false;
    }

    // Initialize Event Pool
    Logger::Print(INFO, "Initializing {} and registering events...",
        fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Event Pool"));
    GetEventPool()->RegisterEvents();

    // Initialize ENet Server
    Logger::Print(INFO, "Initializing {} and starting up {}...",
        fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Server Pool"),
        fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Master Server"));

    if (enet_initialize() != 0) {
        Logger::Print(EXCEPTION, fmt::format(fmt::emphasis::bold, "Failed to Initialize ENet, Terminating the Server..."));
        return false;
    }

    if (!GetServerPool()->StartInstance()) {
        Logger::Print(EXCEPTION, "Couldn't Startup {} Correctly, Terminating the Server...",
            fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "Master Server"));
        return false;
    }

    GetServerPool()->Start();
    return true;
}

void StartConsoleThread() {
    auto consoleThread = std::thread([]() {
        std::string command;
        while (std::cin >> command) {
            switch (Hash::Fnv1A(command)) {
            case "shutdown"_fnv:
                HandleShutdown();
                break;

            case "svinfo"_fnv:
                Logger::Print(INFO, GetServerInfo());
                break;

            case "hwinfo"_fnv:
                Logger::Print(INFO, GetHardwareInfo());
                break;
            }
        }
        });
    consoleThread.detach();
}

int main(int argc, char* argv[]) {
    // Initialize logging
    Logger::Init();
    Logger::Print(INFO, fmt::format(fmt::emphasis::bold, "Starting {} {}",
        fmt::format(fg(fmt::color::gold), Configuration::GetName()),
        fmt::format(fmt::emphasis::bold, "V{}\n", "0.0.1"))
    );

    // Parse command line arguments
    std::string commandArguments;
    for (int i = 1; i < argc; i++) {
        commandArguments.append(argv[i]).append(" ");
    }

    // Initialize server components
    if (!InitializeServer()) {
        return EXIT_FAILURE;
    }

    // Start console thread
    StartConsoleThread();

    // Main loop
    while (GetServerPool()->IsRunning()) {
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }

    return EXIT_SUCCESS;
}