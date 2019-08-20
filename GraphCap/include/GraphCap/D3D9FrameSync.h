#pragma once

#include <boost/interprocess/managed_shared_memory.hpp>
#include <boost/interprocess/sync/interprocess_mutex.hpp>
#include <boost/interprocess/sync/interprocess_condition.hpp>

namespace gc
{
	namespace bip = boost::interprocess;

	struct D3D9FSSharedData
	{
		bip::interprocess_mutex endSceneMutex;
		bip::interprocess_condition endSceneCond;
		bip::interprocess_mutex presentMutex;
		bip::interprocess_condition presentCond;
	};

	class D3D9FrameSync
	{
	public:
		D3D9FrameSync();

		bool waitForEndScene(time_t timeout = 17);
		bool waitForPresent(time_t timeout = 17);

	private:
		bip::managed_shared_memory m_memory;
		D3D9FSSharedData* m_data;
	};
}
