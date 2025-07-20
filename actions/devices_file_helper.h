#pragma once
#include <iostream>
#include <fstream>
#include <vector>

#include "../models/file_struct.h"

using namespace std;

class DevicesFileHelper
{
    private:
        const string file_name;
        FileStruct parse_file_to_struct();

    public:
        DevicesFileHelper(const string file_name)
            :file_name{file_name}{};

        ~DevicesFileHelper(){};

        void create_file( const vector<Device> * devices , const vector<Parameter> * params , uint32_t version = 0);
        void add_device( const std::string name ,uint16_t tcp_port);
        void add_parameter(uint32_t device_id ,  const std::string name);
        void print_file_data();
};

