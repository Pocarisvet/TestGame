#pragma once

namespace Hunter
{
	enum class EventType
	{
		KeyPress,
		KeyRelease,
		WindowClose,
		WindowResize,
		WindowMinimize,
		WindowRestore
	};

	class Event
	{
	public:
		EventType GetEvenType() const;

	private:
		EventType type;
	};
}