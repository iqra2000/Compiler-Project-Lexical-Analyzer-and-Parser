//https://www.geeksforgeeks.org/c-program-detect-tokens-c-program/
#include<fstream>
#include<bits/stdc++.h>
std::ofstream writeFile("Tokens.txt");
using namespace std;

int separator,processsor,delimeter,specialCh,operatorss,key_words,dataType,fun,identifier,integer,strng,floatss,total_token=0,com;

//-----------------Pre-processor Directive------------//

bool preProcessor(string token)
{
    if(token[0] == '#')
    {
        if(token[1] == 'i' && token[2] == 'n' && token[3] == 'c' && token[4] == 'l' && token[5] == 'u' && token[6] == 'd' && token[7] == 'e')
           {
           	 processsor++;
           	 return true;

       	   }
    }
    return false;

}
//------------ Whitespace ------------//

bool whitespace(string token)
{
	int i=0;
	bool test = false;
	do
	{
		if(token[i] == ' ' || token[i] == '\n'  || token[i] == '\t')
		{
			test = true;
		}
		else
		{
			test  = false;
			return test;
		}
		++i;
	}while(i < token.length());
	return test;
}


//----------------- Delimiter ------------//

bool delimeters(string token)
{
	if (token == "''" || token == "," || token == "{" || token == ";" || token == "}" || token == "." || token == "_")
	{
		delimeter++;
		return true;
	}
	return false;
}


//-----------------Special Characters------------//

bool specialCharacters(string token)
{
	if (token == "#" || token == "@" || token == "$" || token == "^" || token == "%"|| token == "&" || token == "("|| token == ")")
		{
			specialCh++;
			return true;
		}
	return false;
}

bool singleCom(std::string token)
{
	if (token[0] == '/' && token[1] == '/')
	{
		com++;
		return true;
	}
	//else if(token[0] == '#' && token[1] == '~')
		//return true;
	else
		return false;
}


//-----------------All Operators------------//

bool operators(string token)
{
    if(token.length() == 1)
    {
        if(token == "+" || token == "-" || token == "*" || token == "/" ||token == "<" || token == ">" || token == "%"|| token == "=")
        {
           		operatorss++;
           		return true;
		}
    }
    else if(token.length() == 2)
    {
        if(token[0] == '-' && (token[1] == '-' || token[1] == '='))
        {
        	operatorss++;
			return true;
		}

		else if(token[0] == '+' && (token[1] == '+' || token[1] == '='))
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '/' &&  token[1] == '=')
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '%' && token[1] == '=')
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '*' && token[1] == '=')
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '>' && (token[1] == '>' || token[1] == '='))
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '<' && (token[1] == '<' || token[1] == '='))
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '!' && token[1] == '=')
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '=' && token[1] == '=')
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '|' && token[1] == '|')
		{
        	operatorss++;
			return true;
		}
		else if(token[0] == '&' && token[1] == '&')
		{
        	operatorss++;
			return true;
		}
		else
			return false;
    }
        return false;

}
//-----------Keywords--------------//

bool keywords(string token)
{
	if(token[0] == 'l')
	{
		if(token[1] == 'o' && token[2] == 'c' && token[3] == 'a' && token[4] == 't' && token[5] == 'i' && token[6] == 'o'&& token[7] == 'n')
        {
            key_words++;
            return true;
        }

        else if(token[1] == 'i' && token[2] == 'b' && token[3] == 'r' && token[4] == 'a' && token[5] == 'r' && token[6] == 'y')
        {
            key_words++;
            return true;
        }
        return false;
	}

	else if(token[0] == '#')
    {
        if(token[1] == 'i' && token[2] == 'n' && token[3] == 'c' && token[4] == 'l' && token[5] == 'u' && token[6] == 'd' && token[7] == 'e')
           {
           	 key_words++;
           	 return true;

       	   }
    }

	else if(token[0] == 'e')
	{
		if(token[1] == 'l' && token[2] == 's'&& token[3] == 'e')
        {
            key_words++;
            return true;
        }
		else if(token[1] == 'n' && token[2] == 'd')
        {
            key_words++;
            return true;
        }
        return false;
	}

	else if(token[0] == 'i')
	{
		if(token[1] == 'f')
        {
            key_words++;
            return true;
        }

		else
			return false;
	}

	else if(token[0] == 'w')
	{
		if(token[1] == 'h' && token[2] == 'i' && token[3] == 'l' && token[4] == 'e' && token[5] == 'l' && token[6] == 'o' && token[7] == 'o' && token[8] == 'p' )
        {
		    key_words++;
		    return true;
		}
			return false;
	}

	else if(token[0] == 'd')
	{
		if(token[1] == 'i' && token[2] == 's' && token[3] == 'p' && token[4] == 'l'&& token[5] == 'a'&& token[6] == 'y' )
        {
		    key_words++;
		    return true;
		}
		return false;
	}


	else if(token[0] == 'r')
	{
		if(token[1] == 'e' && token[2] == 'a' && token[3] == 'd')
        {
		    key_words++;
            return true;
		}
		return false;
	}

	else
		return false;

}
//------------ Separators------------//

