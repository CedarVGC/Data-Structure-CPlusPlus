//
// Created by Administrator on 2020/7/12.
//

#ifndef DATA_STRUCTURE_C_SSTRING_H
#define DATA_STRUCTURE_C_SSTRING_H
#include <iostream>
#include <string>
int Index(std::string S,std::string T){
    int i=0,j=0;
    while(i<S.length()&&j<T.length()){
        if(S[i]==T[j]){
            i++;
            j++;
        } else{
            i=i-j+1;
            j=0;
        }
    }
    if(j>=T.length()){
        return i-T.length();
    } else{
        return -1;
    }
}

void get_next(std::string T,int next[]){

}
#endif //DATA_STRUCTURE_C_SSTRING_H
