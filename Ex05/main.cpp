#include "CPolynomial.h"

int main()
{

CPolynomial p1("P1.txt");
CPolynomial p2("P2.txt");
CPolynomial p3("P3.txt");
CPolynomial p4("P4.txt");
CPolynomial p5("P5.txt");
CPolynomial p6("P6.txt");
p1.Print();
p2.Print();
p3.Print();
p4.Print();
p5.Print();
p6.Print();

CPolynomial p7;
p7=p1+p2;
 p7.Print();

CPolynomial p8;
p8=p1-p2;
p8.Print();

CPolynomial p9;
p9=p3*p4;

p9.Print();


double cof[] = {
1,2,3
};
double deg[] = {
2,2,4
};
CPolynomial p10(cof,deg,3);
p10.Print();

}
