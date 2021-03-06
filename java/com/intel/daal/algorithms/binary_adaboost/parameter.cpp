/* file: parameter.cpp */
/*******************************************************************************
* Copyright 2014-2020 Intel Corporation
*
* Licensed under the Apache License, Version 2.0 (the "License");
* you may not use this file except in compliance with the License.
* You may obtain a copy of the License at
*
*     http://www.apache.org/licenses/LICENSE-2.0
*
* Unless required by applicable law or agreed to in writing, software
* distributed under the License is distributed on an "AS IS" BASIS,
* WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
* See the License for the specific language governing permissions and
* limitations under the License.
*******************************************************************************/

/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>/* Header for class com_intel_daal_algorithms_binary_1adaboost_Batch */

#include "daal.h"
#include "com_intel_daal_algorithms_binary_adaboost_Parameter.h"

using namespace daal;
using namespace daal::algorithms;

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_binary_1adaboost_Parameter_cSetAccuracyThreshold(JNIEnv * env, jobject thisObj, jlong parAddr,
                                                                                                       jdouble acc)
{
    (*(adaboost::interface1::Parameter *)parAddr).accuracyThreshold = acc;
}

JNIEXPORT jdouble JNICALL Java_com_intel_daal_algorithms_binary_1adaboost_Parameter_cGetAccuracyThreshold(JNIEnv * env, jobject thisObj,
                                                                                                          jlong parAddr)
{
    return (jdouble)(*(adaboost::interface1::Parameter *)parAddr).accuracyThreshold;
}

JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_binary_1adaboost_Parameter_cSetMaxIterations(JNIEnv * env, jobject thisObj, jlong parAddr,
                                                                                                   jlong nIter)
{
    (*(adaboost::interface1::Parameter *)parAddr).maxIterations = nIter;
}

JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_binary_1adaboost_Parameter_cGetMaxIterations(JNIEnv * env, jobject thisObj, jlong parAddr)
{
    return (jlong)(*(adaboost::interface1::Parameter *)parAddr).maxIterations;
}
