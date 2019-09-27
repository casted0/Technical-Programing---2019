// Create two matrices filled with random numbers and compute their product.

#include <iostream>
#include <random>
#include <vector>
#include <chrono>

std::vector<double> create_matrix(uint32_t size, std::default_random_engine& prng) {

	std::uniform_real_distribution<double> u01_dist(0.0, 1.0);
	std::vector<double> matrix(size * size, 0.);

	for (uint32_t i = 0; i < size; ++i) {
		for (uint32_t j = 0; j < size; ++j) {
			matrix[i * size + j] = u01_dist(prng);
		}
	}
	return matrix;
}


std::vector<double> compute_product(const std::vector<double>& A, const std::vector<double>& B, uint32_t size) {

	std::vector<double> result(size * size, 0.);

	for (uint32_t i = 0; i < size; ++i) {
		for (uint32_t j = 0; j < size; ++j) {
			double sum = 0.;
			for (uint32_t k = 0; k < size; ++k) {
				sum += A[i * size + k] * B[k * size + j];
				result[i * size + j] = sum;
			}
		}
	}
	return result;
}

void print_matrix(const std::vector<double>& matrix, uint32_t size) {
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
	uint32_t seed = std::chrono::system_clock::now().time_since_epoch().count();
	std::default_random_engine prng(seed);

	std::cout << "Give the size of the matrices:" << std::endl;
	std::cin >> m_size;

	std::vector<double> matrix_A = create_matrix(m_size, prng);
	std::vector<double> matrix_B = create_matrix(m_size, prng);

	std::vector<double> matrix_C = compute_product(matrix_A, matrix_B, m_size);

	if (m_size <= 8) {
		print_matrix(matrix_A, m_size);
		print_matrix(matrix_B, m_size);
		print_matrix(matrix_C, m_size);
	}
	return 0;
}