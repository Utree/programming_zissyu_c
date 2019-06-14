#include <stdio.h>
#include <time.h>


// �萔�錾
#define  COUNT  100000         		// �f�[�^�����w��
#define  INFILE    "07search.txt"		// ���̓t�@�C�����w��


// �v���g�^�C�v�錾
int search_main(int *, int);
void getFile(int *);
double getFuncTime(clock_t, clock_t);

// �T�����C���֐�
int search_main(int *array){    
	// �T���̃f�[�^���i�[
	int result=0;
    	//  �T���̏�����{�֐��Ŏ������邱��
    	// �������܂Ƃ߂����ꍇ�́C�ʊ֐����`���邱��

	// *(array) = 10;			<--   data[0] = 10;�@	�Ɠ���
	// *(array + 10) = 100;		<--   data[10] = 100;	�Ɠ���

	return result;
}


// �v���O�����̃��C���֐�
int main(){
    // �ϐ��錾
    int searchNum;        // �T���̃f�[�^���i�[
    int result;        // �f�[�^�������i�[
    clock_t start,end;      // �J�n���I�����Ԃ��i�[
    int data[COUNT];        // �t�@�C�����̃f�[�^���i�[
    
    // �t�@�C������f�[�^�̓ǂݍ���
    getFile(data);

    printf("�T���������l����͂��ĉ�����\n");
    // �T���f�[�^�̓���


    // �����J�n���Ԃ̐ݒ�
    start = clock();

    // �T���֐��̌ďo��
    result = search_main(data, searchNum);

    // �����I�����Ԃ̐ݒ�
    end = clock();

    // �������ʂ̏o��
   

    /// �����ɂ����������Ԃ̏o��
    printf("--- Search Time is  %.2f sec. ---\n", getFuncTime(start, end));

    return 0;
}


void getFile(int *cur){
    FILE *fp;

    fp = fopen(INFILE, "r");
    while(fscanf(fp,"%d", cur) != EOF){
        cur++;
    }

    fclose(fp);
}

double getFuncTime(clock_t start, clock_t end){
    return (double)(end-start)/CLOCKS_PER_SEC;
}
