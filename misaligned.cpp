#include <iostream>
#include <assert.h>

int printColorMap() {
    const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
    const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};
    int i = 0, j = 0;
    for(i = 0; i < 5; i++) {
        for(j = 0; j < 5; j++) {
            std::cout << i * 5 + j << " | " << majorColor[i] << " | " << minorColor[i] << "\n";
        }
    }
    return i * j;
}

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n"; 
    int result = printColorMap();
    assert(result == 25);
    // ✅ Test format of a few lines
    assert(colorMap[0] == "1 | White | Blue");     // should pass
    assert(colorMap[1] == "2 | White | Orange");   // ❌ this will fail due to bug
    assert(colorMap[5] == "6 | Red | Blue");       // ❌ this will also fail
    std::cout << "All is well (maybe!)\n";
}
int main() {
    testPrintColorMap();
    return 0;
}
