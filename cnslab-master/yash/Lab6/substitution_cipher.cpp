#include <bits/stdc++.h>
using namespace std;
string caesar_encrypt(string s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]<'a'||s[i]>'z'){continue;}
		int val=s[i]-'a';
		val+=3;
		val=val%26;
		s[i]='A'+val;
	}
	return s;
}
string caesar_decrypt(string s)
{
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]<'A'||s[i]>'Z'){continue;}
		int val=s[i]-'A';
		val-=3;
		if(val<0)val+=26;
		val=val%26;
		s[i]='a'+val;
	}
	return s;
}
void shuffle(char s[])
{
	int temp='A'+3;
	for (int i = 0; i < 26; ++i,temp++)
	{
		
		if(temp>'Z')temp-=26;
		s[i]=temp;
	}
	for (int i = 0; i < 26; ++i)
	{
		int r=rand()%26;
		swap(s[i],s[r]);
	}
	cout<<"shuffle_array is :\n";
	for (int i = 0; i < 26; ++i)
	{
		cout<<s[i]<<" ";
	}
	cout<<endl;
}
string monoalphabetic_encrypt(string s,char shuffle_array[])
{
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]<'a'||s[i]>'z'){continue;}
		int val=s[i]-'a';		
		s[i]=shuffle_array[val];
	}
	return s;
}
string monoalphabetic_decrypt(string s,char shuffle_array[])
{
	for (int i = 0; i < s.length(); ++i)
	{
		if(s[i]<'A'||s[i]>'Z'){continue;}
		int j;
		for (j = 0; j < 26; ++j)
		{
			if(shuffle_array[j]==s[i])break;
			/* code */
		}
		int val='a'+j;		
		s[i]=val;
	}
	return s;
}


int mapper[26][26];
void mapping()
{
	for(int i=0; i<26; i++)
	{
		for(int j=0; j<26; j++)
		{
			mapper[i][j] = i+j;
		}
	}
}
string keygen(int s)
{
	int t;
	string key = "";
	for(int i=0; i<s; i++)
	{
		t = rand()%26;
		t = t + 'a';
		key = key + (char)t;
	}
	return key;
}
string polyalphabetic_encrypt(string plain, string key)
{
	int l = plain.length();
	int x, y, z;
	string answer = "";
	for(int i=0; i<l; i++)
	{
		if(plain.at(i)==' '){answer+=" ";continue;}
		x = plain.at(i) - 'a';
		y = key.at(i) - 'a';
		z = mapper[x][y] + 'A';
		answer = answer + (char)z;
	}
	return answer;
}
string polyalphabetic_decrypt(string cipher, string key)
{
	string answer = "";
	int l = cipher.length();
	int x, y, z;
	for(int i=0; i<l; i++)
	{
		x = key.at(i) - 'a';
		y = cipher.at(i) - 'A';
		if(cipher.at(i)==' '){answer+=" ";continue;}
		for(int j=0; j<26; j++)
		{
			if(mapper[x][j] == y)
			{
				z = j + 'a';
				answer = answer + (char)z;
				break;
			}
		}
	}
	return answer;	
}
int main()
{
	cout<<"Substitution cipher--- caesar technique\n";
	cout<<"---------------------------------------\n";
	cout<<"Enter plain text:\n";
	string s;
	getline(cin,s);
	string encrypted_string=caesar_encrypt(s);
	cout<<"Encrypted string:\n";
	cout<<encrypted_string<<endl;
	string decrypted_string=caesar_decrypt(encrypted_string);
	cout<<"Decrypted string:\n";
	cout<<decrypted_string<<endl;


	 cout<<"Substitution cipher--- monoalphabetic technique\n";
	 cout<<"-----------------------------------------------\n";
	 cout<<"Enter plain text:\n";
	 getline(cin,s);
	 char shuffle_array[26];
	 shuffle(shuffle_array);
	 encrypted_string=monoalphabetic_encrypt(s,shuffle_array);
	cout<<"Encrypted string:\n";
	cout<<encrypted_string<<endl;
	decrypted_string=monoalphabetic_decrypt(encrypted_string,shuffle_array);
	cout<<"Decrypted string:\n";
	cout<<decrypted_string<<endl;

	cout<<"Substitution cipher--- polyalphabetic technique\n";
	 cout<<"-----------------------------------------------\n";
	 cout<<"Enter plain text:\n";
	 getline(cin,s);
	 mapping();
	 string key = keygen(s.length());
	cout<<"key is "<<key<<endl;
	encrypted_string=polyalphabetic_encrypt(s, key);
	cout<<"Encrypted string:\n";
	cout<<encrypted_string<<endl;
	decrypted_string=polyalphabetic_decrypt(encrypted_string,key);
	cout<<"Decrypted string:\n";
	cout<<decrypted_string<<endl;
}