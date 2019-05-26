#include <iostream>
using std::cin; using std::cout; using std::endl; using std::cerr;
using std::ostream;
#include <fstream>
using std::ifstream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <algorithm>
using std::sort; using std::unique;

ostream &prt(ostream &os, vector<string> &vs){
    for (const auto &a : vs)
        os << a << " ";
    return os;
}

void read(ifstream &ifs, vector<string> &vs){
    string tmp;
    if (ifs.is_open()){
        while (ifs >> tmp)
            vs.push_back(tmp);
    } else {
        cerr << "Failed to open file" << endl;
        return;
    }
}

void elimDups(ifstream &ifs, ostream &os, vector<string> &vs){
    read(ifs, vs);
    prt(os, vs) << endl;
    sort(vs.begin(), vs.end());
    prt(os, vs) << endl;
    auto end_unique = unique(vs.begin(), vs.end());
    prt(os, vs) << endl;
    vs.erase(end_unique, vs.end());
    prt(os, vs) << endl;
}

int main() {
    string pa("/home/raymain/CLionProjects/CPPLv1/test.txt");
    ifstream in(pa);
    vector<string> vs1;
    elimDups(in, cout, vs1);
}
