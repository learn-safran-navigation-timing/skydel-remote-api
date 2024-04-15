
#include "SetIonoAlpha.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoAlpha
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoAlpha::CmdName = "SetIonoAlpha";
    const char* const SetIonoAlpha::Documentation = "Set the GPS ionospheric Alpha coefficient\n"
      "Alpha 0 is in seconds\n"
      "Alpha 1 is in seconds/semicircle\n"
      "Alpha 2 is in seconds/semicircle^2\n"
      "Alpha 3 is in seconds/semicircle^3\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------\n"
      "Index int    Coefficient index [0..3]\n"
      "Val   double Coefficient value";
    const char* const SetIonoAlpha::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIonoAlpha);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIonoAlpha);


    SetIonoAlpha::SetIonoAlpha()
      : CommandBase(CmdName, TargetId)
    {}

    SetIonoAlpha::SetIonoAlpha(int index, double val)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetIonoAlpha::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index", "Val"}; 
      return names; 
    }


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
