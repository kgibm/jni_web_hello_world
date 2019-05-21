# jni_web_hello_world

    mvn clean install
    ls target/jni_web_hello_world.war

## Compile JNI

Linux

    gcc -g -shared -fPIC -o libNativeWrapper.so -I${JAVA_HOME}/include/ -I${JAVA_HOME}/include/linux/ com_example_NativeWrapper.c

## Run

    -Djava.library.path=${PATH_TO_SO_DIR}
