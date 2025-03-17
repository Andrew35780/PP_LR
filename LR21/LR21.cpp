#include <iostream>

void AllocMemForArray(int** array, int n);
void InputArray(int array[], int n);
void OutputArray(int array[], int n);
void FilterMultiplesOfFour(int array[], int filteredArray[], int n);
int CountMultiplesOfFour(int array[], int n);
int BinarySearchDesc(int array[], int size, int target);
void SelectionSortDesc(int array[], int size);

int main() {
    setlocale(LC_CTYPE, "");
    system("color f0");

    int n;
    printf("\n Введите размер массива n: ");
    scanf_s("%d", &n);

    int* array = NULL;
    AllocMemForArray(&array, n);

    printf("\n Введите элементы массива:\n");
    InputArray(array, n);

    // Вывод исходного массива
    printf("\n Исходный массив:\n");
    OutputArray(array, n);

    // Подсчёт элементов, кратных 4
    int count = CountMultiplesOfFour(array, n);
    if (count == 0) {
        printf("\n Нет элементов, кратных 4.\n");
        free(array);
        return 0;
    }

    // Создание нового массива для элементов, кратных 4
    int* newArray = NULL;
    AllocMemForArray(&newArray, count);
    FilterMultiplesOfFour(array, newArray, n);

    // Сортировка нового массива по убыванию методом выбора
    SelectionSortDesc(newArray, count);

    // Вывод отсортированного массива
    printf("\n Отсортированный массив (по убыванию):\n");
    OutputArray(newArray, count);

    // Быстрый поиск (бинарный) в отсортированном массиве
    int target;
    printf("\n Введите элемент для поиска: ");
    scanf_s("%d", &target);

    int foundIndex = BinarySearchDesc(newArray, count, target);
    if (foundIndex != -1)
        printf(" Элемент %d найден по индексу %d\n", target, foundIndex);
    else
        printf(" Элемент %d не найден в массиве.\n", target);

    // Освобождение памяти
    free(array);
    free(newArray);

    return 0;
}

// Выделение памяти под массив
void AllocMemForArray(int** array, int n) {
    *array = (int*)malloc(n * sizeof(int));
    if (!(*array)) {
        printf("\n Ошибка выделения памяти под массив!\n");
        exit(-1);
    }
}

// Ввод массива
void InputArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" array[%d] = ", i);
        scanf_s("%d", &array[i]);
    }
}

// Вывод массива
void OutputArray(int array[], int n) {
    for (int i = 0; i < n; i++)
        printf("%4d ", array[i]);
    printf("\n");
}

// Подсчет количества элементов, кратных 4
int CountMultiplesOfFour(int array[], int n) {
    int count = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] % 4 == 0)
            count++;
    }

    return count;
}

// Создание нового массива, содержащего только элементы, кратные 4
void FilterMultiplesOfFour(int array[], int filteredArr[], int n) {
    int index = 0;

    for (int i = 0; i < n; i++) {
        if (array[i] % 4 == 0) {
            filteredArr[index] = array[i];
            index++;
        }
    }
}

// Функция бинарного поиска в массиве, отсортированном по убыванию
int BinarySearchDesc(int array[], int size, int target) {
    int low = 0, high = size - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (array[mid] == target)
            return mid;
        // В отсортированном по убыванию массиве, если элемент в mid 
        // меньше искомого, то искомый находится слева.
        else if (array[mid] < target)
            high = mid - 1;
        else
            low = mid + 1;
    }

    return -1; // Элемент не найден
}

// Сортировка методом выбора по убыванию
void SelectionSortDesc(int array[], int size) {
    for (int i = 0; i < size - 2; i++) {
        int maxIndex = i;

        for (int j = i + 1; j < size; j++) {
            if (array[j] > array[maxIndex])
                maxIndex = j;
        }
        // Обмен элементов, если найден больший элемент
        if (maxIndex != i) {
            int temp = array[i];
            array[i] = array[maxIndex];
            array[maxIndex] = temp;
        }
    }
}
