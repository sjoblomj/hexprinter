# hexprinter
Simple program to print a file in hexadecimal representation, with ascii representation on the side. It can be used to display, decode and analyze binary data. Optionally, one can give a start offset to begin printing from, and an end offset to stop printing at.

## Example
```
./hexprinter hexprinter.cc
      0 1  2 3  4 5  6 7  8 9  A B  C D  E F
000:  2369 6E63 6C75 6465 203C 636D 6174 683E    #include <cmath>
010:  0A23 696E 636C 7564 6520 3C73 7472 696E    .#include <strin
020:  673E 0A23 696E 636C 7564 6520 3C73 7374    g>.#include <sst
030:  7265 616D 3E0A 2369 6E63 6C75 6465 203C    ream>.#include <
040:  696F 6D61 6E69 703E 0A23 696E 636C 7564    iomanip>.#includ
050:  6520 3C69 6F73 7472 6561 6D3E 0A75 7369    e <iostream>.usi
060:  6E67 206E 616D 6573 7061 6365 2073 7464    ng namespace std
070:  3B0A 0A63 6F6E 7374 2069 6E74 206D 6178    ;..const int max
080:  5F73 697A 6520 3D20 3634 202A 2031 3032    _size = 64 * 102
090:  343B 0A0A 7374 7269 6E67 2070 7269 6E74    4;..string print
0A0:  5F61 6464 7265 7373 2869 6E74 2061 6464    _address(int add
0B0:  7265 7373 6C65 6E67 7468 2C20 696E 7420    resslength, int
0C0:  6F66 6673 6574 2920 7B0A 2020 2020 7374    offset) {.    st
0D0:  7269 6E67 7374 7265 616D 2073 733B 0A20    ringstream ss;.
0E0:  2020 2073 7320 3C3C 2073 6574 7728 6164       ss << setw(ad
0F0:  6472 6573 736C 656E 6774 6829 203C 3C20    dresslength) <<
100:  7365 7466 696C 6C28 2730 2729 203C 3C20    setfill('0') <<
110:  7570 7065 7263 6173 6520 3C3C 2068 6578    uppercase << hex
120:  203C 3C20 6F66 6673 6574 2F31 3620 3C3C     << offset/16 <<
130:  2022 303A 2022 3B0A 2020 2020 7265 7475     "0: ";.    retu
```

## Compiling
```
g++ hexprinter.cc -o hexprinter
```
