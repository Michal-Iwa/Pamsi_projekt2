#include "Ranking.h"

Ranking::Ranking() {
    size=SIZE;
    baza = new char*[size];
    for(auto i=0; i < size; i++){
        baza[i]= new char[200];
    }
    title=new char*[size];
    for(auto i=0;i<size;i++){
        title[i]= new char[200];
    }
    title_size=new int[size];
    rating=new double[size*sizeof(double)];
    count=new double[size*sizeof(double)];
}
void Ranking::read_file() const {
    std::fstream file;
    file.open("projekt2_dane.csv", std::ios::in);
    if(!file.good()){
        std::clog<<"Error: couldn't open file"<<std::endl;
        file.close();
        exit(0);
    }
    else if(file.good()){
        file.seekg( 0,std::ios::beg);
        long long int j,k,wer,w,coma,z;
        char* fill;
        char* help;
        char* help1;
        bool x;
        fill= new char[13];
        help= new char[4];
        help1= new char[10];
        for(auto i=0; i < size; i++){
            j=0;
            k=0;
            if(i==0) {
                while (k<13){
                    file >> fill[k];
                    k++;
                }
            }
            x=true;
            do{
                coma=0;
                z=0;
                file>>baza[i][j];
                j=j+1;
                if(baza[i][j-2]=='.' && baza[i][j-1]=='0'){
                    if(baza[i][j-5]==',') wer=4;
                    else wer=3;
                    w=wer;
                    for(auto l=0; l < wer; l++){
                        help[l]=baza[i][j-w];
                        w--;
                    }
                    rating[i]=atof(help);
                    x=false;
                    count[i]=i;
                    for(auto l=0; l < j - (wer + 1); l++) {
                        if(coma>0){
                            title[i][z]=baza[i][l];
                            z++;
                        }
                        if (baza[i][l] == ',') {
                            coma++;
                        }
                    }
                    title_size[i]=z;
                }
            }while(x);
        }
        delete[]help;
        delete[]help1;
        delete[]fill;
        for(auto i =size-1;i>=0;i--){
            delete [] baza[i];
        }
        delete []baza;
        file.close();
    }
}
void Ranking::quicksort(long long int left, long long int right){
    char tmp;
    double temp;
    long long int tp;
    long long int i = left, j = right;
    double pivot = rating[(left + right) / 2];
    while (i <= j){
        while (rating[j] < pivot) j--;
        while (rating[i] > pivot) i++;
        if (i <= j){
            temp = rating[i];
            rating[i] = rating[j];
            rating[j] = temp;
            for(auto k=0; k < longer(i, j); k++){
                tmp=title[i][k];
                title[i][k]=title[j][k];
                title[j][k]=tmp;
            }
            tp=title_size[i];
            title_size[i]=title_size[j];
            title_size[j]=tp;
            i++;
            j--;
        }
    }
    if (left < j) quicksort(left, j);
    if (i < right) quicksort(i, right);
}


Ranking::~Ranking() {
    delete []count;
    delete []rating;
    for(auto i =199; i >= 0; i--){
        delete [] title[i];
    }
    delete []title;
    delete []title_size;
}

long long unsigned int Ranking::longer(long long int i, long long int j) {
    if(strlen(title[i])>strlen(title[j])) return strlen(title[i]);
    else return strlen(title[j]);
}

