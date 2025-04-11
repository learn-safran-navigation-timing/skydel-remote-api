
#include "SetTransmittedPrnForSV.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetTransmittedPrnForSV
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetTransmittedPrnForSV::CmdName = "SetTransmittedPrnForSV";
    const char* const SetTransmittedPrnForSV::Documentation = "Set the PRNs transmitted by the SV ID for these signals.\n"
      "\n"
      "Name          Type            Description\n"
      "------------- --------------- -------------------------------------------------------------------------------\n"
      "SvId          int             Satellite SV ID.\n"
      "SignalPrnDict dict string:int A dictionary of signal prn pairs.\n"
      "                              Accepted keys are: \"L1CA\", \"L1C\", \"L2C\", \"L5\", \"E1\", \"E6BC\", \"B1\", \"B2\", \"B1C\",\n"
      "                                                 \"B2a\", \"B3I\", \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\",\n"
      "                                                 \"QZSSL1C\", \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\",\n"
      "                                                 \"QZSSL6\", \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\",\n"
      "                                                 \"PULSARX1\" and \"PULSARX5\"";
    const char* const SetTransmittedPrnForSV::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetTransmittedPrnForSV);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetTransmittedPrnForSV);


    SetTransmittedPrnForSV::SetTransmittedPrnForSV()
      : CommandBase(CmdName, TargetId)
    {}

    SetTransmittedPrnForSV::SetTransmittedPrnForSV(int svId, const std::map<std::string, int>& signalPrnDict)
      : CommandBase(CmdName, TargetId)
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

    const std::vector<std::string>& SetTransmittedPrnForSV::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "SignalPrnDict"}; 
      return names; 
    }


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
