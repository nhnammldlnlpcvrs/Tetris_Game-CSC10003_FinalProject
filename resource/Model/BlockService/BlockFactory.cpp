#include "BlockFactory.h"

/**
 * @brief Khởi tạo BlockFactory với các prototype của 7 loại khối Tetris.
 *
 * Các khối được lưu trữ dưới dạng unique_ptr để đảm bảo quản lý tài nguyên an toàn.
 */
BlockFactory::BlockFactory() {
    _prototypes[0] = std::make_unique<IBlock>();
    _prototypes[1] = std::make_unique<JBlock>();
    _prototypes[2] = std::make_unique<LBlock>();
    _prototypes[3] = std::make_unique<OBlock>();
    _prototypes[4] = std::make_unique<SBlock>();
    _prototypes[5] = std::make_unique<TBlock>();
    _prototypes[6] = std::make_unique<ZBlock>();
}

/**
 * @brief Tạo một khối Tetris dựa trên ID.
 *
 * @param id ID của khối (0–6, tương ứng với I, J, L, O, S, T, Z).
 * @return std::unique_ptr<Block> Con trỏ thông minh tới khối được tạo.
 * @throws std::out_of_range Nếu ID không hợp lệ.
 * @throws std::runtime_error Nếu clone thất bại.
 */
std::unique_ptr<Block> BlockFactory::CreateBlock(int id) const {
    if (id < 0 || id >= static_cast<int>(_prototypes.size())) {
        throw std::out_of_range("Invalid Block ID: " + std::to_string(id));
    }

    auto clone = _prototypes[id]->Clone();
    if (!clone) {
        throw std::runtime_error("Failed to clone Block with ID: " + std::to_string(id));
    }

    return clone;
}

/**
 * @brief Tạo một khối Tetris ngẫu nhiên.
 *
 * @return std::unique_ptr<Block> Con trỏ thông minh tới khối ngẫu nhiên.
 */
std::unique_ptr<Block> BlockFactory::CreateRandomBlock() const {
    return CreateBlock(GenerateRandomId());
}

/**
 * @brief Sinh ID ngẫu nhiên trong khoảng 0–6.
 *
 * @return int ID khối ngẫu nhiên.
 */
int BlockFactory::GenerateRandomId() const {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    static std::uniform_int_distribution<> dist(0, 6);
    return dist(gen);
}
