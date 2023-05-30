//
// Created by hassa on 23.08.2022.
//
//
//compilation errors
int main(){
    int a = 5;
    //int &b;  b has to be initiated or not &
    int *b;
    int *c;
    //c = &b; remove &, & will make a pointer point to a pointer
    c = b;
    a = *b + *c;
    //&b = 2; cannot be set it only returns a value
    *b = 2;

    return 0;
}