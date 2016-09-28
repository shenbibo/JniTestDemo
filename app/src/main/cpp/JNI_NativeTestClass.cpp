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

    LOGI(TAG, "enter the nativeShow function");
    jclass clazz = env->GetObjectClass(instance);

    //获取java层的show方法
    jmethodID jmethodShow = env->GetMethodID(clazz, "show", "()V");

    //调用show方法
    env->CallVoidMethod(instance, jmethodShow);

}

extern "C"
JNIEXPORT void JNICALL
Java_bean_NativeTestClass_getAndSetIntArray(JNIEnv *env, jobject instance) {

    LOGI(TAG, "enter the getAndSetIntArray function");
    //获取class对象，使用FindClass获取
    jclass clazz = env->FindClass("bean/NativeTestClass");

    //通过反射获取int[] 字段
    jfieldID numbersId = env->GetFieldID(clazz, "number", "[I");
    jintArray numbersObject = (jintArray) env->GetObjectField(instance, numbersId);
    //获取数组对象的元素
    jint *numbers = env->GetIntArrayElements(numbersObject, NULL);
    //获取数组的长度
    jsize length = env->GetArrayLength(numbersObject);
    //打印数组的值
    LOGI(TAG, "ready to print the java int array elements in native function");
    char* values = NULL;
    for (int i = 0; i < length; ++i) {
        values = new char[128];
        sprintf(values, "number[%d] = %d", i, numbers[i]);
        LOGI(TAG, values);
        delete[] values;
        //设置数组的新值，但是在调用 env->ReleaseIntArrayElements不会反应到Java层生效
        numbers[i] = i + 100;
    }

    //显示数据
    Java_bean_NativeTestClass_nativeShow(env, instance);

    //尝试重新给number指针指向一个新的数组
    //先删除原来分配的内存
    delete[] numbers;

    LOGI(TAG, "read to modify the java int array elements");
    //注意此处即使使用一个大小为5的数组赋值给指向java数组的指针也只有前四个元素生效
    //如果要修改java数组对象指向一个新的数组，则直接使用env->SetObjectField(instance, numbersId, newjintArray);
    jint temp[] = {777, 888, 456, 884, 12347, 9999};
    numbers = temp;
    //注意未调用该方法前，在本地对java数组做的修改还未生效
    env->ReleaseIntArrayElements(numbersObject, numbers, 0);
}

extern "C"
JNIEXPORT void JNICALL
Java_bean_NativeTestClass_getAndSetStringArray(JNIEnv *env, jobject instance, jobjectArray strings) {

    //打印对象数组的元素
    jint length = env->GetArrayLength(strings);
    const char *tempStr = NULL;
    for (int i = 0; i < length; ++i) {
        jstring str = (jstring) env->GetObjectArrayElement(strings, i);
        tempStr = env->GetStringUTFChars(str, NULL);
        LOGI(TAG, tempStr);
        env->ReleaseStringUTFChars(str, tempStr);

        //设置String数组对象的值
        jstring newStr = env->NewStringUTF("newsting +++ ");
        env->SetObjectArrayElement(strings, i, newStr);
    }


}