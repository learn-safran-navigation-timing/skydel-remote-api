#ifndef DATE_H__
#define DATE_H__

#include "parse_json.hpp"

namespace Sdx
{
struct Date 
{
  Date(int pYear, int pMonth, int pDay)
    : year(pYear), month(pMonth), day(pDay)
  {
  }

  Date()
    : year(0), month(0), day(0)
  {
  }

  bool isValid() const { return year > 0 && month > 0 && day > 0; }

  int year;
  int month;
  int day;
};
}//namespace Sdx


template<>
struct parse_json<Sdx::Date>
{
	static bool is_valid(const rapidjson::Value& value)
	{
		return value.IsObject()
			&& value.HasMember("Year") && parse_json<int>::is_valid(value["Year"])
			&& value.HasMember("Month") && parse_json<int>::is_valid(value["Month"])
			&& value.HasMember("Day") && parse_json<int>::is_valid(value["Day"]);
	}

	static Sdx::Date parse(const rapidjson::Value& value)
	{
		Sdx::Date sent;

		if (!is_valid(value))
			throw std::runtime_error("Unexpected value.");
		sent.year = parse_json<int>::parse(value["Year"]);
		sent.month = parse_json<int>::parse(value["Month"]);
		sent.day = parse_json<int>::parse(value["Day"]);
		return sent;
	}

	static rapidjson::Value format(const Sdx::Date& value, rapidjson::Value::AllocatorType& alloc)
	{
		rapidjson::Value val;
		val.SetObject();

		val.AddMember("Year", value.year, alloc);
		val.AddMember("Month", value.month, alloc);
		val.AddMember("Day", value.day, alloc);
		return val;
	}
};

#endif //DATE_H__