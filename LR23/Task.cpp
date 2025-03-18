#include <iostream>

#define MAX_STR 50

// ���������, �������������� ������ ����������
typedef struct {
    char brand[MAX_STR];
    char color[MAX_STR];
    float price;
} car_t;

// ��������� ���� ������������ ������
typedef struct list_node_t {
    car_t car;
    struct list_node_t* next;
} list_node_t;

// ������� ��� �������� ������ ���� ������
list_node_t* createNode(const char* brand, const char* color, float price) {
    list_node_t* newNode = (list_node_t*)malloc(sizeof(list_node_t));
    if (newNode == NULL) {
        printf("������ ��������� ������\n");
        exit(-1);
    }

    strncpy_s(newNode->car.brand, brand, MAX_STR);
    strncpy_s(newNode->car.color, color, MAX_STR);
    newNode->car.price = price;
    newNode->next = NULL;

    return newNode;
}

// ������� ��� ������� ���� � ������ � ����������� ���������� �� ����������� ����
void insertSorted(list_node_t** head, list_node_t* newNode) {
    // ���� ������ ���� ��� ����� ������� ����� ������� ����, ��� ������
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

// ������� ��� ������ ������
void printList(list_node_t* head) {
    list_node_t* current = head;
    while (current != NULL) {
        printf("�����: %s, ����: %s, ����: %.2f\n",
            current->car.brand, current->car.color, current->car.price);
        current = current->next;
    }
}

// ������� ��� ���������� ������ � ����
void saveToFile(list_node_t* head, const char* filename) {
    FILE* f = NULL;
    fopen_s(&f, filename, "w");
    if (!f) {
        printf("�� ������� ������� ���� ��� ������.\n");
        return;
    }

    list_node_t* current = head;
    while (current != NULL) {
        fprintf(f, "%s %s %.2f\n", current->car.brand, current->car.color, current->car.price);
        current = current->next;
    }

    fclose(f);
}

// ������� ��� �������� ������ �� �����
list_node_t* loadFromFile(const char* filename) {
    FILE* f = NULL;
    fopen_s(&f, filename, "r");
    if (!f) {
        printf("���� �� ������, ��������� ����� ������.\n");
        return NULL;
    }

    list_node_t* head = NULL;
    char brand[MAX_STR];
    char color[MAX_STR];
    float price;

    // ������ �� ������, ����������� ������: ����� ���� ����
    while (fscanf_s(f, "%s %s %f", brand, color, &price) == 3) {
        list_node_t* newNode = createNode(brand, color, price);
        insertSorted(&head, newNode);
    }

    fclose(f);

    return head;
}


// ������ �������������
int main() {
    setlocale(LC_CTYPE, "");

    list_node_t* head = NULL;

    // ��������� ��������� ����������� � ������
    head = createNode("Toyota", "�������", 2500000.0);
    insertSorted(&head, createNode("Honda", "�����", 1200000.0));
    insertSorted(&head, createNode("Ford", "׸����", 1800000.0));
    insertSorted(&head, createNode("Lada", "�����", 1000000.0));
    insertSorted(&head, createNode("Bentley", "�����", 150000000.0));
    insertSorted(&head, createNode("BMW", "׸����", 4500000.0));
    insertSorted(&head, createNode("Mercedes", "������", 8000000.0));
    insertSorted(&head, createNode("Chevrolet", "Ƹ����", 3200000.0));
    insertSorted(&head, createNode("Mazda", "�����", 1600000.0));
    insertSorted(&head, createNode("Exeed", "׸����", 3000000.0));
    insertSorted(&head, createNode("Omoda", "�����", 2900000.0));
    insertSorted(&head, createNode("Chery", "�����", 2600000.0));
    insertSorted(&head, createNode("Geely", "�����", 2500000.0));
    insertSorted(&head, createNode("Volvo", "�������", 3500000.0));
    insertSorted(&head, createNode("Lexus", "׸����", 5600000.0));

    // ������� ������
    printf("������ �����������:\n");
    printList(head);


    const char* filename = "cars.txt";
    // ��������� ������ �� ����� (���� ���� ����������)
    head = loadFromFile(filename);

    int R;
    printf("������� ����������� ��������? ");
    scanf_s("%d", &R);
    getchar();

    for (int i = 0; i < R; i++) {
        char brand[MAX_STR], color[MAX_STR];
        float price;
        printf("\n������� ������ ��� ���������� %d\n", i + 1);
        printf("�����: ");
        scanf_s("%s", brand);
        printf("����: ");
        scanf_s("%s", color);
        printf("����: ");
        scanf_s("%f", &price);

        list_node_t* newCar = createNode(brand, color, price);
        insertSorted(&head, newCar);
    }

    // ������� ����������� ������ �� �����
    printf("\n����������� ������ �����������:\n");
    printList(head);

    // ��������� ����������� ������ � ����
    saveToFile(head, filename);


    // ����������� ������
    while (head != NULL) {
        list_node_t* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
