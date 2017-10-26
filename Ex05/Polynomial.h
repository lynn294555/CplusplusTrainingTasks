#if !defined _POLYNOMIAL_H_
#define _POLYNOMIAL_H_
#include<iostream>

#include<map>
#include<vector>


using namespace std;
//typedef struct Node
//{
//    double  cof;      // coefficient
//        int     deg;      // degree
//} Node;               // the node of polynomial

class CPolynomial
{
private:
    map<int,double> m_Polynomial;
public:
    CPolynomial();
    CPolynomial(string file);                     // initialization using file
    CPolynomial(double *cof,double *deg,int n);
    CPolynomial(const vector<double> cof,const  vector<double>  deg);
      virtual ~CPolynomial();

    // overload
//        CPolynomial operator +(CPolynomial &right );	//Overload operator +
//        CPolynomial operator -(CPolynomial &right );	//Overload operator -
//        CPolynomial operator *(CPolynomial &right );	//Overload operator *
//       CPolynomial operator =(CPolynomial *right );	//Overload operator =

        //void Print () ;
private:
        void ReadFromFile(string file);
        //void AddOneTerm(m_Polynomial);   // add one term into m_Polynomial
};
#endif

