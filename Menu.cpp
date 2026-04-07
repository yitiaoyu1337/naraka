#include"Menu.h"

void 保存模拟振配置()
{
	ofstream file("模拟振配置.ini");
	if (file.is_open())
	{
		file << "长剑左3距离=" << 振刀参数::距离::长剑.左3 << "f;\n";
		file << "长剑右3距离=" << 振刀参数::距离::长剑.右3 << "f;\n";
		file << "长剑左剑气距离=" << 振刀参数::距离::长剑.左剑气 << "f;\n";
		file << "长剑右剑气距离=" << 振刀参数::距离::长剑.右剑气 << "f;\n";
		file << "长剑凤凰羽距离=" << 振刀参数::距离::长剑.凤凰羽 << "f;\n";
		file << "长剑蓝月距离=" << 振刀参数::距离::长剑.蓝月 << "f;\n";
		file << "长剑七星夺窍距离=" << 振刀参数::距离::长剑.七星夺窍 << "f;\n";
		file << "长剑左3角度=" << 振刀参数::角度::长剑.左3 << "f;\n";
		file << "长剑右3角度=" << 振刀参数::角度::长剑.右3 << "f;\n";
		file << "长剑左剑气2M角度=" << 振刀参数::角度::长剑.左剑气2M << "f;\n";
		file << "长剑左剑气4M角度=" << 振刀参数::角度::长剑.左剑气4M << "f;\n";
		file << "长剑左剑气6M角度=" << 振刀参数::角度::长剑.左剑气6M << "f;\n";
		file << "长剑左剑气9M角度=" << 振刀参数::角度::长剑.左剑气9M << "f;\n";
		file << "长剑左剑气9M外角度=" << 振刀参数::角度::长剑.左剑气9M外 << "f;\n";
		file << "长剑右剑气2M角度=" << 振刀参数::角度::长剑.右剑气2M << "f;\n";
		file << "长剑右剑气4M角度=" << 振刀参数::角度::长剑.右剑气4M << "f;\n";
		file << "长剑右剑气6M角度=" << 振刀参数::角度::长剑.右剑气6M << "f;\n";
		file << "长剑右剑气9M角度=" << 振刀参数::角度::长剑.右剑气9M << "f;\n";
		file << "长剑右剑气9M外角度=" << 振刀参数::角度::长剑.右剑气9M外 << "f;\n";
		file << "长剑凤凰羽2M角度=" << 振刀参数::角度::长剑.凤凰羽2M << "f;\n";
		file << "长剑凤凰羽5M角度=" << 振刀参数::角度::长剑.凤凰羽5M << "f;\n";
		file << "长剑凤凰羽8M角度=" << 振刀参数::角度::长剑.凤凰羽8M << "f;\n";
		file << "长剑凤凰羽8M外角度=" << 振刀参数::角度::长剑.凤凰羽8M外 << "f;\n";
		file << "长剑蓝月2M角度=" << 振刀参数::角度::长剑.蓝月2M << "f;\n";
		file << "长剑蓝月6M角度=" << 振刀参数::角度::长剑.蓝月6M << "f;\n";
		file << "长剑蓝月6M外角度=" << 振刀参数::角度::长剑.蓝月6M外 << "f;\n";
		file << "长剑七星夺窍角度=" << 振刀参数::角度::长剑.七星夺窍 << "f;\n";

		file << "太刀左3距离=" << 振刀参数::距离::太刀.左3 << "f;\n";
		file << "太刀右3距离=" << 振刀参数::距离::太刀.右3 << "f;\n";
		file << "太刀左蓄距离=" << 振刀参数::距离::太刀.左蓄 << "f;\n";
		file << "太刀右蓄距离=" << 振刀参数::距离::太刀.右蓄 << "f;\n";
		file << "太刀左惊雷距离=" << 振刀参数::距离::太刀.左惊雷 << "f;\n";
		file << "太刀右惊雷&惊雷十劫距离=" << 振刀参数::距离::太刀.右惊雷 << "f;\n";
		file << "太刀左青鬼距离=" << 振刀参数::距离::太刀.左青鬼 << "f;\n";
		file << "太刀右青鬼距离=" << 振刀参数::距离::太刀.右青鬼 << "f;\n";
		file << "太刀噬魂斩距离=" << 振刀参数::距离::太刀.噬魂斩 << "f;\n";

		file << "太刀左3角度=" << 振刀参数::角度::太刀.左3 << "f;\n";
		file << "太刀右3角度=" << 振刀参数::角度::太刀.右3 << "f;\n";
		file << "太刀左蓄2M角度=" << 振刀参数::角度::太刀.左蓄2M << "f;\n";
		file << "太刀左蓄2M外角度=" << 振刀参数::角度::太刀.左蓄2M外 << "f;\n";
		file << "太刀右蓄2M角度=" << 振刀参数::角度::太刀.右蓄2M << "f;\n";
		file << "太刀右蓄2M外角度=" << 振刀参数::角度::太刀.右蓄2M外 << "f;\n";
		file << "太刀左惊雷角度=" << 振刀参数::角度::太刀.左惊雷 << "f;\n";
		file << "太刀右惊雷5M角度=" << 振刀参数::角度::太刀.右惊雷5M << "f;\n";
		file << "太刀右惊雷5M外角度=" << 振刀参数::角度::太刀.右惊雷5M外 << "f;\n";
		file << "太刀左青鬼角度=" << 振刀参数::角度::太刀.左青鬼 << "f;\n";
		file << "太刀右青鬼角度=" << 振刀参数::角度::太刀.右青鬼 << "f;\n";

		file << "阔刀左左距离=" << 振刀参数::距离::阔刀.左左 << "f;\n";
		file << "阔刀左右距离=" << 振刀参数::距离::阔刀.左右 << "f;\n";
		file << "阔刀右右距离=" << 振刀参数::距离::阔刀.右右 << "f;\n";
		file << "阔刀右左距离=" << 振刀参数::距离::阔刀.右左 << "f;\n";
		file << "阔刀左蓄一段距离=" << 振刀参数::距离::阔刀.左蓄一段 << "f;\n";
		file << "阔刀左蓄二段距离=" << 振刀参数::距离::阔刀.左蓄二段 << "f;\n";
		file << "阔刀左蓄三段距离=" << 振刀参数::距离::阔刀.左蓄三段 << "f;\n";
		file << "阔刀右蓄距离=" << 振刀参数::距离::阔刀.右蓄 << "f;\n";
		file << "阔刀右右蓄距离=" << 振刀参数::距离::阔刀.右右蓄 << "f;\n";
		file << "阔刀雷刀距离=" << 振刀参数::距离::阔刀.雷刀 << "f;\n";
		file << "阔刀雷刀下劈距离=" << 振刀参数::距离::阔刀.雷刀下劈 << "f;\n";

		file << "阔刀左左角度=" << 振刀参数::角度::阔刀.左左 << "f;\n";
		file << "阔刀左右2M角度=" << 振刀参数::角度::阔刀.左右2M << "f;\n";
		file << "阔刀左右2M外角度=" << 振刀参数::角度::阔刀.左右2M外 << "f;\n";
		file << "阔刀右右角度=" << 振刀参数::角度::阔刀.右右 << "f;\n";
		file << "阔刀右左角度=" << 振刀参数::角度::阔刀.右左 << "f;\n";
		file << "阔刀左蓄一段2M角度=" << 振刀参数::角度::阔刀.左蓄一段2M << "f;\n";
		file << "阔刀左蓄一段2M外角度=" << 振刀参数::角度::阔刀.左蓄一段2M外 << "f;\n";
		file << "阔刀右蓄2M角度=" << 振刀参数::角度::阔刀.右蓄2M << "f;\n";
		file << "阔刀右蓄2M外角度=" << 振刀参数::角度::阔刀.右蓄2M外 << "f;\n";
		file << "阔刀右右蓄2M角度=" << 振刀参数::角度::阔刀.右右蓄2M << "f;\n";
		file << "阔刀右右蓄2M外角度=" << 振刀参数::角度::阔刀.右右蓄2M外 << "f;\n";

		file << "长枪左3距离=" << 振刀参数::距离::长枪.左3 << "f;\n";
		file << "长枪右3距离=" << 振刀参数::距离::长枪.右3 << "f;\n";
		file << "长枪左蓄距离=" << 振刀参数::距离::长枪.左蓄 << "f;\n";
		file << "长枪六合枪距离=" << 振刀参数::距离::长枪.六合枪 << "f;\n";
		file << "长枪右蓄距离=" << 振刀参数::距离::长枪.右蓄 << "f;\n";
		file << "长枪大圣游距离=" << 振刀参数::距离::长枪.大圣游 << "f;\n";
		file << "长枪风卷云残距离=" << 振刀参数::距离::长枪.风卷云残 << "f;\n";
		file << "长枪双环扫距离=" << 振刀参数::距离::长枪.双环扫 << "f;\n";
		file << "长枪龙王破距离=" << 振刀参数::距离::长枪.龙王破 << "f;\n";
		file << "长枪穿心脚距离=" << 振刀参数::距离::长枪.穿心脚 << "f;\n";

		file << "长枪左3角度=" << 振刀参数::角度::长枪.左3 << "f;\n";
		file << "长枪右3角度=" << 振刀参数::角度::长枪.右3 << "f;\n";
		file << "长枪左蓄角度=" << 振刀参数::角度::长枪.左蓄 << "f;\n";
		file << "长枪六合枪2M角度=" << 振刀参数::角度::长枪.六合枪2M << "f;\n";
		file << "长枪六合枪2M外角度=" << 振刀参数::角度::长枪.六合枪2M外 << "f;\n";
		file << "长枪右蓄角度=" << 振刀参数::角度::长枪.右蓄 << "f;\n";
		file << "长枪大圣游角度=" << 振刀参数::角度::长枪.大圣游 << "f;\n";
		file << "长枪风卷云残角度=" << 振刀参数::角度::长枪.风卷云残 << "f;\n";
		file << "长枪龙王破2M角度=" << 振刀参数::角度::长枪.龙王破2M << "f;\n";
		file << "长枪龙王破2M外角度=" << 振刀参数::角度::长枪.龙王破2M外 << "f;\n";
		file << "长枪穿心脚2M角度=" << 振刀参数::角度::长枪.穿心脚2M << "f;\n";
		file << "长枪穿心脚2M外角度=" << 振刀参数::角度::长枪.穿心脚2M外 << "f;\n";

		file << "匕首左3距离=" << 振刀参数::距离::匕首.左3 << "f;\n";
		file << "匕首右3距离=" << 振刀参数::距离::匕首.右3 << "f;\n";
		file << "匕首左蓄距离=" << 振刀参数::距离::匕首.左蓄 << "f;\n";
		file << "匕首右蓄距离=" << 振刀参数::距离::匕首.右蓄 << "f;\n";
		file << "匕首鬼反距离=" << 振刀参数::距离::匕首.鬼反 << "f;\n";
		file << "匕首荆轲献匕距离=" << 振刀参数::距离::匕首.荆轲献匕 << "f;\n";
		file << "匕首鬼刃暗扎距离=" << 振刀参数::距离::匕首.鬼刃暗扎 << "f;\n";
		file << "匕首鬼哭神嚎距离=" << 振刀参数::距离::匕首.鬼哭神嚎 << "f;\n";
		file << "匕首亢龙有悔距离=" << 振刀参数::距离::匕首.亢龙有悔 << "f;\n";

		file << "匕首左3角度=" << 振刀参数::角度::匕首.左3 << "f;\n";
		file << "匕首右3角度=" << 振刀参数::角度::匕首.右3 << "f;\n";
		file << "匕首左蓄2M角度=" << 振刀参数::角度::匕首.左蓄2M << "f;\n";
		file << "匕首左蓄2M外角度=" << 振刀参数::角度::匕首.左蓄2M外 << "f;\n";
		file << "匕首右蓄2M角度=" << 振刀参数::角度::匕首.右蓄2M << "f;\n";
		file << "匕首右蓄2M外角度=" << 振刀参数::角度::匕首.右蓄2M外 << "f;\n";
		file << "匕首鬼反角度=" << 振刀参数::角度::匕首.鬼反 << "f;\n";
		file << "匕首荆轲献匕2M角度=" << 振刀参数::角度::匕首.荆轲献匕2M << "f;\n";
		file << "匕首荆轲献匕2M外角度=" << 振刀参数::角度::匕首.荆轲献匕2M外 << "f;\n";
		file << "匕首鬼刃暗扎2M角度=" << 振刀参数::角度::匕首.鬼刃暗扎2M << "f;\n";
		file << "匕首鬼刃暗扎2M外角度=" << 振刀参数::角度::匕首.鬼刃暗扎2M外 << "f;\n";
		file << "匕首亢龙有悔2M角度=" << 振刀参数::角度::匕首.亢龙有悔2M << "f;\n";
		file << "匕首亢龙有悔4M角度=" << 振刀参数::角度::匕首.亢龙有悔4M << "f;\n";
		file << "匕首亢龙有悔4M外角度=" << 振刀参数::角度::匕首.亢龙有悔4M外 << "f;\n";

		file << "双截棍左右3距离=" << 振刀参数::距离::双截棍.左右3 << "f;\n";
		file << "双截棍左蓄距离=" << 振刀参数::距离::双截棍.左蓄 << "f;\n";
		file << "双截棍右蓄距离=" << 振刀参数::距离::双截棍.右蓄 << "f;\n";
		file << "双截棍飞踢距离=" << 振刀参数::距离::双截棍.飞踢 << "f;\n";
		file << "双截棍扬鞭劲距离=" << 振刀参数::距离::双截棍.扬鞭劲 << "f;\n";
		file << "双截棍横栏距离=" << 振刀参数::距离::双截棍.横栏 << "f;\n";
		file << "双截棍龙虎乱舞距离=" << 振刀参数::距离::双截棍.龙虎乱舞 << "f;\n";

		file << "双截棍左右3角度=" << 振刀参数::角度::双截棍.左右3 << "f;\n";
		file << "双截棍左蓄2M角度=" << 振刀参数::角度::双截棍.左蓄2M << "f;\n";
		file << "双截棍左蓄2M外角度=" << 振刀参数::角度::双截棍.左蓄2M外 << "f;\n";
		file << "双截棍右蓄2M角度=" << 振刀参数::角度::双截棍.右蓄2M << "f;\n";
		file << "双截棍右蓄2M外角度=" << 振刀参数::角度::双截棍.右蓄2M外 << "f;\n";
		file << "双截棍飞踢角度=" << 振刀参数::角度::双截棍.飞踢 << "f;\n";
		file << "双截棍扬鞭劲角度=" << 振刀参数::角度::双截棍.扬鞭劲 << "f;\n";
		file << "双截棍横栏角度=" << 振刀参数::角度::双截棍.横栏 << "f;\n";

		file << "双刀左右3距离=" << 振刀参数::距离::双刀.左右3 << "f;\n";
		file << "双刀左蓄距离=" << 振刀参数::距离::双刀.左蓄 << "f;\n";
		file << "双刀右蓄距离=" << 振刀参数::距离::双刀.右蓄 << "f;\n";
		file << "双刀铁马残红距离=" << 振刀参数::距离::双刀.铁马残红 << "f;\n";
		file << "双刀乾坤日月斩距离=" << 振刀参数::距离::双刀.乾坤日月斩 << "f;\n";
		file << "双刀惊雷距离=" << 振刀参数::距离::双刀.惊雷 << "f;\n";
		file << "双刀八斩刀距离=" << 振刀参数::距离::双刀.八斩刀 << "f;\n";

		file << "双刀左右3角度=" << 振刀参数::角度::双刀.左右3 << "f;\n";
		file << "双刀左蓄角度=" << 振刀参数::角度::双刀.左蓄 << "f;\n";
		file << "双刀右蓄角度=" << 振刀参数::角度::双刀.右蓄 << "f;\n";
		file << "双刀铁马残红3M角度=" << 振刀参数::角度::双刀.铁马残红3M << "f;\n";
		file << "双刀铁马残红3M外角度=" << 振刀参数::角度::双刀.铁马残红3M外 << "f;\n";
		file << "双刀乾坤日月斩角度=" << 振刀参数::角度::双刀.乾坤日月斩 << "f;\n";
		file << "双刀惊雷角度=" << 振刀参数::角度::双刀.惊雷 << "f;\n";
		file << "双刀八斩刀角度=" << 振刀参数::角度::双刀.八斩刀 << "f;\n";

		file << "长棍左3距离=" << 振刀参数::距离::长棍.左3 << "f;\n";
		file << "长棍右3距离=" << 振刀参数::距离::长棍.右3 << "f;\n";
		file << "长棍少林棍距离=" << 振刀参数::距离::长棍.少林棍 << "f;\n";
		file << "长棍左蓄距离=" << 振刀参数::距离::长棍.左蓄 << "f;\n";
		file << "长棍右蓄距离=" << 振刀参数::距离::长棍.右蓄 << "f;\n";
		file << "长棍腾云式距离=" << 振刀参数::距离::长棍.腾云式 << "f;\n";
		file << "长棍乱点天宫距离=" << 振刀参数::距离::长棍.乱点天宫 << "f;\n";
		file << "长棍桶劲距离=" << 振刀参数::距离::长棍.桶劲 << "f;\n";
		file << "长棍五情七灭镇距离=" << 振刀参数::距离::长棍.五情七灭镇 << "f;\n";
		file << "长棍双环扫距离=" << 振刀参数::距离::长棍.双环扫 << "f;\n";
		file << "长棍倒海棍距离=" << 振刀参数::距离::长棍.倒海棍 << "f;\n";
		file << "长棍镇地撑天距离=" << 振刀参数::距离::长棍.镇地撑天 << "f;\n";

		file << "长棍左3角度=" << 振刀参数::角度::长棍.左3 << "f;\n";
		file << "长棍右3角度=" << 振刀参数::角度::长棍.右3 << "f;\n";
		file << "长棍少林棍角度=" << 振刀参数::角度::长棍.少林棍 << "f;\n";
		file << "长棍左蓄2M角度=" << 振刀参数::角度::长棍.左蓄2M << "f;\n";
		file << "长棍左蓄2M外角度=" << 振刀参数::角度::长棍.左蓄2M外 << "f;\n";
		file << "长棍腾云式2M角度=" << 振刀参数::角度::长棍.腾云式2M << "f;\n";
		file << "长棍腾云式2M外角度=" << 振刀参数::角度::长棍.腾云式2M外 << "f;\n";
		file << "长棍乱点天宫角度=" << 振刀参数::角度::长棍.乱点天宫 << "f;\n";
		file << "长棍桶劲角度=" << 振刀参数::角度::长棍.桶劲 << "f;\n";
		file << "长棍五情七灭镇8M角度=" << 振刀参数::角度::长棍.五情七灭镇8M << "f;\n";
		file << "长棍五情七灭镇8M外角度=" << 振刀参数::角度::长棍.五情七灭镇8M外 << "f;\n";
		file << "长棍双环扫角度=" << 振刀参数::角度::长棍.双环扫 << "f;\n";
		file << "长棍倒海棍角度=" << 振刀参数::角度::长棍.倒海棍 << "f;\n";
		file << "长棍镇地撑天角度=" << 振刀参数::角度::长棍.镇地撑天 << "f;\n";

		file << "斩马刀左左距离=" << 振刀参数::距离::斩马刀.左左 << "f;\n";
		file << "斩马刀左右距离=" << 振刀参数::距离::斩马刀.左右 << "f;\n";
		file << "斩马刀右右距离=" << 振刀参数::距离::斩马刀.右右 << "f;\n";
		file << "斩马刀右左距离=" << 振刀参数::距离::斩马刀.右左 << "f;\n";
		file << "斩马刀左蓄距离=" << 振刀参数::距离::斩马刀.左蓄 << "f;\n";
		file << "斩马刀右蓄距离=" << 振刀参数::距离::斩马刀.右蓄 << "f;\n";
		file << "斩马刀柄击距离=" << 振刀参数::距离::斩马刀.柄击 << "f;\n";
		file << "斩马刀惊雷距离=" << 振刀参数::距离::斩马刀.惊雷 << "f;\n";
		file << "斩马刀炽焰斩距离=" << 振刀参数::距离::斩马刀.炽焰斩 << "f;\n";
		file << "斩马刀过关斩将距离=" << 振刀参数::距离::斩马刀.过关斩将 << "f;\n";

		file << "斩马刀左左角度=" << 振刀参数::角度::斩马刀.左左 << "f;\n";
		file << "斩马刀左右2M角度=" << 振刀参数::角度::斩马刀.左右2M << "f;\n";
		file << "斩马刀左右2M外角度=" << 振刀参数::角度::斩马刀.左右2M外 << "f;\n";
		file << "斩马刀右右角度=" << 振刀参数::角度::斩马刀.右右 << "f;\n";
		file << "斩马刀右左角度=" << 振刀参数::角度::斩马刀.右左 << "f;\n";
		file << "斩马刀左蓄2M角度=" << 振刀参数::角度::斩马刀.左蓄2M << "f;\n";
		file << "斩马刀左蓄2M外角度=" << 振刀参数::角度::斩马刀.左蓄2M外 << "f;\n";
		file << "斩马刀右蓄角度=" << 振刀参数::角度::斩马刀.右蓄 << "f;\n";
		file << "斩马刀柄击角度=" << 振刀参数::角度::斩马刀.柄击 << "f;\n";
		file << "斩马刀惊雷角度=" << 振刀参数::角度::斩马刀.惊雷 << "f;\n";
		file << "斩马刀炽焰斩角度=" << 振刀参数::角度::斩马刀.炽焰斩 << "f;\n";
		file << "斩马刀过关斩将角度=" << 振刀参数::角度::斩马刀.过关斩将 << "f;\n";

		file << "双戟左右3距离=" << 振刀参数::距离::双戟.左右3 << "f;\n";
		file << "双戟左蓄距离=" << 振刀参数::距离::双戟.左蓄 << "f;\n";
		file << "双戟右蓄距离=" << 振刀参数::距离::双戟.右蓄 << "f;\n";
		file << "双戟勾旋斩距离=" << 振刀参数::距离::双戟.勾旋斩 << "f;\n";
		file << "双戟探海蛟距离=" << 振刀参数::距离::双戟.探海蛟 << "f;\n";
		file << "双戟钩挂距离=" << 振刀参数::距离::双戟.钩挂 << "f;\n";
		file << "双戟战龙在天距离=" << 振刀参数::距离::双戟.战龙在天 << "f;\n";
		file << "双戟形意钩距离=" << 振刀参数::距离::双戟.形意钩 << "f;\n";

		file << "双戟左右3角度=" << 振刀参数::角度::双戟.左右3 << "f;\n";
		file << "双戟左蓄3M角度=" << 振刀参数::角度::双戟.左蓄3M << "f;\n";
		file << "双戟左蓄3M外角度=" << 振刀参数::角度::双戟.左蓄3M外 << "f;\n";
		file << "双戟右蓄3M角度=" << 振刀参数::角度::双戟.右蓄3M << "f;\n";
		file << "双戟右蓄3M外角度=" << 振刀参数::角度::双戟.右蓄3M外 << "f;\n";
		file << "双戟勾旋斩角度=" << 振刀参数::角度::双戟.勾旋斩 << "f;\n";
		file << "双戟探海蛟角度=" << 振刀参数::角度::双戟.探海蛟 << "f;\n";
		file << "双戟钩挂角度=" << 振刀参数::角度::双戟.钩挂 << "f;\n";
		file << "双戟战龙在天角度=" << 振刀参数::角度::双戟.战龙在天 << "f;\n";
		file << "双戟形意钩角度=" << 振刀参数::角度::双戟.形意钩 << "f;\n";

		file << "扇子左3距离=" << 振刀参数::距离::扇子.左3 << "f;\n";
		file << "扇子右3距离=" << 振刀参数::距离::扇子.右3 << "f;\n";
		file << "扇子左蓄距离=" << 振刀参数::距离::扇子.左蓄 << "f;\n";
		file << "扇子右蓄距离=" << 振刀参数::距离::扇子.右蓄 << "f;\n";
		file << "扇子双开圆距离=" << 振刀参数::距离::扇子.双开圆 << "f;\n";
		file << "扇子三风摆距离=" << 振刀参数::距离::扇子.三风摆 << "f;\n";
		file << "扇子惊雷距离=" << 振刀参数::距离::扇子.惊雷 << "f;\n";
		file << "扇子缠龙奔野距离=" << 振刀参数::距离::扇子.缠龙奔野 << "f;\n";
		file << "扇子鬼反距离=" << 振刀参数::距离::扇子.鬼反 << "f;\n";

		file << "扇子左3角度=" << 振刀参数::角度::扇子.左3 << "f;\n";
		file << "扇子右3角度=" << 振刀参数::角度::扇子.右3 << "f;\n";
		file << "扇子左蓄角度=" << 振刀参数::角度::扇子.左蓄 << "f;\n";
		file << "扇子右蓄2M角度=" << 振刀参数::角度::扇子.右蓄2M << "f;\n";
		file << "扇子右蓄2M外角度=" << 振刀参数::角度::扇子.右蓄2M外 << "f;\n";
		file << "扇子双开圆角度=" << 振刀参数::角度::扇子.双开圆 << "f;\n";
		file << "扇子三风摆3M角度=" << 振刀参数::角度::扇子.三风摆3M << "f;\n";
		file << "扇子三风摆3M外角度=" << 振刀参数::角度::扇子.三风摆3M外 << "f;\n";
		file << "扇子惊雷角度=" << 振刀参数::角度::扇子.惊雷 << "f;\n";
		file << "扇子缠龙奔野3M角度=" << 振刀参数::角度::扇子.缠龙奔野3M << "f;\n";
		file << "扇子缠龙奔野3M外角度=" << 振刀参数::角度::扇子.缠龙奔野3M外 << "f;\n";
		file << "扇子鬼反角度=" << 振刀参数::角度::扇子.鬼反 << "f;\n";

		file << "横刀左3距离=" << 振刀参数::距离::横刀.左3 << "f;\n";
		file << "横刀右3距离=" << 振刀参数::距离::横刀.右3 << "f;\n";
		file << "横刀左蓄距离=" << 振刀参数::距离::横刀.左蓄 << "f;\n";
		file << "横刀右蓄距离=" << 振刀参数::距离::横刀.右蓄 << "f;\n";
		file << "横刀破千军距离=" << 振刀参数::距离::横刀.破千军 << "f;\n";
		file << "横刀极光破云闪距离=" << 振刀参数::距离::横刀.极光破云闪 << "f;\n";

		file << "横刀左3角度=" << 振刀参数::角度::横刀.左3 << "f;\n";
		file << "横刀右3角度=" << 振刀参数::角度::横刀.右3 << "f;\n";
		file << "横刀左蓄角度=" << 振刀参数::角度::横刀.左蓄 << "f;\n";
		file << "横刀右蓄角度=" << 振刀参数::角度::横刀.右蓄 << "f;\n";
		file << "横刀破千军角度=" << 振刀参数::角度::横刀.破千军 << "f;\n";
		file << "横刀极光破云闪角度=" << 振刀参数::角度::横刀.极光破云闪 << "f;\n";
		//----------------------------------------------------------------------


		file.close();
	}
}
void 判断模拟振配置(const std::string& line)
{
	std::istringstream iss(line);
	std::string token;
	std::string paramName;
	float paramValue;

	if (std::getline(iss, token, '='))
	{
		paramName = token;
		if (std::getline(iss, token))
		{
			paramValue = std::stof(token);
			//长剑
			if (strstr(paramName.c_str(), "长剑左3距离") != NULL) { 振刀参数::距离::长剑.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右3距离") != NULL) { 振刀参数::距离::长剑.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气距离") != NULL) { 振刀参数::距离::长剑.左剑气 = paramValue; }
			//if (strstr(paramName.c_str(), "长剑左剑气距离") != NULL) { 振刀参数::距离::长剑.左剑气 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气距离") != NULL) { 振刀参数::距离::长剑.右剑气 = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽距离") != NULL) { 振刀参数::距离::长剑.凤凰羽 = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月距离") != NULL) { 振刀参数::距离::长剑.蓝月 = paramValue; }
			if (strstr(paramName.c_str(), "长剑七星夺窍距离") != NULL) { 振刀参数::距离::长剑.七星夺窍 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "长剑左3角度") != NULL) { 振刀参数::角度::长剑.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右3角度") != NULL) { 振刀参数::角度::长剑.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气2M角度") != NULL) { 振刀参数::角度::长剑.左剑气2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气4M角度") != NULL) { 振刀参数::角度::长剑.左剑气4M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气6M角度") != NULL) { 振刀参数::角度::长剑.左剑气6M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气9M角度") != NULL) { 振刀参数::角度::长剑.左剑气9M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气9M外角度") != NULL) { 振刀参数::角度::长剑.左剑气9M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气2M角度") != NULL) { 振刀参数::角度::长剑.右剑气2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气4M角度") != NULL) { 振刀参数::角度::长剑.右剑气4M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气6M角度") != NULL) { 振刀参数::角度::长剑.右剑气6M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气9M角度") != NULL) { 振刀参数::角度::长剑.右剑气9M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气9M外角度") != NULL) { 振刀参数::角度::长剑.右剑气9M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽2M角度") != NULL) { 振刀参数::角度::长剑.凤凰羽2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽5M角度") != NULL) { 振刀参数::角度::长剑.凤凰羽5M = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽8M角度") != NULL) { 振刀参数::角度::长剑.凤凰羽8M = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽8M外角度") != NULL) { 振刀参数::角度::长剑.凤凰羽8M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月2M角度") != NULL) { 振刀参数::角度::长剑.蓝月2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月6M角度") != NULL) { 振刀参数::角度::长剑.蓝月6M = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月6M外角度") != NULL) { 振刀参数::角度::长剑.蓝月6M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑七星夺窍角度") != NULL) { 振刀参数::角度::长剑.七星夺窍 = paramValue; }
			//太刀
			if (strstr(paramName.c_str(), "太刀左3距离") != NULL) { 振刀参数::距离::太刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右3距离") != NULL) { 振刀参数::距离::太刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左蓄距离") != NULL) { 振刀参数::距离::太刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右蓄距离") != NULL) { 振刀参数::距离::太刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左惊雷距离") != NULL) { 振刀参数::距离::太刀.左惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右惊雷&惊雷十劫距离") != NULL) { 振刀参数::距离::太刀.右惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左青鬼距离") != NULL) { 振刀参数::距离::太刀.左青鬼 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右青鬼距离") != NULL) { 振刀参数::距离::太刀.右青鬼 = paramValue; }
			if (strstr(paramName.c_str(), "太刀噬魂斩距离") != NULL) { 振刀参数::距离::太刀.噬魂斩 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "太刀左3角度") != NULL) { 振刀参数::角度::太刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右3角度") != NULL) { 振刀参数::角度::太刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左蓄2M角度") != NULL) { 振刀参数::角度::太刀.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "太刀左蓄2M外角度") != NULL) { 振刀参数::角度::太刀.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右蓄2M角度") != NULL) { 振刀参数::角度::太刀.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "太刀右蓄2M外角度") != NULL) { 振刀参数::角度::太刀.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左惊雷角度") != NULL) { 振刀参数::角度::太刀.左惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右惊雷5M角度") != NULL) { 振刀参数::角度::太刀.右惊雷5M = paramValue; }
			if (strstr(paramName.c_str(), "太刀右惊雷5M外角度") != NULL) { 振刀参数::角度::太刀.右惊雷5M外 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左青鬼角度") != NULL) { 振刀参数::角度::太刀.左青鬼 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右青鬼角度") != NULL) { 振刀参数::角度::太刀.右青鬼 = paramValue; }
			//阔刀
			if (strstr(paramName.c_str(), "阔刀左左距离") != NULL) { 振刀参数::距离::阔刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左右距离") != NULL) { 振刀参数::距离::阔刀.左右 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右距离") != NULL) { 振刀参数::距离::阔刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右左距离") != NULL) { 振刀参数::距离::阔刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄一段距离") != NULL) { 振刀参数::距离::阔刀.左蓄一段 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄二段距离") != NULL) { 振刀参数::距离::阔刀.左蓄二段 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄三段距离") != NULL) { 振刀参数::距离::阔刀.左蓄三段 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右蓄距离") != NULL) { 振刀参数::距离::阔刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右蓄距离") != NULL) { 振刀参数::距离::阔刀.右右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀雷刀距离") != NULL) { 振刀参数::距离::阔刀.雷刀 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀雷刀下劈距离") != NULL) { 振刀参数::距离::阔刀.雷刀下劈 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "阔刀左左角度") != NULL) { 振刀参数::角度::阔刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左右2M角度") != NULL) { 振刀参数::角度::阔刀.左右2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左右2M外角度") != NULL) { 振刀参数::角度::阔刀.左右2M外 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右角度") != NULL) { 振刀参数::角度::阔刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右左角度") != NULL) { 振刀参数::角度::阔刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄一段2M角度") != NULL) { 振刀参数::角度::阔刀.左蓄一段2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄一段2M外角度") != NULL) { 振刀参数::角度::阔刀.左蓄一段2M外 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右蓄2M角度") != NULL) { 振刀参数::角度::阔刀.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右蓄2M外角度") != NULL) { 振刀参数::角度::阔刀.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右蓄2M角度") != NULL) { 振刀参数::角度::阔刀.右右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右蓄2M外角度") != NULL) { 振刀参数::角度::阔刀.右右蓄2M外 = paramValue; }
			//长枪
			if (strstr(paramName.c_str(), "长枪左3距离") != NULL) { 振刀参数::距离::长枪.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右3距离") != NULL) { 振刀参数::距离::长枪.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪左蓄距离") != NULL) { 振刀参数::距离::长枪.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪六合枪距离") != NULL) { 振刀参数::距离::长枪.六合枪 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右蓄距离") != NULL) { 振刀参数::距离::长枪.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪大圣游距离") != NULL) { 振刀参数::距离::长枪.大圣游 = paramValue; }
			if (strstr(paramName.c_str(), "长枪风卷云残距离") != NULL) { 振刀参数::距离::长枪.风卷云残 = paramValue; }
			if (strstr(paramName.c_str(), "长枪双环扫距离") != NULL) { 振刀参数::距离::长枪.双环扫 = paramValue; }
			if (strstr(paramName.c_str(), "长枪龙王破距离") != NULL) { 振刀参数::距离::长枪.龙王破 = paramValue; }
			if (strstr(paramName.c_str(), "长枪穿心脚距离") != NULL) { 振刀参数::距离::长枪.穿心脚 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "长枪左3角度") != NULL) { 振刀参数::角度::长枪.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右3角度") != NULL) { 振刀参数::角度::长枪.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪左蓄角度") != NULL) { 振刀参数::角度::长枪.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪六合枪2M角度") != NULL) { 振刀参数::角度::长枪.六合枪2M = paramValue; }
			if (strstr(paramName.c_str(), "长枪六合枪2M外角度") != NULL) { 振刀参数::角度::长枪.六合枪2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右蓄角度") != NULL) { 振刀参数::角度::长枪.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪大圣游角度") != NULL) { 振刀参数::角度::长枪.大圣游 = paramValue; }
			if (strstr(paramName.c_str(), "长枪风卷云残角度") != NULL) { 振刀参数::角度::长枪.风卷云残 = paramValue; }
			if (strstr(paramName.c_str(), "长枪龙王破2M角度") != NULL) { 振刀参数::角度::长枪.龙王破2M = paramValue; }
			if (strstr(paramName.c_str(), "长枪龙王破2M外角度") != NULL) { 振刀参数::角度::长枪.龙王破2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长枪穿心脚2M角度") != NULL) { 振刀参数::角度::长枪.穿心脚2M = paramValue; }
			if (strstr(paramName.c_str(), "长枪穿心脚2M外角度") != NULL) { 振刀参数::角度::长枪.穿心脚2M外 = paramValue; }
			//匕首
			if (strstr(paramName.c_str(), "匕首左3距离") != NULL) { 振刀参数::距离::匕首.左3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右3距离") != NULL) { 振刀参数::距离::匕首.右3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首左蓄距离") != NULL) { 振刀参数::距离::匕首.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右蓄距离") != NULL) { 振刀参数::距离::匕首.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼反距离") != NULL) { 振刀参数::距离::匕首.鬼反 = paramValue; }
			if (strstr(paramName.c_str(), "匕首荆轲献匕距离") != NULL) { 振刀参数::距离::匕首.荆轲献匕 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼刃暗扎距离") != NULL) { 振刀参数::距离::匕首.鬼刃暗扎 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼哭神嚎距离") != NULL) { 振刀参数::距离::匕首.鬼哭神嚎 = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔距离") != NULL) { 振刀参数::距离::匕首.亢龙有悔 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "匕首左3角度") != NULL) { 振刀参数::角度::匕首.左3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右3角度") != NULL) { 振刀参数::角度::匕首.右3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首左蓄2M角度") != NULL) { 振刀参数::角度::匕首.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首左蓄2M外角度") != NULL) { 振刀参数::角度::匕首.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右蓄2M角度") != NULL) { 振刀参数::角度::匕首.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首右蓄2M外角度") != NULL) { 振刀参数::角度::匕首.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼反角度") != NULL) { 振刀参数::角度::匕首.鬼反 = paramValue; }
			if (strstr(paramName.c_str(), "匕首荆轲献匕2M角度") != NULL) { 振刀参数::角度::匕首.荆轲献匕2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首荆轲献匕2M外角度") != NULL) { 振刀参数::角度::匕首.荆轲献匕2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼刃暗扎2M角度") != NULL) { 振刀参数::角度::匕首.鬼刃暗扎2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼刃暗扎2M外角度") != NULL) { 振刀参数::角度::匕首.鬼刃暗扎2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔2M角度") != NULL) { 振刀参数::角度::匕首.亢龙有悔2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔4M角度") != NULL) { 振刀参数::角度::匕首.亢龙有悔4M = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔4M外角度") != NULL) { 振刀参数::角度::匕首.亢龙有悔4M外 = paramValue; }
			//双截棍
			if (strstr(paramName.c_str(), "双截棍左右3距离") != NULL) { 振刀参数::距离::双截棍.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍左蓄距离") != NULL) { 振刀参数::距离::双截棍.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍右蓄距离") != NULL) { 振刀参数::距离::双截棍.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍飞踢距离") != NULL) { 振刀参数::距离::双截棍.飞踢 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍扬鞭劲距离") != NULL) { 振刀参数::距离::双截棍.扬鞭劲 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍横栏距离") != NULL) { 振刀参数::距离::双截棍.横栏 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍龙虎乱舞距离") != NULL) { 振刀参数::距离::双截棍.龙虎乱舞 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "双截棍左右3角度") != NULL) { 振刀参数::角度::双截棍.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍左蓄2M角度") != NULL) { 振刀参数::角度::双截棍.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "双截棍左蓄2M外角度") != NULL) { 振刀参数::角度::双截棍.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍右蓄2M角度") != NULL) { 振刀参数::角度::双截棍.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "双截棍右蓄2M外角度") != NULL) { 振刀参数::角度::双截棍.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍飞踢角度") != NULL) { 振刀参数::角度::双截棍.飞踢 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍扬鞭劲角度") != NULL) { 振刀参数::角度::双截棍.扬鞭劲 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍横栏角度") != NULL) { 振刀参数::角度::双截棍.横栏 = paramValue; }
			//双刀
			if (strstr(paramName.c_str(), "双刀左右3距离") != NULL) { 振刀参数::距离::双刀.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双刀左蓄距离") != NULL) { 振刀参数::距离::双刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀右蓄距离") != NULL) { 振刀参数::距离::双刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀铁马残红距离") != NULL) { 振刀参数::距离::双刀.铁马残红 = paramValue; }
			if (strstr(paramName.c_str(), "双刀乾坤日月斩距离") != NULL) { 振刀参数::距离::双刀.乾坤日月斩 = paramValue; }
			if (strstr(paramName.c_str(), "双刀惊雷距离") != NULL) { 振刀参数::距离::双刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "双刀八斩刀距离") != NULL) { 振刀参数::距离::双刀.八斩刀 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "双刀左右3角度") != NULL) { 振刀参数::角度::双刀.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双刀左蓄角度") != NULL) { 振刀参数::角度::双刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀右蓄角度") != NULL) { 振刀参数::角度::双刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀铁马残红3M角度") != NULL) { 振刀参数::角度::双刀.铁马残红3M = paramValue; }
			if (strstr(paramName.c_str(), "双刀铁马残红3M外角度") != NULL) { 振刀参数::角度::双刀.铁马残红3M外 = paramValue; }
			if (strstr(paramName.c_str(), "双刀乾坤日月斩角度") != NULL) { 振刀参数::角度::双刀.乾坤日月斩 = paramValue; }
			if (strstr(paramName.c_str(), "双刀惊雷角度") != NULL) { 振刀参数::角度::双刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "双刀八斩刀角度") != NULL) { 振刀参数::角度::双刀.八斩刀 = paramValue; }
			//长棍
			if (strstr(paramName.c_str(), "长棍左3距离") != NULL) { 振刀参数::距离::长棍.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍右3距离") != NULL) { 振刀参数::距离::长棍.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍少林棍距离") != NULL) { 振刀参数::距离::长棍.少林棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍左蓄距离") != NULL) { 振刀参数::距离::长棍.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长棍右蓄距离") != NULL) { 振刀参数::距离::长棍.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长棍腾云式距离") != NULL) { 振刀参数::距离::长棍.腾云式 = paramValue; }
			if (strstr(paramName.c_str(), "长棍乱点天宫距离") != NULL) { 振刀参数::距离::长棍.乱点天宫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍桶劲距离") != NULL) { 振刀参数::距离::长棍.桶劲 = paramValue; }
			if (strstr(paramName.c_str(), "长棍五情七灭镇距离") != NULL) { 振刀参数::距离::长棍.五情七灭镇 = paramValue; }
			if (strstr(paramName.c_str(), "长棍双环扫距离") != NULL) { 振刀参数::距离::长棍.双环扫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍倒海棍距离") != NULL) { 振刀参数::距离::长棍.倒海棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍镇地撑天距离") != NULL) { 振刀参数::距离::长棍.镇地撑天 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "长棍左3角度") != NULL) { 振刀参数::角度::长棍.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍右3角度") != NULL) { 振刀参数::角度::长棍.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍少林棍角度") != NULL) { 振刀参数::角度::长棍.少林棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍左蓄2M角度") != NULL) { 振刀参数::角度::长棍.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "长棍左蓄2M外角度") != NULL) { 振刀参数::角度::长棍.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长棍腾云式2M角度") != NULL) { 振刀参数::角度::长棍.腾云式2M = paramValue; }
			if (strstr(paramName.c_str(), "长棍腾云式2M外角度") != NULL) { 振刀参数::角度::长棍.腾云式2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长棍乱点天宫角度") != NULL) { 振刀参数::角度::长棍.乱点天宫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍桶劲角度") != NULL) { 振刀参数::角度::长棍.桶劲 = paramValue; }
			if (strstr(paramName.c_str(), "长棍五情七灭镇8M角度") != NULL) { 振刀参数::角度::长棍.五情七灭镇8M = paramValue; }
			if (strstr(paramName.c_str(), "长棍五情七灭镇8M外角度") != NULL) { 振刀参数::角度::长棍.五情七灭镇8M外 = paramValue; }
			if (strstr(paramName.c_str(), "长棍双环扫角度") != NULL) { 振刀参数::角度::长棍.双环扫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍倒海棍角度") != NULL) { 振刀参数::角度::长棍.倒海棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍镇地撑天角度") != NULL) { 振刀参数::角度::长棍.镇地撑天 = paramValue; }
			//斩马刀
			if (strstr(paramName.c_str(), "斩马刀左左距离") != NULL) { 振刀参数::距离::斩马刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左右距离") != NULL) { 振刀参数::距离::斩马刀.左右 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右右距离") != NULL) { 振刀参数::距离::斩马刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右左距离") != NULL) { 振刀参数::距离::斩马刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左蓄距离") != NULL) { 振刀参数::距离::斩马刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右蓄距离") != NULL) { 振刀参数::距离::斩马刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀柄击距离") != NULL) { 振刀参数::距离::斩马刀.柄击 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀惊雷距离") != NULL) { 振刀参数::距离::斩马刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀炽焰斩距离") != NULL) { 振刀参数::距离::斩马刀.炽焰斩 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀过关斩将距离") != NULL) { 振刀参数::距离::斩马刀.过关斩将 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "斩马刀左左角度") != NULL) { 振刀参数::角度::斩马刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左右2M角度") != NULL) { 振刀参数::角度::斩马刀.左右2M = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左右2M外角度") != NULL) { 振刀参数::角度::斩马刀.左右2M外 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右右角度") != NULL) { 振刀参数::角度::斩马刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右左角度") != NULL) { 振刀参数::角度::斩马刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左蓄2M角度") != NULL) { 振刀参数::角度::斩马刀.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左蓄2M外角度") != NULL) { 振刀参数::角度::斩马刀.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右蓄角度") != NULL) { 振刀参数::角度::斩马刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀柄击角度") != NULL) { 振刀参数::角度::斩马刀.柄击 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀惊雷角度") != NULL) { 振刀参数::角度::斩马刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀炽焰斩角度") != NULL) { 振刀参数::角度::斩马刀.炽焰斩 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀过关斩将角度") != NULL) { 振刀参数::角度::斩马刀.过关斩将 = paramValue; }
			//双戟
			if (strstr(paramName.c_str(), "双戟左右3距离") != NULL) { 振刀参数::距离::双戟.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双戟左蓄距离") != NULL) { 振刀参数::距离::双戟.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双戟右蓄距离") != NULL) { 振刀参数::距离::双戟.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双戟勾旋斩距离") != NULL) { 振刀参数::距离::双戟.勾旋斩 = paramValue; }
			if (strstr(paramName.c_str(), "双戟探海蛟距离") != NULL) { 振刀参数::距离::双戟.探海蛟 = paramValue; }
			if (strstr(paramName.c_str(), "双戟钩挂距离") != NULL) { 振刀参数::距离::双戟.钩挂 = paramValue; }
			if (strstr(paramName.c_str(), "双戟战龙在天距离") != NULL) { 振刀参数::距离::双戟.战龙在天 = paramValue; }
			if (strstr(paramName.c_str(), "双戟形意钩距离") != NULL) { 振刀参数::距离::双戟.形意钩 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "双戟左右3角度") != NULL) { 振刀参数::角度::双戟.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双戟左蓄3M角度") != NULL) { 振刀参数::角度::双戟.左蓄3M = paramValue; }
			if (strstr(paramName.c_str(), "双戟左蓄3M外角度") != NULL) { 振刀参数::角度::双戟.左蓄3M外 = paramValue; }
			if (strstr(paramName.c_str(), "双戟右蓄3M角度") != NULL) { 振刀参数::角度::双戟.右蓄3M = paramValue; }
			if (strstr(paramName.c_str(), "双戟右蓄3M外角度") != NULL) { 振刀参数::角度::双戟.右蓄3M外 = paramValue; }
			if (strstr(paramName.c_str(), "双戟勾旋斩角度") != NULL) { 振刀参数::角度::双戟.勾旋斩 = paramValue; }
			if (strstr(paramName.c_str(), "双戟探海蛟角度") != NULL) { 振刀参数::角度::双戟.探海蛟 = paramValue; }
			if (strstr(paramName.c_str(), "双戟钩挂角度") != NULL) { 振刀参数::角度::双戟.钩挂 = paramValue; }
			if (strstr(paramName.c_str(), "双戟战龙在天角度") != NULL) { 振刀参数::角度::双戟.战龙在天 = paramValue; }
			if (strstr(paramName.c_str(), "双戟形意钩角度") != NULL) { 振刀参数::角度::双戟.形意钩 = paramValue; }
			//扇子
			if (strstr(paramName.c_str(), "扇子左3距离") != NULL) { 振刀参数::距离::扇子.左3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右3距离") != NULL) { 振刀参数::距离::扇子.右3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子左蓄距离") != NULL) { 振刀参数::距离::扇子.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右蓄距离") != NULL) { 振刀参数::距离::扇子.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "扇子双开圆距离") != NULL) { 振刀参数::距离::扇子.双开圆 = paramValue; }
			if (strstr(paramName.c_str(), "扇子三风摆距离") != NULL) { 振刀参数::距离::扇子.三风摆 = paramValue; }
			if (strstr(paramName.c_str(), "扇子惊雷距离") != NULL) { 振刀参数::距离::扇子.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "扇子缠龙奔野距离") != NULL) { 振刀参数::距离::扇子.缠龙奔野 = paramValue; }
			if (strstr(paramName.c_str(), "扇子鬼反距离") != NULL) { 振刀参数::距离::扇子.鬼反 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "扇子左3角度") != NULL) { 振刀参数::角度::扇子.左3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右3角度") != NULL) { 振刀参数::角度::扇子.右3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子左蓄角度") != NULL) { 振刀参数::角度::扇子.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右蓄2M角度") != NULL) { 振刀参数::角度::扇子.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "扇子右蓄2M外角度") != NULL) { 振刀参数::角度::扇子.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "扇子双开圆角度") != NULL) { 振刀参数::角度::扇子.双开圆 = paramValue; }
			if (strstr(paramName.c_str(), "扇子三风摆3M角度") != NULL) { 振刀参数::角度::扇子.三风摆3M = paramValue; }
			if (strstr(paramName.c_str(), "扇子三风摆3M外角度") != NULL) { 振刀参数::角度::扇子.三风摆3M外 = paramValue; }
			if (strstr(paramName.c_str(), "扇子惊雷角度") != NULL) { 振刀参数::角度::扇子.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "扇子缠龙奔野3M角度") != NULL) { 振刀参数::角度::扇子.缠龙奔野3M = paramValue; }
			if (strstr(paramName.c_str(), "扇子缠龙奔野3M外角度") != NULL) { 振刀参数::角度::扇子.缠龙奔野3M外 = paramValue; }
			if (strstr(paramName.c_str(), "扇子鬼反角度") != NULL) { 振刀参数::角度::扇子.鬼反 = paramValue; }
			//横刀
			if (strstr(paramName.c_str(), "横刀左3距离") != NULL) { 振刀参数::距离::横刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右3距离") != NULL) { 振刀参数::距离::横刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀左蓄距离") != NULL) { 振刀参数::距离::横刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右蓄距离") != NULL) { 振刀参数::距离::横刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀破千军距离") != NULL) { 振刀参数::距离::横刀.破千军 = paramValue; }
			if (strstr(paramName.c_str(), "横刀极光破云闪距离") != NULL) { 振刀参数::距离::横刀.极光破云闪 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "横刀左3角度") != NULL) { 振刀参数::角度::横刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右3角度") != NULL) { 振刀参数::角度::横刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀左蓄角度") != NULL) { 振刀参数::角度::横刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右蓄角度") != NULL) { 振刀参数::角度::横刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀破千军角度") != NULL) { 振刀参数::角度::横刀.破千军 = paramValue; }
			if (strstr(paramName.c_str(), "横刀极光破云闪角度") != NULL) { 振刀参数::角度::横刀.极光破云闪 = paramValue; }

		}
	}
}
void 读取模拟振配置()
{
	std::ifstream file("模拟振配置.ini");
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			判断模拟振配置(line);
		}

		file.close();
	}
}

