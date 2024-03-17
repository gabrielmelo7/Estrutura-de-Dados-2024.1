    #include <iostream>
    using namespace std;

    class UnorderedDictionary{
        private:
        int* keys;
        string* values;
        unsigned int size;
        unsigned int index = 0;

        public:

        UnorderedDictionary(unsigned int size){
            this->size = size;
            keys = new int[size];
            values = new string[size];
        }

        ~UnorderedDictionary(){
            delete[] keys;
            delete[] values;
        }

        void Insert(int key, string value){
            if(!IsFull()){
                int belong = Belongs(key); 
                if(belong == -1){
                    keys[index] = key;
                    values[index] = value;
                    index++;
                }

                else{
                    cout << "The Key is already being used";
                }
            }

            else{
                cout << "The dicionary is full";
            }
        }

        string Consult(int key){
            if(!IsEmpty()){
                int des_index = Belongs(key);
                if(des_index != -1){
                    return values[des_index];
                }
                else{
                    return "The key isn´t stored";
                }
            }

            else{
                return "The dictionary is empty";
            }
        }

        void Remove(int key){
            if(!IsEmpty()){
            int des_index = Belongs(key);

            if(des_index != -1){
                for(size_t i = des_index; i < index-1; i++){
                    keys[i] = keys[i+1];
                    values[i] = values[i+1];    
                }
                index--;
            }

            else{
                cout << "The desired key is not in the dictionary";
            }
        }

            else{
                cout << "The dictionary is empty";
            }
        }

        int Belongs(int key){
            for(size_t i = 0; i < index; i++){
                if(keys[i] == key){
                    return i;
                    break;
                }
            }

            return -1;
        }

        bool IsEmpty(){
            return index == 0;
        }

        bool IsFull(){
            return index == size;
        }
    };

    int main(){

        UnorderedDictionary dicionario(5);
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
                dicionario.Insert(key, value);
            }
            else if (ans == 2){
                cout << "Insert the key you want to remove:\n";
                cin >> key;
                dicionario.Remove(key);
            }
            else if (ans == 3){
                cout << "Insert the key you want to consult\n";
                cin >> key;
                string out = dicionario.Consult(key);
                cout << out << '\n';
                
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