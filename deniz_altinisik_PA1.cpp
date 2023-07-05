#include <iostream>
#include <ctime>
#include <cstring>
using namespace std;

int createNumber(char a[], int N){ // creates random valid number
    int counter = 0;
    int flag = 1;
    while(counter < N){   
        int index;
        if(counter == 0){
        index = rand() % 9 + 1;
        a[counter] = index + 48;
        counter++;
        }
        else{
        index = rand() % 10;
            for(int i = 0; i < N; i++){
                if(a[i] == index + 48){
                flag = 0;
                break;
                }
            }
                if(flag == 1){
                a[counter] = index + 48;
                counter++;
                }
                flag = 1;
     }
    }
    return 1;
};
int checkUserEntry(int size, string arr){ // check if a digit is used only for once
    for(int i = 0; i < size; i++){
        for(int j = 0; j < i; j++){
            if(arr[i] == arr[j])
        return (-1);
        }
    }
    return 1;
};

int main(int argc, char *argv[]){ // MAIN
    
srand(time(NULL));
int N;

if(strlen(argv[2]) > 1 && argv[1][1] == 'u'){ // -u option
    string iter;
    N = strlen(argv[2]);
    for(int k = 0; k < N; k++){
        iter[k] = argv[2][k];
    }
    for(int i = 0; i < N; i++){ // tried to use CheckUserEntry here, does the same thing but function crashes for some reason
        for(int j = 0; j < i; j++){
            if(iter[i] == iter[j]){
            std::cout << "E0" << endl;
            return 0; 
            } 
        }
    }
    
    char number[N];
    for(int i = 0; i < strlen(argv[2]); i++){ // this loop checks the digits if they are integers or not
        if(argv[2][i] > 57 || argv[2][i] < 48){
            cerr << "E2" << endl;
            return 0;
        }
        number[i] = argv[2][i]; // and copies the argv entry to number array
    }
    std::cout << "Enter the secret number: ";
int cExact=0,cMisplaced=0,turn=0;

    for(;turn < 100; turn++){
        string iter;
        cin >> iter;
         
        if(iter.size() != N){
            cerr << "E0" << endl;
            return 0;
        }
        if(checkUserEntry(N,iter) == -1)
        {
            cerr << "E0" << endl;
            return 0;
        }
        for(int i = 0; i < N; i++){
            if(number[i] == iter[i])
                 cExact++;
            
            for(int j  = 0; j < N; j++){
                if(number[i] == iter[j] && i != j){
                    cMisplaced++;
                    break;
                }
            }
        }
        std::cout << cExact << " " << cMisplaced << endl;
        if(cExact == N){
            std::cout << "FOUND " << turn + 1 << endl;
            return 0;
        }
        
        cExact = 0, cMisplaced = 0;  
    }
    std::cout << "FAILED" << endl;
    return 0;

}
else if(argv[1][1] == 'r' && stoi(argv[2]) > 0 && stoi(argv[2]) < 10){ // -r option 
    
    if(*argv[2] == '1' ||*argv[2] == '2' ||*argv[2] == '3' ||*argv[2] == '4' ||*argv[2] == '5' ||*argv[2] == '6' ||*argv[2] == '7' ||*argv[2] == '8' ||*argv[2] == '9'){
    N = stoi(argv[2]); // check if the argument in command line is suitable
    char number[N]; // random valid number array
    
    createNumber(number,N); // random valid number created

    int cExact=0,cMisplaced=0,turn=0;

    for(;turn < 100; turn++){
        string iter;
        cin >> iter;
        for(int i = 0; i < N; i++){
        if(iter[i] > 57 || iter[i] < 48){ // checks validity
            cerr << "E2" << endl;
            return 0;
        }
    }
        if(iter.size() != N){ // checks the users total input digit numbers if they match valid number's digit amount 
            cerr << "E1" << endl;
            return 0;
        }
        if(checkUserEntry(N,iter) == -1) // checks if a digit is used only for once or not
        {
            cerr << "E0" << endl;
            return 0;
        }
        for(int i = 0; i < N; i++){
            if(number[i] == iter[i])
                 cExact++;
            
            for(int j  = 0; j < N; j++){
                if(number[i] == iter[j] && i != j){
                    cMisplaced++;
                    break;
                }
            }
        }
        std::cout << cExact << " " << cMisplaced << endl;
        if(cExact == N){
            std::cout << "FOUND " << turn + 1 << endl;
            return 0;
        }
        cExact = 0, cMisplaced = 0;  
    }
    std::cout << "FAILED" << endl;
    return 0;
    }
    else{
        cerr << "E0" << endl;
        return 0;
    }

    std::cout << endl;
 }
else{
    cerr << "E0" << endl;
    return 0;
 }
} /*end of main*/