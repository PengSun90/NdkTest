
#include <android/log.h>
#include <jni.h>

#define  LOG_TAG    "SelfLib"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__


extern "C"
JNIEXPORT void JNICALL
Java_com_example_pengsun_ndktest_MainActivity_selfHello(JNIEnv *env, jobject instance) {

    //获取obj中对象的class对象
    jclass clazz = env->GetObjectClass(instance);
    //获取Java中的number字段的id(最后一个参数是number的签名)
    jfieldID id_number = env->GetFieldID(clazz, "number", "I");
    //获取number的值
    jint number = env->GetIntField(instance, id_number);
    LOGD("from java number is %d", number);
    //修改number的值为100,这里要注意的是jint对应C++是long类型,所以后面要加一个L
    env->SetIntField(instance, id_number, 100L);




    //获取Java中的max方法的id(最后一个参数是max方法的签名)
    jmethodID id_max = env->GetMethodID(clazz, "max", "(II)I");
    //调用max方法
    jint jint1 = env->CallIntMethod(instance, id_max, 1, 3);
    //输出返回值
    LOGD("max value is %d", jint1);


}

