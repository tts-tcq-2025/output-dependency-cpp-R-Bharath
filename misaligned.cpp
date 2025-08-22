#include <iostream>
#include <vector>
#include <string>
#include <functional>
#include <iomanip>

// Data structure for a color map entry
struct ColorMapEntry {
    int pairNumber;
    std::string major;
    std::string minor;
};

// 1. Generate all color pairs
std::vector<ColorMapEntry> generateColorMap() {
    std::vector<std::string> majorColors = {"White", "Red", "Black", "Yellow", "Violet"};
    std::vector<std::string> minorColors = {"Blue", "Orange", "Green", "Brown", "Slate"};

    std::vector<ColorMapEntry> colorMap;

    for (size_t i = 0; i < majorColors.size(); ++i) {
        for (size_t j = 0; j < minorColors.size(); ++j) {
            int pairNumber = i * minorColors.size() + j;
            colorMap.push_back({pairNumber, majorColors[i], minorColors[j]});
        }
    }
    return colorMap;
}

// 2. Format one line consistently
std::string formatColorMapEntry(int pairNumber, const std::string& major, const std::string& minor) {
    std::ostringstream oss;
    oss << pairNumber << " | " 
        << std::left << std::setw(6) << major << " | "   // align major to width 6
        << minor;
    return oss.str();
}

// 3. Default output function (prints to console)
void printOnConsole(const std::string& lineItem) {
    std::cout << lineItem << std::endl;
}

// 4. Orchestration function
int printColorMap(std::function<void(const std::string&)> outputFunc = printOnConsole) {
    auto colorMap = generateColorMap();
    for (const auto& entry : colorMap) {
        std::string line = formatColorMapEntry(entry.pairNumber, entry.major, entry.minor);
        outputFunc(line);
    }
    return static_cast<int>(colorMap.size());
}

// -----------------------------
// Example "test" with a mock
// -----------------------------
void test_printColorMap_fail() {
    std::vector<std::string> capturedOutput;

    // Mock output function: capture instead of printing
    auto mockPrint = [&](const std::string& line) {
        capturedOutput.push_back(line);
    };

    int count = printColorMap(mockPrint);

    // Value-based test
    if (count != 25 || capturedOutput.size() != 25) {
        throw std::runtime_error("Test failed: wrong count of lines");
    }

    // Behavior tests
    if (capturedOutput.front() != "0 | White  | Blue") {
        throw std::runtime_error("Test failed: first line mismatch");
    }
    if (capturedOutput.back() != "24 | Violet | Slate") {
        throw std::runtime_error("Test failed: last line mismatch");
    }

    std::cout << "All strengthened tests passed (for now!)\n";
}

// -----------------------------
// Main driver
// -----------------------------
int main() {
    // Production use
    printColorMap();

    // Run test
    test_printColorMap_fail();

    return 0;
}
