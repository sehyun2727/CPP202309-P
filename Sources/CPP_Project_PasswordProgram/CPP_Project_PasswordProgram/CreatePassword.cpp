#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <thread>
#include <chrono>

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
    string InputPassNum() {
        string inPutNum;
        while (1) {

            cout << "답변을 입력하세요: ";
            cin >> inPutNum;

            //단어 길이 제한

            string inPutNumStr = inPutNum;

            if (inPutNumStr.length() < 3) {
                cout << "숫자의의 길이가 너무 짧습니다. 다시 입력해주세요" << endl;
                continue;
            }
            else if (inPutNumStr.length() > 8) {
                cout << "숫자의 길이가 너무 깁니다. 다시 입력해주세요" << endl;
                continue;
            }
           
            //단어 형태 제한
            if (inPutNum == "1234") {
                cout << "\"1234\" 숫자는 사용할 수 없습니다. 다시 입력해주세요" << endl;
                continue;
            }

            // todo: 숫자 맨 앞이 0으로 시작할 경우 0을 살리는 기능
            // -> int형 변수를 string으로 변환하여 해결

            break;
        }
        cout << "입력 : " << inPutNum << endl;

        return inPutNum;
    }
 
  //고객이 입력한 정보를 바탕으로 미리 짜여진 조합 방법을 통해 비밀번호를 제작하는 기능

    //보안성 하
    void CreatePasswordEasy(string inPutWord, string inPutnum) {
        // 문자열과 숫자를 합쳐 비밀번호 제작
        passWord = inPutWord + inPutnum;
    }
    //제작한 비밀번호를 반환하는 함수
    string GetPasswordEasy() {
        return passWord;
    }


    // 보안성 중
    void CreatePasswordMid(string inPutWord, string inPutnum, int wordQuestionNum, int numQuestionNum) {
        // 문자열의 가장 첫번쨰 문자는 대문자로 변환
        string PasswordWord = inPutWord;
        PasswordWord[0] = toupper(inPutWord[0]);
        
        // 문자열 뒷편에 입력받은 숫자 삽입
        string inPutNumStr = inPutnum;
        PasswordWord += inPutNumStr;

        // 입력받은 숫자 뒷편에 선택했던 질문에 해당하는 특수문자를 삽입
        char specialChar1 = '\0';
        char specialChar2 = '\0';

        switch (wordQuestionNum)
        {
        case 1:
            specialChar1 = '!';
            break;
        case 2:
            specialChar1 = '@';
            break;
        case 3:
            specialChar1 = '#';
            break;
        case 4:
            specialChar1 = '$';
            break;
        case 5:
            specialChar1 = '%';
            break;
        default:
            break;
        }
        switch (numQuestionNum)
        {
        case 1:
            specialChar2 = '!';
            break;
        case 2:
            specialChar2 = '@';
            break;
        case 3:
            specialChar2 = '#';
            break;
        case 4:
            specialChar2 = '$';
            break;
        case 5:
            specialChar2 = '%';
            break;
        default:
            break;
        }

        // 특수 문자를 비밀번호에 추가합니다.
        PasswordWord += specialChar1;
        PasswordWord += specialChar2;

        passWord = PasswordWord;
    }
    string GetPasswordMid() {
        return passWord;
    }


    // 숫자 순서를 뒤집어주는 함수
    string reverseInt(string num) {
        string reversed;
        for (int j = num.length() - 1; j >= 0; j--) {
            reversed += num[j];
        }
        return reversed;
    }


    // 보안성 상
    void CreatePasswordHigh(string inPutWord, string inPutnum, int wordQuestionNum, int numQuestionNum) {
        //짝수번째 문자 대문자 변환
        string PasswordWord = inPutWord;
        for (int i = 0; i < inPutWord.length() / 2; i++) {
            PasswordWord[2 * i] = toupper(inPutWord[2 * i]);
        }

        string inPutNumStr = reverseInt(inPutnum);

        PasswordWord += inPutNumStr;

        char specialChar1 = '\0';
        char specialChar2 = '\0';

        switch (wordQuestionNum)
        {
        case 1:
            specialChar1 = '!';
            break;
        case 2:
            specialChar1 = '@';
            break;
        case 3:
            specialChar1 = '#';
            break;
        case 4:
            specialChar1 = '$';
            break;
        case 5:
            specialChar1 = '%';
            break;
        default:
            break;
        }
        switch (numQuestionNum)
        {
        case 1:
            specialChar2 = '!';
            break;
        case 2:
            specialChar2 = '@';
            break;
        case 3:
            specialChar2 = '#';
            break;
        case 4:
            specialChar2 = '$';
            break;
        case 5:
            specialChar2 = '%';
            break;
        default:
            break;
        }

        // 특수 문자를 비밀번호에 추가합니다.
        PasswordWord += specialChar1;
        PasswordWord += specialChar2;

        passWord = PasswordWord;

    }
    string GetPasswordHigh() {
        return passWord;
    }

    void explainPassword(int how) {
        cout << "생성된 비밀번호는 다음과 같은 특징을 가집니다:" << endl;

        switch (how) {
        case 1:
            cout << "- 비밀번호는 입력한 단어와 숫자를 그대로 연결한 형태입니다." << endl;
            break;
        case 2:
            cout << "- 비밀번호는 영문 답변은 대문자로 변환되었고, 숫자 답변과 선택한 질문에 해당하는 특수문자가 추가되었습니다." << endl;
            break;
        case 3:
            cout << "- 비밀번호는 영문 답변의 짝수번째 글자가 대문자로 변환되었고, 숫자 답변은 거꾸로 배치되었으며, 선택한 질문에 해당하는 특수문자가 추가되었습니다." << endl;
            break;
        default:
            break;
        }
    }
};


