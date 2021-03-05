#include <iostream>
#include "BreakItAll.hpp"

// #include "common/game.hpp"
// #include "filesManager.hpp"

// Game *game;

BreakItAll *game = new BreakItAll();

#ifdef __cplusplus
extern "C" {
#endif

#include <jni.h>
#include <android/asset_manager_jni.h>

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_surfaceCreated
        (JNIEnv * env, jclass cls) {
    // game->surfaceCreated();
    game->init();
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_surfaceChanged
        (JNIEnv * env, jclass cls, jint width, jint height) {
    // game->surfaceChanged(width, height);
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_drawFrame
        (JNIEnv * env, jclass cls) {
    // game->update();
    game->render();
}

JNIEXPORT bool JNICALL Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_on_1touch_1event
        (JNIEnv * env, jclass cls, jdouble xpos, jdouble ypos) {
    // return game->on_touch_event(xpos, ypos);
}

JNIEXPORT jobjectArray JNICALL Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_getTestsList
        (JNIEnv * env, jclass cls) {
#define LEN 5
    const char *tests[LEN]={"SandBox", "Window", "Triangle", "Circle", "orthographic"};
    jstring str;
    jobjectArray test = nullptr;
    jsize len = LEN;
    int i;

    test = (*env).NewObjectArray(len, (*env).FindClass("java/lang/String"), 0);

    for(i = 0; i < LEN; i++)
    {
        str = (*env).NewStringUTF(tests[i]);
        (*env).SetObjectArrayElement(test, i, str);
    }

    return test;
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_init(JNIEnv *env, jclass type,
                                                                jint position, jobject mgr) {
    AAssetManager *mgr2 = AAssetManager_fromJava(env, mgr);
    assert(mgr2 != nullptr);
    // load_asset_manager(mgr2);

    // assert(game == nullptr);
    // game = Game::init(position);
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_pause(JNIEnv *env, jclass type) {
    game->pause();
    delete game;
    game = nullptr;
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_resume(JNIEnv *env, jclass type) {
    game->resume();
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_BreakItAllLibJNIWrapper_stop(JNIEnv *env, jclass type) {
    delete game;
}

#ifdef __cplusplus
}
#endif
