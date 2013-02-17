# include <map>
# include <cstring>

using namespace std;

class BashColors
{
	private:
		map <string, string> colors;
	public:
		BashColors();
		string GetColorFromName(string);
};

BashColors::BashColors(void)
{
	colors["black"]  = "\033[30m";
	colors["red"]    = "\033[31m";
	colors["green"]  = "\033[32m";
	colors["yellow"] = "\033[33m";
	colors["blue"]   = "\033[34m";
	colors["purple"] = "\033[35m";
	colors["cyan"]   = "\033[36m";
	colors["white"]  = "\033[37m";
	colors["reset"]  = "\033[0m";
}

string BashColors::GetColorFromName(string name)
{
	return colors[name];
}
