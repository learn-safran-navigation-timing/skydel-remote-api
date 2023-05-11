
#include "gen/SetTransmittedPrnForSV.h"

#include "command_factory.h"
#include "command_result_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetTransmittedPrnForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetTransmittedPrnForSV::CmdName = "SetTransmittedPrnForSV";
    const char* const SetTransmittedPrnForSV::Documentation = "Set the PRNs transmitted by the SV ID for these signals.";

    REGISTER_COMMAND_FACTORY(SetTransmittedPrnForSV);


    SetTransmittedPrnForSV::SetTransmittedPrnForSV()
      : CommandBase(CmdName)
    {}

    SetTransmittedPrnForSV::SetTransmittedPrnForSV(int svId, const std::map<std::string, int>& signalPrnDict)
      : CommandBase(CmdName)
    {

      setSvId(svId);
      setSignalPrnDict(signalPrnDict);
    }

    SetTransmittedPrnForSVPtr SetTransmittedPrnForSV::create(int svId, const std::map<std::string, int>& signalPrnDict)
    {
      return std::make_shared<SetTransmittedPrnForSV>(svId, signalPrnDict);
    }

    SetTransmittedPrnForSVPtr SetTransmittedPrnForSV::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetTransmittedPrnForSV>(ptr);
    }

    bool SetTransmittedPrnForSV::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::map<std::string, int>>::is_valid(m_values["SignalPrnDict"])
        ;

    }

    std::string SetTransmittedPrnForSV::documentation() const { return Documentation; }


    int SetTransmittedPrnForSV::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    int SetTransmittedPrnForSV::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void SetTransmittedPrnForSV::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, int> SetTransmittedPrnForSV::signalPrnDict() const
    {
      return parse_json<std::map<std::string, int>>::parse(m_values["SignalPrnDict"]);
    }

    void SetTransmittedPrnForSV::setSignalPrnDict(const std::map<std::string, int>& signalPrnDict)
    {
      m_values.AddMember("SignalPrnDict", parse_json<std::map<std::string, int>>::format(signalPrnDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
