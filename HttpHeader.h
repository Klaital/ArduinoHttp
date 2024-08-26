//
// Created by Kit on 8/20/2024.
//

#ifndef HTTPHEADER_H
#define HTTPHEADER_H

#include <Arduino.h>
#define MAX_HEADER_COUNT 10

class HttpHeader {
public:
    String key;
    String val;

    HttpHeader();
    HttpHeader(const String& k, const String& v);
    HttpHeader(const char* k, const char* v);

    String ToString() const;
};

class HttpHeaderSet {
    HttpHeader headers[MAX_HEADER_COUNT];
    int count;
public:
    HttpHeaderSet() : count(0) {}
    String ToString() const;
    void set(const String& key, const String& val);
};

#endif //HTTPHEADER_H
