
#include "GetTransmittedPrnForSVResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetTransmittedPrnForSVResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetTransmittedPrnForSVResult::CmdName = "GetTransmittedPrnForSVResult";
    const char* const GetTransmittedPrnForSVResult::Documentation = "Result of GetTransmittedPrnForSV.\n"
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
    const char* const GetTransmittedPrnForSVResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetTransmittedPrnForSVResult);


    GetTransmittedPrnForSVResult::GetTransmittedPrnForSVResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetTransmittedPrnForSVResult::GetTransmittedPrnForSVResult(int svId, const std::map<std::string, int>& signalPrnDict)
      : CommandResult(CmdName, TargetId)
    {

      setSvId(svId);
      setSignalPrnDict(signalPrnDict);
    }

    GetTransmittedPrnForSVResult::GetTransmittedPrnForSVResult(CommandBasePtr relatedCommand, int svId, const std::map<std::string, int>& signalPrnDict)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSvId(svId);
      setSignalPrnDict(signalPrnDict);
    }


    GetTransmittedPrnForSVResultPtr GetTransmittedPrnForSVResult::create(int svId, const std::map<std::string, int>& signalPrnDict)
    {
      return std::make_shared<GetTransmittedPrnForSVResult>(svId, signalPrnDict);
    }

    GetTransmittedPrnForSVResultPtr GetTransmittedPrnForSVResult::create(CommandBasePtr relatedCommand, int svId, const std::map<std::string, int>& signalPrnDict)
    {
      return std::make_shared<GetTransmittedPrnForSVResult>(relatedCommand, svId, signalPrnDict);
    }

    GetTransmittedPrnForSVResultPtr GetTransmittedPrnForSVResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetTransmittedPrnForSVResult>(ptr);
    }

    bool GetTransmittedPrnForSVResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<int>::is_valid(m_values["SvId"])
          && parse_json<std::map<std::string, int>>::is_valid(m_values["SignalPrnDict"])
        ;

    }

    std::string GetTransmittedPrnForSVResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetTransmittedPrnForSVResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SvId", "SignalPrnDict"}; 
      return names; 
    }


    int GetTransmittedPrnForSVResult::svId() const
    {
      return parse_json<int>::parse(m_values["SvId"]);
    }

    void GetTransmittedPrnForSVResult::setSvId(int svId)
    {
      m_values.AddMember("SvId", parse_json<int>::format(svId, m_values.GetAllocator()), m_values.GetAllocator());
    }



    std::map<std::string, int> GetTransmittedPrnForSVResult::signalPrnDict() const
    {
      return parse_json<std::map<std::string, int>>::parse(m_values["SignalPrnDict"]);
    }

    void GetTransmittedPrnForSVResult::setSignalPrnDict(const std::map<std::string, int>& signalPrnDict)
    {
      m_values.AddMember("SignalPrnDict", parse_json<std::map<std::string, int>>::format(signalPrnDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
