/* file: average_pooling3d_forward_result.cpp */
/*******************************************************************************
* Copyright 2014-2019 Intel Corporation
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

#include <jni.h>
#include "com_intel_daal_algorithms_neural_networks_layers_average_pooling3d_AveragePooling3dForwardResult.h"

#include "daal.h"

#include "common_helpers.h"

#include "com_intel_daal_algorithms_neural_networks_layers_average_pooling3d_AveragePooling3dLayerDataId.h"
#define auxInputDimensionsId com_intel_daal_algorithms_neural_networks_layers_average_pooling3d_AveragePooling3dLayerDataId_auxInputDimensionsId

USING_COMMON_NAMESPACES();
using namespace daal::algorithms::neural_networks::layers::average_pooling3d;

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_average_1pooling3d_AveragePooling3dForwardResult
 * Method:    cNewResult
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_average_1pooling3d_AveragePooling3dForwardResult_cNewResult
(JNIEnv *env, jobject thisObj)
{
    return jniArgument<forward::Result>::newObj();
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_average_1pooling3d_AveragePooling3dForwardResult
 * Method:    cGetValue
 * Signature: (JI)J
 */
JNIEXPORT jlong JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_average_1pooling3d_AveragePooling3dForwardResult_cGetValue
(JNIEnv *env, jobject thisObj, jlong resAddr, jint id)
{
    if (id == auxInputDimensionsId)
    {
        return jniArgument<forward::Result>::get<LayerDataId, NumericTable>(resAddr, id);
    }

    return (jlong)0;
}

/*
 * Class:     com_intel_daal_algorithms_neural_networks_layers_average_1pooling3d_AveragePooling3dForwardResult
 * Method:    cSetValue
 * Signature: (JIJ)V
 */
JNIEXPORT void JNICALL Java_com_intel_daal_algorithms_neural_1networks_layers_average_1pooling3d_AveragePooling3dForwardResult_cSetValue
(JNIEnv *env, jobject thisObj, jlong resAddr, jint id, jlong ntAddr)
{
    if (id == auxInputDimensionsId)
    {
        jniArgument<forward::Result>::set<LayerDataId, NumericTable>(resAddr, auxInputDimensions, id);
    }
}