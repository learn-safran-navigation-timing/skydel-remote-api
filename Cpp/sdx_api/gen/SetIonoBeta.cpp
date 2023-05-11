
#include "gen/SetIonoBeta.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetIonoBeta
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetIonoBeta::CmdName = "SetIonoBeta";
    const char* const SetIonoBeta::Documentation = "Set the GPS ionospheric Beta coefficient\nBeta 0 is in seconds\nBeta 1 is in seconds/semicircle\nBeta 2 is in seconds/semicircle^2\nBeta 3 is in seconds/semicircle^3";

    REGISTER_COMMAND_FACTORY(SetIonoBeta);


    SetIonoBeta::SetIonoBeta()
      : CommandBase(CmdName)
    {}

    SetIonoBeta::SetIonoBeta(int index, double val)
      : CommandBase(CmdName)
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
