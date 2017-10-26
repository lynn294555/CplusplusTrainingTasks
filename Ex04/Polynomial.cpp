#include<iostream>
#include"Polynomial.h"
#include<list>
#include<vector>
#include <cassert>
#include<string>
#include<fstream>
using namespace std;

CPolynomial :: CPolynomial()
{}
CPolynomial :: CPolynomial (string file)
{
   ReadFromFile(file);

}                     // initialization using file
CPolynomial::CPolynomial(double *cof, double *deg, int n)
{

    for(int i=0;i<n;i++)
    {
        Node temp;
        temp.cof=cof[i];
        temp.deg=deg[i];
        AddOneTerm(temp);
    }

}
CPolynomial::CPolynomial(const vector<double> cof, const vector<double> deg)
{
    for(int i=0;i<cof.size();i++)
    {
        Node temp;
        temp.cof=cof[i];
        temp.deg=deg[i];
        AddOneTerm(temp);
    }
}
CPolynomial:: ~CPolynomial()
{
    m_Polynomial.clear();
}


CPolynomial CPolynomial::operator+(CPolynomial &right )
{

   CPolynomial p;
   p.m_Polynomial=m_Polynomial;
   list<Node>::iterator i;
    for(i=right.m_Polynomial.begin();i!=right.m_Polynomial.end();i++)
    {
       p.AddOneTerm(*i);
    }
    return p;

}//Overload operator +
CPolynomial CPolynomial::operator-(CPolynomial &right )
{

    CPolynomial p;
    p.m_Polynomial=m_Polynomial;
    list<Node>::iterator i;//i is a pointer
    for(i=right.m_Polynomial.begin();i!=right.m_Polynomial.end();i++)
    {
        i->cof*=-1;
        p.AddOneTerm(*i);//*i is the value of the pointer.
    }
    return p;


}//Overload operator -
CPolynomial CPolynomial::operator*( CPolynomial &right )
{
    CPolynomial p;
    //p.m_Polynomial=m_Polynomial;
   list <Node>::iterator l;
       list <Node>::iterator r;

       for(r=right.m_Polynomial.begin();r!=right.m_Polynomial.end();r++){

           for (l = m_Polynomial.begin(); l!= m_Polynomial.end(); l++) {

         Node temp;
         temp.cof=l->cof*r->cof;
         temp.deg=l->deg+r->deg;
         p.AddOneTerm(temp);
     }

    }
}//Overload operator *
CPolynomial CPolynomial::operator=(CPolynomial *right )
{
    m_Polynomial=right->m_Polynomial;
    return *this;
}//Overload operator =

void CPolynomial::Print(){

    list <Node>::iterator j;
        for (j= this->m_Polynomial.begin(); j != this->m_Polynomial.end(); j++)
        {


            if(j==m_Polynomial.begin())
            {

                if(j->deg==0){

                    cout<<j->cof;

                }
                else if(j->deg==1){

                    cout<<j->cof<<"x";

                }
                else{
                    cout<<j->cof<<"x^"<<j->deg;
                }

            }
            else {


                if(j->deg==0)
                {

                    cout<<"+"<<j->cof;

                }
                else if(j->deg==1)
                {

                    if(j->cof==1){

                        cout<<"+x";

                    }
                    else if(j->cof>0){

                        cout<<"+"<<j->cof<<"x";

                    }
                    else{
                        cout<<j->cof<<"x";
                    }

                }
                 else
                {

                    if(j->cof==1){

                        cout<<"+x^"<<j->deg;

                    }
                    else if(j->cof>0){

                        cout<<"+"<<j->cof<<"x^"<<j->deg;

                    }
                    else{
                        cout<<j->cof<<"x^"<<j->deg;
                    }


                }



            }

        }
        cout<<endl;
}

void CPolynomial::ReadFromFile(string file)
{

    fstream infile;//open as a input/output function
    infile.open(file);
    assert(infile.is_open());  //失败,则输出错误消息,并终止程序运行
    string str;
    infile >> str;
    cout << str << endl;
    infile >> str;
    cout << str << endl;

    Node t;
    while(infile >> t.deg >> t.cof)
        AddOneTerm(t);
    //m_Polynomial.push_back(t);
    infile.close();
    cout<<"数据输入成功"<<endl;

}
void CPolynomial::AddOneTerm(Node term)
{
      list <Node>::iterator i=m_Polynomial.begin();
    while(i!=m_Polynomial.end())
    {
        if(term.deg==i->deg)
        {

            double sum=i->cof+term.cof;
            if(sum!=0){

                i->cof=sum;
                //f=true;

            }
            else{

                i=m_Polynomial.erase(i);


            }
            return;

        }//what if the sum==0,this item should be  .
        else if(term.deg > i->deg)
        {

            break;

        }
        else

        {

            i++;

        }


    }
    m_Polynomial.insert(i,term);
}
