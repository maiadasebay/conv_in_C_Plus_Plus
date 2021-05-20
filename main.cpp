#include"Header.h"

int main()
{
	// Test 
	MatrixXi Image = MatrixXi::Random(5, 5);
	cout << "Here is the Image m:" << endl << Image << endl;
	MatrixXi Kernel = MatrixXi::Random(3, 3);
	cout << "Here is the Kernel m:" << endl << Kernel << endl;
	MatrixXi output1 = convolution2D(Image, Kernel);
	MatrixXi output2 = convolution2D_noPadding(Image, Kernel);


}

