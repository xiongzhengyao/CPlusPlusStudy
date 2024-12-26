// #include <iostream>
// #include <unordered_map>
// #include <vector>
// using namespace std;

// // 找出最长的无重复子数组
// int lengthOfLongestSubstring(string s) {
//     unordered_map<char, int> charIndexMap; // 记录每个字符最后出现的位置
//     int maxLength = 0;  // 最长无重复子数组的长度
//     int start = 0;      // 当前无重复子数组的起始位置

//     // 遍历字符串,end为当前字符的位置
//     for (int end = 0; end < s.length(); ++end) {
//         // 如果当前字符已经在map中存在
//         if (charIndexMap.find(s[end]) != charIndexMap.end()) {
//             // 更新start为上一次出现位置的下一个位置
//             start = max(start, charIndexMap[s[end]] + 1);
//         }
//         // 更新当前字符的位置
//         charIndexMap[s[end]] = end;
//         // 更新最大长度
//         maxLength = max(maxLength, end - start + 1);
//     }

//     return maxLength;
// }

// int main() {
//     string input;
//     cout << "请输入一个字符串: ";
//     cin >> input;

//     int result = lengthOfLongestSubstring(input);
//     cout << "最长无重复子数组的长度为: " << result << endl;

//     return 0;
// }

#include <iostream>
#include <unordered_map>
#include <map>
#include <vector>
using namespace std;

// 找出最长的无重复子数组
pair<int, string> lengthOfLongestSubstring(string s) {
    map<char, int> charIndexMap; // 记录每个字符最后出现的位置
    int maxLength = 0;  // 最长无重复子数组的长度
    int start = 0;      // 当前无重复子数组的起始位置
    int maxStart = 0;   // 最长无重复子数组的起始位置

    // 遍历字符串,end为当前字符的位置
    for (int end = 0; end < s.length(); ++end) {
        // 如果当前字符已经在map中存在
        if (charIndexMap.find(s[end]) != charIndexMap.end()) {
            // 更新start为上一次出现位置的下一个位置
            start = max(start, charIndexMap[s[end]] + 1);
        }
        // 更新当前字符的位置
        charIndexMap[s[end]] = end;
        // 更新最大长度
        int currentLength = end - start + 1;
        if (currentLength > maxLength) {
            maxLength = currentLength;
            maxStart = start;
        }
    }

    return {maxLength, s.substr(maxStart, maxLength)};
}

int main() {
    string input;
    // cout << "请输入一个字符串: ";
    // cin >> input;
    input = "dsiugyhuvcxuuhi";
    auto result = lengthOfLongestSubstring(input);
    cout << "最长无重复子数组的长度为: " << result.first << endl;
    cout << "最长无重复子数组的内容为: " << result.second << endl;

    return 0;
}
