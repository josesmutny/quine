#include <iostream>
#include <map>
#include <regex>

using namespace std;

string printWithoutEscaping(const string &str) {
	regex tab("\\\t"), line("\\\\"), newline("\\\n"), quotes("\\\"");
	return regex_replace(regex_replace(regex_replace(regex_replace(str, line, "\\\\"), newline, "\\n"), tab, "\\t"), quotes, "\\\"");
}

int main() {

	map<char, string> elements = {
		{'b', "\tfor (auto &elem : elements)\n\t\tcout << \"\\t\\t{'\" << elem.first << \"', \\\"\" << printWithoutEscaping(elem.second) << \"\\\"},\" << endl;\n"},
		{'c', "\tfor (auto section : string(\"tpbcr\"))\n\t\tcout << elements[section] << endl;\n"},
		{'e', "\tmap<char, string> elements = {"},
		{'f', "string printWithoutEscaping(const string &str) {\n\tregex tab(\"\\\\\\t\"), line(\"\\\\\\\\\"), newline(\"\\\\\\n\"), quotes(\"\\\\\\\"\");\n\treturn regex_replace(regex_replace(regex_replace(regex_replace(str, line, \"\\\\\\\\\"), newline, \"\\\\n\"), tab, \"\\\\t\"), quotes, \"\\\\\\\"\");\n}\n"},
		{'h', "#include <iostream>\n#include <map>\n#include <regex>\n"},
		{'m', "int main() {\n"},
		{'n', "using namespace std;\n"},
		{'p', "\tfor (auto section : string(\"hnfme\"))\n\t\tcout << elements[section] << endl;\n"},
		{'r', "\treturn 0;\n}"},
		{'t', "\t};\n"},
	};

	for (auto section : string("hnfme"))
		cout << elements[section] << endl;

	for (auto &elem : elements)
		cout << "\t\t{'" << elem.first << "', \"" << printWithoutEscaping(elem.second) << "\"}," << endl;

	for (auto section : string("tpbcr"))
		cout << elements[section] << endl;

	return 0;
}
