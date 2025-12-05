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

// checks if string is a repeat of a suffix substring times times
bool check_repeat(const std::string &s, int times) {
    int len = s.length();
    if (len % times != 0) return false;
    
    int sub_len = len / times;
    std::string sub = s.substr(0, sub_len);
    
    for (int i = 1; i < times; i++) {
        if (s.substr(i * sub_len, sub_len) != sub)
            return false;
    }
    
    return true;
}

// sum of invalid numbers
long long repeats_sum(long long from, long long to, int repeats = 2) {
    int start = std::pow(10, (std::to_string(from).length() + 1) / repeats - 1); // smallest num of enough digits for invalid id
    long long sum = 0;

    for( int i = start; ; i++) {
        std::string s = "";
        for( int j = 0; j < repeats; j++) s += std::to_string(i);
        
        long long num = std::stoll(s);
        if(num < from) continue;
        if(num > to) break;

        // Subtract if duplicate found (Only once)
        for(int j = repeats-1; j >= 2; j--) {
            if(check_repeat(s, j)) {
                sum -= num;
                break;
            }
        }
        
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

        for(int i = 2; i < std::to_string(secondnum).length()+1; i++)
            sum += repeats_sum(firstnum, secondnum, i);
    }

    f.close();
    std::cout<<sum;

    return 0;
}