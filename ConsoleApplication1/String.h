#pragma once
#include"stdafx.h"
typedef unsigned char SString[STRING_MAX_SIZE + 1];
int Index(SString S, SString T)
{
	int Len_S = S[0],
		Len_T =T[0];
	
	int indexOfMainStr = 1,
		indexOfSubStr = 1;
	while (indexOfSubStr <= Len_T && indexOfMainStr <= Len_S)
	{
		if (S[indexOfMainStr] == T[indexOfSubStr])//继续比较下一字符
		{
			++indexOfSubStr;
			++indexOfMainStr;
			continue;
		}
		//主指针回退

	}

}
