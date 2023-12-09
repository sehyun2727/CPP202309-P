#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Password {
public:
    string passWord;
    
    string inPutWord;
    int inPutNum;
    
public:
    //고객이 입력한 정보를 바탕으로 미리 짜여진 조합 방법을 통해 비밀번호를 제작하는 기능
    string CreatePassword(string inPutWord, int inPutnum) {
        
    }
    //사용자가 어떤 개인정보를 선택할지 제시하는 함수
    int QuestionWord() {
        int Wordnum;

        
        cout << "===============================" << endl;
        cout << "*** 영문 질문입니다.(10글자 이내) ***" << endl;
        cout << "1. 제일 친한 친구 이름은?" << endl;
        cout << "2. 나의 보물 1호는?" << endl;
        cout << "3. 내가 존경하는 인물은?" << endl;
        cout << "4. 내가 초등학교때 들었던 별명은?" << endl;
        cout << "5. 기타" << endl;
        cout << "===============================" << endl;
        cout << "다음 중 답변 할 질문을 고르세요:  ";
        cin >> Wordnum;
        cout << Wordnum << "번을 고르셨습니다." << endl;

        return Wordnum;
    }
    int QuestionNum() {
        int Numnum;

        cout << "===============================" << endl;
        cout << "*** 숫자 질문입니다. *** " << endl;
        cout << "1. 부모님의 결혼 기념일은?" << endl;
        cout << "2. 가까운 형제의 생일은?" << endl;
        cout << "3. 현재 다니고있는 직장에 처음 입사하게 된 날짜는?" << endl;
        cout << "4. 추억하고 싶은 날짜가 있다면?" << endl;
        cout << "5. 기타" << endl;
        cout << "===============================" << endl;
        cout << "다음 중 답변 할 질문을 고르세요 :  ";
        cin >> Numnum;
        cout << Numnum << "번을 고르셨습니다." << endl;
        return Numnum;
    }

    //답변을를 입력받는 함수
    string InputPassword() {
        string inPutWord;
        while (1) {
            
            cout << "답변을 입력하세요: ";
            cin >> inPutWord;

            //단어 길이 제한
            if (inPutWord.size() < 4) {
                cout << "단어의 길이가 너무 짧습니다. 다시 입력해주세요" << endl;
                continue;
            }
            else if (inPutWord.size() > 10) {
                cout << "단어의 길이가 너무 깁니다. 다시 입력해주세요" << endl;
                continue;
            }

            // 단어 숫자 포함 제한
            bool involveNum = false;
           
            for (char c : inPutWord) {
                if (isdigit(c)) {
                    involveNum = true;
                    break;
                }
            }
            if (involveNum == true) {
                cout << "단어에 숫자가 포함되어있습니다. 다시 입력해주세요" << endl;
                continue;
            }

            // 단어 특수문자 포함 제한
            bool involvespecial = false;
            for (char c : inPutWord) {
                if (!isalnum(c)) {
                    involvespecial = true;
                    break;
                }
            }
            if (involvespecial == true) {
                cout << "단어에 특수문자가 포함되어있습니다. 다시 입력해주세요" << endl;
                continue;
            }

            //단어 형태 제한
            if (inPutWord == "password") {
                cout << "\"password\" 단어는 사용할 수 없습니다. 다시 입력해주세요" << endl;
                continue;
            }
   
            break;
        }

        return inPutWord;
    }
    int InputPassNum() {
        int inPutNum;
        while (1) {

            cout << "답변을 입력하세요: ";
            cin >> inPutNum;

            string inPutNumStr = to_string(inPutNum);

            //단어 길이 제한
            if (inPutNumStr.length() < 3) {
                cout << "숫자의의 길이가 너무 짧습니다. 다시 입력해주세요" << endl;
                continue;
            }
            else if (inPutNumStr.length() > 8) {
                cout << "숫자의 길이가 너무 깁니다. 다시 입력해주세요" << endl;
                continue;
            }
           
            //단어 형태 제한
            if (inPutNum == 1234) {
                cout << "\"1234\" 숫자는 사용할 수 없습니다. 다시 입력해주세요" << endl;
                continue;
            }

            //todo : 숫자에 문자가 포함되어있는지 확인하고 제한하는 기능

            //todo : 숫자 맨 앞이 0으로 시작할 경우 0을 살리는 기능

            break;
        }

        return inPutNum;
    }
  
    //문자열을 문자 배열로 변환시켜주는 함수
    const char* SwitchStringToCharArray(string inPut) {
        inPutWord = inPut;
        return inPutWord.c_str();
    }

};


int main() {
    Password obj;
    obj.QuestionWord();
    string inPutWord = obj.InputPassword();
    obj.QuestionNum();
    int inPutNum = obj.InputPassNum();



    cout << inPutWord << " + " << inPutNum;
    
}
