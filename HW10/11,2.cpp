#include <iostream>
#include <string>
#include <tr1/unordered_map>
#include <bits/stdc++.h>
#include <vector>
using namespace std::tr1;

using namespace std;

class Pattern{
	public:
	char pattern;
	int count;
	double probabilities;
		Pattern(char pattern,int count,double probabilities)
		{
			this->pattern=pattern;
			this->count=count;
			this->probabilities=probabilities;
		}
};

int main()
{
	

    unordered_map<char, vector<Pattern> > lookup;
    
    fstream my_file;
	my_file.open("file.txt", ios::in);
	if (!my_file) {
		cout << "No such file";
	}
	else {
		string file_contents = string((std::istreambuf_iterator<char>(my_file)), std::istreambuf_iterator<char>());
		double ts = (double)file_contents.size();
		for(int i=0;i<file_contents.size();i++)
		{
			if (lookup.find(file_contents[i]) == lookup.end())
	        {
	        	Pattern* p = new Pattern(file_contents[i],1,1/ts);
	            lookup.insert(make_pair(file_contents[i], p));
	        }
	        else
	        {
	        	Pattern p = lookup.at(file_contents[i]);
	        	p.count = p.count+1;
	        	p.probabilities = p.count/ts;
	            lookup[file_contents[i]]->second=p;
	        }
		}
		double random = (double)rand()/(double)file_contents.size();
		string s ="";
		for (auto& it : lookup) {
        	if(it.second.probabilities == random)
        	{
        		s=s+it.second.pattern;
			}
    	}
	}
	my_file.close();
	return 0;
}
