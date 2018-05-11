#include "PropertyFileConfiguration.h"

void PropertyFileConfiguration::split(const std::string &s, char delim, std::vector<std::string> &elems) {
    elems.resize(0);
    std::stringstream ss;
    ss.str(s);
    std::string item;
    while (std::getline(ss, item, delim)) {
        elems.push_back(item);
    }
}

PropertyFileConfiguration::PropertyFileConfiguration(string file_name)
    :file_name(file_name)
{
	fstream plik;
	plik.open(file_name.c_str(),std::ifstream::in);
	string tmp = "";
	char split_char ='=';
	vector<string> str_vec = vector<string>(0);
	while(getline(plik,tmp))
	{
		for(unsigned i = 0; i<tmp.size() ; ++i)
			if(tmp[i] == ' ' || tmp[i] == '\t')
				tmp.erase(i,1);
		if(tmp[0] == '#' || tmp[0] == '/')
			continue;
		split(tmp,split_char,str_vec);
		prop_map[str_vec[0]] = str_vec[1];
	}
	plik.close();
}

string PropertyFileConfiguration::getString(string kay)
{
	return prop_map[kay];
}

int PropertyFileConfiguration::getInt(string kay)
{
	return atoi(prop_map[kay].c_str());
}

double PropertyFileConfiguration::getDouble(string kay)
{
	return atof(prop_map[kay].c_str());
}


void PropertyFileConfiguration::printProperties()
{
    cout<<"Program properties:"<<endl;
    for(map<string, string>::const_iterator it = prop_map.begin();it != prop_map.end(); ++it)
    {
        std::cout << it->first <<"="<< it->second<<endl;
    }
	cout<<endl;
}

void PropertyFileConfiguration::changeProperty(string key,string val)
{
    prop_map[key]=val;
    fstream file;
    file.open(file_name.c_str(),std::ofstream::out |std::ofstream::trunc);
    for(map<string, string>::const_iterator it = prop_map.begin();it != prop_map.end(); ++it)
    {
        file << it->first <<"="<< it->second<<endl;
    }
	file<<endl;
    file.close();
}