#include <iostream>
#include <string>
#include <fstream>
#include <valarray>
#include <cstdlib>
#include <ctime>
#include <bitset>

const int MAX = 10000000;
using namespace std;
void make_data(string &file_buff);
void sort_bit(string &file_dst, string &file_src);

int main(int argc, char const *argv[])
{
	if (argc != 3)
	{
		cout << "No enough argcument\n";
	}
	string source(argv[1]);
	string result(argv[2]);
	make_data(source); 
	sort_bit(result, source);

	return 0;
}

void make_data(string &file_buff)
{
	// rand num
	valarray<int> num_array(MAX);
	for (int i = 0; i < MAX; ++i)
	{
		num_array[i] = i + 1;
	}
	srand(time(NULL));
	for (int i = 0; i < MAX; ++i)
	{
		int array_i = rand() % MAX;
		int array_j = rand() % MAX;
		swap(num_array[array_i], num_array[array_j]);
	}
	
	//write file
	ofstream fout(file_buff.c_str());
	if ( !fout.is_open() )
	{
		cout << "Can't open file: " << file_buff;
	}
	for (int i = 0; i < MAX; ++i)
	{
		fout << num_array[i] << " ";
	}
	fout.close();
}

void sort_bit(string &file_dst, string &file_src)
{
	bitset<MAX + 1> bitmap;
	int index;

	ifstream fin(file_src.c_str());
	ofstream fout(file_dst.c_str());
	if (!fin.is_open())
	{
		cout << "Can't open file src: " << file_src;
	}

	while(fin >> index)
	{
		bitmap[index] = true;
	}
	fin.close();

	for (int i = 1; i <= MAX; ++i)
	{
		if(bitmap[i])
		{
			fout << i << " ";
		}
	}
	fout.close();
}