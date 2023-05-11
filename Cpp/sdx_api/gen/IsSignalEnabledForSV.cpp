
#include "gen/IsSignalEnabledForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForSV::CmdName = "IsSignalEnabledForSV";
    const char* const IsSignalEnabledForSV::Documentation = "Tells if the signal is enabled or disabled.";

    REGISTER_COMMAND_FACTORY(IsSignalEnabledForSV);


    IsSignalEnabledForSV::IsSignalEnabledForSV()
      : CommandBase(CmdName)
    {}

    IsSignalEnabledForSV::IsSignalEnabledForSV(const std::string& signal, int svId)
      : CommandBase(CmdName)
    {

      setSignal(signal);
      setSvId(svId);
    }

    IsSignalEnabledForSVPtr IsSignalEnabledForSV::create(const std::string& signal, int svId)
    {
      return std::make_shared<IsSignalEnabledForSV>(signal, svId);
    }

    IsSignalEnabledForSVPtr IsSignalEnabledForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabledForSV>(ptr);
    }

    bool IsSignalEnabledForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
          && parse_json<int>::is_valid(m_values["SvId"])
        ;

    }

    std::string IsSignalEnabledForSV::documentation() const { return Documentation; }


    int IsSignalEnabledForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSignalEnabledForSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabledForSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }



    int IsSignalEnabledForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void IsSignalEnabledForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
