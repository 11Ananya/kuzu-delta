#include "storage/compression/delta_compression.h"
#include <vector>
#include <cstring>
#include <algorithm>

namespace kuzu {
namespace storage {

template<typename T>
uint64_t DeltaCompression<T>::compressNextPage(const uint8_t* input, uint64_t& numValuesRemaining,
    uint8_t* output, uint64_t pageSize, const CompressionMetadata& metadata) const {
    // TEMP stub: pretend nothing is compressed
    uint64_t numToCompress = std::min(numValuesRemaining, pageSize / sizeof(T));
    std::memcpy(output, input, numToCompress * sizeof(T));
    numValuesRemaining -= numToCompress;
    return numToCompress * sizeof(T);
}

template<typename T>
void DeltaCompression<T>::decompress(const uint8_t* input, uint64_t startValueIdx,
    uint64_t numValuesToRead, uint8_t* output, const CompressionMetadata& metadata) const {
    std::memcpy(output, input, numValuesToRead * sizeof(T));
}

template class DeltaCompression<int64_t>;
template<>
CompressionType DeltaCompression<int64_t>::getCompressionType() const {
    return CompressionType::DELTA;
}

} // namespace storage
} // namespace kuzu
