/* PRESET CODE BEGIN - NEVER TOUCH CODE BELOW */

#include <stdio.h>
//按照题给格式读入矩阵matrix
void matrix_scanf(double matrix[3][3]);
//按照题给格式输出矩阵matrix
void matrix_print(double matrix[3][3]);
//交换矩阵的第h1行和第h2行（从0开始数）
void matrix_operate1(double matrix[3][3],int h1,int h2);
//将矩阵的第h行同乘以x
void matrix_operate2(double matrix[3][3],int h,double x);
//将矩阵的第h1行的k倍加到第h2行
void matrix_operate3(double matrix[3][3],int h1,double k,int h2);
//将矩阵old_matrix拷贝一份，保存到new_matrix中
void matrix_copy(double new_matrix[3][3],double old_matrix[3][3]);
//求两个方阵的和，并将结果存到matrix中
//请完成该函数 
void matrix_add(double matrix[3][3],double other[3][3]);
//求两个方阵的差，并将结果存到matrix中
//请完成该函数 
void matrix_subtract(double matrix[3][3],double other[3][3]);
//求两个方阵的乘积，并将结果存到matrix中
//请完成该函数 
void matrix_multiply(double matrix[3][3],double other[3][3]);
//用快速幂的思想，求方阵的幂（快速幂），并存到matrix中
//请完成该函数 
void matrix_power(double matrix[3][3],int left_index);
//求matrix的逆矩阵，并将结果存到matrix中
//请完成该函数 
void matrix_inverse(double matrix[3][3]);
int main()
{
    int i,j;
    double matrix[3][3];
    char operator;
    matrix_scanf(matrix);
    while (1)
    {
        while (getchar()!='\n');
        operator=getchar();
        if (operator=='+')
        {
            double other[3][3];
            matrix_scanf(other);
            matrix_add(matrix,other);
        }
        else if (operator=='-')
        {
            double other[3][3];
            matrix_scanf(other);
            matrix_subtract(matrix,other);
        }
        else if (operator=='*')
        {
            double other[3][3];
            matrix_scanf(other);
            matrix_multiply(matrix,other);
        }
        else if (operator=='^')
        {
            int index;
            scanf("%d",&index);
            if (index>0)
                matrix_power(matrix,index);
            else if (index<0)
            {
                matrix_inverse(matrix);
                matrix_power(matrix,-index);
            }
        }
        else
            break;
        printf("Result:\n");
        matrix_print(matrix);
    }
    return 0;
}
void matrix_scanf(double matrix[3][3])
{
    int i,j;
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
            scanf("%lf",&matrix[i][j]);
}
void matrix_print(double matrix[3][3])
{
    int i,j;
    for (i=0;i<3;i++)
    {
        for (j=0;j<3;j++)
		{if(j==2)printf("%.2lf\n",matrix[i][j]);
		else	printf("%.2lf ",matrix[i][j]);}
    }
}
void matrix_operate1(double matrix[3][3],int h1,int h2)
{
    int i;
    double tmp;
    for (i=0;i<3;i++)
        tmp=matrix[h1][i],matrix[h1][i]=matrix[h2][i],matrix[h2][i]=tmp;
}
void matrix_operate2(double matrix[3][3],int h,double x)
{
    int i;
    for (i=0;i<3;i++)
        matrix[h][i]*=x;
}
void matrix_operate3(double matrix[3][3],int h1,double k,int h2)
{
    int i;
    for (i=0;i<3;i++)
        matrix[h2][i]+=matrix[h1][i]*k;
}
void matrix_copy(double new_matrix[3][3],double old_matrix[3][3])
{
    int i,j;
    for (i=0;i<3;i++)
        for (j=0;j<3;j++)
            new_matrix[i][j]=old_matrix[i][j];
}

/* PRESET CODE END - NEVER TOUCH CODE ABOVE */

//double quick_power(double base, int index)
//{
//	if(index == 1)
//		return base;
//	else if(index&1)
//		return base*quick_power(base*base, index/2);
//	else
//		return quick_power(base*base, index/2);
//}

//void swap(void *a, void *b)
//{
//	double temp;
//	temp = *(double*)a;
//	*(double*)a = *(double*)b;
//	*(double*)b = temp;
//}

