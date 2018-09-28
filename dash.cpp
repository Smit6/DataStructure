// #include <iostream>
// #include <string>
//
// using std::cout;
// using std::endl;
// using std::string;
//
// string solution(string S, int k) {
//     int dash = 0;
//     int character = 0;
//     int char_rem = 0;
//     int group = 0;
//     string s = "";
//     string return_str = "";
//     // write your code in C++14 (g++ 6.2.0
//     cout << S.length() << endl;
//     for (unsigned int i = 0; i < S.length(); i++) {
//         if (S[i] == '-') {
//             dash++;
//         } else {
//             s = s + S[i];
//             character++;
//         }
//     }
//     for (unsigned int i = 0; i < s.length(); i++) {
//       if (isalpha(s[i]) && islower(s[i])) {
//         cout << "toupper = " << s[i];
//           s[i] = toupper(s[i]);
//       }
//     }
//     cout << endl;
//     char_rem = character % k;
//     group = character / k;
//     if (char_rem != 0) {
//         group++;
//     }
//     cout << dash << ", "<< char_rem << ", " << group << ".\n";
//
//     if (char_rem == 0) {
//       for (unsigned int i = 0; i < s.length(); i++) {
//           return_str = return_str+s[i];
//           if ((i+1) % k == 0 && s.length() - 1 != i) {
//               return_str = return_str + "-";
//           }
//       }
//     } else {
//       for (int i = 0; i != char_rem; i++) {
//         return_str = return_str + s[i];
//       }
//       return_str = return_str + "-";
//       for (unsigned int i = char_rem; i < s.length(); i++) {
//           return_str = return_str+s[i];
//           if ((i+1 - char_rem) % k == 0 && s.length() - 1 != i) {
//               return_str = return_str + "-";
//           }
//       }
//     }
//     return return_str;
// }
//
// int return_str () {
//     string smit = "smit-1-guddu-2";
//     string return_str = solution(smit , 5);
//     cout << return_str << endl;
//     return 0;
// }



// // includes
// #include <iostream>
// #include <string>
//
// // using statemets
// using std::cout;
// using std::endl;
// using std::string;
//
//
// string solution(string &S, int k) {
//     int dash = 0;
//     int character = 0;
//     int char_rem = 0;
//     int group = 0;
//     string s = "";
//     string return_str = "";
//     // write your code in C++14 (g++ 6.2.0
//     // cout << S.length() << endl;
//     for (unsigned int i = 0; i < S.length(); i++) {
//         if (S[i] == '-') {
//             dash++;
//         } else {
//             s = s + S[i];
//             character++;
//         }
//     }
//     for (unsigned int i = 0; i < s.length(); i++) {
//       if (isalpha(s[i]) && islower(s[i])) {
//         // cout << "toupper = " << toupper(s[i]);
//           s[i] = toupper(s[i]);
//       }
//     }
//     char_rem = character % k;
//     group = character / k;
//     if (char_rem != 0) {
//         group++;
//     }
//     // cout << dash << ", "<< char_rem << ", " << group << ".\n";
//
//     if (char_rem == 0) {
//       for (unsigned int i = 0; i < s.length(); i++) {
//           return_str = return_str+s[i];
//           if ((i+1) % k == 0 && s.length() - 1 != i) {
//               return_str = return_str + "-";
//           }
//       }
//     } else {
//       for (int i = 0; i != char_rem; i++) {
//         return_str = return_str + s[i];
//       }
//       return_str = return_str + "-";
//       for (unsigned int i = char_rem; i < s.length(); i++) {
//           return_str = return_str+s[i];
//           if ((i+1 - char_rem) % k == 0 && s.length() - 1 != i) {
//               return_str = return_str + "-";
//           }
//       }
//     }
//     return return_str;
// }
