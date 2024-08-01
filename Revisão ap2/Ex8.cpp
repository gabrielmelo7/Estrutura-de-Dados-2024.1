#include <iostream>

class Queue {
private:
    int *vet;
    int size;
    int first;
    int last;
    int count;

    void Resize(int newSize) {
        int *new_vet = new int[newSize];
        int currentSize = size;
        int start = first;

        for (int i = 0; i < count; i++) {
            new_vet[i] = vet[start];
            start = (start + 1) % currentSize;
        }

        delete[] vet;
        vet = new_vet;
        size = newSize;
        first = 0;
        last = count - 1;
    }

public:
    Queue(int initSize) : size(initSize), first(0), last(-1), count(0) {
        vet = new int[size];
    }

    ~Queue() {
        delete[] vet;
    }

    void Insert(int num) {
        if (Full()) {
            Resize(size * 2);
        }

        last = (last + 1) % size;
        vet[last] = num;
        count++;
    }

    void Delete() {
        if (!Empty()) {
            first = (first + 1) % size;
            count--;

            if (count <= size / 4 && size > 1) {
                Resize(size / 2);
            }
        }
    }

    bool Empty() const {
        return count == 0;
    }

    bool Full() const {
        return count == size;
    }

    void Consult() const {
        if (Empty()) {
            std::cout << "Queue is empty.\n";
            return;
        }

        int start = first;
        for (int i = 0; i < count; i++) {
            std::cout << vet[start] << ' ';
            start = (start + 1) % size;
        }
        std::cout << '\n';
    }

    void PrintQueue() const {
        Consult();
    }
};

int main() {
    Queue fila(1);
    int ans = -50000;

    while (true) {
        std::cout << "insert - > 1, remove -> 2, consult - > 3, print -> 4, end - > -1\n";
        std::cin >> ans;

        if (ans == 1) {
            int aux;
            std::cout << "insert the int\n";
            std::cin >> aux;
            fila.Insert(aux);
            std::cout << aux << " is in the queue\n";
        } else if (ans == 2) {
            fila.Delete();
            std::cout << "removed\n";
        } else if (ans == 3) {
            fila.Consult();
        } else if (ans == 4) {
            fila.PrintQueue();
        } else if (ans == -1) {
            std::cout << "see ya\n";
            break;
        } else {
            std::cout << "Invalid option\n";
        }
    }

    return 0;
}
