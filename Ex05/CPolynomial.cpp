#include<iostream>
#include"CPolynomial.h"
#include<list>
#include<vector>
#include <cassert>
#include<string>
#include<fstream>
using namespace std;


CPolynomial::CPolynomial(){

}

CPolynomial::CPolynomial(string file){

ReadFromFile(file);



}


CPolynomial::CPolynomial(double *cof,double *deg,int n){


    for(int i=0;i<n;i++)
    {
        m_Polynomial[deg[i]]+=cof[i];
    }

//    map<int,double>::iterator it;

//        for(it=m_Polynomial.begin();it!=m_Polynomial.end();it++)
//            cout<<(*it).second<<"x"<<(*it).first<<endl;


}
CPolynomial::CPolynomial(vector<double> cof, vector<double> deg){


}


CPolynomial::~CPolynomial(){

m_Polynomial.clear();


}



CPolynomial CPolynomial::operator+(CPolynomial &right){

    cout<<"加法：";
    CPolynomial p;
    p.m_Polynomial=m_Polynomial;
    map<int,double>::iterator i;
    for(i=right.m_Polynomial.begin();i!=right.m_Polynomial.end();i++)
    {
        int deg;
        double cof;
        deg=(*i).first;
        cof=(*i).second;
        m_Polynomial[deg]+=cof;
    }
    // map<int,double>::iterator it;

    //         for(it=m_Polynomial.begin();it!=m_Polynomial.end();it++)
    //             cout<<(*it).second<<"x"<<(*it).first<<endl;
    return p;

}

CPolynomial CPolynomial::operator-(CPolynomial &right){

    cout<<"减法：";
    CPolynomial p;
    p.m_Polynomial=m_Polynomial;
    map<int,double>::iterator i;
    for(i=right.m_Polynomial.begin();i!=right.m_Polynomial.end();i++)
    {
        int deg;
        double cof;
        deg=(*i).first;
        cof=(*i).second;
        m_Polynomial[deg]-=cof;
    }
//    map<int,double>::iterator it;

//    for(it=m_Polynomial.begin();it!=m_Polynomial.end();it++)
//        cout<<(*it).second<<"x"<<(*it).first<<endl;

    return p;

}

CPolynomial CPolynomial::operator*(CPolynomial &right){

    cout<<"乘法：";
    CPolynomial p;
    // p.m_Polynomial=m_Polynomial;
    map<int,double>::iterator r;
    map<int,double>::iterator l;

    for(r=right.m_Polynomial.begin();r!=right.m_Polynomial.end();r++){
        for (l=m_Polynomial.begin(); l!= m_Polynomial.end();l++) {
            int deg;
            double cof;
            deg=(*r).first+(*l).first;
            cof=(*r).second*(*l).second;
            p.m_Polynomial[deg]+=cof;
        }
    }
//    map<int,double>::iterator it;

//    for(it=p.m_Polynomial.begin();it!=p.m_Polynomial.end();it++)
//        cout<<(*it).second<<"x"<<(*it).first<<endl;
    return p;

}


CPolynomial CPolynomial::operator =( CPolynomial *right )
    {
        CPolynomial p;
        p.m_Polynomial = right->m_Polynomial;
        return p;
    }

void CPolynomial::Print(){

    map<int,double>::iterator j;
    for (j= m_Polynomial.begin(); j != m_Polynomial.end(); j++) {


        if(j==m_Polynomial.begin())
        {

            if((*j).first==0){

                cout<<(*j).second;

            }
            else if((*j).first==1){

                cout<<(*j).second<<"x";

            }
            else{
                cout<<(*j).second<<"x^"<<(*j).first;
            }

        }
        else {


            if((*j).first==0)
            {

                cout<<"+"<<(*j).second;

            }
            else if((*j).first==1)
            {

                if((*j).second==1){

                    cout<<"+x";

                }
                else if((*j).second>0){

                    cout<<"+"<<(*j).second<<"x";

                }
                else{
                    cout<<(*j).second<<"x";
                }

            }
            else
            {

                if((*j).second==1){

                    cout<<"+x^"<<(*j).first;

                }
                else if((*j).second>0){

                    cout<<"+"<<(*j).second<<"x^"<<(*j).first;

                }
                else{
                    cout<<(*j).second<<"x^"<<(*j).first;
                }


            }



        }

    }
    cout<<endl;

}


void CPolynomial::ReadFromFile(string file){


    fstream infile;//open as a input/output function
    infile.open(file);
    assert(infile.is_open());    //失败,则输出错误消息,并终止程序运行
    string str;
    infile >> str;
    //cout << str << endl;
    infile >> str;
    //cout << str << endl;


    int deg;
    double cof;
    while(infile>>deg>>cof){
        m_Polynomial[deg]+=cof;
        cout<<m_Polynomial[deg]<<"x"<<deg<<endl;
    }

    //m_Polynomial.push_back(t);
    infile.close();
    cout<<"数据输入成功"<<endl;

    //    map<int,double>::iterator it;

    //    for(it=m_Polynomial.begin();it!=m_Polynomial.end();it++)
    //        cout<<(*it).second<<"x"<<(*it).first<<endl;


}


