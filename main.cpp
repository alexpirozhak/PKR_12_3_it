#include <iostream>

using namespace std;

// Структура для вузла двонаправленого списку
struct Node {
    int data;
    Node* next;
    Node* prev;
};

// Функція для додавання елемента в кінець списку
void append(Node*& head, int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;

    if (head == nullptr) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}

// Функція для друку списку
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Функція для дублювання кожного елемента списку
void duplicateElements(Node*& head) {
    Node* temp = head;
    while (temp != nullptr) {
        Node* duplicateNode = new Node();
        duplicateNode->data = temp->data;
        duplicateNode->next = temp->next;
        duplicateNode->prev = temp;

        if (temp->next != nullptr) {
            temp->next->prev = duplicateNode;
        }
        temp->next = duplicateNode;
        temp = duplicateNode->next;
    }
}

// Функція для дублювання елемента початкового списку за номером
void duplicateElementByIndexFromOriginal(Node*& head, int index) {
    Node* temp = head;
    int currentIndex = 0;

    while (temp != nullptr && currentIndex < index) {
        temp = temp->next;
        currentIndex++;
    }

    if (temp == nullptr) {
        cout << "Елемент з таким номером не знайдено." << endl;
        return;
    }

    Node* duplicateNode = new Node();
    duplicateNode->data = temp->data;
    duplicateNode->next = temp->next;
    duplicateNode->prev = temp;

    if (temp->next != nullptr) {
        temp->next->prev = duplicateNode;
    }
    temp->next = duplicateNode;
}

// Функція для ручного введення значень списку
void inputList(Node*& head) {
    int n, value;
    cout << "Введіть кількість елементів: ";
    cin >> n;
    for (int i = 0; i < n; i++) {
        cout << "Введіть значення елемента " << i + 1 << ": ";
        cin >> value;
        append(head, value);
    }
}

// Головна функція
int main() {
    Node* originalList = nullptr;
    int choice;

    cout << "Виберіть опцію:" << endl;
    cout << "1. Вручну ввести значення" << endl;
    cout << "2. Використати заздалегідь визначені значення" << endl;
    cout << "Ваш вибір: ";
    cin >> choice;

    if (choice == 1) {
        inputList(originalList);
    } else if (choice == 2) {
        append(originalList, 1);
        append(originalList, 2);
        append(originalList, 3);
        append(originalList, 4);
        append(originalList, 5);
    } else {
        cout << "Неправильний вибір" << endl;
        return 1;
    }

    // Друк початкового списку
    cout << "Початковий список: ";
    printList(originalList);

    // Дублювання елементів початкового списку
    Node* listCopy = nullptr;
    Node* temp = originalList;
    while (temp != nullptr) {
        append(listCopy, temp->data);
        temp = temp->next;
    }

    // Дублювання елемента за індексом в початковому списку
    int index;
    cout << "Введіть номер елемента початкового списку, який потрібно дублювати: ";
    cin >> index;

    duplicateElementByIndexFromOriginal(listCopy, index);

    // Друк списку після дублювання елемента за індексом
    cout << "Список після дублювання елемента за номером: ";
    printList(listCopy);

    return 0;
}
