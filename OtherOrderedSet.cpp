#include <iostream>
using namespace std;

int Partition(char arr[], int low, int high){
    
    int pivot = arr[high];
    int i = low-1;
    
    for(int j = low; j <= high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i+1], arr[high]);
    return (i+1);
    
}

void QuickSort(char arr[], int low, int high){
    if(low < high){
        int pi = Partition(arr, low, high);
        
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

class OrderedSet{
    private:
    char* elements;
    int max_size;
    int size = 0;
    
    public:
    OrderedSet(int max_size){
        this-> max_size = max_size;
        elements = new char[max_size];
    }
    
    void Insert(char let){
        if(!IsFull()){
        int belongs = BinarySearch(let, 0, size-1);
        if(belongs == -1){
            elements[size] = let;
            size++;
        }
        
        else{
            cout << let << " is already in the set";
        }
        
        }
        
        else{
            cout << "The set is full";
        }
    }
    
    void Remove(char let){
        if(!IsEmpty()){
            int belongs = BinarySearch(let, 0, size-1);
            if(belongs != -1){
                elements[belongs] = elements[size-1];
                size--;
                QuickSort(elements, 0, size-1);
            }
            else{
                cout << let << " is not in the set";
            }
        }

        else{
            cout << "The set is empty";
        }
    
    }
    
    int BinarySearch(char let, int start, int end){
        if(start == 0 and end == -1){
            return -1;
        }
        
        QuickSort(elements, 0, size-1);
        if(start > end){
            return -1;
        }
        
        else{
            int middle = start + (end - start)/2;
            if(elements[middle] < let){
                start = middle + 1;
            }
            else if(elements[middle] > let){
                end = middle-1;
            }
            else{
                return middle;
            }
            
            return BinarySearch(let, start, end);
        }
        
    }
    
    bool IsEmpty(){
        return size == 0;
    }
    
    bool IsFull(){
        return size == max_size;
    }
    
    int GetSize(){
        return this->size;
    }
};

int main()
{
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
            int isin = conjunto.BinarySearch(let, 0, (conjunto.GetSize()-1));
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
            break;
        }
    }

    

    return 0;
}
