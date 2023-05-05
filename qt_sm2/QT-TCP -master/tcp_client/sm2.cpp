void AesTools::FileEncryptor(QString inFileName,QString outFileName) {

    QByteArray temp = OpenFile(inFileName);
    //qDebug()<<"temp:"<<temp;
    char mingwen[102400] ;

    //将temp字节数组中的所有数据复制给mingwen数组
    memcpy(mingwen,temp.data(),temp.size());

    //DWORD size = strlen(mingwen);
    //qDebug()<<"size:"<<size;
    char miwen[102400]={0};
    UCHAR key[102400] = "xyz";
    UCHAR *p = key;
    InitializePrivateKey(16, p); //进行初始化

    OnAesEncrypt((LPVOID)mingwen, strlen(mingwen), (LPVOID)miwen); //进行加密
    //qDebug()<<miwen;
    QByteArray miwenData;
    DWORD byteSize = 0;
    //将密文的前四个字符复制给bytesize的地址
    memcpy(&byteSize,miwen,4);
    //qDebug()<<"bytesize:"<<byteSize;
    miwenData.resize(byteSize+16);
    //将密文的前byteSize+16个字符复制给miwenDate
    memcpy(miwenData.data(),miwen,byteSize+16);

    WriteFile(outFileName,miwenData);

    return ;
}


void AesTools::FileDecryptor(QString inFileName,QString outFileName){

    QByteArray temp = OpenFile(inFileName);

    char miwen[1024]={0};
    char jiemi[1024]={0};
    //将temp字节数组中的所有数据复制给miwen char类型数组
    memcpy(miwen,temp.data(),temp.size());
    DWORD byteSize = 0;
    //miwen的大小存放在miwen的前四个字节中，将miwen大小赋值给byteSize
    memcpy(&byteSize,miwen,4);
    UCHAR key[1024] = "xyz";
    UCHAR *p = key;
    InitializePrivateKey(16, p); //进行初始化
    OnAesUncrypt((LPVOID)miwen, (DWORD)byteSize,(LPVOID)jiemi); //进行解密

    //解密结果写入文件中
    WriteFile(outFileName,jiemi);

    return ;
}

void sm2()
{
    printf("test_sm2()\n");
    unsigned char data[] = "Hello World!";
    char *pemPri         = NULL;
    char *pemPub         = NULL;
    // 生成密钥对
    EC_KEY *key = GM_SM2_key_new();
    if (key != NULL)
    {
        // 编码私钥
        if (GM_SM2_key_encode(&pemPri, key, 1) == SUCCESS)
        {
            printf("%s\n", pemPri);
        }
        // 编码公钥
        if (GM_SM2_key_encode(&pemPub, key, 0) == SUCCESS)
        {
            printf("%s\n", pemPub);
        }

        GM_SM2_key_free(key);
        key = NULL;
    }

    unsigned char *enc_data = NULL;
    size_t enc_len          = 0;
    // 解码公钥并加密
    if (GM_SM2_key_decode(&key, pemPub, 0) == SUCCESS &&
        GM_SM2_encrypt(&enc_data, &enc_len, data, sizeof(data), key) == SUCCESS)
    {
        printf("enc_data=%d,", enc_len);
        print_hex(enc_data, enc_len);
        printf("\n");

        GM_SM2_key_free(key);
        key = NULL;

        unsigned char *dec_data = NULL;
        size_t dec_len          = 0;
        // 解码私钥并解密
        if (GM_SM2_key_decode(&key, pemPri, 1) == SUCCESS &&
            GM_SM2_decrypt(&dec_data, &dec_len, enc_data, enc_len, key) == SUCCESS)
        {
            printf("dec_data=%d,%.*s\n", dec_len, dec_len, dec_data);

            GM_SM2_key_free(key);
            key = NULL;
            free(dec_data);
            dec_data = NULL;
        }

        free(enc_data);
        enc_data = NULL;
    }

    unsigned char *sig   = NULL;
    size_t sig_len       = 0;
    unsigned char id[16] = {0};
    // 解码私钥并签名
    if (GM_SM2_key_decode(&key, pemPri, 1) == SUCCESS &&
        GM_SM2_sign(&sig, &sig_len, data, sizeof(data), id, key) == SUCCESS)
    {
        printf("sig=%d,", sig_len);
        print_hex(sig, sig_len);
        printf("\n");

        GM_SM2_key_free(key);
        key = NULL;

        // 解码公钥并验签
        if (GM_SM2_key_decode(&key, pemPub, 0) == SUCCESS)
        {
            int verified = GM_SM2_verify(sig, sig_len, data, sizeof(data), id, key);
            printf("verified=%d\n", verified);

            GM_SM2_key_free(key);
            key = NULL;
        }

        free(sig);
        sig = NULL;
    }

    free(pemPri);
    pemPri = NULL;
    free(pemPub);
    pemPub = NULL;
}


void FileEncryptor(QString inFileName,QString outFileName)
{
     
    QByteArray temp = OpenFile(inFileName);
    //qDebug()<<"temp:"<<temp;
    char mingwen[102400] ;

    //将temp字节数组中的所有数据复制给mingwen数组
    memcpy(mingwen,temp.data(),temp.size());

    //DWORD size = strlen(mingwen);
    //qDebug()<<"size:"<<size;
    char miwen[102400]={0};
    UCHAR key[102400] = "xyz";
    UCHAR *p = key;
    InitializePrivateKey(16, p); //进行初始化

    OnAesEncrypt((LPVOID)mingwen, strlen(mingwen), (LPVOID)miwen); //进行加密
    
    //qDebug()<<miwen;
    QByteArray miwenData;
    DWORD byteSize = 0;
    //将密文的前四个字符复制给bytesize的地址
    memcpy(&byteSize,miwen,4);
    //qDebug()<<"bytesize:"<<byteSize;
    miwenData.resize(byteSize+16);
    //将密文的前byteSize+16个字符复制给miwenDate
    memcpy(miwenData.data(),miwen,byteSize+16);

    WriteFile(outFileName,miwenData);

    return ;
}