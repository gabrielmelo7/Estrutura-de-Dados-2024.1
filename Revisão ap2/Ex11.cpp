#include <iostream>
using namespace std;

class Deque{
    private:
    struct Node{
        Node *n_left;
        char elem;
        Node *n_right;
    };

    Node* left;
    Node* right;

    public:

    Deque(){
        left = nullptr;
        right =  nullptr;
    }

    ~Deque(){
        while(!Empty()) LeftDelete();
    }

    void RightAdd(char elem){
        Node *new_node = new Node;
        new_node->elem = elem;

        if(Empty()){
            new_node->n_right = right;
            right = new_node;
            left = new_node;
        } else{

            new_node->n_right = right->n_right;
            right->n_right = new_node;
            new_node->n_left = right;
            right = new_node;
        }
    }

    void LeftAdd(char elem){
        Node *new_node = new Node;
        new_node->elem = elem;

        if(Empty()){
            new_node->n_left = left;
            left = new_node;
            right = new_node;
        } else{

            new_node->n_left = left->n_left;
            left->n_left = new_node;
            new_node->n_right = left;
            left = new_node;
        }
    }

    void RightDelete(){
        if(!Empty()){
            Node *temp = right;
            right = right->n_left;
            delete temp;

            if(right == nullptr) left = nullptr;
        }
    }

    void LeftDelete(){
        if(!Empty()){
            Node *temp = left;
            left = left->n_right;
            delete temp;

            if(left == nullptr) right = nullptr;
        }
    }   

    void RightConsult(){
        if(!Empty()){
            cout << right->elem;
        }
    }

    void LeftConsult(){
        if(!Empty()){
            cout << left->elem;
        }
    }

    bool Empty(){
        return left == nullptr && right == nullptr;
    }
};

int main(){

    Deque queue;
    int ans = -50000;
    while(true){
        std::cout << "right insert - > 1, left insert  -> 2, right remove -> 3, left remove -> 4, right consult - > 5, left consult -> 6, end - > -1";
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
            queue.RightDelete();
            std::cout << "deleted" << '\n';
        }
        else if(ans == 4){
            queue.LeftDelete();
            std::cout << "deleted" << '\n';
        } 
        else if(ans == 5){
            queue.RightConsult();
            std::cout << '\n';
        }
        else if(ans == 6){
            queue.LeftConsult();
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