void 保存内存振配置()
{
	ofstream file("内存振配置.ini");
	if (file.is_open())
	{
		file << "长剑左3距离=" << 振刀参数::距离::长剑.左3 << "f;\n";
		file << "长剑右3距离=" << 振刀参数::距离::长剑.右3 << "f;\n";
		file << "长剑左剑气距离=" << 振刀参数::距离::长剑.左剑气 << "f;\n";
		file << "长剑右剑气距离=" << 振刀参数::距离::长剑.右剑气 << "f;\n";
		file << "长剑凤凰羽距离=" << 振刀参数::距离::长剑.凤凰羽 << "f;\n";
		file << "长剑蓝月距离=" << 振刀参数::距离::长剑.蓝月 << "f;\n";
		file << "长剑七星夺窍距离=" << 振刀参数::距离::长剑.七星夺窍 << "f;\n";
		file << "长剑左3角度=" << 振刀参数::角度::长剑.左3 << "f;\n";
		file << "长剑右3角度=" << 振刀参数::角度::长剑.右3 << "f;\n";
		file << "长剑左剑气2M角度=" << 振刀参数::角度::长剑.左剑气2M << "f;\n";
		file << "长剑左剑气4M角度=" << 振刀参数::角度::长剑.左剑气4M << "f;\n";
		file << "长剑左剑气6M角度=" << 振刀参数::角度::长剑.左剑气6M << "f;\n";
		file << "长剑左剑气9M角度=" << 振刀参数::角度::长剑.左剑气9M << "f;\n";
		file << "长剑左剑气9M外角度=" << 振刀参数::角度::长剑.左剑气9M外 << "f;\n";
		file << "长剑右剑气2M角度=" << 振刀参数::角度::长剑.右剑气2M << "f;\n";
		file << "长剑右剑气4M角度=" << 振刀参数::角度::长剑.右剑气4M << "f;\n";
		file << "长剑右剑气6M角度=" << 振刀参数::角度::长剑.右剑气6M << "f;\n";
		file << "长剑右剑气9M角度=" << 振刀参数::角度::长剑.右剑气9M << "f;\n";
		file << "长剑右剑气9M外角度=" << 振刀参数::角度::长剑.右剑气9M外 << "f;\n";
		file << "长剑凤凰羽2M角度=" << 振刀参数::角度::长剑.凤凰羽2M << "f;\n";
		file << "长剑凤凰羽5M角度=" << 振刀参数::角度::长剑.凤凰羽5M << "f;\n";
		file << "长剑凤凰羽8M角度=" << 振刀参数::角度::长剑.凤凰羽8M << "f;\n";
		file << "长剑凤凰羽8M外角度=" << 振刀参数::角度::长剑.凤凰羽8M外 << "f;\n";
		file << "长剑蓝月2M角度=" << 振刀参数::角度::长剑.蓝月2M << "f;\n";
		file << "长剑蓝月6M角度=" << 振刀参数::角度::长剑.蓝月6M << "f;\n";
		file << "长剑蓝月6M外角度=" << 振刀参数::角度::长剑.蓝月6M外 << "f;\n";
		file << "长剑七星夺窍角度=" << 振刀参数::角度::长剑.七星夺窍 << "f;\n";

		file << "太刀左3距离=" << 振刀参数::距离::太刀.左3 << "f;\n";
		file << "太刀右3距离=" << 振刀参数::距离::太刀.右3 << "f;\n";
		file << "太刀左蓄距离=" << 振刀参数::距离::太刀.左蓄 << "f;\n";
		file << "太刀右蓄距离=" << 振刀参数::距离::太刀.右蓄 << "f;\n";
		file << "太刀左惊雷距离=" << 振刀参数::距离::太刀.左惊雷 << "f;\n";
		file << "太刀右惊雷&惊雷十劫距离=" << 振刀参数::距离::太刀.右惊雷 << "f;\n";
		file << "太刀左青鬼距离=" << 振刀参数::距离::太刀.左青鬼 << "f;\n";
		file << "太刀右青鬼距离=" << 振刀参数::距离::太刀.右青鬼 << "f;\n";
		file << "太刀噬魂斩距离=" << 振刀参数::距离::太刀.噬魂斩 << "f;\n";

		file << "太刀左3角度=" << 振刀参数::角度::太刀.左3 << "f;\n";
		file << "太刀右3角度=" << 振刀参数::角度::太刀.右3 << "f;\n";
		file << "太刀左蓄2M角度=" << 振刀参数::角度::太刀.左蓄2M << "f;\n";
		file << "太刀左蓄2M外角度=" << 振刀参数::角度::太刀.左蓄2M外 << "f;\n";
		file << "太刀右蓄2M角度=" << 振刀参数::角度::太刀.右蓄2M << "f;\n";
		file << "太刀右蓄2M外角度=" << 振刀参数::角度::太刀.右蓄2M外 << "f;\n";
		file << "太刀左惊雷角度=" << 振刀参数::角度::太刀.左惊雷 << "f;\n";
		file << "太刀右惊雷5M角度=" << 振刀参数::角度::太刀.右惊雷5M << "f;\n";
		file << "太刀右惊雷5M外角度=" << 振刀参数::角度::太刀.右惊雷5M外 << "f;\n";
		file << "太刀左青鬼角度=" << 振刀参数::角度::太刀.左青鬼 << "f;\n";
		file << "太刀右青鬼角度=" << 振刀参数::角度::太刀.右青鬼 << "f;\n";

		file << "阔刀左左距离=" << 振刀参数::距离::阔刀.左左 << "f;\n";
		file << "阔刀左右距离=" << 振刀参数::距离::阔刀.左右 << "f;\n";
		file << "阔刀右右距离=" << 振刀参数::距离::阔刀.右右 << "f;\n";
		file << "阔刀右左距离=" << 振刀参数::距离::阔刀.右左 << "f;\n";
		file << "阔刀左蓄一段距离=" << 振刀参数::距离::阔刀.左蓄一段 << "f;\n";
		file << "阔刀左蓄二段距离=" << 振刀参数::距离::阔刀.左蓄二段 << "f;\n";
		file << "阔刀左蓄三段距离=" << 振刀参数::距离::阔刀.左蓄三段 << "f;\n";
		file << "阔刀右蓄距离=" << 振刀参数::距离::阔刀.右蓄 << "f;\n";
		file << "阔刀右右蓄距离=" << 振刀参数::距离::阔刀.右右蓄 << "f;\n";
		file << "阔刀雷刀距离=" << 振刀参数::距离::阔刀.雷刀 << "f;\n";
		file << "阔刀雷刀下劈距离=" << 振刀参数::距离::阔刀.雷刀下劈 << "f;\n";

		file << "阔刀左左角度=" << 振刀参数::角度::阔刀.左左 << "f;\n";
		file << "阔刀左右2M角度=" << 振刀参数::角度::阔刀.左右2M << "f;\n";
		file << "阔刀左右2M外角度=" << 振刀参数::角度::阔刀.左右2M外 << "f;\n";
		file << "阔刀右右角度=" << 振刀参数::角度::阔刀.右右 << "f;\n";
		file << "阔刀右左角度=" << 振刀参数::角度::阔刀.右左 << "f;\n";
		file << "阔刀左蓄一段2M角度=" << 振刀参数::角度::阔刀.左蓄一段2M << "f;\n";
		file << "阔刀左蓄一段2M外角度=" << 振刀参数::角度::阔刀.左蓄一段2M外 << "f;\n";
		file << "阔刀右蓄2M角度=" << 振刀参数::角度::阔刀.右蓄2M << "f;\n";
		file << "阔刀右蓄2M外角度=" << 振刀参数::角度::阔刀.右蓄2M外 << "f;\n";
		file << "阔刀右右蓄2M角度=" << 振刀参数::角度::阔刀.右右蓄2M << "f;\n";
		file << "阔刀右右蓄2M外角度=" << 振刀参数::角度::阔刀.右右蓄2M外 << "f;\n";

		file << "长枪左3距离=" << 振刀参数::距离::长枪.左3 << "f;\n";
		file << "长枪右3距离=" << 振刀参数::距离::长枪.右3 << "f;\n";
		file << "长枪左蓄距离=" << 振刀参数::距离::长枪.左蓄 << "f;\n";
		file << "长枪六合枪距离=" << 振刀参数::距离::长枪.六合枪 << "f;\n";
		file << "长枪右蓄距离=" << 振刀参数::距离::长枪.右蓄 << "f;\n";
		file << "长枪大圣游距离=" << 振刀参数::距离::长枪.大圣游 << "f;\n";
		file << "长枪风卷云残距离=" << 振刀参数::距离::长枪.风卷云残 << "f;\n";
		file << "长枪双环扫距离=" << 振刀参数::距离::长枪.双环扫 << "f;\n";
		file << "长枪龙王破距离=" << 振刀参数::距离::长枪.龙王破 << "f;\n";
		file << "长枪穿心脚距离=" << 振刀参数::距离::长枪.穿心脚 << "f;\n";

		file << "长枪左3角度=" << 振刀参数::角度::长枪.左3 << "f;\n";
		file << "长枪右3角度=" << 振刀参数::角度::长枪.右3 << "f;\n";
		file << "长枪左蓄角度=" << 振刀参数::角度::长枪.左蓄 << "f;\n";
		file << "长枪六合枪2M角度=" << 振刀参数::角度::长枪.六合枪2M << "f;\n";
		file << "长枪六合枪2M外角度=" << 振刀参数::角度::长枪.六合枪2M外 << "f;\n";
		file << "长枪右蓄角度=" << 振刀参数::角度::长枪.右蓄 << "f;\n";
		file << "长枪大圣游角度=" << 振刀参数::角度::长枪.大圣游 << "f;\n";
		file << "长枪风卷云残角度=" << 振刀参数::角度::长枪.风卷云残 << "f;\n";
		file << "长枪龙王破2M角度=" << 振刀参数::角度::长枪.龙王破2M << "f;\n";
		file << "长枪龙王破2M外角度=" << 振刀参数::角度::长枪.龙王破2M外 << "f;\n";
		file << "长枪穿心脚2M角度=" << 振刀参数::角度::长枪.穿心脚2M << "f;\n";
		file << "长枪穿心脚2M外角度=" << 振刀参数::角度::长枪.穿心脚2M外 << "f;\n";

		file << "匕首左3距离=" << 振刀参数::距离::匕首.左3 << "f;\n";
		file << "匕首右3距离=" << 振刀参数::距离::匕首.右3 << "f;\n";
		file << "匕首左蓄距离=" << 振刀参数::距离::匕首.左蓄 << "f;\n";
		file << "匕首右蓄距离=" << 振刀参数::距离::匕首.右蓄 << "f;\n";
		file << "匕首鬼反距离=" << 振刀参数::距离::匕首.鬼反 << "f;\n";
		file << "匕首荆轲献匕距离=" << 振刀参数::距离::匕首.荆轲献匕 << "f;\n";
		file << "匕首鬼刃暗扎距离=" << 振刀参数::距离::匕首.鬼刃暗扎 << "f;\n";
		file << "匕首鬼哭神嚎距离=" << 振刀参数::距离::匕首.鬼哭神嚎 << "f;\n";
		file << "匕首亢龙有悔距离=" << 振刀参数::距离::匕首.亢龙有悔 << "f;\n";

		file << "匕首左3角度=" << 振刀参数::角度::匕首.左3 << "f;\n";
		file << "匕首右3角度=" << 振刀参数::角度::匕首.右3 << "f;\n";
		file << "匕首左蓄2M角度=" << 振刀参数::角度::匕首.左蓄2M << "f;\n";
		file << "匕首左蓄2M外角度=" << 振刀参数::角度::匕首.左蓄2M外 << "f;\n";
		file << "匕首右蓄2M角度=" << 振刀参数::角度::匕首.右蓄2M << "f;\n";
		file << "匕首右蓄2M外角度=" << 振刀参数::角度::匕首.右蓄2M外 << "f;\n";
		file << "匕首鬼反角度=" << 振刀参数::角度::匕首.鬼反 << "f;\n";
		file << "匕首荆轲献匕2M角度=" << 振刀参数::角度::匕首.荆轲献匕2M << "f;\n";
		file << "匕首荆轲献匕2M外角度=" << 振刀参数::角度::匕首.荆轲献匕2M外 << "f;\n";
		file << "匕首鬼刃暗扎2M角度=" << 振刀参数::角度::匕首.鬼刃暗扎2M << "f;\n";
		file << "匕首鬼刃暗扎2M外角度=" << 振刀参数::角度::匕首.鬼刃暗扎2M外 << "f;\n";
		file << "匕首亢龙有悔2M角度=" << 振刀参数::角度::匕首.亢龙有悔2M << "f;\n";
		file << "匕首亢龙有悔4M角度=" << 振刀参数::角度::匕首.亢龙有悔4M << "f;\n";
		file << "匕首亢龙有悔4M外角度=" << 振刀参数::角度::匕首.亢龙有悔4M外 << "f;\n";

		file << "双截棍左右3距离=" << 振刀参数::距离::双截棍.左右3 << "f;\n";
		file << "双截棍左蓄距离=" << 振刀参数::距离::双截棍.左蓄 << "f;\n";
		file << "双截棍右蓄距离=" << 振刀参数::距离::双截棍.右蓄 << "f;\n";
		file << "双截棍飞踢距离=" << 振刀参数::距离::双截棍.飞踢 << "f;\n";
		file << "双截棍扬鞭劲距离=" << 振刀参数::距离::双截棍.扬鞭劲 << "f;\n";
		file << "双截棍横栏距离=" << 振刀参数::距离::双截棍.横栏 << "f;\n";
		file << "双截棍龙虎乱舞距离=" << 振刀参数::距离::双截棍.龙虎乱舞 << "f;\n";

		file << "双截棍左右3角度=" << 振刀参数::角度::双截棍.左右3 << "f;\n";
		file << "双截棍左蓄2M角度=" << 振刀参数::角度::双截棍.左蓄2M << "f;\n";
		file << "双截棍左蓄2M外角度=" << 振刀参数::角度::双截棍.左蓄2M外 << "f;\n";
		file << "双截棍右蓄2M角度=" << 振刀参数::角度::双截棍.右蓄2M << "f;\n";
		file << "双截棍右蓄2M外角度=" << 振刀参数::角度::双截棍.右蓄2M外 << "f;\n";
		file << "双截棍飞踢角度=" << 振刀参数::角度::双截棍.飞踢 << "f;\n";
		file << "双截棍扬鞭劲角度=" << 振刀参数::角度::双截棍.扬鞭劲 << "f;\n";
		file << "双截棍横栏角度=" << 振刀参数::角度::双截棍.横栏 << "f;\n";

		file << "双刀左右3距离=" << 振刀参数::距离::双刀.左右3 << "f;\n";
		file << "双刀左蓄距离=" << 振刀参数::距离::双刀.左蓄 << "f;\n";
		file << "双刀右蓄距离=" << 振刀参数::距离::双刀.右蓄 << "f;\n";
		file << "双刀铁马残红距离=" << 振刀参数::距离::双刀.铁马残红 << "f;\n";
		file << "双刀乾坤日月斩距离=" << 振刀参数::距离::双刀.乾坤日月斩 << "f;\n";
		file << "双刀惊雷距离=" << 振刀参数::距离::双刀.惊雷 << "f;\n";
		file << "双刀八斩刀距离=" << 振刀参数::距离::双刀.八斩刀 << "f;\n";

		file << "双刀左右3角度=" << 振刀参数::角度::双刀.左右3 << "f;\n";
		file << "双刀左蓄角度=" << 振刀参数::角度::双刀.左蓄 << "f;\n";
		file << "双刀右蓄角度=" << 振刀参数::角度::双刀.右蓄 << "f;\n";
		file << "双刀铁马残红3M角度=" << 振刀参数::角度::双刀.铁马残红3M << "f;\n";
		file << "双刀铁马残红3M外角度=" << 振刀参数::角度::双刀.铁马残红3M外 << "f;\n";
		file << "双刀乾坤日月斩角度=" << 振刀参数::角度::双刀.乾坤日月斩 << "f;\n";
		file << "双刀惊雷角度=" << 振刀参数::角度::双刀.惊雷 << "f;\n";
		file << "双刀八斩刀角度=" << 振刀参数::角度::双刀.八斩刀 << "f;\n";

		file << "长棍左3距离=" << 振刀参数::距离::长棍.左3 << "f;\n";
		file << "长棍右3距离=" << 振刀参数::距离::长棍.右3 << "f;\n";
		file << "长棍少林棍距离=" << 振刀参数::距离::长棍.少林棍 << "f;\n";
		file << "长棍左蓄距离=" << 振刀参数::距离::长棍.左蓄 << "f;\n";
		file << "长棍右蓄距离=" << 振刀参数::距离::长棍.右蓄 << "f;\n";
		file << "长棍腾云式距离=" << 振刀参数::距离::长棍.腾云式 << "f;\n";
		file << "长棍乱点天宫距离=" << 振刀参数::距离::长棍.乱点天宫 << "f;\n";
		file << "长棍桶劲距离=" << 振刀参数::距离::长棍.桶劲 << "f;\n";
		file << "长棍五情七灭镇距离=" << 振刀参数::距离::长棍.五情七灭镇 << "f;\n";
		file << "长棍双环扫距离=" << 振刀参数::距离::长棍.双环扫 << "f;\n";
		file << "长棍倒海棍距离=" << 振刀参数::距离::长棍.倒海棍 << "f;\n";
		file << "长棍镇地撑天距离=" << 振刀参数::距离::长棍.镇地撑天 << "f;\n";

		file << "长棍左3角度=" << 振刀参数::角度::长棍.左3 << "f;\n";
		file << "长棍右3角度=" << 振刀参数::角度::长棍.右3 << "f;\n";
		file << "长棍少林棍角度=" << 振刀参数::角度::长棍.少林棍 << "f;\n";
		file << "长棍左蓄2M角度=" << 振刀参数::角度::长棍.左蓄2M << "f;\n";
		file << "长棍左蓄2M外角度=" << 振刀参数::角度::长棍.左蓄2M外 << "f;\n";
		file << "长棍腾云式2M角度=" << 振刀参数::角度::长棍.腾云式2M << "f;\n";
		file << "长棍腾云式2M外角度=" << 振刀参数::角度::长棍.腾云式2M外 << "f;\n";
		file << "长棍乱点天宫角度=" << 振刀参数::角度::长棍.乱点天宫 << "f;\n";
		file << "长棍桶劲角度=" << 振刀参数::角度::长棍.桶劲 << "f;\n";
		file << "长棍五情七灭镇8M角度=" << 振刀参数::角度::长棍.五情七灭镇8M << "f;\n";
		file << "长棍五情七灭镇8M外角度=" << 振刀参数::角度::长棍.五情七灭镇8M外 << "f;\n";
		file << "长棍双环扫角度=" << 振刀参数::角度::长棍.双环扫 << "f;\n";
		file << "长棍倒海棍角度=" << 振刀参数::角度::长棍.倒海棍 << "f;\n";
		file << "长棍镇地撑天角度=" << 振刀参数::角度::长棍.镇地撑天 << "f;\n";

		file << "斩马刀左左距离=" << 振刀参数::距离::斩马刀.左左 << "f;\n";
		file << "斩马刀左右距离=" << 振刀参数::距离::斩马刀.左右 << "f;\n";
		file << "斩马刀右右距离=" << 振刀参数::距离::斩马刀.右右 << "f;\n";
		file << "斩马刀右左距离=" << 振刀参数::距离::斩马刀.右左 << "f;\n";
		file << "斩马刀左蓄距离=" << 振刀参数::距离::斩马刀.左蓄 << "f;\n";
		file << "斩马刀右蓄距离=" << 振刀参数::距离::斩马刀.右蓄 << "f;\n";
		file << "斩马刀柄击距离=" << 振刀参数::距离::斩马刀.柄击 << "f;\n";
		file << "斩马刀惊雷距离=" << 振刀参数::距离::斩马刀.惊雷 << "f;\n";
		file << "斩马刀炽焰斩距离=" << 振刀参数::距离::斩马刀.炽焰斩 << "f;\n";
		file << "斩马刀过关斩将距离=" << 振刀参数::距离::斩马刀.过关斩将 << "f;\n";

		file << "斩马刀左左角度=" << 振刀参数::角度::斩马刀.左左 << "f;\n";
		file << "斩马刀左右2M角度=" << 振刀参数::角度::斩马刀.左右2M << "f;\n";
		file << "斩马刀左右2M外角度=" << 振刀参数::角度::斩马刀.左右2M外 << "f;\n";
		file << "斩马刀右右角度=" << 振刀参数::角度::斩马刀.右右 << "f;\n";
		file << "斩马刀右左角度=" << 振刀参数::角度::斩马刀.右左 << "f;\n";
		file << "斩马刀左蓄2M角度=" << 振刀参数::角度::斩马刀.左蓄2M << "f;\n";
		file << "斩马刀左蓄2M外角度=" << 振刀参数::角度::斩马刀.左蓄2M外 << "f;\n";
		file << "斩马刀右蓄角度=" << 振刀参数::角度::斩马刀.右蓄 << "f;\n";
		file << "斩马刀柄击角度=" << 振刀参数::角度::斩马刀.柄击 << "f;\n";
		file << "斩马刀惊雷角度=" << 振刀参数::角度::斩马刀.惊雷 << "f;\n";
		file << "斩马刀炽焰斩角度=" << 振刀参数::角度::斩马刀.炽焰斩 << "f;\n";
		file << "斩马刀过关斩将角度=" << 振刀参数::角度::斩马刀.过关斩将 << "f;\n";

		file << "双戟左右3距离=" << 振刀参数::距离::双戟.左右3 << "f;\n";
		file << "双戟左蓄距离=" << 振刀参数::距离::双戟.左蓄 << "f;\n";
		file << "双戟右蓄距离=" << 振刀参数::距离::双戟.右蓄 << "f;\n";
		file << "双戟勾旋斩距离=" << 振刀参数::距离::双戟.勾旋斩 << "f;\n";
		file << "双戟探海蛟距离=" << 振刀参数::距离::双戟.探海蛟 << "f;\n";
		file << "双戟钩挂距离=" << 振刀参数::距离::双戟.钩挂 << "f;\n";
		file << "双戟战龙在天距离=" << 振刀参数::距离::双戟.战龙在天 << "f;\n";
		file << "双戟形意钩距离=" << 振刀参数::距离::双戟.形意钩 << "f;\n";

		file << "双戟左右3角度=" << 振刀参数::角度::双戟.左右3 << "f;\n";
		file << "双戟左蓄3M角度=" << 振刀参数::角度::双戟.左蓄3M << "f;\n";
		file << "双戟左蓄3M外角度=" << 振刀参数::角度::双戟.左蓄3M外 << "f;\n";
		file << "双戟右蓄3M角度=" << 振刀参数::角度::双戟.右蓄3M << "f;\n";
		file << "双戟右蓄3M外角度=" << 振刀参数::角度::双戟.右蓄3M外 << "f;\n";
		file << "双戟勾旋斩角度=" << 振刀参数::角度::双戟.勾旋斩 << "f;\n";
		file << "双戟探海蛟角度=" << 振刀参数::角度::双戟.探海蛟 << "f;\n";
		file << "双戟钩挂角度=" << 振刀参数::角度::双戟.钩挂 << "f;\n";
		file << "双戟战龙在天角度=" << 振刀参数::角度::双戟.战龙在天 << "f;\n";
		file << "双戟形意钩角度=" << 振刀参数::角度::双戟.形意钩 << "f;\n";

		file << "扇子左3距离=" << 振刀参数::距离::扇子.左3 << "f;\n";
		file << "扇子右3距离=" << 振刀参数::距离::扇子.右3 << "f;\n";
		file << "扇子左蓄距离=" << 振刀参数::距离::扇子.左蓄 << "f;\n";
		file << "扇子右蓄距离=" << 振刀参数::距离::扇子.右蓄 << "f;\n";
		file << "扇子双开圆距离=" << 振刀参数::距离::扇子.双开圆 << "f;\n";
		file << "扇子三风摆距离=" << 振刀参数::距离::扇子.三风摆 << "f;\n";
		file << "扇子惊雷距离=" << 振刀参数::距离::扇子.惊雷 << "f;\n";
		file << "扇子缠龙奔野距离=" << 振刀参数::距离::扇子.缠龙奔野 << "f;\n";
		file << "扇子鬼反距离=" << 振刀参数::距离::扇子.鬼反 << "f;\n";

		file << "扇子左3角度=" << 振刀参数::角度::扇子.左3 << "f;\n";
		file << "扇子右3角度=" << 振刀参数::角度::扇子.右3 << "f;\n";
		file << "扇子左蓄角度=" << 振刀参数::角度::扇子.左蓄 << "f;\n";
		file << "扇子右蓄2M角度=" << 振刀参数::角度::扇子.右蓄2M << "f;\n";
		file << "扇子右蓄2M外角度=" << 振刀参数::角度::扇子.右蓄2M外 << "f;\n";
		file << "扇子双开圆角度=" << 振刀参数::角度::扇子.双开圆 << "f;\n";
		file << "扇子三风摆3M角度=" << 振刀参数::角度::扇子.三风摆3M << "f;\n";
		file << "扇子三风摆3M外角度=" << 振刀参数::角度::扇子.三风摆3M外 << "f;\n";
		file << "扇子惊雷角度=" << 振刀参数::角度::扇子.惊雷 << "f;\n";
		file << "扇子缠龙奔野3M角度=" << 振刀参数::角度::扇子.缠龙奔野3M << "f;\n";
		file << "扇子缠龙奔野3M外角度=" << 振刀参数::角度::扇子.缠龙奔野3M外 << "f;\n";
		file << "扇子鬼反角度=" << 振刀参数::角度::扇子.鬼反 << "f;\n";

		file << "横刀左3距离=" << 振刀参数::距离::横刀.左3 << "f;\n";
		file << "横刀右3距离=" << 振刀参数::距离::横刀.右3 << "f;\n";
		file << "横刀左蓄距离=" << 振刀参数::距离::横刀.左蓄 << "f;\n";
		file << "横刀右蓄距离=" << 振刀参数::距离::横刀.右蓄 << "f;\n";
		file << "横刀破千军距离=" << 振刀参数::距离::横刀.破千军 << "f;\n";
		file << "横刀极光破云闪距离=" << 振刀参数::距离::横刀.极光破云闪 << "f;\n";

		file << "横刀左3角度=" << 振刀参数::角度::横刀.左3 << "f;\n";
		file << "横刀右3角度=" << 振刀参数::角度::横刀.右3 << "f;\n";
		file << "横刀左蓄角度=" << 振刀参数::角度::横刀.左蓄 << "f;\n";
		file << "横刀右蓄角度=" << 振刀参数::角度::横刀.右蓄 << "f;\n";
		file << "横刀破千军角度=" << 振刀参数::角度::横刀.破千军 << "f;\n";
		file << "横刀极光破云闪角度=" << 振刀参数::角度::横刀.极光破云闪 << "f;\n";
		//----------------------------------------------------------------------


		file.close();
	}
}
void 判断内存振配置(const std::string& line)
{
	std::istringstream iss(line);
	std::string token;
	std::string paramName;
	float paramValue;

	if (std::getline(iss, token, '='))
	{
		paramName = token;
		if (std::getline(iss, token))
		{
			paramValue = std::stof(token);
			//长剑
			if (strstr(paramName.c_str(), "长剑左3距离") != NULL) { 振刀参数::距离::长剑.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右3距离") != NULL) { 振刀参数::距离::长剑.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气距离") != NULL) { 振刀参数::距离::长剑.左剑气 = paramValue; }
			//if (strstr(paramName.c_str(), "长剑左剑气距离") != NULL) { 振刀参数::距离::长剑.左剑气 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气距离") != NULL) { 振刀参数::距离::长剑.右剑气 = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽距离") != NULL) { 振刀参数::距离::长剑.凤凰羽 = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月距离") != NULL) { 振刀参数::距离::长剑.蓝月 = paramValue; }
			if (strstr(paramName.c_str(), "长剑七星夺窍距离") != NULL) { 振刀参数::距离::长剑.七星夺窍 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "长剑左3角度") != NULL) { 振刀参数::角度::长剑.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右3角度") != NULL) { 振刀参数::角度::长剑.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气2M角度") != NULL) { 振刀参数::角度::长剑.左剑气2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气4M角度") != NULL) { 振刀参数::角度::长剑.左剑气4M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气6M角度") != NULL) { 振刀参数::角度::长剑.左剑气6M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气9M角度") != NULL) { 振刀参数::角度::长剑.左剑气9M = paramValue; }
			if (strstr(paramName.c_str(), "长剑左剑气9M外角度") != NULL) { 振刀参数::角度::长剑.左剑气9M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气2M角度") != NULL) { 振刀参数::角度::长剑.右剑气2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气4M角度") != NULL) { 振刀参数::角度::长剑.右剑气4M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气6M角度") != NULL) { 振刀参数::角度::长剑.右剑气6M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气9M角度") != NULL) { 振刀参数::角度::长剑.右剑气9M = paramValue; }
			if (strstr(paramName.c_str(), "长剑右剑气9M外角度") != NULL) { 振刀参数::角度::长剑.右剑气9M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽2M角度") != NULL) { 振刀参数::角度::长剑.凤凰羽2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽5M角度") != NULL) { 振刀参数::角度::长剑.凤凰羽5M = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽8M角度") != NULL) { 振刀参数::角度::长剑.凤凰羽8M = paramValue; }
			if (strstr(paramName.c_str(), "长剑凤凰羽8M外角度") != NULL) { 振刀参数::角度::长剑.凤凰羽8M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月2M角度") != NULL) { 振刀参数::角度::长剑.蓝月2M = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月6M角度") != NULL) { 振刀参数::角度::长剑.蓝月6M = paramValue; }
			if (strstr(paramName.c_str(), "长剑蓝月6M外角度") != NULL) { 振刀参数::角度::长剑.蓝月6M外 = paramValue; }
			if (strstr(paramName.c_str(), "长剑七星夺窍角度") != NULL) { 振刀参数::角度::长剑.七星夺窍 = paramValue; }
			//太刀
			if (strstr(paramName.c_str(), "太刀左3距离") != NULL) { 振刀参数::距离::太刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右3距离") != NULL) { 振刀参数::距离::太刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左蓄距离") != NULL) { 振刀参数::距离::太刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右蓄距离") != NULL) { 振刀参数::距离::太刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左惊雷距离") != NULL) { 振刀参数::距离::太刀.左惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右惊雷&惊雷十劫距离") != NULL) { 振刀参数::距离::太刀.右惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左青鬼距离") != NULL) { 振刀参数::距离::太刀.左青鬼 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右青鬼距离") != NULL) { 振刀参数::距离::太刀.右青鬼 = paramValue; }
			if (strstr(paramName.c_str(), "太刀噬魂斩距离") != NULL) { 振刀参数::距离::太刀.噬魂斩 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "太刀左3角度") != NULL) { 振刀参数::角度::太刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右3角度") != NULL) { 振刀参数::角度::太刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左蓄2M角度") != NULL) { 振刀参数::角度::太刀.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "太刀左蓄2M外角度") != NULL) { 振刀参数::角度::太刀.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右蓄2M角度") != NULL) { 振刀参数::角度::太刀.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "太刀右蓄2M外角度") != NULL) { 振刀参数::角度::太刀.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左惊雷角度") != NULL) { 振刀参数::角度::太刀.左惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右惊雷5M角度") != NULL) { 振刀参数::角度::太刀.右惊雷5M = paramValue; }
			if (strstr(paramName.c_str(), "太刀右惊雷5M外角度") != NULL) { 振刀参数::角度::太刀.右惊雷5M外 = paramValue; }
			if (strstr(paramName.c_str(), "太刀左青鬼角度") != NULL) { 振刀参数::角度::太刀.左青鬼 = paramValue; }
			if (strstr(paramName.c_str(), "太刀右青鬼角度") != NULL) { 振刀参数::角度::太刀.右青鬼 = paramValue; }
			//阔刀
			if (strstr(paramName.c_str(), "阔刀左左距离") != NULL) { 振刀参数::距离::阔刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左右距离") != NULL) { 振刀参数::距离::阔刀.左右 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右距离") != NULL) { 振刀参数::距离::阔刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右左距离") != NULL) { 振刀参数::距离::阔刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄一段距离") != NULL) { 振刀参数::距离::阔刀.左蓄一段 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄二段距离") != NULL) { 振刀参数::距离::阔刀.左蓄二段 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄三段距离") != NULL) { 振刀参数::距离::阔刀.左蓄三段 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右蓄距离") != NULL) { 振刀参数::距离::阔刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右蓄距离") != NULL) { 振刀参数::距离::阔刀.右右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀雷刀距离") != NULL) { 振刀参数::距离::阔刀.雷刀 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀雷刀下劈距离") != NULL) { 振刀参数::距离::阔刀.雷刀下劈 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "阔刀左左角度") != NULL) { 振刀参数::角度::阔刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左右2M角度") != NULL) { 振刀参数::角度::阔刀.左右2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左右2M外角度") != NULL) { 振刀参数::角度::阔刀.左右2M外 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右角度") != NULL) { 振刀参数::角度::阔刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右左角度") != NULL) { 振刀参数::角度::阔刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄一段2M角度") != NULL) { 振刀参数::角度::阔刀.左蓄一段2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀左蓄一段2M外角度") != NULL) { 振刀参数::角度::阔刀.左蓄一段2M外 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右蓄2M角度") != NULL) { 振刀参数::角度::阔刀.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右蓄2M外角度") != NULL) { 振刀参数::角度::阔刀.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右蓄2M角度") != NULL) { 振刀参数::角度::阔刀.右右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "阔刀右右蓄2M外角度") != NULL) { 振刀参数::角度::阔刀.右右蓄2M外 = paramValue; }
			//长枪
			if (strstr(paramName.c_str(), "长枪左3距离") != NULL) { 振刀参数::距离::长枪.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右3距离") != NULL) { 振刀参数::距离::长枪.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪左蓄距离") != NULL) { 振刀参数::距离::长枪.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪六合枪距离") != NULL) { 振刀参数::距离::长枪.六合枪 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右蓄距离") != NULL) { 振刀参数::距离::长枪.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪大圣游距离") != NULL) { 振刀参数::距离::长枪.大圣游 = paramValue; }
			if (strstr(paramName.c_str(), "长枪风卷云残距离") != NULL) { 振刀参数::距离::长枪.风卷云残 = paramValue; }
			if (strstr(paramName.c_str(), "长枪双环扫距离") != NULL) { 振刀参数::距离::长枪.双环扫 = paramValue; }
			if (strstr(paramName.c_str(), "长枪龙王破距离") != NULL) { 振刀参数::距离::长枪.龙王破 = paramValue; }
			if (strstr(paramName.c_str(), "长枪穿心脚距离") != NULL) { 振刀参数::距离::长枪.穿心脚 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "长枪左3角度") != NULL) { 振刀参数::角度::长枪.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右3角度") != NULL) { 振刀参数::角度::长枪.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长枪左蓄角度") != NULL) { 振刀参数::角度::长枪.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪六合枪2M角度") != NULL) { 振刀参数::角度::长枪.六合枪2M = paramValue; }
			if (strstr(paramName.c_str(), "长枪六合枪2M外角度") != NULL) { 振刀参数::角度::长枪.六合枪2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长枪右蓄角度") != NULL) { 振刀参数::角度::长枪.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长枪大圣游角度") != NULL) { 振刀参数::角度::长枪.大圣游 = paramValue; }
			if (strstr(paramName.c_str(), "长枪风卷云残角度") != NULL) { 振刀参数::角度::长枪.风卷云残 = paramValue; }
			if (strstr(paramName.c_str(), "长枪龙王破2M角度") != NULL) { 振刀参数::角度::长枪.龙王破2M = paramValue; }
			if (strstr(paramName.c_str(), "长枪龙王破2M外角度") != NULL) { 振刀参数::角度::长枪.龙王破2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长枪穿心脚2M角度") != NULL) { 振刀参数::角度::长枪.穿心脚2M = paramValue; }
			if (strstr(paramName.c_str(), "长枪穿心脚2M外角度") != NULL) { 振刀参数::角度::长枪.穿心脚2M外 = paramValue; }
			//匕首
			if (strstr(paramName.c_str(), "匕首左3距离") != NULL) { 振刀参数::距离::匕首.左3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右3距离") != NULL) { 振刀参数::距离::匕首.右3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首左蓄距离") != NULL) { 振刀参数::距离::匕首.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右蓄距离") != NULL) { 振刀参数::距离::匕首.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼反距离") != NULL) { 振刀参数::距离::匕首.鬼反 = paramValue; }
			if (strstr(paramName.c_str(), "匕首荆轲献匕距离") != NULL) { 振刀参数::距离::匕首.荆轲献匕 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼刃暗扎距离") != NULL) { 振刀参数::距离::匕首.鬼刃暗扎 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼哭神嚎距离") != NULL) { 振刀参数::距离::匕首.鬼哭神嚎 = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔距离") != NULL) { 振刀参数::距离::匕首.亢龙有悔 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "匕首左3角度") != NULL) { 振刀参数::角度::匕首.左3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右3角度") != NULL) { 振刀参数::角度::匕首.右3 = paramValue; }
			if (strstr(paramName.c_str(), "匕首左蓄2M角度") != NULL) { 振刀参数::角度::匕首.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首左蓄2M外角度") != NULL) { 振刀参数::角度::匕首.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首右蓄2M角度") != NULL) { 振刀参数::角度::匕首.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首右蓄2M外角度") != NULL) { 振刀参数::角度::匕首.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼反角度") != NULL) { 振刀参数::角度::匕首.鬼反 = paramValue; }
			if (strstr(paramName.c_str(), "匕首荆轲献匕2M角度") != NULL) { 振刀参数::角度::匕首.荆轲献匕2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首荆轲献匕2M外角度") != NULL) { 振刀参数::角度::匕首.荆轲献匕2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼刃暗扎2M角度") != NULL) { 振刀参数::角度::匕首.鬼刃暗扎2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首鬼刃暗扎2M外角度") != NULL) { 振刀参数::角度::匕首.鬼刃暗扎2M外 = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔2M角度") != NULL) { 振刀参数::角度::匕首.亢龙有悔2M = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔4M角度") != NULL) { 振刀参数::角度::匕首.亢龙有悔4M = paramValue; }
			if (strstr(paramName.c_str(), "匕首亢龙有悔4M外角度") != NULL) { 振刀参数::角度::匕首.亢龙有悔4M外 = paramValue; }
			//双截棍
			if (strstr(paramName.c_str(), "双截棍左右3距离") != NULL) { 振刀参数::距离::双截棍.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍左蓄距离") != NULL) { 振刀参数::距离::双截棍.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍右蓄距离") != NULL) { 振刀参数::距离::双截棍.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍飞踢距离") != NULL) { 振刀参数::距离::双截棍.飞踢 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍扬鞭劲距离") != NULL) { 振刀参数::距离::双截棍.扬鞭劲 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍横栏距离") != NULL) { 振刀参数::距离::双截棍.横栏 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍龙虎乱舞距离") != NULL) { 振刀参数::距离::双截棍.龙虎乱舞 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "双截棍左右3角度") != NULL) { 振刀参数::角度::双截棍.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍左蓄2M角度") != NULL) { 振刀参数::角度::双截棍.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "双截棍左蓄2M外角度") != NULL) { 振刀参数::角度::双截棍.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍右蓄2M角度") != NULL) { 振刀参数::角度::双截棍.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "双截棍右蓄2M外角度") != NULL) { 振刀参数::角度::双截棍.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍飞踢角度") != NULL) { 振刀参数::角度::双截棍.飞踢 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍扬鞭劲角度") != NULL) { 振刀参数::角度::双截棍.扬鞭劲 = paramValue; }
			if (strstr(paramName.c_str(), "双截棍横栏角度") != NULL) { 振刀参数::角度::双截棍.横栏 = paramValue; }
			//双刀
			if (strstr(paramName.c_str(), "双刀左右3距离") != NULL) { 振刀参数::距离::双刀.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双刀左蓄距离") != NULL) { 振刀参数::距离::双刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀右蓄距离") != NULL) { 振刀参数::距离::双刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀铁马残红距离") != NULL) { 振刀参数::距离::双刀.铁马残红 = paramValue; }
			if (strstr(paramName.c_str(), "双刀乾坤日月斩距离") != NULL) { 振刀参数::距离::双刀.乾坤日月斩 = paramValue; }
			if (strstr(paramName.c_str(), "双刀惊雷距离") != NULL) { 振刀参数::距离::双刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "双刀八斩刀距离") != NULL) { 振刀参数::距离::双刀.八斩刀 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "双刀左右3角度") != NULL) { 振刀参数::角度::双刀.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双刀左蓄角度") != NULL) { 振刀参数::角度::双刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀右蓄角度") != NULL) { 振刀参数::角度::双刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双刀铁马残红3M角度") != NULL) { 振刀参数::角度::双刀.铁马残红3M = paramValue; }
			if (strstr(paramName.c_str(), "双刀铁马残红3M外角度") != NULL) { 振刀参数::角度::双刀.铁马残红3M外 = paramValue; }
			if (strstr(paramName.c_str(), "双刀乾坤日月斩角度") != NULL) { 振刀参数::角度::双刀.乾坤日月斩 = paramValue; }
			if (strstr(paramName.c_str(), "双刀惊雷角度") != NULL) { 振刀参数::角度::双刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "双刀八斩刀角度") != NULL) { 振刀参数::角度::双刀.八斩刀 = paramValue; }
			//长棍
			if (strstr(paramName.c_str(), "长棍左3距离") != NULL) { 振刀参数::距离::长棍.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍右3距离") != NULL) { 振刀参数::距离::长棍.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍少林棍距离") != NULL) { 振刀参数::距离::长棍.少林棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍左蓄距离") != NULL) { 振刀参数::距离::长棍.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长棍右蓄距离") != NULL) { 振刀参数::距离::长棍.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "长棍腾云式距离") != NULL) { 振刀参数::距离::长棍.腾云式 = paramValue; }
			if (strstr(paramName.c_str(), "长棍乱点天宫距离") != NULL) { 振刀参数::距离::长棍.乱点天宫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍桶劲距离") != NULL) { 振刀参数::距离::长棍.桶劲 = paramValue; }
			if (strstr(paramName.c_str(), "长棍五情七灭镇距离") != NULL) { 振刀参数::距离::长棍.五情七灭镇 = paramValue; }
			if (strstr(paramName.c_str(), "长棍双环扫距离") != NULL) { 振刀参数::距离::长棍.双环扫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍倒海棍距离") != NULL) { 振刀参数::距离::长棍.倒海棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍镇地撑天距离") != NULL) { 振刀参数::距离::长棍.镇地撑天 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "长棍左3角度") != NULL) { 振刀参数::角度::长棍.左3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍右3角度") != NULL) { 振刀参数::角度::长棍.右3 = paramValue; }
			if (strstr(paramName.c_str(), "长棍少林棍角度") != NULL) { 振刀参数::角度::长棍.少林棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍左蓄2M角度") != NULL) { 振刀参数::角度::长棍.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "长棍左蓄2M外角度") != NULL) { 振刀参数::角度::长棍.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长棍腾云式2M角度") != NULL) { 振刀参数::角度::长棍.腾云式2M = paramValue; }
			if (strstr(paramName.c_str(), "长棍腾云式2M外角度") != NULL) { 振刀参数::角度::长棍.腾云式2M外 = paramValue; }
			if (strstr(paramName.c_str(), "长棍乱点天宫角度") != NULL) { 振刀参数::角度::长棍.乱点天宫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍桶劲角度") != NULL) { 振刀参数::角度::长棍.桶劲 = paramValue; }
			if (strstr(paramName.c_str(), "长棍五情七灭镇8M角度") != NULL) { 振刀参数::角度::长棍.五情七灭镇8M = paramValue; }
			if (strstr(paramName.c_str(), "长棍五情七灭镇8M外角度") != NULL) { 振刀参数::角度::长棍.五情七灭镇8M外 = paramValue; }
			if (strstr(paramName.c_str(), "长棍双环扫角度") != NULL) { 振刀参数::角度::长棍.双环扫 = paramValue; }
			if (strstr(paramName.c_str(), "长棍倒海棍角度") != NULL) { 振刀参数::角度::长棍.倒海棍 = paramValue; }
			if (strstr(paramName.c_str(), "长棍镇地撑天角度") != NULL) { 振刀参数::角度::长棍.镇地撑天 = paramValue; }
			//斩马刀
			if (strstr(paramName.c_str(), "斩马刀左左距离") != NULL) { 振刀参数::距离::斩马刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左右距离") != NULL) { 振刀参数::距离::斩马刀.左右 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右右距离") != NULL) { 振刀参数::距离::斩马刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右左距离") != NULL) { 振刀参数::距离::斩马刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左蓄距离") != NULL) { 振刀参数::距离::斩马刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右蓄距离") != NULL) { 振刀参数::距离::斩马刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀柄击距离") != NULL) { 振刀参数::距离::斩马刀.柄击 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀惊雷距离") != NULL) { 振刀参数::距离::斩马刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀炽焰斩距离") != NULL) { 振刀参数::距离::斩马刀.炽焰斩 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀过关斩将距离") != NULL) { 振刀参数::距离::斩马刀.过关斩将 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "斩马刀左左角度") != NULL) { 振刀参数::角度::斩马刀.左左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左右2M角度") != NULL) { 振刀参数::角度::斩马刀.左右2M = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左右2M外角度") != NULL) { 振刀参数::角度::斩马刀.左右2M外 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右右角度") != NULL) { 振刀参数::角度::斩马刀.右右 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右左角度") != NULL) { 振刀参数::角度::斩马刀.右左 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左蓄2M角度") != NULL) { 振刀参数::角度::斩马刀.左蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀左蓄2M外角度") != NULL) { 振刀参数::角度::斩马刀.左蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀右蓄角度") != NULL) { 振刀参数::角度::斩马刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀柄击角度") != NULL) { 振刀参数::角度::斩马刀.柄击 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀惊雷角度") != NULL) { 振刀参数::角度::斩马刀.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀炽焰斩角度") != NULL) { 振刀参数::角度::斩马刀.炽焰斩 = paramValue; }
			if (strstr(paramName.c_str(), "斩马刀过关斩将角度") != NULL) { 振刀参数::角度::斩马刀.过关斩将 = paramValue; }
			//双戟
			if (strstr(paramName.c_str(), "双戟左右3距离") != NULL) { 振刀参数::距离::双戟.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双戟左蓄距离") != NULL) { 振刀参数::距离::双戟.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双戟右蓄距离") != NULL) { 振刀参数::距离::双戟.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "双戟勾旋斩距离") != NULL) { 振刀参数::距离::双戟.勾旋斩 = paramValue; }
			if (strstr(paramName.c_str(), "双戟探海蛟距离") != NULL) { 振刀参数::距离::双戟.探海蛟 = paramValue; }
			if (strstr(paramName.c_str(), "双戟钩挂距离") != NULL) { 振刀参数::距离::双戟.钩挂 = paramValue; }
			if (strstr(paramName.c_str(), "双戟战龙在天距离") != NULL) { 振刀参数::距离::双戟.战龙在天 = paramValue; }
			if (strstr(paramName.c_str(), "双戟形意钩距离") != NULL) { 振刀参数::距离::双戟.形意钩 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "双戟左右3角度") != NULL) { 振刀参数::角度::双戟.左右3 = paramValue; }
			if (strstr(paramName.c_str(), "双戟左蓄3M角度") != NULL) { 振刀参数::角度::双戟.左蓄3M = paramValue; }
			if (strstr(paramName.c_str(), "双戟左蓄3M外角度") != NULL) { 振刀参数::角度::双戟.左蓄3M外 = paramValue; }
			if (strstr(paramName.c_str(), "双戟右蓄3M角度") != NULL) { 振刀参数::角度::双戟.右蓄3M = paramValue; }
			if (strstr(paramName.c_str(), "双戟右蓄3M外角度") != NULL) { 振刀参数::角度::双戟.右蓄3M外 = paramValue; }
			if (strstr(paramName.c_str(), "双戟勾旋斩角度") != NULL) { 振刀参数::角度::双戟.勾旋斩 = paramValue; }
			if (strstr(paramName.c_str(), "双戟探海蛟角度") != NULL) { 振刀参数::角度::双戟.探海蛟 = paramValue; }
			if (strstr(paramName.c_str(), "双戟钩挂角度") != NULL) { 振刀参数::角度::双戟.钩挂 = paramValue; }
			if (strstr(paramName.c_str(), "双戟战龙在天角度") != NULL) { 振刀参数::角度::双戟.战龙在天 = paramValue; }
			if (strstr(paramName.c_str(), "双戟形意钩角度") != NULL) { 振刀参数::角度::双戟.形意钩 = paramValue; }
			//扇子1
			if (strstr(paramName.c_str(), "扇子左3距离") != NULL) { 振刀参数::距离::扇子.左3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右3距离") != NULL) { 振刀参数::距离::扇子.右3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子左蓄距离") != NULL) { 振刀参数::距离::扇子.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右蓄距离") != NULL) { 振刀参数::距离::扇子.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "扇子双开圆距离") != NULL) { 振刀参数::距离::扇子.双开圆 = paramValue; }
			if (strstr(paramName.c_str(), "扇子三风摆距离") != NULL) { 振刀参数::距离::扇子.三风摆 = paramValue; }
			if (strstr(paramName.c_str(), "扇子惊雷距离") != NULL) { 振刀参数::距离::扇子.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "扇子缠龙奔野距离") != NULL) { 振刀参数::距离::扇子.缠龙奔野 = paramValue; }
			if (strstr(paramName.c_str(), "扇子鬼反距离") != NULL) { 振刀参数::距离::扇子.鬼反 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "扇子左3角度") != NULL) { 振刀参数::角度::扇子.左3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右3角度") != NULL) { 振刀参数::角度::扇子.右3 = paramValue; }
			if (strstr(paramName.c_str(), "扇子左蓄角度") != NULL) { 振刀参数::角度::扇子.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "扇子右蓄2M角度") != NULL) { 振刀参数::角度::扇子.右蓄2M = paramValue; }
			if (strstr(paramName.c_str(), "扇子右蓄2M外角度") != NULL) { 振刀参数::角度::扇子.右蓄2M外 = paramValue; }
			if (strstr(paramName.c_str(), "扇子双开圆角度") != NULL) { 振刀参数::角度::扇子.双开圆 = paramValue; }
			if (strstr(paramName.c_str(), "扇子三风摆3M角度") != NULL) { 振刀参数::角度::扇子.三风摆3M = paramValue; }
			if (strstr(paramName.c_str(), "扇子三风摆3M外角度") != NULL) { 振刀参数::角度::扇子.三风摆3M外 = paramValue; }
			if (strstr(paramName.c_str(), "扇子惊雷角度") != NULL) { 振刀参数::角度::扇子.惊雷 = paramValue; }
			if (strstr(paramName.c_str(), "扇子缠龙奔野3M角度") != NULL) { 振刀参数::角度::扇子.缠龙奔野3M = paramValue; }
			if (strstr(paramName.c_str(), "扇子缠龙奔野3M外角度") != NULL) { 振刀参数::角度::扇子.缠龙奔野3M外 = paramValue; }
			if (strstr(paramName.c_str(), "扇子鬼反角度") != NULL) { 振刀参数::角度::扇子.鬼反 = paramValue; }
			//横刀
			if (strstr(paramName.c_str(), "横刀左3距离") != NULL) { 振刀参数::距离::横刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右3距离") != NULL) { 振刀参数::距离::横刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀左蓄距离") != NULL) { 振刀参数::距离::横刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右蓄距离") != NULL) { 振刀参数::距离::横刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀破千军距离") != NULL) { 振刀参数::距离::横刀.破千军 = paramValue; }
			if (strstr(paramName.c_str(), "横刀极光破云闪距离") != NULL) { 振刀参数::距离::横刀.极光破云闪 = paramValue; }
			//角度
			if (strstr(paramName.c_str(), "横刀左3角度") != NULL) { 振刀参数::角度::横刀.左3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右3角度") != NULL) { 振刀参数::角度::横刀.右3 = paramValue; }
			if (strstr(paramName.c_str(), "横刀左蓄角度") != NULL) { 振刀参数::角度::横刀.左蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀右蓄角度") != NULL) { 振刀参数::角度::横刀.右蓄 = paramValue; }
			if (strstr(paramName.c_str(), "横刀破千军角度") != NULL) { 振刀参数::角度::横刀.破千军 = paramValue; }
			if (strstr(paramName.c_str(), "横刀极光破云闪角度") != NULL) { 振刀参数::角度::横刀.极光破云闪 = paramValue; }

		}
	}
}
void 读取内存振配置()
{
	std::ifstream file("内存振配置.ini");
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			判断内存振配置(line);
		}

		file.close();
	}
}

