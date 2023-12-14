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
        string inPutNumStr = to_string(inPutnum);
        PasswordWord += inPutNumStr;

        // �Է¹��� ���� ���� �����ߴ� ������ �ش��ϴ� Ư�����ڸ� ����
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

        // Ư�� ���ڸ� ��й�ȣ�� �߰��մϴ�.
        PasswordWord += specialChar1;
        PasswordWord += specialChar2;

        passWord = PasswordWord;
    }
    string GetPasswordMid() {
        return passWord;
    }


    // ���� ������ �������ִ� �Լ�
    int reverseInt(int num) {
        int reversed = 0;
        while (num != 0) {
            reversed = reversed * 10 + num % 10;
            num /= 10;
        }
        return reversed;
    }


    // ���ȼ� ��
    void CreatePasswordHigh(string inPutWord, int inPutnum, int wordQuestionNum, int numQuestionNum) {
        //¦����° ���� �빮�� ��ȯ
        string PasswordWord = inPutWord;
        for (int i = 0; i < inPutWord.length() / 2; i++) {
            PasswordWord[2 * i] = toupper(inPutWord[2 * i]);
        }

        int reverseint = reverseInt(inPutnum);
        string inPutNumStr = to_string(reverseint);

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

        // Ư�� ���ڸ� ��й�ȣ�� �߰��մϴ�.
        PasswordWord += specialChar1;
        PasswordWord += specialChar2;

        passWord = PasswordWord;

    }
    string GetPasswordHigh() {
        return passWord;
    }
};


int main() {
    Password obj;
    string Newpassword;
    //����ڷκ��� ���� �亯�� �ް� ����
    int wordNum = obj.QuestionWord();
    string inPutWord = obj.InputPassword();
    int numNum = obj.QuestionNum();
    int inPutNum = obj.InputPassNum();

    //���ȼ��� ����, ���õ� ���ȼ��ؿ� �ش��ϴ� ��й�ȣ ����
    while (1) {
        int how;
        cout << "���ȼ����� �����ϼ���. " << endl;
        cout << "1 : ���ȼ��� ��" << endl;
        cout << "2 : ���ȼ��� ��" << endl;
        cout << "3 : ���ȼ��� ��" << endl;
        cout << "���ȼ����� �������ּ���(�����Է�) : ";
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
            cout << "��ȿ���� ���� �ɼ��Դϴ�." << endl;
            continue;
        }
        break;
    }
    
    cout << "��й�ȣ �������Դϴ�.��ø� ��ٷ��ּ���." << endl;

    //3�ʰ� �ε�
    for (int i = 0; i < 3; ++i) {
        this_thread::sleep_for(chrono::seconds(1));  
        cout << " .";
        cout.flush();
        cout << endl;
    }
    cout << endl;

    cout << "�ϼ��� ��й�ȣ : " << Newpassword << endl;

    return 0;
}
// ������ error : ���� ��� �� �̻��� ���ڰ� �پ ����
// ������ error : Ư�����ڰ� ����� �ȵ