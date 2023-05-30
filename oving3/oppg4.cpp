//
// Created by hassa on 26.08.2022.
//
#include<iostream>
#include<string>
using namespace std;

int main(){

    string word1, word2, word3, sentence;

    cout << "Write three words end with pressing enter each time" << endl;
    cin >> word1;
    cin >> word2;
    cin >> word3;

    sentence = word1 + " " + word2 + " " + word3  + ".";
    cout << sentence << endl;

    cout << "Length of first word: " << word1.length() << endl;
    cout << "Length of second word: " << word2.length() << endl;
    cout << "Length of third word: " << word3.length() << endl;
    cout << "Length of sentence: " << sentence.length() << endl;

    string sentence2 = sentence;
    for(int i =10; i<=12; i++){
        if(sentence2[i]){
            sentence2[i] = 'x';
        }
    }
    cout <<"sentence: "<< sentence << endl;
    cout <<"sentence2: "<< sentence2 << endl;

    string sentence_start = "";
    for(int i = 0; i<5; i++){
        if(sentence[i]){
            sentence_start += (sentence2[i]);
        }
    }

    cout <<"sentence: "<<sentence<<endl;
    cout <<"sentence_start: " << sentence_start<<endl;
    cout << "Does sentence contain Hallo? " << (sentence.find("Hallo") != std::string::npos) << endl;
    string find_er = "er";
    int count = 0;
    size_t nPos = sentence.find(find_er, 0);
    while(nPos != string::npos)
    {
        count++;
        nPos = sentence.find(find_er, nPos + 1);
    }
    cout << "How many times does er appear " << count << endl;

    return 0;
}