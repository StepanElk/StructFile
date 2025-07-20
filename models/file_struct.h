#pragma once
#include <cstdint>
#include <vector>

#include "device_struct.h"
#include "parameter_struct.h"
#include "file_header.h"


struct FileStruct
{
    FileHeader header;
    std::vector<Device> devices ;
    std::vector<Parameter> parameters;
};

