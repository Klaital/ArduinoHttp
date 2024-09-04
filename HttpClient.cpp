//
// Created by Kit on 8/20/2024.
//

#include "HttpClient.h"

void HttpClient::exec(HTTP::Request& req, HTTP::Response& resp) {
    if (!this->net->connect(this->host, this->port)) {
        Serial.print("Failed to connect to server '");
        Serial.print(this->host);
        Serial.print(":");
        Serial.print(this->port);
        Serial.print("'");
        return;
    }

    char http_buf[256];
    http_buf[0] = '\0';
    sprintf(http_buf, "%s:%d", this->host, this->port);
    req.headers.set("Host", http_buf);
    req.to_string(http_buf, 256);
    this->net->println(http_buf);

    // Read response
    http_buf[0] = '\0';
    const size_t bytes_read = this->net->readBytes(http_buf, 256);
    http_buf[bytes_read] = '\0';
    resp.parse(http_buf);
}