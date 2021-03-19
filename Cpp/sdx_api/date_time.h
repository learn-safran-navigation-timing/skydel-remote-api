#ifndef DATE_TIME_H__
#define DATE_TIME_H__

#include "date.h"
#include "parse_json.hpp"

namespace Sdx
{
struct DateTime : Date
{
  DateTime(int pYear, int pMonth, int pDay, 
           int pHour = 0, int pMinute = 0, int pSecond = 0)
    : Date(pYear, pMonth, pDay), 
      hour(pHour), minute(pMinute), second(pSecond)
  {
  }

    DateTime(int pHour = 0, int pMinute = 0, int pSecond = 0)
    : Date(), hour(pHour), minute(pMinute), second(pSecond)
  {
  }

  bool isValid() const { return Date::isValid() && hour >= 0 && minute >= 0 && second >= 0; }

  int hour;
  int minute;
  int second;
};
}//namespace Sdx

template<>
struct parse_json<Sdx::DateTime>
{
	static bool is_valid(const rapidjson::Value& value)
	{
		return value.IsObject()
			&& value.HasMember("Year") && parse_json<int>::is_valid(value["Year"])
			&& value.HasMember("Month") && parse_json<int>::is_valid(value["Month"])
			&& value.HasMember("Day") && parse_json<int>::is_valid(value["Day"])
			&& value.HasMember("Hour") && parse_json<int>::is_valid(value["Hour"])
			&& value.HasMember("Minute") && parse_json<int>::is_valid(value["Minute"])
			&& value.HasMember("Second") && parse_json<int>::is_valid(value["Second"]);
	}

	static Sdx::DateTime parse(const rapidjson::Value& value)
	{
		Sdx::DateTime sent;

		if (!is_valid(value))
			throw std::runtime_error("Unexpected value.");
		sent.year = parse_json<int>::parse(value["Year"]);
		sent.month = parse_json<int>::parse(value["Month"]);
		sent.day = parse_json<int>::parse(value["Day"]);
		sent.hour = parse_json<int>::parse(value["Hour"]);
		sent.minute = parse_json<int>::parse(value["Minute"]);
		sent.second = parse_json<int>::parse(value["Second"]);
		return sent;
	}

	static rapidjson::Value format(const Sdx::DateTime& value, rapidjson::Value::AllocatorType& alloc)
	{
		rapidjson::Value val;
		val.SetObject();

		val.AddMember("Spec", "UTC", alloc);
		val.AddMember("Year", value.year, alloc);
		val.AddMember("Month", value.month, alloc);
		val.AddMember("Day", value.day, alloc);
		val.AddMember("Hour", value.hour, alloc);
		val.AddMember("Minute", value.minute, alloc);
		val.AddMember("Second", value.second, alloc);
		return val;
	}
};

#endif //DATE_TIME_H__