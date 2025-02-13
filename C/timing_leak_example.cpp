#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

// Insecure function (leaks timing information)
bool insecureCheck(const string &input, const string &correct) {
    for (size_t i = 0; i < correct.length(); i++) {
        if (input[i] != correct[i]) {
            return false; // Early exit leads to timing leak
        }
    }
    return true;
}

// Secure function (constant-time comparison)
bool secureCheck(const string &input, const string &correct) {
    int diff = 0;
    size_t len = correct.length();
    
    for (size_t i = 0; i < len; i++) {
        diff |= input[i] ^ correct[i];  // No branching
    }
    
    return diff == 0;
}

int main() {
    string correctPassword = "secure123";
    string input = "secure123";

    // Measure time for insecure check
    auto start = high_resolution_clock::now();
    bool result = insecureCheck(input, correctPassword);
    auto end = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(end - start);
    cout << "Insecure Check Time: " << duration.count() << " ns, Result: " << (result ? "Match" : "No Match") << endl;

    // Measure time for secure check
    start = high_resolution_clock::now();
    result = secureCheck(input, correctPassword);
    end = high_resolution_clock::now();
    duration = duration_cast<nanoseconds>(end - start);
    cout << "Secure Check Time: " << duration.count() << " ns, Result: " << (result ? "Match" : "No Match") << endl;

    return 0;
}
