
//
// Opcodes
//

#ifndef _PROTOCOL_H
#define _PROTOCOL_H

#pragma pack(1)
enum CommandType
{
    CT_Test = 1,
    ST_Test,
    CT_Login,
    ST_Login,
    CT_GetVersion,
    ST_GetVersion,
    CT_GetUpdateContent,
    ST_GetUpdateContent,
};

///////////////////

typedef struct sSubmitData
{
	unsigned int cLen;          //数据长度
	enum CommandType cType;     //数据编号
	void *cData() {             //指向数据的指针
		return this+1;
	}; 	
} MSG_HEAD;


#define MSG_HEAD_LEN sizeof(struct sSubmitData)

#pragma pack()

#endif //_PROTOCOL_H
