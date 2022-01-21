#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
	system("color 2");
	
	fstream input;
	string line;
	int forward=0 , up=0 , down=0;
	
	input.open("input.txt" , ios :: in);
	
	while(!input.eof())
	{
		getline(input , line);
		
		if(line[0] == 'f')
		{
			forward += ((int)line.back()-48); // line.back() ->read last char of each lines --- (int) -> convert char to int
		}
		else if(line[0] == 'u')
		{
			up += ((int)line.back()-48);
		}
		else if(line[0] == 'd')
		{
			down += ((int)line.back()-48);
		}
	}
	cout<<"answer(part 1): "<<forward * (down - up)<<endl;
	
	input.close();
	input.open("input.txt" , ios :: in);
	
	forward=0;
	up=0;
	down=0;
	int aim=0;
	
	//line[0] -> read first char of each lines.
	while(!input.eof())
	{
		getline(input , line);
		if(line[0] == 'f') //f = forward
		{
			forward += ((int)line.back()-48);
			down += aim*((int)line.back()-48);
		}
		else if(line[0] == 'u') //u = up
		{
			aim -= ((int)line.back()-48);
		}
		else if(line[0] == 'd') //d = down
		{
			aim += ((int)line.back()-48);
		}
	}
	cout<<"answer(part 2): "<<forward * down<<endl;
	
	return 0;
}