#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <memory>
#include <utility>

class TextQuery;
class QueryResult;

class QueryResult
{
    friend class TextQuery;

public:
    QueryResult(const std::string &word)
        : original_word(word)
    {}

    std::ostream& print(std::ostream &out) const
    {
        out << original_word << " occurs " << times << (times > 1 ? " times" : " time") << std::endl;
        for (auto &&[line_number, line]: lines) {
            out << "    (line " << line_number << ") " << line << std::endl;
        }
        return out;
    }

private:
    void add_line(size_t line_number, const std::string &line)
    {
        std::istringstream ss(line);
        std::string word;
        while (ss >> word) {
            if (word == original_word) {
                ++times;
            }
        }
        lines.emplace_back(line_number, line);
    }

    size_t times = 0;
    std::string original_word;
    std::vector<std::pair<size_t, std::string>> lines;
};

class TextQuery
{
public:
    TextQuery(std::ifstream &fin)
    {
        std::string line;
        size_t line_number = 0;
        while (std::getline(fin, line)) {
            ++line_number;
            lines.push_back(line);
            std::istringstream ss(line);
            std::string word;
            while (ss >> word) {
                words_map[word].insert(line_number);
            }
        }
    }

    QueryResult query(const std::string &word) const
    {
        QueryResult result(word);
        if (words_map.find(word) != words_map.end()) {
            for (auto &line_number:
                    const_cast<std::map<std::string, std::set<size_t>>&>(words_map)[word])
            {
                result.add_line(line_number, lines[line_number - 1]);
            }
        }
        return result;
    }

private:
    std::vector<std::string> lines;
    std::map<std::string, std::set<size_t>> words_map;
};

void runQueries(std::ifstream &infile)
{
    TextQuery tq(infile);
    do {
        std::cout << "enter word to look for, or q to quit: ";
        std::string s;
        if (!(std::cin >> s) || s == "q") break;
        tq.query(s).print(std::cout);
    } while (true);
}

int main()
{
    std::ifstream fin("input.txt");
    runQueries(fin);
    return 0;
}