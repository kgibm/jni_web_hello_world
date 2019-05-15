#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "com_example_NativeWrapper.h"

JNIEXPORT jstring JNICALL Java_com_example_NativeWrapper_testNativeMethod(JNIEnv *env, jclass c, jstring s) {
  const char *nativeString = (*env)->GetStringUTFChars(env, s, 0);
  printf("Hello World from C: \"%s\", len: %d\n", nativeString, strlen(nativeString));
  fflush(stdout);
  printf("Comparison: %d\n", strcmp(nativeString, "test"));
  fflush(stdout);
  if (strcmp(nativeString, "test") == 0) {
    const char *p = 0;
    printf("Printing nonsense value: %s", p);
  }
  (*env)->ReleaseStringUTFChars(env, s, nativeString);
  return s;
}