void 保存活化配置()
{
	ofstream file("活化配置.ini");
	if (file.is_open())
	{
		file << "火男冲拳距离=" << 活化参数::距离::火男冲拳 << "f;\n";
		file << "火男F距离=" << 活化参数::距离::火男F << "f;\n";
		file << "妖刀大招距离=" << 活化参数::距离::妖刀大招 << "f;\n";
		file << "顾倾寒大招距离=" << 活化参数::距离::顾倾寒大招 << "f;\n";
		file << "武田F2距离=" << 活化参数::距离::武田F2 << "f;\n";
		file << "武田F3距离=" << 活化参数::距离::武田F3 << "f;\n";
		file << "胡为F1距离=" << 活化参数::距离::胡为F1 << "f;\n";
		file << "胡为F2距离=" << 活化参数::距离::胡为F2 << "f;\n";
		file << "胡为跃击距离=" << 活化参数::距离::胡为跃击 << "f;\n";
		file << "胡为V1V2距离=" << 活化参数::距离::胡为V1V2 << "f;\n";
		file << "魏轻F1距离=" << 活化参数::距离::魏轻F1 << "f;\n";
		file << "魏轻V1距离=" << 活化参数::距离::魏轻V1 << "f;\n";
		file << "魏轻V2距离=" << 活化参数::距离::魏轻V2 << "f;\n";

		file << "宁红叶F1距离=" << 活化参数::距离::宁红叶F1 << "f;\n";
		file << "宁红叶F2距离=" << 活化参数::距离::宁红叶F2 << "f;\n";
		file << "宁红叶F3距离=" << 活化参数::距离::宁红叶F3 << "f;\n";
		file << "狐狸大招距离=" << 活化参数::距离::狐狸大招 << "f;\n";
		file << "三娘V2距离=" << 活化参数::距离::三娘V2 << "f;\n";
		//角度
		file << "火男冲拳角度=" << 活化参数::角度::火男冲拳 << "f;\n";
		file << "火男F角度=" << 活化参数::角度::火男F << "f;\n";
		file << "妖刀大招3M角度=" << 活化参数::角度::妖刀大招3M << "f;\n";
		file << "妖刀大招3M外角度=" << 活化参数::角度::妖刀大招3M外 << "f;\n";
		file << "顾倾寒大招3M角度=" << 活化参数::角度::顾倾寒大招3M << "f;\n";
		file << "顾倾寒大招3M外角度=" << 活化参数::角度::顾倾寒大招3M外 << "f;\n";
		file << "武田F21M角度=" << 活化参数::角度::武田F21M << "f;\n";
		file << "武田F21M外角度=" << 活化参数::角度::武田F21M << "f;\n";
		file << "武田F31M角度=" << 活化参数::角度::武田F31M << "f;\n";
		file << "武田F31M外角度=" << 活化参数::角度::武田F31M外 << "f;\n";
		file << "胡为F2角度=" << 活化参数::角度::胡为F2 << "f;\n";
		file << "胡为跃击角度=" << 活化参数::角度::胡为跃击 << "f;\n";
		file << "胡为V1V2角度=" << 活化参数::角度::胡为V1V2 << "f;\n";

		file << "宁红叶F1角度=" << 活化参数::角度::宁红叶F1 << "f;\n";
		file << "宁红叶F2角度=" << 活化参数::角度::宁红叶F2 << "f;\n";
		file << "宁红叶F3角度=" << 活化参数::角度::宁红叶F3 << "f;\n";

		file << "狐狸大招4M角度=" << 活化参数::角度::狐狸大招4M << "f;\n";
		file << "狐狸大招8M角度=" << 活化参数::角度::狐狸大招8M << "f;\n";
		file << "狐狸大招12M角度=" << 活化参数::角度::狐狸大招12M << "f;\n";
		file << "狐狸大招12M外角度=" << 活化参数::角度::狐狸大招12M外 << "f;\n";
		file << "魏轻V1角度=" << 活化参数::角度::魏轻V1 << "f;\n";
		file << "魏轻V2角度=" << 活化参数::角度::魏轻V2 << "f;\n";

		file << "三娘V24M角度=" << 活化参数::角度::三娘V24M << "f;\n";
		file << "三娘V210M角度=" << 活化参数::角度::三娘V210M << "f;\n";
		file << "三娘V210M外角度=" << 活化参数::角度::三娘V210M外 << "f;\n";


		file.close();
	}

}
void 判断活化配置(const std::string& line)
{
	std::istringstream iss(line);
	std::string token;
	std::string paramName;
	float paramValue;
	if (std::getline(iss, token, '='))
	{
		paramName = token;
		if (std::getline(iss, token))
		{
			paramValue = std::stof(token);
			if (strstr(paramName.c_str(), "火男冲拳距离") != NULL) { 活化参数::距离::火男冲拳 = paramValue; }
			if (strstr(paramName.c_str(), "火男F距离") != NULL) { 活化参数::距离::火男F = paramValue; }
			if (strstr(paramName.c_str(), "妖刀大招距离") != NULL) { 活化参数::距离::妖刀大招 = paramValue; }
			if (strstr(paramName.c_str(), "顾倾寒大招距离") != NULL) { 活化参数::距离::顾倾寒大招 = paramValue; }
			if (strstr(paramName.c_str(), "武田F2距离") != NULL) { 活化参数::距离::武田F2 = paramValue; }
			if (strstr(paramName.c_str(), "武田F3距离") != NULL) { 活化参数::距离::武田F3 = paramValue; }
			if (strstr(paramName.c_str(), "胡为F1距离") != NULL) { 活化参数::距离::胡为F1 = paramValue; }
			if (strstr(paramName.c_str(), "胡为F2距离") != NULL) { 活化参数::距离::胡为F2 = paramValue; }
			if (strstr(paramName.c_str(), "胡为跃击距离") != NULL) { 活化参数::距离::胡为跃击 = paramValue; }
			if (strstr(paramName.c_str(), "胡为V1V2距离") != NULL) { 活化参数::距离::胡为V1V2 = paramValue; }
			if (strstr(paramName.c_str(), "宁红叶F1距离") != NULL) { 活化参数::距离::宁红叶F1 = paramValue; }
			if (strstr(paramName.c_str(), "宁红叶F2距离") != NULL) { 活化参数::距离::宁红叶F2 = paramValue; }
			if (strstr(paramName.c_str(), "宁红叶F3距离") != NULL) { 活化参数::距离::宁红叶F3 = paramValue; }
			if (strstr(paramName.c_str(), "狐狸大招距离") != NULL) { 活化参数::距离::狐狸大招 = paramValue; }

			if (strstr(paramName.c_str(), "魏轻F1距离") != NULL) { 活化参数::距离::魏轻F1 = paramValue; }
			if (strstr(paramName.c_str(), "魏轻V1距离") != NULL) { 活化参数::距离::魏轻V1 = paramValue; }
			if (strstr(paramName.c_str(), "魏轻V2距离") != NULL) { 活化参数::距离::魏轻V2 = paramValue; }

			//角度
			if (strstr(paramName.c_str(), "火男冲拳角度") != NULL) { 活化参数::角度::火男冲拳 = paramValue; }
			if (strstr(paramName.c_str(), "火男F角度") != NULL) { 活化参数::角度::火男F = paramValue; }
			if (strstr(paramName.c_str(), "妖刀大招3M角度") != NULL) { 活化参数::角度::妖刀大招3M = paramValue; }
			if (strstr(paramName.c_str(), "妖刀大招3M外角度") != NULL) { 活化参数::角度::妖刀大招3M外 = paramValue; }
			if (strstr(paramName.c_str(), "顾倾寒大招3M角度") != NULL) { 活化参数::角度::顾倾寒大招3M = paramValue; }
			if (strstr(paramName.c_str(), "顾倾寒大招3M外角度") != NULL) { 活化参数::角度::顾倾寒大招3M外 = paramValue; }
			if (strstr(paramName.c_str(), "武田F21M角度") != NULL) { 活化参数::角度::武田F21M = paramValue; }
			if (strstr(paramName.c_str(), "武田F21M外角度") != NULL) { 活化参数::角度::武田F21M外 = paramValue; }
			if (strstr(paramName.c_str(), "武田F31M角度") != NULL) { 活化参数::角度::武田F31M = paramValue; }
			if (strstr(paramName.c_str(), "武田F31M外角度") != NULL) { 活化参数::角度::武田F31M外 = paramValue; }
			if (strstr(paramName.c_str(), "胡为F2角度") != NULL) { 活化参数::角度::胡为F2 = paramValue; }
			if (strstr(paramName.c_str(), "胡为跃击角度") != NULL) { 活化参数::角度::胡为跃击 = paramValue; }
			if (strstr(paramName.c_str(), "胡为V1V2角度") != NULL) { 活化参数::角度::胡为V1V2 = paramValue; }

			if (strstr(paramName.c_str(), "宁红叶F1角度") != NULL) { 活化参数::角度::宁红叶F1 = paramValue; }
			if (strstr(paramName.c_str(), "宁红叶F2角度") != NULL) { 活化参数::角度::宁红叶F2 = paramValue; }
			if (strstr(paramName.c_str(), "宁红叶F3角度") != NULL) { 活化参数::角度::宁红叶F3 = paramValue; }

			if (strstr(paramName.c_str(), "狐狸大招4M角度") != NULL) { 活化参数::角度::狐狸大招4M = paramValue; }
			if (strstr(paramName.c_str(), "狐狸大招8M角度") != NULL) { 活化参数::角度::狐狸大招8M = paramValue; }
			if (strstr(paramName.c_str(), "狐狸大招12M角度") != NULL) { 活化参数::角度::狐狸大招12M = paramValue; }
			if (strstr(paramName.c_str(), "狐狸大招12M外角度") != NULL) { 活化参数::角度::狐狸大招12M外 = paramValue; }

			if (strstr(paramName.c_str(), "魏轻V1角度") != NULL) { 活化参数::角度::魏轻V1 = paramValue; }
			if (strstr(paramName.c_str(), "魏轻V2角度") != NULL) { 活化参数::角度::魏轻V2 = paramValue; }

			if (strstr(paramName.c_str(), "三娘V24M角度") != NULL) { 活化参数::角度::三娘V24M = paramValue; }
			if (strstr(paramName.c_str(), "三娘V210M角度") != NULL) { 活化参数::角度::三娘V210M = paramValue; }
			if (strstr(paramName.c_str(), "三娘V210M外角度") != NULL) { 活化参数::角度::三娘V210M外 = paramValue; }
		}
	}
}
void 读取活化配置()
{
	std::ifstream file("活化配置.ini");
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			判断活化配置(line);
		}

		file.close();
	}

}

