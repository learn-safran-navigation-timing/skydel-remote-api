
#include "gen/SetIonoAlpha.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoAlpha
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoAlpha::CmdName = "SetIonoAlpha";
    const char* const SetIonoAlpha::Documentation = "Set the GPS ionospheric Alpha coefficient\nAlpha 0 is in seconds\nAlpha 1 is in seconds/semicircle\nAlpha 2 is in seconds/semicircle^2\nAlpha 3 is in seconds/semicircle^3";

    REGISTER_COMMAND_FACTORY(SetIonoAlpha);


    SetIonoAlpha::SetIonoAlpha()
      : CommandBase(CmdName)
    {}

    SetIonoAlpha::SetIonoAlpha(int index, double val)
      : CommandBase(CmdName)
    {

      setIndex(index);
      setVal(val);
    }

    SetIonoAlphaPtr SetIonoAlpha::create(int index, double val)
    {
      return std::make_shared<SetIonoAlpha>(index, val);
    }

    SetIonoAlphaPtr SetIonoAlpha::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoAlpha>(ptr);
    }

    bool SetIonoAlpha::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetIonoAlpha::documentation() const { return Documentation; }


    int SetIonoAlpha::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIonoAlpha::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void SetIonoAlpha::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIonoAlpha::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetIonoAlpha::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
