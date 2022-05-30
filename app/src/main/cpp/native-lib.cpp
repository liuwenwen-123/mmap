#include <jni.h>
#include <string>
#include <sys/mman.h>

#include <fcntl.h>
#include <unistd.h>
#include <sys/stat.h>

int8_t *m_ptr;
extern "C" JNIEXPORT jstring JNICALL

Java_com_lww_mmap_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    return env->NewStringUTF(hello.c_str());
}
extern "C"
JNIEXPORT void JNICALL


Java_com_lww_mmap_JNIDemo_wiite(JNIEnv *env, jobject thiz) {

  //  文件路径
    std::string  file="/sdcard/lwwbinder";
//    文件不存在 创建文件
     int  m_fd=  open(file.c_str(),O_RDWR|O_CREAT ,S_IREAD);
    ftruncate(m_fd,4096);
//  给虚拟
   int *ptr = static_cast<int *>(malloc(1024));


/**    具体参数  含义可以  报读  mmap
 *
 *   第一参数:  虚拟地址  0:表示 系统分配 虚拟第hi
 *   第二参数  长度:  映射区的产犊  //长度单位是 以字节为单位，不足一内存页按一内存页处理  4k为一夜
 *    第三参数: 可读可写
 *     第四参数 flag: 表示该数据是否共享
 *
 *  第六个参数 偏凉量 被映射对象内容的起点。  0
 *
 */
//   拿到虚拟地址
   m_ptr= static_cast<int8_t *>(mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, m_fd,
                                               0));
// 给 虚拟地址复制
   std::string  info="学习binder";
    memcpy(m_ptr,info.data(),info.size());

}

extern "C"
JNIEXPORT jstring JNICALL
Java_com_lww_mmap_JNIDemo_read(JNIEnv *env, jobject thiz) {
    std::string  file="/sdcard/lwwbinder";
    int  m_fd=  open(file.c_str(),O_RDWR|O_CREAT ,S_IREAD);
    ftruncate(m_fd,4096);
    m_ptr= static_cast<int8_t *>(mmap(0, 4096, PROT_READ | PROT_WRITE, MAP_SHARED, m_fd,
                                      0));

    char *buf= static_cast<char *>(malloc(100));

    memcpy(buf,m_ptr,100);
    std::string result(buf);
    close(m_fd);

    return  env->NewStringUTF(result.c_str());
}
