// Create two matrices filled with random numbers and compute their product.

#include <iostream>
#include <random>
#include <chrono>

using namespace std;

void create_matrix(double* matrix, uint32_t size) {

	std::default_random_engine prng;
	std::uniform_real_distribution<double> u01_dist(0.0, 1.0);

	for (uint32_t i = 0; i < size; ++i) {
		for (uint32_t j = 0; j < size; ++j) {
			matrix[i * size + j] = u01_dist(prng);
		}
	}
	return;
}


void compute_product(double* A, double* B, double* result, uint32_t size) {

	if(!A || !B || !result || size < 0){
		cout << "Error on the arguments." << endl;
		return;
	}

	double sum = 0.;
	for (uint32_t i = 0; i < size; ++i) {
		for (uint32_t j = 0; j < size; ++j) {
			for (uint32_t k = 0; k < size; ++k) {
				sum += A[i * size + k] * B[k * size + j];
				result[i * size + k] = sum;
			}
		}
	}
	return;
}

void print_matrix(double* matrix, uint32_t size) {
	for (uint32_t i = 0; i < size; i++) {
		for (uint32_t j = 0; j < size; j++) {
			std::cout << matrix[i * size + j] << " ";
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

int main()
{
	uint32_t m_size = 0;
	double *matrix_A = nullptr, *matrix_B = nullptr, *matrix_C = nullptr;

	std::cout << "Give the size of the matrices:" << std::endl;
	std::cin >> m_size;

	matrix_A = new double[m_size * m_size];
	matrix_B = new double[m_size * m_size];

	create_matrix(matrix_A, m_size);
	create_matrix(matrix_B, m_size);
	matrix_C = new double[m_size * m_size];
	create_matrix(matrix_C, m_size);

	compute_product(matrix_A, matrix_B, matrix_C, m_size);

	print_matrix(matrix_A, m_size);
	print_matrix(matrix_B, m_size);
	print_matrix(matrix_C, m_size);

	delete [] matrix_A;
	delete [] matrix_B;
	delete [] matrix_C;

	return 0;
}