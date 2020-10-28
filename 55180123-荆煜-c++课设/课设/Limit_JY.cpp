#include "Limit_JY.h"
#include <iostream>
float Limit_JY::numberlimit(float min, float max, int type)
{
	//float num = 0;
	//std::cin >> num;
	////    在输入num是将大小限制在min和max之间
	////    type 0表示必须为整数
	////    type 1表示不需要为整数
	//if (type == 0) {
	//	//          限制为整数
	//	double temp = 1e-5;
	//	int numberlimit_continue = 0;
	//	do {
	//		numberlimit_continue = 0;
	//		if ((num - (int)num < temp) && (num - (int)num > -temp))
	//		{
	//			//是整数
	//			if (num <= max && num >= min)
	//				//                    大小符合要求
	//				return num;
	//			else {
	//				//                    大小不符合要求
	//				do {
	//					printf("输入大小不符合！输入值应在%.0f到%.0f之间，请重新输入：", min, max);
	//					scanf_s("%f", &num);
	//				} while (num<min || num>max);
	//			}
	//		}
	//		else
	//		{
	//			// 不是整数
	//			numberlimit_continue = 1;
	//			printf("输入大小不符合要求！输入值应为整数，请重新输入：");
	//			scanf_s("%f", &num);
	//		}
	//	} while (numberlimit_continue == 1);
	//}
	//else {
	//	//        不需要限制为整数
	//	if (num <= max && num >= min)
	//		//                    大小符合要求
	//		return num;
	//	else {
	//		//                    大小不符合要求
	//		do {
	//			printf("输入大小不符合！输入值应在%.2f到%.2f之间，请重新输入：", min, max);
	//			scanf_s("%f", &num);
	//		} while (num<min || num>max);
	//	}
	//}
	float num = 0.0, temp = 1e-5;
	while (1) {
		if (scanf("%f", &num) == 0 || getchar() != 10) {
			while (getchar() != 10);
			printf("请勿输入非法字符！请重新输入：");
		}
		else {
			if (type == 1) {
				if (min > num || num > max) {
					printf("输入不合规！输入值应在%.2f到%.2f之间，请重新输入：", min, max);
					continue;
				}
				else {
					return num;
				}
			}
			else {
				if (min > num || num > max) {
					printf("输入不合规！输入值应在%.0f到%.0f之间，请重新输入：", min, max);
					continue;
				}
				else {
					if (((num - (int)num) < temp) && ((num - (int)num) > -temp))
						return num;
					printf("输入不合规！请输入整数：");
				}
			}
		}
	}
}
