#include <iostream>
#include <random>
#include "Player.h"

int main() {
    using size = std::size_t;
    constexpr size N = 48, m = 8;
    constexpr size n = N / m;
    Player player[m][n];
    double sum[m]={};

    for(size i=0;i<m;i++){
        for(size j=0;j<n;j++){
            double x=(10000/6.0*j)+((double)std::rand()/RAND_MAX)*(10000/6.0);
            /*
            double x;
            std::cin>>x;
             */
            player[i][j]=x;
            sum[i]+=x;
        }
    }
    bool flag=true;
    while(flag){
        flag=false;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                for (auto &k : player) {
                    if(k[i]> k[j]){
                        if(sum[i]- k[i]>sum[j]- k[j]){
                            double x=k[i]-k[j];
                            sum[i]-=x;
                            sum[j]+=x;
                            std::swap(k[i],k[j]);
                            flag=true;
                        }
                    }
                    else if(k[i]< k[j]){
                        if(sum[i]- k[i]<sum[j]- k[j]){
                            double x=k[i]-k[j];
                            sum[i]-=x;
                            sum[j]+=x;
                            std::swap(k[i],k[j]);
                            flag=true;
                        }
                    }
                    else continue;
                }
            }
        }
    }
    for (int i=0;i<m;i++) {
        for (int j=0;j<n;j++) {
            std::cout<< player[i][j] << '\t';
        }
        std::cout<<" || "<<sum[i];
        std::cout<<std::endl;
    }
}