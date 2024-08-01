#include <iostream>
using namespace std;

class PQueue{
    private:
    struct Node{
        char element;
        Node *next;
    };

    Node *start;
    Node *end;

    public:

    PQueue(){
        start = nullptr;
        end = nullptr;
    }

    ~PQueue(){
        while(!Empty()) UnQueue();
    }

    void RightAdd(char elem){
        Node *new_node = new Node{elem, nullptr};

        if(Empty()) start = new_node;
        else end->next = new_node;

        end = new_node;
    }

    void LeftAdd(char elem){
        Node *new_node = new Node{elem, nullptr};

        if(Empty()) end = new_node;
        else new_node->next = start;

        start = new_node;
    }

    void UnQueue(){
        if(!Empty()){
            Node *temp = start;
            start = start->next;
            delete temp;

            if(start == nullptr) end = nullptr;
        }
    }

    void Consult(){
        if(!Empty()) cout << start->element;
    }

    bool Empty(){
        return start == nullptr && end == nullptr;
    }
};

int main(){

    PQueue queue;
    int ans = -50000;
    while(true){
        std::cout << "right insert - > 1, left insert  -> 2, remove -> 3, consult -> 4, end - > -1";
        std::cout << "\n";
        std::cin >> ans;
        if(ans == 1){
            char aux;
            std::cout << "insert the char";
            std::cout << "\n";
            std::cin >> aux;
            queue.RightAdd(aux);
            std::cout << aux << " is in the queue";
            std::cout << "\n";
        }
        else if(ans == 2){
            char aux;
            std::cout << "insert the char";
            std::cout << "\n";
            std::cin >> aux;
            queue.LeftAdd(aux);
            std::cout << aux << " is in the queue";
            std::cout << "\n";
        }
        else if(ans == 3){
            queue.UnQueue();
            std::cout << "deleted" << '\n';
        }
        else if(ans == 4){
            queue.Consult();
            std::cout << '\n';
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
