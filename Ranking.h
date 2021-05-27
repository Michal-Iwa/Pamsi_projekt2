#ifndef PAMSI2_RANKING_H
#define PAMSI2_RANKING_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

#define SIZE 10

class Ranking  {
private:
    long long int size;
    char** baza;
    double* count;
    char** title;
    double* rating;
    int* title_size;
public:
    Ranking ();
    ~Ranking();
    void read_file() const;
    long long unsigned int longer(long long int i,long long int j);
    friend std::ostream & operator <<(std::ostream &Strm,const Ranking &R);
    void quicksort(long long int left, long long int right);
    void mergesort(long long int left, long long int right);
};
inline
std::ostream & operator <<(std::ostream &Strm,const Ranking &R){
    std::cout<<std::endl;
    for(int i=0; i<R.size; i++){
        std::cout<<i<<'.';
        for(int j=0;j<R.title_size[i];j++){
            std::cout<<R.title[i][j];
        }
        std::cout<<" Points: "<<R.rating[i]<<std::endl;
    }
    return Strm;
}
#endif //PAMSI2_RANKING_H
