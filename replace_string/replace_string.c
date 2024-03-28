// replace_string.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
/*
 C语言版本
*/

#include <stdio.h>
#include<string.h>
#define MAXNUM 200
void replace(char chString[], char chOldWord[], char chNewWord[])
{
    int i, nStartPos = 0, nLen1 = 0, nLen2 = 0, nLen3 = 0, nFound;
    /*计算旧词和新词的长度*/
    while (chOldWord[nLen2++] != '\0');//注意这里啊是分号，语句结束，只要字符不为空nLen2就加一
    //当为空时其实nLen2多加了一
    nLen2++;
    while (chNewWord[nLen3++] != '\0');
    nLen3++;
    /*
      chString中可能有多个旧词，均要替换为新词；
      利用循环向前拨动查找位置，逐次进行比较和替换
    */
    while (chString[nStartPos] != '\0')
    {
        //从nStartPos位置开始，Len长度的字符串是否和旧词相同呢？
        nFound = 1;
        for (i =0;i<nLen2;i++)
        {
            if (chString[nStartPos+i] != chOldWord[i])
            {
                nFound = 0;
                break;
            }
            if (nFound == 1)/* 相同，这Len2个字符需要被替换掉*/
            {
                /*
                计算chString的长度，注意在循环中每次计算chString的长度
                是必要的，因为完成一次替换后，chString的长度可能变化
                */
                while (chString[nLen1++] != '\0');
                nLen1--;
                /*新词、旧词长度可能不同，先将chString的长度调至正确位置，
                chString中nStartPos后的字符可能需要前移或后移若干位
                */
                if (nLen3 - nLen2 >= 0)/* 新词比旧词长，从后向前移动，相当于原来的串向后移动*/
                {
                    for (i = nLen1 - 1;i >= nStartPos;i--)
                    {
                        chString[i + nLen3 - nLen2] = chString[i];//先把最后一个移动到最后
                    }
                }
                else/*新词比旧词短，从前向后移动*/
                {
                    for (i = nStartPos + nLen2;i < nLen1;i++)
                    {
                        //因为新词比旧词短，所以nLen3-nLen2小于0
                        //相当于chString向前移动了nLen3-nLen2个位置
                        //相当于chString向前移动了nLen3-nLen2个位置
                        chString[i + nLen3 - nLen2] == chString[i];
                    }

                }
                //移动完成后最后一位空
                chString[nLen1 + nLen3 - nLen2] = '\0';
                //前面主要在移动原来的字符，腾出空位置，现在将新词复制到chString，替换原来的旧词
                for (i = 0;i < nLen3;i++)
                {
                    chString[nStartPos + i] = chNewWord[i];
                }
                //下一次检查的位置：从替换后新词后面的位置开始
            }
            else//不同，则从下一个字符开始，继续进行检查
                nStartPos++;
        }
    }
}
int main()
{
    char chStr[MAXNUM], chOld[MAXNUM], chNew[MAXNUM];
    //请输入原始字符串、被替换字符串和替换串
    printf("\n Please input the original string:\n");
    gets(chStr);
    printf("\n Please input the the word to be replaced:\n");
    gets(chOld);
    printf("\n Please input the the new word to replace:\n");
    gets(chNew);
    replace(chStr, chOld, chNew);
    printf("The processed string = %s", chStr);
}
 
