#include <iostream>
#include <cstdlib>

void createArray(double*& arr, int n);
void printArray(const double* arr, int n);
double Sum(const double* arr, int n, int currentIndex = 0, double currentSum = 0.0);
double DobytokMaxMin(const double* arr, int n, int currentIndex = 0, int maxIdx = 0, int minIdx = 0);
void Sort(double* arr, int n, int i = 1);

int main() {
    int n;
    std::cout << "Rozmir masivy ";
    std::cin >> n;

    double* arr = nullptr;
    createArray(arr, n);

    std::cout << "Vvedit " << n << " diysnih chisel: ";
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    std::cout << "Masiv: ";
    printArray(arr, n);

    double sumPositives = Sum(arr, n);
    std::cout << "Suma dodatnih elementiv: " << sumPositives << std::endl;

    double product = DobytokMaxMin(arr, n);
    std::cout << "Dobytok elementiv mij maksimalnim i minimalnim za modulem: " << product << std::endl;

    Sort(arr, n);

    std::cout << "Masiv pislya sortuvannya neparnih za spadannyam:: ";
    printArray(arr, n);

    delete[] arr;
    return 0;
}
// Функція для створення динамічного масиву подвійних чисел розміру 'n'.
void createArray(double*& arr, int n) {
    arr = new double[n];// Виділяємо пам'ять для масиву.
}
// Функція для виведення вмісту масиву на екран.
void printArray(const double* arr, int n) {
    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " "; // Виводимо елементи масиву на екран.
    }
    std::cout << std::endl;
}
// Рекурсивна функція для обчислення суми додатних елементів у масиві.
double Sum(const double* arr, int n, int currentIndex, double currentSum) {
    if (currentIndex == n) {
        return currentSum; // Якщо досягнуто кінець масиву, повертаємо суму.
    }
    if (arr[currentIndex] > 0) {
        currentSum += arr[currentIndex];// Додаємо додатні елементи до суми.
    }
    return Sum(arr, n, currentIndex + 1, currentSum);// Рекурсивний виклик для наступного елемента.
}
// Рекурсивна функція для обчислення добутку елементів між максимальним і мінімальним за модулем елементами.
double DobytokMaxMin(const double* arr, int n, int currentIndex, int maxIdx, int minIdx) {
    if (currentIndex == n) {
        int start = std::min(maxIdx, minIdx) + 1;
        int end = std::max(maxIdx, minIdx);
        double product = 1.0;
        for (int i = start; i < end; i++) {
            product *= arr[i];
        }
        return product;// Якщо досягнуто кінець масиву, обчислюємо добуток.
    }
    if (std::abs(arr[currentIndex]) > std::abs(arr[maxIdx])) {
        maxIdx = currentIndex;// Знаходимо індекс максимального за модулем елемента.
    }
    if (std::abs(arr[currentIndex]) < std::abs(arr[minIdx])) {
        minIdx = currentIndex;  // Знаходимо індекс мінімального за модулем елемента.
    }
    return DobytokMaxMin(arr, n, currentIndex + 1, maxIdx, minIdx); // Рекурсивний виклик для наступного елемента.
}
// Рекурсивна функція для сортування непарних елементів за спаданням у масиві.
void Sort(double* arr, int n, int i) {
    if (i == n) {
        return;// Якщо індекс дорівнює розміру масиву, завершуємо рекурсію.
    }
    if (i % 2 != 0) {
        for (int j = i; j < n; j++) {
            if (j % 2 != 0) {
                if (arr[i] < arr[j]) {
                    std::swap(arr[i], arr[j]);// Порівнюємо і обмінюємо елементи для сортування.
                }
            }
        }
    }
    Sort(arr, n, i + 1);// Рекурсивний виклик для наступного індексу.
}
