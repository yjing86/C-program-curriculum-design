#include "Limit_JY.h"
#include <iostream>
float Limit_JY::numberlimit(float min, float max, int type)
{
	//float num = 0;
	//std::cin >> num;
	////    ������num�ǽ���С������min��max֮��
	////    type 0��ʾ����Ϊ����
	////    type 1��ʾ����ҪΪ����
	//if (type == 0) {
	//	//          ����Ϊ����
	//	double temp = 1e-5;
	//	int numberlimit_continue = 0;
	//	do {
	//		numberlimit_continue = 0;
	//		if ((num - (int)num < temp) && (num - (int)num > -temp))
	//		{
	//			//������
	//			if (num <= max && num >= min)
	//				//                    ��С����Ҫ��
	//				return num;
	//			else {
	//				//                    ��С������Ҫ��
	//				do {
	//					printf("�����С�����ϣ�����ֵӦ��%.0f��%.0f֮�䣬���������룺", min, max);
	//					scanf_s("%f", &num);
	//				} while (num<min || num>max);
	//			}
	//		}
	//		else
	//		{
	//			// ��������
	//			numberlimit_continue = 1;
	//			printf("�����С������Ҫ������ֵӦΪ���������������룺");
	//			scanf_s("%f", &num);
	//		}
	//	} while (numberlimit_continue == 1);
	//}
	//else {
	//	//        ����Ҫ����Ϊ����
	//	if (num <= max && num >= min)
	//		//                    ��С����Ҫ��
	//		return num;
	//	else {
	//		//                    ��С������Ҫ��
	//		do {
	//			printf("�����С�����ϣ�����ֵӦ��%.2f��%.2f֮�䣬���������룺", min, max);
	//			scanf_s("%f", &num);
	//		} while (num<min || num>max);
	//	}
	//}
	float num = 0.0, temp = 1e-5;
	while (1) {
		if (scanf("%f", &num) == 0 || getchar() != 10) {
			while (getchar() != 10);
			printf("��������Ƿ��ַ������������룺");
		}
		else {
			if (type == 1) {
				if (min > num || num > max) {
					printf("���벻�Ϲ棡����ֵӦ��%.2f��%.2f֮�䣬���������룺", min, max);
					continue;
				}
				else {
					return num;
				}
			}
			else {
				if (min > num || num > max) {
					printf("���벻�Ϲ棡����ֵӦ��%.0f��%.0f֮�䣬���������룺", min, max);
					continue;
				}
				else {
					if (((num - (int)num) < temp) && ((num - (int)num) > -temp))
						return num;
					printf("���벻�Ϲ棡������������");
				}
			}
		}
	}
}
