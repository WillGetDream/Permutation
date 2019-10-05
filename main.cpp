#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

float logPnm(int,int);
float lognPm(int n,int m);
float lognCmR(int n,int m);
float lognCm(int n,int m);

int main() {


    cout<<"P -> Permutation(Order Matters)"<<endl;
    cout<<"C -> Combination(Order does not matter)"<<endl;
    cout<<"Rep -> with replacement"<<endl;
    cout<<"no Rep -> no replacement"<<endl;
    cout<<"N -> Number of total elements"<<endl;
    cout<<"M -> Number of elements to take from the total"<<endl<<endl;
    cout<<" N M P Rep P no Rep C Rep C no Rep"<<endl;
    cout<<" N^M N!/(N-M)! (N+M-1)!/((N-1)!M!) N!/((N-M)!M!)"<<endl<<endl;

    //Declare Variables
    int n,m;
    float nPm;
    nPm=exp(1);
    //header
    cout<<setw(12)<<"N"<<setw(12)
        <<"M"<<setw(16)<<"Rep P"<<setw(16)<<"no Rep"<<setw(12)<<"Rep C"<<setw(14)<<"C no Rep"<<endl;

    for(int n=2;n<=26;n++){
        for(int m=0;m<=n;m++){
            cout<<setw(12)<<n<<
            setw(12) <<m<<
            setw(14)<<exp(logPnm(n,m))<<
            setw(14)<<exp(lognPm(n,m))<<
            setw(14)<<exp(lognCmR(n,m))<<
            setw(14)<<exp(lognCm(n,m))<<
            endl;

        }
    }



    return 0;
}

float logPnm(int n,int m){
    return static_cast<float>(m*log(n));


};

float lognPm(int n,int m){
    float sum=0;
    for(int i=n-m+1;i<=n;i++){
        sum+= static_cast<float>(log(i));
    }

    return sum;

};



float lognCmR(int n,int m){
    float sumn=0.0f,summ=0.0f;
    for(int i=n;i<=n+m-1;i++){
        sumn+= static_cast<float>(log(i));
    }
    for(int i=1;i<=m;i++){
        summ+= static_cast<float>(log(i));
    }
    return sumn-summ;

};

float lognCm(int n,int m){
    float sumn=0.0f,summ=0.0f;
    for(int i=n-m+1;i<=n;i++){
        sumn+= static_cast<float>(log(i));
    }
    for(int i=1;i<=m;i++){
        summ+= static_cast<float>(log(i));
    }
    return sumn-summ;


};