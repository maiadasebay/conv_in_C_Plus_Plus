#pragma once
#include "Eigen/Core"
#include <Eigen/Dense>
using namespace Eigen;

#include<fstream>

#include<iostream>
using std::cout;
using std::endl;


MatrixXi convolution2D_noPadding(MatrixXi Img, MatrixXi Kern);
MatrixXi convolution2D(MatrixXi image, MatrixXi kernel);
