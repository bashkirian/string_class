
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
    
    
    bool operator == (const String& other)
    {
        if (this->length != other.length) return 0;
        else
        {
            for (int i = 0; i < this->length; i++)
            {
                if (this->str[i] != other.str[i]) break;
            }
        }
        return 1;
    }

    String& operator + (const String& other)
    {
        if (other.str == nullptr) return *this;
        else
        {
            String temp(*this);
            delete[] this->str;
            this->length = other.length + temp.length;
            this->str = new char[other.length + temp.length + 1];
            int i = 0;
            for (; i < other.length; i++)
            {
                this->str[i] = other.str[i];
            }
            for (i = other.length; i < other.length + temp.length; i++)
            {
                this->str[i] = temp.str[i-other.length];
            }
            this->str[other.length + temp.length] = '\0';
            return *this;
        }
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
    char s1[256], s2[2], s3[256], s4[256], s5[256], s6[256], s7[256], s8[256], s9[256];
    int n;
    cout << "Enter the string to demonstrate the first conctructor:" << endl;
    cin.getline(s1,256);
    String str1(s1);
    str1.Print();

    cout << endl << "Enter number and then character to demonstrate the second conctructor:" << endl;
    cin >> n;
    cin.get();
    cin >> s1;
    String str2(s1, n);
    str2.Print();

    cout << endl << "Enter string to demonstrate the copy constructor:" << endl;
    cin.get();
    cin.getline(s3, 256);
    String str(s3);
    String copy(str);
    copy.Print();

    cout << endl << "Enter 2 strings to demonstrate the = operator" << endl;
    cin.getline(s4, 256);
    cin.getline(s5, 256);
    String str4(s4);
    String str5(s5);
    str5 = str4;
    str5.Print();

    cout << endl << "Enter 2 strings to demonstrate the == operator" << endl;
    cin.getline(s6, 256);
    cin.getline(s7, 256);
    String str6(s6);
    String str7(s7);
    (str6 == str7) ? cout << "Strings are equal" : cout << "Strings are not equal";

    cout << endl << "Enter 2 strings to demonstrate the + operator (concatenation) " << endl;
    cin.getline(s8, 256);
    cin.getline(s9, 256);
    String str8(s8);
    String str9(s9);
    String temp = str9 + str8;
    temp.Print();

    return 0;
}