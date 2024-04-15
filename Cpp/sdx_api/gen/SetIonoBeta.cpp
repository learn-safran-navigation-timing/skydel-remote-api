
#include "SetIonoBeta.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoBeta
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoBeta::CmdName = "SetIonoBeta";
    const char* const SetIonoBeta::Documentation = "Set the GPS ionospheric Beta coefficient\n"
      "Beta 0 is in seconds\n"
      "Beta 1 is in seconds/semicircle\n"
      "Beta 2 is in seconds/semicircle^2\n"
      "Beta 3 is in seconds/semicircle^3\n"
      "\n"
      "Name  Type   Description\n"
      "----- ------ ------------------------\n"
      "Index int    Coefficient index [0..3]\n"
      "Val   double Coefficient value";
    const char* const SetIonoBeta::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetIonoBeta);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetIonoBeta);


    SetIonoBeta::SetIonoBeta()
      : CommandBase(CmdName, TargetId)
    {}

    SetIonoBeta::SetIonoBeta(int index, double val)
      : CommandBase(CmdName, TargetId)
    {

      setIndex(index);
      setVal(val);
    }

    SetIonoBetaPtr SetIonoBeta::create(int index, double val)
    {
      return std::make_shared<SetIonoBeta>(index, val);
    }

    SetIonoBetaPtr SetIonoBeta::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetIonoBeta>(ptr);
    }

    bool SetIonoBeta::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["Index"])
          && parse_json<double>::is_valid(m_values["Val"])
        ;

    }

    std::string SetIonoBeta::documentation() const { return Documentation; }

    const std::vector<std::string>& SetIonoBeta::fieldNames() const 
    { 
      static const std::vector<std::string> names {"Index", "Val"}; 
      return names; 
    }


    int SetIonoBeta::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetIonoBeta::index() const
    {
      return parse_json<int>::parse(m_values["Index"]);
    }

    void SetIonoBeta::setIndex(int index)
    {
      m_values.AddMember("Index", parse_json<int>::format(index, m_values.GetAllocator()), m_values.GetAllocator());
    }



    double SetIonoBeta::val() const
    {
      return parse_json<double>::parse(m_values["Val"]);
    }

    void SetIonoBeta::setVal(double val)
    {
      m_values.AddMember("Val", parse_json<double>::format(val, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
