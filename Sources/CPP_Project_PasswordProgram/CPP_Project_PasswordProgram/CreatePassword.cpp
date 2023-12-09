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
    //���� �Է��� ������ �������� �̸� ¥���� ���� ����� ���� ��й�ȣ�� �����ϴ� ���
    string CreatePassword(string inPutWord, int inPutnum) {
        
    }
    //����ڰ� � ���������� �������� �����ϴ� �Լ�
    int QuestionWord() {
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
    int QuestionNum() {
        int Numnum;

        cout << "===============================" << endl;
        cout << "*** ���� �����Դϴ�. *** " << endl;
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
        string inPutWord;
        while (1) {
            
            cout << "�亯�� �Է��ϼ���: ";
            cin >> inPutWord;

            //�ܾ� ���� ����
            if (inPutWord.size() < 4) {
                cout << "�ܾ��� ���̰� �ʹ� ª���ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }
            else if (inPutWord.size() > 10) {
                cout << "�ܾ��� ���̰� �ʹ� ��ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }

            // �ܾ� ���� ���� ����
            bool involveNum = false;
           
            for (char c : inPutWord) {
                if (isdigit(c)) {
                    involveNum = true;
                    break;
                }
            }
            if (involveNum == true) {
                cout << "�ܾ ���ڰ� ���ԵǾ��ֽ��ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }

            // �ܾ� Ư������ ���� ����
            bool involvespecial = false;
            for (char c : inPutWord) {
                if (!isalnum(c)) {
                    involvespecial = true;
                    break;
                }
            }
            if (involvespecial == true) {
                cout << "�ܾ Ư�����ڰ� ���ԵǾ��ֽ��ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }

            //�ܾ� ���� ����
            if (inPutWord == "password") {
                cout << "\"password\" �ܾ�� ����� �� �����ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }
   
            break;
        }

        return inPutWord;
    }
    int InputPassNum() {
        int inPutNum;
        while (1) {

            cout << "�亯�� �Է��ϼ���: ";
            cin >> inPutNum;

            string inPutNumStr = to_string(inPutNum);

            //�ܾ� ���� ����
            if (inPutNumStr.length() < 3) {
                cout << "�������� ���̰� �ʹ� ª���ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }
            else if (inPutNumStr.length() > 8) {
                cout << "������ ���̰� �ʹ� ��ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }
           
            //�ܾ� ���� ����
            if (inPutNum == 1234) {
                cout << "\"1234\" ���ڴ� ����� �� �����ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }

            //todo : ���ڿ� ���ڰ� ���ԵǾ��ִ��� Ȯ���ϰ� �����ϴ� ���

            //todo : ���� �� ���� 0���� ������ ��� 0�� �츮�� ���

            break;
        }

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
    obj.QuestionWord();
    string inPutWord = obj.InputPassword();
    obj.QuestionNum();
    int inPutNum = obj.InputPassNum();



    cout << inPutWord << " + " << inPutNum;
    
}