void matrix_add(double matrix[3][3],double other[3][3])
{
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			matrix[i][j] += other[i][j];
	return;
}

void matrix_subtract(double matrix[3][3],double other[3][3])
{
	int i, j;
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			matrix[i][j] -= other[i][j];
	return;
}

void matrix_multiply(double matrix[3][3],double other[3][3])
{
//	printf("要相乘的两个矩阵分别为：\n");
//	int i, j, k;
//	for(i = 0; i < 3; i++)
//	{
//		for(j = 0; j < 3; j++)
//		{
//			printf("%.2lf ", matrix[i][j]);
//		}
//		printf("\n");
//	}	
//	printf("和\n");
//	for(i = 0; i < 3; i++)
//	{
//		for(j = 0; j < 3; j++)
//		{
//			printf("%.2lf ", other[i][j]);
//		}
//		printf("\n");
//	}	
	int i, j, k;
	double temp[3][3] = {0};
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			for(k = 0; k < 3; k++)
				temp[i][j] += matrix[i][k]*other[k][j];
//	printf("相乘后的结果为：\n");
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			matrix[i][j] = temp[i][j];
//			printf("%.2lf ", matrix[i][j]);
		}
//		printf("\n");
	}
	return;
}

void matrix_power(double matrix[3][3],int left_index)
{
//	printf("此时次数为： %d\n要处理的矩阵为：\n", left_index);
	int i, j;
//	for(i = 0; i < 3; i++)
//	{
//		for(j = 0; j < 3; j++)
//		{
//			printf("%.2lf ", matrix[i][j]);
//		}
//		printf("\n");
//	}
	if(left_index == 1)
		return;
	else if(left_index&1)
	{
		double matrix_temp[3][3];
//		printf("matrix_temp值为：\n");
		for(i = 0; i < 3; i++)
		{
			for(j = 0;j < 3; j++)
			{
				matrix_temp[i][j] = matrix[i][j];
//				printf("%.2lf ", matrix_temp[i][j]);
			}
//			printf("\n");
		}
		matrix_multiply(matrix,matrix);
		matrix_power(matrix, left_index>>1);		
		matrix_multiply(matrix,matrix_temp);
	}
	else
	{
		matrix_multiply(matrix,matrix);
		matrix_power(matrix, left_index>>1);				
	}	
}

void matrix_inverse(double matrix[3][3])
{
	int i, j, k, l;
	double adjoint_matrix[3][3], minor[2][2], determinant_matrix, *p;
	determinant_matrix = matrix[0][0]*matrix[1][1]*matrix[2][2]+matrix[0][1]*matrix[1][2]*matrix[2][0]+matrix[0][2]*matrix[1][0]*matrix[2][1]-
						 matrix[0][2]*matrix[1][1]*matrix[2][0]-matrix[0][1]*matrix[1][0]*matrix[2][2]-matrix[0][0]*matrix[1][2]*matrix[2][1];
//	printf("行列式的值为：\n%lf\n伴随矩阵的值为：\n", determinant_matrix);
	for(i = 0; i < 3; i++)
	{
		for(j = 0; j < 3; j++)
		{
			p = &minor[0][0];
			for(k = 0; k < 3; k++)
				for(l = 0; l < 3; l++)
					if(k != i && l != j)
						*p++ = matrix[k][l];
//			printf("余子式为：\n");
//			for(k = 0; k < 2; k++)
//			{
//				for(l = 0; l < 2; l++)
//					printf("%lf ", minor[k][l]);
//				printf("\n");
//			}
			adjoint_matrix[i][j] = (((i+j)&1)?(-1):1)*(minor[0][0]*minor[1][1]-minor[0][1]*minor[1][0]);
//			printf("%lf ", adjoint_matrix[i][j]);
		}
//		printf("\n");
	}
	for(i = 0; i < 3; i++)
		for(j = 0; j < 3; j++)
			matrix[j][i] = adjoint_matrix[i][j]/determinant_matrix;
	return;
}

//教训1：请再次复习一下swap的写法！两次使用*：*(double*)，含义不同！
//教训2：可以学习一下标准的快速幂算法；