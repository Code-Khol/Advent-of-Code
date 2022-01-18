#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    system("color 2");
    int meter[2000] , sum_part1=0 , sum_part2=0 ,windows[2];
    fstream input;
    input.open("input.txt" , ios :: in);
    
    for(int i=0 ; !input.eof() ; i++)
    {
    	input>>meter[i];
	}
	for(int i=0 ; i<2000 ; i++)
	{
		if(meter[i] < meter[i+1])
			sum_part1++;
		else
			continue;
	}
	cout<<"answer(part 1): "<<sum_part1<<endl;
	
	for(int i=0 ; i<2000 ; i++)
	{
		windows[0] = meter[i] + meter[i+1] + meter[i+2];
		windows[1] = meter[i+1] + meter[i+2] + meter[i+3];
		
		if(windows[1] > windows[0])
			sum_part2++;
	}
    cout<<"answer(part 2): "<<sum_part2<<endl;
    
    return 0;
}