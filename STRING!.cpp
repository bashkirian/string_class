
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
    String(const char *str)
    {
        length = strlen(str);
        this->str = new char[length + 1];
        
        for (int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }
        this->str[length] = '\0';
    }
    String(const char *str, int k)
    {
        length = k;
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
        delete[] this->str;
    }
};

int main()
{
    char s[256];
    cin.getline(s,256);
    String str("Hello World!");
    str.Print();
    return 0;
}