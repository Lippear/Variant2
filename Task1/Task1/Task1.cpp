#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

int CalculateSumOfPositiveNumbers(int numbers[], int N) {
    int sum = 0;
    for (int i = 0; i < N; i++) {
        if (numbers[i] > 0) {
            sum += numbers[i];
        }
    }
    return sum;
}

int CalculateProductBetweenMaxMinByAbs(int numbers[], int N) {
    int maxIndex = 0;
    int minIndex = 0;

    for (int i = 1; i < N; i++) {
        if (std::abs(numbers[i]) > std::abs(numbers[maxIndex])) {
            maxIndex = i;
        }
        if (std::abs(numbers[i]) < std::abs(numbers[minIndex])) {
            minIndex = i;
        }
    }

    int startIndex = std::min(maxIndex, minIndex);
    int endIndex = std::max(maxIndex, minIndex);

    if (endIndex - startIndex <= 2) {
        return -1;
    }

    int product = 1;
    for (int i = startIndex + 1; i < endIndex; i++) {
        product *= numbers[i];
    }

    return product;
}

int main() {
    int N;
    std::cout << "Enter the number of elements in the array N: ";
    std::cin >> N;

    if (N <= 0) {
        std::cerr << "The number of elements must be positive." << std::endl;
        return 1;
    }

    int* numbers = new (std::nothrow) int[N];
    if (!numbers) {
        std::cerr << "Memory allocation failed." << std::endl;
        return 1;
    }

    std::srand(std::time(nullptr));
    for (int i = 0; i < N; i++) {
        numbers[i] = std::rand() % 201 - 100;
    }

    std::cout << "Generated array elements:\n";
    for (int i = 0; i < N; i++) {
        std::cout << numbers[i] << " ";
    }
    std::cout << std::endl;

    std::cout << "Sum of positive numbers: " << CalculateSumOfPositiveNumbers(numbers, N) << std::endl;

    int productBetweenMaxMin = CalculateProductBetweenMaxMinByAbs(numbers, N);

    if (productBetweenMaxMin == -1) {
        std::cout << "It is impossible to calculate the product if there are fewer than 2 required elements." << std::endl;
    }
    else {
        std::cout << "Product of elements between max and min by absolute value: " << productBetweenMaxMin << std::endl;
    }

    delete[] numbers;
    return 0;
}
