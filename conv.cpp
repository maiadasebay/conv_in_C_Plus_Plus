#include"Header.h"

MatrixXi convolution2D(MatrixXi image, MatrixXi kernel_orig)
{
	MatrixXi kernel = kernel_orig.reverse();
	std::ofstream MyFile("convolution2D_output.txt");

	int kernelX = kernel.rows();
	int kernelY = kernel.cols();

	int kernel_centerX = kernel.rows() / 2;
	int kernel_centerY = kernel.cols() / 2;

	int rows = image.rows();
	int cols = image.cols();

	MatrixXi output(rows, cols);
	output.setZero();
	int new_i, new_j;
	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			for (int k_i = 0; k_i < kernelX; ++k_i)
			{
				for (int k_j = 0; k_j < kernelY; ++k_j)
				{
					new_i = i + (k_i - kernel_centerX);
					new_j = j + (k_j - kernel_centerY);

					if (new_i >= 0 && new_i < rows && new_j >= 0 && new_j < cols)
					{
						output(i, j) += image(new_i, new_j) * kernel(k_i, k_j);
					}
				}
			}
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			MyFile << output(i, j) << " ";
		}
		MyFile << "\n";
	}
	MyFile.close();
	return output;
}

MatrixXi convolution2D_noPadding(MatrixXi image, MatrixXi kernel_orig)
{
	MatrixXi kernel = kernel_orig.reverse();
	std::ofstream MyFile("convolution2D_output_noPadding.txt");
	int rows = (image.rows() - kernel.rows()) + 1;
	int cols = (image.cols() - kernel.cols()) + 1;

	MatrixXi output(rows, cols);
	output.setZero();

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{

			for (int ii = i, k_i = 0; ii < i + kernel.rows(), k_i < kernel.rows(); ++ii, ++k_i)
			{
				for (int jj = j, k_j = 0; jj < j + kernel.cols(), k_j < kernel.cols(); ++jj, ++k_j)
				{
					output(i, j) += image(ii, jj) * kernel(k_i, k_j);
				}
			}
		}
	}

	for (int i = 0; i < rows; ++i)
	{
		for (int j = 0; j < cols; ++j)
		{
			MyFile << output(i, j) << " ";
		}
		MyFile << "\n";
	}
	MyFile.close();
	return output;
}