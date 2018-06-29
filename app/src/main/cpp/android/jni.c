//
// Created by Simonppg on 11/4/2017.
//

#include <jni.h>
#include <stdbool.h>
#include <android/asset_manager_jni.h>

#include "game.h"

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1surface_1created
    (JNIEnv * env, jclass cls) {
    on_surface_created();
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1surface_1changed
    (JNIEnv * env, jclass cls, jint width, jint height) {
    on_surface_changed(width, height);
}

JNIEXPORT void JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1draw_1frame
    (JNIEnv * env, jclass cls) {
    on_draw_frame();
}

JNIEXPORT bool JNICALL Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_on_1touch_1event
        (JNIEnv * env, jclass cls) {
    return on_touch_event();
}

JNIEXPORT void JNICALL
Java_com_example_simonppg_break_1it_1all_GameLibJNIWrapper_load_1asset_1manager
        (JNIEnv *env, jclass type, jobject mgr) {
    AAssetManager *mgr2 = AAssetManager_fromJava(env, mgr);
    load_asset_manager(mgr2);
}
