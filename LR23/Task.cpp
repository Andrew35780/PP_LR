#include <iostream>

#define MAX_STR 50

// Структура, представляющая запись автомобиля
typedef struct {
    char brand[MAX_STR];
    char color[MAX_STR];
    float price;
} car_t;

// Структура узла односвязного списка
typedef struct list_node_t {
    car_t car;
    struct list_node_t* next;
} list_node_t;

// Функция для создания нового узла списка
list_node_t* createNode(const char* brand, const char* color, float price) {
    list_node_t* newNode = (list_node_t*)malloc(sizeof(list_node_t));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(-1);
    }

    strncpy_s(newNode->car.brand, brand, MAX_STR);
    strncpy_s(newNode->car.color, color, MAX_STR);
    newNode->car.price = price;
    newNode->next = NULL;

    return newNode;
}

// Функция для вставки узла в список с сохранением сортировки по возрастанию цены
void insertSorted(list_node_t** head, list_node_t* newNode) {
    // Если список пуст или новый элемент имеет меньшую цену, чем первый
    if (*head == NULL || newNode->car.price < (*head)->car.price) {
        newNode->next = *head;
        *head = newNode;
    }
    else {
        list_node_t* current = *head;

        while (current->next != NULL && current->next->car.price < newNode->car.price) {
            current = current->next;
        }

        newNode->next = current->next;
        current->next = newNode;
    }
}

// Функция для вывода списка
void printList(list_node_t* head) {
    list_node_t* current = head;
    while (current != NULL) {
        printf("Марка: %s, Цвет: %s, Цена: %.2f\n",
            current->car.brand, current->car.color, current->car.price);
        current = current->next;
    }
}

// Функция для сохранения списка в файл
void saveToFile(list_node_t* head, const char* filename) {
    FILE* f = NULL;
    fopen_s(&f, filename, "w");
    if (!f) {
        printf("Не удалось открыть файл для записи.\n");
        return;
    }

    list_node_t* current = head;
    while (current != NULL) {
        fprintf(f, "%s %s %.2f\n", current->car.brand, current->car.color, current->car.price);
        current = current->next;
    }

    fclose(f);
}

// Функция для загрузки списка из файла
list_node_t* loadFromFile(const char* filename) {
    FILE* f = NULL;
    fopen_s(&f, filename, "r");
    if (!f) {
        printf("Файл не найден, создается новый список.\n");
        return NULL;
    }

    list_node_t* head = NULL;
    char brand[MAX_STR];
    char color[MAX_STR];
    float price;

    // Читаем по строке, предполагая формат: марка цвет цена
    while (fscanf_s(f, "%s %s %f", brand, color, &price) == 3) {
        list_node_t* newNode = createNode(brand, color, price);
        insertSorted(&head, newNode);
    }

    fclose(f);

    return head;
}


// Пример использования
int main() {
    setlocale(LC_CTYPE, "");

    list_node_t* head = NULL;

    // Добавляем несколько автомобилей в список
    head = createNode("Toyota", "Красный", 2500000.0);
    insertSorted(&head, createNode("Honda", "Синий", 1200000.0));
    insertSorted(&head, createNode("Ford", "Чёрный", 1800000.0));
    insertSorted(&head, createNode("Lada", "Белый", 1000000.0));
    insertSorted(&head, createNode("Bentley", "Серый", 150000000.0));
    insertSorted(&head, createNode("BMW", "Чёрный", 4500000.0));
    insertSorted(&head, createNode("Mercedes", "Зелёный", 8000000.0));
    insertSorted(&head, createNode("Chevrolet", "Жёлтый", 3200000.0));
    insertSorted(&head, createNode("Mazda", "Серый", 1600000.0));
    insertSorted(&head, createNode("Exeed", "Чёрный", 3000000.0));
    insertSorted(&head, createNode("Omoda", "Синий", 2900000.0));
    insertSorted(&head, createNode("Chery", "Белый", 2600000.0));
    insertSorted(&head, createNode("Geely", "Синий", 2500000.0));
    insertSorted(&head, createNode("Volvo", "Бежевый", 3500000.0));
    insertSorted(&head, createNode("Lexus", "Чёрный", 5600000.0));

    // Выводим список
    printf("Список автомобилей:\n");
    printList(head);


    const char* filename = "cars.txt";
    // Загружаем данные из файла (если файл существует)
    head = loadFromFile(filename);

    int R;
    printf("Сколько автомобилей добавить? ");
    scanf_s("%d", &R);
    getchar();

    for (int i = 0; i < R; i++) {
        char brand[MAX_STR], color[MAX_STR];
        float price;
        printf("\nВведите данные для автомобиля %d\n", i + 1);
        printf("Марка: ");
        scanf_s("%s", brand);
        printf("Цвет: ");
        scanf_s("%s", color);
        printf("Цена: ");
        scanf_s("%f", &price);

        list_node_t* newCar = createNode(brand, color, price);
        insertSorted(&head, newCar);
    }

    // Выводим обновленный список на экран
    printf("\nОбновленный список автомобилей:\n");
    printList(head);

    // Сохраняем обновленный список в файл
    saveToFile(head, filename);


    // Освобождаем память
    while (head != NULL) {
        list_node_t* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
