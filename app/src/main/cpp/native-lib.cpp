#include <jni.h>
#include <string>
#include <android/log.h>

#define  LOG_TAG    "MainActivity"
#define  LOGI(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGD(...)  __android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__)
#define LOGE(...)  __android_log_print(ANDROID_LOG_ERROR, LOG_TAG, __VA_ARGS__

extern "C" JNIEXPORT jstring

JNICALL
Java_com_example_pengsun_ndktest_MainActivity_stringFromJNI(JNIEnv *env, jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}

extern "C"
JNIEXPORT void JNICALL
Java_com_example_pengsun_ndktest_MainActivity_sayHello(JNIEnv *env, jobject instance) {


    //获取obj中对象的class对象
    jclass clazz = env->GetObjectClass(instance);
    //获取Java中的number字段的id(最后一个参数是number的签名)
    jfieldID id_number = env->GetFieldID(clazz, "number", "I");
    //获取number的值
    jint number = env->GetIntField(instance, id_number);
    LOGD("from java number is %d", number);
    //修改number的值为100,这里要注意的是jint对应C++是long类型,所以后面要加一个L
    env->SetIntField(instance, id_number, 100L);

}
extern "C"
JNIEXPORT jint JNICALL
Java_com_example_pengsun_ndktest_MainActivity_intFromJNI(JNIEnv *env, jobject instance) {


    return 999;

}

extern "C"
JNIEXPORT jobject JNICALL
Java_com_example_pengsun_ndktest_MainActivity_getPersion(JNIEnv *env, jobject instance, jint a, jfloat b,
                                                  jstring c_) {

    //关于包描述符，这儿可以是 com/feixun/jni/Student 或者是 Lcom/feixun/jni/Student;
    //   这两种类型 都可以获得class引用
    jclass stucls = env->FindClass("com/example/pengsun/ndktest/Persion"); //或得Student类引用

    //获得得该类型的构造函数  函数名为 <init> 返回类型必须为 void 即 V
    jmethodID constrocMID = env->GetMethodID(stucls, "<init>", "(IFLjava/lang/String;)V");

    jstring str = env->NewStringUTF(" come from Native ");

    jobject stu_ojb = env->NewObject(stucls, constrocMID, a, b, c_);  //构造一个对象，调用该类的构造函数，并且传递参数

    return stu_ojb;

}