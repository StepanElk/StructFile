#pragma once
#include <cstdint>
#include <sstream>

#include "string_struct.h"

#pragma pack(push, 1) 

struct Device
{
    uint32_t id;
    String name;
    uint16_t tcp_port;

    Device(): id(0), tcp_port(8000) {};
    Device(uint32_t id , const std::string name ,uint16_t tcp_port ):
        id{id} , name{String{&name}} , tcp_port{tcp_port}{}

    std::string to_string() const {
        std::ostringstream ss;
        ss << "ID: " << id << ", Название: " << name.to_string() << ", Порт: " << tcp_port ;
        return ss.str();
    };
};

#pragma pack(pop)
