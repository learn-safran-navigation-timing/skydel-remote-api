#ifndef SDX_OPTIONAL_H
#define SDX_OPTIONAL_H

#include <cassert>
#include <utility>
#include <type_traits>

namespace Sdx
{
  // Trivial implementation of c++17 std::optional
  template<typename T>
  class optional
  {
  public:
    optional()
      : m_isSet(false),
      m_value()
    {}

    optional(T value)
    {
      set(value);
    }

    optional(const optional& other)
      : m_isSet(other.m_isSet),
      m_value(other.m_value)
    {}

    optional& operator=(const optional& other)
    {
      m_isSet = other.m_isSet;
      m_value = other.m_value;
      return *this;
    }

    void set(T value)
    {
      m_isSet = true;
      m_value = value;
    }

    void unset()
    {
      m_isSet = false;
    }

    bool has_value() const
    {
      return m_isSet;
    }

    T value() const
    {
      assert(m_isSet);
      return m_value;
    }

    T operator*() const
    {
      return value();
    }

    template<typename U>
    T value_or(U&& default_value) const
    {
      return bool(*this) ? **this : static_cast<T>(std::forward<U>(default_value));
    }

    explicit operator bool() const
    {
      return has_value();
    }

    bool operator==(const optional& other) const
    {
      if (m_isSet != other.m_isSet)
        return false;
      if (!m_isSet) // If none of them are sets, we don't need to compare values.
        return true;
      return m_value == other.m_value;
    }

    bool operator!=(const optional& other) const
    {
      return !(*this == other);
    }

    bool operator==(T other) const
    {
      return m_isSet && m_value == other;
    }

    bool operator!=(T other) const
    {
      return !(*this == other);
    }


  private:
    bool m_isSet;
    T m_value;
  };
}

#endif // SDX_OPTIONAL_H
