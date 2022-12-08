#include <bits/stdc++.h>
using namespace std;


//void file()
//{
//	fstream myfile;
//	myfile.open("dictonary.txt");
//	string str,s;
//	if(!myfile.is_open())
//		cout << "Error while Opening File";
//	getline(myfile,str);
//	cout<<str<<endl;
//	while(getline(myfile,str))
//	{
//		cout<<str<<endl;
//		dict.insert(str);
//	}
//	myfile.close();
//}

set<string> dict;

int main()
{
//    file();
    dict.insert("i");
    dict.insert("am");
    dict.insert("are");
    dict.insert("assignment");
    dict.insert("complete");
    dict.insert("good");
    dict.insert("how");
    dict.insert("the");
    dict.insert("time");
    dict.insert("you");
    dict.insert("please");
    dict.insert("in");
    
    string s, org;
    cout << "Enter Cipher text" << endl;
    getline(cin, s);

    string x;

    int k = 0;

    cout << "\nCipher text is: " << s << endl << endl;
    
    string msg;
    
    org = s;
    for (int k = 0; k < 26; k++)
    {
        cout << "Keep Key as: " << k << endl;
        s = org;
        string word = "";
        int flg = 0;
        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] == ' ')
            {
                if (dict.find(word) == dict.end())
                {
                    flg = 1;
                    break;
                }
                word = "";
                continue;
            }
            int val = s[i] - 'a';
            val = (val - k + 26) % 26;
            char ch = 'a' + val;
            word += ch;
            s[i] = ch;
        }

        if (dict.find(word) == dict.end())
        {
            flg = 1;
        }
        cout << s << endl << endl;
        if (flg == 0)
        	msg = s;
    }
    cout<<endl;
    cout<<"The Message is:\n"<<msg<<endl;
    return 0;
}
