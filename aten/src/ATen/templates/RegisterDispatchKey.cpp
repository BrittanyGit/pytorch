// required for old g++ to compile PRId64 macros, see
// https://github.com/pytorch/pytorch/issues/3571
// for context
#ifndef __STDC_FORMAT_MACROS
#define __STDC_FORMAT_MACROS
#endif

// NOTE: This condition is true for all PyTorch internal libraries, it
//       just excludes external projects such as torch_xla which
//       re-use some of the PyTorch codegen machinery.
#if defined(CAFFE2_BUILD_MAIN_LIB)        || \
    defined(TORCH_CUDA_BUILD_MAIN_LIB)    || \
    defined(TORCH_HIP_BUILD_MAIN_LIB)     || \
    defined(TORCH_CUDA_CU_BUILD_MAIN_LIB) || \
    defined(TORCH_CUDA_CPP_BUILD_MAIN_LIB)
#define TORCH_ASSERT_ONLY_METHOD_OPERATORS
#endif

// ${generated_comment}

#include <c10/core/TensorImpl.h>
#include <c10/core/Allocator.h>
#include <ATen/DeviceGuard.h>
#include <ATen/NamedTensorUtils.h>
#include <ATen/Utils.h>
#include <ATen/WrapDimUtils.h>
#include <ATen/Dispatch.h>
#include <c10/util/ExclusivelyOwned.h>
#include <c10/util/Half.h>
#include <c10/core/UndefinedTensorImpl.h>
#include <c10/util/Optional.h>
#include <ATen/Tensor.h>
#include <ATen/native/Resize.h>

#include <cstddef>
#include <functional>
#include <memory>
#include <utility>

#include <ATen/Config.h>
#include <ATen/core/op_registration/adaption.h>
#include <torch/library.h>
$extra_cuda_headers
$external_backend_headers
$dispatch_headers
$ops_headers


namespace at {

// NB: TORCH_LIBRARY_IMPL must be in an anonymous namespace to avoid
// ambiguity with conflicting identifiers that may have been defined in
// at namespace already.
namespace {

${dispatch_helpers}

${dispatch_anonymous_definitions}

TORCH_LIBRARY_IMPL(aten, ${DispatchKey}, m) {
  ${dispatch_registrations}
}

} // anonymous namespace

namespace ${dispatch_namespace} {

${dispatch_namespaced_definitions}

} // namespace ${dispatch_namespace}

} // namespace at
