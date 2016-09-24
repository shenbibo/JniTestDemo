//
// Created by shenbb on 2016/9/23.
//


#ifndef JNITESTDEMO_COMMON_H
#define JNITESTDEMO_COMMON_H

#include <android/log.h>

//debug
#define LOGD(...) __android_log_print(ANDROID_LOG_DEBUG, __VA_ARGS__, __VA_ARGS__)
//info
#define LOGI(...) __android_log_print(ANDROID_LOG_INFO, __VA_ARGS__, __VA_ARGS__)
//WARN
#define LOGW(...) __android_log_print(ANDROID_LOG_WARM, __VA_ARGS__, __VA_ARGS__)
//ERROR
#define LOGE(...) __android_log_print(ANDROID_LOG_ERROR, __VA_ARGS__, __VA_ARGS__)

#endif //JNITESTDEMO_COMMON_H

