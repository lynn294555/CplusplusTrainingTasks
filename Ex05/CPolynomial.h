#ifndef HEADER_CPOLYNOMIAL
#define HEADER_CPOLYNOMIAL
#include<list>
#include<vector>
#include<iostream>
#include<map>
using namespace std;

//typedef struct Node
//{

//    double  cof;      // coefficient 代数式的单项式中的数字因数叫做它的系数(coefficient).单项式中所有字母的指数的和叫做它的次数.如abc的系数是1,次数是3。多项式中最高次幂项的因数叫做这个多项式的系数。单项数中的的数字因数为它的系数。
//int     deg;      // degree   次数

//} Node;               // the node of polynomial(多项式)


class CPolynomial
{

private:
    map<int,double> m_Polynomial;

public:
CPolynomial();
CPolynomial(string file);                     // initialization using file  初始化使用文件
CPolynomial(double *cof,double *deg,int n);
CPolynomial(vector<double> cof, vector<double> deg);
virtual ~CPolynomial();

    // overload
CPolynomial operator+( CPolynomial &right );//Overload operator +
CPolynomial operator-( CPolynomial &right );//Overload operator -
CPolynomial operator*( CPolynomial &right );//Overload operator *
CPolynomial operator=( CPolynomial *right );//Overload operator =

void Print();
private:
void ReadFromFile(string file);
 //   void AddOneTerm(map<);   // add one term into m_Polynomial只要不是引用都会发生拷贝。

};


#endif
