#include "grid.h"

int main(){
    grid G;
    cell C1(1,1);
    cell C2(2,2);
    cell C3(3,3);
    cell C4(3,1);
    cell C5(1,3);
    cell C6(2,4);
    cell C7(1,4);
    cell C8(2,5);
    cell C9(3,4);
    cell C10(1,5);
    G.insert(C1);
    G.insert(C2);
    G.insert(C3);
    G.insert(C4);
    G.insert(C5);
    G.insert(C6);
    G.insert(C7);
    G.insert(C8);
    G.insert(C9);
    G.insert(C10);
    std::cout << "lista celle dopo inserimento: " << endl; 
    G.print();
    G.moveRight(1,1);
    G.moveLeft(3,3);
    G.moveDown(1,3);
    G.moveUpper(3,1);
    std::cout << "lista celle dopo spostamento: " << endl; 
    G.print();
    G.remove(C10);
    std::cout << "lista celle dopo rimozione cella 1,5: " << endl; 
    G.print();
    G.removeSurrounded();
    std::cout << "lista celle dopo removeSurrounded(): " << endl; 
    G.print();
}