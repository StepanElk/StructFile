#include "devices_file_helper.h"    

void DevicesFileHelper::create_file( const vector<Device> * devices , const vector<Parameter> * params , uint32_t version){
    ofstream file{file_name, std::ios::binary};
    if (!file.is_open()) {
        throw std::runtime_error("DevicesFileHelper::create_file: Не удалось открыть файл: " + file_name);
    }

    FileHeader header{ version , (uint32_t)devices->size() , (uint32_t)params->size()};
    file.write(reinterpret_cast<const char*>(&header), sizeof(FileHeader));

    for (auto device : *devices) {
        file.write(reinterpret_cast<const char*>(&device), sizeof(Device));
    }

    for (auto param : *params) {
        file.write(reinterpret_cast<const char*>(&param), sizeof(Parameter));
    }

    file.close();
}

FileStruct DevicesFileHelper::parse_file_to_struct(){
    std::ifstream file(file_name, std::ios::binary);
    if (!file.is_open()) {
        throw std::runtime_error("DevicesFileHelper::parse_file_to_struct: Не удалось открыть файл: " + file_name);
    }

    FileStruct file_struct;
    file.read(reinterpret_cast<char*>(&file_struct.header), sizeof(FileHeader));

    file_struct.devices = vector<Device>(file_struct.header.devices_count);
    file.read(reinterpret_cast<char*>(file_struct.devices.data()), file_struct.header.devices_count * sizeof(Device));
    
    file_struct.parameters = vector<Parameter>(file_struct.header.parameters_count);
    file.read(reinterpret_cast<char*>(file_struct.parameters.data()), file_struct.header.parameters_count * sizeof(Parameter));

    file.close();

    return file_struct;
}


void DevicesFileHelper::print_file_data(){
    FileStruct file_struct = parse_file_to_struct();

    std::cout << "\n=== Заголовок файла ===" << std::endl;
    std::cout << file_struct.header.to_string() << std::endl;

    std::cout << "\n=== Устройства ===" << std::endl;
    for (const auto& device : file_struct.devices) {
        std::cout << device.to_string() << std::endl;     
    }

    std::cout << "\n=== Параметры ===" << std::endl;
    for (const auto& param : file_struct.parameters) {
        std::cout << param.to_string() << std::endl;     
    }
}

void DevicesFileHelper::add_device( const std::string name , uint16_t tcp_port){
    FileStruct file_struct = parse_file_to_struct();
    file_struct.header.version++;

    auto last_device_id = file_struct.devices[file_struct.header.devices_count - 1].id;
    file_struct.devices.push_back(Device{last_device_id + 1,name , tcp_port});

    create_file(&file_struct.devices , &file_struct.parameters , file_struct.header.version);
}

void DevicesFileHelper::add_parameter( uint32_t device_id ,  const std::string name){
    FileStruct file_struct = parse_file_to_struct();
    file_struct.header.version++;

    if (file_struct.header.devices_count < device_id + 1){
        throw std::out_of_range("Неверный идентификатор устройства: " + to_string(device_id));
    }

    auto last_param_id = file_struct.parameters[file_struct.header.parameters_count - 1].id;
    file_struct.parameters.push_back(Parameter{last_param_id + 1 , device_id  , name});

    create_file(&file_struct.devices , &file_struct.parameters , file_struct.header.version);
}





