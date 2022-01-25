#ifndef PERCEPTRON_H
#define PERCEPTRON_H

#include <numeric>
#include <vector>

class Perceptron{
private:
  std::vector<double> weights;
  double threshold, learning_rate;
public:
  //Perceptron(){}
  Perceptron(int matrix_size=0, double learning_rate=0.1, double threshold=0.5);

  bool predict(std::vector<double> data);
  bool preLearn(std::vector<double> data, bool expected);
  void setThreshold(double threshold);
  double getThreshold();
  void setLRate(double learning_rate);
  double getLRate();
  int size();
};

#endif
