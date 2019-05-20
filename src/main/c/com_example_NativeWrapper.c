#include <jni.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>
#include <sys/mman.h>
#include "com_example_NativeWrapper.h"

JNIEXPORT jstring JNICALL Java_com_example_NativeWrapper_testNativeMethod(JNIEnv *env, jclass c, jstring s) {
  const char *nativeString = (*env)->GetStringUTFChars(env, s, 0);
  printf("Hello World from C: \"%s\", len: %d\n", nativeString, strlen(nativeString));
  fflush(stdout);
  if (strcmp(nativeString, "test") == 0) {
    int *p = NULL;
    printf("Printing nonsense value: %d", *p);
  } else if (strcmp(nativeString, "nativemem") == 0) {    
    void *p = mmap((void*)0x10000000, 0xA0000000, PROT_READ|PROT_WRITE, MAP_PRIVATE|MAP_ANONYMOUS, -1, 0);
    if (p) {
      printf("Allocated mmap %p\n", p);
      fflush(stdout);
    } else {
      printf("Failed to allocate\n");
      fflush(stdout);
    }
  }
  (*env)->ReleaseStringUTFChars(env, s, nativeString);
  return s;
}
