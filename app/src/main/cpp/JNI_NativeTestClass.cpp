//
// Created by shenbb on 2016/9/23.
//
#include <jni.h>
#include "common.h"
#include <string>
#include "utils.cpp"

#define TAG "NativeTestClass"



extern "C"
JNIEXPORT void JNICALL Java_bean_NativeTestClass_getAndSetField(JNIEnv *env, jobject instance) {


    LOGI(TAG, "enter the getAndSetField function");
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


extern "C"
JNIEXPORT void JNICALL Java_bean_NativeTestClass_getAndSetObjectField(JNIEnv *env, jobject instance) {

    LOGI(TAG, "enter the getAndSetObjectField function");
    jclass clazz = env->GetObjectClass(instance);

    //获取字段user
    jfieldID jFieldUser = env->GetFieldID(clazz, "user", "Lbean/User;");
    jobject jUser = env->GetObjectField(instance, jFieldUser);

    //获取user.id
    jint userId = getObjectBaseTypeFieldValue<jint>(env, jUser, "userId", "I");

    jclass userClazz = env->GetObjectClass(jUser);
    //获取字段user.name
    jfieldID jFieldName = env->GetFieldID(userClazz, "userName", "Ljava/lang/String;");
    //获取String字段值
    jstring name = (jstring) env->GetObjectField(jUser, jFieldName);
    const char* str = env->GetStringUTFChars(name, 0);

    char* tempStr = new char[128];
    sprintf(tempStr, "User.id = %d, User.Name = %s", userId, str);
    LOGI(TAG, tempStr);
    delete[] tempStr;

    //创建一个新的user对象，设置该字段的值
    jmethodID  userConstructor = env->GetMethodID(userClazz, "<init>", "(ILjava/lang/String;)V");
    jobject newUser = env->NewObject(userClazz, userConstructor, 110L, env->NewStringUTF("from the jni new string"));
    env->SetObjectField(instance, jFieldUser, newUser);

    env->ReleaseStringUTFChars(name, str);
}

extern "C"
JNIEXPORT void JNICALL Java_bean_NativeTestClass_nativeShow(JNIEnv *env, jobject instance) {

    LOGI(TAG, "enter the getAndSetObjectField function");
    jclass clazz = env->GetObjectClass(instance);

    //获取java层的show方法
    jmethodID jmethodShow = env->GetMethodID(clazz, "show", "()V");

    //调用show方法
    env->CallVoidMethod(instance, jmethodShow);

}