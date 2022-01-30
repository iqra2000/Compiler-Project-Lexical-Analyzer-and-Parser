#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int length(string arr[]){
    return sizeof(arr)/sizeof(arr[0]);
}
int parse(string v,string alltokens){
	//int found = alltokens.find(validStatements[i]);
	int found=alltokens.find(v);
	cout << "Parsing tokens : "<< v <<endl;
	if(found!=string::npos){	
	cout << "tokens parsed : Statment is correct"  << endl;
	return 0;
		}
	else{
	cout<< "tokens parsed : Statment is InCorrect"  << endl;
	return 1;
	}
	
}
int main()
{
    fstream file;
    string validStatements[] = {"<PreProcessor><Special Character><Keyword><Special Character>", "<Comment><String>","<Datatype><Identifier><Operator><Integer><Delimeter>","<Datatype><Identifier><Operator><Float><Delimeter>","<Datatype><Identifier><Operator><String><Delimeter>","<Keyword><Delimeter><Identifier><Operator><Integer><Delimeter>","<Delimeter><Keyword><Special Character><String><Special Character><Delimeter>","<Keyword><Delimeter><Delimeter>","<Keyword><Delimeter><Identifier><Operator><Float><Delimeter>","<Delimeter><Keyword><Special Character><String><Special Character><Delimeter><Delimeter>","<Keyword><Special Character><Special Character>","<Keyword><Special Character><String><Special Character><Delimeter><Delimeter>"};
    file.open("Tokens.txt", ios::in);
    string token;
    if (file.is_open())
    {
        string token,alltokens="";
        int count=0;
        cout<<"Reading tokens line by line"<<endl;;
        while(getline(file,token)){
        	alltokens=alltokens+token;
		}
		int len = length(validStatements);
		int b=0;
		for(int i=0; i<=len+10; i++){
			int a = parse(validStatements[i],alltokens);
			cout<< endl;
			b=b+a;
			
		}
		
		cout << "Parsing done"<<endl;
        if(b>0){
        	cout<<"Errors Detected by Parsing Tokens: "<<b<<endl;
		}
		else
		cout<<"No errors detected"<<endl;      
    }
    else
        cout << "File Could not be opened";
}
