#include <iostream>

#include "VECTOR.H"

using namespace std;

int main()
{
    Vector<string> v;

    v.SetElement("Thing");
    v.SetElement("Thingo");
    v.SetElement("Thingy");

    for(int i = 0; i < v.GetElementAmount(); i++)
    {
        cout << v[i] << endl;
    }

    cout << v.GetElementAmount() << endl;
    cout << v.GetSize() << endl;

    v.ShrinkVector();

    cout << v.GetElementAmount() << endl;
    cout << v.GetSize() << endl;

    for(int i = 0; i < 4; i++)
    {
        cout << v[i] << endl;
    }

    return 0;
}
