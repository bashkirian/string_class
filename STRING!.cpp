
#include <iostream>
using namespace std;

class String
{
private:
    int size;
    char str[255];
public:
    String(char str[])
    {
        size = strlen(str);
        strcpy_s(this->str, str);
    }
    String(char str[], int k)
    {
        size = k;
        for (int i = 0; i < k; i++)
        {
            this->str[i] = str[0];
        }
        this->str[k] = '\0';
    }
    void Print()
    {
        cout << str << endl;
    }
    ~String()
    {
        delete[] str;
    }
};

int main()
{
    char *string1;
    cin >> string1;
    String st1(string1);
    st1.Print();
    char string2[1];
    cin >> string2;
    String st2(string2, 5);
    st2.Print();
    return 0;
}
