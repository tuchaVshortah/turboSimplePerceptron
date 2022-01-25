#include <iostream>
#include <utility>
#include <fstream>
#include "includes/perceptron.hpp"
#include "includes/fileio.hpp"

int main(){
  Perceptron p = Perceptron(0, 0);
  std::ifstream ifs;
  ifs.open("some_data_file.csv");
  std::pair<std::vector<std::vector<double>>, std::vector<bool>> training_data = readCSV(ifs, p.size());
  std::cout << "Weights: " << p.size() << std::endl;
  std::vector<std::vector<double>> in_values = std::get<0>(training_data);
  std::vector<bool> out_values = std::get<1>(training_data);
  std::cout << "Number of inputs: " << in_values.size() << std::endl;
  std::cout << "Number of outputs: " << out_values.size() << std::endl;
  std::cout << "\n\n\n\n\n";
  /***************************************
  for(size_t i = 0; i < in_values.size(); ++i){
    for(size_t j = 0; j < in_values[i].size(); ++j){
      std::cout << in_values[i][j] << " ";
    }
    std::cout << out_values[i] << std::endl;
  }
  ****************************************/
  int correct = 0, incorrect = 0;
  for(size_t i = 0; i < in_values.size(); ++i){
    if(p.preLearn(in_values[i], out_values[i])){
      ++correct;
    }else{
      ++incorrect;
    }
  }
  std::cout << "\n\n\n";
  std::cout << "Correct predictions: " << correct << std::endl;
  std::cout << "Incorrect predictions: " << incorrect << std::endl;
  std::cout << "Overall accuracy: " << (double)correct/incorrect << std::endl;
  return 0;
}
