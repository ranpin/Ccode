#include<string>
#include<iostream>
using namespace std;
int main(){
    string s1 = "",s2,s3 = "bye";
    s1.append("good moring");
    s2 = s1;
    int i = s2.find("moring");
    s2.replace(i,s2.length()-1,s3);
    cout<<"s1:"<<s1<<endl;
    cout<<"s2:"<<s2<<endl;
}
    