#pragma once

#include <rapidjson/document.h>

#include <map>
#include <stdexcept>
#include <vector>

#include "sdx_optional.h"

template<typename T>
struct parse_json;

// bool specialization
template<>
struct parse_json<bool>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsBool(); }

  static bool parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return value.GetBool();
  }

  static rapidjson::Value format(bool value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(value); }
};

// int specialization
template<>
struct parse_json<int>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsInt() || value.IsDouble(); }

  static int parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return value.GetInt();
  }

  static rapidjson::Value format(int value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(value); }
};

// double specialization
template<>
struct parse_json<double>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsDouble() || value.IsInt(); }

  static double parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return value.GetDouble();
  }

  static rapidjson::Value format(double value, rapidjson::Value::AllocatorType&) { return rapidjson::Value(value); }
};

// string specialization
template<>
struct parse_json<std::string>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsString(); }

  static std::string parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    return std::string(value.GetString(), value.GetStringLength());
  }

  static rapidjson::Value format(const std::string& value, rapidjson::Value::AllocatorType& alloc)
  {
    return rapidjson::Value(value.c_str(), static_cast<rapidjson::SizeType>(value.size()), alloc);
  }
};

// vector specialization
template<typename T>
struct parse_json<std::vector<T>>
{
  static bool is_valid(const rapidjson::Value& value)
  {
    if (!value.IsArray())
      return false;
    for (rapidjson::Value::ConstValueIterator itr = value.Begin(); itr != value.End(); ++itr)
      if (!parse_json<T>::is_valid(*itr))
        return false;
    return true;
  }

  static std::vector<T> parse(const rapidjson::Value& value)
  {
    std::vector<T> sent;

    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");
    for (rapidjson::Value::ConstValueIterator itr = value.Begin(); itr != value.End(); ++itr)
      sent.push_back(std::move(parse_json<T>::parse(*itr)));
    return sent;
  }

  static rapidjson::Value format(const std::vector<T>& value, rapidjson::Value::AllocatorType& alloc)
  {
    rapidjson::Value sent;

    sent.SetArray();
    for (const T& v : value)
      sent.PushBack(std::move(parse_json<T>::format(v, alloc)), alloc);
    return sent;
  }
};

// map specialization
// Json key/value pairs requires keys as string
template<typename TValue>
struct parse_json<std::map<std::string, TValue>>
{
  static bool is_valid(const rapidjson::Value& value)
  {
    if (!value.IsObject())
    {
      return false;
    }

    for (rapidjson::Value::ConstMemberIterator itr = value.MemberBegin(); itr != value.MemberEnd(); ++itr)
    {
      if (!parse_json<std::string>::is_valid(itr->name) || !parse_json<TValue>::is_valid(itr->value))
      {
        return false;
      }
    }

    return true;
  }

  static std::map<std::string, TValue> parse(const rapidjson::Value& value)
  {
    if (!is_valid(value))
      throw std::runtime_error("Unexpected value");

    std::map<std::string, TValue> sent;

    for (rapidjson::Value::ConstMemberIterator itr = value.MemberBegin(); itr != value.MemberEnd(); ++itr)
    {
      sent.emplace(itr->name.GetString(), parse_json<TValue>::parse(itr->value));
    }

    return sent;
  }

  static rapidjson::Value format(const std::map<std::string, TValue>& map, rapidjson::Value::AllocatorType& alloc)
  {
    rapidjson::Value sent(rapidjson::kObjectType);

    for (auto itr = map.begin(); itr != map.end(); ++itr)
    {
      sent.AddMember(parse_json<std::string>::format(itr->first, alloc),
                     parse_json<TValue>::format(itr->second, alloc),
                     alloc);
    }

    return sent;
  }
};

template<typename T>
struct parse_json<Sdx::optional<T>>
{
  static bool is_valid(const rapidjson::Value& value) { return value.IsNull() || parse_json<T>::is_valid(value); }

  static Sdx::optional<T> parse(const rapidjson::Value& value)
  {
    if (value.IsNull())
      return Sdx::optional<T>();
    return parse_json<T>::parse(value);
  }

  static rapidjson::Value format(const Sdx::optional<T>& value, rapidjson::Value::AllocatorType& alloc)
  {
    rapidjson::Value sent;

    if (value.has_value())
    {
      sent = parse_json<T>::format(value.value(), alloc);
    }
    return sent;
  }
};
