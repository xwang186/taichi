#include "taichi/aot/module_loader.h"

namespace taichi {
namespace lang {
namespace aot {

Kernel *ModuleLoader::get_kernel(const std::string &name) {
  auto itr = loaded_kernels_.find(name);
  if (itr != loaded_kernels_.end()) {
    return itr->second.get();
  }
  auto k = make_new_kernel(name);
  auto *kptr = k.get();
  loaded_kernels_[name] = std::move(k);
  return kptr;
}

}  // namespace aot
}  // namespace lang
}  // namespace taichi
