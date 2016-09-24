//
// Created by shenbb on 2016/9/24.
//
#include <string.h>
#include "utils.h"
template <typename T>
T getObjectBaseTypeFieldValue(JNIEnv* env, jobject instance, const char* fieldName, const char* sign){
    T t = NULL;
    jclass clazz = env->GetObjectClass(instance);

    //获取字段id
    jfieldID jFieldId = env->GetFieldID(clazz, fieldName, sign);

    if(strcmp(sign, "I") == 0){
        t = env->GetIntField(instance, jFieldId);
    }else if(strcmp(sign, "L") == 0){
        t = env->GetLongField(instance, jFieldId);
    }else if(strcmp(sign, "F") == 0){
        t = env->GetFloatField(instance, jFieldId);
    }else if(strcmp(sign, "D") == 0){
        t = env->GetDoubleField(instance, jFieldId);
    }else if(strcmp(sign, "C") == 0){
        t = env->GetCharField(instance, jFieldId);
    }else if(strcmp(sign, "B") == 0){
        t = env->GetByteField(instance, jFieldId);
    }else if(strcmp(sign, "Z") == 0){
        t = env->GetBooleanField(instance, jFieldId);
    }else if(strcmp(sign, "S") == 0){
        t = env->GetShortField(instance, jFieldId);
    }
    return t;
}


//void test(){}