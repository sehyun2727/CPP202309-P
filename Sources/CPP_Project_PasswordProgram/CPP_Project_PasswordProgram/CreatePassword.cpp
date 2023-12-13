#include <iostream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

class Password {
public:
    string passWord;

public:

    //���ڿ� ������ ����ϰ� � ������ ������� �����ϴ� �Լ�
    int QuestionWord() {

        int wordNum;

        while (1)
        {
           
            cout << "===============================" << endl;
            cout << "*** ���� �����Դϴ�.(10���� �̳�) ***" << endl;
            cout << "1. ���� ģ�� ģ�� �̸���?" << endl;
            cout << "2. ���� ���� 1ȣ��?" << endl;
            cout << "3. ���� �����ϴ� �ι���?" << endl;
            cout << "4. ���� �ʵ��б��� ����� ������?" << endl;
            cout << "5. ��Ÿ" << endl;
            cout << "===============================" << endl;
            cout << "���� �� �亯 �� ������ ������:  ";
            cin >> wordNum;

            if (wordNum > 5) {
                cout << "���� ���� ������ ���̽��ϴ�. ������ �ٽ� ����ּ���";
                continue;
            }
            break;
        }
        cout << wordNum << "���� �����ϼ̽��ϴ�.";
        return wordNum;
        
    }
    //���� ������ ����ϰ� � ������ ������� �����ϴ� �Լ�
    int QuestionNum() {
        int numNum;

        while (1) {
            cout << "===============================" << endl;
            cout << "*** ���� �����Դϴ�. *** " << endl;
            cout << "1. �θ���� ��ȥ �������?" << endl;
            cout << "2. ����� ������ ������?" << endl;
            cout << "3. ���� �ٴϰ��ִ� ���忡 ó�� �Ի��ϰ� �� ��¥��?" << endl;
            cout << "4. �߾��ϰ� ���� ��¥�� �ִٸ�?" << endl;
            cout << "5. ��Ÿ" << endl;
            cout << "===============================" << endl;
            cout << "���� �� �亯 �� ������ ������ :  ";
            cin >> numNum;

            if (numNum > 5) {
                cout << "���� ���� ������ ���̽��ϴ�. ������ �ٽ� ����ּ���";
                continue;
            }
            break;
        }
        cout << numNum << "���� �����ϼ̽��ϴ�.";
        return numNum;
    }

    //���ڿ� �亯�� �Է¹޴� �Լ�
    string InputPassword() {
        string inPutWord;
        while (1) {
            
            cout << "�亯�� �Է��ϼ���: ";
            cin >> inPutWord;

            if (inPutWord.empty()) {
                cout << "�亯���� �����̽��ϴ�. �ٽ� �Է����ּ���" << endl;
                continue;
            }

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
            
            cout << "�Է� : " << inPutWord << endl;

            break;
        }

        return inPutWord;
    }
    // ���� �亯�� �Է¹޴� �Լ�
    int InputPassNum() {
        int inPutNum;
        while (1) {

            cout << "�亯�� �Է��ϼ���: ";
            cin >> inPutNum;

            

            //�ܾ� ���� ����

            string inPutNumStr = to_string(inPutNum);

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
        cout << "�Է� : " << inPutNum << endl;

        return inPutNum;
    }
 
  //���� �Է��� ������ �������� �̸� ¥���� ���� ����� ���� ��й�ȣ�� �����ϴ� ���
    

    //���ȼ� ��
    void CreatePasswordEasy(string inPutWord, int inPutnum) {
        // ���ڿ��� ���ڸ� ���� ��й�ȣ ����
        passWord = inPutWord + to_string(inPutnum);
    }
    //������ ��й�ȣ�� ��ȯ�ϴ� �Լ�
    string GetPasswordEasy() {
        return passWord;
    }


    // ���ȼ� ��
    void CreatePasswordMid(string inPutWord, int inPutnum, int wordQuestionNum, int numQuestionNum) {
        // ���ڿ��� ���� ù���� ���ڴ� �빮�ڷ� ��ȯ
        string PasswordWord = inPutWord;
        PasswordWord[0] = toupper(inPutWord[0]);

        // ���ڿ� ���� �Է¹��� ���� ����
        for (int i = 0; i < inPutnum; i++) {
            PasswordWord += to_string(inPutnum);
        }

        // �Է¹��� ���� ���� �����ߴ� ������ �ش��ϴ� Ư�����ڸ� ����
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


    // ���ȼ� ��
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
