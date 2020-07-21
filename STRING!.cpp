
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
        length = 0;
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
        length = n;
        this->str = new char[n + 1];
        for (int i = 0; i < n; i++)
        {
            this->str[i] = str[0];
        }
        this->str[n] = '\0';
    }

    String(const String& other)
    {
        this->length = other.length;
        this->str = new char[other.length+1];
        for (int i = 0; i < this->length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
    }

    String& operator = (const String& other)
    {
        this->length = other.length;
        if (this->str != nullptr) delete[] this->str;
        this->str = new char[other.length + 1];
        for (int i = 0; i < this->length; i++)
        {
            this->str[i] = other.str[i];
        }
        this->str[length] = '\0';
        return *this;
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
    char s1[256], s2[2], s3[256], s4[256], s5[256];
    int n;
    cout << "Enter the string to demonstrate the first conctructor:" << endl;
    cin.getline(s1,256);
    String str1(s1);
    str1.Print();

    cout << endl << "Enter number and then character to demonstrate the second conctructor:" << endl;
    cin >> n;
    cin.get();
    cin >> s2;
    String str2(s2, n);
    str2.Print();

    cout << endl << "Enter string to demonstrate copy constructor:" << endl;
    cin.get();
    cin.getline(s3, 256);
    String str(s3);
    String copy(str);
    copy.Print();

    cout << endl << "Enter 2 strings to demonstrate = operator" << endl;
    cin.getline(s4, 256);
    cin.getline(s5, 256);
    String str4(s4);
    String str5(s5);
    str5 = str4;
    str5.Print();
    return 0;
}