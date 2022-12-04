#include <iostream>

using namespace std;

int main() {
    int impares=0, pares=0;    
    int i, A[6]={}, B[6]={};
    int parA = 0, impD = 0;

    //salva + contabiliza os pares e impares em A
    for (i=0; i<6; i++) {
        cout << "A [" << i << "] => ";
        cin >> A[i];
        
        if (A[i] % 2 == 0) {
            pares++; 
        } else{
            impares++; 
        }
    }
    
    //salva + contabiliza os pares e impares em B
    for (i=0; i<6; i++) {
        cout << "B [" << i << "] => ";
        cin >> B[i];

        if (B[i] % 2 == 0) {
            pares++; 
        }else{
            impares++; 
        }
        
    }

    //cria os vetores C e D com o tamanho de par e impar
    int C[pares], D[impares];
    cout << "\nC.size = " << pares << "\n";
    cout << "D.size = " << impares << "\n";
    
    for (i=0; i<6; i++){
                
            if (A[i] % 2 == 0){
                C[parA] = A[i];
                parA ++;
            }else{
                D[impD] = A[i];
                impD ++;
            }
    }
    
    for (i=0; i<6; i++){
            
            if (B[i] % 2 == 0){
                C[parA] = B[i];
                parA++;
            }else{
                D[impD] = B[i];
                impD++;
            }
    }


    cout << "\n";
    //printando A [check!]
    cout << "A = [";
    for (int count = 0; count < 6; count++){
        cout << " " << A[count] << " ";
    }
    cout << "]";
    
    //printando B [check!]
    cout << "\n";
    cout << "B = [";
    for (int count = 0; count < 6; count++){
        cout << " " << B[count] << " ";
    }
    cout << "]";
    
    //printando C
    cout << "\n";
    cout << "C = [";
    for (int count = 0; count < parA; count ++){
        cout << " " << C[count] << " ";
    }
    cout << "]";
    
    //printando D
    cout << "\n";
    cout << "D = [";
    for (int count = 0; count < impD; count ++){
        cout << " " << D[count] << " ";
    }
    cout << "]";
}