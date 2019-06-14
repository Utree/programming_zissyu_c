#include <stdio.h>
#include <time.h>


// �萔�錾
#define  COUNT  100000         		// �f�[�^�����w��
#define  INFILE    "08sort.txt"		// ���̓t�@�C�����w��
#define  SORTFILE  "out.txt"   		// �o�̓t�@�C�����w��


// �v���g�^�C�v�錾
void sort_main(int *);
void getFile(int *);
void outFile(int *);
double getFuncTime(clock_t, clock_t);


// �\�[�g�i���ёւ��j���C���֐�
void sort_main(int *array){    

    // �\�[�g�i���ёւ��j�̏�����{�֐��Ŏ������邱��
    // �������܂Ƃ߂����ꍇ�́C�ʊ֐����`���邱��

	// *(array) = 10;			<--   data[0] = 10;�@	�Ɠ���
	// *(array + 10) = 100;		<--   data[10] = 100;	�Ɠ���
}


// �v���O�����̃��C���֐�
int main(){
    // �ϐ��錾
    clock_t start,end;      // �J�n���I�����Ԃ��i�[
    int data[COUNT];        // �t�@�C�����̃f�[�^���i�[
    
    // �t�@�C������f�[�^�̓ǂݍ���
    getFile(data);

    // �����J�n���Ԃ̐ݒ�
    start = clock();

    // �\�[�g�֐��̌ďo��
    sort_main(data);

    // �����I�����Ԃ̐ݒ�
    end = clock();

    /// �����ɂ����������Ԃ̏o��
    printf("--- Sort Time is  %.2f sec. ---\n", getFuncTime(start, end));

    // �z��ɕۑ����ꂽ�f�[�^�̊i�[
    outFile(data);
}


void getFile(int *cur){
    FILE *fp;

    fp = fopen(INFILE, "r");
    while(fscanf(fp,"%d", cur) != EOF){
        cur++;
    }

    fclose(fp);
}

void outFile(int *cur){
    FILE *fp;
    int i;

    fp = fopen(SORTFILE, "w");
   
    for(i=0; i<COUNT; i++){
        fprintf(fp, "%d\n", *(cur+i));
    }

    fclose(fp);
} 


double getFuncTime(clock_t start, clock_t end){
    return (double)(end-start)/CLOCKS_PER_SEC;
}

