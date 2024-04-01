#include <iostream>
#include <string>

const int n = 3; // [0, 1, 2]
static std::string pilha[n];

static int answer = 0;
static int top = 0;

void pop() {
    
    pilha[top] = ""; // vazio 
    top --;

    std::cout << "top: " << top;
    
    for(int i=0;i<=n;i++){
        std::cout<<pilha[i];
    }

}

void push() {
    int ans = 0;

    std::cout << "\nTop: [" << top << "]\n";
    std::cout << "\n- Insert a word to push: ";

    std::string word;
    std::cin >> word;

    std::cout << "[1] to push [2] cancel\n=> ";
    std::cin >> ans;

    if(ans==1){   
        pilha[top] = word;
        std::cout << word << " pushed\n";
        std::cout << " pilha[" << top << "] = '" << pilha[top] << "'\n";
        top ++;
    } 

}

std::string peek(){
    
    return pilha[top];

}

bool isFully(){
    // somatório de quantos index tem valor = "" - vazio
    int fully = 0;

    for(int i=0; i<=n; i++){
        if(pilha[i] != ""){
            fully ++;
        }
    }

    // se o somatório for igual a quantidade total do vetor, ele está vazio
    if (fully > n){
        return true;
    } else return false;
}

bool isEmpity(){

    // somatório de quantos index tem valor = "" - vazio
    int empity = 0;

    for(int i=0; i<=n; i++){
        if(pilha[i] == "" || pilha[i] == " "){
            empity ++;
        }
    }

    // se o somatório for igual a quantidade total do vetor, ele está vazio
    if (empity == n){
        return true;
    } else return false;

}

void printStack(bool empity){
    
    std::cout << "===========STACK===========\n";

    if(empity == true){
        std::cout << "Stack is empity.\n";
    } else{
        for (int i=1; i<=n; i++){
            if(i==1){
                std::cout<< "Stack: [  " << pilha[i] << " | ";
            } else if(i==n){
                std::cout << " " << pilha[i] << " ]";
            } else std::cout<< " " << pilha[i] << " | ";
        }
    }
    
    std::cout << "\n- stack top index: " << top << "\n";
    std::cout << "\n===========================\n";
}

int main() {    
    
    int mode = 0;
    std::cout << "Stack Data Structure." << std::endl;

    do{ 
        
        // extrai os valores das funções uma única vez a cada ciclo do programa
        bool fully = isFully();
        bool empity = isEmpity();

        std::cout << "STACK DATA\n";

        printStack(empity);

        std::cout << "\n\nSELECT A MODE\n[1] Push element\n[2] Pop element\n[3] Peek\n[4] isFully\n[5] isEmpity\n=> ";

        std::cin >> mode;

        switch (mode) {
        case 1:
            if(fully==true){
                std::cout << "Cannot push more elements. The stack is full.\n";
            } else push();

            break;
        case 2:
            pop();
            break;
        case 3:
            std::cout << "peek: " << peek() << "\n";
            break;
        case 4:
            if(isFully()==true){
                std::cout << "This stack is fully.\n";
            } else if (isFully==false) {
                std::cout << "It's not fully.\n";
            } 
            break;
        case 5:
            if(isEmpity()==true){
                std::cout << "This stack is empity\n";
            } else if(isEmpity()==false){
                std::cout << "It's not empity.\n";
            } else std::cout << "error: isEmpity()";
            break;
        }

    } while (true);

    return 0;

}