bool divider(char token)
{
	if
	(token == ' ' || token == '\n' || token == '\t'  || token == '(' || token == ')' || token == '"' || token == '\'' || token == '.' ||	token == ';' || token == '\\' || token == '{' || token == '}' ||token == '[' || token == ']' || token == ',' || token == ':' || token == '+' ||token == '-' || token == '*' || token == '$' ||token == '/' || token == '&' || token == '|' || token == '=' ||token == '<' || token == '>' )
		return true;
	return false;
}

//--------Data types-----------------//

bool dataTypes(string token)
{
    if (token[0] == 'i')
    {
        if (token[1] == 'q')
        {
        	dataType++;
            return true;
        }
        return false;
    }

    else if(token[0] == 'a')
    {
        if(token[1] == 'i')
        {
        	dataType++;
            return true;
        }
        return false;
    }

    else if(token[0] == 'w')
    {
        if(token[1] == 'i')
        {
        	dataType++;
            return true;
        }
        return false;
    }
}
//--------Function---------- error//

bool funct(string token)
{

    if (token[0] >= 'A' && token[0] <= 'Z')
    {
        if (token[token.length()-1] == ')' && token[token.length()-2] == '(')
        {

            fun++;
            return true;
        }

    }
	else if (token[0] >= 'a' && token[0] <= 'z')
    {
         if (token[token.length()-1] == ')' && token[token.length()-2] == '(')
        {

            fun++;
            return true;
        }
    }
	return false;
}

//---------Identifiers (variables)------------//

bool identifiers(string token)
{
	if (token[0] == '_')
    {
        identifier++;
        return true;
    }
	else if (token[0] >= 'A' && token[0] <= 'Z')
    {
        identifier++;
        return true;
    }
	else if (token[0] >= 'a' && token[0] <= 'z')
    {
        identifier++;
        return true;
    }
	return false;
}
//------------Integers-----------------//

bool integers(std::string token)
{
	bool test = false;
	int i=0;
	while(i < token.length())
	{
		if(token[i] =='0' || token[i] == '1' || token[i] == '2' || token[i] == '3'|| token[i] == '4' || token[i] == '5' || token[i] == '6' || token[i] == '7'|| token[i] == '8' || token[i] == '9')
		{
            identifier++;
            integer++;
            test=true;
        }

		else
		{
			test = false;
			return test;
		}
		++i;
	}
	return test;
}

//------------ Strings------------//

bool strings(string token)
{
	int length = token.length()-1;
	if (token[0] == '"' && token[length] == '"')
    {
        strng++;
        return true;
    }
	else if (token[0] == '\'' && token[length] == '\'')
    {
        strng++;
        return true;
    }
    return false;
}


//------------ Float ------------//

bool floats(string token)
{
	bool test = false;
	bool decimal = false;
	int i=0;
	do
	{
		if(token[i] == '0' || token[i] == '1' || token[i] == '2' || token[i] == '3'|| token[i] == '4' || token[i] == '5' || token[i] == '6' || token[i] == '7'|| token[i] == '8' || token[i] == '9' || token[i] == '.')
		{
		    if(token[i] == '.')
            {
                decimal = true;
                test = true;
            }

        }
		else
		{
			test = false;
			return test;
		}
		++i;
	}while(i < token.length());
	if(decimal)
    {
        //identifier++;
        floatss++;
        return test;
    }
	return test;
}


