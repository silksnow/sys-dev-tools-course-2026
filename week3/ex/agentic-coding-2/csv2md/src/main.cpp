#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using Row = std::vector<std::string>;

static std::string readFile(const std::string& path) {
    std::ifstream in(path, std::ios::binary);
    if (!in) {
        std::cerr << "error: cannot open file: " << path << "\n";
        std::exit(1);
    }
    std::ostringstream ss;
    ss << in.rdbuf();
    return ss.str();
}

static std::vector<Row> parseCsv(const std::string& text) {
    std::vector<Row> rows;
    Row row;
    std::string field;
    bool inQuotes = false;
    bool fieldStarted = false;

    for (std::size_t i = 0; i < text.size(); ++i) {
        char c = text[i];

        if (inQuotes) {
            if (c == '"') {
                if (i + 1 < text.size() && text[i + 1] == '"') {
                    field += '"';
                    ++i;
                } else {
                    inQuotes = false;
                }
            } else {
                field += c;
            }
            continue;
        }

        switch (c) {
            case '"':
                if (fieldStarted) {
                    // A quote in the middle of an unquoted field is treated
                    // as literal content (tolerate malformed input).
                    field += c;
                } else {
                    inQuotes = true;
                }
                break;
            case ',':
                row.push_back(field);
                field.clear();
                fieldStarted = false;
                break;
            case '\r':
                break;
            case '\n':
                row.push_back(field);
                field.clear();
                fieldStarted = false;
                rows.push_back(row);
                row.clear();
                break;
            default:
                field += c;
                fieldStarted = true;
                break;
        }
    }

    if (fieldStarted || inQuotes || !field.empty()) {
        row.push_back(field);
    }
    if (!row.empty()) {
        rows.push_back(row);
    }

    return rows;
}

static std::string escapeMd(const std::string& s) {
    std::string out;
    for (char c : s) {
        if (c == '|') {
            out += "\\|";
        } else {
            out += c;
        }
    }
    return out;
}

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cerr << "usage: " << argv[0] << " <input.csv>\n";
        return 1;
    }

    std::string text = readFile(argv[1]);
    std::vector<Row> rows = parseCsv(text);

    if (rows.empty()) {
        std::cerr << "error: no data found\n";
        return 1;
    }

    // Normalize column count to the widest row.
    std::size_t cols = 0;
    for (const auto& r : rows) {
        cols = std::max(cols, r.size());
    }
    for (auto& r : rows) {
        r.resize(cols);
    }

    const Row& header = rows.front();

    for (std::size_t j = 0; j < cols; ++j) {
        std::cout << "| " << escapeMd(header[j]) << " ";
    }
    std::cout << "|\n";

    for (std::size_t j = 0; j < cols; ++j) {
        std::cout << "| --- ";
    }
    std::cout << "|\n";

    for (std::size_t i = 1; i < rows.size(); ++i) {
        for (std::size_t j = 0; j < cols; ++j) {
            std::cout << "| " << escapeMd(rows[i][j]) << " ";
        }
        std::cout << "|\n";
    }

    return 0;
}