void 保存Kmbox()
{
	ofstream file("Kmbox.ini");
	if (file.is_open())
	{
		file << "IP=" << Function::Kmbox::Net::IP << "\n";
		file << "Port=" << Function::Kmbox::Net::Port << "\n";
		file << "UUID=" << Function::Kmbox::Net::mac << "\n";

		file << "端口号=" << Function::Kmbox::B_Pro::PorttextBuffer << "\n";
		file << "波特率=" << Function::Kmbox::B_Pro::SpeedBuffer << "\n";

		file.close();
	}

}
void 判断Kmbox配置(const std::string& line)
{
	std::istringstream iss(line);
	std::string token;
	std::string paramName;
	//float paramValue;
	if (std::getline(iss, token, '='))
	{
		paramName = token;
		if (std::getline(iss, token))
		{
			//paramValue = std::stof(token);
			if (strstr(paramName.c_str(), "IP") != NULL) { strcpy(Function::Kmbox::Net::IP, token.c_str()); /*printf("%s\n", Function::Kmbox::Net::IP);*/ }
			if (strstr(paramName.c_str(), "Port") != NULL) { strcpy(Function::Kmbox::Net::Port, token.c_str()); /*printf("%s\n", Function::Kmbox::Net::Port);*/ }
			if (strstr(paramName.c_str(), "UUID") != NULL) { strcpy(Function::Kmbox::Net::mac, token.c_str()); /*printf("%s\n", Function::Kmbox::Net::mac);*/ }

			if (strstr(paramName.c_str(), "端口号") != NULL) { strcpy(Function::Kmbox::B_Pro::PorttextBuffer, token.c_str()); }
			if (strstr(paramName.c_str(), "波特率") != NULL) { strcpy(Function::Kmbox::B_Pro::SpeedBuffer, token.c_str()); }

		}
	}
}
void 读取Kmbox配置()
{
	std::ifstream file("Kmbox.ini");
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			判断Kmbox配置(line);
		}

		file.close();
	}

}