void testToken(string token)
{
    writeFile.open("Tokens.txt",ios_base::app);
   // if(!writeFile) {
     //   cout << "cannot open file " << endl;
//    }
	if(preProcessor(token) == true)
    {
        cout << token << "\t\t\t\t\tThis is PreProcessor Directive" <<endl;
        writeFile <<"<PreProcessor>" <<endl;
    }

    else if(delimeters(token) == true)
    {
		cout << token << "\t\t\t\t\t\tThis is Delimeter" <<endl;
        writeFile <<"<Delimeter>" <<endl;
    }

    else if(preProcessor(token) == true)
    {
        cout << token << "\t\t\t\t\tThis is PreProcessor Directive" <<endl;
        writeFile <<"<PreProcessor>" <<endl;
    }

	else if(specialCharacters(token) == true)
	{
		cout << token << "\t\t\t\t\t\tThis is Special Character" <<endl;
        writeFile <<"<Special Character>" <<endl;
    }

	else if(operators(token) == true)
	{
		cout << token << "\t\t\t\t\t\tThis is Operator" <<endl;
        writeFile <<"<Operator>" <<endl;
    }

    else if(keywords(token) == true)
    {
		cout << token << "\t\t\t\t\t\tThis is Keyword" <<endl;
        writeFile <<"<Keyword>" <<endl;
    }

    else if(dataTypes(token) == true)
    {
        cout << token << "\t\t\t\t\t\tThis is Datatype" <<endl;
        writeFile <<"<Datatype>" <<endl;
    }

    else if(funct(token) == true)
    {
		cout << token << "\t\t\t\t\t\tThis is Function" <<endl;
        writeFile <<"<Function>" <<endl;
    }

	else if(identifiers(token) == true)
	{
		cout << token << "\t\t\t\t\t\tThis is Identifier" <<endl;
        writeFile <<"<Identifier>" <<endl;
    }

    else if(floats(token) == true)
    {
        cout << token << "\t\t\t\t\t\tThis if Float value" <<endl;
        writeFile <<"<Float>" <<endl;
    }

    else if(integers(token) == true)
    {
        cout << token << "\t\t\t\t\t\tThis is Integer value" <<endl;
        writeFile <<"<Integer>" <<endl;
    }

	else if(strings(token) == true)
	{
		cout << token << "\t\t\t    \t\tThis is a String" <<endl;
        writeFile <<"<String>" <<endl;
    }

	else if(singleCom(token) == true)
	{
		std::cout << token << "\t\t\t\t\t\tThis is a Single Comment" << std::endl;
        writeFile <<"<Comment>" <<endl;
    }

    else if(whitespace(token) == true)

	{
		// If whitespace, don't print anything
	}
	else
	{
		if(token != "" || token != "\0")
		cout << token << "\t\t\t\t\t\t Error: Invalid Token" <<endl;
	}

	writeFile.close();
}

void loadBuff(char* state)
{
	int start = 0,  lookAhead= 0,  i = 0;
	string token = "";
	do
	{
		while(!divider(state[lookAhead]))
		{
			token += state[lookAhead];
			++lookAhead;
			++i;
		}
		if(divider(state[lookAhead]))
		{
			if (state[lookAhead] == '"')
			{
				token += state[lookAhead];
				++lookAhead;
				++i;
				while(state[lookAhead] != '"')
				{
					token += state[lookAhead];
					++i;
					++lookAhead;
				}
				token += state[lookAhead];
				testToken(token);
				token = "";
			}
	 	else if (state[lookAhead] == '.')
			{
				if(integers(string(1, state[lookAhead-1])))
				{
					token += state[lookAhead];
					++lookAhead;
					++i;
					do
					{
						token += state[lookAhead];
						++lookAhead;
						++i;
					}while(!divider(state[lookAhead]));
					testToken(token);
					token = "";
					token += state[lookAhead];
				}

				else
				{
					testToken(token);
					token = "";
					token += state[lookAhead];
				}

			}
			else if (operators(string(1, state[lookAhead])))
			{
				if(operators(string(1, state[lookAhead+1])))
				{
					token += state[lookAhead];
					++lookAhead;
					++i;
					token += state[lookAhead];
				}
				else
				{
					testToken(token);
					token = "";
					token += state[lookAhead];
				}

			}
			else
			{
				testToken(token);
				token = "";
				token += state[lookAhead];
			}
		}
		i++;
		testToken(token);
		token = "";
		++lookAhead;
		start = lookAhead;

	}while(i < strlen(state));

}

int main()
{
	char character;
	int count = 1;
    string x,word,line,temp;
    int row = 0;
	ifstream file("input.wai");

    if(file.is_open())
    {
    	file.get(character);
        while(!file.eof())
        {
            file.get(character);
            ++count;
        }
	}
	file.close();

	char Arr[count] = {'\0'};

    file.open("input.wai");
    if(file.is_open())
    {
    	int i = 0;
    	file.get(character);
        while(!file.eof())
        {
            Arr[i] = character;
            file.get(character);
            ++i;
        }
        Arr[i] = '\0';
		loadBuff(Arr);
	}
    else
    {
    	std::cout<<"Error while opening the file\n";
	}
	cout << "\n^*^*^*^* No of tokens in file ^*^*^*^*"<< endl;
	cout<<"\n\tPre Processor Directive: " <<processsor<<endl;
	cout<<"\tDelimiters: "<<delimeter<<endl;
	cout<<"\tSpecial characters: "<<specialCh<<endl;
	cout<<"\tOperators:" <<operatorss<<endl;
	cout<<"\tData types: " <<dataType<<endl;
	cout<<"\tFunctions: "<<fun<<endl;
	cout<<"\tIdentifiers: "<<identifier<<endl;
	cout<<"\tIntegers: "<<integer<<endl;
	cout<<"\tStrings: "<<strng<<endl;
	cout<<"\tFloat: "<<floatss<<endl;
	cout<<"\tKeywords: "<<key_words<<endl;
	cout<<"\tSingle Comment: "<<com<<endl;
	total_token = processsor+delimeter+specialCh+operatorss+dataType+fun+identifier+integer+strng+floatss+key_words+com;
	cout<<"\n\tTotal Tokens: "<<total_token<<endl;

	return (0);
}
