// Merge Sequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


using namespace std;


int main(int argc, char* argv[])
{
	ios::sync_with_stdio(0);
	if (argc == 1 || strlen(argv[1]) == 0)
	{
		cout << "Usage:\nMergeSequence [filepath1] [filepath2]...\nThis program reads [filepath] and merges the expression number after the \'>' title.\nPress any key to exit...";
		getchar();
		return 0;
	}
	ifstream infs;
	unordered_map<string, pair<string, size_t>> records;
	for (int n = 1; n < argc; n++)
	{
		string path(argv[n]);
		string line;		
		infs.open(path, ifstream::in);
		if (!infs.is_open())
		{
			cout << "\nCannot open file \"" << path << "\" to input\nPress any key to exit...";
			getchar();
			return 1;
		}
		string fname, seq;
		size_t count;
		cout << "Reading file \"" << path << "\" ...\n";
		while (getline(infs, line))
		{
			if (line.size() == 0 || line[0] == ';')
				continue;
			if (line[0] == '>')
			{
				if (seq.size())
				{
					if (records.find(seq) == records.end())
						records[seq] = make_pair(fname, count);
					else
						records[seq].second += count;
				}
				seq.clear();
				count = 0;
				fname.clear();
				int i = 0;
				string countStr;
				while (i < line.size() && (line[i] == ' ' || line[i] == '\t'))
					i++;
				while (i < line.size() && !(line[i] == ' ' || line[i] == '\t'))
				{
					fname.push_back(line[i]);
					i++;
				}
				while (i < line.size() && (line[i] == ' ' || line[i] == '\t'))
					i++;
				while (i < line.size() && !(line[i] == ' ' || line[i] == '\t'))
				{
					countStr.push_back(line[i]);
					i++;
				}
				count = stoull(countStr);
			}
			else
			{
				if (seq.size())
					seq.push_back('\n');
				seq += line;
			}
		}
		if (seq.size())
		{
			if (records.find(seq) == records.end())
				records[seq] = make_pair(fname, count);
			else
				records[seq].second += count;
		}
		infs.close();
	}
	string extension;
	string path(argv[1]);
	int i = path.size() - 1;
	while (i >= 0 && path[i] != '.')
	{
		extension.push_back(path[i]);
		path.pop_back();
		i--;
	}
	path.pop_back();
	reverse(extension.begin(), extension.end());
	path = path + "_processed." + extension;
	cout << "Writing to \"" << path << "\" ...\n";
	ofstream ofs;
	ofs.open(path, ofstream::out);
	if (!ofs.is_open())
	{
		cout << "\nCannot open file \"" << path << "\"  to output\nPress any key to exit...";
		getchar();
		return 1;
	}
	for (auto& key : records)
	{
		ofs << key.second.first << '\t' << key.second.second << '\n';
		ofs << key.first << "\n\n";
	}
	ofs.close();
	cout << "Done.\nPress any key to exit...";
	getchar();
}

