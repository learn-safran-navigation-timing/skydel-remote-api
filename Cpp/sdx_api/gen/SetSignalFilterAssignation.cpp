
#include "SetSignalFilterAssignation.h"

#include "command_factory.h"
#include "parse_json.hpp"

///
/// Definition of SetSignalFilterAssignation
///

namespace Sdx
{
  namespace Cmd
  {
    const char* const SetSignalFilterAssignation::CmdName = "SetSignalFilterAssignation";
    const char* const SetSignalFilterAssignation::Documentation = "Assigns filters to signals by name; accepted filter values are \"None\" and \"Default\".\n"
      "\n"
      "Name             Type               Description\n"
      "---------------- ------------------ --------------------------------------------------------------------------------\n"
      "SignalFilterDict dict string:string A dictionary of signal filter pairs.\n"
      "                                    Accepted keys are: \"L1CA\", \"L1C\", \"L1P\", \"L1ME\", \"L1MR\", \"L2C\", \"L2P\", \"L2ME\",\n"
      "                                                       \"L2MR\", \"L5\", \"G1\", \"G2\", \"E1\", \"E1PRS\", \"E5a\", \"E5b\",\n"
      "                                                       \"E5AltBOC\", \"E6BC\", \"E6PRS\", \"B1\", \"B2\", \"B1C\", \"B2a\", \"B3I\",\n"
      "                                                       \"SBASL1\", \"SBASL5\", \"QZSSL1CA\", \"QZSSL1CB\", \"QZSSL1C\",\n"
      "                                                       \"QZSSL2C\", \"QZSSL5\", \"QZSSL1S\", \"QZSSL5S\", \"QZSSL6\",\n"
      "                                                       \"NAVICL1\", \"NAVICL5\", \"NAVICS\", \"PULSARXL\", \"PULSARX1\" and\n"
      "                                                       \"PULSARX5\"";
    const char* const SetSignalFilterAssignation::TargetId = "";

    REGISTER_COMMAND_TO_FACTORY_DECL(SetSignalFilterAssignation);
    REGISTER_COMMAND_TO_FACTORY_IMPL(SetSignalFilterAssignation);


    SetSignalFilterAssignation::SetSignalFilterAssignation()
      : CommandBase(CmdName, TargetId)
    {}

    SetSignalFilterAssignation::SetSignalFilterAssignation(const std::map<std::string, std::string>& signalFilterDict)
      : CommandBase(CmdName, TargetId)
    {

      setSignalFilterDict(signalFilterDict);
    }

    SetSignalFilterAssignationPtr SetSignalFilterAssignation::create(const std::map<std::string, std::string>& signalFilterDict)
    {
      return std::make_shared<SetSignalFilterAssignation>(signalFilterDict);
    }

    SetSignalFilterAssignationPtr SetSignalFilterAssignation::dynamicCast(CommandBasePtr ptr)
    {
      return std::dynamic_pointer_cast<SetSignalFilterAssignation>(ptr);
    }

    bool SetSignalFilterAssignation::isValid() const
    {
      
        return m_values.IsObject()
          && parse_json<std::map<std::string, std::string>>::is_valid(m_values["SignalFilterDict"])
        ;

    }

    std::string SetSignalFilterAssignation::documentation() const { return Documentation; }

    const std::vector<std::string>& SetSignalFilterAssignation::fieldNames() const 
    { 
      static const std::vector<std::string> names {"SignalFilterDict"}; 
      return names; 
    }


    int SetSignalFilterAssignation::executePermission() const
    {
      return EXECUTE_IF_IDLE;
    }


    std::map<std::string, std::string> SetSignalFilterAssignation::signalFilterDict() const
    {
      return parse_json<std::map<std::string, std::string>>::parse(m_values["SignalFilterDict"]);
    }

    void SetSignalFilterAssignation::setSignalFilterDict(const std::map<std::string, std::string>& signalFilterDict)
    {
      m_values.AddMember("SignalFilterDict", parse_json<std::map<std::string, std::string>>::format(signalFilterDict, m_values.GetAllocator()), m_values.GetAllocator());
    }


  }
}
