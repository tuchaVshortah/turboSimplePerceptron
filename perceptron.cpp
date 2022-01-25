#include <iostream>
#include <numeric>
#include <random>
#include <stdexcept>
#include "includes/perceptron.hpp"

Perceptron::Perceptron(int matrix_size, double learning_rate, double threshold)
  : threshold(threshold), learning_rate(learning_rate), weights(matrix_size)
{
  std::default_random_engine generator;
  std::uniform_real_distribution<double> distribution(0.0, 1.0);

  for(double &weight: weights){
    weight = distribution(generator);
  }
}

bool Perceptron::predict(std::vector<double> data){
  if((int)data.size() == size()){
    double result = std::inner_product(weights.begin(), weights.end(), data.begin(), 0);
    return (result > threshold);
  }else{
    throw std::invalid_argument("Something is wrong with data arrays (incorrect size):" + size());
  }
}

bool Perceptron::preLearn(std::vector<double> data, bool expected){
  if((int)data.size() == size()){
    double result = std::inner_product(weights.begin(), weights.end(), data.begin(), 0);
    if((bool)result != expected){
      for(int i = 0; i < size(); ++i){
        weights[i] = learning_rate * data[i] * (expected - result);
      }
      std::cout << "===============" << std::endl;
      std::cout << "Expected output: " << expected << std::endl;
      std::cout << "Actual output: " << (result > threshold) << std::endl;
      std::cout << "===============\n\n" << std::endl;
      return false;
    }else{
      return true;
    }
  }else{
    throw std::invalid_argument("Something is wrong with data arrays (incorrect size):" + size());
  }
}

void Perceptron::setThreshold(double threshold){
  this -> threshold = threshold;
}

double Perceptron::getThreshold(){
  return threshold;
}

void Perceptron::setLRate(double learning_rate){
  this -> learning_rate = learning_rate;
}

double Perceptron::getLRate(){
  return learning_rate;
}

int Perceptron::size(){
  return weights.size();
}
