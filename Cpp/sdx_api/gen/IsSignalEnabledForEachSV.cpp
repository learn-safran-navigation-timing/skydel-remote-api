
#include "gen/IsSignalEnabledForEachSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of IsSignalEnabledForEachSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const IsSignalEnabledForEachSV::CmdName = "IsSignalEnabledForEachSV";
    const char* const IsSignalEnabledForEachSV::Documentation = "Tells if the signal is enabled or disabled for each satellite.";

    REGISTER_COMMAND_FACTORY(IsSignalEnabledForEachSV);


    IsSignalEnabledForEachSV::IsSignalEnabledForEachSV()
      : CommandBase(CmdName)
    {}

    IsSignalEnabledForEachSV::IsSignalEnabledForEachSV(const std::string& signal)
      : CommandBase(CmdName)
    {

      setSignal(signal);
    }

    IsSignalEnabledForEachSVPtr IsSignalEnabledForEachSV::create(const std::string& signal)
    {
      return std::make_shared<IsSignalEnabledForEachSV>(signal);
    }

    IsSignalEnabledForEachSVPtr IsSignalEnabledForEachSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<IsSignalEnabledForEachSV>(ptr);
    }

    bool IsSignalEnabledForEachSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::string>::is_valid(m_values["Signal"])
        ;

    }

    std::string IsSignalEnabledForEachSV::documentation() const { return Documentation; }


    int IsSignalEnabledForEachSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::string IsSignalEnabledForEachSV::signal() const
    {
      return parse_json<std::string>::parse(m_values["Signal"]);
    }

    void IsSignalEnabledForEachSV::setSignal(const std::string& signal)
    {
      m_values.AddMember("Signal", parse_json<std::string>::format(signal, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
