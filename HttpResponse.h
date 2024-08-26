//
// Created by Kit on 8/20/2024.
//

#ifndef HTTPRESPONSE_H
#define HTTPRESPONSE_H

#include <Arduino.h>
#include "HttpHeader.h"

class HttpResponse {
public:
    unsigned int code;
    String status;
    HttpHeaderSet headers;
    String body;
};



#endif //HTTPRESPONSE_H
