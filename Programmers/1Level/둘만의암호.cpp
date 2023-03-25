#include <string>
#include <vector>

using namespace std;

string solution(string s, string skip, int index) {
    string answer = "";
    string a;
    
    // skip에 포함되지 않는 모든 문자들로 이루어진 새로운 문자열을 만든다
    for(char c = 'a'; c <= 'z'; c++){
        // string::npos -> 문자열에서 찾는 문자가 없을 때 반환되는 값, skip에 들어있는 문자가 아니면 a 문자열에 추가
        if(skip.find(c) == string::npos){
            a += c;
        }
    }
    
    for(char t : s) {
        // t가 a의 몇 번째 문자인지 계산하고 주어진 index만큼 뒤의 인덱스로 간다. 이 때, a의 인덱스 길이를 넘어갈 수 있으므로 a의 길이로 나눈 나머질르 구하여 다시 a 내의 인덱스 안으로 들어올 수 있게 한다.
        answer += a[(a.find(t) + index)%a.length()];
    }

    return answer;
}
