#include <iostream>
#include <vector>
using namespace std;

//EXERCICE 1
template <typename T>

T multiply( T n1, int n2){
    T res;
    res = n1 * n2;
    return res;
}

//EXERCICE 2

/* Write a function template named powiter that allows the user to calculate
an, where the first parameter a could be of any type and the second parameter
n is an integer. The function should be not be recursive and should return the
same type as the first parameter.
Write a function template powrec which does the same thing in a recursive
way */

template <typename T>
T powiter(T a, int n){
//we will store the answer in this variable
T answer;
answer = 1;
while(n>0){
   
    if(n%2==1){
        answer = answer*a; //car answer va prendre que les 3 a la puissances qui ont l'indexe de bit 1
        //exemple 3^13 = 3 ^ (1101)in base_2 = (1 * 3^8) * (1 * 3^4) * (0 * 3^2) * (1 * 3^1)
        a = a*a;
    }

    else
        a = a*a;

    n = n/2;  //exemple 3^13 = 3 ^ (1101)in base_2 = (1 * 3^8) * (1 * 3^4) * (0 * 3^2) * (1 * 3^1) 
    // n etait 8 puis 4 puis 2 puis 1
    }
    return answer;
}

template <typename T>
T powrec(T a, int n){
    if(n==0)
        return 1;
    else
        if(n%2 == 1)
            return a * powrec(a, n/2) * powrec(a, n/2);
        else
            return powrec(a, (n-1)/2) * powrec(a, (n-1)/2);
}

template <typename T>

vector < vector < T > > initi_v(int n, int m, T iniv) {
vector < T > t(n, iniv);
vector < vector < T >> arr(m, t);
  return arr;
}

template <typename T>
void matprint(vector<vector<T>> a){
    if(a.empty())
        cout<<"empty matrix"; 
    else{
        cout<<"Printing the matrix "<<endl;
        for(int i=0;i<a.size();i++){
            for(int j=0;j<a[0].size();j++){
                cout<<" "<<a[i][j];
            }
        cout<<endl;
        }
    }
}

template <typename T>
vector<vector<T>> matmul(vector<vector<T>> a, vector<vector<T>> b, T initi_vAL){ //en fait je voulais faire initi_vAL=0, mais j'utilise template donc initi_vAl depend de T
    if(a[0].size()!=b.size()){
        cout<<"Incompatible dimensions. \n";
        exit(0);
    }
    else{
    vector<T> lines_res(a.size(), initi_vAL);
    vector<vector<T>> res(b[0].size(),lines_res);
    int row_i, column_j, sum_ij;
    for(row_i=0; row_i<a.size()/*number of rows in a*/; row_i++){

        for(column_j=0; column_j<b[0].size()/*number of columns in b*/;column_j++){ //because a is n*n
            res[row_i][column_j]=0;
            for(sum_ij=0; sum_ij<a[0].size()/*number of columns in a*/;sum_ij++){
                res[row_i][column_j]+= a[row_i][sum_ij]*b[sum_ij][column_j];
            }
        }
    }
    return res;
    }
}

template <typename T>
vector<vector<T>> matpownaive(vector<vector<T>> a, int k, T initi_vAL){
    int i=0;
    vector<vector<T>> ak=a;
    while(i<k-1){
        ak = matmul(a, ak, initi_vAL);
        i++;
    }
    return ak;
    
}

template <typename T>
vector<vector<T>> matpow(vector<vector<T>> a, int k, T initi_vAL){
    int i=0;
    vector<vector<T>> ak=initi_v(a.size(),a.size(),0);
    for(int i=0; i<a.size(); i++){
        for(int j=0;j<a.size();j++)
            if(i==j)
                ak[i][i]=1;
            else
                continue;
    }
    matprint(ak);
    while(k!=0){
        if(k%2==1){
            ak = matmul(ak,a,0);
        }
        a=matmul(a,a,0);
        k=k/2;
    }
    return ak;
}





























int main()
{
    cout << "EXERCICE 1 \n";
    cout << multiply(2,3) << "\n";
    cout << multiply<double>(1.2,3) << "\n";
    cout << "------------------------------------ \n";



    cout << "EXERCICE 2 \n";
    double res1;
    double res2;
    cout << "Algorithme de binary exponention via une fonction iterative: \n";
    res1 = powiter(2, 3);
    cout<<res1<<endl;
    res1 = powiter(1.2, 3);
    cout<<res1<<endl;
    cout << "Algorithme de binary exponention via une fonction recursive: \n";
    res2 = powiter(2, 3);
    cout<<res2<<endl;
    res2 = powiter(1.2, 3);
    cout<<res2<<endl;
    cout << "------------------------------------ \n";






    cout << "EXERCICE 3 \n";
    vector<vector<int>> a {{1,1,1}, {2,2,2},{3,3,1}};

    cout<<"~~matrix A"<<endl;
    matprint(a);

    //cout<<"the size is: "<<a.size();
    vector<vector<int>> ak;
    cout<<"~~Product of matrices via matpow(): A^k "<<endl;
    ak = matpow<int>(a, 5, 0);
    matprint(ak);

    vector<vector<int>> ak_naive;
    cout<<"~~Product of matrices via matpownaive(): A^k "<<endl;
    ak_naive = matpownaive<int>(a, 5, 0);
    matprint(ak_naive);
    cout << "------------------------------------ \n";
    



    return 0;
}
