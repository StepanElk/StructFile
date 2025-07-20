#pragma once
#include <cstdint>
#include <sstream>
#include "string_struct.h"

#pragma pack(push, 1) 

struct Parameter
{
    uint32_t id;
    uint32_t device_id;
    String name;

    Parameter(): id(0), device_id(0){};
    Parameter(uint32_t id , uint32_t device_id ,  const std::string name ):
        id{id} , device_id{device_id} , name{String{&name}}{}

    std::string to_string() const {
        std::ostringstream ss;
        ss << "ID: " << id << ", Устройство: " << device_id << ", Название: " << name.to_string();
        return ss.str();
    };
};

#pragma pack(pop)
