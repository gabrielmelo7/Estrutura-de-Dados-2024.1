    #include <iostream>
    using namespace std;

    struct Pair{
        int key;
        string value;
    };

    struct Dictionary{
        int capacity;
        int index;
        Pair* dict;
    };

    bool IsFull(Dictionary &map);
    bool IsHere(Dictionary &map, int key);
    void QuickSort(Dictionary &map, int low, int high);
    bool IsEmpty(Dictionary &map);
    int BinarySearch(Dictionary &map, int start, int end, int key);

    void StartDict(int size, Dictionary &map){
        map.capacity = size;
        map.index = 0;
        map.dict = new Pair[map.capacity];
    };

    void DestroyDict(Dictionary &map){
        delete[] map.dict;
    };

    void Insert(Dictionary &map, int key, string value){
        if(!IsFull(map)){
            if(!IsHere(map, key)){
                map.dict[map.index].key = key;
                map.dict[map.index].value = value;
                map.index++;
                QuickSort(map, 0, map.index-1);

            }   else{
                throw runtime_error("The key is already stored!");
            }
        } else{
            throw runtime_error("The dictionary is full\n");
        }
    };

    void Delete(Dictionary &map, int key){
        if(!IsEmpty(map)){
            if(IsHere(map ,key)){
            int position = BinarySearch(map, 0, map.index-1, key);
            map.dict[position] = map.dict[map.index-1];
            map.index--;
            QuickSort(map, 0, map.index-1);

            }   else{
                throw runtime_error("The key is not stored");
            }
        } else{
            throw runtime_error("The dictionary is empty");
        }
    };

    bool IsFull(Dictionary &map){
        return map.index == map.capacity;
    };

    bool IsEmpty(Dictionary &map){
        return map.index == 0;
    };

    int BinarySearch(Dictionary &map, int start, int end, int key){
        if(start > end){
            return -1;
        }   else{
            int middle = start + (end - start) / 2;
            if(key == map.dict[middle].key){
                return middle;
            }   else if(key < map.dict[middle].key){
                end = middle - 1;
            }   else{
                start = middle + 1;
            }

            return BinarySearch(map, start, end, key);
        }
    };

    bool IsHere(Dictionary &map, int key){
        int search = BinarySearch(map, 0, map.index - 1, key);
        return search != -1;
    };

    int Partition(Dictionary &map, int low, int high){
        int pivot = map.dict[high].key;
        int i = low - 1;

        for(int j = low; j <= high; j++){
            if(map.dict[j].key < pivot){
                i++;
                swap(map.dict[i], map.dict[j]);
            }
        }

        swap(map.dict[i+1], map.dict[high]);
        return i+1; 
    }

    void QuickSort(Dictionary &map, int low, int high){
        if(low < high){
            int pi = Partition(map, low, high);

            QuickSort(map, low, pi-1);
            QuickSort(map, pi+1, high);
        }
    }

    string Consult(Dictionary &map, int key){
        if(!IsEmpty(map)){
            if(IsHere(map, key)){
                int position = BinarySearch(map, 0, map.index-1, key);
                return map.dict[position].value;
            } else{
                return "The key isn´t stored";
            }
        } else{
            return "The dictionary is empty";
        }
    }

    
    int main(){
        Dictionary map;
        StartDict(5, map);
        int ans;
        int key;
        string value;
        while(true){
            cout << "1 - insert, 2 - remove, 3 - consult, -1 - end\n";
            cin >> ans;
            if(ans == 1){
                cout << "Insert the key (int):\n";
                cin >> key;
                cout << "Insert the value (string):\n";
                cin >> value;
                Insert(map, key, value);   
            }
            else if (ans == 2){
                cout << "Insert the key you want to remove:\n";
                cin >> key;
                Delete(map, key);
            }
            else if (ans == 3){
                cout << "Insert the key you want to consult\n";
                cin >> key;
                string out = Consult(map, key);
                cout << out << '\n';
                
            }
            else if (ans == -1){
                cout << "Bye\n";
                DestroyDict(map);
                break;
            }
            else{
                cout << "Stop it, get some help\n";
            }
        }



        return 0;
    }