#include <iostream>
using namespace std;


// ����N���X
class MyClass {
public:
	void /*�X�V�֐�*/();

	void /*��Ԋ֐�1*/();
	void /*��Ԋ֐�2*/();
	void /*��Ԋ֐�3*/();

	// �����o�֐��|�C���^�̃e�[�u��
	static void (MyClass:: *table[])();

private:
	// �����o�֐��|�C���^�̃e�[�u�����Q�Ƃ���C���f�b�N�X
	int index = 0;
};

void MyClass::/*��Ԋ֐�1*/() {
	cout << "�G�̐ڋ߁I" << endl;
}

void MyClass::/*��Ԋ֐�2*/() {
	cout << "�G�̍U���I" << endl;
}

void MyClass::/*��Ԋ֐�3*/() {
	cout << "�G�̌�ށI" << endl;
}

void MyClass::/*�X�V�֐�*/() {

	// �֐��|�C���^�̃e�[�u������֐������s
	(this->*table[index])();

	if (/*�X�y�[�X�����ꂽ�H*/) {
		/*�G�̏�ԁi�֐��|�C���^�z��̃C���f�b�N�X�j��+1*/
		/*�C���f�b�N�X���z��̍Ō�̗v�f�Ȃ瑼�̒l������*/
	}
}

// static�Ő錾���������o�֐��|�C���^�e�[�u���̎���
void (MyClass:: *MyClass::table[])() = {
  &MyClass::/*��Ԋ֐�1�̖��O*/, // �C���f�b�N�X�ԍ�0
  &MyClass::/*��Ԋ֐�2�̖��O*/, // �C���f�b�N�X�ԍ�1
  &MyClass::/*��Ԋ֐�3�̖��O*/  // �C���f�b�N�X�ԍ�2
};


int main()
{
	MyClass my;

	my.Update();

	return 0;
}