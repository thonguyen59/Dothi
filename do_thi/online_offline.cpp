#include <iostream>

using namespace std;

// còn case sai
const int TABLE_SIZE = 500000;

struct HashNode {
    int id;
    bool isOccupied;
};

HashNode hashTable[TABLE_SIZE];

int hashFunction(const int& id) {
    return id % TABLE_SIZE;
}

int quadraticProbing(const int& id, int i) {
    return (hashFunction(id) + i) % TABLE_SIZE;
}

//int quadraticProbing(const int& id, int i) {
//    return (hashFunction(id) + (i * i)) % TABLE_SIZE;
//}

// Hàm để thêm một ID mới vào bảng băm
void addID(const int& id) {
    int pos = hashFunction(id);
    int i = 1;

    while (hashTable[pos].isOccupied) {
        if (hashTable[pos].id != id) {
            pos = quadraticProbing(pos, i);
            i++;
        } else {
            return;
        }
    }

    if (!hashTable[pos].isOccupied) {
        hashTable[pos].id = id;
        hashTable[pos].isOccupied = true;
    }
}

// Hàm để tìm kiếm một ID trong bảng băm
bool searchID(const int& id) {
    int pos = hashFunction(id);
    int i = 1;

    while (hashTable[pos].isOccupied) {
        if (hashTable[pos].id == id) {
            return true;
        }
        pos = quadraticProbing(pos, i);
        i++;
    }

    return false;
}

// Hàm để xóa một ID khỏi bảng băm
void removeID(const int& id) {
    int pos = hashFunction(id);
    int i = 1;

    while (hashTable[pos].isOccupied) {
        if (hashTable[pos].id == id) {
            hashTable[pos].isOccupied = false;
            return;
        }
        pos = quadraticProbing(pos, i);
        i++;
    }
}

int main() {
    char choice;
    int id;

    do {
        cin >> choice;

        switch (choice) {
            case '1':
                cin >> id;
                addID(id);
                break;
            case '2':
                cin >> id;
                if (searchID(id)) {
                    cout << 1;
                } else {
                    cout << 0;
                }
                break;
            case '3':
                cin >> id;
                removeID(id);
                break;
            case '0':
                break;
        }
    } while (choice != '0');
}
