#include "Danmaku.hpp"

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>

namespace thk
{

inline BulletClass::HitType
stringToHitType(std::string str)
{
#define DEDUCE_HITTYPE(key, Type) \
	if (str == key) return BulletClass::Type

	DEDUCE_HITTYPE("Circle", Circle);
	DEDUCE_HITTYPE("Line", Line);

	return BulletClass::HitType::Circle;
#undef DEDUCE_HITTYPE
}

} // namespace thk

thk::Danmaku::Danmaku()
{
}

void thk::Danmaku::load(std::istream& stream)
{
	using boost::property_tree::ptree;

	ptree tree;
	boost::property_tree::read_xml(
	  stream, tree,
	  boost::property_tree::xml_parser::trim_whitespace);

	for (auto& child: tree.get_child("environment"))
	{
		if (child.first == "bullet")
		{
			ptree treeBullet = (ptree) child.second;
			BulletClass bullet
			{
				treeBullet.get<std::string>("Name"),
				stringToHitType(treeBullet.get<std::string>("HitType")),
				treeBullet.get<double>("HitRadius")
			};
			bulletClasses.push_back(bullet);
		}
		if (child.first == "entity")
		{
			ptree treeBullet = (ptree) child.second;
			EntityClass entity 
			{
				treeBullet.get<std::string>("Name"),
				treeBullet.get<int>("HitPoints", -1)
			};
			entityClasses.push_back(entity);
		}
	}
}

