//
// Created by Kit on 8/20/2024.
//

#ifndef HTTPREQUEST_H
#define HTTPREQUEST_H

#include <Arduino.h>
#include <HttpHeader.h>
#include <HttpResponse.h>


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


class HttpRequest {
public:
    String method;
    String path;
    String queryString;
    String body;

    HttpHeaderSet headers;

    HttpResponse exec(const String& host, int port, const WiFiClient& client);
    String ToString(const String& host);
};



#endif //HTTPREQUEST_H
