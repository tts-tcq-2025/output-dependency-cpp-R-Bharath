#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms > 38 && cms < 42) {
        sizeName = 'M';
    } else if(cms > 42) {
        sizeName = 'L';
    }
    return sizeName;
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    // ❗ New tests to expose the bug
    assert(size(38) == 'S');  // Will fail –– bug: 38 not handled
    assert(size(42) == 'M');  // Will fail –– bug: 42 not handled
    std::cout << "All is well (maybe!)\n";
}

int main() {
    testTshirtSize();
    return 0;
}
