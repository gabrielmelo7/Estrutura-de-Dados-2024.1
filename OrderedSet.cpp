#include<iostream>
using namespace std;

class OrderedSet{
    private:
    char* elements;
    unsigned int max_size;
    unsigned int vec_size = 0;

    public:

    OrderedSet(unsigned int max_size){
        this->max_size = max_size;
        elements = new char[max_size];
    }

    ~OrderedSet(){
        delete[] elements;
    }

    int BinarySearch(char let){
        int start = 0, end = vec_size - 1;
        while(start<=end){
            int middle = start + (end - start)/2;
            if(let == elements[middle]){
                return middle;
            }
            else if(let < elements[middle]){
                end = middle - 1;
            }
            else{
                start = middle + 1;
            }
        }
        return -1;
    }

    void Insert(char let){
        if (IsFull()){
            cout << "The set is full\n";
        }
        else{
        int is_in = BinarySearch(let);
        if(is_in == -1){
            elements[vec_size] = let;
            vec_size++;
        }
        else{
            cout << let << " is already in the set\n";
        }
        }
    }

    void Remove(char let){
        if(IsEmpty()){
            cout << "The set is empty\n";
        }
        else{
        int is_in = BinarySearch(let);
        if(is_in == -1){
            cout << let << " is not even in the set\n";
        }
        else{
                for(size_t i = is_in; i < vec_size; i++){
                    elements[i] = elements[i+1];
                }
                vec_size--;
            
        }
        }
    }

    bool IsFull(){
        return vec_size == max_size;
    }

    bool IsEmpty(){
        return vec_size == 0;
    }

    
};

int main(){

    OrderedSet conjunto(5);
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
            int isin = conjunto.BinarySearch(let);
            if(isin != -1){
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
        }
    }




    return 0;
}