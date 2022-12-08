#include <bits/stdc++.h>
using namespace std;
  
string encrypt(string text, int s)
{
    string result = "";
  
    for (int i=0;i<text.length();i++)
    {
        result += char((int(text[i]-'A')+s)%26) +65; 
    }
  
    return result;
}

string decrypt(string cipher,int s){
    string result = "";
    for(int i=0;i<cipher.size();i++){
        result += char((int(cipher[i]-s-65)+26)%26 +65);
    }
    return result;
}
  
int main()
{

    while(1){
        cout<<"\nChoose\n 1.Encryption using Caesar Cipher \n2.Decryption using Caesar Cipher :- \n ";
        int choice;
        cin>>choice;    
        
        string text="DefaultText";
        int s = 3;
        if(choice==1){
            cout<<"Enter the plain text:-";
            cin>>text;
            cout<<"Enter the Key:-";
            cin>>s;
            cout<<"The Encrypted text is:- "<<encrypt(text,s);
            cout<<"\n\n";
        }else if(choice==2){ 
            cout<<"Enter the cipher text:-";
            cin>>text;
            cout<<"Enter the Key:-";
            cin>>s;
            cout<<"The Decrypted text is:-"<<decrypt(text,s);
            cout<<"\n\n";
        }else{
            cout<<"Program Ended.\n";
            break;
        }

    }
    return 0;
}
