#include "actions/devices_file_helper.h"

int main(int argc, char const *argv[])
{
    
    vector<Device> devices {
        Device{1 , "Device_1" , 8000},
        Device{2 , "Device_2" , 8000},
        Device{3 , "Device_3" , 8000},
    };
    
    vector<Parameter> parameters {
        Parameter{1 ,1, "Parameter_1" },
        Parameter{2 ,2, "Parameter_2" },
        Parameter{3 ,2, "Parameter_3" },
    };
    
    DevicesFileHelper file_helper{"devices.dat"};
    
    std::cout << "\n*** Создание файла ***" << std::endl;
    
    file_helper.create_file(&devices ,&parameters);
    file_helper.print_file_data();

    std::cout << "\n*** Добавление устройства ***" << std::endl;
    file_helper.add_device( "New_device" , 3000 );
    file_helper.print_file_data();

    std::cout << "\n*** Добавление параметра ***" << std::endl;
    file_helper.add_parameter( 3, "New_parameter");
    file_helper.print_file_data();

    return 0;
}
