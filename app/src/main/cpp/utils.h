//
// Created by shenbb on 2016/9/24.
//

#ifndef JNITESTDEMO_UTILS_H
#define JNITESTDEMO_UTILS_H

#include <jni.h>

/**
 * 定义用于获取对象的指定签名类型、指定字段名称的基本类型的值的模板方法
 * */
template <typename T> T getObjectBaseTypeFieldValue(JNIEnv* env, jobject instance, const char* fieldName, const char* sign);
//template <typename T>
//T getObjectBaseTypeFieldValue(JNIEnv* env, jobject instance, const char* fieldName, const char* sign){
//    T t = NULL;
//    jclass clazz = env->GetObjectClass(instance);
//
//    //获取字段id
//    jfieldID jFieldId = env->GetFieldID(clazz, fieldName, sign);
//
//    if(strcmp(sign, "I") == 0){
//        t = env->GetIntField(instance, jFieldId);
//    }else if(strcmp(sign, "L") == 0){
//        t = env->GetLongField(instance, jFieldId);
//    }else if(strcmp(sign, "F") == 0){
//        t = env->GetFloatField(instance, jFieldId);
//    }else if(strcmp(sign, "D") == 0){
//        t = env->GetDoubleField(instance, jFieldId);
//    }else if(strcmp(sign, "C") == 0){
//        t = env->GetCharField(instance, jFieldId);
//    }else if(strcmp(sign, "B") == 0){
//        t = env->GetByteField(instance, jFieldId);
//    }else if(strcmp(sign, "Z") == 0){
//        t = env->GetBooleanField(instance, jFieldId);
//    }else if(strcmp(sign, "S") == 0){
//        t = env->GetShortField(instance, jFieldId);
//    }
//    return t;
//}
#endif //JNITESTDEMO_UTILS_H
