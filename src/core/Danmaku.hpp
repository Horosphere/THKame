#ifndef _THKAME_CORE_DANMAKU_HPP__
#define _THKAME_CORE_DANMAKU_HPP__

#include <boost/property_tree/ptree.hpp>

namespace thk
{

class Danmaku final
{
public:
	void read(boost::property_tree::ptree const&)
	throw(boost::property_tree::ptree_error);

};
	

} // namespace thk

#endif // !_THKAME_CORE_DANMAKU_HPP__
