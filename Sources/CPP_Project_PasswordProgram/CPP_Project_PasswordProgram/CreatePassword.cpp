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
    //���� �Է��� ������ �������� �̸� ¥���� ���� ����� ���� ��й�ȣ�� �����ϴ� ���
    string CreatePassword(string inPutWord, int inPutnum) {

    }
    //����ڰ� � ���������� �������� �����ϴ� �Լ�
    int makeQuestionWord() {
        int Wordnum;

        
        cout << "===============================" << endl;
        cout << "*** ���� �����Դϴ�.(10���� �̳�) ***" << endl;
        cout << "1. ���� ģ�� ģ�� �̸���?" << endl;
        cout << "2. ���� ���� 1ȣ��?" << endl;
        cout << "3. ���� �����ϴ� �ι���?" << endl;
        cout << "4. ���� �ʵ��б��� ����� ������?" << endl;
        cout << "5. ��Ÿ" << endl;
        cout << "===============================" << endl;
        cout << "���� �� �亯 �� ������ ������:  ";
        cin >> Wordnum;
        cout << Wordnum << "���� ���̽��ϴ�." << endl;

        return Wordnum;
    }
    int makeQuestionNum() {
        int Numnum;

        
        cout << "===============================" << endl;
        cout << "*** ���� �����Դϴ�. (8�ڸ� ��¥ ex) 20231111) *** " << endl;
        cout << "1. �θ���� ��ȥ �������?" << endl;
        cout << "2. ����� ������ ������?" << endl;
        cout << "3. ���� �ٴϰ��ִ� ���忡 ó�� �Ի��ϰ� �� ��¥��?" << endl;
        cout << "4. �߾��ϰ� ���� ��¥�� �ִٸ�?" << endl;
        cout << "5. ��Ÿ" << endl;
        cout << "===============================" << endl;
        cout << "���� �� �亯 �� ������ ������ :  ";
        cin >> Numnum;
        cout << Numnum << "���� ���̽��ϴ�." << endl;
        return Numnum;
    }

    //�亯���� �Է¹޴� �Լ�
    string InputPassword() {
        cout << "�亯�� �Է��ϼ���: ";
        cin >> inPutWord;
        return inPutWord;
    }
    int InputPassNum() {
        cout << "�亯�� �Է��ϼ���: ";
        cin >> inPutNum;
        return inPutNum;
    }
  
    //���ڿ��� ���� �迭�� ��ȯ�����ִ� �Լ�
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
