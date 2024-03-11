#include <iostream>
using namespace std;

class UnorderedSet {
    private:
    char* elements;
    int max_size;
    int vec_size = 0;

    public:

    UnorderedSet(int max_size){
        this->max_size = max_size;
        elements = new char[max_size];
    }

    ~UnorderedSet(){
        delete[] elements;
    }

    bool Belongs(char let){
        for(int i = 0; i < vec_size; i++){
            if(elements[i] == let){
                return true;
                break;
            }
        }
        return false;
    }

    bool IsFull(){
        return vec_size == max_size;
    }

    bool IsEmpty(){
        return vec_size == 0;
    }

    void Insert(char let){
        if(IsFull()){
            cout << "The set is full!\n";
        }
        else if(!Belongs(let)){
            elements[vec_size] = let;
            vec_size++;
        }
        else{
            cout << let << " is already in the set!\n";
        }
    }

    void Remove(char let){
        if(IsEmpty()){
            cout << "The set is empty!\n";
        }

        else{
            if(!Belongs(let)){
                cout << let << " is not even in the set\n";
            }
            else{
        for(int i = 0; i < vec_size; i++){
            if(elements[i] == let){
                elements[i] = elements[vec_size];
                vec_size--;
                break;
            }
        }
        }
        }

    }
};



int main(){

    UnorderedSet conjunto(5);
    int ans;
    char let;
    while(true){
        cout << "1 - insert, 2 - remove, 3 - verify, -1 - end\n";
        cin >> ans;
        if(ans == 1){
            cout << "Insert the char:\n";
            cin >> let;
            conjunto.Insert(let);
        }
        else if (ans == 2){
            cout << "Insert the char you want to remove:\n";
            cin >> let;
            conjunto.Remove(let);
        }
        else if (ans == 3){
            cout << "Insert the char you want to verify\n";
            cin >> let;
            bool isin = conjunto.Belongs(let);
            if(isin){
                cout << let << " is in the set\n";
            }
            else{
                cout << let << " is not in the set\n";
            }
        }
        else if (ans == -1){
            cout << "Bye\n";
            break;
        }
        else{
            cout << "Stop it, get some help\n";
            break;
        }
    }




    return 0;
}
