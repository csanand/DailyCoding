/*
Given an even number (greater than 2), return two prime numbers whose sum
will be equal to the given number.
A solution will always exist. See Goldbach’s conjecture.

Example:
Input: 4
Output: 2 + 2 = 4

If there are more than one solution possible,
return the lexicographically smaller solution.
*/

#include <iostream>
#include <vector>

void generate_prime_array(std::vector<bool>& prime);
void mark_multiple(std::vector<bool>& prime, int num);

int main()
{
    int even_num = 0;
    std::vector<bool> prime;
	while(1)
    {
        std::cout << "Enter Even number:  \n";
        std::cin >> even_num;
        if (even_num %2 != 0)
        {
            std::cout << "Exiting : Even number not entered!!!\n";
            return 1;
        }

        prime.resize(even_num,true);
        generate_prime_array(prime);

        for(int i= 1; i < prime.size()/2; ++i)
        {
            if(prime[i] == true && prime[prime.size() -i] == true)
            {
                std::cout<<"Numbers are: " << i << "\t"<< (prime.size()-i) << "\n";
                break;
        		//return 0;
            }
        }
	}
    return 0;
}

void generate_prime_array(std::vector<bool>& prime)
{
    int i;

	std::cout << "prime array size : "<< prime.size()<<"\n";
    for(i= 2; i < prime.size()/2; ++i)
    {
        mark_multiple(prime, i);
    }

    return;
}

void mark_multiple(std::vector<bool>& prime, int num)
{
    if (prime[num] == false)
        return;
    int j = 2;
    while(num*j < prime.size())
    {
        prime[num*j] = false;
        j++;
    }
}
