#include <jni.h>
#include <stdio.h>
#include <string.h>
#include "com_example_NativeWrapper.h"

JNIEXPORT jstring JNICALL Java_com_example_NativeWrapper_testNativeMethod(JNIEnv *env, jclass c, jstring s) {
  const char *nativeString = (*env)->GetStringUTFChars(env, s, 0);
  printf("Hello World from C: \"%s\", len: %d\n", nativeString, strlen(nativeString));
  fflush(stdout);
  if (strcmp(nativeString, "test") == 0) {
    void *p = NULL;
    printf("Printing nonsense value: %d", *p);
	fflush(stdout);
  }
  (*env)->ReleaseStringUTFChars(env, s, nativeString);
  return s;
}
