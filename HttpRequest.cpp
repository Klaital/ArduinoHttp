//
// Created by Kit on 8/20/2024.
//

#include "HttpRequest.h"

// #if defined(ARDUINO_SAMD_MKRWIFI1010) || defined(ARDUINO_SAMD_NANO_33_IOT) || defined(ARDUINO_AVR_UNO_WIFI_REV2)
  // #include <WiFiNINA.h>
// #elif defined(ARDUINO_SAMD_MKR1000)
//   #include <WiFi101.h>
// #elif defined(ARDUINO_ARCH_ESP8266)
//   #include <ESP8266WiFi.h>
// #elif defined(ARDUINO_PORTENTA_H7_M7) || defined(ARDUINO_NICLA_VISION) || defined(ARDUINO_ARCH_ESP32) || defined(ARDUINO_GIGA) || defined(ARDUINO_OPTA)
   #include <WiFi.h>
// #elif defined(ARDUINO_PORTENTA_C33)
//   #include <WiFiC3.h>
// #elif defined(ARDUINO_UNOR4_WIFI)
//   #include <WiFiS3.h>
// #endif

String HttpRequest::ToString(const String &host) {
    this->headers.set("Host", host);
    if (this->body.length() > 0) {
        this->headers.set("Content-Length", String(this->body.length()));
    }
    String raw = this->method + " HTTP/1.1\r\n";
    raw += this->headers.ToString();
    raw += "\r\n"; // empty line after headers
    if (this->body.length() > 0) {
        raw += this->body;
    }
    raw += "\r\n\r\n";
    return raw;
}

HttpResponse HttpRequest::exec(const String& host, int port, const WiFiClient& client) {
    return HttpResponse{};
}