#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Password {
public:
    string passWord;

public:

    //문자열 질문을 출력하고 어떤 질문에 대답할지 제시하는 함수
    int QuestionWord() {

        int wordNum;

        while (1)
        {
           
            cout << "===============================" << endl;
            cout << "*** 영문 질문입니다.(10글자 이내) ***" << endl;
            cout << "1. 제일 친한 친구 이름은?" << endl;
            cout << "2. 나의 보물 1호는?" << endl;
            cout << "3. 내가 존경하는 인물은?" << endl;
            cout << "4. 내가 초등학교때 들었던 별명은?" << endl;
            cout << "5. 기타" << endl;
            cout << "===============================" << endl;
            cout << "다음 중 답변 할 질문을 고르세요:  ";
            cin >> wordNum;

            if (wordNum > 5) {
                cout << "범위 밖의 질문을 고르셨습니다. 질문을 다시 골라주세요";
                continue;
            }
            break;
        }
        cout << wordNum << "번을 선택하셨습니다.";
        return wordNum;
        
    }
    //숫자 질문을 출력하고 어떤 질문에 대답할지 제시하는 함수
    int QuestionNum() {
        int numNum;

        while (1) {
            cout << "===============================" << endl;
            cout << "*** 숫자 질문입니다. *** " << endl;
            cout << "1. 부모님의 결혼 기념일은?" << endl;
            cout << "2. 가까운 형제의 생일은?" << endl;
            cout << "3. 현재 다니고있는 직장에 처음 입사하게 된 날짜는?" << endl;
            cout << "4. 추억하고 싶은 날짜가 있다면?" << endl;
            cout << "5. 기타" << endl;
            cout << "===============================" << endl;
            cout << "다음 중 답변 할 질문을 고르세요 :  ";
            cin >> numNum;

            if (numNum > 5) {
                cout << "범위 밖의 질문을 고르셨습니다. 질문을 다시 골라주세요";
                continue;
            }
            break;
        }
        cout << numNum << "번을 선택하셨습니다.";
        return numNum;
    }

    //문자열 답변을 입력받는 함수
    string InputPassword() {
        string inPutWord;
        while (1) {
            
            cout << "답변을 입력하세요: ";
            cin >> inPutWord;

            if (inPutWord.empty()) {
                cout << "답변하지 않으셨습니다. 다시 입력해주세요" << endl;
                continue;
            }

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
            
            cout << "입력 : " << inPutWord << endl;

            break;
        }

        return inPutWord;
    }
    // 숫자 답변을 입력받는 함수
    int InputPassNum() {
        int inPutNum;
        while (1) {

            cout << "답변을 입력하세요: ";
            cin >> inPutNum;

            

            //단어 길이 제한

            string inPutNumStr = to_string(inPutNum);

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
        cout << "입력 : " << inPutNum << endl;

        return inPutNum;
    }
 
  //고객이 입력한 정보를 바탕으로 미리 짜여진 조합 방법을 통해 비밀번호를 제작하는 기능
    

    //보안성 하
    void CreatePasswordEasy(string inPutWord, int inPutnum) {
        // 문자열과 숫자를 합쳐 비밀번호 제작
        passWord = inPutWord + to_string(inPutnum);
    }
    //제작한 비밀번호를 반환하는 함수
    string GetPasswordEasy() {
        return passWord;
    }


    // 보안성 중
    void CreatePasswordMid(string inPutWord, int inPutnum, int wordQuestionNum, int numQuestionNum) {
        // 문자열의 가장 첫번쨰 문자는 대문자로 변환
        string PasswordWord = inPutWord;
        PasswordWord[0] = toupper(inPutWord[0]);

        // 문자열 뒷편에 입력받은 숫자 삽입
        for (int i = 0; i < inPutnum; i++) {
            PasswordWord += to_string(inPutnum);
        }

        // 입력받은 숫자 뒷편에 선택했던 질문에 해당하는 특수문자를 삽입
        char specialChar1;
        char specialChar2;

        switch (wordQuestionNum)
        {
        case 1:
            specialChar1 = '!';
        case 2:
            specialChar1 = '@';
        case 3:
            specialChar1 = '#';
        case 4:
            specialChar1 = '$';
        case 5:
            specialChar1 = '%';
        default:
            break;
        }
        switch (numQuestionNum)
        {
        case 1:
            specialChar2 = '!';
        case 2:
            specialChar2 = '@';
        case 3:
            specialChar2 = '#';
        case 4:
            specialChar2 = '$';
        case 5:
            specialChar2 = '%';
        default:
            break;
        }

        PasswordWord += to_string(specialChar1);
        PasswordWord += to_string(specialChar2);

        passWord = PasswordWord;
    }
    string GetPasswordMid() {
        return passWord;
    }


    // 보안성 상
    void CreatePasswordHigh(string inPutWord, int inPutnum, int wordNum, int numNum) {

    }
    string GetPasswordHigh() {

    }
};


int main() {
    Password obj;

    int wordNum = obj.QuestionWord();
    string inPutWord = obj.InputPassword();
    int numNum = obj.QuestionNum();
    int inPutNum = obj.InputPassNum();



    cout << inPutWord << " + " << inPutNum;
    
}
