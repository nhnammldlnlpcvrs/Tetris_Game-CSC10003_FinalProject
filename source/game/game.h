#pragma once

#include "../core/grid.h"
#include "../data/block.h"
#include "../blocks/L_block.h"
#include "../blocks/J_block.h"
#include "../blocks/I_block.h"
#include "../blocks/O_block.h"
#include "../blocks/S_block.h"
#include "../blocks/T_block.h"
#include "../blocks/Z_block.h"
#include "../audio/audio_service.h"
#include <memory>

/**
 * @class Game
 * @brief Quản lý toàn bộ vòng đời và logic chính của trò chơi Tetris.
 *
 * Lớp này xử lý việc tạo khối, di chuyển, xoay, tính điểm, khóa khối và kiểm tra trạng thái trò chơi.
 * Đồng thời chịu trách nhiệm giao tiếp với dịch vụ âm thanh và vẽ màn hình.
 */
class Game
{
public:
    /**
     * @brief Khởi tạo trò chơi và sinh khối đầu tiên.
     */
    Game();

    /**
     * @brief Giải phóng bộ nhớ.
     */
    ~Game();

    /**
     * @brief Vẽ lưới, khối hiện tại và khối tiếp theo.
     */
    void Draw();

    /**
     * @brief Xử lý các thao tác từ người chơi như di chuyển, xoay, thả nhanh.
     */
    void HandleInput();

    /**
     * @brief Di chuyển khối xuống theo thời gian.
     */
    void MoveBlockDown();

    /**
     * @brief Trạng thái kết thúc trò chơi.
     */
    bool gameOver;

    /**
     * @brief Điểm hiện tại của người chơi.
     */
    int score;

    /**
     * @brief Điểm cao nhất trong các lần chơi.
     */
    int bestScore = 0;

    /**
     * @brief Tải điểm cao nhất từ file.
     */
    void LoadBestScore();

    /**
     * @brief Lưu điểm cao nhất vào file.
     */
    void SaveBestScore();

    /**
     * @brief Dịch vụ âm thanh dùng để phát hiệu ứng.
     */
    std::shared_ptr<AudioService> audioService;

    /**
     * @brief Lấy AudioService hiện tại.
     * @return Shared pointer trỏ đến AudioService.
     */
    std::shared_ptr<AudioService> GetAudioService();

public:
    /**
     * @brief Di chuyển khối sang trái nếu hợp lệ.
     */
    void MoveBlockLeft();

    /**
     * @brief Di chuyển khối sang phải nếu hợp lệ.
     */
    void MoveBlockRight();

    /**
     * @brief Xoay khối hiện tại nếu hợp lệ.
     */
    void RotateBlock();

private:
    /**
     * @brief Thả khối xuống đáy nhanh chóng.
     */
    void HardDrop();

    /**
     * @brief Tạo một khối ngẫu nhiên từ danh sách khối.
     * @return Con trỏ unique_ptr đến khối mới.
     */
    std::unique_ptr<Block> GetRandomBlock();

    /**
     * @brief Lấy danh sách tất cả các loại khối.
     * @return Vector chứa các khối mẫu.
     */
    std::vector<std::unique_ptr<Block>> GetAllBlocks();

    /**
     * @brief Kiểm tra xem khối hiện tại có nằm ngoài lưới không.
     * @return True nếu nằm ngoài.
     */
    bool IsBlockOutside();

    

    /**
     * @brief Khóa khối vào lưới khi không thể di chuyển thêm.
     */
    void LockBlock();

    /**
     * @brief Kiểm tra khối có vừa vặn trong lưới không.
     * @return True nếu vừa.
     */
    bool BlockFits();

    /**
     * @brief Reset trò chơi, khởi tạo lại trạng thái ban đầu.
     */
    void Reset();

    /**
     * @brief Cập nhật điểm số dựa trên số dòng bị xóa và điểm rơi khối.
     * @param linesCleared Số dòng đã xóa.
     * @param moveDownPoints Điểm thưởng từ việc rơi nhanh.
     */
    void UpdateScore(int linesCleared, int moveDownPoints);

    /**
     * @brief Lưới chính của trò chơi.
     */
    Grid grid;

    /**
     * @brief Danh sách các khối khả dụng.
     */
    std::vector<std::unique_ptr<Block>> blocks;

    /**
     * @brief Khối đang hoạt động hiện tại.
     */
    std::unique_ptr<Block> currentBlock;

    /**
     * @brief Khối tiếp theo sẽ xuất hiện sau currentBlock.
     */
    std::unique_ptr<Block> nextBlock;
};