int main() {
    Password obj;
    string Newpassword;
    //사용자로부터 여러 답변을 받고 저장
    int wordNum = obj.QuestionWord();
    string inPutWord = obj.InputPassword();
    int numNum = obj.QuestionNum();
    string inPutNum = obj.InputPassNum();
    int how;

    //보안수준 선택, 선택된 보안수준에 해당하는 비밀번호 생성
    while (1) {
        cout << "보안수준을 선택하세요. " << endl;
        cout << "1 : 보안수준 하" << endl;
        cout << "2 : 보안수준 중" << endl;
        cout << "3 : 보안수준 상" << endl;
        cout << "보안수준을 선택해주세요(숫자입력) : ";
        cin >> how;
        switch (how)
        {
        case 1:
            obj.CreatePasswordEasy(inPutWord, inPutNum);
            Newpassword = obj.GetPasswordEasy();
            break;
        case 2:
            obj.CreatePasswordMid(inPutWord, inPutNum, wordNum, numNum);
            Newpassword = obj.GetPasswordMid();
            break;
        case 3:
            obj.CreatePasswordHigh(inPutWord, inPutNum, wordNum, numNum);
            Newpassword = obj.GetPasswordHigh();
            break;
        default:
            cout << "유효하지 않은 옵션입니다." << endl;
            continue;
        }
        break;
    }
    
    cout << "비밀번호 생성중입니다.잠시만 기다려주세요." << endl;

    //3초간 로딩
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::seconds(1));  
        cout << " .";
        cout.flush();
        cout << endl;
    }
    cout << endl;

    cout << "완성된 비밀번호 : " << Newpassword << endl;

    cout << "프로그램 종료 0번 비밀번호 설명 1번" << endl;
    int what;
    cin >> what;
    if (what == 1) {
        obj.explainPassword(how);
    }
    else {
        return 0;
    }
    

    return 0;
}

// 한학기 동안 고생많으셨습니다. 좋은 강의 감사드립니다.