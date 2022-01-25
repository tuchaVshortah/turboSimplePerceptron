#ifndef FILEIO_H
#define FILEIO_H

#include <vector>
#include <fstream>

std::pair<std::vector<std::vector<double>>, std::vector<bool>> readCSV(std::ifstream &ifs, int size);

#endif
