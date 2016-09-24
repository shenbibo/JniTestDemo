//
// Created by shenbb on 2016/9/23.
//
#include <jni.h>
#include "common.h"
#include <string>
#define TAG "NativeTestClass"
extern "C"
JNIEXPORT void JNICALL
Java_bean_NativeTestClass_getAndSetField(JNIEnv *env, jobject instance) {


    LOGI(TAG, "enter the testField function");
    jclass clazz = env->GetObjectClass(instance);

    //获取字段id
    jfieldID jFieldId = env->GetFieldID(clazz, "id", "I");
    //获取字段的值
    jint id = env->GetIntField(instance, jFieldId);

    //拼接字符串用于打印
    char str1[128];
    sprintf(str1, "before set id = %d", id);
    LOGI(TAG, str1);

    //设置字段的值
    env->SetIntField(instance, jFieldId, 101L);


    //获取字段String name
    jfieldID jFieldName = env->GetFieldID(clazz, "name", "Ljava/lang/String;");
    //获取String字段值
    jstring  name = (jstring) env->GetObjectField(instance, jFieldName);
    const char* str = env->GetStringUTFChars(name, 0);
//    const char* fix = "before set name = ";
    LOGI(TAG, str);
    env->ReleaseStringUTFChars(name, str);

    //设置name的值，要设置String的值，必须使用NewStringUTF方法进行转换
    env->SetObjectField(instance, jFieldName, env->NewStringUTF("sky_fly"));
}
