#include <iostream>
using namespace std;

class Queue{
    private:

    struct Node{
        char element;
        Node *next;
    };

    Node *start;
    Node *end;

    public:

    Queue(){
        Node *start = nullptr;
        Node *end = nullptr;
    }

    ~Queue(){
        while(!Empty()) DeQueue();
    }

    void EnQueue(char elem){
        Node *new_node = new Node;
        
        if(Empty()){
            new_node->next = end;
            end = new_node;
            start = new_node;
        } else{
            new_node->next = end->next;
            end->next = new_node;
            end = new_node;
        }
    }

    void DeQueue(){
        Node *temp = start;
        start = start->next;
        delete temp;
        if(start == nullptr) end == nullptr;
    }

    bool Empty(){
        return start == nullptr && end == nullptr;
    }

    void Consult(){
        cout << start->element;
    }
};



int main(){

      Queue queue;
    int ans = -50000;
    while(true){
        std::cout << "insert - > 1, remove -> 2, consult - > 3, end - > -1";
        std::cout << "\n";
        std::cin >> ans;
        if(ans == 1){
            char aux;
            std::cout << "insert the int";
            std::cout << "\n";
            std::cin >> aux;
            queue.EnQueue(aux);
            std::cout << aux << " is in the queue";
            std::cout << "\n";
        }
        else if(ans == 2){
            queue.DeQueue();
            std::cout << "removed";
            std::cout << "\n";
        }
        else if(ans == 3){
            queue.Consult();
            std::cout << "\n";
        }
        else if(ans == -1){
            std::cout << "see ya";
            break;
        }
        else{
            std::cout << "stop it, get some help";
            std::cout << "\n";
        }
    }


    return 0;
}