void 保存其他参数()
{
	ofstream file("其他配置.ini");
	if (file.is_open())
	{
		file << "方框=" << Function::ESP::方框 << "\n";
		file << "信息=" << Function::ESP::信息 << "\n";
		file << "血甲=" << Function::ESP::血条 << "\n";
		file << "手持=" << Function::ESP::手持 << "\n";
		file << "预警=" << Function::ESP::预警 << "\n";
		file << "血条样式=" << Function::ESP::血条样式 << "\n";
		file << "盲区样式=" << Function::ESP::预警样式 << "\n";
		//振刀
		file << "启用振刀=" << Function::Shock::F_ShockKnife << "\n";
		file << "预判振刀=" << Function::Shock::预判振刀 << "\n";
		file << "扬鞭劲振刀=" << Function::Shock::扬鞭劲振刀 << "\n";
		file << "横栏振刀=" << Function::Shock::横栏振刀 << "\n";
		file << "横刀左蓄振刀=" << Function::Shock::横刀左蓄振刀 << "\n";
		file << "是否闪避=" << Function::Shock::Flag_ShortDodge << "\n";
		file << "是否拼刀=" << Function::Shock::Flag_CollideKnife << "\n";
		file << "振刀延迟=" << Function::Shock::Shock_Delay << "\n";
		file << "输出调试执行=" << 调试::输出调试执行 << "\n";
		file << "输出逻辑执行=" << 调试::输出逻辑执行 << "\n";
		file << "按键方式=" << 按键方式 << "\n";
		file << "双截棍左蓄短闪振=" << 振刀参数::特殊处理::双截棍左蓄是否短闪振 << "\n";
		file << "扇子左蓄中闪振=" << 振刀参数::特殊处理::扇子左蓄是否中闪振 << "\n";
		file << "扇子右蓄中闪振=" << 振刀参数::特殊处理::扇子右蓄是否中闪振 << "\n";
		file << "斩马刀左蓄长闪振=" << 振刀参数::特殊处理::斩马刀左蓄是否长闪振 << "\n";
		file << "阔刀右蓄短闪振=" << 振刀参数::特殊处理::阔刀右蓄是否短闪振 << "\n";
		file << "横刀左蓄是否只短闪=" << 振刀参数::特殊处理::横刀左蓄是否只短闪 << "\n";
		//物品
		file << "近战=" << Function::ESP::近战 << "\n";
		file << "远程=" << Function::ESP::远程 << "\n";
		file << "道具=" << Function::ESP::道具 << "\n";
		file << "扩容=" << Function::ESP::扩容 << "\n";
		file << "金魂=" << Function::ESP::金魂 << "\n";
		file << "夺魂=" << Function::ESP::夺魂 << "\n";
		file << "属性=" << Function::ESP::属性 << "\n";
		file << "盒子=" << Function::ESP::盒子 << "\n";
		file << "白甲=" << Function::ESP::护甲Lv1 << "\n";
		file << "蓝甲=" << Function::ESP::护甲Lv2 << "\n";
		file << "紫甲=" << Function::ESP::护甲Lv3 << "\n";
		file << "金甲=" << Function::ESP::护甲Lv4 << "\n";
		file << "红甲=" << Function::ESP::护甲Lv5 << "\n";
		file << "果实=" << Function::ESP::果实 << "\n";
		file << "萤火虫=" << Function::ESP::萤火虫 << "\n";
		file << "金堆=" << Function::ESP::金堆 << "\n";
		file << "蓝堆=" << Function::ESP::蓝堆 << "\n";
		file << "绿堆=" << Function::ESP::绿堆 << "\n";
		file << "任务=" << Function::ESP::任务 << "\n";
		//活化
		file << "启用闪避=" << Function::HeroActivation::IsDodge << "\n";
		file << "躲避火男冲拳=" << Function::HeroActivation::躲避火男冲拳 << "\n";
		file << "躲避火男F=" << Function::HeroActivation::躲避火男F << "\n";
		file << "躲避妖刀大招=" << Function::HeroActivation::躲避妖刀大招 << "\n";
		file << "躲避顾清寒V1V2=" << Function::HeroActivation::躲避顾清寒V1V2 << "\n";
		file << "躲避武田F=" << Function::HeroActivation::躲避武田F << "\n";
		file << "躲避胡为=" << Function::HeroActivation::躲避胡为 << "\n";
		file << "躲避宁红叶F=" << Function::HeroActivation::躲避宁红叶F << "\n";
		file << "躲避狐狸大招=" << Function::HeroActivation::躲避狐狸大招 << "\n";
		file << "躲避三娘V2=" << Function::HeroActivation::躲避三娘V2 << "\n";
		file << "躲避哈迪大招=" << Function::HeroActivation::躲避哈迪大招 << "\n";
		file << "躲避魏轻F1=" << Function::HeroActivation::躲避魏轻F1 << "\n";
		file << "躲避魏轻大招=" << Function::HeroActivation::躲避魏轻V << "\n";

		file << "蓄力抓振刀=" << Function::LogicKnife::BlueAttackShock << "\n";
		file << "蓄力抓白刀=" << Function::LogicKnife::BlueAttackWrite << "\n";
		file << "出蓄抓振延迟=" << 活化参数::出蓄抓振延迟 << "\n";



	}
	file.close();
}
void 判断其他配置(const std::string& line)
{
	std::istringstream iss(line);
	std::string token;
	std::string paramName;
	if (std::getline(iss, token, '='))
	{
		paramName = token;
		if (std::getline(iss, token))
		{
			if (strstr(paramName.c_str(), "方框") != NULL) { Function::ESP::方框 = stoi(token); }
			if (strstr(paramName.c_str(), "信息") != NULL) { Function::ESP::信息 = stoi(token); }
			if (strstr(paramName.c_str(), "血甲") != NULL) { Function::ESP::血条 = stoi(token); }
			if (strstr(paramName.c_str(), "手持") != NULL) { Function::ESP::手持 = stoi(token); }
			if (strstr(paramName.c_str(), "预警") != NULL) { Function::ESP::预警 = stoi(token); }
			if (strstr(paramName.c_str(), "血条样式") != NULL) { Function::ESP::血条样式 = stoi(token); }
			if (strstr(paramName.c_str(), "盲区样式") != NULL) { Function::ESP::预警样式 = stoi(token); }

			if (strstr(paramName.c_str(), "近战") != NULL) { Function::ESP::近战 = stoi(token); }
			if (strstr(paramName.c_str(), "远程") != NULL) { Function::ESP::远程 = stoi(token); }
			if (strstr(paramName.c_str(), "道具") != NULL) { Function::ESP::道具 = stoi(token); }
			if (strstr(paramName.c_str(), "扩容") != NULL) { Function::ESP::扩容 = stoi(token); }
			if (strstr(paramName.c_str(), "金魂") != NULL) { Function::ESP::金魂 = stoi(token); }
			if (strstr(paramName.c_str(), "夺魂") != NULL) { Function::ESP::夺魂 = stoi(token); }
			if (strstr(paramName.c_str(), "属性") != NULL) { Function::ESP::属性 = stoi(token); }
			if (strstr(paramName.c_str(), "盒子") != NULL) { Function::ESP::盒子 = stoi(token); }
			if (strstr(paramName.c_str(), "白甲") != NULL) { Function::ESP::护甲Lv1 = stoi(token); }
			if (strstr(paramName.c_str(), "蓝甲") != NULL) { Function::ESP::护甲Lv2 = stoi(token); }
			if (strstr(paramName.c_str(), "紫甲") != NULL) { Function::ESP::护甲Lv3 = stoi(token); }
			if (strstr(paramName.c_str(), "金甲") != NULL) { Function::ESP::护甲Lv4 = stoi(token); }
			if (strstr(paramName.c_str(), "红甲") != NULL) { Function::ESP::护甲Lv5 = stoi(token); }
			if (strstr(paramName.c_str(), "果实") != NULL) { Function::ESP::果实 = stoi(token); }
			if (strstr(paramName.c_str(), "萤火虫") != NULL) { Function::ESP::萤火虫 = stoi(token); }
			if (strstr(paramName.c_str(), "金堆") != NULL) { Function::ESP::金堆 = stoi(token); }
			if (strstr(paramName.c_str(), "蓝堆") != NULL) { Function::ESP::蓝堆 = stoi(token); }
			if (strstr(paramName.c_str(), "绿堆") != NULL) { Function::ESP::绿堆 = stoi(token); }
			if (strstr(paramName.c_str(), "任务") != NULL) { Function::ESP::任务 = stoi(token); }

			if (strstr(paramName.c_str(), "启用振刀") != NULL) { Function::Shock::F_ShockKnife = stoi(token); }
			if (strstr(paramName.c_str(), "预判振刀") != NULL) { Function::Shock::预判振刀 = stoi(token); }
			if (strstr(paramName.c_str(), "扬鞭劲振刀") != NULL) { Function::Shock::扬鞭劲振刀 = stoi(token); }
			if (strstr(paramName.c_str(), "横栏振刀") != NULL) { Function::Shock::横栏振刀 = stoi(token); }
			if (strstr(paramName.c_str(), "横刀左蓄振刀") != NULL) { Function::Shock::横刀左蓄振刀 = stoi(token); }
			if (strstr(paramName.c_str(), "是否闪避") != NULL) { Function::Shock::Flag_ShortDodge = stoi(token); }
			if (strstr(paramName.c_str(), "是否拼刀") != NULL) { Function::Shock::Flag_CollideKnife = stoi(token); }
			if (strstr(paramName.c_str(), "振刀延迟") != NULL) { Function::Shock::Shock_Delay = stoi(token); }
			if (strstr(paramName.c_str(), "输出调试执行") != NULL) { 调试::输出调试执行 = stoi(token); }
			if (strstr(paramName.c_str(), "输出逻辑执行") != NULL) { 调试::输出逻辑执行 = stoi(token); }
			if (strstr(paramName.c_str(), "按键方式") != NULL) { 按键方式 = stoi(token); }
			if (strstr(paramName.c_str(), "双截棍左蓄短闪振") != NULL) { 振刀参数::特殊处理::双截棍左蓄是否短闪振 = stoi(token); }
			if (strstr(paramName.c_str(), "扇子左蓄中闪振") != NULL) { 振刀参数::特殊处理::扇子左蓄是否中闪振 = stoi(token); }
			if (strstr(paramName.c_str(), "扇子右蓄中闪振") != NULL) { 振刀参数::特殊处理::扇子右蓄是否中闪振 = stoi(token); }
			if (strstr(paramName.c_str(), "斩马刀左蓄长闪振") != NULL) { 振刀参数::特殊处理::斩马刀左蓄是否长闪振 = stoi(token); }
			if (strstr(paramName.c_str(), "阔刀右蓄短闪振") != NULL) { 振刀参数::特殊处理::阔刀右蓄是否短闪振 = stoi(token); }
			if (strstr(paramName.c_str(), "横刀左蓄是否只短闪") != NULL) { 振刀参数::特殊处理::横刀左蓄是否只短闪 = stoi(token); }

			if (strstr(paramName.c_str(), "启用闪避") != NULL) { Function::HeroActivation::IsDodge = stoi(token); }
			if (strstr(paramName.c_str(), "躲避火男冲拳") != NULL) { Function::HeroActivation::躲避火男冲拳 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避火男F") != NULL) { Function::HeroActivation::躲避火男F = stoi(token); }
			if (strstr(paramName.c_str(), "躲避妖刀大招") != NULL) { Function::HeroActivation::躲避妖刀大招 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避顾清寒V1V2") != NULL) { Function::HeroActivation::躲避顾清寒V1V2 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避武田F") != NULL) { Function::HeroActivation::躲避武田F = stoi(token); }
			if (strstr(paramName.c_str(), "躲避胡为") != NULL) { Function::HeroActivation::躲避胡为 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避宁红叶F") != NULL) { Function::HeroActivation::躲避宁红叶F = stoi(token); }
			if (strstr(paramName.c_str(), "躲避狐狸大招") != NULL) { Function::HeroActivation::躲避狐狸大招 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避三娘V2") != NULL) { Function::HeroActivation::躲避三娘V2 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避哈迪大招") != NULL) { Function::HeroActivation::躲避哈迪大招 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避魏轻F1") != NULL) { Function::HeroActivation::躲避魏轻F1 = stoi(token); }
			if (strstr(paramName.c_str(), "躲避魏轻大招") != NULL) { Function::HeroActivation::躲避魏轻V = stoi(token); }
			if (strstr(paramName.c_str(), "蓄力抓振刀") != NULL) { Function::LogicKnife::BlueAttackShock = stoi(token); }
			if (strstr(paramName.c_str(), "蓄力抓白刀") != NULL) { Function::LogicKnife::BlueAttackWrite = stoi(token); }
			if (strstr(paramName.c_str(), "出蓄抓振延迟") != NULL) { 活化参数::出蓄抓振延迟 = stoi(token); }



		}
	}
}
void 读取其他配置()
{
	std::ifstream file("其他配置.ini");
	if (file.is_open())
	{
		std::string line;
		while (std::getline(file, line))
		{
			判断其他配置(line);
		}

		file.close();
	}

}

ImFont* medium;
ImFont* bold;
ImFont* tab_icons;
ImFont* logo;
ImFont* tab_title;
ImFont* tab_title_icon;
ImFont* subtab_title;
ImFont* combo_arrow;
enum heads {
	启动
};

enum sub_heads {
	透视配置, 振刀配置,物品配置, 活化配置, 杂项配置
};

void MenuESP()
{
	static bool 初始化 = false, 初始化读取 = false;
	if (初始化读取 == false) { 读取其他配置(); 读取Kmbox配置(); 初始化读取 = true; }

	if (Function::ESP::菜单)
	{
		static heads tab{ 启动 };
		static sub_heads subtab{ 透视配置 };

		const char* 血条样式[3] = { u8"自定义 0",u8"自定义 1", u8"自定义 2" };
		const char* 预警样式[2] = { u8"自定义 0",u8"自定义 1" };

		ImGui::SetNextWindowSize({ 830, 580 });
		ImGui::PushStyleVar(ImGuiStyleVar_WindowPadding, { 0, 0 });

		ImGui::Begin("Cheats", nullptr, ImGuiWindowFlags_NoDecoration); {
			auto draw = ImGui::GetWindowDrawList();

			auto pos = ImGui::GetWindowPos();
			auto size = ImGui::GetWindowSize();

			ImGuiStyle style = ImGui::GetStyle();
			//背景色
			draw->AddRectFilled(pos, ImVec2(pos.x + 160, pos.y + size.y), ImColor(24, 24, 26), style.WindowRounding, ImDrawFlags_RoundCornersLeft);
			//背景分割线
			draw->AddLine(ImVec2(pos.x + 160, pos.y + 2), ImVec2(pos.x + 160, pos.y + size.y - 2), ImColor(1.0f, 1.0f, 1.0f, 0.03f));
			//标题分割线
			draw->AddLine(ImVec2(pos.x, pos.y + 47), ImVec2(pos.x + 160, pos.y + 47), ImColor(1.0f, 1.0f, 1.0f, 0.03f));
			//标题
			draw->AddText(logo, 18.0f, ImVec2(pos.x + 50, pos.y + 14), ImColor(66, 167, 190), " Naraka");

			ImVec2 temp = { pos.x + size.x - 1,pos.y + size.y - 1 };

			draw->AddRect({ pos.x + 1, pos.y + 1 }, temp, ImColor(1.0f, 1.0f, 1.0f, 0.03f), style.WindowRounding);
			switch (tab) {
			case 启动:
				ImGui::SetCursorPos({ 8, 50 });
				ImGui::BeginGroup(); {
					if (elements::subtab(u8"             玩家", subtab == 透视配置)) { subtab = 透视配置; }
					if (elements::subtab(u8"             振刀", subtab == 振刀配置)) { subtab = 振刀配置; }
					if (elements::subtab(u8"             物品", subtab == 物品配置)) { subtab = 物品配置; }
					if (elements::subtab(u8"             活化", subtab == 活化配置)) { subtab = 活化配置; }
					if (elements::subtab(u8"             杂项", subtab == 杂项配置)) { subtab = 杂项配置; }
				} ImGui::EndGroup();
				switch (subtab) {
				case 透视配置:
					ImGui::SetCursorPos({ 190, 16 });
					e_elements::begin_child(u8"人物", ImVec2(250, 450)); {
						ImGui::Checkbox(u8"方框", &Function::ESP::方框);
						ImGui::Checkbox(u8"信息", &Function::ESP::信息);
						ImGui::Checkbox(u8"名字", &Function::ESP::名字);
						ImGui::Checkbox(u8"血甲", &Function::ESP::血条);
						ImGui::Checkbox(u8"手持", &Function::ESP::手持);
						ImGui::Checkbox(u8"盲区预警", &Function::ESP::预警);
						ImGui::Combo(u8"血甲样式", &Function::ESP::血条样式, 血条样式, IM_ARRAYSIZE(血条样式));
						ImGui::Combo(u8"预警样式", &Function::ESP::预警样式, 预警样式, IM_ARRAYSIZE(预警样式));
						ImGui::ColorEdit4(u8"人机颜色", reinterpret_cast<float*>(&Function::ESP::人机颜色), ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(u8"玩家颜色", reinterpret_cast<float*>(&Function::ESP::玩家颜色), ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(u8"名字颜色", reinterpret_cast<float*>(&Function::ESP::名字颜色), ImGuiColorEditFlags_NoInputs);
						ImGui::ColorEdit4(u8"信息颜色", reinterpret_cast<float*>(&Function::ESP::信息颜色), ImGuiColorEditFlags_NoInputs);
					}
					e_elements::end_child();
					break;
				}
				switch (subtab) {
				case 振刀配置:
					ImGui::SetCursorPos({ 190, 16 });
					e_elements::begin_child(u8"选择", ImVec2(240, 400)); {
						if (ImGui::Checkbox(u8"模拟振刀", &Function::Shock::F_ShockKnife))
						{
							if (Function::Shock::F_ShockKnife)
							{
								读取模拟振配置();
								Function::Shock::F_MemShock = false;
							}
						}
						ImGui::SameLine();
						ImGui::Text(u8"F5快捷开关");
						if (ImGui::Checkbox(u8"内存振刀", &Function::Shock::F_MemShock))
						{
							if (Function::Shock::F_MemShock)
							{
								读取内存振配置();
								Function::Shock::F_ShockKnife = false;
							}
						}
						if (ImGui::IsItemHovered())
						{
							ImGui::SetTooltip(u8"一但启用内存振后，有封号风险，若不想开内存以后，必须重启游戏重启辅助自动清理残留");
						}
						ImGui::Checkbox(u8"预判振刀", &Function::Shock::预判振刀);
						ImGui::Checkbox(u8"振扬鞭劲", &Function::Shock::扬鞭劲振刀);
						ImGui::Checkbox(u8"振横栏", &Function::Shock::横栏振刀);
						ImGui::Checkbox(u8"振横刀左蓄", &Function::Shock::横刀左蓄振刀);
						ImGui::Checkbox(u8"是否闪避", &Function::Shock::Flag_ShortDodge);
						ImGui::Checkbox(u8"是否拼刀", &Function::Shock::Flag_CollideKnife);
						ImGui::Checkbox(u8"和尚F2", &Function::HeroActivation::和尚自动F2);
						ImGui::Checkbox(u8"武田夺刀", &Function::HeroActivation::武田自动毛刀);
						ImGui::SliderInt(u8"", &Function::Shock::Shock_Delay, -100, 100);
						if (ImGui::IsItemHovered())
						{
							ImGui::SetTooltip(u8"数值越高，振刀时间点越早，适用于能站振招式");
						}
						ImGui::Checkbox(u8"输出调试执行", &调试::输出调试执行);
						if (ImGui::IsItemHovered())
						{
							ImGui::SetTooltip(u8"请勿开启输出调试执行玩游戏，此功能会显示范围内所有的出招距离以及角度，此功能仅仅只是方便用户自身调试范围和距离而开启的功能");
						}
						ImGui::SameLine();
						ImGui::Checkbox(u8"输出逻辑执行", &调试::输出逻辑执行);
						if (ImGui::IsItemHovered())
						{
							ImGui::SetTooltip(u8"该功能可以在玩游戏时开启，此功能将记录本局所有的振刀-拼刀-闪避等一系列操作，方便用户优化实战中招式的角度以及范围");
						}
						ImGui::RadioButton("KmBox-Net", &按键方式, 0);
						ImGui::SameLine();
						ImGui::RadioButton("KmBox-Pro", &按键方式, 1);

					}
					e_elements::end_child();
					ImGui::SetCursorPos({ 190, 420 });
					e_elements::begin_child(u8"特殊处理", ImVec2(220, 150)); {

						ImGui::Checkbox(u8"双截棍左蓄短闪振", &振刀参数::特殊处理::双截棍左蓄是否短闪振);
						ImGui::Checkbox(u8"扇子左蓄中闪振", &振刀参数::特殊处理::扇子左蓄是否中闪振);
						ImGui::Checkbox(u8"扇子右蓄中闪振 ", &振刀参数::特殊处理::扇子右蓄是否中闪振);
						ImGui::Checkbox(u8"斩马刀左蓄长闪振", &振刀参数::特殊处理::斩马刀左蓄是否长闪振);
						ImGui::Checkbox(u8"阔刀右蓄短闪振", &振刀参数::特殊处理::阔刀右蓄是否短闪振);
						ImGui::Checkbox(u8"横刀是否只短闪", &振刀参数::特殊处理::横刀左蓄是否只短闪);

					}
					e_elements::end_child();
					ImGui::SetCursorPos({ 450, 16 });
					e_elements::begin_child(u8"参数", ImVec2(350, 480)); {
						if (ImGui::CollapsingHeader(u8"长剑"))
						{
							if (ImGui::TreeNode(u8"左三"))
							{
								ImGui::SliderFloat(u8" 距离", &振刀参数::距离::长剑.左3, 1.f, 5.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长剑.左3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长剑.右3, 1.f, 5.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长剑.右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左剑气"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长剑.左剑气, 1.f, 15.f);
								振刀参数::距离::长剑.左剑气 = 振刀参数::距离::长剑.左剑气;
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::长剑.左剑气2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"4M角度", &振刀参数::角度::长剑.左剑气4M, 1.f, 360.f);//A
								ImGui::SliderFloat(u8"6M角度", &振刀参数::角度::长剑.左剑气6M, 1.f, 360.f);
								ImGui::SliderFloat(u8"9M角度", &振刀参数::角度::长剑.左剑气9M, 1.f, 360.f);
								ImGui::SliderFloat(u8"9M外角度", &振刀参数::角度::长剑.左剑气9M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右剑气"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长剑.右剑气, 1.f, 15.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::长剑.右剑气2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"4M角度", &振刀参数::角度::长剑.右剑气4M, 1.f, 360.f);
								ImGui::SliderFloat(u8"6M角度", &振刀参数::角度::长剑.右剑气6M, 1.f, 360.f);
								ImGui::SliderFloat(u8"9M角度", &振刀参数::角度::长剑.右剑气9M, 1.f, 360.f);
								ImGui::SliderFloat(u8"9M外角度", &振刀参数::角度::长剑.右剑气9M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"凤凰羽"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长剑.凤凰羽, 1.f, 15.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::长剑.凤凰羽2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"5M角度", &振刀参数::角度::长剑.凤凰羽5M, 1.f, 360.f);
								ImGui::SliderFloat(u8"8M角度", &振刀参数::角度::长剑.凤凰羽8M, 1.f, 360.f);
								ImGui::SliderFloat(u8"8M外角度", &振刀参数::角度::长剑.凤凰羽8M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"蓝月"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长剑.蓝月, 1.f, 15.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::长剑.蓝月2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"6M角度", &振刀参数::角度::长剑.蓝月6M, 1.f, 360.f);
								ImGui::SliderFloat(u8"6M外角度", &振刀参数::角度::长剑.蓝月6M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"七星夺窍"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长剑.七星夺窍, 1.f, 15.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长剑.七星夺窍, 1.f, 360.f);

								ImGui::TreePop();
							}
						}
						if (ImGui::CollapsingHeader(u8"太刀"))
						{
							if (ImGui::TreeNode(u8"左三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.左3, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::太刀.左3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.右3, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::太刀.右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左百裂"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.左蓄, 1.f, 11.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::太刀.左蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::太刀.左蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右百裂"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.右蓄, 1.f, 11.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::太刀.右蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::太刀.右蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左惊雷"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.左惊雷, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::太刀.左惊雷, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右惊雷&惊雷十劫"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.右惊雷, 1.f, 11.f);
								ImGui::SliderFloat(u8"5M角度", &振刀参数::角度::太刀.右惊雷5M, 1.f, 360.f);
								ImGui::SliderFloat(u8"5M外角度", &振刀参数::角度::太刀.右惊雷5M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左青鬼"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.左青鬼, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::太刀.左青鬼, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右青鬼"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.右青鬼, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::太刀.右青鬼, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"噬魂斩"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::太刀.噬魂斩, 1.f, 13.f);
								ImGui::TreePop();
							}

						}
						if (ImGui::CollapsingHeader(u8"阔刀"))
						{
							if (ImGui::TreeNode(u8"左左"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.左左, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::阔刀.左左, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左右"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.左右, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::阔刀.左右2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::阔刀.左右2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右右"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.右右, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::阔刀.右右, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄一段"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.左蓄一段, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::阔刀.左蓄一段2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::阔刀.左蓄一段2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄二段"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.左蓄二段, 1.f, 10.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄三段"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.左蓄三段, 1.f, 10.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.右蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::阔刀.右蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::阔刀.右蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.右右蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M角度", &振刀参数::角度::阔刀.右右蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::阔刀.右右蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"雷刀"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.雷刀, 1.f, 10.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"雷刀下劈"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::阔刀.雷刀下劈, 1.f, 10.f);
								ImGui::TreePop();
							}
						}
						if (ImGui::CollapsingHeader(u8"长枪"))
						{
							if (ImGui::TreeNode(u8"左三连"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.左3, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长枪.左3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右三连"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.右3, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长枪.右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.左蓄, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长枪.左蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.右蓄, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长枪.右蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"六合枪"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.六合枪, 1.f, 11.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::长枪.六合枪2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::长枪.六合枪2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"大圣游"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.大圣游, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长枪.大圣游, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"风卷云残"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.风卷云残, 1.f, 11.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长枪.风卷云残, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"双环扫"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.双环扫, 1.f, 11.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"龙王破"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.龙王破, 1.f, 11.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::长枪.龙王破2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::长枪.龙王破2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"穿心脚"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长枪.穿心脚, 1.f, 11.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::长枪.穿心脚2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::长枪.穿心脚2M外, 1.f, 360.f);
								ImGui::TreePop();
							}

						}
						if (ImGui::CollapsingHeader(u8"匕首"))
						{
							if (ImGui::TreeNode(u8"左三连"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.左3, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::匕首.左3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右三连"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.右3, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::匕首.右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.右蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::匕首.右蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::匕首.右蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.左蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::匕首.左蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::匕首.左蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"鬼返"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.鬼反, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::匕首.鬼反, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"荆轲献匕"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.荆轲献匕, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::匕首.荆轲献匕2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::匕首.荆轲献匕2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"鬼刃暗扎"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.鬼刃暗扎, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::匕首.鬼刃暗扎2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::匕首.鬼刃暗扎2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"鬼哭神嚎"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.鬼哭神嚎, 1.f, 10.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"亢龙有悔"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::匕首.亢龙有悔, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::匕首.亢龙有悔2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"4M内角度", &振刀参数::角度::匕首.亢龙有悔4M, 1.f, 360.f);
								ImGui::SliderFloat(u8"4M外角度", &振刀参数::角度::匕首.亢龙有悔4M外, 1.f, 360.f);
								ImGui::TreePop();
							}

						}
						if (ImGui::CollapsingHeader(u8"双截棍"))
						{
							if (ImGui::TreeNode(u8"左右三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双截棍.左右3, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双截棍.左右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双截棍.左蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::双截棍.左蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::双截棍.左蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双截棍.右蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::双截棍.右蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::双截棍.右蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"飞踢"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双截棍.飞踢, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双截棍.飞踢, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"扬鞭劲"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双截棍.扬鞭劲, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双截棍.扬鞭劲, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"横栏"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双截棍.横栏, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双截棍.横栏, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"龙虎乱舞"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双截棍.龙虎乱舞, 1.f, 10.f);
								ImGui::TreePop();
							}
						}
						if (ImGui::CollapsingHeader(u8"双刀"))
						{
							if (ImGui::TreeNode(u8"左右三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.左右3, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双刀.左右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.左蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双刀.左蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.右蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双刀.右蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"铁马残红"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.铁马残红, 1.f, 10.f);
								ImGui::SliderFloat(u8"3M内角度", &振刀参数::角度::双刀.铁马残红3M, 1.f, 360.f);
								ImGui::SliderFloat(u8"3M外角度", &振刀参数::角度::双刀.铁马残红3M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"乾坤日月斩"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.乾坤日月斩, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双刀.乾坤日月斩, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"惊雷"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.惊雷, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双刀.惊雷, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"八斩刀"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.八斩刀, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双刀.八斩刀, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"分水斩"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双刀.分水斩, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双刀.分水斩, 1.f, 360.f);
								ImGui::TreePop();
							}
						}
						if (ImGui::CollapsingHeader(u8"长棍"))
						{
							if (ImGui::TreeNode(u8"左三连"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.左3, 0.f, 14.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.左3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右三连"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.右3, 0.f, 14.f);
								//asdmd
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.左蓄, 0.f, 14.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::长棍.左蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::长棍.左蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.右蓄, 0.f, 14.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"少林棍"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.少林棍, 0.f, 14.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.少林棍, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"腾云式"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.腾云式, 0.f, 14.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::长棍.腾云式2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::长棍.腾云式2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"乱点天宫"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.乱点天宫, 0.f, 14.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.乱点天宫, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"桶劲"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.桶劲, 0.f, 14.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.桶劲, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"五情七灭镇"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.五情七灭镇, 0.f, 14.f);
								ImGui::SliderFloat(u8"8M内角度", &振刀参数::角度::长棍.五情七灭镇8M, 1.f, 360.f);
								ImGui::SliderFloat(u8"8M外角度", &振刀参数::角度::长棍.五情七灭镇8M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"双环扫"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.双环扫, 0.f, 14.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.双环扫, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"倒海棍"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.倒海棍, 0.f, 14.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.倒海棍, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"镇地撑天"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::长棍.镇地撑天, 0.f, 14.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::长棍.镇地撑天, 1.f, 360.f);
								ImGui::TreePop();
							}

						}
						if (ImGui::CollapsingHeader(u8"斩马刀"))
						{
							if (ImGui::TreeNode(u8"左左"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.左左, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.左左, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左右"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.左右, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::斩马刀.左右2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::斩马刀.左右2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右右"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.右右, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.右右, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右左"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.右左, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.右左, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.左蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::斩马刀.左蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::斩马刀.左蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.右蓄, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.右蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"柄击"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.柄击, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.柄击, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"惊雷"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.惊雷, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.惊雷, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"炽焰斩"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.炽焰斩, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.炽焰斩, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"过关斩将"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::斩马刀.过关斩将, 1.f, 10.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::斩马刀.过关斩将, 1.f, 360.f);
								ImGui::TreePop();
							}

						}
						if (ImGui::CollapsingHeader(u8"双戟"))
						{
							if (ImGui::TreeNode(u8"左右三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.左右3, 0.f, 8.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双戟.左右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.左蓄, 0.f, 8.f);
								ImGui::SliderFloat(u8"3M内角度", &振刀参数::角度::双戟.左蓄3M, 1.f, 360.f);
								ImGui::SliderFloat(u8"3M外角度", &振刀参数::角度::双戟.左蓄3M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.右蓄, 0.f, 8.f);
								ImGui::SliderFloat(u8"3M内角度", &振刀参数::角度::双戟.右蓄3M, 1.f, 360.f);
								ImGui::SliderFloat(u8"3M外角度", &振刀参数::角度::双戟.右蓄3M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"勾旋斩"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.勾旋斩, 0.f, 8.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双戟.勾旋斩, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"探海蛟"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.探海蛟, 0.f, 8.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双戟.探海蛟, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"钩挂"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.钩挂, 0.f, 8.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双戟.钩挂, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"战龙在天"))
							{//哈哈
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.战龙在天, 0.f, 8.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双戟.战龙在天, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"形意钩"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::双戟.形意钩, 0.f, 8.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::双戟.形意钩, 1.f, 360.f);
								ImGui::TreePop();
							}

						}
						if (ImGui::CollapsingHeader(u8"扇子"))
						{
							if (ImGui::TreeNode(u8"左三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.左3, 0.f, 12.5f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::扇子.左3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.右3, 0.f, 12.5f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::扇子.右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.左蓄, 0.f, 12.5f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::扇子.左蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.右蓄, 0.f, 12.5f);
								ImGui::SliderFloat(u8"2M内角度", &振刀参数::角度::扇子.右蓄2M, 1.f, 360.f);
								ImGui::SliderFloat(u8"2M外角度", &振刀参数::角度::扇子.右蓄2M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"双开圆"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.双开圆, 0.f, 12.5f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::扇子.双开圆, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"三风摆"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.三风摆, 0.f, 12.5f);
								ImGui::SliderFloat(u8"3M内角度", &振刀参数::角度::扇子.三风摆3M, 1.f, 360.f);
								ImGui::SliderFloat(u8"3M外角度", &振刀参数::角度::扇子.三风摆3M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"惊雷"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.惊雷, 0.f, 12.5f);
								ImGui::SliderFloat(u8"3M内角度", &振刀参数::角度::扇子.惊雷, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"缠龙奔野"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.缠龙奔野, 0.f, 12.5f);
								ImGui::SliderFloat(u8"3M内角度", &振刀参数::角度::扇子.缠龙奔野3M, 1.f, 360.f);
								ImGui::SliderFloat(u8"3M外角度", &振刀参数::角度::扇子.缠龙奔野3M外, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"鬼返"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::扇子.鬼反, 0.f, 12.5f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::扇子.鬼反, 1.f, 360.f);
								ImGui::TreePop();
							}

						}
						if (ImGui::CollapsingHeader(u8"横刀"))
						{
							if (ImGui::TreeNode(u8"左三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::横刀.左3, 0.f, 7.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::横刀.左3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右三"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::横刀.右3, 0.f, 7.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::横刀.右3, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"左蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::横刀.左蓄, 0.f, 7.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::横刀.左蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"右蓄"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::横刀.右蓄, 0.f, 7.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::横刀.右蓄, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"破千军"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::横刀.破千军, 0.f, 7.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::横刀.破千军, 1.f, 360.f);
								ImGui::TreePop();
							}
							if (ImGui::TreeNode(u8"极光破云闪"))
							{
								ImGui::SliderFloat(u8"距离", &振刀参数::距离::横刀.极光破云闪, 0.f, 7.f);
								ImGui::SliderFloat(u8"角度", &振刀参数::角度::横刀.极光破云闪, 1.f, 360.f);
								ImGui::TreePop();
							}
						}
						if (ImGui::Button(u8"保存配置"))
						{
							Function::Shock::F_ShockKnife ? 保存模拟振配置() : 保存内存振配置();
						}
						ImGui::SameLine();
						if (ImGui::Button(u8"读取配置"))
						{
							Function::Shock::F_ShockKnife ? 读取模拟振配置() : 读取内存振配置();
						}
					}
					e_elements::end_child();
					break;
				}
				switch (subtab) {
				case 物品配置:
					ImGui::SetCursorPos({ 190, 16 });
					e_elements::begin_child(u8"物品", ImVec2(220, 400)); {
						ImGui::Checkbox(u8"近战", &Function::ESP::近战);
						ImGui::SameLine();
						ImGui::Checkbox(u8"远程", &Function::ESP::远程);
						ImGui::SameLine();
						ImGui::Checkbox(u8"魂冢", &Function::ESP::盒子);


						ImGui::Checkbox(u8"金魂", &Function::ESP::金魂);
						ImGui::SameLine();
						ImGui::Checkbox(u8"夺魂", &Function::ESP::夺魂);
						ImGui::SameLine();
						ImGui::Checkbox(u8"扩容", &Function::ESP::扩容);

						ImGui::Checkbox(u8"萤火虫", &Function::ESP::萤火虫);
						ImGui::SameLine();
						ImGui::Checkbox(u8"果实", &Function::ESP::果实);
						ImGui::SameLine();
						ImGui::Checkbox(u8"金堆", &Function::ESP::金堆);

						ImGui::Checkbox(u8"蓝堆", &Function::ESP::蓝堆);
						ImGui::SameLine();
						ImGui::Checkbox(u8"绿堆", &Function::ESP::绿堆);
						ImGui::SameLine();
						ImGui::Checkbox(u8"任务", &Function::ESP::任务);

						ImGui::Checkbox(u8"白甲", &Function::ESP::护甲Lv1);
						ImGui::SameLine();
						ImGui::Checkbox(u8"蓝甲", &Function::ESP::护甲Lv2);
						ImGui::SameLine();
						ImGui::Checkbox(u8"紫甲", &Function::ESP::护甲Lv3);

						ImGui::Checkbox(u8"金甲", &Function::ESP::护甲Lv4);
						ImGui::SameLine();
						ImGui::Checkbox(u8"红甲", &Function::ESP::护甲Lv5);
						ImGui::SameLine();
						ImGui::Checkbox(u8"道具", &Function::ESP::道具);

					}
					e_elements::end_child();

					break;
				}
				switch (subtab) {
				case 活化配置:
					ImGui::SetCursorPos({ 190, 16 });
					e_elements::begin_child(u8"闪避", ImVec2(220, 370)); {
						ImGui::Checkbox(u8"启用闪避", &Function::HeroActivation::IsDodge);
						ImGui::SameLine();
						ImGui::Text(u8"F6快捷开关");
						ImGui::Checkbox(u8"躲避火男冲拳", &Function::HeroActivation::躲避火男冲拳);
						ImGui::Checkbox(u8"躲避火男F", &Function::HeroActivation::躲避火男F);
						ImGui::Checkbox(u8"躲避妖刀大招", &Function::HeroActivation::躲避妖刀大招);
						ImGui::Checkbox(u8"躲避顾清寒V1V2", &Function::HeroActivation::躲避顾清寒V1V2);
						ImGui::Checkbox(u8"永远躲避顾清寒V1", &Function::HeroActivation::特殊处理::永远躲避顾倾寒V1);
						ImGui::Checkbox(u8"躲避武田F", &Function::HeroActivation::躲避武田F);
						ImGui::Checkbox(u8"躲避胡为", &Function::HeroActivation::躲避胡为);
						ImGui::Checkbox(u8"躲避宁红夜F", &Function::HeroActivation::躲避宁红叶F);
						ImGui::Checkbox(u8"躲避狐狸V1V2", &Function::HeroActivation::躲避狐狸大招);
						ImGui::Checkbox(u8"躲避三娘V2", &Function::HeroActivation::躲避三娘V2);
						ImGui::Checkbox(u8"躲避哈迪大招", &Function::HeroActivation::躲避哈迪大招);
						ImGui::Checkbox(u8"躲避魏轻F1", &Function::HeroActivation::躲避魏轻F1);
						ImGui::Checkbox(u8"躲避魏轻V", &Function::HeroActivation::躲避魏轻V);

					}
					e_elements::end_child();
					ImGui::SetCursorPos({ 190, 400 });
					e_elements::begin_child(u8"出蓄", ImVec2(250, 150)); {

						ImGui::Checkbox(u8"蓄力抓振刀", &Function::LogicKnife::BlueAttackShock);
						ImGui::Checkbox(u8"蓄力抓白刀", &Function::LogicKnife::BlueAttackWrite);
						ImGui::SliderInt(u8"", &活化参数::出蓄抓振延迟, 0, 300);
						if (ImGui::IsItemHovered())
						{
							ImGui::SetTooltip(u8"数值越高,出蓄抓振刀时越慢");
						}
					}
					e_elements::end_child();
					ImGui::SetCursorPos({ 450, 16 });
					e_elements::begin_child(u8"参数", ImVec2(330, 480)); {
						if (ImGui::TreeNode(u8"火男冲拳"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::火男冲拳, 0.f, 5.f);
							ImGui::SliderFloat(u8"角度", &活化参数::角度::火男冲拳, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"火男F"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::火男F, 0.f, 5.f);
							ImGui::SliderFloat(u8"角度", &活化参数::角度::火男F, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"妖刀大招"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::妖刀大招, 0.f, 35.f);
							ImGui::SliderFloat(u8"3M角度", &活化参数::角度::妖刀大招3M, 1.f, 360.f);
							ImGui::SliderFloat(u8"3M外角度", &活化参数::角度::妖刀大招3M外, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"顾倾寒大招"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::顾倾寒大招, 0.f, 35.f);
							ImGui::SliderFloat(u8"3M内角度", &活化参数::角度::顾倾寒大招3M, 1.f, 360.f);
							ImGui::SliderFloat(u8"3M外角度", &活化参数::角度::顾倾寒大招3M外, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"武田F2"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::武田F2, 0.f, 6.f);
							ImGui::SliderFloat(u8"1M内角度", &活化参数::角度::武田F21M, 1.f, 360.f);
							ImGui::SliderFloat(u8"1M外角度", &活化参数::角度::武田F21M外, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"武田F3"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::武田F2, 0.f, 4.f);
							ImGui::SliderFloat(u8"1M内角度", &活化参数::角度::武田F31M, 1.f, 360.f);
							ImGui::SliderFloat(u8"1M外角度", &活化参数::角度::武田F31M外, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"胡为F1"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::胡为F1, 0.f, 7.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"胡为F2"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::胡为F2, 0.f, 10.f);
							ImGui::SliderFloat(u8"角度", &活化参数::角度::胡为F2, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"胡为跃击"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::胡为跃击, 0.f, 12.f);
							ImGui::SliderFloat(u8"角度", &活化参数::角度::胡为跃击, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"胡为V1V2"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::胡为V1V2, 0.f, 15.f);
							ImGui::SliderFloat(u8"角度", &活化参数::角度::胡为V1V2, 1.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"宁红夜F"))
						{
							ImGui::SliderFloat(u8"F1距离", &活化参数::距离::宁红叶F1, 0.f, 15.f);
							ImGui::SliderFloat(u8"F2距离", &活化参数::距离::宁红叶F2, 0.f, 15.f);
							ImGui::SliderFloat(u8"F3距离", &活化参数::距离::宁红叶F3, 0.f, 15.f);
							ImGui::SliderFloat(u8"F1角度", &活化参数::角度::宁红叶F1, 0.f, 360.f);
							ImGui::SliderFloat(u8"F2角度", &活化参数::角度::宁红叶F2, 0.f, 360.f);
							ImGui::SliderFloat(u8"F3角度", &活化参数::角度::宁红叶F3, 0.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"狐狸V1V2"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::狐狸大招, 0.f, 15.f);

							ImGui::SliderFloat(u8"4M角度", &活化参数::角度::狐狸大招4M, 0.f, 360.f);
							ImGui::SliderFloat(u8"8M角度", &活化参数::角度::狐狸大招8M, 0.f, 360.f);
							ImGui::SliderFloat(u8"12M角度", &活化参数::角度::狐狸大招12M, 0.f, 360.f);
							ImGui::SliderFloat(u8"12M外角度", &活化参数::角度::狐狸大招12M外, 0.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"三娘V2"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::三娘V2, 0.f, 15.f);

							ImGui::SliderFloat(u8"4M角度", &活化参数::角度::三娘V24M, 0.f, 360.f);
							ImGui::SliderFloat(u8"10M角度", &活化参数::角度::三娘V210M, 0.f, 360.f);
							ImGui::SliderFloat(u8"10M外角度", &活化参数::角度::三娘V210M外, 0.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"哈迪大招"))
						{
							ImGui::SliderFloat(u8"2段距离", &活化参数::距离::哈迪大招2段, 0.f, 15.f);
							ImGui::SliderFloat(u8"3段距离", &活化参数::距离::哈迪大招3段, 0.f, 15.f);
							ImGui::SliderFloat(u8"角度", &活化参数::角度::哈迪大招, 0.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"魏轻F1"))
						{
							ImGui::SliderFloat(u8"距离", &活化参数::距离::魏轻F1, 0.f, 8.f);
							ImGui::TreePop();
						}
						if (ImGui::TreeNode(u8"魏轻V1V2"))
						{
							ImGui::SliderFloat(u8"V1距离", &活化参数::距离::魏轻V1, 0.f, 20.f);
							ImGui::SliderFloat(u8"V2距离", &活化参数::距离::魏轻V2, 0.f, 6.f);
							ImGui::SliderFloat(u8"V1角度", &活化参数::角度::魏轻V1, 0.f, 360.f);
							ImGui::SliderFloat(u8"V2角度", &活化参数::角度::魏轻V2, 0.f, 360.f);
							ImGui::TreePop();
						}
						if (ImGui::Button(u8"保存配置")) {
							保存活化配置();
						}
						ImGui::SameLine();
						if (ImGui::Button(u8"读取配置")) {
							读取活化配置(); 
						}

					}
					e_elements::end_child();
					break;
				}
				switch (subtab) {
				case 杂项配置:
					ImGui::SetCursorPos({ 190, 16 });
					e_elements::begin_child(u8"KmBox-Net", ImVec2(240, 240)); {

						ImGui::InputTextEx(u8"IP", "", Function::Kmbox::Net::IP, sizeof(Function::Kmbox::Net::IP), ImVec2(110.f, 20.f), ImGuiInputTextFlags_None);
						ImGui::InputTextEx(u8"Port", "", Function::Kmbox::Net::Port, sizeof(Function::Kmbox::Net::Port), ImVec2(110.f, 20.f), ImGuiInputTextFlags_None);
						ImGui::InputTextEx(u8"UUID", "", Function::Kmbox::Net::mac, sizeof(Function::Kmbox::Net::mac), ImVec2(110.f, 20.f), ImGuiInputTextFlags_None);
						if (ImGui::Button(u8"连接")) {
							保存Kmbox();
							Function::Kmbox::Net::NetState = kmNet_init(Function::Kmbox::Net::IP, Function::Kmbox::Net::Port, Function::Kmbox::Net::mac);

						}
						if (Function::Kmbox::Net::NetState == 0) { ImGui::Text(u8"NET已连接"); }
						if (Function::Kmbox::Net::NetState != 0) { ImGui::Text(u8"未连接或失败ID:[%d]", Function::Kmbox::Net::NetState); }

					}
					e_elements::end_child();
					ImGui::SetCursorPos({ 450, 16 });
					e_elements::begin_child(u8"KmBox-B-Pro", ImVec2(240, 240)); {

						ImGui::InputTextEx(u8"端口号", "", Function::Kmbox::B_Pro::PorttextBuffer, sizeof(Function::Kmbox::B_Pro::PorttextBuffer), ImVec2(110.f, 20.f), ImGuiInputTextFlags_None);
						ImGui::InputTextEx(u8"波特率", "", Function::Kmbox::B_Pro::SpeedBuffer, sizeof(Function::Kmbox::B_Pro::SpeedBuffer), ImVec2(110.f, 20.f), ImGuiInputTextFlags_None);
						if (ImGui::Button(u8"连接")) {

							保存Kmbox();
							Function::Kmbox::B_Pro::BproState = myserial.open(atoi(Function::Kmbox::B_Pro::PorttextBuffer), atoi(Function::Kmbox::B_Pro::SpeedBuffer));	  //打开串口号COM3 波特率115200
						}
						if (Function::Kmbox::B_Pro::BproState) { ImGui::Text(u8"Bpro连接成功"); }
						if (!Function::Kmbox::B_Pro::BproState) { ImGui::Text(u8"未连接或失败"); }

					}
					e_elements::end_child();
					ImGui::SetCursorPos({ 190, 260 });
					e_elements::begin_child(u8"融合器", ImVec2(140, 120)); {


						if (ImGui::Button(u8"开启")) {

							初始化 = true;


						}
						ImGui::SameLine();
						if (ImGui::Button(u8"关闭")) {

							初始化 = false;

						}

					}
					e_elements::end_child();
					break;
				}
			}
		}
		ImGui::End();
		ImGui::PopStyleVar();
	}
	int screenWidth = GetSystemMetrics(SM_CXSCREEN);
	int screenHeight = GetSystemMetrics(SM_CYSCREEN);
	if (初始化) Gui.RectangleFilled(Vec2{ 0 ,0 }, Vec2{ (float)screenWidth ,(float)screenHeight }, ImColor{ 0,0,0 });
	Gui.Text(u8"Ins 显示/隐藏", Vec2{ 10,280 }, ImColor{ 255,255,255 });
	if (Function::ESP::菜单_2)
	{
		string 振刀状态 = Function::Shock::F_ShockKnife ? u8"启用" : u8"关闭";
		Gui.Text(u8"F5-模拟振刀状态 [" + 振刀状态 + "]", Vec2{ 10,300 }, ImColor{ 255,255,255 });
		string 闪避状态 = Function::HeroActivation::IsDodge ? u8"启用" : u8"关闭";
		Gui.Text(u8"F6-闪避状态 [" + 闪避状态 + "]", Vec2{ 10,320 }, ImColor{ 255,255,255 });
	}

}

void MENUKEY()
{
	if (GetAsyncKeyState(VK_HOME)) { Function::ESP::菜单 = !Function::ESP::菜单; Sleep(150); }
	if (GetAsyncKeyState(VK_INSERT)) { Function::ESP::菜单_2 = !Function::ESP::菜单_2; Sleep(150); }
	if (GetAsyncKeyState(VK_DELETE)) { Memory::scatterDestroy(DmaData::hS); VMMDLL_Close(DmaData::vmm_handle); exit(0); }
	if (GetAsyncKeyState(VK_F5))
	{
		Function::Shock::F_ShockKnife = !Function::Shock::F_ShockKnife;
		if (Function::Shock::F_ShockKnife)
		{
			读取模拟振配置();
			Function::Shock::F_MemShock = false;
		}
		Sleep(150);
	}//模拟振功能开关
	if (GetAsyncKeyState(VK_F6)) { Function::HeroActivation::IsDodge = !Function::HeroActivation::IsDodge; Sleep(150); }//闪避功能开关

}


void DrawRun()
{
	MenuESP();
	Memory::ReadMemory(Offset::MatrixAddr, &MATRIX, 64);
	MENUKEY();
	PlayerESP();
	ItemESP();
	InteractiveESP();


}