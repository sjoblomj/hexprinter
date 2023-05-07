#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <iostream>
using namespace std;

const int max_size = 64 * 1024;

string print_address(int offsetdigits, int offset) {
    stringstream ss;
    ss << setw(offsetdigits) << setfill('0') << uppercase << hex << offset/16 << "0: ";
    return ss.str();
}

void printhex(int len, unsigned char* filecontent, int offset) {

    char hexstr[10]; // Array to store hexadecimal string
    sprintf(hexstr, "%X", len - 1);
    int offsetdigits = 0;
    while (hexstr[offsetdigits] != '\0') {
        ++offsetdigits;
    }
    offsetdigits--;

    stringstream ss;
    string asciireps = "";
    string hexout = "";
    for (int i = 0; i < offsetdigits; i++)
        hexout += " ";
    hexout += "    0 1  2 3  4 5  6 7  8 9  A B  C D  E F";
    if (offset % 16 != 0) {
        cout << hexout << endl;
        hexout = print_address(offsetdigits, offset);
        int digits_to_skip = offset - (offset / 16) * 16;
        for (int i = 0; i < digits_to_skip; i++) {
            hexout += "  ";
            asciireps += " ";
            if (i % 2 == 0)
                hexout += " ";
        }
    }

    for (int i = offset; i < len; i++) {
        if (i % 16 == 0) {
            cout << hexout << "    " << asciireps << endl;
            hexout = print_address(offsetdigits, i) + " ";
            asciireps = "";
        } else if (i % 2 == 0) {
            hexout += " ";
        }
        ss.str("");
        ss << setw(2) << setfill('0') << uppercase << hex << (int) filecontent[i];
        hexout += ss.str();

        asciireps += (isprint(filecontent[i]) ? filecontent[i] : '.');
    }

    size_t pos = hexout.length();
    if (pos == string::npos)
        pos = 0;
    for (int i = pos + 1; i < 48 + offsetdigits; i++)
        hexout += ' ';

    cout << hexout << asciireps << endl;
}

int min(int a, int b) {
    return (a > b) ? b : a;
}

void print_help(const char *program_name) {
    cout << "hexprinter 1.0 by Johan Sjöblom" << endl;
    cout << "Usage:" << endl << program_name << " file [[start_index] end_index]" << endl << endl;
    cout << "The file to open needs to be provided. Optionally, " << endl;
    cout << "one can give an end_index (in decimal), in which " << endl;
    cout << "case the content of the file up until that index " << endl;
    cout << "will be displayed. " << endl;
    cout << "If start_index (in decimal) is given in addition, " << endl;
    cout << "the content between the indexes is displayed." << endl;
}

int main(int argc, char **argv) {
    if (argc < 2 || argc > 4) {
        print_help(argv[0]);
        return 1;
    }
    FILE *file = fopen(argv[1], "rb");
    if (file == NULL) {
        print_help(argv[0]);
        return 1;
    }
    fseek(file, 0L, SEEK_END);
    long filelen = ftell(file);
    fseek(file, 0L, SEEK_SET);

    int start_index = argc == 4 ? atoi(argv[2]) : 0;
    int end_index = argc > 2 ? atoi(argv[argc - 1]) : max_size;
    if (start_index >= end_index) {
        cout << "Start index '" << start_index << "' must be less than end index '" << end_index << "'" << endl << endl;
        print_help(argv[0]);
        return 1;
    }

    int size = min(filelen, end_index);

    unsigned char content[size];
    fread(&content, sizeof(content), 1, file);
    fclose(file);

    if (start_index > 0)
        cout << "<Content cut off> ..." << endl;
    printhex(size, content, start_index);
    if (size < filelen)
        cout << "... <Content cut off>";
    cout << endl;
    return 0;
}
