//#ifndef SRC_UTILS_Tsm2CLASS_H
#define SRC_UTILS_Tsm2CLASS_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "sm2.h"

class sm2Tools
{
public:
    sm2Tools();
    ~sm2Tools();
  void InitializePrivateKey(DWORD KeySize,UCHAR *KeyBytes); //sm2 密钥初始化
    DWORD Onsm2Encrypt(LPVOID InBuffer,DWORD InLength,LPVOID OutBuffer);            //sm2 加密数据
    DWORD Onsm2Uncrypt(LPVOID InBuffer,DWORD InLength,LPVOID OutBuffer);            //sm2 解密数据
    unsigned int extraBytes;
    unsigned int ciphertextLength;


    void FileEncryptor(QString inFileName,QString outFileName);//sm2 加密文件
    void FileDecryptor(QString inFileName,QString outFileName);//sm2 解密文件
private:
    sm2 * m_lpsm2;

    QByteArray OpenFile(QString fileName); //打开指定文件
    void WriteFile(QString fileName,QByteArray data); //将内容data写入到指定的文件内
};
