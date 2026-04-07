#pragma once
#include"pak.h"
#include"OS-ImGui\\OS-ImGui_Struct.h"
namespace Offset
{
	inline uint64_t GameAssembly = 0;
	inline uint64_t NarakaBladepoint = 0;
	inline uint64_t MatrixAddr = 0;
	inline uint64_t Base_WindowBase = 0x352ABF8;  // 游戏窗口大小
	inline uint64_t Base_BuffManager = 0x3513318;  // 人物BUFF
	inline uint64_t m_GlobalTime = 0x351D6C8;  // 世界时间 
	inline uint64_t m_CharacterManager = 0x3514648;  // 世界地址  
	inline uint64_t m_UserDataManager = 0x3538278;  // 技能建筑数据基址 
	inline uint64_t m_CharactorSync = 0x35146B0;  // 人物同步
	inline uint64_t m_EntityManager = 0x351D780;  // 物品基址 

	//inline uint64_t InitActorKitRefer = 0x3530E80 ;  // 内存振刀
	inline uint64_t FlushState = 0xC5;  // 刷新状态

	inline uint64_t ActorKitRefer = 0xC;  // 动画
	inline uint64_t vtbale_ret = 0x1D;  // 返回

	//inline uint64_t LocalGenRangeSingleData = 0x;  // 追踪
	//inline uint64_t op_Subtraction = 0x;  // 返回地址

	//inline uint64_t Call_GetVelocity = 0x;  // 人物移动速c

    struct
    {
        uint32_t AllAliveCharList = 0x58;
        uint32_t ArrayStart = 0x30;
    } Character;

    struct
    {
        uint32_t ObjectMsg = 0xD8;  // 对象消息
        uint32_t EventTracksForLayer = 0x30;
        uint32_t Transform = 0x118;  // 转换
        uint32_t ActorWeapon = 0xF8;
        uint32_t RuntimePropertyData = 0xA8;
        uint32_t PropertyData = 0x348;
        uint32_t ActorKit = 0xC8;

        struct
        {
            uint32_t Heroid = 0x108;  // 英雄ID
            uint32_t Group = 0x118;  // 团队
            uint32_t WeaponId = 0x128;  // 武器id
            uint32_t RobotId = 0x130;  // 机器人
            uint32_t PlayerName = 0x1F8;  // 人物名称
            uint32_t SkillStatus = 0x198;  // 技能施放状态（0:未施放 1:前摇中 2:施放中）
        } ProPerty;

        struct
        {
            uint32_t BackingField = 0x38;
            uint32_t ActorPhysics = 0xD0;
            uint32_t ActorKitSync = 0xC8;
            uint32_t CurrentCollisionFlags = 0xEC;
            uint32_t HitSimulateData = 0xF0;  // 状态
            uint32_t actorKitComboData = 0xE0;  // 状态
            uint32_t actorKitBreakData = 0xF8;
            uint32_t PlayerCollideAgent = 0x1E8;
            uint32_t FlashType = 0x58;
            struct
            {
                uint32_t ReactionType = 0x54;  // 出刀状态
                uint32_t RangeReactionType = 0x58;  // 攻击状态
                uint32_t ReactionExtraType = 0x5C;  // 振刀状态
                uint32_t endureLevel = 0xD0;  // 当前状态
                uint32_t ActionDuration = 0x2C;  // 僵直
                uint32_t ReactionParryType = 0xB4;  // 磐石状态
                uint32_t XuListate = 0x70;  // 蓄力状态
                uint32_t XuLilevel = 0x54;  // 蓄力层级
            } HitSimulate;
        } ActorKitS;
    } ActorModel;  // 行动状态

    struct
    {
        uint32_t EquipPackData = 0xA8;
        uint32_t InteractiveManager = 0x228;
        uint32_t SpectatorData = 0x88;
        uint32_t Skill_ID = 0x70;
        uint32_t skillState = 0x80;
        uint32_t ClientLeftCdTime = 0x44;
        uint32_t ClientLeftContinueTime = 0x4c;
    } UserData;  // 人物数据
}  // namespace Offset