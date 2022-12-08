#include<bits/stdc++.h>
using namespace std;
 

string generateKey(string str, string key)
{
    int x = str.size();
 
    for (int i = 0; ; i++)
    {
        if (x == i)
            i = 0;
        if (key.size() == str.size())
            break;
        key.push_back(key[i]);
    }
    return key;
}
 

string cipherText(string str, string key)
{
    string cipher_text;
 
    for (int i = 0; i < str.size(); i++)
    {
        // converting in range 0-25
        char x = (str[i] + key[i]) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
 
        cipher_text.push_back(x);
    }
    return cipher_text;
}
 
// This function decrypts the encrypted text
// and returns the original text
string originalText(string cipher_text, string key)
{
    string orig_text;
 
    for (int i = 0 ; i < cipher_text.size(); i++)
    {
        // converting in range 0-25
        char x = (cipher_text[i] - key[i] + 26) %26;
 
        // convert into alphabets(ASCII)
        x += 'A';
        orig_text.push_back(x);
    }
    return orig_text;
}
 


int main()
{
	 while(1){
        cout<<"\nChoose\n 1.Encryption using Caesar Cipher \n2.Decryption using Caesar Cipher :- \n ";
        int choice;
        cin>>choice;    
        
        string text="DefaultText";
        string s = "KEY";
        if(choice==1){
            string str;
		    string keyword;
		    cout<<"Enter plain text: ";
		    cin>>str;
		    cout<<"\nEnter Key: ";
		    cin>>keyword;
		    string key = generateKey(str, keyword);
		    cout<<"\nNew Key: "<<key<<"\n";
            cout<<"The Encrypted text is:- "<<cipherText(str, key);
            cout<<"\n\n";
        }else if(choice==2){ 
            string str;
		    string keyword;
		    cout<<"Enter plain text: ";
		    cin>>str;
		    cout<<"\nEnter Key: ";
		    cin>>keyword;
		    string key = generateKey(str, keyword);
		    cout<<"\nNew Key: "<<key<<"\n";
		    cout << "Original/Decrypted Text : "<< originalText(str, key);
            cout<<"\n\n";
        }else{
            cout<<"Program Ended.\n";
            break;
        }

    }
 
    
    return 0;
}
