#include <bits/stdc++.h>
using namespace std;
#include "regex.h"

int main() {
    Lexer lexer;
    string src;
    cin >> src;
    lexer.feed("[0-9][0-9]*",
            [&](string raw) {
                printf("match number: %s\n", raw.c_str());
            })
         .feed("[_a-zA-Z][_a-zA-Z0-9]*",
            [&](string raw) {
                printf("match identify: %s\n", raw.c_str());
            })
         .feed("\\:\\=",
            [&](string raw) {
                printf("match assign: %s\n", raw.c_str());
            })
         .feed("\\<\\=",
            [&](string raw) {
                printf("match <=\n");
            })
         .feed("\\>\\=",
            [&](string raw) {
                printf("match >=\n");
            })
         .feed("[!?:;.,#<=>+-\\*/\\(\\)]",
            [&](string raw) {
                printf("match symbol: %s\n", raw.c_str());
            })
         .feed("\\{[\f\n\r\t\v -z|~]*\\}",
            [&](string raw) {
                printf("match annotation: %s\n", raw.c_str());
            })
         .feed("[ \f\n\r\t\v][ \f\n\r\t\v]*",
            [&](string raw) {
                printf("just space\n");
            })
         .match(src);
}
