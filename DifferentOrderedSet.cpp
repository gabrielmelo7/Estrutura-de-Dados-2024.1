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
            return start;
        }

        void Insert(char let){
        if (IsFull()){
                cout << "The set is full\n";
            }
        else{
            int position = BinarySearch(let);

            if(elements[position] == let){
                cout << let << " is already in the set!\n";
            }

            else{
            for(int i = vec_size; i > position; i--){
                elements[i] = elements[i-1];
            }
            elements[position] = let;
            vec_size++;
            }

        }
            
        }

        void Remove(char let){
            if(IsEmpty()){
                cout << "The set is empty\n";
            }
            else{
            int position = BinarySearch(let);

            if(elements[position] != let){
                cout << let << " is not even in the set\n";
            }

            else{
                    for(size_t i = position; i < vec_size - 1; i++){
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

        void Verify(){
            if(!IsEmpty()){
            for(size_t i = 0; i < vec_size; i++){
                cout << elements[i] << ' ';
            }
            } else{
                cout << "The set is empty";
            }
        }

        bool IsIn(char let){
            int position = BinarySearch(let);
            return elements[position] == let;
        }

        
    };

    int main(){

        OrderedSet conjunto(5);
        int ans;
        char let;
        while(true){
            cout << "1 - insert, 2 - remove, 3 - consult, 4 - verify the set -1 - end\n";
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
                bool isin = conjunto.IsIn(let);
                if(isin){
                    cout << let << " is in the set\n";
                }

                else{
                    cout << let << " is not in the set\n";
                }
            }
            else if(ans == 4){
                conjunto.Verify();
                cout << '\n';
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