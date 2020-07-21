
#include <iostream>
using namespace std;
//my realization of c++ string class
class String
{
  private:
    int length;
    char* str;
  public:
    String()
    {
        str = nullptr;
    }
    String(const char* str)
    {
        length = strlen(str);
        this->str = new char[length + 1];
        
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }
    String(const char* str, int n)
    {
        this->str = new char[n + 1];
        for (int i = 0; i < n; i++)
        {
            this->str[i] = str[0];
        }
        this->str[n] = '\0';
    }
    void Print()
    {
        cout << str << endl;
    }
    ~String()
    {
        delete[] this->str;
    }
};

int main()
{
    char s1[256], s2[2];
    int n;
    cout << "//////////////" << endl << "Enter the string to demonstrate the first conctructor" << endl;
    cin.getline(s1,256);
    String str1(s1);
    str1.Print();
    cout << "//////////////" << endl << "Enter number and then character to demonstrate the second conctructor" << endl;
    cin >> n;
    cin.get();
    cin >> s2;
    String str2(s2, n);
    str2.Print();
    cout << "//////////////" << endl;
    return 0;
}