#include <Network/HTTPServer.hpp>
#include <config.hpp>
#include <Logger/Logger.hpp>
#include <Utils/TextParse.hpp>
#include <config.hpp>

HTTPServer g_httpServer;
HTTPServer* GetHTTP() {
    return &g_httpServer;
}

bool HTTPServer::Listen() {
    Logger::Print(INFO, "Starting {}, binding port to server",
        fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "HTTP Server"));

    m_pServer = std::make_unique<httplib::SSLServer>("./cache/cert.pem", "./cache/key.pem");

    if (!m_pServer->bind_to_port("0.0.0.0", 443)) {
        Logger::Print(EXCEPTION, "Failed to bind port 443 to HTTP Server.");
        return false;
    }

    std::thread t(&HTTPServer::ServicePoll, this);
    this->m_serviceThread = std::move(t);

    Logger::Print(INFO, "{} Initialized, Listening to {}",
        fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "HTTP Server"),
        fmt::format(fmt::emphasis::bold | fg(fmt::color::cornsilk), "https://0.0.0.0:443"));

    return true;
}

void HTTPServer::Stop() {
    m_pServer->stop();
    m_pServer.release();
}

std::thread& HTTPServer::GetThread() {
    return this->m_serviceThread;
}

void HTTPServer::ServicePoll() {
    m_pServer->Post("/growtopia/server_data.php", [&](const httplib::Request& request, httplib::Response& response) {
        Logger::Print(INFO, "A request from {} | {}", request.remote_addr, request.path);

        const std::string version = "4.67";
        std::string client_version = request.get_param_value("version");

        if (client_version == version) {
            Logger::Print(INFO, "Version matched: {}", client_version); //DEBUG
            //response.set_redirect("https://kukuri.xyz"); Testing redirect
        }
        else {
            std::string str = "error|1000|Update is now available for your device. Go get it!\n";
            str += "url|https://growtopiagame.com/Growtopia-Installer.exe\n";
            str += fmt::format("port|{}\n", Configuration::GetBasePort());
            str += "loginurl|https://kukuri.xyz\n";
            str += "type|1\n";
            str += "#maint|Server is under maintenance.\n";
            str += "meta|ignoremeta\n";
            str += "RTENDMARKERBS1001";

            response.set_content(str, "text/html");
        }
        });

    m_pServer->Get("/growtopia/cache*", [&](const httplib::Request& request, httplib::Response& response) {
        std::string url = fmt::format("https://ubistatic-a.akamaihd.net/{}", request.path);
        Logger::Print(WARNING, "Client requesting cache: {} not found. Redirecting to original CDN: {}",
            request.path, url);
        response.set_redirect(url);
        });

    m_pServer->listen_after_bind();
}
