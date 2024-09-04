//
// Created by Kit on 8/20/2024.
//

#ifndef HTTPCLIENT_H
#define HTTPCLIENT_H

#include <Arduino.h>
#include <WiFiNINA.h>
#include <cstring>

// Request/Response library pulled in from https://github.com/Klaital/barebones-http
#include <Request.h>
#include <Response.h>

class HttpClient {
public:
    char host[32] = "";
    int port=80;
    WiFiClient *net = nullptr;

    HttpClient() = default;
    HttpClient(const char* host, const int port, WiFiClient *client) {
        strcpy(this->host, host);
        this->port = port;
        this->net = client;
    }

    void exec(HTTP::Request& req, HTTP::Response& resp);
};



#endif //HTTPCLIENT_H
