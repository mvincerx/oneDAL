/* file: eltwise_sum_layer_forward.h */
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

/*
//++
//  Implementation of the interface for the forward element-wise sum layer
//  in the batch processing mode
//--
*/

#ifndef __ELTWISE_SUM_LAYER_FORWARD_H__
#define __ELTWISE_SUM_LAYER_FORWARD_H__

#include "algorithms/algorithm.h"
#include "services/daal_defines.h"

#include "data_management/data/tensor.h"

#include "algorithms/neural_networks/layers/layer.h"
#include "algorithms/neural_networks/layers/eltwise_sum/eltwise_sum_layer_types.h"
#include "algorithms/neural_networks/layers/eltwise_sum/eltwise_sum_layer_forward_types.h"

namespace daal
{
namespace algorithms
{
namespace neural_networks
{
namespace layers
{
namespace eltwise_sum
{
namespace forward
{
namespace interface1
{
/**
 * @defgroup eltwise_sum_forward_batch Batch
 * @ingroup eltwise_sum_forward
 * @{
 */
/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__ELTWISE_SUM__FORWARD__BATCHCONTAINER"></a>
 * \brief Provides methods to run implementations of the forward element-wise sum layer.
 *        This class is associated with the daal::algorithms::neural_networks::layers::eltwise_sum::forward::Batch class
 *        and supports the method of forward element-wise sum layer computation in the batch processing mode
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of forward element-wise sum layer, double or float
 * \tparam method           Computation method of the layer, \ref daal::algorithms::neural_networks::layers::eltwise_sum::Method
 * \tparam cpu              Version of the cpu-specific implementation of the layer, \ref daal::CpuType
 */
template<typename algorithmFPType, Method method, CpuType cpu>
class BatchContainer : public layers::forward::LayerContainerIfaceImpl
{
public:
    /**
     * Constructs a container for the forward element-wise sum layer with a specified environment
     * in the batch processing mode
     * \param[in] daalEnv   Environment object
     */
    BatchContainer(daal::services::Environment::env *daalEnv);
    /** Default destructor */
    ~BatchContainer();
    /**
     * Computes the result of the forward element-wise sum layer in the batch processing mode
     *
     * \return Status of computations
     */
    services::Status compute() DAAL_C11_OVERRIDE;
};

/**
 * <a name="DAAL-CLASS-ALGORITHMS__NEURAL_NETWORKS__LAYERS__ELTWISE_SUM__FORWARD__BATCH"></a>
 * \brief Computes the results of the forward element-wise sum layer in the batch processing mode
 * <!-- \n<a href="DAAL-REF-ELTWISE_SUMFORWARD-ALGORITHM">Forward element-wise sum layer description and usage models</a> -->
 *
 * \tparam algorithmFPType  Data type to use in intermediate computations of forward element-wise sum layer, double or float
 * \tparam method           Computation method of the layer, \ref Method
 *
 * \par Enumerations
 *      - \ref Method      Computation methods for the forward element-wise sum layer
 *      - \ref LayerDataId Identifiers of results of the forward element-wise sum layer
 *
 * \par References
 *      - \ref backward::interface1::Batch "backward::Batch" class
 */
template<typename algorithmFPType = DAAL_ALGORITHM_FP_TYPE, Method method = defaultDense>
class Batch : public layers::forward::LayerIfaceImpl
{
public:
    typedef layers::forward::LayerIfaceImpl super;

    typedef algorithms::neural_networks::layers::eltwise_sum::forward::Input  InputType;
    typedef algorithms::neural_networks::layers::eltwise_sum::Parameter       ParameterType;
    typedef algorithms::neural_networks::layers::eltwise_sum::forward::Result ResultType;

    ParameterType &parameter; /*!< Forward element-wise sum layer \ref interface1::Parameter "parameters" */
    InputType input;          /*!< Forward element-wise sum layer input */

    /**
     * Constructs forward element-wise sum layer
     */
    Batch() : parameter(_defaultParameter)
    {
        initialize();
    };

    /**
     * Constructs a forward element-wise sum layer in the batch processing mode
     * and initializes its parameter with the provided parameter
     * \param[in] parameter Parameter to initialize the parameter of the layer
     */
    Batch(Parameter& parameter) : parameter(parameter), _defaultParameter(parameter)
    {
        initialize();
    }

    /**
     * Constructs a forward element-wise sum layer by copying input objects and parameters of another forward element-wise sum layer
     * \param[in] other A layer to be used as the source to initialize the input objects
     *                  and parameters of this layer
     */
    Batch(const Batch<algorithmFPType, method> &other) : super(other),
        _defaultParameter(other.parameter), parameter(_defaultParameter), input(other.input)
    {
        initialize();
    }

    /**
    * Returns method of the layer
    * \return Method of the layer
    */
    virtual int getMethod() const DAAL_C11_OVERRIDE { return(int) method; }

    /**
     * Returns the structure that contains the input objects of the forward element-wise sum layer
     * \return Structure that contains the input objects of the forward element-wise sum layer
     */
    virtual InputType *getLayerInput() DAAL_C11_OVERRIDE { return &input; }

    /**
     * Returns the structure that contains parameters of the forward element-wise sum layer
     * \return Structure that contains parameters of the forward element-wise sum layer
     */
    virtual Parameter *getLayerParameter() DAAL_C11_OVERRIDE { return &parameter; };

    /**
     * Returns the structure that contains results of element-wise sum layer
     * \return Structure that contains results of element-wise sum layer
     */
    virtual layers::forward::ResultPtr getLayerResult() DAAL_C11_OVERRIDE
    {
        return getResult();
    }

    /**
     * Returns the structure that contains results of element-wise sum layer
     * \return Structure that contains results of element-wise sum layer
     */
    ResultPtr getResult()
    {
        return _result;
    }

    /**
     * Registers user-allocated memory to store results of element-wise sum layer
     * \param[in] result  Structure to store results of element-wise sum layer
     *
     * \return Status of computations
     */
    services::Status setResult(const ResultPtr& result)
    {
        DAAL_CHECK(result, services::ErrorNullResult)
        _result = result;
        _res = _result.get();
        return services::Status();
    }

    /**
     * Returns a pointer to the newly allocated element-wise sum layer
     * with a copy of input objects and parameters of this element-wise sum layer
     * \return Pointer to the newly allocated layer
     */
    services::SharedPtr<Batch<algorithmFPType, method> > clone() const
    {
        return services::SharedPtr<Batch<algorithmFPType, method> >(cloneImpl());
    }

    /**
     * Allocates memory to store the result of the forward element-wise sum layer
     *
     * \return Status of computations
     */
    virtual services::Status allocateResult() DAAL_C11_OVERRIDE
    {
        services::Status s = this->_result->template allocate<algorithmFPType>(&(this->input), &parameter, (int) method);
        this->_res = this->_result.get();
        return s;
    }

protected:
    virtual Batch<algorithmFPType, method> *cloneImpl() const DAAL_C11_OVERRIDE
    {
        return new Batch<algorithmFPType, method>(*this);
    }

    void initialize()
    {
        Analysis<batch>::_ac = new __DAAL_ALGORITHM_LAYER_CONTAINER(BatchContainer, algorithmFPType, method)(&_env);
        _in = &input;
        _par = &parameter;
        _result.reset(new ResultType());
    }

private:
    ResultPtr _result;
    ParameterType _defaultParameter;
};
/** @} */
} // namespace interface1
using interface1::BatchContainer;
using interface1::Batch;
} // namespace forward
} // namespace eltwise_sum
} // namespace layers
} // namespace neural_networks
} // namespace algorithms
} // namespace daal
#endif