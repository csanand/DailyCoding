/*
Given a range of co-ordinates of kingdoms on a line, (start,end), 
find number of bombs needed to blow the kingdom, if each non-overlapping kingdom requires 1 bomb.
 If overlapping then to blow up the overlapping it will take 1 bomb.
 I/P :  [(4,8), (8,9),(12,15),(2,5)]
 ANS: 2 bombs needed, [(2,9),(12,15)]

My Solution : 
	1. Get the range of co-ordinates, ie. line segment encapsulating all the line segment co-ordinates given.
	2. Create an initialized with 0. A number_of_bombs variable initialized to number of line segment.
	3. For the starting point of each segment maps to array index [adjust for distance from origin], fill the value with length of the segment.
	4. Loop through the array, by the distance at each starting point.
	5. For every new starting point[non-zero value] found on range of line segment reduce the number_of_bombs.
	6. At the end of the array, we get number of bombs needed.
	
*/


#include <iostream>
#include <vector>

int main()
{
	std::vector<std::vector<int>> co_ordinates = {{7,9},{1,6},{1,2},{5,8},{15,18},{18,22}};//{{4,8},{8,9},{12,15},{2,5}};//{{7,9},{1,6},{1,2},{5,8},{15,19},{18,22}};
	int number_of_bombs = co_ordinates.size();
	std::cout << number_of_bombs << std::endl;
	int start_line = co_ordinates[0][0];
	int end_line = co_ordinates[0][1];
	std::vector<int> line;
	//std::vector<std::vector<int>>::iterator it;
	int temp_count=0;
	//bool decrement;
	int it;
	
	for( it = 0; it < co_ordinates.size();++it)
	{
		if(co_ordinates[it][0] < start_line)
			start_line = co_ordinates[it][0];
		if(co_ordinates[it][1] > end_line)
			end_line = co_ordinates[it][1];
	}
	
	std::cout << "start of the line : " << start_line << std::endl;
	std::cout << "end of the line : " << end_line << std::endl;
	
	line.resize((end_line - start_line),0);
	
	for(it = 0; it < co_ordinates.size();++it)
	{
		if(line[co_ordinates[it][0] - start_line] == 0 )
		{
			line[co_ordinates[it][0] - start_line] = (co_ordinates[it][1]-co_ordinates[it][0]);
			
			//std::cout << "2nd For IF : " << line[co_ordinates[it][0] - start_line] << std::endl;
		}
		else
		{
			number_of_bombs--;
			line[co_ordinates[it][0] - start_line] = (line[co_ordinates[it][0] - start_line] > co_ordinates[it][1]-co_ordinates[it][0]) ?\
			line[co_ordinates[it][0] - start_line] : co_ordinates[it][1]-co_ordinates[it][0];
			//std::cout << "2nd For else : " << line[co_ordinates[it][0] - start_line] << std::endl;
		}
	}
/*
	for(it = 0; it < line.size(); ++it)
	{
	    std::cout << "Array Element : " << it << " is : " << line[it] << std::endl;    
	}
*/	
	
	temp_count = line[0]-1;
        
	
	for(it = 1; it < line.size()-1; ++it)
	{
	
		if((line[it] != 0))  
		{
			if (temp_count !=0)
				number_of_bombs--;
			if(line[it] > temp_count)
				temp_count = line[it];
//			std::cout << "FOR : number of bombs = " << number_of_bombs << "  " << it << std::endl;
			
		}
		else
		{
			if(temp_count == 0)
				continue;
			else
				temp_count--;
		}
		
//		std::cout << "Temp Count = " << temp_count << "   " << it << std::endl;
	}
	
	std::cout << "number of bombs = " << number_of_bombs << std::endl;
	
	return 0;
}

