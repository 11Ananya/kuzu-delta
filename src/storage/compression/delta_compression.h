#pragma once

#include "storage/compression/compression.h"

namespace kuzu {
namespace storage {

template<typename T>
class DeltaCompression final : public CompressionAlg {
public:
    
    DeltaCompression() = default;

    uint64_t compressNextPage(const uint8_t* input, uint64_t& numValuesRemaining,
        uint8_t* output, uint64_t pageSize, const CompressionMetadata& metadata) const override;

    void decompress(const uint8_t* input, uint64_t startValueIdx, uint64_t numValuesToRead,
        uint8_t* output, const CompressionMetadata& metadata) const override;
    CompressionType getCompressionType() const override;
};

} // namespace storage
} // namespace kuzu
