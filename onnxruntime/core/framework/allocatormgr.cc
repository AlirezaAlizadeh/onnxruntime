// Copyright (c) Microsoft Corporation. All rights reserved.
// Licensed under the MIT License.

#include "core/framework/allocatormgr.h"
#include "core/framework/bfc_arena.h"
#include "core/framework/mimalloc_arena.h"
#include <mutex>
#include <sstream>
#include <unordered_map>
#include <limits>

namespace onnxruntime {
using namespace common;

#ifdef USE_MIMALLOC
using TArenaAllocator = MiMallocArena;
#else
using TArenaAllocator = BFCArena;
#endif

AllocatorPtr CreateAllocator(DeviceAllocatorRegistrationInfo info, bool use_arena, int device_id) {
  auto device_allocator = std::unique_ptr<IDeviceAllocator>(info.factory(device_id));
  if (use_arena) {
    return std::shared_ptr<IArenaAllocator>(
        onnxruntime::make_unique<TArenaAllocator>(std::move(device_allocator), info.max_mem));
  }

  return AllocatorPtr(std::move(device_allocator));
}

DeviceAllocatorRegistry& DeviceAllocatorRegistry::Instance() {
  static DeviceAllocatorRegistry s_instance;
  return s_instance;
}

}  // namespace onnxruntime
