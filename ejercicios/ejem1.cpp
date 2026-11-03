#include <iostream>
using namespace std;

int main() {
    double a, b, c, d, e, f, resul=0;

    cout<<"Digite el valor de a:"; cin>>a;
    cout<<"Digite el valor de b:"; cin>>b;
    cout<<"Digite el valor de c:"; cin>>c;
    cout<<"Digite el valor de d:"; cin>>d;
    cout<<"Digite el valor de e:"; cin>>e;
    cout<<"Digite el valor de f:"; cin>>f;

    resul= (a+(b/c))/(d+(e/f));

    cout<<"Su resultado es:"<<resul<<endl;

    return 0;
}

#include <iostream>
using namespace std;
int main() {
    double a,b,c,d,resul=0;
    cout<<"Digite el valor de a: "; cin>> a;
    cout<<"Digite el valor de b: "; cin>> b;
    cout<<"Digite el valor de c: "; cin>> c;
    cout<<"Digite el valor de d: "; cin>> d;

    resul= a+(b)/(c-d);

    cout<<"Su resultado es: "<<resul<<endl;

    return 0;
}