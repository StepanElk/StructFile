#pragma once
#include <cstdint>
#include <cstring>
#include <string>

#pragma pack(push, 1) 

struct String
{
    uint8_t length;
    char data[255];

    String(): length(0) { data[0] = '\0'; };
    String(const std::string * content ){
        length = static_cast<uint8_t>(content->size());
        strncpy(data, content->c_str(), 255);
    }

    std::string to_string() const { return std::string(data, length); }
};

#pragma pack(pop)
