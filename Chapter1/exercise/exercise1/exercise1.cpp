//////////////////////Exercise1/////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include <valarray>
#include <cstdlib>
#include <ctime>
#include <bitset>
#include <algorithm>
#include <set>
#include <iterator>

const int MAX = 10000000;
using namespace std;
void make_data(string &file_buff);
//bit sort
void sort_bit(string &file_dst, string &file_src);
//C++ std::sort
void sort_methord(string &file_dst, string &file_src);
//tree sort
void sort_set(string &file_dst, string &file_src);

int main(int argc, char const *argv[])
{
	if (argc != 5)
	{
		cout << "No enough argcument\n";
	}
	string source(argv[1]);
	string result_bit(argv[2]); 
	string result_sort(argv[3]);
	string result_set(argv[4]);
	sort_bit(result_bit, source);
	sort_methord(result_sort, source);
	sort_set(result_set, source);	

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

void sort_methord(string &file_dst, string &file_src)
{
	valarray<int> num_array(MAX);
	ifstream fin(file_src.c_str());
	int num;

	for (int i = 0; i < MAX && fin >> num; ++i)
	{
		num_array[i] = num;
	}
	cout << num_array[MAX];
	sort(&num_array[0], &num_array[MAX]);
	fin.close();

	ofstream fout(file_dst.c_str());
	for (int i = 0; i < MAX; ++i)
	{
		fout << num_array[i] << " ";
	}
	fout.close();
}

void sort_set(string &file_dst, string &file_src)
{
	set<int> num_tree;
	ifstream fin(file_src.c_str());
	int num;

	for (int i = 0; i < MAX && fin >> num; ++i)
	{
		num_tree.insert(num);
	}
	fin.close();

	ofstream fout(file_dst.c_str());
	copy(num_tree.begin(), num_tree.end(), ostream_iterator<int> (fout, " "));
	
	fout.close();
}