//
// Created by Kit on 8/20/2024.
//

#include "HttpHeader.h"

HttpHeader::HttpHeader(): key(""), val("") {
}

HttpHeader::HttpHeader(const String &k, const String &v)
    : key(k), val(v)
{
}
HttpHeader::HttpHeader(const char *k, const char *v)
    : key(k), val(v)
{
}

String HttpHeader::ToString() const {
    return this->key + ": " + this->val + "\r\n";
}

String HttpHeaderSet::ToString() const {
    String raw = "";
    for(int i=0; i<this->count; i++) {
        raw += this->headers[i].ToString();
    }
    return raw;
}

void HttpHeaderSet::set(const String &key, const String &val) {
    if (this->count >= MAX_HEADER_COUNT) {
        return; // can't add more headers
    }
    this->headers[this->count].key = key;
    this->headers[this->count].val = val;
    this->count++;
}
