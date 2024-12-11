
#include "GetSignalFilterAssignationResult.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of GetSignalFilterAssignationResult
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const GetSignalFilterAssignationResult::CmdName = "GetSignalFilterAssignationResult";
    const char* const GetSignalFilterAssignationResult::Documentation = "Result of GetSignalFilterAssignation.\n"
      "\n"
      "Name             Type               Description\n"
      "---------------- ------------------ --------------------------------------------------------------------------------\n"
      "SignalFilterDict dict string:string A dictionary of signal filter pairs.\n"
      "                                    Accepted keys are: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\",\n"
      "                                                       \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\",\n"
      "                                                       \"E5AltBOC\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"
      "                                                       \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                                       \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
      "                                                       \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\" and \"PULSARX1\"";
    const char* const GetSignalFilterAssignationResult::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_IMPL(GetSignalFilterAssignationResult);


    GetSignalFilterAssignationResult::GetSignalFilterAssignationResult()
      : CommandResult(CmdName, TargetId)
    {}

    GetSignalFilterAssignationResult::GetSignalFilterAssignationResult(const std::map<std::string, std::string>& signalFilterDict)
      : CommandResult(CmdName, TargetId)
    {

      setSignalFilterDict(signalFilterDict);
    }

    GetSignalFilterAssignationResult::GetSignalFilterAssignationResult(CommandBasePtr relatedCommand, const std::map<std::string, std::string>& signalFilterDict)
      : CommandResult(CmdName, TargetId, relatedCommand)
    {

      setSignalFilterDict(signalFilterDict);
    }


    GetSignalFilterAssignationResultPtr GetSignalFilterAssignationResult::create(const std::map<std::string, std::string>& signalFilterDict)
    {
      return std::make_shared<GetSignalFilterAssignationResult>(signalFilterDict);
    }

    GetSignalFilterAssignationResultPtr GetSignalFilterAssignationResult::create(CommandBasePtr relatedCommand, const std::map<std::string, std::string>& signalFilterDict)
    {
      return std::make_shared<GetSignalFilterAssignationResult>(relatedCommand, signalFilterDict);
    }

    GetSignalFilterAssignationResultPtr GetSignalFilterAssignationResult::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<GetSignalFilterAssignationResult>(ptr);
    }

    bool GetSignalFilterAssignationResult::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::map<std::string, std::string>>::is_valid(m_values["SignalFilterDict"])
        ;

    }

    std::string GetSignalFilterAssignationResult::documentation() const { return Documentation; }

    const std::vector<std::string>& GetSignalFilterAssignationResult::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalFilterDict"}; 
      return names; 
    }


    std::map<std::string, std::string> GetSignalFilterAssignationResult::signalFilterDict() const
    {
      return parse_json<std::map<std::string, std::string>>::parse(m_values["SignalFilterDict"]);
    }

    void GetSignalFilterAssignationResult::setSignalFilterDict(const std::map<std::string, std::string>& signalFilterDict)
    {
      m_values.AddMember("SignalFilterDict", parse_json<std::map<std::string, std::string>>::format(signalFilterDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
