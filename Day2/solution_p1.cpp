#include <iostream>
#include <fstream>
#include <string>
#include <cmath>

// Note: I added a comma at the end of input

// pops back until ',' character
std::string extract_pair(std::string &s) {
    auto pair_idx = s.find(",");
    if(pair_idx == -1) return "";
    
    std::string res = s.substr(0, pair_idx);

    s = s.substr(pair_idx + 1);
    
    return res;
}

// sum of invalid numbers
long long repeats_sum(long long from, long long to) {
    int start = std::pow(10, (std::to_string(from).length() + 1) / 2 - 1); // smallest num of enough digits for invalid id

    long long sum = 0;

    for( int i = start; ; i++) {
        std::string s = std::to_string(i) + std::to_string(i);
        
        long long num = std::stoll(s);
        if(num < from) continue;
        if(num > to) break;
        
        sum += num;
    }

    return sum;
}

int main() {
    std::fstream f("input.txt");

    std::string line;
    f >> line;
    long long sum = 0;

    while( line.length() > 0 ) {
        std::string pair = extract_pair(line);
        if(pair == "") break;
        
        std::string firststr = pair.substr(0, pair.find('-'));
        std::string secondstr = pair.substr(pair.find('-') + 1);
        long long firstnum = std::stoll(firststr);
        long long secondnum = std::stoll(secondstr);

        sum += repeats_sum(firstnum, secondnum);
    }

    f.close();
    std::cout<<sum;

    return 0;
}