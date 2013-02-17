# include <map>
# include <string>

using namespace std;

class Colors
{
private:
	map <string, string> colors;
	
	Colors()
	{
		colors["reset"] = "\33[0m";
		colors["red"]   = 'B';
		colors["green"] = 'D';
		colors["blue"]  = 'E';
	}

};
