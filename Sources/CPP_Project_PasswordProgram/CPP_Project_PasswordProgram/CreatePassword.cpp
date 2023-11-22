#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Password {
private:
    string passWord;
    
    string inPutWord;
    int inPutNum;
    
public:
    //고객이 입력한 정보를 바탕으로 미리 짜여진 조합 방법을 통해 비밀번호를 제작하는 기능
    string CreatePassword(string inPutWord, int inPutnum) {

    }
    //사용자가 어떤 개인정보를 선택할지 제시하는 함수
    int makeQuestionWord() {
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
    int makeQuestionNum() {
        int Numnum;

        
        cout << "===============================" << endl;
        cout << "*** 숫자 질문입니다. (8자리 날짜 ex) 20231111) *** " << endl;
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
        cout << "답변을 입력하세요: ";
        cin >> inPutWord;
        return inPutWord;
    }
    int InputPassNum() {
        cout << "답변을 입력하세요: ";
        cin >> inPutNum;
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
    obj.makeQuestionWord();
    string inPutWord = obj.InputPassword();
    obj.makeQuestionNum();
    int inPutNum = obj.InputPassNum();

    cout << inPutWord << " + " << inPutNum;
    
}
