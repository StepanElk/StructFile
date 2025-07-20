#pragma once
#include <cstdint>
#include <sstream>


#pragma pack(push, 1) 

struct FileHeader
{
    uint32_t version;
    uint32_t devices_count;
    uint32_t parameters_count;

    FileHeader(): version(0), devices_count(0), parameters_count(0){};
    FileHeader(uint32_t version , uint32_t devices_count ,uint32_t parameters_count ):
        version{version} , devices_count{devices_count} , parameters_count{parameters_count}{}
    
    std::string to_string() const {
        std::ostringstream ss;
        ss <<"Версия файла: " << version  << "\nУстройств: " << devices_count << "\nПараметров: " << parameters_count ;
        return ss.str();
    };
};

#pragma pack(pop)
