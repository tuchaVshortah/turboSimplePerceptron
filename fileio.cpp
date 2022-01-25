#include <vector>
#include <utility>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

std::pair<std::vector<std::vector<double>>, std::vector<bool>> readCSV(std::ifstream &ifs, int matrix_size){
    std::vector<std::vector<double>> in_values;
    std::vector<double> in_value;
    std::vector<bool> out_values;
    std::string line, value;
    while(std::getline(ifs, line)){
        std::stringstream stream(line);
        while(std::getline(stream, value, ',')){
            if((int)in_value.size() < matrix_size){
                //std::cout << "in: " << std::stod(value) << std::endl;
                in_value.push_back(std::stod(value));
            }else{
                //std::cout << "out: " << std::stod(value) << std::endl;
                out_values.push_back(std::stod(value));
                in_values.push_back(std::move(in_value));
            }
        }
    }
    std::cout << "\n\n\n\n\n";
    std::cout << "=========================" << std::endl;
    std::cout << "Closing the input file..." << std::endl;
    std::cout << "=========================" << std::endl;
    ifs.close();
    return std::make_pair(in_values, out_values);
}
